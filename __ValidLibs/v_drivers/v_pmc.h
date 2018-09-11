// $asf_license$

/*! \file *********************************************************************
 *
 * \brief PMC driver for SAM3.
 *
 * Power Management Controller (PMC) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 ******************************************************************************/

#ifndef _V_PMC_H
#define _V_PMC_H

#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"


// Validation patch: in case of two slck domains each domain can be switched
// to XTAL independantly (timing & monitoring)
#if (SUPC_HAS_MONITORING_DOMAIN==1)  
  #define SUPC_CR_XTALSEL  (SUPC_CR_MDXTALSEL|SUPC_CR_TDXTALSEL)
  #define SUPC_SR_OSCSEL    SUPC_SR_TDOSCSEL
   void v_pmc_switch_tdsclk_to_32kxtal(uint32_t dw_bypass);
   void v_pmc_switch_mdsclk_to_32kxtal(uint32_t dw_bypass);
   void v_pmc_switch_mdsclk_to_32krc(void);
#endif


/**
 * \brief Switch master clock source selection to main clock.
 *
 * \param dw_pres Processor clock prescaler.
 * \param dw_mdiv system clock divider.
 * \param plldiv2 PLL output divider (0 or 1).
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
//ERr: added MDIV & PLLDIV2 fields management
uint32_t v_pmc_switch_mck_to_mainck(uint32_t dw_pres,uint32_t dw_mdiv);



/**
 * \brief Switch master clock source selection to plla clock.
 *
 * \param dw_pres Processor clock prescaler.
 * \param dw_mdiv system clock divider.
 * \param plldiv2 PLL output divider (0 or 1).
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
//ERr: added MDIV & PLLDIV2 fields management
uint32_t v_pmc_switch_mck_to_pllack(uint32_t dw_pres,uint32_t dw_mdiv,uint8_t plldiv2);



/**
 * \brief Switch programmable clock source selection to master clock.
 *
 * \param dwId Id (number) of the programmable clock.
 * \param dwPres Programmable clock prescaler. The dwPres argument must not be shifted.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 * \retval 2 Invalid prescaler selection.
 */
extern uint32_t pmc_switch_pck_to_mck( uint32_t dwId, uint32_t dwPres ) ;

/**
 * \brief Switch programmable clock source selection to plla clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 * \param dw_pres Programmable clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
extern uint32_t v_pmc_switch_pck_to_pllack(uint32_t dw_id, uint32_t dw_pres);


/**
 * \brief Switch programmable clock source selection to plla clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 * \param dw_pres Programmable clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t v_pmc_switch_pck_to_pllack(uint32_t dw_id, uint32_t dw_pres);



/**
 * \brief Enable all peripheral clocks.
 */
// Corrected ASF finction / ERr
extern void v_pmc_enable_all_periph_clk(void);


/**
 * \brief Enable all peripheral clocks.
 */
// Corrected ASF function / ERr
void v_pmc_switch_sclk_to_32kxtal(uint32_t dw_bypass);
void v_pmc_switch_td_sclk_to_32kxtal(uint32_t dw_bypass);

#if DEVICE_HAS_PLLB
void v_pmc_enable_pllbck(uint32_t mulb, uint32_t pllbcount, uint32_t divb);
uint32_t v_pmc_switch_mck_to_pllbck(uint32_t dw_pres,uint32_t dw_mdiv,uint8_t plldiv2);
#endif


//void  pmc_set_gclk(unsigned int periph_id , int gclkchoice);
#endif // _V_PMC_H

