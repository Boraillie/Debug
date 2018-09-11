/*! \file *********************************************************************
 *
 * \brief PMC driver for SAM3.
 *
 * $asf_license$
 *
 * Power Management Controller (PMC) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.com/
 *
 ******************************************************************************/

#ifndef PMC_H_INCLUDED
#define PMC_H_INCLUDED

#include "compiler.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond
  


// Validation patch: in case of two slck domains both domains will be switched
// to XTAL simultaneously (timing & monitoring)
#if (SUPC_HAS_MONITORING_DOMAIN==1)  
  #define SUPC_CR_XTALSEL  (SUPC_CR_MDXTALSEL|SUPC_CR_TDXTALSEL)
  #define SUPC_SR_OSCSEL    SUPC_SR_TDOSCSEL
#endif

extern uint32_t pmc_init(void);
extern void pmc_enable_pllack(uint32_t mula, uint32_t pllacount, uint32_t diva);
extern uint32_t pmc_is_locked_pllack(void);
extern void pmc_disable_pllack(void);
extern void pmc_pck_set_prescaler(uint32_t dw_id, uint32_t dw_pres);
extern void pmc_pck_set_source(uint32_t dw_id, uint32_t dw_source);
extern void pmc_mck_set_prescaler(uint32_t dw_pres);
extern void pmc_mck_set_source(uint32_t dw_source);
extern void pmc_switch_sclk_to_32kxtal(uint32_t dw_bypass);
extern uint32_t pmc_osc_is_ready_32kxtal(void);

extern void pmc_switch_mainck_to_fastrc(uint32_t dw_moscrcf);

extern void pmc_osc_enable_fastrc(uint32_t dw_rc);
extern void pmc_osc_disable_fastrc(void);
extern uint32_t pmc_osc_is_ready_fastrc(void);
extern void pmc_switch_mainck_to_xtal(uint32_t dw_bypass);
extern void pmc_osc_disable_xtal(uint32_t dw_bypass);
extern uint32_t pmc_osc_is_ready_xtal(void);
extern uint32_t pmc_switch_mck_to_sclk(uint32_t dw_pres);
extern uint32_t pmc_switch_mck_to_mainck(uint32_t dw_pres);
extern uint32_t pmc_switch_mck_to_pllack(uint32_t dw_pres);
extern uint32_t pmc_enable_periph_clk(uint32_t dw_id);
extern uint32_t pmc_disable_periph_clk(uint32_t dw_id);
extern void pmc_enable_all_periph_clk(void);
extern void pmc_disable_all_periph_clk(void);
extern uint32_t pmc_is_periph_clk_enabled(uint32_t dw_id);
extern uint32_t pmc_switch_pck_to_mainck(uint32_t dw_id, uint32_t dw_pres);
extern uint32_t pmc_switch_pck_to_pllack(uint32_t dw_id, uint32_t dw_pres);
extern void pmc_enable_pck(uint32_t dw_id);
extern void pmc_disable_pck(uint32_t dw_id);
extern void pmc_enable_all_pck(void);
extern void pmc_disable_all_pck(void);
extern uint32_t pmc_is_pck_enabled(uint32_t dw_id);

#ifndef SAM9X6 //MNn SAM9X6
extern uint32_t pmc_switch_pck_to_sclk(uint32_t dw_id, uint32_t dw_pres);
#endif //MNn SAM9X6

#ifdef SAM9X6 //MNn SAM9X6
extern uint32_t pmc_switch_pck_to_md_sclk(uint32_t dw_id, uint32_t dw_pres); 
extern uint32_t pmc_switch_pck_to_td_sclk(uint32_t dw_id, uint32_t dw_pres); 
#endif //MNn SAM9X6

#ifndef SAMA5 //ERr SAMA5
#ifndef SAM4N //ERr SAM4N
extern void pmc_set_fast_startup_input(uint32_t dw_inputs);
extern void pmc_enable_sleepmode(uint8_t uc_type);
extern void pmc_enable_waitmode(void);
extern void pmc_enable_backupmode(void);
#endif //ERr SAM4N
#endif //ERr SAMA5

extern void pmc_enable_interrupt(uint32_t dw_sources);
extern void pmc_disable_interrupt(uint32_t dw_sources);
extern uint32_t pmc_get_interrupt_mask(void);
extern uint32_t pmc_get_status(void);
extern void pmc_set_writeprotect(uint32_t dw_enable);
extern uint32_t pmc_get_writeprotect_status(void);

#if (SIRIUS ||SAM3S || SAM4S) //ERr SAM4S
extern void pmc_enable_pllbck(uint32_t mulb, uint32_t pllbcount, uint32_t divb);
extern uint32_t pmc_is_locked_pllbck(void);
extern void pmc_disable_pllbck(void);
extern uint32_t pmc_switch_mck_to_pllbck(uint32_t dw_pres);
extern uint32_t pmc_switch_pck_to_pllbck(uint32_t dw_id, uint32_t dw_pres);
extern void pmc_switch_udpck_to_pllbck(uint32_t dw_usbdiv);
#endif

#if (SAM3S || SAM3XA)
extern void pmc_switch_udpck_to_pllack(uint32_t dw_usbdiv);
extern void pmc_enable_udpck(void);
extern void pmc_disable_udpck(void);
#endif

#if (SAM3XA || SAM3U)
extern void pmc_enable_upll_clock(void);
extern void pmc_disable_upll_clock(void);
#endif


#ifndef SAM4N //ERr
#endif


/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* PMC_H_INCLUDED */
