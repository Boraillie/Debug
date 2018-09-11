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
 * \file v_test_adc.c
 * \brief Programme de tests.
 * \author AYi
 * \version 0.1
 * \date 12 Feb 2016
 *
 * Validation test for ATMEL product ADC 
 *
 *\todo add dualtrig test with all cases. test can toogle an IO or use timers for pass/fail tests
 */
#include  "v_tests/v_test_adc.h"
#include  "v_drivers/v_adc.h"

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
void v_adc_basic_demo(Adc* pAdc)
{
//        char menu_choice_msg0[MENU_STRING_LENGTH]= {"Sleep walking ADC"};
	DEBUG_Printk("\n\r\n\r");
	DEBUG_Printk("  =========== Performing a Software Reset ==\n\r");
	//strcpy(menu_choice_msg[1],"Sleep walking ADC");

	//Adc init 
	v_adc_initialize(ADC);
        pmc_enable_periph_clk(ID_ADC);

        ADC_CfgTiming( (Adc*)ADC, ADC_TRACKING, ADC_SETTLING, ADC_TRANSFER );
        
                
	//ADC_CfgTrigering( ADC,ADC_MR_TRGSEL_ADC_TRIG0, ADC_TRGR_TRGMOD_EXT_TRIG_ANY, 0 );
        ADC_CfgTrigering( (Adc*)ADC,0,0, ADC_TRGR_TRGMOD_CONTINUOUS );
        
        
        // Configure PIO controllers for ADTRG pin
        v_pioV4_iocfg_periph(PIOD, PIO_PD31A_ADTRG, PIO_PERIPH_A);
	 
        ADC_EnableChannel(ADC, 0);
        while(1)
        {
                
                //ADC_StartConversion( ADC );            
                
  //              sprintf (message,"==> Chanbnel 0 output : 0x%.8X\n\r",ADC->ADC_CDR0);Valid_DebugTrace(message);  
                
                while ((ADC_GetStatus(pAdc) & ADC_ISR_DRDY)==0);
                sprintf (message,"==> Channel output : 0x%.8X\n\r",ADC_GetLastConvertedData(ADC));Valid_DebugTrace(message);
                
                        
        }

        
}

/**
 * \fn void v_adc_dualtrig_demo(Adc* pAdc)
 * \brief Dual trig demo with ADC trigered by RTCOUT1
 * \param pAdc ADC instnace e.g ADC0
 * \return no retrun provided.
 * \todo return fail or pass depending on ADC value. e.g Vref/2
 * \todo Add a second source, toggle a PIO and, and check with an oscilloscope the peridicty of data conversion
 */
void v_adc_dualtrig_demo(Adc* pAdc)
{
//Adc init 
	v_adc_initialize(ADC);
        pmc_enable_periph_clk(ID_ADC);
        //! \todo take in account adc source clock
        uint32_t adc_pres  = (((PMC->PMC_MCKR & PMC_MCKR_H32MXDIV_H32MXDIV2)?(MCK_clock_speed/2):MCK_clock_speed)/(2*ADC_CLOCK))-1;             //PRESCAL = (fperipheral clock / (2 × fADCCLK)) – 1
        
        
        ADC_CfgTiming( (Adc*)ADC, ADC_TRACKING, ADC_SETTLING, ADC_TRANSFER );
        ADC_cfgFrequency( ADC, ADC_STARTUP,adc_pres); 
        ADC_CfgTrigering(ADC,0,0, 0 );

        DEBUG_Printk("ADC triggered by 1HZ RTC waveform\n\r");
        rtc_waveform_output_last_adc_channel(RTC,RTC_MR_OUT1_FREQ1HZ);  


        //!
        //\todo All chnnels must be disabled before enabling dualtrig mode 
        //!
        pAdc->ADC_LCTMR |= ADC_LCTMR_DUALTRIG;
        
        while(1)
        {
                //ADC_StartConversion( ADC );            
                
  //              sprintf (message,"==> Chanbnel 0 output : 0x%.8X\n\r",ADC->ADC_CDR0);Valid_DebugTrace(message);  
                
                while ((ADC_GetStatus(pAdc) & ADC_ISR_EOC11)==0);
                uint32_t  read_tempo =ADC->ADC_LCDR;     // avoid GOVR error
                read_tempo = ADC_GetConvertedData(ADC,11);
                sprintf (message,"==> Channel output : 0x%.8X\n\r",read_tempo);Valid_DebugTrace(message);
                
        }

        
}

/**
 * \fn void v_adc_basic_demo(Adc* pAdc)
 * \brief Demo with external Tigger 

 * \param pAdc ADC instnace e.g ADC0
 * \todo Only pin trig is done. RTC and TimerCOnunter are to be done  
 * \return no retrun provided.
 * \todo return fail or pass depending on ADC value. e.g Vref/2
 */
void v_adc_trig_demo(Adc* pAdc, uint32_t TrigType)
{
	DEBUG_Printk("\n\r\n\r");
	DEBUG_Printk("  =========== ADC demo with hw trigger ==\n\r");
        
        
	//Adc init 
	v_adc_initialize(ADC);
        pmc_enable_periph_clk(ID_ADC);
        //! \todo take in account adc source clock
        uint32_t adc_pres  = (((PMC->PMC_MCKR & PMC_MCKR_H32MXDIV_H32MXDIV2)?(MCK_clock_speed/2):MCK_clock_speed)/(2*ADC_CLOCK))-1;             //PRESCAL = (fperipheral clock / (2 × fADCCLK)) – 1
        
        
        ADC_CfgTiming( (Adc*)ADC, ADC_TRACKING, ADC_SETTLING, ADC_TRANSFER );
        ADC_cfgFrequency( ADC, ADC_STARTUP,adc_pres); 
        
        
        
        
	ADC_CfgTrigering( ADC,ADC_TRGR_TRGMOD_EXT_TRIG_ANY,ADC_MR_TRGSEL_ADC_TRIG0, 0 );
        
        // Configure PIO controllers for ADTRG pin
        v_pioV4_iocfg_periph(PIOD, PIO_PD31A_ADTRG, PIO_PERIPH_A);
        
        ADC_EnableChannel(ADC, 0);
        while(1)
        {
               //change ADTRG PIN state to start a converion 
                while ((ADC_GetStatus(pAdc) & ADC_ISR_DRDY)==0);
                sprintf (message,"==> Channel output : 0x%.8X\n\r",ADC_GetLastConvertedData(ADC));Valid_DebugTrace(message);
        }
        
        
        
}


/**
 * \fn void v_adc_comparison_demo(Adc* pAdc)
 * \brief Demo with comparison window. Freerun mode used 
 * \param pAdc ADC instnace e.g ADC0
 * \todo Only pin trig is done. RTC and TimerCOnunter are to be done  
 * \return no retrun provided.
 * \todo return fail or pass depending on ADC value. e.g Vref/2
 */
void v_adc_comparison_demo(Adc* pAdc)
{
	DEBUG_Printk("\n\r\n\r");
	DEBUG_Printk("  =========== ADC demo with hw trigger ==\n\r");
        
        
	//Adc init 
	v_adc_initialize(ADC);
        pmc_enable_periph_clk(ID_ADC);
        //! \todo take in account adc source clock
        uint32_t adc_pres  = (((PMC->PMC_MCKR & PMC_MCKR_H32MXDIV_H32MXDIV2)?(MCK_clock_speed/2):MCK_clock_speed)/(2*ADC_CLOCK))-1;             //PRESCAL = (fperipheral clock / (2 × fADCCLK)) – 1
        
        
        ADC_CfgTiming( (Adc*)ADC, ADC_TRACKING, ADC_SETTLING, ADC_TRANSFER );
        ADC_cfgFrequency( ADC, ADC_STARTUP,adc_pres); 
        ADC_CfgTrigering(ADC,0,0, ADC_TRGR_TRGMOD_CONTINUOUS );
        
        //Comparison mode init        
        ADC_SetComparisonWindow(ADC, 3000,4095);
	ADC_SetCompareMode( ADC, ADC_EMR_CMPMODE_IN );
        ADC_SetCompareType( ADC, ADC_EMR_CMPTYPE_FLAG_ONLY );
        ADC_SetCompareChannel( ADC,0);
        
        
        ADC_EnableChannel(ADC, 0);
        while(1)
        {
                while ((ADC_GetStatus(pAdc) & ADC_ISR_DRDY)==0);
                if ((ADC_GetStatus(pAdc) & ADC_ISR_COMPE)) 
                {
                        //Change AD0 input until getting in the window.
                        sprintf (message,"==> Condition met. Channel output : 0x%.8X\n\r",ADC_GetLastConvertedData(ADC));Valid_DebugTrace(message);
        
                }
        }
}

/**
 * \fn void prepare_adc_sleepWalking(Adc* pAdc)
 * \brief Demo with comparison window. Freerun mode used 
* \param rtc_trig : true/ false
* \return no retrun provided.
* \todo return fail or pass depending on ADC value. e.g Vref/2
*/

void run_adc_sleepWalking(uint32_t rtc_trig)
{
        DEBUG_Printk("SleepWalking test on ADC \n\r\n\r");
        while ( rtc_trig && pmc_sleep_walking_is_active(ID_ADC))
        {
                DEBUG_Printk("Activity on ADC! \n\r\n\r");
                adc_comparison_restart(ADC);
                pmc_disable_sleep_walking(ID_ADC);
                
        
        }

        
        
        pmc_enable_sleep_walking(ID_ADC);
        
        if (!pmc_sleep_walking_is_active(ID_ADC))
                
        {
                DEBUG_Printk("Starting wait mode... \n\r\n\r");
                
                adc_comparison_restart(ADC);
                //Enable rtc trig if needed
                if (rtc_trig)
                {
                        
                        //                        rtc_waveform_output_all_adc_channels(RTC,RTC_MR_OUT0_FREQ1HZ);  
                        rtc_waveform_output_all_adc_channels(RTC,7<<16);  
                        RTC->RTC_MR |= 7 << 24;
                }

                
                set_clocks((uint8_t)USE_RC_12MHZ,USE_MAIN_CLK,0,0,0,0,0,1,0);;          //MCK_MDIV =1    
                v_start_waitmode();           
                set_clocks((uint8_t)MAIN_CLK_CONFIG,MCK_CONFIG,PLLA_MUL,PLLA_DIV,0,0,PCK_PRESCALER,MCK_MDIV,PLL_DIV2);
                DEBUG_Printk("WKUP! \n\r\n\r");
                
                //Disable rtc trig 
                if (rtc_trig)
                        rtc_waveform_output_all_adc_channels(RTC,RTC_MR_OUT0_NO_WAVE);
                adc_comparison_restart(ADC);
                return;
        }
        DEBUG_Printk("Activity on peripherals! \n\r\n\r");
  
}



/**
 * \fn void v_adc_sleepwalking_basic_demo(Adc* pAdc)
 * \brief Demo with comparison window. ADTRG pin used
* \param pAdc ADC instnace e.g ADC0
* \return no retrun provided.
* \todo return fail or pass depending on ADC value. e.g Vref/2
*/
void v_adc_sleepwalking_basic_demo(Adc* pAdc)
{
        uint32_t channel_sel = 0;
        
        DEBUG_Printk("ADC SleepWalking test\n\r");
        //Adc init 
	v_adc_initialize(ADC);
        pmc_enable_periph_clk(ID_ADC);
        //! \todo take in account adc source clock
        uint32_t adc_pres  = (((PMC->PMC_MCKR & PMC_MCKR_H32MXDIV_H32MXDIV2)?(MCK_clock_speed/2):MCK_clock_speed)/(2*ADC_CLOCK))-1;             //PRESCAL = (fperipheral clock / (2 × fADCCLK)) – 1
        
        
        ADC_CfgTiming( (Adc*)ADC, ADC_TRACKING, ADC_SETTLING, ADC_TRANSFER );
        ADC_cfgFrequency( ADC, ADC_STARTUP,adc_pres);
        //configure power modes
        //ADC_CfgPowerSave( ADC, 1, 0 );//sleep = 1 , wkup =0
        
        ADC_DisableChannels(ADC,0xFFFFFFFF);
        ADC_ClearStatus(ADC);
        //ADC_EnableTag(ADC,ADC_EMR_TAG);
        //ADC_CfgChannelMode(ADC,ADC_MR_USEQ_NUM_ORDER,0);
        //user_seq = ADC_MR_USEQ_NUM_ORDER;
        ADC_DisableIt(ADC, (0xFFFFFFFF));
        ADC_SetCompareChannel(ADC,channel_sel);
        ADC_CfgTrigering( ADC,ADC_TRGR_TRGMOD_EXT_TRIG_ANY,ADC_MR_TRGSEL_ADC_TRIG0, 0 );
        
        // Configure PIO controllers for ADTRG pin
        v_pioV4_iocfg_periph(PIOD, PIO_PD31A_ADTRG, PIO_PERIPH_A);
       
        //Comparison mode init  
        DEBUG_Printk("Compare IN test -- Set Compare window 3000<->4095 \n\r");        
        ADC_SetComparisonWindow(ADC, 3000,4095);
	ADC_SetCompareMode( ADC, ADC_EMR_CMPMODE_IN );
        ADC_SetCompareType( ADC, ADC_EMR_CMPTYPE_FLAG_ONLY );
        ADC_EnableChannel(ADC, channel_sel);



       
        run_adc_sleepWalking(0);
        
        DEBUG_Printk(" Condition matched, SYS wakes up! \n\r");
}

/**
 * \fn void v_adc_sleepwalking_demo(Adc* pAdc,)
 * \brief Demo with comparison window. ADTRG pin used
 * \param pAdc ADC instnace e.g ADC0
 * \param trgsel
 *<TABLE>
 *<TR><TD>Input</TD><TD>Function</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG0</TD><TD>ADTRG</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG1</TD><TD>TIOA0</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG2</TD><TD>TIOA1</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG3</TD><TD>TIOA2</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG4</TD><TD>PWM event line 0</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG5</TD><TD>PWM event line 1</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG6</TD><TD>TIOA3</TD>
 *<TR><TD>ADC_MR_TRGSEL_ADC_TRIG7</TD><TD>RTCOUT0</TD>
 * </TABLE>
 * \return no retrun provided.
 * \todo return fail or pass depending on ADC value. e.g Vref/2
*/
void v_adc_sleepwalking_demo(Adc* pAdc, uint32_t trigsel)
{
        uint32_t channel_sel = 0;
        
        DEBUG_Printk("ADC SleepWalking test\n\r");
        //Adc init 
	v_adc_initialize(ADC);
        pmc_enable_periph_clk(ID_ADC);
        //! \todo take in account adc source clock
        uint32_t adc_pres  = (((PMC->PMC_MCKR & PMC_MCKR_H32MXDIV_H32MXDIV2)?(MCK_clock_speed/2):MCK_clock_speed)/(2*ADC_CLOCK))-1;             //PRESCAL = (fperipheral clock / (2 × fADCCLK)) – 1
        
        
        ADC_CfgTiming( (Adc*)ADC, ADC_TRACKING, ADC_SETTLING, ADC_TRANSFER );
        ADC_cfgFrequency( ADC, ADC_STARTUP,adc_pres);
        //configure power modes
        ADC_CfgPowerSave( ADC, 1, 0 );//sleep = 1 , wkup =0
        
        ADC_DisableChannels(ADC,0xFFFFFFFF);
        ADC_ClearStatus(ADC);
        //ADC_EnableTag(ADC,ADC_EMR_TAG);
        //ADC_CfgChannelMode(ADC,ADC_MR_USEQ_NUM_ORDER,0);
        //user_seq = ADC_MR_USEQ_NUM_ORDER;
        ADC_DisableIt(ADC, (0xFFFFFFFF));
        ADC_SetCompareChannel(ADC,channel_sel);

//        ADC_CfgTrigering( ADC,ADC_TRGR_TRGMOD_EXT_TRIG_ANY,trigsel, 0 );
          ADC_CfgTrigering( ADC,ADC_TRGR_TRGMOD_EXT_TRIG_RISE,trigsel, 0 );
        
        switch (trigsel)
        {
          case ADC_MR_TRGSEL_ADC_TRIG0:
                // Configure PIO controllers for ADTRG pin
                v_pioV4_iocfg_periph(PIOD, PIO_PD31A_ADTRG, PIO_PERIPH_A);       
                break;
                
          case ADC_MR_TRGSEL_ADC_TRIG1:
                //!\todo configure TIOA0
                break;                
          case ADC_MR_TRGSEL_ADC_TRIG2:
                //!\todo configure TIOA1
                break;                
          case ADC_MR_TRGSEL_ADC_TRIG3:
                //!\todo configure TIOA2
                break;
          case ADC_MR_TRGSEL_ADC_TRIG4:
                //!\todo configure pwm line 0
                break;
          case ADC_MR_TRGSEL_ADC_TRIG5:
                //!\todo configure pwm line 1
                break;
          case ADC_MR_TRGSEL_ADC_TRIG6:
                //!\todo configure TIOA2
                break;
          case ADC_MR_TRGSEL_ADC_TRIG7:
                /* Default RTC configuration */
                RTC_SetHourMode(RTC,0);	/* 24-hour mode */
                RTC_SetTime( RTC,12, 30, 30 );
                RTC_SetDate( RTC, 2016, 10, 4, 5 );
                DEBUG_Printk("ADC triggered by 1HZ RTC waveform\n\r");
                //!\todo configure RTCOUT0
                break;
          default:
                //!\todo print Error and exit
                break;
                
        }
        
        //Comparison mode init  
        DEBUG_Printk("Compare IN test -- Set Compare window 3000<->4095 \n\r");        
        ADC_SetComparisonWindow(ADC, 3000,4095);
        ADC_SetCompareMode( ADC, ADC_EMR_CMPMODE_IN );
        ADC_SetCompareType( ADC, ADC_EMR_CMPTYPE_START_CONDITION );
        ADC_SetCompareChannel( ADC,channel_sel  );
        ADC_EnableChannel(ADC, channel_sel);
        
        while(1)
                run_adc_sleepWalking(trigsel&ADC_MR_TRGSEL_ADC_TRIG7);
        
        
}
