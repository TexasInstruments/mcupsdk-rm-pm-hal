/*
 * Resource Management
 *
 * Resource Assignment Subtype definitions
 *
 * Data version: 230724_185448
 *
 * Copyright (C) 2023, Texas Instruments Incorporated
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
#ifndef RESASG_TYPES_H
#define RESASG_TYPES_H

/**
 * Resource assignment type shift
 */
#define RESASG_TYPE_SHIFT (0x0006U)
/**
 * Resource assignment type mask
 */
#define RESASG_TYPE_MASK (0xFFC0U)
/**
 * Resource assignment subtype shift
 */
#define RESASG_SUBTYPE_SHIFT (0x0000U)
/**
 * Resource assignment subtype mask
 */
#define RESASG_SUBTYPE_MASK (0x003FU)
/**
 * Macro to create unique resource assignment types using type and subtype
 */

#define RESASG_UTYPE(type, subtype) \
	(((type << RESASG_TYPE_SHIFT) & RESASG_TYPE_MASK) | \
	 ((subtype << RESASG_SUBTYPE_SHIFT) & RESASG_SUBTYPE_MASK))

/**
 * IA subtypes definitions
 */
#define RESASG_SUBTYPE_IA_VINT (0x000AU)
#define RESASG_SUBTYPE_GLOBAL_EVENT_GEVT (0x000BU)
#define RESASG_SUBTYPE_GLOBAL_EVENT_MEVT (0x000CU)
#define RESASG_SUBTYPE_GLOBAL_EVENT_SEVT (0x000DU)
#define RESASG_SUBTYPE_GLOBAL_EVENT_LEVT (0x000EU)
#define RESASG_SUBTYPE_IA_PKTDMA_TX_CHAN_ERROR_OES (0x000FU)
#define RESASG_SUBTYPE_IA_PKTDMA_TX_FLOW_COMPLETION_OES (0x0010U)
#define RESASG_SUBTYPE_IA_PKTDMA_RX_CHAN_ERROR_OES (0x0011U)
#define RESASG_SUBTYPE_IA_PKTDMA_RX_FLOW_COMPLETION_OES (0x0012U)
#define RESASG_SUBTYPE_IA_PKTDMA_RX_FLOW_STARVATION_OES (0x0013U)
#define RESASG_SUBTYPE_IA_BCDMA_CHAN_ERROR_OES (0x0014U)
#define RESASG_SUBTYPE_IA_BCDMA_CHAN_DATA_COMPLETION_OES (0x0015U)
#define RESASG_SUBTYPE_IA_BCDMA_CHAN_RING_COMPLETION_OES (0x0016U)
#define RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_ERROR_OES (0x0017U)
#define RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_DATA_COMPLETION_OES (0x0018U)
#define RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_RING_COMPLETION_OES (0x0019U)
#define RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_ERROR_OES (0x001AU)
#define RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_DATA_COMPLETION_OES (0x001BU)
#define RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_RING_COMPLETION_OES (0x001CU)
#define RESASG_SUBTYPES_IA_CNT (0x0013U)

/**
 * IR subtypes definitions
 */
#define RESASG_SUBTYPE_IR_OUTPUT (0x0000U)
#define RESASG_SUBTYPES_IR_CNT (0x0001U)

/**
 * RA subtypes definitions
 */
#define RESASG_SUBTYPE_RA_ERROR_OES (0x0000U)
#define RESASG_SUBTYPE_RA_VIRTID (0x000AU)
#define RESASG_SUBTYPE_BCDMA_RING_BLOCK_COPY_CHAN (0x000DU)
#define RESASG_SUBTYPE_BCDMA_RING_SPLIT_TR_RX_CHAN (0x000EU)
#define RESASG_SUBTYPE_BCDMA_RING_SPLIT_TR_TX_CHAN (0x000FU)
#define RESASG_SUBTYPE_PKTDMA_RING_UNMAPPED_TX_CHAN (0x0010U)
#define RESASG_SUBTYPE_PKTDMA_RING_CPSW_TX_CHAN (0x0011U)
#define RESASG_SUBTYPE_PKTDMA_RING_SAUL_TX_0_CHAN (0x0012U)
#define RESASG_SUBTYPE_PKTDMA_RING_SAUL_TX_1_CHAN (0x0013U)
#define RESASG_SUBTYPE_PKTDMA_RING_UNMAPPED_RX_CHAN (0x0016U)
#define RESASG_SUBTYPE_PKTDMA_RING_CPSW_RX_CHAN (0x0017U)
#define RESASG_SUBTYPE_PKTDMA_RING_SAUL_RX_0_CHAN (0x0018U)
#define RESASG_SUBTYPE_PKTDMA_RING_SAUL_RX_1_CHAN (0x0019U)
#define RESASG_SUBTYPE_PKTDMA_RING_SAUL_RX_2_CHAN (0x001AU)
#define RESASG_SUBTYPE_PKTDMA_RING_SAUL_RX_3_CHAN (0x001BU)
#define RESASG_SUBTYPES_RA_CNT (0x000FU)

/**
 * UDMAP subtypes definitions
 */
#define RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER (0x0002U)
#define RESASG_SUBTYPE_UDMAP_GLOBAL_CONFIG (0x0003U)
#define RESASG_SUBTYPE_BCDMA_BLOCK_COPY_CHAN (0x0020U)
#define RESASG_SUBTYPE_BCDMA_SPLIT_TR_RX_CHAN (0x0021U)
#define RESASG_SUBTYPE_BCDMA_SPLIT_TR_TX_CHAN (0x0022U)
#define RESASG_SUBTYPE_PKTDMA_UNMAPPED_TX_CHAN (0x0023U)
#define RESASG_SUBTYPE_PKTDMA_CPSW_TX_CHAN (0x0024U)
#define RESASG_SUBTYPE_PKTDMA_SAUL_TX_0_CHAN (0x0025U)
#define RESASG_SUBTYPE_PKTDMA_SAUL_TX_1_CHAN (0x0026U)
#define RESASG_SUBTYPE_PKTDMA_UNMAPPED_RX_CHAN (0x0029U)
#define RESASG_SUBTYPE_PKTDMA_FLOW_UNMAPPED_RX_CHAN (0x002AU)
#define RESASG_SUBTYPE_PKTDMA_CPSW_RX_CHAN (0x002BU)
#define RESASG_SUBTYPE_PKTDMA_FLOW_CPSW_RX_CHAN (0x002CU)
#define RESASG_SUBTYPE_PKTDMA_SAUL_RX_0_CHAN (0x002DU)
#define RESASG_SUBTYPE_PKTDMA_FLOW_SAUL_RX_0_CHAN (0x002EU)
#define RESASG_SUBTYPE_PKTDMA_SAUL_RX_1_CHAN (0x002FU)
#define RESASG_SUBTYPE_PKTDMA_FLOW_SAUL_RX_1_CHAN (0x0030U)
#define RESASG_SUBTYPE_PKTDMA_SAUL_RX_2_CHAN (0x0031U)
#define RESASG_SUBTYPE_PKTDMA_FLOW_SAUL_RX_2_CHAN (0x0032U)
#define RESASG_SUBTYPE_PKTDMA_SAUL_RX_3_CHAN (0x0033U)
#define RESASG_SUBTYPE_PKTDMA_FLOW_SAUL_RX_3_CHAN (0x0034U)
#define RESASG_SUBTYPES_UDMAP_CNT (0x0015U)


/**
 * Total number of unique resource types for SoC
 */
#define RESASG_UTYPE_CNT 68U

/**
 * Total number of resource entries allowed for SoC
 */
#define RESASG_ENTRIES_MAX (RESASG_UTYPE_CNT * 5U)

#endif /* RESASG_TYPES_H */
