/*
 * DM Stub Firmware
 *
 * Secure Proxy driver for Message Transfer
 *
 * Copyright (C) 2021-2024, Texas Instruments Incorporated
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

/**
 * \brief Send a Secure Proxy message
 * \param msg Message buffer pointer pointing to the message to be sent
 * \param len Length of the message in bytes
 */
s32 sproxy_send_msg_rom(void *msg, u32 len);

/**
 * \brief Receive a Secure Proxy message
 * \param msg buffer pointer pointing to the buffer to store the message
 * \param len Length of the message in bytes
 */
s32 sproxy_receive_msg_rom(void *msg, u32 len);

/**
 * \brief Send a Secure Proxy message on dmsc2dm thread
 * \param msg Message buffer pointer pointing to the message to be sent
 * \param len Length of the message in bytes
 */
s32 sproxy_send_msg_tifs_fw(void *msg, u32 len);

/**
 * \brief Receive a Secure Proxy message on dmsc2dm thread
 * \param msg buffer pointer pointing to the buffer to store the message
 * \param len Length of the message in bytes
 */
s32 sproxy_receive_msg_tifs_fw(void *msg, u32 len);

/**
 * \brief Send a Secure Proxy message on dm2dmsc thread
 * \param msg Message buffer pointer pointing to the message to be sent
 * \param len Length of the message in bytes
 */
s32 sproxy_send_msg_dm2dmsc_fw(void *msg, u32 len);

/**
 * \brief Receive a Secure Proxy message on dm2dmsc thread
 * \param msg buffer pointer pointing to the buffer to store the message
 * \param len Length of the message in bytes
 */
s32 sproxy_receive_msg_dm2dmsc_fw(void *msg, u32 len);
