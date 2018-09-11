/*! \file *********************************************************************
 *
 * \brief ACC driver for SAM3.
 *
 * $asf_license$
 *
 * Analog Comparator Controller(ACC) driver module for SAM3 MCUs.
 *
 * - Compiler: 		  IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  SAM3S devices.
 * - AppNote:
 *
 * \author 			  Atmel Corporation: http://www.atmel.com \n
 * 					  Support and FAQ: http://support.atmel.com/
 *
 ******************************************************************************/

#ifndef ACC_H_INCLUDED
#define ACC_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#if (DEVICE_HAS_ACC)
void acc_init(Acc *p_acc, uint32_t ul_select_plus, uint32_t ul_select_minus,
		uint32_t ul_edge_type, uint32_t ul_invert);
void acc_enable(Acc *p_acc);
void acc_disable(Acc *p_acc);
void acc_reset(Acc *p_acc);
void acc_set_input(Acc *p_acc, uint32_t ul_select_minus,
		uint32_t ul_select_plus);
void acc_set_output(Acc *p_acc, uint32_t ul_invert,
		uint32_t ul_fault_enable, uint32_t ul_fault_source);
uint32_t acc_get_comparison_result(Acc *p_acc);
void acc_enable_interrupt(Acc *p_acc);
void acc_disable_interrupt(Acc *p_acc);
uint32_t acc_get_interrupt_status(Acc *p_acc);
void acc_set_writeprotect(Acc *p_acc, uint32_t ul_enable);
uint32_t acc_get_writeprotect_status(Acc *p_acc);
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* ACC_H_INCLUDED */
