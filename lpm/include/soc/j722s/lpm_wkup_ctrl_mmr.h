/*
 * DM Stub Firmware
 *
 * j722s lpm_wkup_ctrl_mmr.h
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

#ifndef LPM_WKUP_CTRL_MMR_H_
#define LPM_WKUP_CTRL_MMR_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LPM_WKUP_CLKSEL                     (0x00008010U)
#define LPM_DDR16SS_PMCTRL                  (0x000080d0U)
#define LPM_WKUP_WWD0_CTRL                  (0x00008340U)
#define LPM_CHNG_DDR4_FSP_REQ               (0x00014000U)
#define LPM_CHNG_DDR4_FSP_ACK               (0x00014004U)
#define LPM_DDR4_FSP_CLKCHNG_REQ            (0x00014080U)
#define LPM_DDR4_FSP_CLKCHNG_ACK            (0x000140C0U)
#define LPM_PMCTRL_SYS                      (0x00018080U)
#define LPM_PMCTRL_IO_0                     (0x00018084U)
#define LPM_PMCTRL_MOSC                     (0x00018090U)
#define LPM_RST_CTRL                        (0x00018170U)
#define LPM_CANUART_WAKE_CTRL               (0x00018300U)
#define LPM_CANUART_WAKE_STAT1              (0x0001830CU)
#define LPM_CANUART_WAKE_OFF_MODE           (0x00018310U)
#define LPM_SLEEP_STATUS                    (0x00018410U)
#define LPM_DS_MAGIC_WORD                   (0x00018418U)
#define LPM_DS_MAIN                         (0x00018420U)
#define LPM_DS_DM_RESET                     (0x00018440U)
#define LPM_DS_DDR0_RESET                   (0x00018450U)
#define LPM_DS_USB0_RESET                   (0x00018460U)
#define LPM_DS_USB1_RESET                   (0x00018464U)
#define LPM_DM_CLKSTOP_EN                   (0x00018480U)
#define LPM_DM_CLKSTOP_ACK                  (0x00018490U)
#define LPM_DM_GRP_CLKSTOP_REQ              (0x000184A0U)
#define LPM_DM_GRP_CLKSTOP_ACK              (0x000184A4U)

/* PMCTRL IO0(WKUP) and IO1(MAIN) IOs */
#define LPM_WKUP_CTRL_PMCTRL_IO_0                          (0x18084U)
#define LPM_WKUP_CTRL_PMCTRL_IO_1                          (0x18088U)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_ISOCLK_OVRD              BIT(0)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_ISOOVR_EXTEND            BIT(4)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_ISO_BYPASS               BIT(6)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_WUCLK_CTRL               BIT(8)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_STATUS            BIT(25)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_GLOBAL_WUEN              BIT(16)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_CTRL              BIT(24)
#define LPM_WKUP_CTRL_PMCTRL_IO_0_WUCLK_STATUS_ENABLED     1U
#define LPM_WKUP_CTRL_PMCTRL_IO_0_WUCLK_STATUS_DISABLED    0U
#define LPM_WKUP_CTRL_PMCTRL_IO_0_WRITE_MASK               (LPM_WKUP_CTRL_PMCTRL_IO_0_ISOCLK_OVRD	    \
							    | LPM_WKUP_CTRL_PMCTRL_IO_0_ISOOVR_EXTEND  \
							    | LPM_WKUP_CTRL_PMCTRL_IO_0_ISO_BYPASS	 \
							    | LPM_WKUP_CTRL_PMCTRL_IO_0_WUCLK_CTRL	 \
							    | LPM_WKUP_CTRL_PMCTRL_IO_0_GLOBAL_WUEN    \
							    | LPM_WKUP_CTRL_PMCTRL_IO_0_IO_ISO_CTRL)

/* PADCONFIG */
#define LPM_PADCONFIG_RX_ACTIVE                     BIT(18)
#define LPM_PADCONFIG_ISO_BYPASS_PAD                BIT(23)
#define LPM_MCU_PADCONFIG_WRITE_MASK                (LPM_PADCONFIG_ISO_BYPASS_PAD \
						     | LPM_PADCONFIG_RX_ACTIVE)

/* IOs DEEPSLEEP CTRL */
#define LPM_WKUP_CTRL_DEEPSLEEP_CTRL                (0x18160U)
#define LPM_WKUP_CTRL_DEEPSLEEP_CTRL_ENABLE_IO      (0x101U)
#define LPM_WKUP_CTRL_DEEPSLEEP_CTRL_DISABLE_IO     0U

/* PMCTRL IOs GLOBAL CTRL */
#define LPM_WKUP_CTRL_PMCTRL_IO_GLB                 (0x1809CU)
#define LPM_WKUP_CTRL_PMCTRL_IO_GLB_ENABLE_IO       1U
#define LPM_WKUP_CTRL_PMCTRL_IO_GLB_DISABLE_IO      0U

/* CANUART WAKE CTRL */
#define LPM_WKUP_CANUART_CTRL               (0x00018300U)
#define LPM_WKUP_CANUART_WAKE_STAT0         (0x00018308U)
#define LPM_WKUP_CANUART_WAKE_STAT1         (0x0001830CU)
#define LPM_WKUP_CANUART_MAGIC_WRD          (0x2AAAAAAAU << 1U)
#define LPM_WKUP_CANUART_MAGIC_WRD_LD_EN    (0x1U)
#define LPM_WKUP_CANUART_MAGIC_WRD_LD_DIS   (0x0U)
#define LPM_WKUP_CANUART_IO_MODE_ACTIVE     (0x1U)

/* WKUP_PMCTRL_SYS */
#define LPM_WKUP0_PMCTRL_SYS                (0x00018080U)
#define LPM_WKUP0_PMCTRL_SYS_EN_DS          (0x5U)
#define LPM_WKUP0_PMCTRL_SYS_EN_PMIC        (0x0U)
#define LPM_WKUP0_PMIC_OUT_EN               (0x10U)
#define LPM_WKUP0_PMIC_OUT_DIS              (0x0U)

/* LPM_WKUP0_EN */
#define LPM_WKUP0_EN                        (0x00018180U)

#define LPM_WKUP0_EN_WKUP_I2C0              BIT(0)
#define LPM_WKUP0_EN_WKUP_USART0            BIT(1)
#define LPM_WKUP0_EN_MCU_GPIO0              BIT(2)
#define LPM_WKUP0_EN_DEBUG                  BIT(3)
#define LPM_WKUP0_EN_MCU_M4F_INT            BIT(4)
#define LPM_WKUP0_EN_WKUP_DMTIMER0          BIT(5)
#define LPM_WKUP0_EN_WKUP_DMTIMER1          BIT(6)
#define LPM_WKUP0_EN_WKUP_RTC               BIT(7)
#define LPM_WKUP0_EN_MAIN_RESET_REQZ        BIT(8)
#define LPM_WKUP0_EN_USB0                   BIT(9)
#define LPM_WKUP0_EN_USB1                   BIT(10)
#define LPM_WKUP0_EN_MAIN_IO_DAISY_CHAIN    BIT(16)
#define LPM_WKUP0_EN_MCU_IO_DAISY_CHAIN     BIT(17)
#define LPM_WKUP0_EN_CANUART_IO_DAISY_CHAIN BIT(18)

/* WKUP_EN_CLKSTOP */
#define LPM_WKUP_EN_CLKSTOP_ALL             (0x00030009U)

#define LPM_WKUP_EN_CLKSTOP_WKUP_I2C0       BIT(0)
#define LPM_WKUP_EN_CLKSTOP_WKUP_USART0     BIT(3)
#define LPM_WKUP_EN_CLKSTOP_WKUP_DMTIMER0   BIT(16)
#define LPM_WKUP_EN_CLKSTOP_WKUP_DMTIMER1   BIT(17)
#define LPM_WKUP_EN_GRP_CLKSTOP_REQ         BIT(0)
#define LPM_WKUP_DIS_GRP_CLKSTOP_REQ        0U
#define LPM_WKUP_EN_GRP_CLKSTOP_ACK         BIT(0)
#define LPM_WKUP_DIS_GRP_CLKSTOP_ACK        0U

/* LPM_WKUP_CLKSEL */
#define LPM_WKUP_CLKSEL_MAIN                0U
#define LPM_WKUP_CLKSEL_MCU                 1U

/* LPM_DDR16SS_PMCTRL */
#define LPM_DDR16SS_RETENTION_DIS           0U
#define LPM_DDR16SS_RETENTION_EN            0x6U
#define LPM_DDR16SS_DATA_RET_LD_BIT         31U
#define LPM_DDR16SS_DATA_RET_LD_OPEN        0x1U
#define LPM_DDR16SS_DATA_RET_LD_CLOSE       0x0U

/* LPM_WKUP_WWD0_CTRL */
#define LPM_WWD_RUN                         0U
#define LPM_WWD_STOP                        0xA

/* LPM_CHNG_DDR4_FSP_REQ */
#define LPM_CHNG_DDR4_FSP_REQ_SET           BIT(8)
#define LPM_CHNG_DDR4_FSP_REQ_CLR           0U
#define LPM_CHNG_DDR4_FSP_REQ_TYPE_MASK     0x3U
#define LPM_CHNG_DDR4_FSP_REQ_TYPE_FSP0     0x0U
#define LPM_CHNG_DDR4_FSP_REQ_TYPE_FSP2     0x2U

/* LPM_CHNG_DDR4_FSP_ACK */
#define LPM_CHNG_DDR4_FSP_CHNG_ACK          BIT(7)
#define LPM_CHNG_DDR4_FSP_CHNG_ERR          BIT(0)

/* LPM_DDR4_FSP_CLKCHNG_REQ */
#define LPM_DDR4_FSP_CLKCHNG_REQ_SET        BIT(7)
#define LPM_DDR4_FSP_CLKCHNG_REQ_CLR        0U
#define LPM_DDR4_FSP_CLKCHNG_REQ_TYPE_MASK  0x3U
#define LPM_DDR4_FSP_CLKCHNG_REQ_TYPE_FSP0  0x0U
#define LPM_DDR4_FSP_CLKCHNG_REQ_TYPE_FSP2  0x2U

/* LPM_DDR4_FSP_CLKCHNG_ACK */
#define LPM_DDR4_FSP_CLKCHNG_REQ_ACK        BIT(0)

/* LPM_PMCTRL_MOSC */
#define LPM_PMCTRL_MOSC_OSC_CG_ON_WFI       BIT(31)

/* LPM_RST_CTRL */
#define LPM_RST_CTRL_MAIN_RST_ISO_DONE_Z    BIT(18)

/* CANUART WAKE STAT1 */
#define LPM_WKUP_CANUART_CAN_IO_ISO_SET     (0x1U)
#define LPM_WKUP_CANUART_CAN_IO_ISO_CLRD    (0x0U)

/* CANUART WAKE OFF MODE */
#define LPM_WKUP_CANUART_OFF_MAGIC_WORD     (0x555555)

/* LPM_SLEEP_STATUS */
#define LPM_SLEEP_STATUS_MAIN_RESETSTATZ    BIT(8)

/* LPM_DS_MAGIC_WORD */
#define LPM_DS_MAGIC_WORD_RESUME_TIFS       0xdee51ee5U
#define LPM_DS_MAGIC_WORD_RESUME_ROM        0x00d5d02eU

/* LPM_DS_MAIN */
#define LPM_DS_MAIN_OFF                     0x6U
#define LPM_DS_MAIN_ON                      0xFU

/* Deep Sleep reset mask and unmask */
#define LPM_DS_RESET_MASK                   0x6U
#define LPM_DS_RESET_UNMASK                 0xFU

#ifdef __cplusplus
}
#endif
#endif /* LPM_WKUP_CTRL_MMR_H_ */
