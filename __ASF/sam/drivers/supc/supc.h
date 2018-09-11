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

#ifndef SUPC_H_INCLUDED
#define SUPC_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

void supc_enable_backup_mode(Supc *p_supc);
void supc_switch_sclk_to_32kxtal(Supc *p_supc, uint32_t ul_bypass);
void supc_enable_voltage_regulator(Supc *p_supc);
void supc_disable_voltage_regulator(Supc *p_supc);
void supc_enable_brownout_detector(Supc *p_supc);
void supc_disable_brownout_detector(Supc *p_supc);
void supc_enable_brownout_reset(Supc *p_supc);
void supc_disable_brownout_reset(Supc *p_supc);
void supc_set_monitor_threshold(Supc *p_supc, uint32_t ul_threshold);
void supc_set_monitor_sampling_period(Supc *p_supc, uint32_t ul_period);
void supc_enable_monitor_reset(Supc *p_supc);
void supc_disable_monitor_reset(Supc *p_supc);
void supc_enable_monitor_interrupt(Supc *p_supc);
void supc_disable_monitor_interrupt(Supc *p_supc);
void supc_set_wakeup_mode(Supc *p_supc, uint32_t ul_mode);
void supc_set_wakeup_inputs(Supc *p_supc, uint32_t ul_inputs,
		uint32_t ul_transition);
uint32_t supc_get_status(Supc *p_supc);
#if LIMES
void supc_enable_ov_mon(Supc *p_supc);
void supc_disable_ov_mon(Supc *p_supc);
void supc_enable_ov_mon_interrupt(Supc *p_supc);
void supc_disable_ov_mon_interrupt(Supc *p_supc);
void supc_enable_ov_mon_dbg(Supc *p_supc);
void supc_disable_ov_monitor_dbg(Supc *p_supc);
void supc_enable_ov_mon_out_status(Supc *p_supc);
void supc_disable_ov_mon_out_status(Supc *p_supc);
void supc_enable_vusb_ready_interrupt(Supc *p_supc);
void supc_disable_vusb_ready_interrupt(Supc *p_supc);
void supc_enable_vbus_drop_interrupt(Supc *p_supc);
void supc_disable_vbus_drop_interrupt(Supc *p_supc);
uint32_t supc_get_vusb_mon_ouput_status(Supc *p_supc);
uint32_t supc_get_vbus_mon_ouput_status(Supc *p_supc);
uint32_t supc_get_amr(Supc *p_supc);
void supc_enable_vddana(Supc *p_supc);
void supc_disable_vddana(Supc *p_supc);
void supc_configure_dcdc(Supc *p_supc, uint32_t ul_dcdcmode, uint32_t ul_dcdcvoltage);
void supc_enable_vddana_rising_edge_interrupt(Supc *p_supc);
void supc_disable_vddana_rising_edge_interrupt(Supc *p_supc);
void supc_enable_vddana_falling_edge_interrupt(Supc *p_supc);
void supc_disable_vddana_falling_edge_interrupt(Supc *p_supc);
void supc_enable_low_noise_bandgap(Supc *p_supc);
void supc_disable_low_noise_bandgap(Supc *p_supc);
void supc_enable_low_noise_bandgap_interrupt(Supc *p_supc);
void supc_disable_low_noise_bandgap_interrupt(Supc *p_supc);
void supc_low_noise_pad_off(Supc *p_supc);
void supc_set_startup_cur_limit(Supc *p_supc, uint32_t ul_startup_cur_lim);
void supc_set_max_cur_limit(Supc *p_supc, uint32_t ul_max_cur_lim);
void supc_enable_vrefp(Supc *p_supc);
void supc_disable_vrefp(Supc *p_supc);
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* SUPC_H_INCLUDED */
