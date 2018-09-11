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



#include "pmc.h"
/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define MASK_STATUS0    0xFFFFFFFC	/* Bit mask for periphal clocks (PCER0) */
#define MASK_STATUS1    0xFFFFFFFF	/* Bit mask for periphal clocks (PCER1) */

#define PMC_TIMEOUT		2048		/* Loop counter timeout value */

#ifdef CKGR_MOR_KEY_PASSWD
  #define CKGR_MOR_KEY_VALUE	CKGR_MOR_KEY_PASSWD /* Key to unlock CKGR_MOR register */
#else
  #define CKGR_MOR_KEY_VALUE	CKGR_MOR_KEY(0x37) /* Key to unlock CKGR_MOR register */
#endif

#ifdef PMC_WPMR_WPKEY_PASSWD
  #define PMC_WPMR_WPKEY_VALUE	PMC_WPMR_WPKEY_PASSWD /* Key to unlock CKGR_MOR register */
#else
  #define PMC_WPMR_WPKEY_VALUE PMC_WPMR_WPKEY((uint32_t) 0x504D43)
#endif



  
/**
 * \brief Initialize PMC with default settings.
 *
 * \return 0 for OK.
 */
uint32_t pmc_init(void)
{
	return 0;
}

/**
 * \brief Enable plla clock.
 *
 * \param mula Plla multiplier.
 * \param pllacount Plla counter.
 * \param diva Divider.
 */
void pmc_enable_pllack(uint32_t mula, uint32_t pllacount, uint32_t diva)
{
	pmc_disable_pllack();	// Hardware BUG FIX : first disable the PLL to unlock the lock! 
	// It occurs when re-enabling the PLL with the same parameters.
/*
#if (SAM4C || SAM4SH1) 
#warning : default clock source of PLLA is the slow clock 
#define CKGR_PLLAR_ONE 0 //TODO : This parameter is used for plla src clk => pmc_enable_pllack fn to redefine
#endif
*/
#ifndef CKGR_PLLAR_ONE // SAM4SH1 SAM4C
  #define CKGR_PLLAR_ONE (0) //TODO : This parameter is used for plla src clk => pmc_enable_pllack fn to redefine
#endif
#if (SAMG53 || SAMG55) //ERr SAMG53 => SAMG51?
       PMC->CKGR_PLLAR =
			CKGR_PLLAR_PLLAEN(1) | 
			CKGR_PLLAR_PLLACOUNT(pllacount) | CKGR_PLLAR_MULA(mula);
	while ((PMC->PMC_SR & PMC_SR_LOCKA) == 0);
#elif (SIRIUS ||SAM3XA || SAM3S  || SAM3S8  || SAM4S || SAM3U || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1  || SAMG53 || LIMES || CANOPUS || CAPELLA  ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C
        PMC->CKGR_PLLAR =
			CKGR_PLLAR_ONE | CKGR_PLLAR_DIVA(diva) | 
			CKGR_PLLAR_PLLACOUNT(pllacount) | CKGR_PLLAR_MULA(mula);
	while ((PMC->PMC_SR & PMC_SR_LOCKA) == 0);
#elif ( SAM9X6 ) //MNn dev for SAM9X6
        //enable pll lock interrupt for pll0 
 /* -------- PMC_PLL_IER : (PMC Offset: 0x00E0) PLL Interrupt Enable Register -------- */
        PMC->PMC_PLL_IER = PMC_PLL_IER_LOCK0;
        // configure pll0 (PllA)
        PMC->PMC_PLL_CTRL0 = PMC_PLL_CTRL0_ENPLL | PMC_PLL_CTRL0_DIVPMC(diva) |PMC_PLL_CTRL0_ENPLLCK | PMC_PLL_CTRL0_ENLOCK;
        PMC->PMC_PLL_CTRL1 = PMC_PLL_CTRL1_MUL(mula);        
        PMC->PMC_PLL_UPDT = PMC_PLL_UPDT_UPDATE |PMC_PLL_UPDT_ID(0x0); // pll_ID was replaced by 0 for PllA (system Pll)
        //start polling on PMC_PLL_ISR0 
 	while ((PMC->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCK0) == 0);
 	//while ((PMC->PMC_SR & PMC_SR_LOCKA) == 0); // commented out since this was for 
#else
	PMC->CKGR_PLLR = CKGR_PLLR_STUCKTO1 | CKGR_PLLR_DIV(diva) |
			CKGR_PLLR_PLLCOUNT(pllacount) | CKGR_PLLR_MUL(mula);
	while ((PMC->PMC_SR & PMC_SR_LOCK) == 0);
#endif
}

/**
 * \brief Is plla clocked?.
 *
 * \retval 0 Not locked.
 * \retval 1 Locked.
 */
uint32_t pmc_is_locked_pllack(void)
{
#if (SAM3N)
	return (PMC->PMC_SR & PMC_SR_LOCK);
#elif ( SAM9X6 )
        return (PMC->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCK0);
#else
	return (PMC->PMC_SR & PMC_SR_LOCKA);
#endif
}

/**
 * \brief Disable plla clock.
 */
void pmc_disable_pllack(void)
{
#if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C ||SAM4SH1 || SAMG53 || LIMES || SAMG55 || CANOPUS || CAPELLA) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C
	PMC->CKGR_PLLAR = CKGR_PLLAR_MULA(0);
#elif ( SAM9X6 )
        PMC->PMC_PLL_CTRL0 = (PMC->PMC_PLL_CTRL0 & (uint32_t) ~ PMC_PLL_CTRL0_ENPLL);
        PMC->PMC_PLL_UPDT = PMC_PLL_UPDT_UPDATE |PMC_PLL_UPDT_ID(0x0); // pll_ID was replaced by 0 for PllA (system Pll)
#else
	PMC->CKGR_PLLR = CKGR_PLLR_MUL(0);

#endif
}

/**
 * \brief Set prescaler of the peripheral clock.
 * \param dw_id Peripheral ID.
 * \param dw_pres Prescaler value.
 */
void pmc_pck_set_prescaler(uint32_t dw_id, uint32_t dw_pres)
{
	PMC->PMC_PCK[dw_id] =
			(PMC->PMC_PCK[dw_id] & ~PMC_PCK_PRES_Msk) | dw_pres;
	while ((PMC->PMC_SCER & (PMC_SCER_PCK0 << dw_id))
			&& !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id)));
}

/**
 * \brief Set the source of the peripheral clock.
 * \param dw_id Peripheral ID.
 * \param dw_source Source selection value.
 */
void pmc_pck_set_source(uint32_t dw_id, uint32_t dw_source)
{
	PMC->PMC_PCK[dw_id] =
			(PMC->PMC_PCK[dw_id] & ~PMC_PCK_CSS_Msk) | dw_source;
	while ((PMC->PMC_SCER & (PMC_SCER_PCK0 << dw_id))
			&& !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id)));
}

/**
 * \brief Set the prescaler of the MCK. 
 * \param dw_pres Prescaler value.
 */
void pmc_mck_set_prescaler(uint32_t dw_pres)
{
#if ( SAM9X6 ) 
	PMC->PMC_CPU_CKR = 
			(PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_PRES_Msk) | dw_pres;
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY));
#else
	PMC->PMC_MCKR = 
			(PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY));
#endif
}

/**
 * \brief Set the source of the MCK.
 * \param dw_source Source selection value.
 */
void pmc_mck_set_source(uint32_t dw_source)
{
 #if ( SAM9X6 ) 
	PMC->PMC_CPU_CKR = 
			(PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_CSS_Msk) | dw_source;
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY));
#else       
        PMC->PMC_MCKR = 
			(PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) | dw_source;
	while (!(PMC->PMC_SR & PMC_SR_MCKRDY));
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
void pmc_switch_sclk_to_32kxtal(uint32_t dw_bypass)
{
#if (SAMA5==1) //ERr SAMA5
  #if (ISLERO == 1 )      
   REG_SCKC_CR = SCKC_CR_OSCSEL_XTAL;  // select external 32 KHz Osc   
   //   while( !(REG_PMC_SR & PMC_SR_OSCSELS) );// bug : the status doesn't change
   while( (REG_SCKC_CR & SCKC_CR_OSCSEL_XTAL) == 0 );    //AYi
  #else
    #warning pmc_switch_sclk_to_32kxtal must be updated for SAMA5
    #if (SLOW_OSC_HAS_NO_BYPASS !=1)
    if (dw_bypass == 1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32BYP;}
    else
    #endif
    #if (SLOW_OSC_ALWAYS_ON !=1)
      {SCKC->SCKC_CR |= SCKC_CR_OSC32EN;}//
    #else
      {}
    #endif
    
    SCKC->SCKC_CR |= SCKC_CR_OSCSEL_XTAL;
  #endif
  //wait resynchro
    
#elif ( SAM9X6 ==1 ) 
    if (dw_bypass == 1)
	SCKC->SCKC_CR = (SCKC_CR_OSCSEL | SCKC_CR_OSC32BYP);
    else
        SCKC->SCKC_CR = (SCKC_CR_OSCSEL | SCKC_CR_OSC32EN);
     
#else //#elif (SAM3S==1 || SAM3U==1 || SAM3N==1 || SAM3X==1 || SAM4S==1) //ERr SAMA5
	/* Set Bypass mode if required */
	if (dw_bypass == 1)
		SUPC->SUPC_MR |= SUPC_MR_KEY((uint32_t) 0xA5) |
				SUPC_MR_OSCBYPASS;

	SUPC->SUPC_CR |= SUPC_CR_KEY((uint32_t) 0xA5) | SUPC_CR_XTALSEL;
#endif //ERr SAMA5
}

/**
 * \brief Check if the external 32k Xtal is ready.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */

#ifndef SAM9X6 // MNn
#ifndef SAMA5 //ERr SAMA5
uint32_t pmc_osc_is_ready_32kxtal(void)
{
	if (!(SUPC->SUPC_SR & SUPC_SR_OSCSEL)
			&& !(PMC->PMC_SR & PMC_SR_OSCSELS))
		return 1;
	else
		return 0;
}
#endif //ERr SAMA5
#else //SAM9X6 defined
  #warning 'MNn : not sure that the slow clock xtal status is available on SAM9X6'
#endif //SAM9X6 // MNn

/**
 * \brief Switch main clock source selection to internal fast RC.
 *
 * \param dw_moscrcf 0 for 4Mhz, 1 for 8Mhz and 2 for 12Mhz.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 * \retval 2 Invalid frequency.
 */
#if (SAMA5 || SAM9X6) //ERr SAMA5
void pmc_switch_mainck_to_fastrc(uint32_t dw_moscrcf) // parameter not used
{
  PMC->CKGR_MOR = (PMC->CKGR_MOR|CKGR_MOR_KEY(MOR_KEY_VAL)|CKGR_MOR_MOSCRCEN);
  
  //Wait the Fast RC to stabilize
  while (!(PMC->PMC_SR & PMC_SR_MOSCRCS));

  //Switch to Fast RC
  PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL)|CKGR_MOR_KEY(MOR_KEY_VAL);
}
#else //ERr
void pmc_switch_mainck_to_fastrc(uint32_t dw_moscrcf)
{
	uint32_t dw_needXTEN = 0;

	dw_moscrcf = (dw_moscrcf << CKGR_MOR_MOSCRCF_Pos) &
			CKGR_MOR_MOSCRCF_Msk;
	/* Enable Fast RC oscillator but DO NOT switch to RC now */
	if (PMC->CKGR_MOR & CKGR_MOR_MOSCXTEN)
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCRCF_Msk) |
				CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCRCEN |
				dw_moscrcf;
	else {
		dw_needXTEN = 1;
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCRCF_Msk) |
				CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCRCEN |
				CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCXTST(0x1) |
				dw_moscrcf;
	}

	/* Wait the Fast RC to stabilize */
        while (!(PMC->PMC_SR & PMC_SR_MOSCRCS));

	/* Switch to Fast RC */
	PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL) | CKGR_MOR_KEY_VALUE;
	

        
	// BUG FIX : clock_example3_sam3s does not switch sclk->mainck with XT disabled.
	if (dw_needXTEN)
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTEN) |
				CKGR_MOR_KEY_VALUE;
}
#endif //SAMA5 SAM9X6


/**
 * \brief Enable fast RC oscillator.
 *
 * \param dw_rc fast RC oscillator(4/8/12Mhz).
 */
void pmc_osc_enable_fastrc(uint32_t dw_rc)
{
	/* Enable Fast RC oscillator but DO NOT switch to RC now . Keep MOSCSEL to 1 */
	PMC->CKGR_MOR = CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCSEL |
			CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCRCEN | dw_rc;
	/* Wait the Fast RC to stabilize */
	while (!(PMC->PMC_SR & PMC_SR_MOSCRCS));
}

/**
 * \brief Disable the internal fast RC.
 */
void pmc_osc_disable_fastrc(void)
{
	/* Disable Fast RC oscillator */
	PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCRCEN) | CKGR_MOR_KEY_VALUE;
}

/**
 * \brief Check if the external fast RC is ready.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_osc_is_ready_fastrc(void)
{
	/* Is the Fast RC selected? */
	if (PMC->PMC_SR & PMC_SR_MOSCSELS)
		return 1;
	else
		return 0;
}

/**
 * \brief Switch main clock source selection to external Xtal/Bypass.
 * The function may switches mck to sclk if mck source is mainck to avoid any system crash.
 *
 * \param dw_bypass 0 for Xtal, 1 for bypass.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
void pmc_switch_mainck_to_xtal(uint32_t dw_bypass)
{
	/* Enable Main Xtal oscillator */
  
#if (SAM9X6) //MNn
	if (dw_bypass)
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTEN) |
				CKGR_MOR_KEY_VALUE |CKGR_MOR_MOSCSEL;
	else {
		PMC->CKGR_MOR = (PMC->CKGR_MOR) | CKGR_MOR_KEY_VALUE | 
                                 CKGR_MOR_MOSCXTEN | CKGR_MOR_MOSCXTST(0x3F)|CKGR_MOR_MOSCSEL;
		/* Wait the Xtal to stabilize */
		while (!(PMC->PMC_SR & PMC_SR_MOSCXTS));

		PMC->CKGR_MOR |= CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCSEL;
	}
#else
        	if (dw_bypass)
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTEN) |
				CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCXTBY |
				CKGR_MOR_MOSCSEL;
	else {
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTBY) |
				CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCXTEN |
				CKGR_MOR_MOSCXTST(0x3F);
		/* Wait the Xtal to stabilize */
		while (!(PMC->PMC_SR & PMC_SR_MOSCXTS));

		PMC->CKGR_MOR |= CKGR_MOR_KEY_VALUE | CKGR_MOR_MOSCSEL;
}
#endif 
}

/**
 * \brief Disable the external Xtal.
 * \param dw_bypass 0 for Xtal, 1 for bypass.
 */
void pmc_osc_disable_xtal(uint32_t dw_bypass)
{  
#if (SAM9X6) //MNn
	/* Disable xtal oscillator */
  // MNn since theXTAL does not exist, only need to disable XTAL (~CKGR_MOR_MOSCXTEN)
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTEN) |
				CKGR_MOR_KEY_VALUE;
  
#else
	/* Disable xtal oscillator */
	if (dw_bypass)
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTBY) |
				CKGR_MOR_KEY_VALUE;
	else
		PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTEN) |
				CKGR_MOR_KEY_VALUE;
#endif // MNn SAM9X6
}

/**
 * \brief Check if the Xtal is ready.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_osc_is_ready_xtal(void)
{
	/* Is the xtal selected? */
	if (PMC->PMC_SR & PMC_SR_MOSCSELS)
		return 1;
	else
		return 0;
}

/**
 * \brief Switch master clock source selection to slow clock.
 * This function disables the PLLs.
 *
 * \param dw_pres Processor clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_switch_mck_to_sclk(uint32_t dw_pres)
{
	uint32_t dw_timeout;
#if (SAM9X6)
	PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_CSS_Msk) |
			PMC_CPU_CKR_CSS_SLOW_CLK;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

	PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_PRES_Msk) | 
			dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

#else

	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) |
			PMC_MCKR_CSS_SLOW_CLK;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | 
			dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;        
#endif // MNn SAM9X6        
	return 0;
}

/**
 * \brief Switch master clock source selection to main clock.
 *
 * \param dw_pres Processor clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
#if SAM9X6
uint32_t pmc_switch_mck_to_mainck(uint32_t dw_pres)
{
	uint32_t dw_timeout;
	PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_CSS_Msk) |
			PMC_CPU_CKR_CSS_MAIN_CLK;

	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

        
	PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_PRES_Msk) | dw_pres;

	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;       
	return 0;
}
#endif //MNn SAM9X6

#ifndef SAM9X6
uint32_t pmc_switch_mck_to_mainck(uint32_t dw_pres)
{
	uint32_t dw_timeout;
     
	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) |
			PMC_MCKR_CSS_MAIN_CLK;

	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

        
	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;

	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

	return 0;
}
#endif //MNn SAM9X6




/**
 * \brief Switch master clock source selection to plla clock.
 *
 * \param dw_pres Processor clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_switch_mck_to_pllack(uint32_t dw_pres)
{
	uint32_t dw_timeout;
#if (SAM9X6)        
 	PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_PRES_Msk) | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
	PMC->PMC_CPU_CKR = (PMC->PMC_CPU_CKR & (uint32_t) ~ PMC_CPU_CKR_CSS_Msk) |
			PMC_CPU_CKR_CSS_PLLACK;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
               
#else       
	PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_PRES_Msk) | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

        #if (SIRIUS ||SAM3XA || SAM3S || SAM3S8 || SAM3U || SAM4S || SAMA5 || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53 || LIMES || SAMG55 || CANOPUS || CAPELLA ) //ERr SAM4S SAM3S8 SAMA5 SAM4N CM4P2 AYi SAM4C
            PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) |
			PMC_MCKR_CSS_PLLA_CLK;
        #else
              PMC->PMC_MCKR = (PMC->PMC_MCKR & (uint32_t) ~ PMC_MCKR_CSS_Msk) |
			PMC_MCKR_CSS_PLL_CLK;
        #endif
                for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & PMC_SR_MCKRDY);
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
#endif  //SAM9X6 MNn
	return 0;
}

/**
 * \brief Enable the clock of a peripheral. The peripheral ID is used
 * to identify which peripheral is targetted.
 *
 * \note The ID must NOT be shifted (i.e. 1 << ID_xxx).
 *
 * \param dw_id Peripheral ID (ID_xxx).
 *
 * \retval 0 Success.
 * \retval 1 Invalid parameter.
 */
#pragma location = ".prg_used_drv_functions" //used by prg mode linker
__root uint32_t pmc_enable_periph_clk(uint32_t dw_id)
{
//	if (!(dw_id < 35))
//		return 1;
//ERr

#if (SAM3N || SAM3U)
	if ((PMC->PMC_PCSR & ((uint32_t) 1 << dw_id)) ==
			((uint32_t) 1 << dw_id)) {
		//TRACE_DEBUG( "PMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", dw_id ) ;
	} else {
		PMC->PMC_PCER = 1 << dw_id;
	}
#elif (SAM4N || SAM4SH1 || SAMG53 || SAMG55) //ERr
	if ((PMC->PMC_PCSR0 & ((uint32_t) 1 << dw_id)) ==
			((uint32_t) 1 << dw_id)) {
		//TRACE_DEBUG( "PMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", dw_id ) ;
	} else {
		PMC->PMC_PCER0 = 1 << dw_id;
	}
#elif !defined(PMC_HAS_PCR_NO_MORE_PCxR) || (PMC_HAS_PCR_NO_MORE_PCxR==0)
	if (dw_id < 32) {
		if ((PMC->PMC_PCSR0 & ((uint32_t) 1 << dw_id)) ==
				((uint32_t) 1 << dw_id)) {
			//TRACE_DEBUG( "PMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", dw_id ) ;
		} else {
			PMC->PMC_PCER0 = 1 << dw_id;
		}
	} else {
		dw_id -= 32;
		if ((PMC->PMC_PCSR1 & ((uint32_t) 1 << dw_id)) ==
				((uint32_t) 1 << dw_id)) {
			//TRACE_DEBUG( "PMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", dw_id + 32 ) ;
		} else {
			PMC->PMC_PCER1 = 1 << dw_id;
		}
	}
#else
        uint32_t pcr_value;
        PMC->PMC_PCR = PMC_PCR_PID(dw_id); // map the Peripheral dw_id to PMC_PCR register for next Read operation
        pcr_value = PMC->PMC_PCR;          // to retrieve info related to the Peripheral Clock of interest
        if ((pcr_value & PMC_PCR_EN) != 0x0)
        {
          //TRACE_DEBUG( "PMC_EnablePeripheral: clock of peripheral"  " %u is already enabled\n\r", dw_id);
        }
        else
          PMC->PMC_PCR = (pcr_value & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | PMC_PCR_PID(dw_id) | PMC_PCR_EN;
#endif
	return 0;
}

/**
 * \brief Disable the clock of a peripheral. The peripheral ID is used
 * to identify which peripheral is targetted.
 *
 * \note The ID must NOT be shifted (i.e. 1 << ID_xxx).
 *
 * \param dw_id Peripheral ID (ID_xxx).
 *
 * \retval 0 Success.
 * \retval 1 Invalid parameter.
 */
uint32_t pmc_disable_periph_clk(uint32_t dw_id)
{
	if (!(dw_id < 35))
		return 1;

        
#if (SAM3N || SAM3U)
	if ((PMC->PMC_PCSR & ((uint32_t) 1 << dw_id)) !=
			((uint32_t) 1 << dw_id)) {
		//TRACE_DEBUG("PMC_DisablePeripheral: clock of peripheral" " %u is not enabled\n\r", dw_id ) ;
	} else {
		PMC->PMC_PCDR = 1 << dw_id;
	}
#elif (SAM4N || SAM4SH1 || SAMG53 || SAMG55) //ERr
	if ((PMC->PMC_PCSR0 & ((uint32_t) 1 << dw_id)) !=
			((uint32_t) 1 << dw_id)) {
		//TRACE_DEBUG("PMC_DisablePeripheral: clock of peripheral" " %u is not enabled\n\r", dw_id ) ;
	} else {
		PMC->PMC_PCDR0 = 1 << dw_id;
	}
#elif !defined(PMC_HAS_PCR_NO_MORE_PCxR) || (PMC_HAS_PCR_NO_MORE_PCxR==0)
	if (dw_id < 32) {
		if ((PMC->PMC_PCSR0 & ((uint32_t) 1 << dw_id)) !=
				((uint32_t) 1 << dw_id)) {
			//TRACE_DEBUG("PMC_DisablePeripheral: clock of peripheral" " %u is not enabled\n\r", dw_id ) ;
		} else {
			PMC->PMC_PCDR0 = 1 << dw_id;
		}
	} else {
		dw_id -= 32;
		if ((PMC->PMC_PCSR1 & ((uint32_t) 1 << dw_id)) !=
				((uint32_t) 1 << dw_id)) {
			//TRACE_DEBUG( "PMC_DisablePeripheral: clock of peripheral" " %u is not enabled\n\r", dw_id + 32 ) ;
		} else {
			PMC->PMC_PCDR1 = 1 << dw_id;
		}
	}
#else
        uint32_t pcr_value;
        PMC->PMC_PCR = PMC_PCR_PID(dw_id); // map the Peripheral dw_id to PMC_PCR register for next Read operation
        pcr_value = PMC->PMC_PCR;          // to retrieve info related to the Peripheral Clock of interest
        if ((pcr_value & PMC_PCR_EN) == 0x0)
        {
          //TRACE_DEBUG( "PMC_EnablePeripheral: clock of peripheral"  " %u is already disabled\n\r", dw_id);
        }
        else
          PMC->PMC_PCR = (pcr_value & ~(PMC_PCR_PID_Msk | PMC_PCR_EN)) | PMC_PCR_CMD | PMC_PCR_PID(dw_id);
#endif
	return 0;
}

/**
 * \brief Enable all peripheral clocks.
 */
void pmc_enable_all_periph_clk(void)
{
#if (SAM3N || SAM3U)
	PMC->PMC_PCER = MASK_STATUS0;
	while ((PMC->PMC_PCSR & MASK_STATUS0) != MASK_STATUS0);
#elif (SAM4N || SAM4SH1 || SAMG53 || SAMG55) //ERr
	PMC->PMC_PCER0 = MASK_STATUS0;
	while ((PMC->PMC_PCSR0 & MASK_STATUS0) != MASK_STATUS0);
#elif !defined(PMC_HAS_PCR_NO_MORE_PCxR) || (PMC_HAS_PCR_NO_MORE_PCxR==0)
	PMC->PMC_PCER0 = MASK_STATUS0;
	while ((PMC->PMC_PCSR0 & MASK_STATUS0) != MASK_STATUS0);

	PMC->PMC_PCER1 = MASK_STATUS1;
	while ((PMC->PMC_PCSR1 & MASK_STATUS1) != MASK_STATUS1);
#else
     uint32_t pid, mask;
     for (mask=MASK_STATUS0, pid=0; pid < 32; ++pid, mask>>=1)
       if (mask & 0x1)
       {
         PMC->PMC_PCR = PMC_PCR_PID(pid); // map the Peripheral pid to PMC_PCR register for next Read operation
         PMC->PMC_PCR = (PMC->PMC_PCR & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | PMC_PCR_PID(pid) | PMC_PCR_EN;
         while ((PMC->PMC_PCR & PMC_PCR_EN) == 0x0)
           ;
       }
     for (mask=MASK_STATUS1, pid=32; pid < 64; ++pid, mask>>=1)
       if (mask & 0x1)
       {
         PMC->PMC_PCR = PMC_PCR_PID(pid); // map the Peripheral pid to PMC_PCR register for next Read operation
         PMC->PMC_PCR = (PMC->PMC_PCR & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | PMC_PCR_PID(pid) | PMC_PCR_EN;
         while ((PMC->PMC_PCR & PMC_PCR_EN) == 0x0)
           ;
       }
#endif
}

/**
 * \brief Disable all peripheral clocks.
 */
void pmc_disable_all_periph_clk(void)
{
#if (SAM3N || SAM3U)
	PMC->PMC_PCDR = MASK_STATUS0;
	while ((PMC->PMC_PCSR & MASK_STATUS0) != 0);
#elif (SAM4N ||SAM4SH1 || SAMG53 || SAMG55)
	PMC->PMC_PCDR0 = MASK_STATUS0;
	while ((PMC->PMC_PCSR0 & MASK_STATUS0) != 0);
#elif !defined(PMC_HAS_PCR_NO_MORE_PCxR) || (PMC_HAS_PCR_NO_MORE_PCxR==0)
	PMC->PMC_PCDR0 = MASK_STATUS0;
	while ((PMC->PMC_PCSR0 & MASK_STATUS0) != 0);

	PMC->PMC_PCDR1 = MASK_STATUS1;
	while ((PMC->PMC_PCSR1 & MASK_STATUS1) != 0);
#else
     uint32_t pid, mask;
     for (mask=MASK_STATUS0, pid=0; pid < 32; ++pid, mask>>=1)
       if (mask & 0x1)
       {
         PMC->PMC_PCR = PMC_PCR_PID(pid); // map the Peripheral pid to PMC_PCR register for next Read operation
         PMC->PMC_PCR = (PMC->PMC_PCR & ~(PMC_PCR_PID_Msk|PMC_PCR_EN)) | PMC_PCR_CMD | PMC_PCR_PID(pid);
         while ((PMC->PMC_PCR & PMC_PCR_EN) != 0x0)
           ;
       }
     for (mask=MASK_STATUS1, pid=32; pid < 64; ++pid, mask>>=1)
       if (mask & 0x1)
       {
         PMC->PMC_PCR = PMC_PCR_PID(pid); // map the Peripheral pid to PMC_PCR register for next Read operation
         PMC->PMC_PCR = (PMC->PMC_PCR & ~(PMC_PCR_PID_Msk|PMC_PCR_EN)) | PMC_PCR_CMD | PMC_PCR_PID(pid);
         while ((PMC->PMC_PCR & PMC_PCR_EN) != 0x0)
           ;
       }
#endif
}

/**
 * \brief Get the status of the specified peripheral clock.
 *
 * \note The ID must NOT be shifted (i.e. 1 << ID_xxx).
 *
 * \param dw_id Peripheral ID (ID_xxx).
 *
 * \retval 0 Clock is active.
 * \retval 1 Clock is inactive.
 * \retval 2 Invalid parameter.
 */
uint32_t pmc_is_periph_clk_enabled(uint32_t dw_id)
{
	if (!(dw_id < 35))
		return 2;

#if (SAM3N || SAM3U)
	if ((PMC->PMC_PCSR & ((uint32_t) 1 << dw_id))) {
		return 0;
	} else {
		return 1;
	}
#elif (SAM4N ||SAM4SH1 || SAMG53 || SAMG55)
	if ((PMC->PMC_PCSR0 & ((uint32_t) 1 << dw_id))) {
		return 0;
	} else {
		return 1;
	}
#elif !defined(PMC_HAS_PCR_NO_MORE_PCxR) || (PMC_HAS_PCR_NO_MORE_PCxR==0)
	if (dw_id < 32) {
		if ((PMC->PMC_PCSR0 & ((uint32_t) 1 << dw_id))) {
			return 0;
		} else {
			return 1;
		}
	} else {
		dw_id -= 32;
		if ((PMC->PMC_PCSR1 & ((uint32_t) 1 << dw_id))) {
			return 0;
		} else {
			return 1;
		}
	}
#else
        PMC->PMC_PCR = PMC_PCR_PID(dw_id); // map the Peripheral dw_id to PMC_PCR register for next Read operation
        return ((PMC->PMC_PCR & PMC_PCR_EN) != 0x0);
#endif
}

/**
 * \brief Switch programmable clock source selection to slow clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 * \param dw_pres Programmable clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
#ifndef SAM9X6
uint32_t pmc_switch_pck_to_sclk(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;

	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_SLOW_CLK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
	return 0;
}
#endif // MNn SAM9X6

#if (SAM9X6)
uint32_t pmc_switch_pck_to_md_sclk(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;

	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_MD_SLOW_CLK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
	return 0;
}

uint32_t pmc_switch_pck_to_td_sclk(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;

	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_TD_SLOW_CLOCK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
	return 0;
}
#endif // MNn SAM9X6

/**
 * \brief Switch programmable clock source selection to main clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 * \param dw_pres Programmable clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_switch_pck_to_mainck(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;
#if (SAM9X6)
	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_MAINCK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
#else
	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_MAIN_CLK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
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
uint32_t pmc_switch_pck_to_pllack(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;
        
#if (SAM9X6)             
	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_PLLA | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
#else
 	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_PLLA_CLK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;
#endif // MNn SAM9X6
        
        
	return 0;
}

/**
 * \brief Enable the specified programmable clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 */
void pmc_enable_pck(uint32_t dw_id)
{
	PMC->PMC_SCER = PMC_SCER_PCK0 << dw_id;
}

/**
 * \brief Disable the specified programmable clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 */
void pmc_disable_pck(uint32_t dw_id)
{
	PMC->PMC_SCDR = PMC_SCER_PCK0 << dw_id;
}

/**
 * \brief Enable all programmable clocks.
 */
void pmc_enable_all_pck(void)
{
#if (LIMES || SAM9X6 ) // no PCK2
        PMC->PMC_SCER = PMC_SCER_PCK0 | PMC_SCER_PCK1;
#else 
	PMC->PMC_SCER = PMC_SCER_PCK0 | PMC_SCER_PCK1 | PMC_SCER_PCK2;
#endif
}

/**
 * \brief Disable all programmable clocks.
 */
void pmc_disable_all_pck(void)
{
#if (LIMES || SAM9X6 ) // no PCK2
	PMC->PMC_SCDR = PMC_SCDR_PCK0 | PMC_SCDR_PCK1;
#else 
	PMC->PMC_SCDR = PMC_SCDR_PCK0 | PMC_SCDR_PCK1 | PMC_SCDR_PCK2;
#endif
}

/**
 * \brief Get the status of the specified programmable clock.
 *
 * \param dw_id Id of the programmable clock.
 *
 * \retval 0 Clock is inactive.
 * \retval 1 Clock is active.
 * \retval 2 Invalid selection.
 */
uint32_t pmc_is_pck_enabled(uint32_t dw_id)
{
	if (dw_id > 2)
		return 2;

	return (PMC->PMC_SCSR & (PMC_SCSR_PCK0 << dw_id));
}



/**
 * \brief Set the wake-up inputs for fast startup mode registers (event generation).
 *
 * \param dw_inputs Wake up inputs to enable.
 */
#ifndef SAMA5 //ERr SAMA5
#ifndef SAM4N //ERr SAMA5
void pmc_set_fast_startup_input(uint32_t dw_inputs)
{
	PMC->PMC_FSMR &= (uint32_t) ~ 0xFFFF;
	PMC->PMC_FSMR |= dw_inputs;
}
/**
 * \brief Enable Sleep Mode.
 * Enter condition: (WFE or WFI) + (SLEEPDEEP bit = 0) + (LPM bit = 0)
 *
 * \param uc_type 0 - wait for interrupt, 1 - wait for event.
 */
void pmc_enable_sleepmode(uint8_t uc_type)
{
#if (SAM9X6)

  PMC->PMC_FSMR &= (uint32_t) ~ PMC_FSMR_ULPM;	// Enter Sleep mode
  //	SCB->SCR &= (uint32_t) ~ SCB_SCR_SLEEPDEEP_Msk;	// MNn : this register or field does not exist on SAM9X6

	if (uc_type == 0) {
		//__WFI();
	} else {
		//__WFE();
	}

#else  
#if (SAM4SH1 || SAMG53 || LIMES)
  #warning check FLPM field use
#else
  #ifndef SAM4C 
	PMC->PMC_FSMR &= (uint32_t) ~ PMC_FSMR_LPM;	// Enter Sleep mode
  #endif
	SCB->SCR &= (uint32_t) ~ SCB_SCR_SLEEPDEEP_Msk;	// Deep sleep

	if (uc_type == 0) {
		//__WFI();
	} else {
		//__WFE();
	}
#endif
#endif // MNn SAM9X6        
}

/**
 * \brief Enable Wait Mode.
 * Enter condition: WFE + (SLEEPDEEP bit = 0) + (LPM bit = 1)
 */
void pmc_enable_waitmode(void)
{
 uint32_t i;
#if (SAM4SH1 || SAMG53 || LIMES)
  #warning check FLPM field use
#else
  #ifndef SAM4C 
      #if SAM9X6 //ULMP added to SAM9X6 valid patch MNn because wrongly not defined in isoc header for PMC_FSMR
 	PMC->PMC_FSMR |= PMC_FSMR_ULPM;	// Enter Wait mode for sam9X6 this field is called ULPM and not LPM MNn 
      #else 
	PMC->PMC_FSMR |= PMC_FSMR_LPM;	// Enter Wait mode
#endif // SAM9X6 
  #endif
#endif
	//SCB->SCR &= (uint32_t) ~ SCB_SCR_SLEEPDEEP_Msk;	// Deep sleep SLEEPDEEP and SCB undefined in SAM9X6
	//__WFE();

	/* Waiting for MOSCRCEN bit is cleared is strongly recommended
	 * to ensure that the core will not execute undesired instructions
	 */
	for (i = 0; i < 500; i++) {
		//__NOP();
                asm("nop");
	}
	while (!(PMC->CKGR_MOR & CKGR_MOR_MOSCRCEN));
}


/**
 * \brief Enable Backup Mode.
 * Enter condition: WFE + (SLEEPDEEP bit = 1)
 */
void pmc_enable_backupmode(void)
{
	//SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
//	__WFE();
}
#endif //ERr SAM4N
#endif //ERr SAMA5




/** 
 * \brief Enable PMC interrupts.
 *
 * \param dw_sources interrupt sources bit map.
 */
void pmc_enable_interrupt(uint32_t dw_sources)
{
	PMC->PMC_IER = dw_sources;
}

/** 
 * \brief Disable PMC interrupts.
 *
 * \param dw_sources interrupt sources bit map.
 */
void pmc_disable_interrupt(uint32_t dw_sources)
{
	PMC->PMC_IDR = dw_sources;
}

/** 
 * \brief Read PMC interrupt mask.
 *
 * \return The interrupt mask value.
 */
uint32_t pmc_get_interrupt_mask(void)
{
	return PMC->PMC_IMR;
}

/**
 * \brief Get current status.
 *
 * \return The current PMC status.
 */
uint32_t pmc_get_status(void)
{
	return PMC->PMC_SR;
}


/** 
 * \brief Enable/Disable write protect of PMC registers.
 *
 * \param dw_enable 1 to enable, 0 to disable.
 */
void pmc_set_writeprotect(uint32_t dw_enable)
{
	if (dw_enable)
		PMC->PMC_WPMR = PMC_WPMR_WPKEY_VALUE | PMC_WPMR_WPEN;
	else
		PMC->PMC_WPMR = PMC_WPMR_WPKEY_VALUE;
}

/** 
 * \brief Return write protect status.
 *
 * \retval 0 Protection disabled.
 * \retval 1 Protection enabled.
 */
uint32_t pmc_get_writeprotect_status(void)
{
	return PMC->PMC_WPMR & PMC_WPMR_WPEN;
}

#if (SAM3S)
/**
 * \brief Enable pllb clock.
 *
 * \param mulb Pllb multiplier.
 * \param pllbcount Pllb counter.
 * \param divb Divider.
 */
void pmc_enable_pllbck(uint32_t mulb, uint32_t pllbcount, uint32_t divb)
{
	pmc_disable_pllbck();	// Hardware BUG FIX : first disable the PLL to unlock the lock! 
	// It occurs when re-enabling the PLL with the same parameters.
	PMC->CKGR_PLLBR =
			CKGR_PLLBR_DIVB(divb) | CKGR_PLLBR_PLLBCOUNT(pllbcount)
			| CKGR_PLLBR_MULB(mulb);
	while ((PMC->PMC_SR & PMC_SR_LOCKB) == 0);
}

/**
 * \brief Is pllb clocked?.
 *
 * \retval 0 Not locked.
 * \retval 1 Locked.
 */
uint32_t pmc_is_locked_pllbck(void)
{
	return (PMC->PMC_SR & PMC_SR_LOCKB);
}

/**
 * \brief Disable pllb clock.
 */
void pmc_disable_pllbck(void)
{
	PMC->CKGR_PLLBR = CKGR_PLLBR_MULB(0);
}

/**
 * \brief Switch master clock source selection to pllb clock.
 *
 * \param dw_pres Processor clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_switch_mck_to_pllbck(uint32_t dw_pres)
{
	uint32_t dw_timeout;

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

/**
 * \brief Switch programmable clock source selection to pllb clock.
 *
 * \param dw_id Id (number) of the programmable clock.
 * \param dw_pres Programmable clock prescaler.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 */
uint32_t pmc_switch_pck_to_pllbck(uint32_t dw_id, uint32_t dw_pres)
{
	uint32_t dw_timeout;

	PMC->PMC_PCK[dw_id] = PMC_PCK_CSS_PLLA_CLK | dw_pres;
	for (dw_timeout = PMC_TIMEOUT; !(PMC->PMC_SR & (PMC_SR_PCKRDY0 << dw_id));
			--dw_timeout)
		if (dw_timeout == 0)
			return 1;

	return 0;
}

/**
 * \brief Switch udp (usb) clock source selection to pllb clock.
 *
 * \param dw_usbdiv Clock divisor.
 */
void pmc_switch_udpck_to_pllbck(uint32_t dw_usbdiv)
{
	PMC->PMC_USB = PMC_USB_USBDIV(dw_usbdiv) | PMC_USB_USBS;
}
#endif

#if (SAM3S || SAM3XA)
/**
 * \brief Switch udp (usb) clock source selection to plla clock.
 *
 * \param dw_usbdiv Clock divisor.
 */
void pmc_switch_udpck_to_pllack(uint32_t dw_usbdiv)
{
	PMC->PMC_USB = PMC_USB_USBDIV(dw_usbdiv);
}

/**
 * \brief Enable udp (usb) clock.
 */
void pmc_enable_udpck(void)
{
#if SAM3S
	PMC->PMC_SCER = PMC_SCER_UDP;
#else
	PMC->PMC_SCER = PMC_SCER_UOTGCK;
#endif
}

/**
 * \brief Disable udp (usb) clock.
 */
void pmc_disable_udpck(void)
{
#if SAM3S
	PMC->PMC_SCDR = PMC_SCDR_UDP;
#else
	PMC->PMC_SCDR = PMC_SCDR_UOTGCK;
#endif
}
#endif


#if (SAM3XA || SAM3U)
/**
 * \brief Enable UPLL clock.
 */
void pmc_enable_upll_clock(void)
{
	PMC->CKGR_UCKR = CKGR_UCKR_UPLLCOUNT(3) | CKGR_UCKR_UPLLEN;

	/* Wait UTMI PLL Lock Status */
	while (!(PMC->PMC_SR & PMC_SR_LOCKU));
}

/**
 * \brief Disable UPLL clock.
 */
void pmc_disable_upll_clock(void)
{
	PMC->CKGR_UCKR &= ~CKGR_UCKR_UPLLEN;
}
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
