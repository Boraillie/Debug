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

#include "v_pmc.h"


// ERr : already defined in ASF drivers/pmc.c
#define MASK_STATUS0	0xFFFFFFFC
#define MASK_STATUS1	0xFFFFFFFF

#define PMC_TIMEOUT		2048



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
uint32_t v_pmc_switch_mck_to_mainck(uint32_t dw_pres,uint32_t dw_mdiv)
{
 uint32_t dw_timeout;
 uint32_t pres_mdiv;

#if (SAM9X6)
 PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_CSS_Msk) | PMC_CPU_CKR_CSS_MAIN_CLK;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }

  pres_mdiv = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_PRES_Msk) | dw_pres;
#if(PMC_HAS_MCKR_FIELD_MDIV==1)
   pres_mdiv = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_MDIV_Msk) | dw_mdiv;
#endif
  
  PMC->PMC_CPU_CKR = pres_mdiv;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }
#else 
 PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }

  pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
#if(PMC_HAS_MCKR_FIELD_MDIV==1)
   pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_MDIV_Msk) | dw_mdiv;
#endif
  
  PMC->PMC_MCKR = pres_mdiv;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }
#endif // MNn SAM9X6
  return 0;
}


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
uint32_t v_pmc_switch_mck_to_pllack(uint32_t dw_pres,uint32_t dw_mdiv,uint8_t plldiv2)
{
 uint32_t dw_timeout;
 uint32_t pres_mdiv;

#if SAM9X6
        pres_mdiv = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_PRES_Msk) | dw_pres;
      #if(PMC_HAS_MCKR_FIELD_MDIV==1)
        pres_mdiv = (pres_mdiv & (uint32_t) ~ PMC_CPU_CKR_MDIV_Msk) | dw_mdiv;
      #endif

        #if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || SAMG55 || LIMES) //ERr
        if(plldiv2)
          {pres_mdiv = pres_mdiv | PMC_MCKR_PLLADIV2;}
        else
          {pres_mdiv = pres_mdiv & ~PMC_MCKR_PLLADIV2;}
      #else //ERr??

      #endif
        
        PMC->PMC_CPU_CKR = pres_mdiv;
        for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
          if (dw_timeout == 0){return 1;}
          }

      #if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || SAMG55 ||LIMES||CANOPUS || CAPELLA ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2  AYi SAM4C
        PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLLA_CLK;
      #else
        PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_CSS_Msk) | PMC_CPU_CKR_CSS_PLLACK;
      #endif
        for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
          if (dw_timeout == 0){return 1;}
          }
#else
              pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
          #if(PMC_HAS_MCKR_FIELD_MDIV==1)
            pres_mdiv = (pres_mdiv & (uint32_t) ~ PMC_MCKR_MDIV_Msk) | dw_mdiv;
          #endif

          //#if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || SAMG55 || LIMES||CANOPUS) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C
            #if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || SAMG55 || LIMES) //ERr
            if(plldiv2)
              {pres_mdiv = pres_mdiv | PMC_MCKR_PLLADIV2;}
            else
              {pres_mdiv = pres_mdiv & ~PMC_MCKR_PLLADIV2;}
          #else //ERr??
            /*
            if(plldiv2)
              {pres_mdiv = pres_mdiv | PMC_MCKR_PLLDIV2;}
            else
              {pres_mdiv = pres_mdiv & ~PMC_MCKR_PLLDIV2;}
            */
          #endif
            
            PMC->PMC_MCKR = pres_mdiv;
            for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
              if (dw_timeout == 0){return 1;}
              }

          #if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || SAMG55 ||LIMES||CANOPUS || CAPELLA ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2  AYi SAM4C
            PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLLA_CLK;
          #else
            PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLL_CLK;
          #endif
            for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
              if (dw_timeout == 0){return 1;}
              }
#endif // MNn SAM9X6
  
  
  
  return 0;
}



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
extern uint32_t pmc_switch_pck_to_mck( uint32_t dwId, uint32_t dwPres )
{
	uint32_t timeout;
	
	if ( dwPres > 6 )
		return 2;
#if SAM9X6	
    PMC->PMC_PCK[dwId] = PMC_PCK_CSS_MCK | dwPres << PMC_PCK_PRES_Pos ;
    for ( timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dwId)); --timeout )
		if (timeout == 0)
			return 1;
#else
    PMC->PMC_PCK[dwId] = PMC_PCK_CSS_MCK | dwPres << 4 ;
    for ( timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dwId)); --timeout )
		if (timeout == 0)
			return 1;
    
#endif // MNn SAM9X6
	return 0;
}

/**
 * \brief Switch programmable clock source selection to plla clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 * \param dw_pres Programmable clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t v_pmc_switch_pck_to_pllack(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;
#if SAM9X6
	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_PLLA | dw_pres << PMC_PCK_PRES_Pos;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
#else
	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_PLLA_CLK | dw_pres << PMC_PCK_PRES_Pos;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
#endif // MNn SAM9X6
	return 0;
}


/**
 * \brief Enable all peripheral clocks.
 */
// Corrected ASF function / ERr
extern void v_pmc_enable_all_periph_clk(void)
{
#if (SAM3N || SAM3U)
	PMC->PMC_PCER = MASK_STATUS0;
	//while ((PMC->PMC_PCSR & MASK_STATUS0) != MASK_STATUS0);
#elif (SAM4N || SAM4SH1 || SAMG53 || SAMG55)
	PMC->PMC_PCER0 = MASK_STATUS0;
	//while ((PMC->PMC_PCSR & MASK_STATUS0) != MASK_STATUS0);
#elif !defined(PMC_HAS_PCR_NO_MORE_PCxR) || (PMC_HAS_PCR_NO_MORE_PCxR==0)
	PMC->PMC_PCER0 = MASK_STATUS0;
	//while ((PMC->PMC_PCSR0 & MASK_STATUS0) != MASK_STATUS0);

	PMC->PMC_PCER1 = MASK_STATUS1;
	//while ((PMC->PMC_PCSR1 & MASK_STATUS1) != MASK_STATUS1);
#else
     uint32_t pid, mask;
     for (mask=MASK_STATUS0, pid=0; pid < 32; ++pid, mask>>=1)
       if (mask & 0x1)
       {
         PMC->PMC_PCR = PMC_PCR_PID(pid); // map the Peripheral pid to PMC_PCR register for next Read operation
         PMC->PMC_PCR = (PMC->PMC_PCR & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | PMC_PCR_PID(pid) | PMC_PCR_EN;
       }
     for (mask=MASK_STATUS1, pid=32; pid < 64; ++pid, mask>>=1)
       if (mask & 0x1)
       {
         PMC->PMC_PCR = PMC_PCR_PID(pid); // map the Peripheral pid to PMC_PCR register for next Read operation
         PMC->PMC_PCR = (PMC->PMC_PCR & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | PMC_PCR_PID(pid) | PMC_PCR_EN;
       }
#endif
}



/**
 * \brief Switch slow clock source selection to external 32k (Xtal or Bypass).
 * This function disables the PLLs.
 *
 * Note: Switching back sclk to 32krc is only possible by shutting down the VDDIO power supply.
 *
 * \param dw_bypass 0 for Xtal, 1 for bypass.
 * 
 */
// ASF function updated for SAMA5 / ERr
#ifndef SAM9X6
void v_pmc_switch_sclk_to_32kxtal(uint32_t dw_bypass)
{
#if (SAMA5==1)
  #if (SLOW_OSC_HAS_NO_BYPASS !=1)
    if (dw_bypass == 1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32BYP;}
    else
  #endif
  #if (SLOW_OSC_ALWAYS_ON !=1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32EN;}
  #else
      {}
  #endif
  SCKC->SCKC_CR = (SCKC->SCKC_CR & ~SCKC_CR_OSCSEL)|SCKC_CR_OSCSEL_XTAL;
#else //#elif (SAM3S==1 || SAM3U==1 || SAM3N==1 || SAM3X==1 || SAM4S==1||SIRIUS )
  if (dw_bypass == 1) SUPC->SUPC_MR |= SUPC_MR_KEY((uint32_t) 0xA5) | SUPC_MR_OSCBYPASS;
  SUPC->SUPC_CR |= SUPC_CR_KEY((uint32_t) 0xA5) | SUPC_CR_XTALSEL;
#endif
}
#endif // SAM9X6

/////* -------- SCKC_CR : (SCKC Offset: 0x0) Slow Clock Controller Configuration Register -------- */
////#define SCKC_CR_RCEN (0x1u << 0) /**< \brief (SCKC_CR) Embedded 32 kHz (typical) RC Oscillator */
////#define SCKC_CR_OSC32EN (0x1u << 1) /**< \brief (SCKC_CR) 32.768 kHz Crystal Oscillator */
////#define SCKC_CR_OSC32BYP (0x1u << 2) /**< \brief (SCKC_CR) 32.768 kHz Crystal Oscillator Bypass */
////#define SCKC_CR_OSCSEL (0x1u << 3) /**< \brief (SCKC_CR) Slow Clock Selector */
////#define   SCKC_CR_OSCSEL_RC (0x0u << 3) /**< \brief (SCKC_CR) Slow clock is the embedded 32 kHz (typical) RC oscillator. */
////#define   SCKC_CR_OSCSEL_XTAL (0x1u << 3) /**< \brief (SCKC_CR) Slow clock is the 32.768 kHz crystal oscillator. */

#if SAM9X6
void v_pmc_switch_td_sclk_to_32kxtal(uint32_t dw_bypass)
{
    if (dw_bypass == 1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32BYP;}
    else
      {SCKC->SCKC_CR |= SCKC_CR_OSC32EN;}
  SCKC->SCKC_CR = (SCKC->SCKC_CR & ~SCKC_CR_OSCSEL)|SCKC_CR_OSCSEL_XTAL;

}
#endif // SAM9X6





#if (SUPC_HAS_MONITORING_DOMAIN==1)

// Added for 65108: switches 32K timing domain only to XTAL
void v_pmc_switch_tdsclk_to_32kxtal(uint32_t dw_bypass)
{
#if (SAMA5==1)
  /*
  #if (SLOW_OSC_HAS_NO_BYPASS !=1)
    if (dw_bypass == 1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32BYP;}
    else
  #endif
  #if (SLOW_OSC_ALWAYS_ON !=1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32EN;}
  #else
      {}
  #endif
  SCKC->SCKC_CR = (SCKC->SCKC_CR & ~SCKC_CR_OSCSEL)|SCKC_CR_OSCSEL_XTAL;
  */
  #error Not implemented: multiple slow clock domains on SAMA5 products!
#else
  if (dw_bypass == 1) SUPC->SUPC_MR |= SUPC_MR_KEY((uint32_t) 0xA5) | SUPC_MR_OSCBYPASS;
  SUPC->SUPC_CR |= SUPC_CR_KEY((uint32_t) 0xA5) | SUPC_CR_TDXTALSEL;
#endif
}

// Added for 65108: switches 32K monitoring domain only to XTAL
void v_pmc_switch_mdsclk_to_32kxtal(uint32_t dw_bypass)
{
#if (SAMA5==1)
  #error Not implemented: multiple slow clock domains on SAMA5 products!
#else
  if (dw_bypass == 1) SUPC->SUPC_MR |= SUPC_MR_KEY((uint32_t) 0xA5) | SUPC_MR_OSCBYPASS;
  SUPC->SUPC_CR |= SUPC_CR_KEY((uint32_t) 0xA5) | SUPC_CR_MDXTALSEL;
#endif
}

// Added for 65108: switches back 32K monitoring domain only to RC osc
void v_pmc_switch_mdsclk_to_32krc(void)
{
#if (SAMA5==1)
  #error Not implemented: multiple slow clock domains on SAMA5 products!
#else
  SUPC->SUPC_CR |= SUPC_CR_KEY((uint32_t) 0xA5) | SUPC_CR_MDRCSEL;
#endif
}

#endif




#if DEVICE_HAS_PLLB
void v_pmc_enable_pllbck(uint32_t mulb, uint32_t pllbcount, uint32_t divb)
{
	//pmc_disable_pllbck();	// Hardware BUG FIX : first disable the PLL to unlock the lock! 
	// It occurs when re-enabling the PLL with the same parameters.
	PMC->CKGR_PLLBR =
			CKGR_PLLBR_DIVB(divb) | CKGR_PLLBR_PLLBCOUNT(pllbcount)
			| CKGR_PLLBR_MULB(mulb);
	while ((PMC->PMC_SR & PMC_SR_LOCKB) == 0);
}

uint32_t v_pmc_switch_mck_to_pllbck(uint32_t dw_pres,uint32_t dw_mdiv,uint8_t plldiv2)
{
  uint32_t dw_timeout;
  uint32_t pres_mdiv;


  pres_mdiv = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
#if(PMC_HAS_MCKR_FIELD_MDIV==1)
  pres_mdiv = (pres_mdiv & (uint32_t) ~ PMC_MCKR_MDIV_Msk) | dw_mdiv;
#endif

#if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C
  if(plldiv2)
    {pres_mdiv = pres_mdiv | PMC_MCKR_PLLADIV2;}
  else
    {pres_mdiv = (pres_mdiv & (~PMC_MCKR_PLLADIV2));}
#else //ERr??
  if(plldiv2)
    {pres_mdiv = pres_mdiv | PMC_MCKR_PLLDIV2;}
  else
    {pres_mdiv = pres_mdiv & ~PMC_MCKR_PLLDIV2;}
#endif
  
  PMC->PMC_MCKR = pres_mdiv;
  for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);--dw_timeout){
    if (dw_timeout == 0){return 1;}
    }

	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) |
			PMC_MCKR_CSS_PLLB_CLK;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

	return 0;
}
#endif


/*
void  pmc_set_gclk(unsigned int periph_id , int gclkchoice)
{
       uint32_t pcr_value;
       PMC->PMC_PCR = PMC_PCR_PID(periph_id); // map the Peripheral gclk to PMC_PCR register 
       pcr_value = PMC->PMC_PCR;          // to retrieve info related to the Peripheral Clock of interest
       PMC->PMC_PCR = (pcr_value & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | gclkchoice | PMC_PCR_PID(periph_id) | PMC_PCR_EN | PMC_PCR_GCLKEN;
       return;
}
*/