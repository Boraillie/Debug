/*! \file *********************************************************************
 *
 * \brief TC driver for SAM3.
 *
 * TC (Timer Counter) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.com/
 *
 ******************************************************************************/

/* $asf_license$ */

#ifndef _TC_
#define _TC_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/*----------------------------------------------------------------------------
 *        Global Functions
 *----------------------------------------------------------------------------*/
extern void tc_init(Tc * p_tc, uint32_t ul_Channel, uint32_t ul_Mode);
extern uint32_t tc_init_quad_dec(Tc * p_tc, uint32_t ul_blockmode);

//#if (SAM3S || SAM3N || SAM3XA || SAM4S) //ERr SAM4S
#if (TC_HAS_SMMR == 1)
extern uint32_t tc_init_2bit_gray(Tc * p_tc, uint32_t ul_channel,
		uint32_t ul_steppermode);
#endif

extern void tc_enable(Tc * tc, uint32_t ul_channel);
extern void tc_disable(Tc * tc, uint32_t ul_channel);
extern uint32_t tc_find_mck_divisor(uint32_t ul_freq, uint32_t ul_mck,
		uint32_t * p_uldiv, uint32_t * ul_tcclks, uint32_t ul_boardmck);
extern void tc_enable_interrupt(Tc * tc, uint32_t ul_channel,
		uint32_t ul_sources);
extern void tc_disable_interrupt(Tc * tc, uint32_t ul_channel,
		uint32_t ul_sources);
extern uint32_t tc_get_interrupt_mask(Tc * tc, uint32_t ul_channel);
extern uint32_t tc_get_status(Tc * tc, uint32_t ul_channel);
#if (TC_HAS_QDEC == 1) //ERr
extern void tc_enable_qdec_interrupt(Tc * tc, uint32_t ul_sources);
extern void tc_disable_qdec_interrupt(Tc * tc, uint32_t ul_sources);
extern uint32_t tc_get_qdec_interrupt_mask(Tc * tc);
extern uint32_t tc_get_qdec_interrupt_status(Tc * tc);
#endif
//#if (SAM3S || SAM3N || SAM3XA || SAM4S) //ERr SAM4S
#if (TC_HAS_WR_PROTECT == 1) //ERr
extern void tc_set_writeprotect(Tc * tc, uint32_t ul_enable);
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* _TC_ */
