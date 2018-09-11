/**
 * \file v_test_adc.h
 * \brief adc demo header file
 * \author AYi
 * \version 0.1
 * \date 01 Janvier 2016
 *
 */


#ifndef _V_TEST_ADC_H
#define _V_TEST_ADC_H

#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"

// ---- Validation libraries
#include "v_debug.h"
#include "v_utils.h"
#include "v_drivers/v_pioV4.h"





/** 
 * \define ADC_TRACKING 
 * \brief Tracking time 
 *
 * The tracking time represents the time between the channel selection change and the time for the controller to start the ADC. 
 *
 *  * \todo define ADC_TRACKING accurately 
 *  */
#define ADC_TRACKING	15
/** 
 * \define ADC_SETTLING 
 * \brief SETTLING time 
 *
 * The tracking time represents the time between the channel selection change and the time for the controller to start the ADC. 
 *
 *  * \todo define ADC_TRACKING accurately 
 *  */
#define ADC_SETTLING	2
/** 
 * \define ADC_TRACKING 
 * \brief Tracking time  
 *
 *  * \todo define ADC_TRACKING accurately. seems to be not applicable to sama5d2
 *  */
#define ADC_TRANSFER	2



/** 
 * \define ADC_STARTUP 
 * \brief adc startup
 *
 *  * \todo define ADC_STARTUP accurately.
 *  */
#define  ADC_STARTUP 2
/** 
 * \define ADC_CLOCK 
 * \brief adc clock : PRESCAL = (fperipheral clock / (2 × fADCCLK)) – 1.  
 *
 *  */
#define  ADC_CLOCK      1000000 //1MHz


#endif //_V_TEST_ADC_H