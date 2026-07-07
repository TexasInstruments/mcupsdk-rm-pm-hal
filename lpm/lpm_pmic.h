/*
 *  DM Stub Firmware
 *
 *  Minimal pmic driver to facilitate low power entry
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
 *  \file lpm_pmic.h
 *
 *  \brief This file contains the pmic function declarations used in low power modes
 */
#ifndef LPM_PMIC_H_
#define LPM_PMIC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* PMIC registers */
#define LPM_PMIC_I2C_ADDR                           (0x48U)
#define LPM_PMIC_CONFIG1_REGADDR                    (0x7DU)
#define LPM_PMIC_FSM_I2C_TRIGGERS_REGADDR           (0x85U)
#define LPM_PMIC_FSM_NSLEEP_TRIGGERS_REGADDR        (0x86U)
#define LPM_PMIC_SCRATCH_PAD_REG_3                  (0xCBU)
#define LPM_PMIC_MASK_GPIO_FALL_REGADDR             (0x4FU)
#define LPM_PMIC_MASK_GPIO_RISE_REGADDR             (0x50U)
#define LPM_PMIC_INT_TOP                            (0x5AU)
#define LPM_PMIC_INT_BUCK_STATUS                    (0x5BU)
#define LPM_PMIC_INT_LDO_VMON_STATUS                (0x5FU)
#define LPM_PMIC_INT_GPIO_REGADDR                   (0x63U)
#define LPM_PMIC_INT_STARTUP_REGADDR                (0x65U)
#define LPM_PMIC_INT_MISC_REGADDR_STATUS            (0x66U)
#define LPM_PMIC_INT_MODERATE_ERR_STATUS            (0x67U)
#define LPM_PMIC_INT_SEVERE_ERR_STATUS              (0x68U)
#define LPM_PMIC_INT_FSM_ERR_STATUS                 (0x69U)
#define LPM_PMIC_INT_ESM_ERR_STATUS                 (0x6CU)

/* INT_TOP interrupt source masks */
#define LPM_PMIC_INT_TOP_BUCK_MASK                  (1U << 0U)
#define LPM_PMIC_INT_TOP_LDO_VMON_MASK              (1U << 1U)
#define LPM_PMIC_INT_TOP_GPIO_MASK                  (1U << 2U)
#define LPM_PMIC_INT_TOP_STARTUP_MASK               (1U << 3U)
#define LPM_PMIC_INT_TOP_MISC_MASK                  (1U << 4U)
#define LPM_PMIC_INT_TOP_MODERATE_ERR_MASK          (1U << 5U)
#define LPM_PMIC_INT_TOP_SEVERE_ERR_MASK            (1U << 6U)
#define LPM_PMIC_INT_TOP_FSM_ERR_MASK               (1U << 7U)
#define LPM_PMIC_INT_ESM_FSM_ERR_MASK               (1U << 6U)
#define LPM_PMIC_INT_WD_FSM_ERR_MASK                (1U << 7U)

/* PMIC register values */
#define LPM_PMIC_MASK_GPIO1_FALL                    (0x3FU)
#define LPM_PMIC_UNMASK_GPIO1_RISE                  (0x3EU)
#define LPM_PMIC_ACTIVE_STATE                       (0x03U)
#define LPM_PMIC_MAGIC_SUSPEND                      (0xBAU)
#define LPM_PMIC_CLR_NSLEEP2_BIT                    (0x01U)
#define LPM_PMIC_FSM_I2C_TRIGGERS_IO_DDR_RET        (0xA0U)
#define LPM_PMIC_UNMASK_NSLEEP2                     (0x43U)

/* PMIC register lock/unlock */
#define LPM_PMIC_REGISTER_LOCK_REGADDR              (0xA1U)
#define LPM_PMIC_REGISTER_UNLOCK_VAL                (0x9BU)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Configure PMIC to keep only selected power rails on during low power modes
 */
void lpm_setup_pmic_for_retention(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef LPM_PMIC_H_*/
