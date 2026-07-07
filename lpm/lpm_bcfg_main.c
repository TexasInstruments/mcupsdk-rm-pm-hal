/*
 * DM Stub Firmware
 *
 * DM Stub main low power functionality for boardcfg managed modes.
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
 * \file lpm_bcfg_main.c
 *
 * \brief This file contains the code which is loaded to R5F-TCMB for low power support.
 * It is responsible for putting the DDR in retention and configure PMIC to powerdown the SOC.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <lpm_baseaddress.h>
#include <lpm_wkup_ctrl_mmr.h>
#include <lpm_serial_8250.h>
#include <lpm_io.h>
#include <timeout.h>
#include <tisci_lpm.h>
#include "ddr.h"
#include "ctrlmmr_raw.h"
#include "lpm_pmic.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static void lpm_bypass_i2c_ios(void);
static void lpm_bypass_wkup_uart_ios(void);
static void lpm_set_io_isolation(void);
static s32 lpm_latch_ddr_and_can_io_magic_words(void);
void lpm_enter_low_power_mode(u32);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* dummy variables to ensure .bss and .rodata sections exist for dm_stub,
 * this prevents linker warnings. */
static uint32_t dm_stub_bss_dummy __attribute__((section(".bss"), used));
static const uint32_t dm_stub_rodata_dummy __attribute__((section(".rodata"), used)) = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static void lpm_bypass_i2c_ios(void)
{
	u32 reg;

	/* Bypass WKUP_I2C IOs so they remain active after IO isolation is
	 * asserted, allowing I2C commands to be sent to the PMIC later in
	 * the suspend sequence
	 */
	reg = readl(LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SCL);
	reg = reg & LPM_MCU_PADCONFIG_WRITE_MASK;
	reg = reg | (LPM_PADCONFIG_RX_ACTIVE | LPM_PADCONFIG_ISO_BYPASS_PAD);
	writel(reg, LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SCL);

	reg = readl(LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SDA);
	reg = reg & LPM_MCU_PADCONFIG_WRITE_MASK;
	reg = reg | (LPM_PADCONFIG_RX_ACTIVE | LPM_PADCONFIG_ISO_BYPASS_PAD);
	writel(reg, LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_I2C_SDA);
}

static void lpm_bypass_wkup_uart_ios(void)
{
#ifdef CONFIG_LPM_DM_TRACE_UART
	u32 reg;

	/* Bypass Wakeup UART IOs so debug logs remain available after IO
	 * isolation is asserted
	 */
	reg = readl(LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_CTS);
	reg = reg & LPM_MCU_PADCONFIG_WRITE_MASK;
	reg = reg | LPM_PADCONFIG_ISO_BYPASS_PAD;
	writel(reg, LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_CTS);

	reg = readl(LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_RTS);
	reg = reg & LPM_MCU_PADCONFIG_WRITE_MASK;
	reg = reg | LPM_PADCONFIG_ISO_BYPASS_PAD;
	writel(reg, LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_RTS);

	reg = readl(LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_RXD);
	reg = reg & LPM_MCU_PADCONFIG_WRITE_MASK;
	reg = reg | LPM_PADCONFIG_ISO_BYPASS_PAD;
	writel(reg, LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_RXD);

	reg = readl(LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_TXD);
	reg = reg & LPM_MCU_PADCONFIG_WRITE_MASK;
	reg = reg | LPM_PADCONFIG_ISO_BYPASS_PAD;
	writel(reg, LPM_MCU_PADCFG_BASE + LPM_MCU_PADCONFIG_UART_TXD);
#endif
}

static void lpm_set_io_isolation(void)
{
	s32 ret = -EFAIL;
	u32 reg;
	u32 i = 0;

	writel(LPM_WKUP_CTRL_DEEPSLEEP_CTRL_ENABLE_IO, (LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_DEEPSLEEP_CTRL));
	writel(LPM_WKUP_CTRL_PMCTRL_IO_GLB_ENABLE_IO, (LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_GLB));

	/* Set global isobypass (valid for MCU IOs only) */
	reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);
	reg = reg & LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK;
	reg = reg | LPM_WKUP_CTRL_PMCTRL_IO_0_ISO_BYPASS;
	writel(reg, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);

	/* Set global wuen */
	reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);
	reg = reg & LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK;
	reg = reg | LPM_WKUP_CTRL_PMCTRL_IO_0_GLOBAL_WUEN;
	writel(reg, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);

	reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);
	reg = reg & LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK;
	reg = reg | LPM_WKUP_CTRL_PMCTRL_IO_0_GLOBAL_WUEN;
	writel(reg, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);

	reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);
	reg = reg & LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK;
	reg = reg | LPM_WKUP_CTRL_PMCTRL_IO_0_ISO_BYPASS;
	writel(reg, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);

	/* Set global isoin */
	reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);
	reg = reg & LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK;
	reg = reg | LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_CTRL;
	writel(reg, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);

	reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);
	reg = reg & LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK;
	reg = reg | LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_CTRL;
	writel(reg, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);

	/* Wait for wu clock state to be 1*/
	i = 0;
	do {
		ret = -EFAIL;
		reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_0);
		if ((reg & LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_STATUS) == LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_STATUS) {
			ret = 0;
			break;
		}
	} while (i++ < TIMEOUT_10_MS);

	if (ret != 0) {
		lpm_puts("Failed waiting for LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_STATUS\n");
	}

	i = 0;
	do {
		ret = -EFAIL;
		reg = readl(LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_CTRL_PMCTRL_IO_1);
		if ((reg & LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_STATUS) == LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_STATUS) {
			ret = 0;
			break;
		}
	} while (i++ < TIMEOUT_10_MS);

	if (ret != 0) {
		lpm_puts("Failed waiting for WKUP_CTRL_PMCTRL_IO_1_IO_ISO_STATUS\n");
	}
}

static s32 lpm_latch_ddr_and_can_io_magic_words(void)
{
	u32 timeout = TIMEOUT_10_MS;
	s32 ret = 0;

	/* Program the OFF mode MMR in case of IO Only plus DDR mode. */
	writel(LPM_WKUP_CANUART_OFF_MAGIC_WORD, LPM_WKUP_CTRL_MMR_BASE + LPM_CANUART_WAKE_OFF_MODE);

	/* Program the CAN IO MMR. */
	writel(0x0U, LPM_WKUP_CTRL_MMR_BASE + LPM_CANUART_WAKE_CTRL);
	writel((LPM_WKUP_CANUART_MAGIC_WRD | LPM_WKUP_CANUART_MAGIC_WRD_LD_EN), LPM_WKUP_CTRL_MMR_BASE + LPM_CANUART_WAKE_CTRL);

	/* Wait for CAN_ONLY_IO signal to be 1 */
	while ((timeout > 0U) && ((readl(LPM_WKUP_CTRL_MMR_BASE + LPM_CANUART_WAKE_STAT1)) != LPM_WKUP_CANUART_CAN_IO_ISO_SET)) {
		--timeout;
	}

	if (timeout == 0U) {
		ret = -EFAIL;
	}

	/* Clear the magic word to prevent any other word loading */
	writel((~LPM_WKUP_CANUART_MAGIC_WRD) | LPM_WKUP_CANUART_MAGIC_WRD_LD_DIS, LPM_WKUP_CTRL_MMR_BASE + LPM_CANUART_WAKE_CTRL);

	return ret;
}

/*
 * \brief Run the suspend sequence (put DDR in retention and powerdown the SOC)
 *
 * This function is the entry point of when DM-Firmware jumps to R5F-TCMB to start the
 * suspend sequence.
 *
 */
void lpm_enter_low_power_mode(u32 mode)
{
	lpm_console_init();

	/* Unlock wkup_ctrl_mmr region 2 & 6 */
	ctrlmmr_unlock(LPM_WKUP_CTRL_MMR_BASE, 2);
	ctrlmmr_unlock(LPM_WKUP_CTRL_MMR_BASE, 6);

	/* Unlock mcu_ctrl_mmr region 0,2 */
	ctrlmmr_unlock(LPM_MCU_CTRL_MMR_BASE, 0);
	ctrlmmr_unlock(LPM_MCU_CTRL_MMR_BASE, 2);

	if (mode == TISCI_MSG_VALUE_SLEEP_MODE_IO_ONLY_PLUS_DDR) {
		lpm_bypass_i2c_ios();
		lpm_bypass_wkup_uart_ios();
		lpm_set_io_isolation();
		lpm_puts("lpm_enter_low_power_mode: io-isolation enabled \n");
	}

	if (lpm_latch_ddr_and_can_io_magic_words() != 0) {
		lpm_puts("lpm_latch_ddr_and_can_io_magic_words failed \n");
	}

	if (ddr_enter_io_ddr_mode() != 0) {
		lpm_puts("failed to enter ddr self-refresh \n");
	}

	/* Enable wakeup through IO daisy chain */
	if (mode == TISCI_MSG_VALUE_SLEEP_MODE_IO_ONLY_PLUS_DDR) {
		writel((LPM_WKUP0_EN_MCU_IO_DAISY_CHAIN | LPM_WKUP0_EN_CANUART_IO_DAISY_CHAIN), (LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP0_EN));
	} else {
		writel(0, (LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP0_EN));
	}

	/* Ensure that PMIC EN control from SOC is selected */
	writel((LPM_WKUP0_PMCTRL_SYS_EN_PMIC | LPM_WKUP0_PMIC_OUT_EN), (LPM_WKUP_CTRL_MMR_BASE + LPM_PMCTRL_SYS));

	/* Enter IO DDR mode */
	writel((LPM_WKUP0_PMCTRL_SYS_EN_PMIC | LPM_WKUP0_PMIC_OUT_DIS), LPM_WKUP_CTRL_MMR_BASE + LPM_PMCTRL_SYS);

	/* disable the watchdog so it doesn't wake the soc during low power modes */
	writel(LPM_WWD_STOP, LPM_WKUP_CTRL_MMR_BASE + LPM_WKUP_WWD0_CTRL);

	lpm_puts("lpm_enter_low_power_mode: ddr retention done \n");

	lpm_setup_pmic_for_retention();

	while (1) {
		/* Wait for PMIC to powerdown the SoC */
	}
}
