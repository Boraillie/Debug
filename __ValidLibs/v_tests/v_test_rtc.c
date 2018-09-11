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
#include  "v_tests/v_test_adc.h"
#include  "v_drivers/v_rtc.h"

#error "Demo to be used with svn external feauture"

extern  char   message[80];
extern unsigned int  MCK_clock_speed;


/**
 * \fn void v_adc_basic_demo(Adc* pAdc)
 * \brief Basic demo that enable channel0 in freerun(continious) mode and print converted data to default serial debug  *
 * \param pAdc ADC instnace e.g ADC0
 * \return no retrun provided.
 * \todo return fail or pass depending on ADC value. e.g Vref/2
 */
void v_rtc_adc_out_demo(Adc* pAdc)
{
/* Output example information */
	printf("\r\n\r\n\r\n");
	printf("-- Compiled: " __DATE__ " " __TIME__ " --\n\r");
	
	
	/* Default RTC configuration */
	RTC_SetHourMode(RTC,0);	/* 24-hour mode */
	RTC_SetTime( RTC,12, 30, 30 );
        RTC_SetDate( RTC, 2016, 10, 4, 5 );
                


	
	//output waveform in order to wakeup the system through the ADC
	rtc_waveform_output_last_adc_channel(RTC_MR_OUT1_FREQ1HZ);
}
