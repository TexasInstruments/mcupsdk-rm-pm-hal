/*
 * DM Stub Firmware
 *
 * Bare-metal I2C driver for LPM PMIC communication.
 *
 * Copyright (C) 2026, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file lpm_i2c.c
 *
 * \brief Bare-metal I2C primitives used by the LPM stub to configure the PMIC
 * during the suspend-to-RAM sequence. Provides direct-register I2C read/write
 * operations and WKUP_I2C0 initialisation for the PMIC control path.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <lib/bitops.h>
#include <timeout.h>
#include <types/short_types.h>
#include <lpm_baseaddress.h>
#include <lpm_i2c.h>
#include <lpm_io.h>
#include <lpm_serial_8250.h>
#include <lpm_wkup_ctrl_mmr.h>
#include "lpm_pmic.h"

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Read one byte from an I2C target register with a polling timeout.
 *
 * \param add        Target register address byte.
 * \param rxd        Pointer to store the received byte.
 * \param timeout_ms Maximum number of polling iterations before giving up.
 * \return           0 on success, -EFAIL on timeout.
 */
static s32 lpm_i2c_read_timeout(u32 i2c_base, u8 add, u8 *rxd, u32 timeout_ms);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static s32 lpm_i2c_read_timeout(u32 i2c_base, u8 add, u8 *rxd, u32 timeout_ms)
{
	u32 val;
	u32 timeout = timeout_ms;

	/* Ensure the Bus Busy (BB) bit is de-asserted before starting a new transfer */
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_BB_MASK) != 0U)) {
		--timeout;
	}

	if (timeout == 0U) {
		lpm_puts("i2c_read_timeout: timeout loop exceed");
		return -EFAIL;
	}

	/* Set transfer count to 1 byte and set transmit mode (TRX=1) and master mode (MST=1) */
	writel(LPM_I2C_CNT_ONE_BYTE, (i2c_base + LPM_I2C_CNT_REG));
	val = readl((i2c_base + LPM_I2C_CON_REG)) & ~LPM_I2C_CON_STP_MASK;
	writel((val | ((LPM_I2C_CON_STT_MASK | LPM_I2C_CON_STP_MASK) << LPM_I2C_CON_TRX_SHIFT)), (i2c_base + LPM_I2C_CON_REG));

	/* Assert START to begin the address-phase write */
	val = readl((i2c_base + LPM_I2C_CON_REG));
	val |= LPM_I2C_CON_STT_MASK;
	writel(val, (i2c_base + LPM_I2C_CON_REG));

	/* Poll XRDY (Transmit Data Ready) until the TX FIFO is ready to accept the register address byte */
	timeout = timeout_ms;
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_XRDY_MASK) == 0U)) {
		--timeout;
	}

	if (timeout == 0U) {
		lpm_puts("i2c_read_timeout: timeout for XRDY: loop exceed");
		return -EFAIL;
	}

	/* Load the register address into the TX FIFO and clear XRDY (Transmit Data Ready) to transmit it */
	writel(add, (i2c_base + LPM_I2C_DATA_REG));
	writel(LPM_I2C_IRQSTATUS_XRDY_MASK, (i2c_base + LPM_I2C_IRQSTATUS_REG));

	/* Poll ARDY (Access Ready) until the address-write phase is complete and
	 * the controller is ready for the read phase
	 */
	timeout = timeout_ms;
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_ARDY_MASK) == 0U)) {
		--timeout;
	}

	if (timeout == 0U) {
		lpm_puts("i2c_read_timeout: timeout for ARDY: loop exceed");
		return -EFAIL;
	}

	/* Clear all pending interrupt status bits before switching to receive mode */
	val = readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG));
	writel(val, (i2c_base + LPM_I2C_IRQSTATUS_REG));

	/* Switch to receive mode (TRX=0 enables receive mode) and keep master mode
	 * (MST=1 is master mode) for a 1-byte read
	 */
	val = readl((i2c_base + LPM_I2C_CON_REG)) & ~LPM_I2C_CON_TRX_MASK;
	writel((val | LPM_I2C_CON_MST_MASK), (i2c_base + LPM_I2C_CON_REG));
	writel(LPM_I2C_CNT_ONE_BYTE, (i2c_base + LPM_I2C_CNT_REG));

	/* Issue a repeated START + STOP to clock in the data byte from the target */
	val = readl((i2c_base + LPM_I2C_CON_REG));
	val |= (LPM_I2C_CON_STT_MASK | LPM_I2C_CON_STP_MASK) << LPM_I2C_CON_STT_SHIFT;
	writel(val, (i2c_base + LPM_I2C_CON_REG));

	/* Poll RRDY (Receive Data Ready) until the RX FIFO holds the response byte from the target */
	timeout = timeout_ms;
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_RRDY_MASK) == 0U)) {
		--timeout;
	}

	if (timeout == 0U) {
		lpm_puts("i2c_read_timeout: timeout for RRDY: loop exceed");
		return -EFAIL;
	}

	*rxd = readl((i2c_base + LPM_I2C_DATA_REG));

	/* Poll ARDY (Access Ready) until the data read phase is complete and
	 * the STOP condition has been issued
	 */
	timeout = timeout_ms;
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_ARDY_MASK) == 0U)) {
		--timeout;
	}

	if (timeout == 0U) {
		lpm_puts("i2c_read_timeout: timeout for ARDY: loop exceed");
		return -EFAIL;
	}

	/* Clear all pending interrupt status bits to leave the controller clean */
	val = readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG));
	writel(val, (i2c_base + LPM_I2C_IRQSTATUS_REG));

	return 0;
}

u8 lpm_i2c_read(u32 i2c_base, u8 add)
{
	u8 rxData;

	lpm_i2c_read_timeout(i2c_base, add, &rxData, TIMEOUT_10_MS);

	return rxData;
}

void lpm_i2c_write(u32 i2c_base, u8 add, u8 data)
{
	/*
	 * Perform a 2-byte I2C master write to the PMIC:
	 *
	 *  1. Wait for the bus to be free (BB bit de-asserted).
	 *
	 *  2. Set transfer count to 2 (addr and data), configure transmit mode, and
	 *     assert START condition to begin the transaction.
	 *
	 *  3. For each byte (register address 'add'; then the data byte 'data'):
	 *     a. Poll XRDY (Transmit Data Ready) until the TX FIFO can accept the next byte.
	 *     b. Load the byte into the TX FIFO.
	 *
	 *  4. Clear XRDY (Transmit Data Ready) to signal the last byte is loaded.
	 *
	 *  5. Poll ARDY (Access Ready) until the STOP condition has been issued and both bytes
	 *     have been acknowledged by the target.
	 *
	 *  6. Clear all pending interrupt status bits to leave the controller state clean.
	 */

	u32 n;
	u32 val;

	/* Ensure the Bus Busy (BB) bit is de-asserted before starting a new write transfer */
	while ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_BB_MASK) != 0U) {
		/* Wait for busy bit signal */
	}

	/* Set transfer count to 2 bytes (addr and data) and configure transmit mode
	 * (TRX=1, Transmit mode) with START + STOP
	 */
	writel(LPM_I2C_CNT_TWO_BYTES, (i2c_base + LPM_I2C_CNT_REG));
	val = readl((i2c_base + LPM_I2C_CON_REG)) & ~LPM_I2C_CON_STP_MASK;
	writel((val | ((LPM_I2C_CON_STT_MASK | LPM_I2C_CON_STP_MASK) << LPM_I2C_CON_TRX_SHIFT)), (i2c_base + LPM_I2C_CON_REG));

	/* Assert START condition to begin the two-byte write transfer */
	val = readl((i2c_base + LPM_I2C_CON_REG));
	writel((val | ((LPM_I2C_CON_STT_MASK | LPM_I2C_CON_STP_MASK) << LPM_I2C_CON_STT_SHIFT)), (i2c_base + LPM_I2C_CON_REG));

	/* Send register address (add) then data value (data) across two TX iterations */
	for (n = 0; n < LPM_I2C_CNT_TWO_BYTES; n++) {
		/* Poll XRDY (Transmit Data Ready) before loading the next byte into the TX FIFO */
		while ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_XRDY_MASK) == 0U) {
			/* Wait for XRDY signal */
		}

		if (n == 0U) {
			/* Load the target register address into the TX FIFO */
			writel(add, (i2c_base + LPM_I2C_DATA_REG));
		} else {
			/* Load the data value into the TX FIFO and clear XRDY
			 * (Transmit Data Ready) to transmit it
			 */
			writel(data, (i2c_base + LPM_I2C_DATA_REG));
			writel(LPM_I2C_IRQSTATUS_XRDY_MASK, (i2c_base + LPM_I2C_IRQSTATUS_REG));
		}
	}

	/* Poll ARDY (Access Ready) flag to make sure both bytes are transmitted and
	 * the STOP condition has been issued
	 */
	while ((readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG)) & LPM_I2C_IRQSTATUS_RAW_ARDY_MASK) == 0U) {
		/* Wait for ARDY signal */
	}

	/* Clear all pending interrupt status bits to leave the controller state clean */
	val = readl((i2c_base + LPM_I2C_IRQSTATUS_RAW_REG));
	writel(val, (i2c_base + LPM_I2C_IRQSTATUS_REG));
}

void lpm_configure_i2c(u8 pmic, u32 i2c_base)
{
	/*
	 * Initialise WKUP_I2C0 for PMIC communication during the S2R sequence:
	 *
	 *  1. Enable RX_ACTIVE on the SCL and SDA pad receivers so the pads
	 *     remain functional after IO isolation is asserted.
	 *
	 *  2. Soft-reset the I2C module (SRST) to reach a known state and enable
	 *     smart-idle mode.
	 *
	 *  3. Configure the SCL clock: set PSC (Prescaler) to derive 12 MHz
	 *     from the 96 MHz input, then set SCLL and SCLH appropriately for 400 kHz
	 *     fast mode timing. Clear old state of the controller and re-enable
	 *     the module, and wait for RDONE to confirm the new settings are active.
	 *
	 *  4. Set the PMIC slave address as the transfer target, flush the
	 *     TX and RX FIFOs, and unlock the PMIC register space.
	 */

	u32 val;
	u32 timeout = TIMEOUT_10_MS;

	/*
	 * Pinmux I2C:
	 * B9 MCU_PADCONFIG19 WKUP_I2C0_SCL 0x0408404C mux0
	 * D11 MCU_PADCONFIG20 WKUP_I2C0_SDA 0x04084050 mux0
	 */
	/* Enable RX_ACTIVE on WKUP_I2C SCL and SDA to keep receivers active during IO isolation */
	val = readl((LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SCL));
	val |= LPM_PADCONFIG_RX_ACTIVE;
	writel(val, (LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SCL));

	val = readl((LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SDA));
	val |= LPM_PADCONFIG_RX_ACTIVE;
	writel(val, (LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SDA));

	/* Assert SRST (Soft Reset) to bring the I2C module to a known state */
	val = readl((i2c_base + LPM_I2C_SYSC_REG));
	val |= LPM_I2C_SYSC_SRST_MASK;
	writel(val, (i2c_base + LPM_I2C_SYSC_REG));

	/* Enable smart-idle mode: the I2C module refuses PRCM idle requests during
	 * an active transfer, preventing clock gating mid-transaction and
	 * ensuring PMIC commands complete without corruption
	 */
	val = readl((i2c_base + LPM_I2C_SYSC_REG));
	val |= LPM_I2C_SYSC_IDLEMODE_MASK;
	writel(val, (i2c_base + LPM_I2C_SYSC_REG));

	/* Assert I2C_EN (I2C Enable) to start the reset sequence */
	val = readl((i2c_base + LPM_I2C_CON_REG));
	val |= LPM_I2C_CON_I2C_EN_MASK;
	writel(val, (i2c_base + LPM_I2C_CON_REG));

	/* Poll SYSS.RDONE (Reset Done) flag until the soft-reset completes */
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_SYSS_REG)) & LPM_I2C_SYSS_RDONE_MASK) == 0U)) {
		--timeout;
	}

	/*
	 * Configure SCL clock for I2C Fast Mode (400 kHz).
	 *
	 * Fast Mode minimum timing requirements (I2C spec):
	 *   t_LOW  >= 1.3 s   (SCL low period)
	 *   t_HIGH >= 0.6 s   (SCL high period)
	 *
	 * The TI I2C controller derives SCL from the module's input clock via a
	 * two-stage process:
	 *   1. PSC divides the 96 MHz input to produce the internal 12 MHz clock.
	 *   2. SCLL and SCLH count in multiples of that 12 MHz tick (83.3 ns each).
	 *      The hardware adds fixed overheads: +7 cycles for low and +5 cycles for high.
	 *
	 * Result: SCLL set to 9 derives 1.333 s as low period,
	 *         SCLH set to 9 derives 1.167 s as high period.
	 *
	 * Hence, SCLL + SCLH = 1.333 + 1.167 = 2.5 s = 400 kHz.
	 */

	/* Set I2C_PSC (Prescaler) to derive 12 MHz internal clock: 96/(7+1) = 12MHz */
	val = readl((i2c_base + LPM_I2C_PSC_REG)) & ~0xFF;
	writel((val | LPM_I2C_PRESCALER_DIVIDER_12MHZ), (i2c_base + LPM_I2C_PSC_REG));

	/* Set SCLL (SCL Low period): (9+7 cycles)/12MHz = 1.333 s.
	 * This meets Fast Mode requirement that t_LOW >= 1.3 s
	 */
	val = readl((i2c_base + LPM_I2C_SCLL_REG)) & ~0xFF;
	writel((val | LPM_I2C_SCLL_16), (i2c_base + LPM_I2C_SCLL_REG));

	/* Set SCLH (SCL High period): (9+5 cycles)/12MHz = 1.167 s.
	 * This meets Fast Mode requirement that t_HIGH >= 0.6 s
	 */
	val = readl((i2c_base + LPM_I2C_SCLH_REG)) & ~0xFF;
	writel((val | LPM_I2C_SCLH_14), (i2c_base + LPM_I2C_SCLH_REG));

	/* Clear write-control bits, data count, and DMA fields before re-enabling */
	val = readl((i2c_base + LPM_I2C_CON_REG));
	val &= ~LPM_I2C_CON_WRITE_MASK;
	writel(val, (i2c_base + LPM_I2C_CON_REG));

	/* Clear DCOUNT (data count) to prevent a stale byte count from a previous
	 * transaction from carrying over
	 */
	val = readl((i2c_base + LPM_I2C_CNT_REG));
	val &= ~LPM_I2C_CNT_DCOUNT_MAX;
	writel(val, (i2c_base + LPM_I2C_CNT_REG));

	/* Disable RX (RDMA_EN) and TX (XDMA_EN) DMA to use polling IO mode */
	val = readl((i2c_base + LPM_I2C_BUF_REG));
	val &= ~(LPM_I2C_BUF_RDMA_EN_MASK | LPM_I2C_BUF_XDMA_EN_MASK);
	writel(val, (i2c_base + LPM_I2C_BUF_REG));

	/* Set own address OA (Own Address) to initialise the hardware address comparator,
	 * required even in master-only mode
	 */
	val = readl((i2c_base + LPM_I2C_OA_REG)) & ~LPM_I2C_OA_OA_MASK;
	writel((val | LPM_I2C_OWN_ADDR), (i2c_base + LPM_I2C_OA_REG));

	/* Re-assert I2C_EN (I2C Enable) after clock configuration */
	val = readl((i2c_base + LPM_I2C_CON_REG));
	val |= LPM_I2C_CON_I2C_EN_MASK;
	writel(val, (i2c_base + LPM_I2C_CON_REG));

	/* Poll SYSS.RDONE (Reset Done) flag until the soft-reset completes and
	 * new clock settings are active
	 */
	timeout = TIMEOUT_10_MS;
	while ((timeout > 0U) &&
	       ((readl((i2c_base + LPM_I2C_SYSS_REG)) & LPM_I2C_SYSS_RDONE_MASK) == 0U)) {
		--timeout;
	}

	/* Set the PMIC's I2C slave address as the target for subsequent transfers */
	val = readl((i2c_base + LPM_I2C_SA_REG)) & ~LPM_I2C_SA_SA_MASK;
	writel((val | pmic), (i2c_base + LPM_I2C_SA_REG));

	/* Reset TX and RX FIFOs and set both transfer thresholds to 1 byte */
	writel((LPM_I2C_BUF_TXFIFO_CLR_MASK | LPM_I2C_BUF_RXFIFO_CLR_MASK), (i2c_base + LPM_I2C_BUF_REG));
}
