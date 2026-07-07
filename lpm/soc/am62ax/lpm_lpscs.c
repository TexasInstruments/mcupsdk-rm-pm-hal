/*
 * DM Stub Firmware
 *
 * am62ax soc lpscs.c
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

#include <lpm_lpscs.h>

/* MAIN LPSCs to be disabled during Deepsleep phase 1 */
const struct pd_lpsc main_lpscs_phase1[LPSC_PHASE1_MAX] = {
	{ LPM_PD_A53_0,		LPM_LPSC_A53_0				},
	{ LPM_PD_A53_1,		LPM_LPSC_A53_1				},
	{ LPM_PD_A53_2,		LPM_LPSC_A53_2				},
	{ LPM_PD_A53_3,		LPM_LPSC_A53_3				},
	{ LPM_PD_A53_CLUSTER_0, LPM_LPSC_A53_CLUSTER_0_PBIST_0		},
	{ LPM_PD_A53_CLUSTER_0, LPM_LPSC_A53_CLUSTER_0			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_HSM				},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_TIFS				},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_FSS_OSPI			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_DM_PBIST			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_DM_PBIST_1			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_GPMC				},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_MAIN_MCASP_0			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_MAIN_MCASP_1			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_MAIN_MCASP_2			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_EMMC_8B			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_EMMC_4B_0			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_EMMC_4B_1			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_CSI_RX_0			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_DPHY_0				},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_MAIN_MCANSS_0			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_GIC				},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_MAIN_PBIST			},
	{ LPM_PD_CPSW,		LPM_LPSC_CPSW3G				},
	{ LPM_PD_DSS,		LPM_LPSC_DSS				},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_JPEG				},
	{ LPM_PD_VPAC,		LPM_LPSC_VPAC_CORE			},
	{ LPM_PD_VPAC,		LPM_LPSC_VPAC_PBIST			},
	{ LPM_PD_CODEC,		LPM_LPSC_CODEC_PBIST			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_DM2CENTRAL_ISO			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_MAIN2DM_ISO			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_DM2MAIN_ISO			},
	{ LPM_PD_GP_CORE_CTL,	LPM_LPSC_CENTRAL2DM_ISO			}
};

u32 num_main_lpscs_phase1 = sizeof(main_lpscs_phase1) / sizeof(struct pd_lpsc);

/* MAIN LPSCs to be disabled during Deepsleep phase 2 */
const struct pd_lpsc main_lpscs_phase2[LPSC_PHASE2_MAX] = {
	{ LPM_PD_GP_CORE_CTL, LPM_LPSC_DEBUGSS	  }
};

u32 num_main_lpscs_phase2 = sizeof(main_lpscs_phase2) / sizeof(struct pd_lpsc);

/* MCU LPSCs to be disabled during Deepsleep */
const struct pd_lpsc mcu_lpscs[LPSCS_MCU_MAX] = {
	{ LPM_PD_GP_CORE_CTL_MCU, LPM_LPSC_MAIN2MCU_ISO	       },
	{ LPM_PD_GP_CORE_CTL_MCU, LPM_LPSC_DM2MCU_ISO	       },
	{ LPM_PD_GP_CORE_CTL_MCU, LPM_LPSC_MCU2DM_ISO	       },
	{ LPM_PD_GP_CORE_CTL_MCU, LPM_LPSC_MCU_TEST	       },
	{ LPM_PD_MCUSS,		  LPM_LPSC_MCU_PBIST	       },
	{ LPM_PD_MCUSS,		  LPM_LPSC_MCU_MCANSS0	       },
	{ LPM_PD_MCUSS,		  LPM_LPSC_MCU_MCANSS1	       },
};

u32 num_mcu_lpscs = sizeof(mcu_lpscs) / sizeof(struct pd_lpsc);

/* MCU PDs to be disabled during Deepsleep */
const u32 mcu_pds[MCU_PDS_MAX] = {
	LPM_PD_GP_CORE_CTL_MCU,
};

u32 num_mcu_pds = sizeof(mcu_pds) / sizeof(u32);

/* USB LPSCs to be saved and restored during Deepsleep */
struct usb_lpsc usb_lpscs[USB_LPSCS_MAX] = {
	{ LPM_PD_GP_CORE_CTL, LPM_LPSC_USB_0, LPM_LPSC_MAIN_USB0_ISO, 0U	},
	{ LPM_PD_GP_CORE_CTL, LPM_LPSC_USB_1, LPM_LPSC_MAIN_USB1_ISO, 0U	},
};

u32 num_usb_lpscs = sizeof(usb_lpscs) / sizeof(struct usb_lpsc);
