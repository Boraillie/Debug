/*! \file *********************************************************************
*
* \brief PMC driver for PMC2 (Starting from SAM9X6).
*
* Power Management Controller (PMC) driver module for Microchi MPUs.
*
* - Compiler:           IAR EWARM and GNU.
* - Supported devices:  SAM9X6.
* - AppNote:
*
******************************************************************************/


#include "v_pmcV2.h"

uint32_t pmc_switch_mck_to_mainck(uint32_t dw_pres)
{
#if PMC_HAS_PMC_MCKR
    pmc_switch_mck_to_new_source(PMC_MCKR_CSS_MAIN_CLK);
    pmc_set_mck_prescaler(dw_pres);
#elif PMC_HAS_CPU_CKR
    pmc_switch_mck_to_new_source(PMC_CPU_CKR_CSS_MAIN_CLK);
    //Presacler set after switching to avoid running on a high frequency in case current source is PLL
    pmc_set_mck_prescaler(dw_pres); 
#else
  #error Device not supported
#endif
}

void v_pmc_switch_mck_to_mainck(void)
{
  pmc_switch_mck_to_new_source(PMC_CPU_CKR_CSS_MAIN_CLK);
}

uint32_t pmc_switch_mck_to_sclk(uint32_t dw_pres)
{
  #if PMC_HAS_PMC_MCKR
    pmc_switch_mck_to_new_source(PMC_MCKR_CSS_SLOW_CLK);
    pmc_set_mck_prescaler(dw_pres);
#elif PMC_HAS_CPU_CKR
    pmc_switch_mck_to_new_source(PMC_CPU_CKR_CSS_SLOW_CLK);
    //Presacler set after switching to avoid running on a high frequency in case current source is PLL
    pmc_set_mck_prescaler(dw_pres); 
#else
  #error Device not supported
#endif
    
}
void v_pmc_switch_mck_to_pllack(void)
{
    pmc_switch_mck_to_pll();
}

/**
 * \brief Switch main clock source selection to internal fast RC.
 *
 * \param dw_moscrcf 0 for 4Mhz, 1 for 8Mhz and 2 for 12Mhz.
 *
 * \retval 0 Success.
 * \retval 1 Timeout error.
 * \retval 2 Invalid frequency.
 */

void pmc_switch_mainck_to_fastrc(uint32_t dw_moscrcf)
{
#if PMC_HAS_MOSCRCF
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
#else 
        PMC->CKGR_MOR = (PMC->CKGR_MOR|CKGR_MOR_KEY(MOR_KEY_VAL)|CKGR_MOR_MOSCRCEN);
        
        //Wait the Fast RC to stabilize
        while (!(PMC->PMC_SR & PMC_SR_MOSCRCS));
        
        //Switch to Fast RC
        PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL)|CKGR_MOR_KEY(MOR_KEY_VAL);
#endif
        
}








void v_pmc_switch_mainck_to_fastrc(void) 
{
    PMC->CKGR_MOR = (PMC->CKGR_MOR|CKGR_MOR_KEY(MOR_KEY_VAL)|CKGR_MOR_MOSCRCEN);
    
    //Wait the Fast RC to stabilize
    while (!(PMC->PMC_SR & PMC_SR_MOSCRCS));
    
    //Switch to Fast RC
    PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL)|CKGR_MOR_KEY(MOR_KEY_VAL);
}

void pmc_switch_mainck_to_xtal(uint32_t dw_bypass)
{
    //\ TODO : To be implemented in SOftpacK. pmc_select_internal_crystal and external_crys available in softpack but not compatible 
}
    



void pmc_enable_pllack(uint32_t mul, uint32_t count, uint32_t div)
{
    static struct _pmc_plla_cfg plla_config = {.mul = 0,.div = 0,.count = 0};
    plla_config.mul = mul; plla_config.div = div; plla_config.count = count; 
    pmc_configure_plla(&plla_config);
}

#if DEVICE_HAS_GCLK
void  pmc_set_gclk(unsigned int periph_id , int gclkchoice)
{
       uint32_t pcr_value;
       PMC->PMC_PCR = PMC_PCR_PID(periph_id); // map the Peripheral gclk to PMC_PCR register 
       pcr_value = PMC->PMC_PCR;          // to retrieve info related to the Peripheral Clock of interest
       PMC->PMC_PCR = (pcr_value & ~PMC_PCR_PID_Msk) | PMC_PCR_CMD | gclkchoice | PMC_PCR_PID(periph_id) | PMC_PCR_EN | PMC_PCR_GCLKEN;
       return;
}
#endif

        