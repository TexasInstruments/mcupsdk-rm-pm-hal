/*
 * Interrupt Router
 *
 * Interrupt router driver instance data definition
 *
 * Data version: 240122_143513
 *
 * Copyright (C) 2023-2025, Texas Instruments Incorporated
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

#include <types/short_types.h>
#include <types/array_size.h>
#include <types/sbool.h>
#include <soc/rm_mmr.h>
#include <devices.h>
#include <soc/j722s/resasg_types.h>
#include <soc/j722s/soc_devgrps.h>

#include "../../include/ir_inst.h"
#include "ir_cfg.h"

static const struct rm_mmr mmr_MAIN_GPIOMUX_INTROUTER0_INTR_ROUTER_CFG = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0xa00000U,
};

static const struct rm_mmr mmr_WKUP_MCU_GPIOMUX_INTROUTER0_INTR_ROUTER_CFG = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x4210000U,
};

static const struct rm_mmr mmr_TIMESYNC_EVENT_INTROUTER0_INTR_ROUTER_CFG = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0xa40000U,
};

struct ir_instance ir_inst[IR_INST_COUNT] = {
	{
		.id = J722S_DEV_MAIN_GPIOMUX_INTROUTER0,
		.initialized = SFALSE,
		.devgrp = SOC_DEVGRP_J722S_MAIN,
		.int_enable = STRUE,
		.cfg = &mmr_MAIN_GPIOMUX_INTROUTER0_INTR_ROUTER_CFG,
		.n_inp = 200U,
		.n_outp = 36U,
		.inp0_mapping = 0U,
		.outp_utype = RESASG_UTYPE(J722S_DEV_MAIN_GPIOMUX_INTROUTER0, RESASG_SUBTYPE_IR_OUTPUT),
		.rom_usage = NULL,
		.n_rom_usage = 0U,
	},
	{
		.id = J722S_DEV_WKUP_MCU_GPIOMUX_INTROUTER0,
		.initialized = SFALSE,
		.devgrp = SOC_DEVGRP_J722S_MCU_WAKEUP,
		.int_enable = STRUE,
		.cfg = &mmr_WKUP_MCU_GPIOMUX_INTROUTER0_INTR_ROUTER_CFG,
		.n_inp = 32U,
		.n_outp = 16U,
		.inp0_mapping = 0U,
		.outp_utype = RESASG_UTYPE(J722S_DEV_WKUP_MCU_GPIOMUX_INTROUTER0, RESASG_SUBTYPE_IR_OUTPUT),
		.rom_usage = NULL,
		.n_rom_usage = 0U,
	},
	{
		.id = J722S_DEV_TIMESYNC_EVENT_INTROUTER0,
		.initialized = SFALSE,
		.devgrp = SOC_DEVGRP_J722S_MAIN,
		.int_enable = STRUE,
		.cfg = &mmr_TIMESYNC_EVENT_INTROUTER0_INTR_ROUTER_CFG,
		.n_inp = 20U,
		.n_outp = 26U,
		.inp0_mapping = 0U,
		.outp_utype = RESASG_UTYPE(J722S_DEV_TIMESYNC_EVENT_INTROUTER0, RESASG_SUBTYPE_IR_OUTPUT),
		.rom_usage = NULL,
		.n_rom_usage = 0U,
	},
};
