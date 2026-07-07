/*
 * DM Stub Firmware
 *
 * DM Stub pmic functionality.
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
 * \file lpm_pmic.c
 *
 * \brief PMIC control driver for lpm stub. Configures the PMIC to
 * power off the SoC while retaining DDR and IOs in low power mode.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <types/short_types.h>
#include <lpm_i2c.h>
#include <lpm_pmic_config.h>
#include "lpm_pmic.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Read a PMIC register via I2C.
 * \param reg  PMIC register address.
 * \return     Register value.
 */
static u8 lpm_read_pmic(u8 reg);

/**
 * \brief Write to a PMIC register via I2C.
 * \param reg  PMIC register address.
 * \param val  Value to write.
 */
static void lpm_write_pmic(u8 reg, u8 val);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static u8 lpm_read_pmic(u8 reg)
{
	u8 rxd;

	rxd = lpm_i2c_read(LPM_I2C_CTL_BASE, reg);

	return rxd;
}

static void lpm_write_pmic(u8 reg, u8 val)
{
	lpm_i2c_write(LPM_I2C_CTL_BASE, reg, val);
}

static void lpm_clear_pmic_interrupts(void)
{
	u8 int_top, val, val1;

	int_top = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_TOP);

	if (!int_top) {
		return;
	}

	if (int_top & LPM_PMIC_INT_TOP_BUCK_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_BUCK_STATUS);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_BUCK_STATUS, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_LDO_VMON_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_LDO_VMON_STATUS);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_LDO_VMON_STATUS, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_GPIO_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_GPIO_REGADDR);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_GPIO_REGADDR, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_STARTUP_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_STARTUP_REGADDR);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_STARTUP_REGADDR, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_MISC_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_MISC_REGADDR_STATUS);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_MISC_REGADDR_STATUS, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_MODERATE_ERR_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_MODERATE_ERR_STATUS);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_MODERATE_ERR_STATUS, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_SEVERE_ERR_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_SEVERE_ERR_STATUS);
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_SEVERE_ERR_STATUS, val);
	}

	if (int_top & LPM_PMIC_INT_TOP_FSM_ERR_MASK) {
		val = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_FSM_ERR_STATUS);
		if (val & LPM_PMIC_INT_ESM_FSM_ERR_MASK) {
			val1 = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_ESM_ERR_STATUS);
			lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_ESM_ERR_STATUS, val1);
		}
		/* Clear INT_FSM_ERR */
		lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_INT_FSM_ERR_STATUS, val);
	}

	int_top = lpm_i2c_read(LPM_I2C_CTL_BASE, LPM_PMIC_INT_TOP);
}

void lpm_setup_pmic_for_retention(void)
{
	lpm_configure_i2c(LPM_PMIC_I2C_ADDR, LPM_I2C_CTL_BASE);

	/* Unlock PMIC configuration registers to enable writes to protected register space */
	lpm_i2c_write(LPM_I2C_CTL_BASE, LPM_PMIC_REGISTER_LOCK_REGADDR, LPM_PMIC_REGISTER_UNLOCK_VAL);

	/* Write magic number to scratch register to indicate the suspend */
	lpm_write_pmic(LPM_PMIC_SCRATCH_PAD_REG_3, LPM_PMIC_MAGIC_SUSPEND);

	/* Set PMIC to ACTIVE state */
	lpm_write_pmic(LPM_PMIC_FSM_NSLEEP_TRIGGERS_REGADDR, LPM_PMIC_ACTIVE_STATE);

	/* mask GPIO1_FALL interrupt */
	lpm_write_pmic(LPM_PMIC_MASK_GPIO_FALL_REGADDR, LPM_PMIC_MASK_GPIO1_FALL);

	/* unmask GPIO1_RISE interrupt */
	lpm_write_pmic(LPM_PMIC_MASK_GPIO_RISE_REGADDR, LPM_PMIC_UNMASK_GPIO1_RISE);

	/* clear remaining interrupts */
	lpm_clear_pmic_interrupts();

	/* unmask NSLEEP2 */
	lpm_write_pmic(LPM_PMIC_CONFIG1_REGADDR, LPM_PMIC_UNMASK_NSLEEP2);

	/* Set I2C_TRIGGERS_7 + I2C_TRIGGERS_5 to retain IOs and DDR */
	lpm_write_pmic(LPM_PMIC_FSM_I2C_TRIGGERS_REGADDR, LPM_PMIC_FSM_I2C_TRIGGERS_IO_DDR_RET);

	/* Make NSLEEP2_BIT = 0 */
	lpm_write_pmic(LPM_PMIC_FSM_NSLEEP_TRIGGERS_REGADDR, LPM_PMIC_CLR_NSLEEP2_BIT);
}
