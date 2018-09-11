/**
 * \file
 *
 * \brief 16-bit Analog-to-Digital Converter (ADC16) driver for Limes.
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

#include "adc16.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \defgroup limes_drivers_adc16_group 16-bit Analog-to-digital Converter (ADC16)
 *
 * See \ref limes_adc16_quickstart.
 *
 * Driver for the 16-bit Analog-to-digital Converter. This driver provides access to the main 
 * features of the ADC16 controller.
 *
 * @{
 */

/**
 * \brief Initialize the given ADC with the specified ADC clock.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_mck Main clock of the device (value in Hz).
 * \param ul_adc_clock Analog-to-Digital conversion clock (value in Hz).
 * \param ul_startuptime ADC startup time value (value in us). 
 * \param ul_tia when set, enables the Trans-Impedance Amplifier (TIA).
 * \param ul_pga when set, enables the Programmable Gain Amplifier (PGA).
 * for details.
 *
 * \return 0 on success.
 */
uint32_t adc16_init(Adc16sdc *p_adc, struct adc16_cfg_desc *adc_desc)
{
    struct adc16_tia_cfg *tia = adc_desc->tia;
    struct adc16_pga_cfg *pga = adc_desc->pga;
    struct adc16_dsp_cfg *dsp = adc_desc->dsp;
    uint32_t ul_prescal;

    /*  Reset the controller. */
    p_adc->ADC16SDC_CR = ADC16SDC_CR_SWRST;

    /* Reset Mode Register. */
    p_adc->ADC16SDC_MR = 0;

    /* Reset PDC transfer. */
    p_adc->ADC16SDC_PTCR = (ADC16SDC_PTCR_RXTDIS | ADC16SDC_PTCR_TXTDIS);
    p_adc->ADC16SDC_RCR = 0;
    p_adc->ADC16SDC_RNCR = 0;

    // TIA configuration
    if (tia->enabled) {

        p_adc->ADC16SDC_TIAR = 0x0;

        if (tia->bypass)
            p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_TBYP;
        if (tia->hi_pass_filter)
            p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_THPFEN;
        if (tia->low_pass_filter)
            p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_TLPFEN;
        if (tia->hi_z)
            p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_THIZEN;
        p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_TINSEL(tia->input);
        if (tia->idac_sel)
            p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_IDACCSEL;

        p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_VIN3(tia->vin3);
        p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_VIN4(tia->vin4);
        p_adc->ADC16SDC_TIAR |= ADC16SDC_TIAR_TIASTARTUP(tia->startuptime);
    }

    /* PGA configuration */
    if (pga->enabled) {
        p_adc->ADC16SDC_PGAR = 0x0;

        if (pga->bypass)
            p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PBYP;
        if (pga->hi_pass_filter)
            p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PHPFEN;
        if (pga->low_pass_filter)
            p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PLPFEN;
        if (pga->hi_z)
            p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PHIZEN;
        if (pga->input == ADC16_PGA_INPUT_PINS)
            p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PINSEL;

        p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PGAGAIN(pga->gain);
        p_adc->ADC16SDC_PGAR |= ADC16SDC_PGAR_PGASTARTUP(pga->startuptime);
    }

    /* DSP configuration */
    p_adc->ADC16SDC_DSPR0 = 0x0;
    if (dsp->fir_bypass)
        p_adc->ADC16SDC_DSPR0 |= ADC16SDC_DSPR0_FIRBYP;
    if (dsp->iir_bypass)
        p_adc->ADC16SDC_DSPR0 |= ADC16SDC_DSPR0_IIRBYP;
    if (dsp->sincc_bypass)
        p_adc->ADC16SDC_DSPR0 |= ADC16SDC_DSPR0_SINBYP;
    if (dsp->data_size == ADC16_DSP_SIZE_32)
        p_adc->ADC16SDC_DSPR0 |= ADC16SDC_DSPR0_SIZE;

    p_adc->ADC16SDC_DSPR0 |= dsp->osr;
    p_adc->ADC16SDC_DSPR0 |= ADC16SDC_DSPR0_SCALE(dsp->scale);
    p_adc->ADC16SDC_DSPR0 |= ADC16SDC_DSPR0_SHIFT(dsp->shift);
    p_adc->ADC16SDC_DSPR1 |= ADC16SDC_DSPR1_DGAIN(dsp->gain);
    p_adc->ADC16SDC_DSPR1 |= ADC16SDC_DSPR1_OFFSET(dsp->offset);

    /* ADC16 Configuration */
    ul_prescal = adc_desc->mck / (2 * adc_desc->adc_clock) - 1;
    p_adc->ADC16SDC_MR |= ADC16SDC_MR_PRESCAL(ul_prescal)|
                          ((adc_desc->startuptime << ADC16SDC_MR_STARTUP_Pos) &
                          ADC16SDC_MR_STARTUP_Msk);

    if (adc_desc->insel) {
        p_adc->ADC16SDC_MR = ADC16SDC_MR_INSEL;
    }

    if (adc_desc->invt) {
        p_adc->ADC16SDC_MR = ADC16SDC_MR_INVT;
    }

    if (adc_desc->dyninv) {
        p_adc->ADC16SDC_MR = ADC16SDC_MR_DYNINV;
    }

    return 0;
}

/**
 * \brief Start analog-to-digital conversion.
 *
 * \note If one of the hardware event is selected as ADC trigger, 
 * this function can NOT start analog to digital conversion.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_start(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_CR |= ADC16SDC_CR_ENADC;
}

/**
 * \brief Stop analog-to-digital conversion.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_stop(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_CR = ADC16SDC_CR_SWRST;
}

/**
 * \brief Enable TIA.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_enable_tia(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_CR |= ADC16SDC_CR_ENTIA;
}

/**
 * \brief Disable TIA.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_disable_tia(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_CR &= ~ADC16SDC_CR_ENTIA;
}

/**
 * \brief Enable PGA.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_enable_pga(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_CR |= ADC16SDC_CR_ENPGA;
}

/**
 * \brief Disable PGA.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_disable_pga(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_CR &= ~ADC16SDC_CR_ENPGA;
}

/**
 * \brief Read the ADC result data.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return ADC value.
 */
uint32_t adc16_get_value(const Adc16sdc *p_adc)
{
	return (p_adc->ADC16SDC_CDR);
}

/**
 * \brief Set analog signal gain and offset.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param channel ADC gain.
 * \param channel ADC offset.
 * \param channel ADC shift.
 */
void adc16_set_dsp_gain_offset(Adc16sdc *p_adc,
                               const uint16_t us_gain,
                               const uint16_t us_offset)
{
	p_adc->ADC16SDC_DSPR1 = ADC16SDC_DSPR1_DGAIN(us_gain)
                              | ADC16SDC_DSPR1_OFFSET(us_offset);
}


/**
 * \brief Return the actual ADC clock.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_mck Main clock of the device (in Hz).
 *
 * \return The actual ADC clock (in Hz).
 */
uint32_t adc16_get_actual_adc_clock(const Adc16sdc *p_adc, const uint32_t ul_mck)
{
    uint32_t ul_adcfreq;
    uint32_t ul_prescal;

    /* ADCClock = MCK / ( (PRESCAL+1) * 2 ) */
    ul_prescal = ((p_adc->ADC16SDC_MR & ADC16SDC_MR_PRESCAL_Msk) >> ADC16SDC_MR_PRESCAL_Pos);
    ul_adcfreq = ul_mck / ((ul_prescal + 1) * 2);

    return ul_adcfreq;
}

/**
 * \brief Enable ADC interrupts.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_source Interrupts to be enabled.
 */
void adc16_enable_interrupt(Adc16sdc *p_adc, uint32_t ul_source)
{
	p_adc->ADC16SDC_IER = ul_source;
}

/**
 * \brief Disable ADC interrupt.
 *
 * \param p_adc Pointer to an ADC instance.
 * \param ul_source Interrupts to be disabled.
 */
void adc16_disable_interrupt(Adc16sdc *p_adc, uint32_t ul_source)
{
	p_adc->ADC16SDC_IDR = ul_source;
}

/**
 * \brief Get ADC interrupt status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return ADC eoc status structure.
 */
uint32_t adc16_get_status(const Adc16sdc *p_adc)
{
	return p_adc->ADC16SDC_ISR;
}

/**
 * \brief Read ADC interrupt mask.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return The interrupt mask value.
 */
uint32_t adc16_get_interrupt_mask(const Adc16sdc *p_adc)
{
	return p_adc->ADC16SDC_IMR;
}

/**
 * \brief Enable write protection of ADC registers.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_enable_writeprotect(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_WPMR = ADC16SDC_WPMR_WPKEY_PASSWD | ADC16SDC_WPMR_WPEN;
}

/**
 * \brief Disable write protection of ADC registers.
 *
 * \param p_adc Pointer to an ADC instance.
 */
void adc16_disable_writeprotect(Adc16sdc *p_adc)
{
	p_adc->ADC16SDC_WPMR = ADC16SDC_WPMR_WPKEY_PASSWD & ~ADC16SDC_WPMR_WPEN;
}

/**
 * \brief Indicate write protect status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 * \return 0 if the peripheral is not protected, or 16-bit write protect 
 * violation Status.
 */
uint32_t adc16_get_writeprotect_status(const Adc16sdc *p_adc)
{
	return p_adc->ADC16SDC_WPSR & ADC16SDC_WPSR_WPVS;
}

/**
 * \brief Indicate write protect status.
 *
 * \param p_adc Pointer to an ADC instance.
 *
 */
void adc16_set_synchro(Adc16sdc *p_adc, uint32_t idacc_id, uint32_t counter)
{
	p_adc->ADC16SDC_SYNR = idacc_id | counter;
}


//@}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
