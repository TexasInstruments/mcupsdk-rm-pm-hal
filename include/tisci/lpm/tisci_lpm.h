/*
 * DM Firmware TISCI LPM Messaging
 *
 * TISCI LPM layer for managing Low Power Mode TISCI message handlers
 *
 * Copyright (C) 2021-2025, Texas Instruments Incorporated
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

#ifndef TISCI_LPM_H
#define TISCI_LPM_H

#include <config.h>
#include <types/short_types.h>
#include <tisci/tisci_protocol.h>

/**
 * Sleep mode in which complete SOC except the wakeup domain is turned off.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_DEEP_SLEEP           0x0U

/**
 * Sleep mode in which complete SOC except the wakeup and MCU domain is turned off.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_MCU_ONLY             0x1U

/**
 * Sleep mode in which complete SOC except the DDR memory and CAN IOs is turned off.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_IO_ONLY_PLUS_DDR     0x2U

/**
 * Sleep mode in which complete SOC except the CAN IOs is turned off.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_PARTIAL_IO           0x3U

/**
 * Sleep mode in which software is in low power mode but the hardware remains on.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_STANDBY              0x4U

/**
 * Sleep mode in which the complete SOC except the DDR is turned off.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_SOC_OFF              0x5U

/**
 * Sleep mode in which complete SOC except the RTC and DDR is off
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_RTC_PLUS_DDR         0x6U

/**
 * Value passed to request device manager for low power mode selection.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_DM_MANAGED           0xFDU

/**
 * Value returned if device manager has not yet selected the low power mode.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_NOT_SELECTED         0xFEU

/**
 * Value returned if low power mode entered is invalid.
 */
#define TISCI_MSG_VALUE_SLEEP_MODE_INVALID              0xFFU

#define MSG_FLAG_CERT_AUTH_PASS                        0x555555U
#define MSG_FLAG_CERT_AUTH_FAIL                        0xffffffU

#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_00            0x0x00000001
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_01            0x0x00000002
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_02            0x0x00000004
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_03            0x0x00000008
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_04            0x0x00000010
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_05            0x0x00000020
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_06            0x0x00000040
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_07            0x0x00000080
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_08            0x0x00000100
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_09            0x0x00000200
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_10            0x0x00000400
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_11            0x0x00000800
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_12            0x0x00001000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_13            0x0x00002000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_14            0x0x00004000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_15            0x0x00008000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_16            0x0x00010000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_17            0x0x00020000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_18            0x0x00040000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_19            0x0x00080000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_20            0x0x00100000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_21            0x0x00200000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_22            0x0x00400000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_23            0x0x00800000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_24            0x0x01000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_25            0x0x02000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_26            0x0x04000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_27            0x0x08000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_28            0x0x10000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_29            0x0x20000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_30            0x0x40000000
#define TISCI_MSG_VALUE_SLEEP_DEBUG_FLAG_31            0x0x80000000

#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_WKUP_I2C0                       0x00U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_WKUP_UART0                      0x10U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_MCU_GPIO0                       0x20U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_WKUP_ICEMELTER0                 0x30U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_WKUP_TIMER0                     0x40U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_WKUP_TIMER1                     0x41U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_WKUP_RTC0                       0x50U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_RESET                           0x60U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_USB0                            0x70U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_USB1                            0x71U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_MAIN_IO                         0x80U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_MCU_IO                          0x81U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_CAN_IO                          0x82U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_MCU_IPC                         0x90U
#define TISCI_MSG_VALUE_LPM_WAKE_SOURCE_INVALID                         0xFFU

/** Used by TISCI_MSG_LPM_WAKE_REASON to return wake pin number as invalid */
#define TISCI_MSG_VALUE_LPM_WAKE_PIN_INVALID                            0xFFU

/** Used by TISCI_MSG_GET_NEXT_HOST_STATE to return remote core's state as on */
#define TISCI_MSG_VALUE_HOST_STATE_ON                                   1U
/** Used by TISCI_MSG_GET_NEXT_HOST_STATE to return remote core's state as off */
#define TISCI_MSG_VALUE_HOST_STATE_OFF                                  0U
/** Used by TISCI_MSG_GET_NEXT_HOST_STATE to return remote core's state as invalid */
#define TISCI_MSG_VALUE_HOST_STATE_INVALID                              0xFFU

/** Used by TISCI_MSG_SET_IO_ISOLATION to enable IO isolation */
#define TISCI_MSG_VALUE_IO_ENABLE 1U
/** Used by TISCI_MSG_SET_IO_ISOLATION to disable IO isolation */
#define TISCI_MSG_VALUE_IO_DISABLE 0U

/** Used by set and get constraints APIs to set/get constraint for device/latency */
#define TISCI_MSG_VALUE_STATE_SET       1U
/** Used by set and get constraints APIs to clear/get constraint for device/latency */
#define TISCI_MSG_VALUE_STATE_CLEAR     0U

/**
 * \brief Request for TISCI_MSG_PREPARE_SLEEP.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param mode Low power mode to enter.
 * \param ctx_lo Low 32-bits of physical pointer to address to use for context save.
 * \param ctx_hi High 32-bits of physical pointer to address to use for context save.
 * \param debug_flags Flags that can be set to halt the sequence during suspend or
 *                                    resume to allow JTAG connection and debug.
 *
 * This message is used as the first step of entering a low power mode. It
 * allows configurable information, including which state to enter to be
 * easily shared from the application, as this is a non-secure message and
 * therefore can be sent by anyone.
 *
 * Notes:
 *  * Mode is defined as one of TISCI_MSG_VALUE_SLEEP_MODE_x macros.
 *  * Mode parameter should be equal to partial IO low power mode for partial IO
 *    mode entry. In this mode, ctx_lo and ctx_hi are unused. There is no requirement
 *    of "carve out" in DDR.
 *  * Mode parameter should be equal to intermediate value "DM managed" if
 *    mode selection logic has to be applied. In this case, ctx_lo and ctx_hi are
 *    reserved for internal use (DM application should allocate "carve out" for LPM)
 *  * For mode value not equal to "DM managed" or partial IO, ctx_lo and ctx_hi should
 *    be a reserved memory region as decided on by the HLOS. This region should be a
 *    carve out in DDR and valid for use with DMA. Otherwise there are no constraints
 *    on this memory. An encrypted blob will be placed here and only a valid blob can be
 *    decrypted and authenticated, which eliminates risk of tampering.
 */
struct tisci_msg_prepare_sleep_req {
	struct tisci_header	hdr;
	u8			mode;
	u32			ctx_lo;
	u32			ctx_hi;
	u32			debug_flags;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_PREPARE_SLEEP.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 */
struct tisci_msg_prepare_sleep_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_ENTER_SLEEP.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param mode Low power mode to enter.
 * \param proc_id Processor id to be used for restoring boot vector and debug
 *                status upon resume.
 * \param core_resume_lo Low 32-bits of physical pointer to address for core to
 *                       begin execution upon resume.
 * \param core_resume_hi High 32-bits of physical pointer to address for core to
 *                       begin execution upon resume.
 *
 * This message is to be sent after TISCI_MSG_PREPARE_SLEEP and actually triggers
 * entry into the previously selected low power mode.
 *
 */
struct tisci_msg_enter_sleep_req {
	struct tisci_header	hdr;
	u8			mode;
	u8			proc_id;
	u32			core_resume_lo;
	u32			core_resume_hi;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_ENTER_SLEEP.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param status Value that gives information about what happened during LPM cycle.
 */
struct tisci_msg_enter_sleep_resp {
	struct tisci_header	hdr;
	u32			status;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_FIRMWARE_LOAD.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param image_addr SPS memory address to load FS stub from.
 * \param image_size Size of the FS stub image.
 */
struct tisci_msg_firmware_load_req {
	struct tisci_header	hdr;
	u32			image_addr;
	u32			image_size;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_FIRMWARE_LOAD.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 */
struct tisci_msg_firmware_load_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_SYNC_RESUME.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * Generic synchronization message between cores to be used as a checkpoint
 * when TIFS and DM are working in coordination.
 */
struct tisci_msg_sync_resume_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_SYNC_RESUME.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * Generic synchronization message between cores to be used as a checkpoint
 * when TIFS and DM are working in coordination.
 */
struct tisci_msg_sync_resume_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_CONTINUE_RESUME.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is sent from TIFS Stub to DM stub to indicate that all
 * prerequisite steps to allow DDR restore to proceed have been completed.
 *
 */
struct tisci_msg_continue_resume_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_CONTINUE_RESUME.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * \param ctx_lo Low 32-bits of physical pointer to address that was used for context save.
 * \param ctx_hi High 32-bits of physical pointer to address that was used for context save.
 *
 * This response is sent from the DM stub to the TIFS stub to trigger TIFS
 * Stub restore of TIFS context from the address provided in the ctx_lo and
 * ctx_hi parameters. This response assumes DDR has been fully restored by DM
 * Stub before it is sent.
 *
 */
struct tisci_msg_continue_resume_resp {
	struct tisci_header	hdr;
	u32			ctx_lo;
	u32			ctx_hi;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_CORE_RESUME.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is sent from the DM firmware to the TIFS firmware during
 * resume to indicate that it is ready for all other cores to be restored.
 * TIFS receives this message and restores A53 and HSM core.
 */
struct tisci_msg_core_resume_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_CORE_RESUME.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 */
struct tisci_msg_core_resume_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_DM_ABORT_SLEEP.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is sent from the DM firmware to the TIFS firmware during lpm
 * suspend sequence to indicate that DM was not able to successfully suspend
 * the SOC and DM is aborting the sleep cycle. On receiving this message TIFS
 * will wake from WFI and the same message will be forwarded to the power
 * master to wake it from WFI.
 */
struct tisci_msg_dm_abort_sleep_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_DM_ABORT_SLEEP.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 */
struct tisci_msg_dm_abort_sleep_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_WAKE_REASON.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is used to query the wake up source from low power mode.
 *
 */
struct tisci_msg_lpm_wake_reason_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_WAKE_REASON.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param wake_source The wake up source that woke soc from LPM.
 * \param wake_timestamp Timestamp at which soc woke.
 * \param wake_pin The pin that has triggered wake up.
 * \param mode The last entered low power mode.
 * \param rsvd_0 Reserved for future use.
 * \param rsvd_1 Reserved for future use.
 *
 */
struct tisci_msg_lpm_wake_reason_resp {
	struct tisci_header	hdr;
	u32			wake_source;
	u64			wake_timestamp;
	u8			wake_pin;
	u8			mode;
	u32			rsvd_0;
	u32			rsvd_1;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_SET_IO_ISOLATION.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param state The desired state of the IO isolation.
 *
 * This message is used to enable/disable IO isolation for low power modes.
 *
 */
struct tisci_msg_set_io_isolation_req {
	struct tisci_header	hdr;
	u8			state;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_SET_IO_ISOLATION.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 */
struct tisci_msg_set_io_isolation_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_MIN_CONTEXT_RESTORE.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param ctx_lo Low 32-bits of physical pointer to address to use for context restore.
 * \param ctx_hi High 32-bits of physical pointer to address to use for context restore.
 *
 * This message is sent from bootloader to TIFS to indicate that DDR is active and
 * TIFS can restore the minimal context from the address provided in the ctx_lo and
 * ctx_hi parameters. This response assumes DDR has been fully restored by bootloader before
 * it is sent.
 *
 */
struct tisci_msg_min_context_restore_req {
	struct tisci_header	hdr;
	u32			ctx_lo;
	u32			ctx_hi;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_MIN_CONTEXT_RESTORE.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This response is sent from the TIFS to the R5 SPL to indicate that now standard
 * firmware can be executed. This response is sent after DDR firewalls have been fully
 * restored by TIFS.
 *
 */
struct tisci_msg_min_context_restore_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_SET_DEVICE_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param id Device ID of device on which constraint has to be set/cleared.
 * \param state The desired state of constraint: set or clear.
 * \param rsvd_0 Reserved for future use.
 * \param rsvd_1 Reserved for future use.
 *
 * This message is used by host to set constraint on a device. This can be
 * sent anytime after boot before prepare sleep message and after current low
 * power mode is exited. Any device can set a constraint on the low power mode
 * that the SoC can enter. It allows configurable information to be easily shared
 * from the application, as this is a non-secure message and therefore can be sent
 * by anyone. By setting a constraint, the device ensures that it will not be
 * powered off or reset in the selected mode.
 *
 * Notes:
 * * Access Restriction: Exclusivity flag of Device will be honored for setting
 *   constraint. If some other host has exclusive rights on this device, NAK will
 *   be returned.
 * * Clearing of constraints can be done irrespective of exclusivity.
 */
struct tisci_msg_lpm_set_device_constraint_req {
	struct tisci_header	hdr;
	u32			id;
	u8			state;
	u32			rsvd_0;
	u32			rsvd_1;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_SET_DEVICE_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 */
struct tisci_msg_lpm_set_device_constraint_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_GET_DEVICE_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param id Device ID of device for which constraint value is requested.
 *
 * This message is used by host to get constraints that it has put on a
 * device.
 *
 */
struct tisci_msg_lpm_get_device_constraint_req {
	struct tisci_header	hdr;
	u32			id;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_GET_DEVICE_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param state The returned state of constraint: set or clear.
 */
struct tisci_msg_lpm_get_device_constraint_resp {
	struct tisci_header	hdr;
	u8			state;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_SET_LATENCY_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param resume_latency The maximum acceptable latency to wake up from low power mode
 *                       in milliseconds. The deeper the state, the higher the latency.
 * \param state The desired state of constraint: set or clear.
 * \param rsvd Reserved for future use.
 *
 * This message is used by host to set latency for waking up from low power mode. This can
 * be sent anytime after boot before prepare sleep message and after current low power
 * mode is exited. Any host can set a constraint on the low power mode that the SoC can
 * enter. It allows configurable information to be easily shared from the application, as
 * this is a non-secure message and therefore can be sent by anyone. By setting a wakeup
 * latency constraint, the host ensures that the resume time from selected low power mode
 * will be less than the constraint value.
 */
struct tisci_msg_lpm_set_latency_constraint_req {
	struct tisci_header	hdr;
	u16			resume_latency;
	u8			state;
	u32			rsvd;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_SET_LATENCY_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 */
struct tisci_msg_lpm_set_latency_constraint_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_GET_LATENCY_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is used by the host to get the resume latency it set for waking up from low
 * power mode.
 *
 */
struct tisci_msg_lpm_get_latency_constraint_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_GET_LATENCY_CONSTRAINT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param resume_latency The maximum acceptable latency for waking up from low power mode
 *                       in milliseconds. The deeper the state, the higher the latency.
 * \param state The returned state of constraint: set or clear.
 */
struct tisci_msg_lpm_get_latency_constraint_resp {
	struct tisci_header	hdr;
	u16			resume_latency;
	u8			state;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_GET_NEXT_SYS_MODE.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is used to enquire DM for selected system wide low power mode.
 *
 */
struct tisci_msg_lpm_get_next_sys_mode_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_GET_NEXT_SYS_MODE.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param mode The selected system wide low power mode.
 *
 * Note: If the mode selection is not yet locked, this API returns "not selected" mode.
 */
struct tisci_msg_lpm_get_next_sys_mode_resp {
	struct tisci_header	hdr;
	u8			mode;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_GET_LPM_NEXT_HOST_STATE.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is used by host to enquire DM for its expected state
 * in current low power mode selection - ON or OFF.
 *
 */
struct tisci_msg_lpm_get_next_host_state_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_GET_NEXT_HOST_STATE.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 * \param state The expected state of host in selected low power mode.
 *
 * Note: If the mode selection is not yet locked, this API returns invalid state.
 */
struct tisci_msg_lpm_get_next_host_state_resp {
	struct tisci_header	hdr;
	u8			state;
} __attribute__((__packed__));

/**
 * \brief Request for TISCI_MSG_LPM_ABORT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 *
 * This message is used by linux to notify the firmware to abort the current low
 * power mode entry by clearing the current mode selection.
 *
 * Note: This message should be sent after prepare sleep message in case of failure
 * to suspend the system.
 */
struct tisci_msg_lpm_abort_req {
	struct tisci_header hdr;
} __attribute__((__packed__));

/**
 * \brief Response for TISCI_MSG_LPM_ABORT.
 *
 * \param hdr TISCI header to provide ACK/NAK flags to the host.
 */
struct tisci_msg_lpm_abort_resp {
	struct tisci_header hdr;
} __attribute__((__packed__));

#endif
