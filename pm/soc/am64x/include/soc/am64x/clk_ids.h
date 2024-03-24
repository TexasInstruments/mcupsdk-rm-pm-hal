/*
 * Data version: 220519_153621
 *
 * Copyright (C) 2017-2022, Texas Instruments Incorporated
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
#ifndef SOC_AM64X_CLK_IDS_H
#define SOC_AM64X_CLK_IDS_H

#define CLK_AM64X_GLUELOGIC_HFOSC0_CLKOUT 1
#define CLK_AM64X_GLUELOGIC_RCOSC_CLKOUT 2
#define CLK_AM64X_GLUELOGIC_RCOSC_CLK_1P0V_97P65K 3
#define CLK_AM64X_BOARD_0_EXT_REFCLK1_OUT 4
#define CLK_AM64X_BOARD_0_MCU_EXT_REFCLK0_OUT 5
#define CLK_AM64X_BOARD_0_MCU_I2C0_SCL_OUT 6
#define CLK_AM64X_BOARD_0_MCU_I2C1_SCL_OUT 7
#define CLK_AM64X_BOARD_0_MCU_SPI0_CLK_OUT 8
#define CLK_AM64X_BOARD_0_MCU_SPI1_CLK_OUT 9
#define CLK_AM64X_DMTIMER_DMC1MS_MCU_0_TIMER_PWM 10
#define CLK_AM64X_DMTIMER_DMC1MS_MCU_1_TIMER_PWM 11
#define CLK_AM64X_DMTIMER_DMC1MS_MCU_2_TIMER_PWM 12
#define CLK_AM64X_DMTIMER_DMC1MS_MCU_3_TIMER_PWM 13
#define CLK_AM64X_HSDIV0_16FFT_MCU_32KHZ_GEN_0_HSDIVOUT0_CLK 14
#define CLK_AM64X_MSHSI2C_MCU_0_PORSCL 15
#define CLK_AM64X_MSHSI2C_MCU_1_PORSCL 16
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MCU_0_FOUTVCOP_CLK 17
#define CLK_AM64X_SPI_MCU_0_IO_CLKSPIO_CLK 18
#define CLK_AM64X_SPI_MCU_1_IO_CLKSPIO_CLK 19
#define CLK_AM64X_MCU_WWDTCLK_SEL_OUT0 20
#define CLK_AM64X_MCU_SPI0_MSTR_LP_CLKSEL_OUT0 21
#define CLK_AM64X_MCU_SPI1_MSTR_LP_CLKSEL_OUT0 22
#define CLK_AM64X_HSDIV4_16FFT_MCU_0_HSDIVOUT0_CLK 23
#define CLK_AM64X_HSDIV4_16FFT_MCU_0_HSDIVOUT1_CLK 24
#define CLK_AM64X_HSDIV4_16FFT_MCU_0_HSDIVOUT2_CLK 25
#define CLK_AM64X_HSDIV4_16FFT_MCU_0_HSDIVOUT3_CLK 26
#define CLK_AM64X_HSDIV4_16FFT_MCU_0_HSDIVOUT4_CLK 27
#define CLK_AM64X_K3_PLL_CTRL_WRAP_MCU_0_SYSCLKOUT_CLK 28
#define CLK_AM64X_K3_PLL_CTRL_WRAP_MCU_0_CHIP_DIV1_CLK_CLK 29
#define CLK_AM64X_MCU_TIMERCLKN_SEL_OUT0 30
#define CLK_AM64X_MCU_TIMERCLKN_SEL_OUT1 31
#define CLK_AM64X_MCU_TIMERCLKN_SEL_OUT2 32
#define CLK_AM64X_MCU_TIMERCLKN_SEL_OUT3 33
#define CLK_AM64X_MAIN_WWDTCLKN_SEL_OUT0 34
#define CLK_AM64X_MAIN_WWDTCLKN_SEL_OUT1 35
#define CLK_AM64X_MAIN_WWDTCLKN_SEL_OUT2 36
#define CLK_AM64X_MAIN_WWDTCLKN_SEL_OUT3 37
#define CLK_AM64X_MAIN_WWDTCLKN_SEL_OUT4 38
#define CLK_AM64X_MAIN_WWDTCLKN_SEL_OUT5 39
#define CLK_AM64X_MCU_M4FSS_CLKSEL_OUT0 40
#define CLK_AM64X_MCU_OBSCLK_MUX_SEL_OUT0 41
#define CLK_AM64X_BOARD_0_CPTS0_RFT_CLK_OUT 42
#define CLK_AM64X_BOARD_0_CP_GEMAC_CPTS0_RFT_CLK_OUT 43
#define CLK_AM64X_BOARD_0_FSI_RX0_CLK_OUT 44
#define CLK_AM64X_BOARD_0_FSI_RX1_CLK_OUT 45
#define CLK_AM64X_BOARD_0_FSI_RX2_CLK_OUT 46
#define CLK_AM64X_BOARD_0_FSI_RX3_CLK_OUT 47
#define CLK_AM64X_BOARD_0_FSI_RX4_CLK_OUT 48
#define CLK_AM64X_BOARD_0_FSI_RX5_CLK_OUT 49
#define CLK_AM64X_BOARD_0_GPMC0_CLKLB_OUT 50
#define CLK_AM64X_BOARD_0_I2C0_SCL_OUT 51
#define CLK_AM64X_BOARD_0_I2C1_SCL_OUT 52
#define CLK_AM64X_BOARD_0_I2C2_SCL_OUT 53
#define CLK_AM64X_BOARD_0_I2C3_SCL_OUT 54
#define CLK_AM64X_BOARD_0_LED_CLK_OUT 55
#define CLK_AM64X_BOARD_0_MMC1_CLKLB_OUT 56
#define CLK_AM64X_BOARD_0_OSPI0_DQS_OUT 57
#define CLK_AM64X_BOARD_0_OSPI0_LBCLKO_OUT 58
#define CLK_AM64X_BOARD_0_PRG0_RGMII1_RXC_OUT 59
#define CLK_AM64X_BOARD_0_PRG0_RGMII1_TXC_OUT 60
#define CLK_AM64X_BOARD_0_PRG0_RGMII2_RXC_OUT 61
#define CLK_AM64X_BOARD_0_PRG0_RGMII2_TXC_OUT 62
#define CLK_AM64X_BOARD_0_PRG1_RGMII1_RXC_OUT 63
#define CLK_AM64X_BOARD_0_PRG1_RGMII1_TXC_OUT 64
#define CLK_AM64X_BOARD_0_PRG1_RGMII2_RXC_OUT 65
#define CLK_AM64X_BOARD_0_PRG1_RGMII2_TXC_OUT 66
#define CLK_AM64X_BOARD_0_RGMII1_RXC_OUT 67
#define CLK_AM64X_BOARD_0_RGMII1_TXC_OUT 68
#define CLK_AM64X_BOARD_0_RGMII2_RXC_OUT 69
#define CLK_AM64X_BOARD_0_RGMII2_TXC_OUT 70
#define CLK_AM64X_BOARD_0_RMII_REF_CLK_OUT 71
#define CLK_AM64X_BOARD_0_SPI0_CLK_OUT 72
#define CLK_AM64X_BOARD_0_SPI1_CLK_OUT 73
#define CLK_AM64X_BOARD_0_SPI2_CLK_OUT 74
#define CLK_AM64X_BOARD_0_SPI3_CLK_OUT 75
#define CLK_AM64X_BOARD_0_SPI4_CLK_OUT 76
#define CLK_AM64X_BOARD_0_TCK_OUT 77
#define CLK_AM64X_CPSW_3GUSS_MAIN_0_CPTS_GENF0 78
#define CLK_AM64X_CPSW_3GUSS_MAIN_0_CPTS_GENF1 79
#define CLK_AM64X_CPSW_3GUSS_MAIN_0_RGMII1_TXC_O 80
#define CLK_AM64X_CPSW_3GUSS_MAIN_0_RGMII2_TXC_O 81
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_0_TIMER_PWM 82
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_1_TIMER_PWM 83
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_10_TIMER_PWM 84
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_11_TIMER_PWM 85
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_2_TIMER_PWM 86
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_3_TIMER_PWM 87
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_4_TIMER_PWM 88
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_5_TIMER_PWM 89
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_6_TIMER_PWM 90
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_7_TIMER_PWM 91
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_8_TIMER_PWM 92
#define CLK_AM64X_DMTIMER_DMC1MS_MAIN_9_TIMER_PWM 93
#define CLK_AM64X_EMMCSD4SS_MAIN_0_EMMCSDSS_IO_CLK_O 94
#define CLK_AM64X_FSI_TX_MAIN_0_FSI_TX_CK 95
#define CLK_AM64X_FSI_TX_MAIN_1_FSI_TX_CK 96
#define CLK_AM64X_FSS_UL_MAIN_0_OSPI_0_OSPI_OCLK_CLK 97
#define CLK_AM64X_GPMC_MAIN_0_PO_GPMC_DEV_CLK 98
#define CLK_AM64X_ICSS_G_16FF_MAIN_0_PR1_MDIO_MDCLK_O 99
#define CLK_AM64X_ICSS_G_16FF_MAIN_0_PR1_RGMII0_TXC_O 100
#define CLK_AM64X_ICSS_G_16FF_MAIN_0_PR1_RGMII1_TXC_O 101
#define CLK_AM64X_ICSS_G_16FF_MAIN_1_PR1_MDIO_MDCLK_O 102
#define CLK_AM64X_ICSS_G_16FF_MAIN_1_PR1_RGMII0_TXC_O 103
#define CLK_AM64X_ICSS_G_16FF_MAIN_1_PR1_RGMII1_TXC_O 104
#define CLK_AM64X_K3_CPTS_MAIN_0_CPTS_GENF1 105
#define CLK_AM64X_K3_CPTS_MAIN_0_CPTS_GENF2 106
#define CLK_AM64X_K3_CPTS_MAIN_0_CPTS_GENF3 107
#define CLK_AM64X_K3_CPTS_MAIN_0_CPTS_GENF4 108
#define CLK_AM64X_MCU_OBSCLK_DIV_OUT0 109
#define CLK_AM64X_MSHSI2C_MAIN_0_PORSCL 110
#define CLK_AM64X_MSHSI2C_MAIN_1_PORSCL 111
#define CLK_AM64X_MSHSI2C_MAIN_2_PORSCL 112
#define CLK_AM64X_MSHSI2C_MAIN_3_PORSCL 113
#define CLK_AM64X_PCIE_G2X1_64_MAIN_0_PCIE_LANE0_TXCLK 114
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_0_FOUTVCOP_CLK 115
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_0_FOUTPOSTDIV_CLK 116
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_1_FOUTVCOP_CLK 117
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_1_FOUTPOSTDIV_CLK 118
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_12_FOUTVCOP_CLK 119
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_14_FOUTVCOP_CLK 120
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_2_FOUTVCOP_CLK 121
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_2_FOUTPOSTDIV_CLK 122
#define CLK_AM64X_PLLFRACF_SSMOD_16FFT_MAIN_8_FOUTVCOP_CLK 123
#define CLK_AM64X_POSTDIV1_16FFT_MAIN_1_HSDIVOUT5_CLK 124
#define CLK_AM64X_POSTDIV1_16FFT_MAIN_1_HSDIVOUT6_CLK 125
#define CLK_AM64X_POSTDIV4_16FF_MAIN_0_HSDIVOUT5_CLK 126
#define CLK_AM64X_POSTDIV4_16FF_MAIN_0_HSDIVOUT6_CLK 127
#define CLK_AM64X_POSTDIV4_16FF_MAIN_0_HSDIVOUT7_CLK 128
#define CLK_AM64X_POSTDIV4_16FF_MAIN_0_HSDIVOUT8_CLK 129
#define CLK_AM64X_POSTDIV4_16FF_MAIN_0_HSDIVOUT9_CLK 130
#define CLK_AM64X_POSTDIV4_16FF_MAIN_2_HSDIVOUT5_CLK 131
#define CLK_AM64X_POSTDIV4_16FF_MAIN_2_HSDIVOUT6_CLK 132
#define CLK_AM64X_POSTDIV4_16FF_MAIN_2_HSDIVOUT7_CLK 133
#define CLK_AM64X_POSTDIV4_16FF_MAIN_2_HSDIVOUT8_CLK 134
#define CLK_AM64X_POSTDIV4_16FF_MAIN_2_HSDIVOUT9_CLK 135
#define CLK_AM64X_SPI_MAIN_0_IO_CLKSPIO_CLK 136
#define CLK_AM64X_SPI_MAIN_1_IO_CLKSPIO_CLK 137
#define CLK_AM64X_SPI_MAIN_2_IO_CLKSPIO_CLK 138
#define CLK_AM64X_SPI_MAIN_3_IO_CLKSPIO_CLK 139
#define CLK_AM64X_SPI_MAIN_4_IO_CLKSPIO_CLK 140
#define CLK_AM64X_USB3P0SS64_16FFC_MAIN_0_PIPE_TXCLK 141
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP1_LN0_REFCLK 142
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP1_LN0_RXCLK 143
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP1_LN0_RXFCLK 144
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP1_LN0_TXFCLK 145
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP1_LN0_TXMCLK 146
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP2_LN0_REFCLK 147
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP2_LN0_RXCLK 148
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP2_LN0_RXFCLK 149
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP2_LN0_TXFCLK 150
#define CLK_AM64X_WIZ16B2M4CT_MAIN_0_IP2_LN0_TXMCLK 151
#define CLK_AM64X_MAIN_ADC_CLK_SEL_OUT0 152
#define CLK_AM64X_MAIN_EMMCSD1_IO_CLKLB_SEL_OUT0 153
#define CLK_AM64X_MAIN_OSPI_LOOPBACK_CLK_SEL_OUT0 154
#define CLK_AM64X_MAIN_PCIE0_CPTS_CLK_SEL_OUT0 155
#define CLK_AM64X_MAIN_SPI0_MSTR_LP_CLKSEL_OUT0 156
#define CLK_AM64X_MAIN_SPI1_MSTR_LP_CLKSEL_OUT0 157
#define CLK_AM64X_MAIN_SPI2_MSTR_LP_CLKSEL_OUT0 158
#define CLK_AM64X_MAIN_SPI3_MSTR_LP_CLKSEL_OUT0 159
#define CLK_AM64X_MAIN_SPI4_MSTR_LP_CLKSEL_OUT0 160
#define CLK_AM64X_MCU_OBSCLK_OUTMUX_SEL_OUT0 161
#define CLK_AM64X_HSDIV0_16FFT_MAIN_12_HSDIVOUT0_CLK 162
#define CLK_AM64X_HSDIV0_16FFT_MAIN_8_HSDIVOUT0_CLK 163
#define CLK_AM64X_HSDIV1_16FFT_MAIN_14_HSDIVOUT0_CLK 164
#define CLK_AM64X_HSDIV1_16FFT_MAIN_14_HSDIVOUT1_CLK 165
#define CLK_AM64X_HSDIV4_16FFT_MAIN_0_HSDIVOUT0_CLK 166
#define CLK_AM64X_HSDIV4_16FFT_MAIN_0_HSDIVOUT1_CLK 167
#define CLK_AM64X_HSDIV4_16FFT_MAIN_0_HSDIVOUT2_CLK 168
#define CLK_AM64X_HSDIV4_16FFT_MAIN_0_HSDIVOUT3_CLK 169
#define CLK_AM64X_HSDIV4_16FFT_MAIN_0_HSDIVOUT4_CLK 170
#define CLK_AM64X_HSDIV4_16FFT_MAIN_1_HSDIVOUT0_CLK 171
#define CLK_AM64X_HSDIV4_16FFT_MAIN_1_HSDIVOUT1_CLK 172
#define CLK_AM64X_HSDIV4_16FFT_MAIN_1_HSDIVOUT2_CLK 173
#define CLK_AM64X_HSDIV4_16FFT_MAIN_1_HSDIVOUT3_CLK 174
#define CLK_AM64X_HSDIV4_16FFT_MAIN_1_HSDIVOUT4_CLK 175
#define CLK_AM64X_HSDIV4_16FFT_MAIN_2_HSDIVOUT0_CLK 176
#define CLK_AM64X_HSDIV4_16FFT_MAIN_2_HSDIVOUT2_CLK 177
#define CLK_AM64X_HSDIV4_16FFT_MAIN_2_HSDIVOUT3_CLK 178
#define CLK_AM64X_HSDIV4_16FFT_MAIN_2_HSDIVOUT4_CLK 179
#define CLK_AM64X_K3_PLL_CTRL_WRAP_MAIN_0_SYSCLKOUT_CLK 180
#define CLK_AM64X_K3_PLL_CTRL_WRAP_MAIN_0_CHIP_DIV1_CLK_CLK 181
#define CLK_AM64X_CLKOUT_CTRL_OUT0 182
#define CLK_AM64X_MAIN_CPTS_CLK_SEL_OUT0 183
#define CLK_AM64X_MAIN_CP_GEMAC_CPTS_CLK_SEL_OUT0 184
#define CLK_AM64X_MAIN_EMMCSD0_REFCLK_SEL_OUT0 185
#define CLK_AM64X_MAIN_EMMCSD1_REFCLK_SEL_OUT0 186
#define CLK_AM64X_MAIN_GPMC_FCLK_SEL_OUT0 187
#define CLK_AM64X_MAIN_GTCCLK_SEL_OUT0 188
#define CLK_AM64X_MAIN_ICSSGN_CORE_CLK_SEL_OUT0 189
#define CLK_AM64X_MAIN_ICSSGN_CORE_CLK_SEL_OUT1 190
#define CLK_AM64X_MAIN_ICSSGN_IEPCLK_SEL_OUT0 191
#define CLK_AM64X_MAIN_ICSSGN_IEPCLK_SEL_OUT1 192
#define CLK_AM64X_MAIN_MCANN_CLK_SEL_OUT0 193
#define CLK_AM64X_MAIN_MCANN_CLK_SEL_OUT1 194
#define CLK_AM64X_MAIN_OBSCLK0_MUX_SEL_OUT0 195
#define CLK_AM64X_MAIN_OSPI_REF_CLK_SEL_OUT0 196
#define CLK_AM64X_MAIN_SERDES0_CORE_REFCLK_SEL_OUT0 197
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT0 198
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT1 199
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT10 200
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT11 201
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT2 202
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT3 203
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT4 204
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT5 205
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT6 206
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT7 207
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT8 208
#define CLK_AM64X_MAIN_TIMERCLKN_SEL_OUT9 209
#define CLK_AM64X_MAIN_USB0_REFCLK_SEL_OUT0 210
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT0 211
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT1 212
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT2 213
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT3 214
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT4 215
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT5 216
#define CLK_AM64X_USART_PROGRAMMABLE_CLOCK_DIVIDER_OUT6 217
#define CLK_AM64X_OSBCLK0_DIV_OUT0 218
#define CLK_AM64X_MAIN_USART0_FCLK_SEL_OUT0 219
#define CLK_AM64X_MAIN_USART1_FCLK_SEL_OUT0 220
#define CLK_AM64X_MAIN_USART2_FCLK_SEL_OUT0 221
#define CLK_AM64X_MAIN_USART3_FCLK_SEL_OUT0 222
#define CLK_AM64X_MAIN_USART4_FCLK_SEL_OUT0 223
#define CLK_AM64X_MAIN_USART5_FCLK_SEL_OUT0 224
#define CLK_AM64X_MAIN_USART6_FCLK_SEL_OUT0 225
#define CLK_AM64X_K3_PLL_CTRL_WRAP_MAIN_0_CHIP_DIV24_CLK_CLK 226
#define CLK_AM64X_K3_PLL_CTRL_WRAP_MCU_0_CHIP_DIV24_CLK_CLK 227

#endif /* SOC_AM64X_CLK_IDS_H */
