/*
 * Device Manager - LPM interface
 *
 * Handlers for Low Power Mode implementation for boardcfg based LPM
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

#include <tisci/tisci_protocol.h>
#include <tisci/lpm/tisci_lpm.h>
#include <lib/trace_protocol.h>
#include <types/short_types.h>
#include <types/errno.h>
#include <lib/trace.h>
#include <lib/io.h>
#include <osal_hwi.h>
#include <boardcfg/boardcfg.h>
#include <boardcfg/boardcfg_pm_data.h>
#include <device.h>
#include <cache.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define LPM_TCMB_STACK_POINTER  (0x41014000U)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

extern void lpm_enter_low_power_mode(u32 mode);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

s32 lpm_enter_sleep_handler(u32 *msg_recv)
{
	struct tisci_msg_enter_sleep_req *req =
		(struct tisci_msg_enter_sleep_req *) msg_recv;
	s32 ret = SUCCESS;
	u8 mode = TISCI_MSG_VALUE_SLEEP_MODE_INVALID;

	pm_trace(TRACE_PM_ACTION_MSG_RECEIVED, TISCI_MSG_ENTER_SLEEP);

	if (ret == SUCCESS) {
		mode = req->mode;
	}

	/* Check if the input mode is valid */
	if (ret == SUCCESS) {
		if ((mode != TISCI_MSG_VALUE_SLEEP_MODE_SOC_OFF) &&
		    (mode != TISCI_MSG_VALUE_SLEEP_MODE_IO_ONLY_PLUS_DDR)) {
			ret = -EINVAL;
		} else {
			/* de-initialize all device flags before powering off to ensure
			 * that no statle state persists after wakeup from low power mode
			 */
			devices_deinit_flags();

			/* disable interrupts to ensure that the suspend sequence executes
			 * atomically without interference.
			 */
			(void) osal_hwip_disable();

			/* flush all dirty cache lines to ddr to maintain memory consistency */
			cache_wb_data();

			asm volatile ("mov sp, %0" : : "r" (LPM_TCMB_STACK_POINTER));

			/* jump to entry point of the DM stub in TCMB */
			lpm_enter_low_power_mode(mode);
		}
	}

	return ret;
}

s32 lpm_wake_reason_handler(u32 *msg_recv)
{
	s32 ret = -EFAIL;

	pm_trace(TRACE_PM_ACTION_MSG_RECEIVED, TISCI_MSG_LPM_WAKE_REASON);

	return ret;
}

s32 lpm_get_next_sys_mode(u32 *msg_recv)
{
	s32 ret = SUCCESS;
	struct boardcfg_pm_lpm_cfg *lpm_local;
	struct tisci_msg_lpm_get_next_sys_mode_resp *resp =
		(struct tisci_msg_lpm_get_next_sys_mode_resp *) msg_recv;

	pm_trace(TRACE_PM_ACTION_MSG_RECEIVED, TISCI_MSG_LPM_GET_NEXT_SYS_MODE);

	resp->hdr.flags = 0U;
	resp->mode = TISCI_MSG_VALUE_SLEEP_MODE_INVALID;
	bool lpm_bcfg_valid = is_lpm_boardcfg_valid();
	if (lpm_bcfg_valid == true) {
		lpm_local = (struct boardcfg_pm_lpm_cfg *) boardcfg_pm_extract_lpm_cfg();
		if (lpm_local == NULL) {
			ret = -EFAIL;
		}

		if (ret == SUCCESS) {
			resp->mode = lpm_local->boardcfg_lpm_mode;
		}
	} else {
		ret = -EFAIL;
	}

	return ret;
}
