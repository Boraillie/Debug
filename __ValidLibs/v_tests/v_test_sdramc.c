/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2016, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file v_test_rtc.c
 * \brief Programme de tests.
 * \author AYi
 * \version 0.1
 * \date 12 Feb 2016
 *
 * Validation test for ATMEL product ADC 
 *
 */
#include  "v_tests/v_test_sdramc.h"


extern  char   message[80];
extern unsigned int  MCK_clock_speed;




void v_sdramc_cfg_pio(uint32_t ioset)
{
        unsigned char restore_wr_protect=0;
	//switch ioset : to implement 
	//implement io depending on device
	//Hardcoded for Capella 
#ifndef _LINK_TO_SDRAM_ //init Already done by macro
	

	// Check write protection
	if(PIO_IS_WRITE_PROTECTED(PIO)){
		v_pioV4_pio_wr_protect_disable(PIO);
		restore_wr_protect=1;
	}
	// periph A
	// data lines:
	// PC27 D0, PC28 D1, PC29 D2, PC30 D3, PC31 D4  
	v_pioV4_iocfg_periph(PIOC, 0xF8000000, PIO_PERIPH_A);

	// data lines:
	// PD0 D5, PD1 D6, PD2 D7, PD3 D8, PD4 D9, PD5 D10, PD6 D11, PD7 D12, PD8 D13, PD9 D14, PD10 D15,
	// Adresses:
	// PD11 A2, PD12 A3, PD13 A4, PD14 A5, PD15 A6, PD16 A7, PD17 A8, PD18 A9, PD19 A10, PD20 SDA10, PD21 A11, PD22 A13, PD23 A14,
	// PD25 SDCK, PD26 SDCKE, PD27 SDWE, PD28 BA0, PD29 BA1, PD30 RAS, PD31 CAS
	// Not used PD24 A15, 
	v_pioV4_iocfg_periph(PIOD, 0xFEFFFFFF, PIO_PERIPH_A);

	// PE0 SDCS0 
	// PE1 SDCS1
	// PE2 A0: NBS0
	// PE3 NBS1 
	v_pioV4_iocfg_periph(PIOE, 0x0000000F, PIO_PERIPH_A);
	// Restore write protection
	if(restore_wr_protect){
		v_pioV4_pio_wr_protect_enable(PIO);
	}
#endif
}

	


/**
 * \fn void v_adc_basic_demo(Adc* pAdc)
 * \brief Basic demo that enable channel0 in freerun(continious) mode and print converted data to default serial debug  *
 * \param pAdc ADC instnace e.g ADC0
 * \return no retrun provided.
 * \todo return fail or pass depending on ADC value. e.g Vref/2
 */

void v_sdramc_basic_demo(uint32_t cs)
{
        unsigned int * pt_ram;
        unsigned char restore_wr_protect=0;
	int ii,error=0;

#ifndef _LINK_TO_SDRAM_ //init Already done by macro

	v_sdramc_cfg_pio(0);
	v_sdram_cs_set(cs);                         /* Set CS 0 or 1 */
	pmc_enable_periph_clk(ID_SDRAMC);
	ConfigureSdram(SDRAMC); 

#endif
	 // 0 -> SDRAM Test

	DEBUG_Printk("Perform SDRAM Test...\n\r");
	pt_ram= (unsigned int * )0x70020000;
        
	for (ii=0;ii < (128*1024)/4; ii++){
		pt_ram[ii]= 0X550000+ii;
	}
	for (ii=0;ii < (128*1024)/4; ii++){
		if(   pt_ram[ii]!= 0X550000+ii) { error++;};
	}
	if( error != 0) DEBUG_Printk("SDRAM ERROR during write++\n\r");
        
	for (ii= (128*1024)/4; ii > 0; ii--){
		pt_ram[ii]= 0X550000+ii;
	}  
	for (ii= (128*1024)/4; ii > 0; ii--){
		if(   pt_ram[ii]!= 0X550000+ii) { error++;};
	}
	
        if( error != 0) 
                DEBUG_Printk("SDRAM ERROR during write--\n\r");
        else
                DEBUG_Printk("SDRAM Test Pass--\n\r");
        
        DEBUG_Printk("End of SDRAM Test\n\r");
}

