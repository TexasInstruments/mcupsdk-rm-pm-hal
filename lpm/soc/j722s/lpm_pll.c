/*
 * DM Stub Firmware
 *
 * j722s lpm_pll.c
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

#include <lpm_pll.h>

/* MCU PLL to be saved and restored */
struct pll_raw_data lpm_mcu_pll =
{ .base = LPM_MCU_PLL_MMR_BASE, };

/* Main PLL to be saved and restored */
struct pll_raw_data lpm_main_pll0 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(0U), };

struct pll_raw_data lpm_main_pll1 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(1U), };

struct pll_raw_data lpm_main_pll2 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(2U), };

struct pll_raw_data lpm_main_pll5 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(5U), };

struct pll_raw_data lpm_main_pll6 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(6U), };

struct pll_raw_data lpm_main_pll7 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(7U), };

struct pll_raw_data lpm_main_pll8 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(8U), };

struct pll_raw_data lpm_main_pll12 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(12U), };

struct pll_raw_data lpm_main_pll16 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(16U), };

struct pll_raw_data lpm_main_pll17 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(17U), };

struct pll_raw_data lpm_main_pll18 =
{ .base = LPM_MAIN_PLL_MMR_BASE + LPM_PLLOFFSET(18U), };
