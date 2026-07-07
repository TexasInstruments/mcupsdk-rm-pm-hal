/*
 * DM Stub Firmware
 *
 * am62px soc lpscs.h
 *
 * Copyright (C) 2023-2026, Texas Instruments Incorporated
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

#ifndef LPM_LPSCS_H_
#define LPM_LPSCS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <types/short_types.h>
#include <psc_raw.h>

#define LPM_PD_GP_CORE_CTL                   0       /* Main GP CORE CTL PD and its LPSCs */
#define LPM_LPSC_MAIN_ALWAYS_ON              0
#define LPM_LPSC_MAIN_DM                     1
#define LPM_LPSC_DM_PBIST                    2
#define LPM_LPSC_MAIN2DM_ISO                 3
#define LPM_LPSC_DM2MAIN_ISO                 4
#define LPM_LPSC_DM2MAIN_INFRA_ISO           5
#define LPM_LPSC_DM2CENTRAL_ISO              6
#define LPM_LPSC_CENTRAL2DM_ISO              7
#define LPM_LPSC_DM_PBIST_1                  8
#define LPM_LPSC_CSI_RX1                     9
#define LPM_LPSC_DPHY_RX1                    10
#define LPM_LPSC_CSI_TX0                     11
#define LPM_LPSC_USB0_ISO                    12
#define LPM_LPSC_USB2_ISO                    13
#define LPM_LPSC_MAIN_TEST                   14
#define LPM_LPSC_GPMC                        15
#define LPM_LPSC_MCAN1                       16
#define LPM_LPSC_MAIN_MCASP_0                17
#define LPM_LPSC_MAIN_MCASP_1                18
#define LPM_LPSC_MAIN_MCASP_2                19
#define LPM_LPSC_EMMC_8B                     20
#define LPM_LPSC_EMMC_4B_0                   21
#define LPM_LPSC_EMMC_4B_1                   22
#define LPM_LPSC_USB_0                       23
#define LPM_LPSC_USB_2                       24
#define LPM_LPSC_CSI_RX_0                    25
#define LPM_LPSC_DPHY_RX_0                   26
#define LPM_LPSC_SMS_COMMON                  27
#define LPM_LPSC_FSS_OSPI                    28
#define LPM_LPSC_TIFS                        29
#define LPM_LPSC_HSM                         30
#define LPM_LPSC_SA3UL                       31
#define LPM_LPSC_HSM_ISO                     32
#define LPM_LPSC_DEBUGSS                     33
#define LPM_LPSC_MAIN_IP                     34
#define LPM_LPSC_MAIN_MCANSS_0               35
#define LPM_LPSC_GIC                         36
#define LPM_LPSC_MAIN_PBIST                  37
#define LPM_LPSC_DPHY_TX0                    38
#define LPM_LPSC_JPEG                        39
#define LPM_LPSC_SERDES0                     40
#define LPM_LPSC_SERDES1                     41
#define LPM_LPSC_CPSW                        42
#define LPM_LPSC_GPCORE_RSVD2                43
#define LPM_LPSC_CSI_RX3                     44
#define LPM_LPSC_DPHY_RX3                    45
#define LPM_LPSC_PBIST1                      46
#define LPM_LPSC_USB1                        47
#define LPM_LPSC_CSI_RX2                     48
#define LPM_LPSC_DPHY_RX2                    49
#define LPM_LPSC_GPCORE_RSVD3                50
#define LPM_PD_GPU_CORE                      1          /* Main GPU CORE PD and its LPSCs */
#define LPM_LPSC_GPU_CORE                    51
#define LPM_PD_CPSW                          2          /* Main CPSW PD and its LPSCs */
#define LPM_LPSC_GPCORE_RSVD5                52
#define LPM_PD_A53_CLUSTER_0                 3          /* Main A53 CLUSTER0 PD and its LPSCs */
#define LPM_LPSC_A53_CLUSTER_0               53
#define LPM_LPSC_A53_CLUSTER_0_PBIST_0       54
#define LPM_LPSC_A53_CLUSTER_0_PBIST_1       55
#define LPM_PD_A53_CLUSTER_0_CORE_0          4          /* Main A53_0 PD and its LPSCs */
#define LPM_LPSC_A53_CLUSTER_0_CORE_0        56
#define LPM_PD_A53_CLUSTER_0_CORE_1          5          /* Main A53_1 PD and its LPSCs */
#define LPM_LPSC_A53_CLUSTER_0_CORE_1        57
#define LPM_PD_A53_CLUSTER_0_CORE_2          6          /* Main A53_2 PD and its LPSCs */
#define LPM_LPSC_A53_CLUSTER_0_CORE_2        58
#define LPM_PD_A53_CLUSTER_0_CORE_3          7          /* Main A53_3 PD and its LPSCs */
#define LPM_LPSC_A53_CLUSTER_0_CORE_3        59
#define LPM_PD_GPU                           8          /* Main GPU PD and its LPSCs */
#define LPM_LPSC_GPU                         60
#define LPM_LPSC_GPU_PBIST                   61
#define LPM_LPSC_PDRSVD2_RSVD0               62
#define LPM_LPSC_PDRSVD2_RSVD1               63
#define LPM_LPSC_PDRSVD2_RSVD2               64
#define LPM_PD_CODEC                         10             /* Main CODEC PD and its LPSCs */
#define LPM_LPSC_CODEC                       65
#define LPM_LPSC_CODEC_PBIST                 66
#define LPM_PD_C7X                           11             /* Main C7X PD and its LPSCs */
#define LPM_LPSC_C7X_CORE                    67
#define LPM_LPSC_C7X_PBIST                   68
#define LPM_LPSC_C7X_COMMON                  69
#define LPM_PD_VPAC                          12     /* Main VPAC PD and its LPSCs */
#define LPM_LPSC_VPAC_CORE                   70
#define LPM_LPSC_VPAC_PBIST                  71
#define LPM_PD_DDR                           13     /* Main DDR PD and its LPSCs */
#define LPM_LPSC_EMIF_LOCAL                  72
#define LPM_LPSC_EMIF_CFG_ISO                73
#define LPM_LPSC_EMIF_DATA_ISO               74
#define LPM_PD_PCIE                          14         /* Main PCIE PD and its LPSCs */
#define LPM_LPSC_PCIE0                       75
#define LPM_PD_CSDSP_1                       15         /* Main CSDSP1 CORE PD and its LPSCs */
#define LPM_LPSC_CSDSP_1_CORE                76
#define LPM_LPSC_CSDSP_1_PBIST               77
#define LPM_LPSC_CSDSP_1_COMMON              78
#define LPM_PD_MAIN_MCUSS0                   16             /* Main MCUSS0 PD and its LPSCs */
#define LPM_LPSC_MAIN_MCUSS0_CORE0           79
#define LPM_LPSC_MAIN_MCUSS0_PBIST           80
#define LPM_PD_MAIN_SRAM0                    17             /* Main SRAM0 MSRAM PD and its LPSCs */
#define LPM_LPSC_MAIN_SRAM0_MSRAM            81
#define LPM_LPSC_MAIN_SRAM0_PBIST            82
#define LPM_PD_MAIN_SRAM1                    18     /* Main SRAM1 MSRAM PD and its LPSCs */
#define LPM_LPSC_MAIN_SRAM1_MSRAM            83
#define LPM_LPSC_MAIN_SRAM1_PBIST            84
#define LPM_PD_RSVD0                         19     /* RSVD0 PD and its LPSCs */
#define LPM_LPSC_PDRSVD0_RSVD0               85
#define LPM_LPSC_PDRSVD0_RSVD1               86
#define LPM_LPSC_PDRSVD0_RSVD2               87
#define LPM_PD_RSVD1                         20     /* RSVD1 PD and its LPSCs */
#define LPM_LPSC_PDRSVD1_RSVD0               88
#define LPM_LPSC_RSVD1_RSVD1                 89
#define LPM_LPSC_RSVD1_RSVD2                 90
#define LPM_PD_DSS                           21     /* DSS PD and its LPSCs */
#define LPM_LPSC_DSS0                        91
#define LPM_LPSC_DSS1                        92
#define LPM_LPSC_DSS_DSI0                    93
#define LPM_LPSC_OLDI0                       94
#define LPM_LPSC_OLDI1                       95

#define LPM_PD_GP_CORE_CTL_MCU               0      /* MCU GP CORE CTL PD and its LPSCs */
#define LPM_LPSC_MCU_ALWAYSON                0
#define LPM_LPSC_MAIN2MCU_ISO                1
#define LPM_LPSC_DM2MCU_ISO                  2
#define LPM_LPSC_DM2SAFE_ISO                 3
#define LPM_LPSC_MCU2DM_ISO                  4
#define LPM_LPSC_MCU_TEST                    5
#define LPM_PD_MCUSS                         1      /* MCUSS PD and its LPSCs */
#define LPM_LPSC_MCU_R5                      6
#define LPM_LPSC_MCU_MCANSS0                 7
#define LPM_LPSC_MCU_MCANSS1                 8
#define LPM_LPSC_MCU_COMMON                  9
#define LPM_LPSC_MCU_PBIST                   10

#define LPM_DDR_PD                           LPM_PD_DDR       /* DDR power domain */

enum lpscs_main_phase1 {
	LPSC_PHASE1_A53_0,
	LPSC_PHASE1_A53_CLUSTER_0,
	LPSC_PHASE1_HSM,
	LPSC_PHASE1_TIFS,
	LPSC_PHASE1_DM2CENTRAL_ISO,
	LPSC_PHASE1_MAIN2DM_ISO,
	LPSC_PHASE1_DM2MAIN_ISO,
	LPSC_PHASE1_CENTRAL2DM_ISO,
	LPSC_PHASE1_MAX,
};

enum lpscs_main_phase2 {
	LPSC_PHASE2_DEBUGSS,
	LPSC_PHASE2_MAX,
};

enum lpscs_mcu {
	LPSCS_MAIN2MCU_ISO,
	LPSCS_MCU2DM_ISO,
	LPSCS_DM2MCU_ISO,
	LPSCS_MCU_TEST,
	LPSCS_MCU_COMMON,
	LPSCS_DM2SAFE_ISO,
	LPSCS_MCU_MAX,
};

enum mcu_pds {
	GP_CORE_CTL_MCU_PDS,
	MCUSS_PDS,
	MCU_PDS_MAX,
};

enum usb_lpscs {
	USB_LPSC_0,
	USB_LPSC_2,
	USB_LPSCS_MAX,
};

extern u32 num_main_lpscs_phase1;
extern u32 num_main_lpscs_phase2;
extern u32 num_mcu_lpscs;
extern u32 num_mcu_pds;
extern u32 num_usb_lpscs;

extern const struct pd_lpsc main_lpscs_phase1[LPSC_PHASE1_MAX];
extern const struct pd_lpsc main_lpscs_phase2[LPSC_PHASE2_MAX];
extern const struct pd_lpsc mcu_lpscs[LPSCS_MCU_MAX];
extern const u32 mcu_pds[MCU_PDS_MAX];
extern struct usb_lpsc usb_lpscs[USB_LPSCS_MAX];

#ifdef __cplusplus
}
#endif
#endif /* LPM_LPSCS_H_ */
