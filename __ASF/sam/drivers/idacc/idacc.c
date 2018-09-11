/**
 * \file
 *
 * \brief Current Digital-to-Analog Converter Controller (IDACC) driver for Limes.
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

#include "idacc.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \defgroup sam_drivers_idacc_group Current Digital-to-Analog Converter Controller (IDACC)
 *
 * \par Purpose
 *
 * Driver for the Current Digital-to-Analog Converter Controller. It provides access to the main 
 * features of the DAC controller.
 *
 * \par Usage
 *
 *
 * \section dependencies Dependencies
 * This driver does not depend on other modules.
 *
 * @{
 */

//! DACC Write Protect Key "DAC" in ASCII
#define IDACC_WP_KEY     (0x494441)

/**
 * \brief Reset IDACC.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 */
void idacc_reset(Idacc *p_idacc)
{
	p_idacc->IDACC_CR = IDACC_CR_SWRST;
}


/**
 * \brief Initialize IDACC.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param idacc_desc IDACC mode configuration descriptor.
 *
 */
void idacc_init(Idacc *p_idacc, struct idacc_cfg_desc *idacc_desc)
{
    idacc_reset(p_idacc);

    p_idacc->IDACC_MR = IDACC_MR_PRESCAL(idacc_desc->prescaler)
                      | IDACC_MR_INDEX_SEL(idacc_desc->index_sel)
                      | idacc_desc->size
                      | idacc_desc->mode
                      | IDACC_MR_SYNC_DEL(idacc_desc->sync_del)
                      | idacc_desc->startup;

    if (idacc_desc->adc_sync)
        p_idacc->IDACC_MR |= IDACC_MR_ADC_SYNC_ENABLED;

    if (idacc_desc->rtz)
        p_idacc->IDACC_MR |= IDACC_MR_RTZ_ENA_ENABLE;

    if (idacc_desc->clkup6)
        p_idacc->IDACC_MR |= IDACC_MR_CLKUP6M;

}

/**
 * \brief Enable IDACC interrupts.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_interrupt_mask The interrupt mask.
 */
void idacc_enable_interrupt(Idacc *p_idacc, uint32_t ul_interrupt_mask)
{
	p_idacc->IDACC_IER = ul_interrupt_mask;
}

/**
 * \brief Disable IDACC interrupts.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_interrupt_mask The interrupt mask.
 */
void idacc_disable_interrupt(Idacc *p_idacc, uint32_t ul_interrupt_mask)
{
	p_idacc->IDACC_IDR = ul_interrupt_mask;
}

/**
 * \brief Get the interrupt mask.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 * \return The interrupt mask.
 */
uint32_t idacc_get_interrupt_mask(Idacc *p_idacc)
{
	return p_idacc->IDACC_IMR;
}

/**
 * \brief Get the interrupt status.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 * \return The interrupt status.
 */
uint32_t idacc_get_interrupt_status(Idacc *p_idacc)
{
	return p_idacc->IDACC_ISR;
}

/**
 * \brief Write data to conversion register.
 *
 * \note The \a ul_data could be output data or data with channel TAG when
 * flexible mode is used.
 *
 * In flexible mode the 2 bits, IDACC_CDR[13:12] which are otherwise unused,
 * are employed to select the channel in the same way as with the USER_SEL
 * field. Finally, if the WORD field is set, the 2 bits, IDACC_CDR[13:12] are
 * used for channel selection of the first data and the 2 bits,
 * IDACC_CDR[29:28] for channel selection of the second data.
 *
 * \see idacc_enable_flexible_selection()
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_data The data to be transferred to analog value. 
 */
void idacc_write_conversion_data(Idacc *p_idacc, uint32_t ul_data)
{
	p_idacc->IDACC_CDR = ul_data;
}

/**
 * \brief Enable or disable write protect of IDACC registers.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_enable 1 to enable, 0 to disable.
 */
void idacc_set_writeprotect(Idacc *p_idacc, uint32_t ul_enable)
{
	if (ul_enable) {
		p_idacc->IDACC_WPMR = IDACC_WPMR_WPKEY(IDACC_WP_KEY)
			                | IDACC_WPMR_WPEN;
	} else {
		p_idacc->IDACC_WPMR = IDACC_WPMR_WPKEY(IDACC_WP_KEY);
	}
}

/**
 * \brief Get the write protect status.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 * \return Write protect status.
 */
uint32_t idacc_get_writeprotect_status(Idacc *p_idacc)
{
	return p_idacc->IDACC_WPSR;
}

/**
 * \brief Get PDC registers base address.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 * \return IDACC PDC register base address.
 */
//Pdc *idacc_get_pdc_base(Idacc *p_idacc)
//{
//	return PDC_IDACC;
//}


/**
 * \brief Enable IDACC channel.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_channel The output channel to enable.
 *
 */
void idacc_enable_channel(Idacc *p_idacc, uint32_t ul_channel)
{
	p_idacc->IDACC_CHER = IDACC_CHER_CH0 << ul_channel;
}

/**
 * \brief Disable IDACC channel.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_channel The output channel to disable.
 *
 */
void idacc_disable_channel(Idacc *p_idacc, uint32_t ul_channel)
{
	p_idacc->IDACC_CHDR = IDACC_CHDR_CH0 << ul_channel;
}

/**
 * \brief Get the channel status.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 * \return IDACC channel status.
 */
uint32_t idacc_get_channel_status(Idacc *p_idacc)
{
	return p_idacc->IDACC_CHSR;
}

/**
 * \brief Set the Min and Max DAC converted values.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_max Constant Maximum DAC Converted Data.
 * \param ul_min Constant Minimum DAC Converted Data.
 *
 */
void idacc_set_min_max_data(Idacc *p_idacc, uint32_t ul_max, uint32_t ul_min)
{
	p_idacc->IDACC_DDR = IDACC_DDR_DATA_MAX(ul_max) | IDACC_DDR_DATA_MIN(ul_min);
}

/**
 * \brief Get the Max DAC converted values.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 */
uint32_t idacc_get_max_data(Idacc *p_idacc)
{
	return ((p_idacc->IDACC_DDR & IDACC_DDR_DATA_MAX_Msk) >> IDACC_DDR_DATA_MAX_Pos);
}

/**
 * \brief Get the Min DAC converted values.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 */
uint32_t idacc_get_min_data(Idacc *p_idacc)
{
	return ((p_idacc->IDACC_DDR & IDACC_DDR_DATA_MIN_Msk) >> IDACC_DDR_DATA_MIN_Pos);
}

/**
 * \brief Set the analog output current trimming value.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 * \param ul_analog_current Analog output current trimming value.
 *
 */
void idacc_set_analog_current(Idacc *p_idacc, uint32_t ul_analog_current)
{
	p_idacc->IDACC_ACR = IDACC_ACR_ICTLDAC(ul_analog_current);

}

/**
 * \brief Get the analog output current trimming value.
 *
 * \param p_idacc Pointer to a IDACC instance. 
 *
 * \return Analog output current trimming value.
 */
uint32_t idacc_get_analog_current(Idacc *p_idacc)
{
	return p_idacc->IDACC_ACR;
}

//@}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
