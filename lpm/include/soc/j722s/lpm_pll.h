/*
 * DM Stub Firmware
 *
 * j722s lpm_pll.h
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

#ifndef LPM_PLL_H_
#define LPM_PLL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <types/short_types.h>
#include <lpm_baseaddress.h>
#include <pll_16fft_raw.h>

#define LPM_PLLOFFSET(idx) (0x1000U * (idx))

extern struct pll_raw_data lpm_mcu_pll;
extern struct pll_raw_data lpm_main_pll0;
extern struct pll_raw_data lpm_main_pll1;
extern struct pll_raw_data lpm_main_pll2;
extern struct pll_raw_data lpm_main_pll5;
extern struct pll_raw_data lpm_main_pll6;
extern struct pll_raw_data lpm_main_pll7;
extern struct pll_raw_data lpm_main_pll8;
extern struct pll_raw_data lpm_main_pll12;
extern struct pll_raw_data lpm_main_pll16;
extern struct pll_raw_data lpm_main_pll17;
extern struct pll_raw_data lpm_main_pll18;

#ifdef __cplusplus
}
#endif
#endif /* LPM_PLL_H_ */
