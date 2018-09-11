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

#ifndef IDACC_H_INCLUDED
#define IDACC_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond


struct idacc_cfg_desc {
    uint32_t idacc_clock;
    uint32_t prescaler;
    uint32_t index_sel;
    uint32_t size;
    uint32_t mode;
    uint32_t sync_del;
    uint32_t adc_sync;
    uint32_t startup;
    uint32_t rtz;
    uint32_t clkup6;
};




void idacc_reset(Idacc *p_idacc);
void idacc_init(Idacc *p_idacc, struct idacc_cfg_desc *idacc_desc);
void idacc_enable_interrupt(Idacc *p_idacc, uint32_t ul_interrupt_mask);
void idacc_disable_interrupt(Idacc *p_idacc, uint32_t ul_interrupt_mask);
uint32_t idacc_get_interrupt_mask(Idacc *p_idacc);
uint32_t idacc_get_interrupt_status(Idacc *p_idacc);
void idacc_write_conversion_data(Idacc *p_idacc, uint32_t ul_data);
void idacc_set_writeprotect(Idacc *p_idacc, uint32_t ul_enable);
uint32_t idacc_get_writeprotect_status(Idacc *p_idacc);
void idacc_enable(Idacc *p_idacc);
void idacc_disable(Idacc *p_idacc);

void idacc_set_channel_selection(Idacc *p_idacc, uint32_t ul_channel);

uint32_t idacc_set_timing(Idacc *p_idacc, uint32_t ul_refresh, uint32_t ul_maxs, uint32_t ul_startup);
void idacc_enable_channel(Idacc *p_idacc, uint32_t ul_channel);
void idacc_disable_channel(Idacc *p_idacc, uint32_t ul_channel);
uint32_t idacc_get_channel_status(Idacc *p_idacc);
void idacc_set_min_max_data(Idacc *p_idacc, uint32_t ul_max, uint32_t ul_min);
uint32_t idacc_get_max_data(Idacc *p_idacc);
uint32_t idacc_get_min_data(Idacc *p_idacc);
void idacc_set_analog_current(Idacc *p_idacc, uint32_t ul_analog_current);
uint32_t idacc_get_analog_current(Idacc *p_idacc);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* IDACC_H_INCLUDED */
