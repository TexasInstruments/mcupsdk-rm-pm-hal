/*
 * Interrupt Aggregator
 *
 * Interrupt aggregator driver instance data definition
 *
 * Data version: 240826_164236
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
#include <soc/am62px/resasg_types.h>
#include <soc/am62px/soc_devgrps.h>

#include "../../include/ia_inst.h"
#include "ia_cfg.h"

static const struct rm_mmr mmr_DMASS0_INTAGGR_0_INTAGGR_IMAP = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x48100000U,
};

static const struct rm_mmr mmr_DMASS0_INTAGGR_0_INTAGGR_INTR = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x48000000U,
};

static const struct rm_mmr mmr_DMASS0_INTAGGR_0_INTAGGR_GCNTRTI = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x4a000000U,
};

static const struct rm_mmr mmr_DMASS0_INTAGGR_0_INTAGGR_UNMAP = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x48180000U,
};

static u8 vint_usage_count_DMASS0_INTAGGR_0[184U];

static struct ia_used_mapping rom_usage_DMASS0_INTAGGR_0[1U] = {
	{
		.event = 30U,
		.cleared = SFALSE,
	},
};

static struct ia_used_mapping rom_usage_unmapped_events_DMASS0_INTAGGR_0[1U] = {
	{
		.event = 5651U,
		.cleared = SFALSE,
	},
};

static const struct ia_resource_type unmapped_events_DMASS0_INTAGGR_0[14U] = {
	{
		.start = 4096U,
		.end = 4124U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_PKTDMA_TX_CHAN_ERROR_OES),
	},
	{
		.start = 4608U,
		.end = 4706U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_PKTDMA_TX_FLOW_COMPLETION_OES),
	},
	{
		.start = 5120U,
		.end = 5143U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_PKTDMA_RX_CHAN_ERROR_OES),
	},
	{
		.start = 5632U,
		.end = 5682U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_PKTDMA_RX_FLOW_COMPLETION_OES),
	},
	{
		.start = 6144U,
		.end = 6194U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_PKTDMA_RX_FLOW_STARVATION_OES),
	},
	{
		.start = 8192U,
		.end = 8223U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_CHAN_ERROR_OES),
	},
	{
		.start = 8704U,
		.end = 8735U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_CHAN_DATA_COMPLETION_OES),
	},
	{
		.start = 9216U,
		.end = 9247U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_CHAN_RING_COMPLETION_OES),
	},
	{
		.start = 9728U,
		.end = 9752U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_ERROR_OES),
	},
	{
		.start = 10240U,
		.end = 10264U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_DATA_COMPLETION_OES),
	},
	{
		.start = 10752U,
		.end = 10776U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_RING_COMPLETION_OES),
	},
	{
		.start = 11264U,
		.end = 11288U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_ERROR_OES),
	},
	{
		.start = 11776U,
		.end = 11800U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_DATA_COMPLETION_OES),
	},
	{
		.start = 12288U,
		.end = 12312U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_RING_COMPLETION_OES),
	},
};

static const struct rm_mmr mmr_DMASS1_INTAGGR_0_INTAGGR_IMAP = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x4e0b0000U,
};

static const struct rm_mmr mmr_DMASS1_INTAGGR_0_INTAGGR_INTR = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x4e400000U,
};

static const struct rm_mmr mmr_DMASS1_INTAGGR_0_INTAGGR_GCNTRTI = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x4e000000U,
};

static const struct rm_mmr mmr_DMASS1_INTAGGR_0_INTAGGR_UNMAP = {
	.fwl_id		= RM_MMR_FWL_INVALID,
	.fwl_ch_start	= 0U,
	.fwl_ch_end	= 0U,
	.base		= 0x4e040000U,
};

static u8 vint_usage_count_DMASS1_INTAGGR_0[8U];

static struct ia_used_mapping rom_usage_unmapped_events_DMASS1_INTAGGR_0[1U] = {
	{
		.event = 5651U,
		.cleared = SFALSE,
	},
};

static const struct ia_resource_type unmapped_events_DMASS1_INTAGGR_0[3U] = {
	{
		.start = 3072U,
		.end = 3077U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS1_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_ERROR_OES),
	},
	{
		.start = 3584U,
		.end = 3589U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS1_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_DATA_COMPLETION_OES),
	},
	{
		.start = 4096U,
		.end = 4101U,
		.utype = RESASG_UTYPE(AM62PX_DEV_DMASS1_INTAGGR_0, RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_RING_COMPLETION_OES),
	},
};

struct ia_instance ia_inst[IA_INST_COUNT] = {
	{
		.id = AM62PX_DEV_DMASS0_INTAGGR_0,
		.initialized = SFALSE,
		.devgrp = SOC_DEVGRP_AM62PX_MAIN,
		.imap = &mmr_DMASS0_INTAGGR_0_INTAGGR_IMAP,
		.intr = &mmr_DMASS0_INTAGGR_0_INTAGGR_INTR,
		.gcntrti = &mmr_DMASS0_INTAGGR_0_INTAGGR_GCNTRTI,
		.unmap = &mmr_DMASS0_INTAGGR_0_INTAGGR_UNMAP,
		.sevt_offset = 0U,
		.n_sevt = 1536U,
		.vint_utype = RESASG_UTYPE(AM62PX_DEV_DMASS0_INTAGGR_0, RESASG_SUBTYPE_IA_VINT),
		.n_vint = 184U,
		.vint_usage_count = &vint_usage_count_DMASS0_INTAGGR_0[0U],
		.v0_b0_evt = 0U,
		.rom_usage = &rom_usage_DMASS0_INTAGGR_0[0U],
		.n_rom_usage = ARRAY_SIZE(rom_usage_DMASS0_INTAGGR_0),
		.rom_usage_unmapped_events = &rom_usage_unmapped_events_DMASS0_INTAGGR_0[0U],
		.n_rom_usage_unmapped_events = ARRAY_SIZE(rom_usage_unmapped_events_DMASS0_INTAGGR_0),
		.unmapped_events = &unmapped_events_DMASS0_INTAGGR_0[0U],
		.n_unmapped_events = ARRAY_SIZE(unmapped_events_DMASS0_INTAGGR_0),
	},
	{
		.id = AM62PX_DEV_DMASS1_INTAGGR_0,
		.initialized = SFALSE,
		.devgrp = SOC_DEVGRP_AM62PX_MAIN,
		.imap = &mmr_DMASS1_INTAGGR_0_INTAGGR_IMAP,
		.intr = &mmr_DMASS1_INTAGGR_0_INTAGGR_INTR,
		.gcntrti = &mmr_DMASS1_INTAGGR_0_INTAGGR_GCNTRTI,
		.unmap = &mmr_DMASS1_INTAGGR_0_INTAGGR_UNMAP,
		.sevt_offset = 12288U,
		.n_sevt = 128U,
		.vint_utype = RESASG_UTYPE(AM62PX_DEV_DMASS1_INTAGGR_0, RESASG_SUBTYPE_IA_VINT),
		.n_vint = 8U,
		.vint_usage_count = &vint_usage_count_DMASS1_INTAGGR_0[0U],
		.v0_b0_evt = 0U,
		.rom_usage = NULL,
		.n_rom_usage = 0U,
		.rom_usage_unmapped_events = &rom_usage_unmapped_events_DMASS1_INTAGGR_0[0U],
		.n_rom_usage_unmapped_events = ARRAY_SIZE(rom_usage_unmapped_events_DMASS1_INTAGGR_0),
		.unmapped_events = &unmapped_events_DMASS1_INTAGGR_0[0U],
		.n_unmapped_events = ARRAY_SIZE(unmapped_events_DMASS1_INTAGGR_0),
	},
};
