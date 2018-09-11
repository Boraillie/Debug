/**
 * \file
 *
 * \brief 14-bit Analog-to-Digital Converter (ADC14) driver for LIMES.
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

#ifndef ADC14_H_INCLUDED
#define ADC14_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/* The max adc sample freq definition*/
#define ADC14_FREQ_MAX       6000000
/* The min adc sample freq definition*/
#define ADC14_FREQ_MIN       3000000

/* Definitions for ADC trigger */
enum adc14_trigger_t {
	/* Starting a conversion is only possible by software. */
	ADC14_TRIG_SW = ADC14SDC_MR_TRGEN_DIS,
	/* External trigger */
	ADC14_TRIG_EXT = ADC14SDC_MR_TRGSEL_ADC14SDC_TRIG0 | ADC14SDC_MR_TRGEN_EN,
	/* TIO Output of the Timer Counter Channel 0 */
	ADC14_TRIG_TIO_CH_0 = ADC14SDC_MR_TRGSEL_ADC14SDC_TRIG1 | ADC14SDC_MR_TRGEN_EN,
	/* TIO Output of the Timer Counter Channel 1 */
	ADC14_TRIG_TIO_CH_1 = ADC14SDC_MR_TRGSEL_ADC14SDC_TRIG2 | ADC14SDC_MR_TRGEN_EN,
	/* TIO Output of the Timer Counter Channel 2 */
	ADC14_TRIG_TIO_CH_2 = ADC14SDC_MR_TRGSEL_ADC14SDC_TRIG3 | ADC14SDC_MR_TRGEN_EN,
	/* PWM Event Line 0 */
	ADC14_TRIG_PWM_EVENT_LINE_0 = ADC14SDC_MR_TRGSEL_ADC14SDC_TRIG4 | ADC14SDC_MR_TRGEN_EN,
	/* PWM Event Line 1 */
	ADC14_TRIG_PWM_EVENT_LINE_1 = ADC14SDC_MR_TRGSEL_ADC14SDC_TRIG5 | ADC14SDC_MR_TRGEN_EN
};


/* Definitions for OSR */
enum adc14_osr_t {
        ADC14_OSR_32   = ADC14SDC_MR_OSR_OSR32,
        ADC14_OSR_64   = ADC14SDC_MR_OSR_OSR64,
        ADC14_OSR_128  = ADC14SDC_MR_OSR_OSR128,
        ADC14_OSR_256  = ADC14SDC_MR_OSR_OSR256,
        ADC14_OSR_512  = ADC14SDC_MR_OSR_OSR512,
        ADC14_OSR_1024 = ADC14SDC_MR_OSR_OSR1024
};

/* Definitions for ADC channel number */
enum adc14_channel_num_t {
	ADC14_VBAT          = 0,
	ADC14_VUSB          = 1,
	ADC14_VDDIOS        = 2,
	ADC14_VCAP          = 3,
	ADC14_VDDBU         = 4,
	ADC14_AUX_IN        = 5,
	ADC14_VDDANA        = 6,
	ADC14_TIAVDC        = 7,
	ADC14_INTEMP        = 8,
	ADC14_ADVREF        = 9,
	ADC14_VREFP         = 10,
	ADC14_VTEMP         = 11,
	ADC14_GND_ADC_VEEFN = 12,
	ADC14_VBUS          = 13,
	ADC14_VLED          = 14,
	ADC14_GND           = 15,
	ADC14_EXT           = 16,
};

/* Definitions for ADC gain value */
enum adc14_gainvalue_t {
	ADC14_GAINVALUE_0 = 0,
	ADC14_GAINVALUE_1 = 1,
	ADC14_GAINVALUE_2 = 2,
	ADC14_GAINVALUE_3 = 3
};


uint32_t adc14_init(Adc14sdc *p_adc, const uint32_t ul_mck,
		const uint32_t ul_adc_clock);
void adc14_configure_trigger(Adc14sdc *p_adc, const enum adc14_trigger_t trigger,
		const uint8_t uc_freerun);
void adc14_configure_timing(Adc14sdc *p_adc, const uint8_t uc_clear_width);
void adc14_configure_sleep(Adc14sdc *p_adc, const uint8_t uc_sleep);
void adc14_configure_osr(Adc14sdc *p_adc, enum adc14_osr_t osr_value);
void adc14_enable_tag(Adc14sdc *p_adc);
void adc14_disable_tag(Adc14sdc *p_adc);
enum adc14_channel_num_t adc14_get_tag(const Adc14sdc *p_adc);
void adc14_set_comparison_window(Adc14sdc *p_adc, const enum adc14_channel_num_t channel,
                                 const uint16_t us_low_threshold,
		                         const uint16_t us_high_threshold);
void adc14_set_writeprotect(Adc14sdc *p_adc, const uint32_t ul_enable);
uint32_t adc14_get_writeprotect_status(const Adc14sdc *p_adc);
void adc14_check(Adc14sdc *p_adc, const uint32_t ul_mck);
uint32_t adc14_get_overrun_status(const Adc14sdc *p_adc);

void adc14_start(Adc14sdc *p_adc);
void adc14_stop(Adc14sdc *p_adc);
void adc14_enable_channel(Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch);
void adc14_disable_channel(Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch);
void adc14_enable_all_channel(Adc14sdc *p_adc);
void adc14_disable_all_channel(Adc14sdc *p_adc);
uint32_t adc14_get_channel_status(const Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch);
uint32_t adc14_get_channel_value(const Adc14sdc *p_adc,const enum adc14_channel_num_t adc_ch);
uint32_t adc14_get_latest_value(const Adc14sdc *p_adc);
uint32_t adc14_get_actual_adc_clock(const Adc14sdc *p_adc, const uint32_t ul_mck);
void adc14_enable_eoc_interrupt(Adc14sdc *p_adc, const uint32_t ul_source);
void adc14_enable_compe_interrupt(Adc14sdc *p_adc, const uint32_t ul_source);
void adc14_disable_eoc_interrupt(Adc14sdc *p_adc, const uint32_t ul_source);
void adc14_disable_compe_interrupt(Adc14sdc *p_adc, const uint32_t ul_source);
uint32_t adc14_get_eoc_status(const Adc14sdc *p_adc);
uint32_t adc14_get_compe_status(const Adc14sdc *p_adc);
uint32_t adc14_get_eoc_interrupt_mask(const Adc14sdc *p_adc);
uint32_t adc14_get_compe_interrupt_mask(const Adc14sdc *p_adc);
void adc14_set_channel_gain_offset(Adc14sdc *p_adc, const enum adc14_channel_num_t channel,
                                   const uint16_t us_gain,
                                   const uint16_t us_offset,
                                   const uint16_t us_shift);


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \page limes_adc14_quickstart Quickstart guide for LIMES ADC14 driver
 *
 * This is the quickstart guide for the \ref limes_adc14_group "LIMES ADC14 driver",
 * with step-by-step instructions on how to configure and use the driver in a
 * selection of use cases.
 *
 * The use cases contain several code fragments. The code fragments in the
 * steps for setup can be copied into a custom initialization function, while
 * the steps for usage can be copied into, e.g., the main application function.
 *
 * TBD
 */
#endif /* ADC14_H_INCLUDED */
