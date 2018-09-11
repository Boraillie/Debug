/**
 * \file
 *
 * \brief 14-bit Analog-to-Digital Converter (ADC14) driver for Limes.
 *
 * Copyright (c) 2011 - 2013 Atmel Corporation. All rights reserved.
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

#include "adc14.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \defgroup limes_drivers_adc14_group Analog-to-digital Converter (ADC)
 *
 * See \ref limes_adc14_quickstart.
 *
 * Driver for the 14-bit Analog-to-digital Converter. This driver provides access to the main 
 * features of the ADC14 controller.
 *
 * @{
 */

/**
 * \brief Initialize the given ADC with the specified ADC clock and startup time.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_mck Main clock of the device (value in Hz).
 * \param ul_adc_clock Analog-to-Digital conversion clock (value in Hz).
 * for details.
 *
 * \return 0 on success.
 */
uint32_t adc14_init(Adc14sdc *p_adc, const uint32_t ul_mck,
		const uint32_t ul_adc_clock)
{
	uint32_t ul_prescal;

	/*  Reset the controller. */
	p_adc->ADC14SDC_CR = ADC14SDC_CR_SWRST;

	/* Reset Mode Register. */
	p_adc->ADC14SDC_MR = 0;

	ul_prescal = ul_mck / (2 * ul_adc_clock) - 1;
	p_adc->ADC14SDC_MR |= ADC14SDC_MR_PRESCAL(ul_prescal);
	return 0;
}

/**
 * \brief Configure conversion trigger and free run mode.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param trigger Conversion trigger.
 * \param uc_freerun ADC14SDC_MR_FREERUN_ON enables freerun mode, 
 * ADC14SDC_MR_FREERUN_OFF disables freerun mode.
 *
 */
void adc14_configure_trigger(Adc14sdc *p_adc, const enum adc14_trigger_t trigger,
		uint8_t uc_freerun)
{
	p_adc->ADC14SDC_MR |= trigger | ((uc_freerun << 7) & ADC14SDC_MR_FREERUN);
}

/**
 * \brief Configure ADC timing.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param uc_clear_width time.
 */
void adc14_configure_timing(Adc14sdc *p_adc, const uint8_t uc_clear_width)
{
	p_adc->ADC14SDC_MR |= ADC14SDC_MR_CWIDTH(uc_clear_width);
}

/**
 * \brief Configures ADC sleep mode.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param uc_sleep ADC14SDC_MR_SLEEP_NORMAL keeps the ADC Core and reference voltage 
 * circuitry ON between conversions.
 * ADC14SDC_MR_SLEEP_SLEEP keeps the ADC Core and reference voltage circuitry OFF 
 * between conversions.
 */
void adc14_configure_sleep(Adc14sdc *p_adc, const uint8_t uc_sleep)
{
	p_adc->ADC14SDC_MR |= ((uc_sleep << 5) & ADC14SDC_MR_SLEEP);
}

/**
 * \brief configure Over-Sampling Ratio.
 *
 * \note If one of the hardware event is selected as ADC trigger, 
 * this function can NOT start analog to digital conversion.
 *
 * \param p_adc Pointer to an ADC instance.
 */

void adc14_configure_osr(Adc14sdc *p_adc, enum adc14_osr_t osr_value)
{
	p_adc->ADC14SDC_MR |= osr_value;
}

/**
 * \brief Start analog-to-digital conversion.
 *
 * \note If one of the hardware event is selected as ADC trigger, 
 * this function can NOT start analog to digital conversion.
 *
 * \param p_adc Pointer to an ADC instance.
 */

void adc14_start(Adc14sdc *p_adc)
{
	p_adc->ADC14SDC_CR = ADC14SDC_CR_START;
}

/**
 * \brief Stop analog-to-digital conversion.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc14_stop(Adc14sdc *p_adc)
{
	p_adc->ADC14SDC_CR = ADC14SDC_CR_SWRST;
}

/**
 * \brief Enable the specified ADC channel.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param adc_ch ADC channel number.
 */
void adc14_enable_channel(Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch)
{
	p_adc->ADC14SDC_CHER = 1 << adc_ch;
}

/**
 * \brief Enable all ADC channels.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc14_enable_all_channel(Adc14sdc *p_adc)
{
	p_adc->ADC14SDC_CHER = 0xFFFF;
}

/**
 * \brief Disable the specified ADC channel.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param adc_ch ADC channel number.
 */
void adc14_disable_channel(Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch)
{
	p_adc->ADC14SDC_CHDR = 1 << adc_ch;
}

/**
 * \brief Disable all ADC channel.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc14_disable_all_channel(Adc14sdc *p_adc)
{
	p_adc->ADC14SDC_CHDR = 0xFFFF;
}

/**
 * \brief Read the ADC channel status.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param adc_ch ADC channel number.
 *
 * \retval 1 if channel is enabled.
 * \retval 0 if channel is disabled.
 */
uint32_t adc14_get_channel_status(const Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch)
{
	return p_adc->ADC14SDC_CHSR & (1 << adc_ch);
}

/**
 * \brief Read the ADC result data of the specified channel.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param adc_ch ADC channel number.
 *
 * \return ADC value of the specified channel.
 */
uint32_t adc14_get_channel_value(const Adc14sdc *p_adc, const enum adc14_channel_num_t adc_ch)
{
	uint32_t ul_data = 0;

	if (15 >= adc_ch) {
		ul_data = *(p_adc->ADC14SDC_CDR + adc_ch);
	}

	return ul_data;
}

/**
 * \brief Read the last ADC result data.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return ADC latest value.
 */
uint32_t adc14_get_latest_value(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_LCDR;
}

/**
 * \brief Enable TAG option so that the number of the last converted channel 
 * can be indicated.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc14_enable_tag(Adc14sdc *p_adc)
{
	p_adc->ADC14SDC_MR |= ADC14SDC_MR_TAG;
}

/**
 * \brief Disable TAG option.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc14_disable_tag(Adc14sdc *p_adc)
{
	p_adc->ADC14SDC_MR &= ~ADC14SDC_MR_TAG;
}

/**
 * \brief Indicate the last converted channel.
 *
 * \note If TAG option is NOT enabled before, an incorrect channel 
 * number is returned.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return The last converted channel number.
 */
enum adc14_channel_num_t adc14_get_tag(const Adc14sdc *p_adc)
{
	return (enum adc14_channel_num_t)
			((p_adc->ADC14SDC_LCDR & ADC14SDC_LCDR_CHNB_Msk) >> ADC14SDC_LCDR_CHNB_Pos);
}

/**
 * \brief Configure ADC compare window.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param w_low_threshold Low threshold of compare window.
 * \param w_high_threshold High threshold of compare window.
 */
void adc14_set_comparison_window(Adc14sdc *p_adc, const enum adc14_channel_num_t channel,
                                 const uint16_t us_low_threshold,
		                         const uint16_t us_high_threshold)
{
	p_adc->ADC14SDC_CWR[channel] = ADC14SDC_CWR_LOWTHRES(us_low_threshold) |
			ADC14SDC_CWR_HIGHTHRES(us_high_threshold);
}

/**
 * \brief Set analog signal gain and offset for the specified channel.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param channel ADC channel number.
 * \param channel ADC gain.
 * \param channel ADC offset.
 * \param channel ADC shift.
 */
void adc14_set_channel_gain_offset(Adc14sdc *p_adc, const enum adc14_channel_num_t channel,
                                   const uint16_t us_gain,
                                   const uint16_t us_offset,
                                   const uint16_t us_shift)
{
	p_adc->ADC14SDC_CGOR[channel] = ADC14SDC_CGOR_GAIN(us_gain)
                                  | ADC14SDC_CGOR_OFFSET(us_offset)
                                  | ADC14SDC_CGOR_SHIFT(us_shift);
}


/**
 * \brief Return the actual ADC clock.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_mck Main clock of the device (in Hz).
 *
 * \return The actual ADC clock (in Hz).
 */
uint32_t adc14_get_actual_adc_clock(const Adc14sdc *p_adc, const uint32_t ul_mck)
{
	uint32_t ul_adcfreq;
	uint32_t ul_prescal;

	/* ADCClock = MCK / ( (PRESCAL+1) * 2 ) */
	ul_prescal = ((p_adc->ADC14SDC_MR & ADC14SDC_MR_PRESCAL_Msk) >> ADC14SDC_MR_PRESCAL_Pos);
	ul_adcfreq = ul_mck / ((ul_prescal + 1) * 2);
	return ul_adcfreq;
}

/**
 * \brief Enable ADC EOC interrupts.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_source Interrupts to be enabled.
 */
void adc14_enable_eoc_interrupt(Adc14sdc *p_adc, const uint32_t ul_source)
{
	p_adc->ADC14SDC_IE1R = ul_source;
}

/**
 * \brief Enable ADC Comparison Error interrupts.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_source Interrupts to be enabled.
 */
void adc14_enable_compe_interrupt(Adc14sdc *p_adc, const uint32_t ul_source)
{
	p_adc->ADC14SDC_IE2R = ul_source;
}

/**
 * \brief Disable ADC EOC interrupts.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_source Interrupts to be disabled.
 */
void adc14_disable_eoc_interrupt(Adc14sdc *p_adc, const uint32_t ul_source)
{
	p_adc->ADC14SDC_ID1R = ul_source;
}

/**
 * \brief Disable ADC Comparison Error interrupts.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_source Interrupts to be disabled.
 */
void adc14_disable_compe_interrupt(Adc14sdc *p_adc, const uint32_t ul_source)
{
	p_adc->ADC14SDC_ID2R = ul_source;
}

/**
 * \brief Get ADC EOC interrupt and overrun error status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return ADC eoc status structure.
 */
uint32_t adc14_get_eoc_status(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_IS1R;
}

/**
 * \brief Get ADC Comparison Error interrupt status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return ADC compe status structure.
 */
uint32_t adc14_get_compe_status(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_IS2R;
}

/**
 * \brief Get ADC interrupt and overrun error status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return ADC status structure.
 */
uint32_t adc14_get_overrun_status(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_OVER;
}

/**
 * \brief Read ADC EOC interrupt mask.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return The interrupt mask value.
 */
uint32_t adc14_get_eoc_interrupt_mask(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_IM1R;
}

/**
 * \brief Read ADC Comparison Error interrupt mask.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return The interrupt mask value.
 */
uint32_t adc14_get_compe_interrupt_mask(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_IM2R;
}

/**
 * \brief Enable or disable write protection of ADC registers.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_enable 1 to enable, 0 to disable.
 */
void adc14_set_writeprotect(Adc14sdc *p_adc, const uint32_t ul_enable)
{
	p_adc->ADC14SDC_WPMR |= ADC14SDC_WPMR_WPKEY(ul_enable);
}

/**
 * \brief Indicate write protect status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return 0 if the peripheral is not protected, or 16-bit write protect 
 * violation Status.
 */
uint32_t adc14_get_writeprotect_status(const Adc14sdc *p_adc)
{
	return p_adc->ADC14SDC_WPSR & ADC14SDC_WPSR_WPVS;
}

/**
 * \brief Check ADC configurations.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_mck Main clock of the device (in Hz).
 */
void adc14_check(Adc14sdc *p_adc, const uint32_t ul_mck)
{
	uint32_t ul_adcfreq;
	uint32_t ul_prescal;

	/* ADCClock = MCK / ( (PRESCAL+1) * 2 ) */
	ul_prescal = ((p_adc->ADC14SDC_MR & ADC14SDC_MR_PRESCAL_Msk) >>
			ADC14SDC_MR_PRESCAL_Pos);
	ul_adcfreq = ul_mck / ((ul_prescal + 1) * 2);
	//printf("ADC clock frequency = %d Hz\r\n", (int)ul_adcfreq); //ERr

	if (ul_adcfreq < ADC14_FREQ_MIN) {
		//printf("adc frequency too low (out of specification: %d Hz)\r\n", //ERr
			//(int)ADC14_FREQ_MIN); //ERr
	}
	if (ul_adcfreq > ADC14_FREQ_MAX) {
		//printf("adc frequency too high (out of specification: %d Hz)\r\n", //ERr
			//(int)ADC14_FREQ_MAX); //ERr
	}

        if (p_adc->ADC14SDC_MR & ADC14SDC_MR_FREERUN_ON) {
                //puts("FreeRun forbidden in sleep mode\r"); //ERr
        }
}

//@}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
