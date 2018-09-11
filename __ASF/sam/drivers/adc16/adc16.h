/**
 * \file
 *
 * \brief 16-bit Analog-to-Digital Converter (ADC16) driver for LIMES.
 *
 * Copyright (c) 2011-2013 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef ADC16_H_INCLUDED
#define ADC16_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/* The normal adc startup time*/
#define ADC16_STARTUP_NORM        40
/* The fast adc startup time*/
#define ADC16_STARTUP_FAST        12

/* Definitions for ADC trigger */
//enum adc16_trigger_t {
//	/* Starting a conversion is only possible by software. */
//	ADC16_TRIG_SW = ADC16SDC_MR_TRGEN_DIS,
//	/* External trigger */
//	ADC16_TRIG_EXT = ADC16SDC_MR_TRGSEL_ADC16SDC_TRIG0 | ADC16SDC_MR_TRGEN_EN,
//	/* TIO Output of the Timer Counter Channel 0 */
//	ADC16_TRIG_TIO_CH_0 = ADC16SDC_MR_TRGSEL_ADC16SDC_TRIG1 | ADC16SDC_MR_TRGEN_EN,
//	/* TIO Output of the Timer Counter Channel 1 */
//	ADC16_TRIG_TIO_CH_1 = ADC16SDC_MR_TRGSEL_ADC16SDC_TRIG2 | ADC16SDC_MR_TRGEN_EN,
//	/* TIO Output of the Timer Counter Channel 2 */
//	ADC16_TRIG_TIO_CH_2 = ADC16SDC_MR_TRGSEL_ADC16SDC_TRIG3 | ADC16SDC_MR_TRGEN_EN,
//	/* PWM Event Line 0 */
//	ADC16_TRIG_PWM_EVENT_LINE_0 = ADC16SDC_MR_TRGSEL_ADC16SDC_TRIG4 | ADC16SDC_MR_TRGEN_EN,
//	/* PWM Event Line 1 */
//	ADC16_TRIG_PWM_EVENT_LINE_1 = ADC16SDC_MR_TRGSEL_ADC16SDC_TRIG5 | ADC16SDC_MR_TRGEN_EN
//};


/* Definitions for ADC TIA activation */
enum adc16_tia_input_t {
    ADC16_TIAR_INPUT_PHOTODIODE = 0,
    ADC16_TIAR_INPUT_BS = 2,
    ADC16_TIAR_INPUT_BS_RZ = 3,
};

struct adc16_tia_cfg {
    uint32_t enabled;
    uint32_t bypass;
    uint32_t hi_pass_filter;
    uint32_t low_pass_filter;
    uint32_t hi_z;
    uint32_t input;
    uint32_t idac_sel;
    uint32_t vin3;
    uint32_t vin4;
    uint32_t startuptime;
};

/* Definitions for ADC PGA activation */
enum adc16_pga_input_t {
    ADC16_PGA_INPUT_TIA = 0,
    ADC16_PGA_INPUT_PINS = 1,
};

struct adc16_pga_cfg {
    uint32_t enabled;
    uint32_t bypass;
    uint32_t hi_pass_filter;
    uint32_t low_pass_filter;
    uint32_t hi_z;
    uint32_t input;
    uint32_t gain;
    uint32_t startuptime;
};

/* Definitions for OSR */
enum adc16_osr_t {
        ADC16_OSR_32   = ADC16SDC_DSPR0_OSR_32,
        ADC16_OSR_64   = ADC16SDC_DSPR0_OSR_64,
        ADC16_OSR_128  = ADC16SDC_DSPR0_OSR_128,
        ADC16_OSR_256  = ADC16SDC_DSPR0_OSR_256,
        ADC16_OSR_512  = ADC16SDC_DSPR0_OSR_512,
        ADC16_OSR_1024 = ADC16SDC_DSPR0_OSR_1024
};

/* Definitions for OSR */
enum adc16_dsp_data_size_t {
        ADC16_DSP_SIZE_16 = 0,
        ADC16_DSP_SIZE_32 = 1,
};

struct adc16_dsp_cfg {
    uint32_t fir_bypass;
    uint32_t iir_bypass;
    uint32_t sincc_bypass;
    uint32_t data_size;
    uint32_t osr;
    uint32_t scale;
    uint32_t shift;
    uint32_t gain;
    uint32_t offset;
};

struct adc16_cfg_desc {
    uint32_t mck;
	uint32_t adc_clock;
    uint32_t startuptime;
    uint32_t insel;
    uint32_t invt;
    uint32_t dyninv;
    struct adc16_tia_cfg *tia;
    struct adc16_pga_cfg *pga;
    struct adc16_dsp_cfg *dsp;
};




uint32_t adc16_init(Adc16sdc *p_adc, struct adc16_cfg_desc * adc_desc);
void adc16_enable_tia(Adc16sdc *p_adc);
void adc16_disable_tia(Adc16sdc *p_adc);
void adc16_enable_pga(Adc16sdc *p_adc);
void adc16_disable_pga(Adc16sdc *p_adc);
void adc16_start(Adc16sdc *p_adc);
void adc16_stop(Adc16sdc *p_adc);
void adc16_configure_timing(Adc16sdc *p_adc, const uint8_t uc_clear_width);
enum adc16_channel_num_t adc16_get_tag(const Adc16sdc *p_adc);
void adc16_enable_writeprotect(Adc16sdc *p_adc);
void adc16_disable_writeprotect(Adc16sdc *p_adc);
uint32_t adc16_get_writeprotect_status(const Adc16sdc *p_adc);
uint32_t adc16_get_overrun_status(const Adc16sdc *p_adc);
uint32_t adc16_get_status(const Adc16sdc *p_adc);
uint32_t adc16_get_value(const Adc16sdc *p_adc);
uint32_t adc16_get_latest_value(const Adc16sdc *p_adc);
uint32_t adc16_get_actual_adc_clock(const Adc16sdc *p_adc, const uint32_t ul_mck);
void adc16_enable_interrupt(Adc16sdc *p_adc, uint32_t ul_source);
void adc16_disable_interrupt(Adc16sdc *p_adc, uint32_t ul_source);
uint32_t adc16_get_status(const Adc16sdc *p_adc);
uint32_t adc16_get_interrupt_mask(const Adc16sdc *p_adc);
Pdc *adc16_get_pdc_base(const Adc16sdc *p_adc);

void adc16_set_dsp_gain_offset(Adc16sdc *p_adc,
                               const uint16_t us_gain,
                               const uint16_t us_offset);
void adc16_set_bias_current(Adc16sdc *p_adc, const uint8_t uc_ibctl);
void adc16_enable_ts(Adc16sdc *p_adc);
void adc16_disable_ts(Adc16sdc *p_adc);
void adc16_set_synchro(Adc16sdc *p_adc, uint32_t idacc_id, uint32_t counter);



/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \page limes_adc16_quickstart Quickstart guide for LIMES ADC16 driver
 *
 * This is the quickstart guide for the \ref limes_adc16_group "LIMES ADC16 driver",
 * with step-by-step instructions on how to configure and use the driver in a
 * selection of use cases.
 *
 * The use cases contain several code fragments. The code fragments in the
 * steps for setup can be copied into a custom initialization function, while
 * the steps for usage can be copied into, e.g., the main application function.
 *
 * TBD
 *
 */
#endif /* ADC16_H_INCLUDED */
