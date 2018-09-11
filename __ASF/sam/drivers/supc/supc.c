/**
 * \file
 *
 * \brief Supply Controller (SUPC) driver for SAM.
 *
 * Copyright (c) 2011 Atmel Corporation. All rights reserved.
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

#include "supc.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \defgroup sam_drivers_supc_group Supply Controller (SUPC)
 *
 * Driver for the SUPC (Supply Controller). This driver provides access to the main 
 * features of the Supply Controller.
 *
 * @{
 */

#define SUPC_KEY   0xA5u

/**
 * \brief Switch off the voltage regulator to put the device in backup mode.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_backup_mode(Supc *p_supc)
{
	p_supc->SUPC_CR = SUPC_CR_KEY_PASSWD | SUPC_CR_VROFF;
}

/**
 * \brief Switch slow clock source selection to external 32k (Xtal or Bypass) oscillator.
 * This function disables the PLLs.
 *
 * \note Switching sclk back to 32krc is only possible by shutting down the VDDIO power supply.
 *
 * \param ul_bypass 0 for Xtal, 1 for bypass.
 */
void supc_switch_sclk_to_32kxtal(Supc *p_supc, uint32_t ul_bypass)
{
	/* Set Bypass mode if required */
	if (ul_bypass == 1) {
		p_supc->SUPC_MR |= SUPC_MR_KEY_PASSWD | SUPC_MR_OSCBYPASS;
	}

	p_supc->SUPC_CR |= SUPC_CR_KEY_PASSWD | SUPC_CR_XTALSEL;
}

#if !LIMES
/**
 * \brief Enable the internal voltage regulator.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_voltage_regulator(Supc *p_supc)
{
#if (SAM3U || SAM3XA)
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_VDDIORDYONREG));
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr | SUPC_MR_VDDIORDYONREG;
#else
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_ONREG));
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr | SUPC_MR_ONREG;
#endif
}

/**
 * \brief Disable the internal voltage regulator to supply VDDCORE with an external supply.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_voltage_regulator(Supc *p_supc)
{
#if (SAM3U || SAM3XA)
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_VDDIORDYONREG));
#else
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_ONREG));
#endif
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr;
}
#endif

/**
 * \brief Enable the core brownout detector.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_brownout_detector(Supc *p_supc)
{
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_BODDIS));
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr;
}

/**
 * \brief Disable the core brownout detector.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_brownout_detector(Supc *p_supc)
{
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_BODDIS));
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr | SUPC_MR_BODDIS;
}

/**
 * \brief Enable the assertion of core reset signal when a brownout detection occurs.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_brownout_reset(Supc *p_supc)
{
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_BODRSTEN));
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr | SUPC_MR_BODRSTEN;
}

/**
 * \brief Disable the assertion of core reset signal when a brownout detection occurs.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_brownout_reset(Supc *p_supc)
{
	uint32_t ul_mr = p_supc->SUPC_MR & (~(SUPC_MR_KEY_Msk | SUPC_MR_BODRSTEN));
	p_supc->SUPC_MR = SUPC_MR_KEY_PASSWD | ul_mr;
}

/**
 * \brief Set Supply monitor threshold.
 *
 * \param p_supc Pointer to a SUPC instance.
 * \param ul_threshold Supply monitor threshold (between 1.9V and 3.4V).
 */
void supc_set_monitor_threshold(Supc *p_supc, uint32_t ul_threshold)
{
	uint32_t ul_smmr = p_supc->SUPC_SMMR & (~SUPC_SMMR_SMTH_Msk);
	p_supc->SUPC_SMMR = ul_smmr | (SUPC_SMMR_SMTH_Msk & ul_threshold);
}

/**
 * \brief Set Supply monitor sampling period.
 *
 * \param p_supc Pointer to a SUPC instance.
 * \param ul_period Supply monitor sampling period.
 */
void supc_set_monitor_sampling_period(Supc *p_supc, uint32_t ul_period)
{
	uint32_t ul_smmr = p_supc->SUPC_SMMR & (~SUPC_SMMR_SMSMPL_Msk);
	p_supc->SUPC_SMMR = ul_smmr | (SUPC_SMMR_SMSMPL_Msk & ul_period);
}

/**
 * \brief Enable the assertion of the core reset signal when a supply monitor detection occurs.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_monitor_reset(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_SMRSTEN;
}

/**
 * \brief Disable the assertion of core reset signal when a supply monitor detection occurs.
 *
 * \param p_supc Pointer to a SUPC instance. 
 */
void supc_disable_monitor_reset(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_SMRSTEN;
}

/**
 * \brief Enable the assertion of SUPC interrupt signal when a supply monitor detection occurs.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_monitor_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_SMIEN;
}

/**
 * \brief Disable the assertion of SUPC interrupt signal when a supply monitor detection occurs.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_monitor_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_SMIEN;
}


#if LIMES
/**
 * \brief Enable over voltage Supply Monitor.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_ov_mon(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_OVSMEN;
}

/**
 * \brief Disable over voltage Supply Monitor.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_ov_mon(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_OVSMEN;
}

/**
 * \brief Enable over voltage Supply Monitor Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_ov_mon_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_OVSMIEN;
}

/**
 * \brief Disable over voltage Supply Monitor Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_ov_mon_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_OVSMIEN;
}

/**
 * \brief Enable over voltage Supply Monitor Debug mode.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_ov_mon_dbg(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_OVSMDBG;
}

/**
 * \brief Disable over voltage Supply Monitor Debug mode.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_ov_monitor_dbg(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_OVSMDBG;
}

/**
 * \brief Enable over voltage Supply Monitor output status.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_ov_mon_out_status(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_OVSMOS;
}

/**
 * \brief Disable over voltage Supply Monitor output status.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_ov_mon_out_status(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_OVSMOS;
}

/**
 * \brief Enable VUSB Ready Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_vusb_ready_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_VUSBRIEN;
}

/**
 * \brief Disable VUSB Ready Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_vusb_ready_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_VUSBRIEN;
}

/**
 * \brief Enable VBUS Drop Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_vbus_drop_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR |= SUPC_SMMR_VBUSDIEN;
}

/**
 * \brief Disable VBUS Drop Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_vbus_drop_interrupt(Supc *p_supc)
{
	p_supc->SUPC_SMMR &= ~SUPC_SMMR_VBUSDIEN;
}

/**
 * \brief Get VUSB Supply Monitor Output Status .
 *
 * \param p_supc Pointer to a SUPC instance.<F8>
 */
uint32_t supc_get_vusb_mon_ouput_status(Supc *p_supc)
{
	return (p_supc->SUPC_SMMR & SUPC_SMMR_VUSBSMOS);
}

/**
 * \brief Get VBUS Supply Monitor Output Status .
 *
 * \param p_supc Pointer to a SUPC instance.
 */
uint32_t supc_get_vbus_mon_ouput_status(Supc *p_supc)
{
	return (p_supc->SUPC_SMMR & SUPC_SMMR_VBUSSMOS);
}

/**
 * \brief read AMR register.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
uint32_t supc_get_amr(Supc *p_supc)
{
	return (p_supc->SUPC_AMR);
}

/**
 * \brief Enable VDDANA.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_vddana(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_VANAON));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_VANAON;
}

/**
 * \brief Disable VDDANA.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_vddana(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_VANAON));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr;
}

/**
 * \brief Set DCDC Output Typical Voltage.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_configure_dcdc(Supc *p_supc, uint32_t ul_dcdcmode, uint32_t ul_dcdcvoltage)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_DCDCVSEL_Msk));
    p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | ul_dcdcmode | ul_dcdcvoltage;
}

/**
 * \brief Enable VDDANA Rising Edge Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_vddana_rising_edge_interrupt(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_VANARIEN));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_VANARIEN;
}

/**
 * \brief Disable VDDANA Rising Edge Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_vddana_rising_edge_interrupt(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_VANARIEN));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr;
}

/**
 * \brief Enable VDDANA Falling Edge Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_vddana_falling_edge_interrupt(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_VANAFIEN));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_VANAFIEN;
}

/**
 * \brief Disable VDDANA Falling Edge Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_vddana_falling_edge_interrupt(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_VANAFIEN));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr;
}

/**
 * \brief Enable Low Noise Band Gap.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_low_noise_bandgap(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_LNBGON));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_LNBGON;
}

/**
 * \brief Disable Low Noise Band Gap.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_low_noise_bandgap(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_LNBGON));
    p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr;
}

/**
 * \brief Enable Low Noise Band Gap Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_low_noise_bandgap_interrupt(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_LNBGIEN));
    p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_LNBGIEN;
}

/**
 * \brief Disable Low Noise Band Gap Interrupt.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_low_noise_bandgap_interrupt(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_LNBGIEN));
    p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr;
}

/**
 * \brief Low Noise Pad OFF.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_low_noise_pad_off(Supc *p_supc)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_LNPADOFF));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_LNPADOFF;
}

/**
 * \brief Set Startup Current Limitation.
 *
 * \param p_supc Pointer to a SUPC instance.
 * \param ul_startup_cur_lim Current Limitation for Start-up Sequence.
 */
void supc_set_startup_cur_limit(Supc *p_supc, uint32_t ul_startup_cur_lim)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_ILIMSTART_Msk));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_ILIMSTART(ul_startup_cur_lim);
}

/**
 * \brief Set Max Current Limitation.
 *
 * \param p_supc Pointer to a SUPC instance.
 * \param ul_max_cur_lim Maximum Current Limitation.
 */
void supc_set_max_cur_limit(Supc *p_supc, uint32_t ul_max_cur_lim)
{
    uint32_t ul_amr = p_supc->SUPC_AMR & (~(SUPC_AMR_KEY_Msk | SUPC_AMR_ILIMMAX_Msk));
	p_supc->SUPC_AMR = SUPC_AMR_KEY_PASSWD | ul_amr | SUPC_AMR_ILIMMAX(ul_max_cur_lim);
}

/**
 * \brief Enable VREFP of Low Noise Bang Gap.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_enable_vrefp(Supc *p_supc)
{
	p_supc->SUPC_ATR = SUPC_ATR_KEY_PASSWD & ~SUPC_ATR_DISVREFP;
}

/**
 * \brief Disable VREFP of Low Noise Bang Gap.
 *
 * \param p_supc Pointer to a SUPC instance.
 */
void supc_disable_vrefp(Supc *p_supc)
{
	p_supc->SUPC_ATR = SUPC_ATR_KEY_PASSWD | SUPC_ATR_DISVREFP;
}

#endif


/**
 * \brief Set system controller wake up mode.
 *
 * \param p_supc Pointer to a SUPC instance.
 * \param ul_mode Bitmask of wake up mode (please refer to datasheet for more details).
 */
void supc_set_wakeup_mode(Supc *p_supc, uint32_t ul_mode)
{
	p_supc->SUPC_WUMR = ul_mode;
}

/**
 * \brief Set system controller wake up inputs.
 *
 * \param p_supc Pointer to a SUPC instance.
 * \param ul_inputs Bitmask of wake-up inputs that can force wake up of 
 * the core power supply.
 * \param ul_transition Bitmask of level transition of the wake-up inputs.
 * 1 means a high-to-low level transition forces the wake up of core power supply. 
 * 0 means a low-to-high level transition forces the wake up of core power supply.
 */
void supc_set_wakeup_inputs(Supc *p_supc, uint32_t ul_inputs,
		uint32_t ul_transition)
{
	p_supc->SUPC_WUIR = ul_inputs | ul_transition;
}

/**
 * \brief Get supply controller status.
 *
 * \param p_supc Pointer to a SUPC instance.
 *
 * \return The status of supply controller.
 */
uint32_t supc_get_status(Supc *p_supc)
{
	return p_supc->SUPC_SR;
}

//@}

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
