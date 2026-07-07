/*
 * DM Stub Firmware
 *
 * lpm_i2c.h - Bare-metal I2C register definitions and API for LPM PMIC
 * communication.
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

#ifndef LPM_I2C_H_
#define LPM_I2C_H_

#include <types/short_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* System Configuration register */
#define LPM_I2C_SYSC_REG                                   (0x10U)
/* Per-event raw interrupt status vector */
#define LPM_I2C_IRQSTATUS_RAW_REG                          (0x24U)
/* Per-event enabled interrupt status vector */
#define LPM_I2C_IRQSTATUS_REG                              (0x28U)
/* System Status register */
#define LPM_I2C_SYSS_REG                                   (0x90U)
/* Buffer Configuration register */
#define LPM_I2C_BUF_REG                                    (0x94U)
/* Data counter register */
#define LPM_I2C_CNT_REG                                    (0x98U)
/* Data access register */
#define LPM_I2C_DATA_REG                                   (0x9CU)
/* I2C configuration register */
#define LPM_I2C_CON_REG                                    (0xA4U)
/* Own address register */
#define LPM_I2C_OA_REG                                     (0xA8U)
/* Target address register */
#define LPM_I2C_SA_REG                                     (0xACU)
/* I2C Clock Prescaler Register */
#define LPM_I2C_PSC_REG                                    (0xB0U)
/* I2C SCL Low Time Register */
#define LPM_I2C_SCLL_REG                                   (0xB4U)
/* I2C SCL High Time Register */
#define LPM_I2C_SCLH_REG                                   (0xB8U)

#define LPM_I2C_SYSC_SRST_SHIFT                            (1U)
#define LPM_I2C_SYSC_IDLEMODE_SHIFT                        (3U)
#define LPM_I2C_IRQSTATUS_RAW_ARDY_SHIFT                   (2U)
#define LPM_I2C_IRQSTATUS_RAW_RRDY_SHIFT                   (3U)
#define LPM_I2C_IRQSTATUS_RAW_XRDY_SHIFT                   (4U)
#define LPM_I2C_IRQSTATUS_RAW_BB_SHIFT                     (12U)
#define LPM_I2C_IRQSTATUS_XRDY_SHIFT                       (4U)
#define LPM_I2C_SYSC_SRST_MASK                             (0x00000002U)
#define LPM_I2C_SYSC_IDLEMODE_MASK                         (0x00000008U)
#define LPM_I2C_IRQSTATUS_RAW_ARDY_MASK                    (0x00000004U)
#define LPM_I2C_IRQSTATUS_RAW_RRDY_MASK                    (0x00000008U)
#define LPM_I2C_IRQSTATUS_RAW_XRDY_MASK                    (0x00000010U)
#define LPM_I2C_IRQSTATUS_RAW_BB_MASK                      (0x00001000U)
#define LPM_I2C_IRQSTATUS_XRDY_MASK                        (0x00000010U)
#define LPM_I2C_SYSS_RDONE_MASK                            (0x00000001U)
#define LPM_I2C_BUF_TXFIFO_CLR_SHIFT                       (6U)
#define LPM_I2C_BUF_TXFIFO_CLR_MASK                        (0x00000040U)
#define LPM_I2C_BUF_XDMA_EN_MASK                           (0x00000080U)
#define LPM_I2C_BUF_RXFIFO_CLR_SHIFT                       (14U)
#define LPM_I2C_BUF_RXFIFO_CLR_MASK                        (0x00004000U)
#define LPM_I2C_BUF_RDMA_EN_MASK                           (0x00008000U)
#define LPM_I2C_CNT_ONE_BYTE                               (1U)
#define LPM_I2C_CNT_TWO_BYTES                              (2U)
#define LPM_I2C_CNT_DCOUNT_MAX                             (0x0000ffffU)
#define LPM_I2C_CON_STT_SHIFT                              (0U)
#define LPM_I2C_CON_STT_MASK                               (0x00000001U)
#define LPM_I2C_CON_STP_MASK                               (0x00000002U)
#define LPM_I2C_CON_XSA_MASK                               (0x00000100U)
#define LPM_I2C_CON_TRX_MASK                               (0x00000200U)
#define LPM_I2C_CON_MST_MASK                               (0x00000400U)
#define LPM_I2C_CON_STB_MASK                               (0x00000800U)
#define LPM_I2C_CON_RESERVED_MASK                          (0x00004000U)
#define LPM_I2C_CON_I2C_EN_MASK                            (0x00008000U)

#define LPM_I2C_CON_WRITE_MASK                             (LPM_I2C_CON_STT_MASK \
							    | LPM_I2C_CON_STP_MASK \
							    | LPM_I2C_CON_XSA_MASK \
							    | LPM_I2C_CON_TRX_MASK \
							    | LPM_I2C_CON_MST_MASK \
							    | LPM_I2C_CON_STB_MASK \
							    | LPM_I2C_CON_RESERVED_MASK	\
							    | LPM_I2C_CON_I2C_EN_MASK)

#define LPM_I2C_CON_TRX_SHIFT                              (9U)
#define LPM_I2C_CON_MST_SHIFT                              (10U)
#define LPM_I2C_CON_I2C_EN_SHIFT                           (15U)
#define LPM_I2C_OA_OA_MASK                                 (0x000003FFU)
#define LPM_I2C_SA_SA_MASK                                 (0x000003FFU)

#define LPM_I2C_PRESCALER_DIVIDER_12MHZ                    (0x7U)
#define LPM_I2C_SCLL_16                                    (0x9U)
#define LPM_I2C_SCLH_14                                    (0x9U)
#define LPM_I2C_OWN_ADDR                                   (0xB4U)

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Write one byte to an I2C target register.
 *
 * \param i2c_base  Base address of the I2C controller.
 * \param add       Target register address byte.
 * \param data      Data byte to write.
 */
void lpm_i2c_write(u32 i2c_base, u8 add, u8 data);

/**
 * \brief Read one byte from an I2C target register.
 *
 * \param i2c_base  Base address of the I2C controller.
 * \param add       Target register address byte.
 * \return          Data byte read from the target.
 */
u8 lpm_i2c_read(u32 i2c_base, u8 add);

/**
 * \brief Initialise an I2C controller for PMIC communication.
 *
 * Configures pad receivers, soft-resets the controller, sets the SCL
 * clock for 400 kHz Fast Mode, and programs the target slave address.
 *
 * \param pmic      I2C slave address of the PMIC to target.
 * \param i2c_base  Base address of the I2C controller to configure.
 */
void lpm_configure_i2c(u8 pmic, u32 i2c_base);

#ifdef __cplusplus
}
#endif
#endif  /* LPM_I2C_H_ */
