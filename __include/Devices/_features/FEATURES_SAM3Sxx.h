/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : features_sama5xxxxx.h
* Object              : ATSAM Definition File.
*
* Creation            : Sept/2011
*----------------------------------------------------------------------------
*/
#ifndef _FEATURES_SAM3Sxx_H
#define _FEATURES_SAM3Sxx_H


#include "global.h"


//------------------------------------------------------------------------------
// ----     Devices specific Definitions       ----
//-------------------------------------------------
#if defined __SAM3S1A__
  #include "SAM3S/SAM3S_FEATURES_4A.h"  //ERr
#elif defined __SAM3S1B__
  #include "SAM3S/SAM3S_FEATURES_4B.h"  //ERr
#elif defined __SAM3S1C__
  #include "SAM3S/SAM3S_FEATURES_4C.h"  //ERr
#elif defined __SAM3S2A__
  #include "SAM3S/SAM3S_FEATURES_4A.h"  //ERr
#elif defined __SAM3S2B__
  #include "SAM3S/SAM3S_FEATURES_4B.h"  //ERr
#elif defined __SAM3S2C__
  #include "SAM3S/SAM3S_FEATURES_4C.h"  //ERr
#elif defined __SAM3S4A__
  #include "SAM3S/SAM3S_FEATURES_4A.h"
#elif defined __SAM3S4B__
  #include "SAM3S/SAM3S_FEATURES_4B.h"
#elif defined __SAM3S4C__
  #include "SAM3S/SAM3S_FEATURES_4C.h"
// ------ SAM3S8 / SAM3SD8 ---------------
#elif defined __SAM3S8B__
  #include "SAM3S/SAM3S_FEATURES_4B.h"  //ERr
#elif defined __SAM3S8C__
  #include "SAM3S/SAM3S_FEATURES_4C.h"  //ERr
#elif defined __SAM3SD8B__
  #include "SAM3S/SAM3S_FEATURES_D8B.h"
#elif defined __SAM3SD8C__
  #include "SAM3S/SAM3S_FEATURES_D8C.h"
#else
  #error Library does not support the specified device.
#endif

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// ----       Core Definitions           ----
//-------------------------------------------
#define DEVICE_CORE_0_TYPE     CORE_TYPE_CM3
#define DEVICE_CORE_0_VERSION  0
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
//#define DEVICE_NB_INTERRUPTS ID_PERIPH_COUNT
#define DEVICE_NB_INTERRUPTS (35) // not defined in iSOCK headers
#define DEVICE_HAS_SUPC      1
#define DEVICE_HAS_AIC       0
//...
#define DEVICE_HAS_ACC       1
#define DEVICE_HAS_ADC       1
#define DEVICE_HAS_AES       0
#define DEVICE_HAS_CAN0      0
#define DEVICE_HAS_CAN1      0
#define DEVICE_HAS_CRCCU     1
#define DEVICE_HAS_DAC       1
#define DEVICE_HAS_DBGU      0
#define DEVICE_HAS_DMAC      0
#define DEVICE_HAS_EFC0      1
//#define DEVICE_HAS_EFC1      0
#define DEVICE_HAS_EMAC      0
#define DEVICE_HAS_GMAC      0
#define DEVICE_HAS_HSMCI0    1
#define DEVICE_HAS_HSMCI1    0
#define DEVICE_HAS_HSMCI2    0
#define DEVICE_HAS_ISI       0
#define DEVICE_HAS_LCDC      0
#define DEVICE_HAS_MPDDRC    0
#define DEVICE_HAS_PDC       1
#define DEVICE_HAS_PIOA      1
#define DEVICE_HAS_PIOB      1
//#define DEVICE_HAS_PIOC      1
#define DEVICE_HAS_PIOD      0
#define DEVICE_HAS_PIOE      0

#define DEVICE_HAS_PLLA      (1)
#define DEVICE_HAS_PLLB      (1)

#define DEVICE_HAS_PWM       1
#define DEVICE_HAS_RTC       1
#define DEVICE_HAS_RTT       1
#define DEVICE_HAS_SHA       0
#define DEVICE_HAS_SPI0      1
#define DEVICE_HAS_SPI1      0
#define DEVICE_HAS_SSC0      1
#define DEVICE_HAS_SSC1      0
#define DEVICE_HAS_TC0       1 // channels 0-2
//#define DEVICE_HAS_TC1       1 // channels 3-5
#define DEVICE_HAS_TC2       0 // channels 6-9
#define DEVICE_HAS_TC3       0
#define DEVICE_HAS_TDES      0
#define DEVICE_HAS_TRNG      0
#define DEVICE_HAS_TWI0      1
#define DEVICE_HAS_TWI1      1
#define DEVICE_HAS_TWI2      0
#define DEVICE_HAS_UART0     1
#define DEVICE_HAS_UART1     1
#define DEVICE_HAS_UDP       1
#define DEVICE_HAS_UHP       0
#define DEVICE_HAS_USART0    1
//#define DEVICE_HAS_USART1    1
//#define DEVICE_HAS_USART2    0
#define DEVICE_HAS_USART3    0
#define DEVICE_HAS_WDT       1
//...
#define DEVICE_HAS_CAN       DEVICE_HAS_CAN0
#define DEVICE_HAS_DACC      DEVICE_HAS_DAC // DAC=DACC
#define DEVICE_HAS_EFC       DEVICE_HAS_EFC0
#define DEVICE_HAS_HSMCI     DEVICE_HAS_HSMCI0
#define DEVICE_HAS_SPI       DEVICE_HAS_SPI0
#define DEVICE_HAS_SSC       DEVICE_HAS_SSC0
#define DEVICE_HAS_TWI       DEVICE_HAS_TWI0
#define DEVICE_HAS_UART      DEVICE_HAS_UART0
#define DEVICE_HAS_USART     DEVICE_HAS_USART0
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//
// ---- ADC ---------------------------------
//#define ADC_CHANNELS    (16)
#define ADC_HAS_PDC         (1)
#define ADC_HAS_TRIGGER_REG (0)
#define ADC_HAS_PROGRAMMABLE_GAIN (1) // CGR & COR registers
#define ADC_HAS_ACR_REG           (1) // TS(Temperature Sensor) & IBCTL fields
#define ADC_HAS_DUAL_TRIG         (0) // LCTMR & LCCWR registers
#define ADCMR_HAS_ANACH_FIELD    (1)
#define ADCMR_HAS_SETTLING_FIELD (1)
#define ADCMR_HAS_FWUP_FIELD     (1)
//-------------------------------------------

// ---- DAC ---------------------------------
#define DAC_HAS_PDC         (1)
#define DACC_HAS_PDC        (DAC_HAS_PDC)
//-------------------------------------------

// ---- HSMCI -------------------------------
#define HSMCI_HAS_PDC     (1)
#define HSMCI0_HAS_PDC    (HSMCI_HAS_PDC)
//--------------------------------------------

// ---- PIO ---------------------------------
#define PIO_HAS_PERIPH_A          (1)
#define PIO_HAS_PERIPH_B          (1)
#define PIO_HAS_PERIPH_C          (1)
#define PIO_HAS_PERIPH_D          (1)
#define PIO_HAS_PARALLEL_CAPTURE  (1)
#define PIO_HAS_PDC               (1)
//...
#define PIOA_HAS_PDC              (1)
#define PIOB_HAS_PDC              (0)
//#define PIOC_HAS_PDC              (0)
//-------------------------------------------

// ---- PMC ---------------------------------
#define PMC_HAS_MCKR_FIELD_MDIV     0
#define PMC_HAS_PLLA_TUNING         0

#define PLLA_INPUT_IS_SLOW_CK       (0)
//#define PLLA_INPUT_IS_MAIN_CK       (0)
#define PLLA_HAS_DIVIDER            (1)
//-------------------------------------------

// ---- PWM ---------------------------------
#define PWM_HAS_PDC        (1)
#define PWM_HAS_SMMR       (1)
#define PWM_HAS_FPV2       (0)
//--------------------------------------------

// ---- SPI ---------------------------------
#define SPI_HAS_PDC       (1)
#define SPI0_HAS_PDC      SPI_HAS_PDC
//--------------------------------------------

// ---- SSC ---------------------------------
#define SSC_HAS_PDC       (1)
#define SSC0_HAS_PDC      SSC_HAS_PDC
//--------------------------------------------

// ---- TC  ---------------------------------
//#define TC_CHANNELS       (6)
#define TC_BMR_HAS_FILTER  (1)
#define TC_HAS_SMMR        (1)
#define TC_HAS_QDEC        (1)
#define TC_HAS_WR_PROTECT  (1)
#define TC_HAS_PDC         (0)
//--------------------------------------------
#define TC0_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//#define TC1_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//--------------------------------------------
#define TC0_HAS_SMMR  TC_HAS_SMMR
//#define TC1_HAS_SMMR  TC_HAS_SMMR
//--------------------------------------------
#define TC0_HAS_QDEC  TC_HAS_QDEC
//#define TC1_HAS_QDEC  TC_HAS_QDEC
//--------------------------------------------
#define TC0_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//#define TC1_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//-------------------------------------------
#define TC0_HAS_PDC  TC_HAS_PDC
//#define TC1_HAS_PDC  TC_HAS_PDC
//-------------------------------------------

// ---- TWI ---------------------------------
#define TWI_HAS_PDC       (1)
#define TWI0_HAS_PDC      TWI_HAS_PDC
#define TWI1_HAS_PDC      TWI_HAS_PDC
//--------------------------------------------

// ---- UART --------------------------------
#define UART_HAS_PDC     (1)
#define UART0_HAS_PDC    (UART_HAS_PDC)
#define UART1_HAS_PDC    (UART_HAS_PDC)
//-------------------------------------------

// ---- USART -------------------------------
#define USART_HAS_PDC    (1)
#define USART0_HAS_PDC   (1)
//#define USART1_HAS_PDC   (1)
//#define USART2_HAS_PDC   (0)
//-------------------------------------------
//...
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----    Keys Definition         ----
//-------------------------------------
#define ACC_KEY_VAL    0x414343u
#define ADC_KEY_VAL    0x414443u
#define DACC_KEY_VAL   0x444143u
#define EFC_KEY_VAL    0x5Au
#define MATRIX_KEY_VAL 0x4D4154u
#define MOR_KEY_VAL    0x37u
#define PIO_KEY_VAL    0x50494Fu
#define PMC_KEY_VAL    0x504D43u
#define PWM_KEY_VAL    0x50574Du
#define RSTC_KEY_VAL   0xA5u
#define SMC_KEY_VAL    0x534D43u
#define SPI_KEY_VAL    0x535049u
#define SSC_KEY_VAL    0x535343u
#define SUPC_KEY_VAL   0xA5u  
#define TC_KEY_VAL     0x54494Du
#define TWI_KEY_VAL    0x545749u
#define USART_KEY_VAL  0x555341u
#define WDT_KEY_VAL    0xA5u
//------------------------------------------------------------------------------







//------------------------------------------------------------------------------
// ----     Global Definitions           ----
//-------------------------------------------
/*
#define CORE_TYPE_CA5    315
#define CORE_TYPE_CM3    3133
#define CORE_TYPE_CM4    3134
#define CORE_TYPE_ARM7   118137
#define CORE_TYPE_ARM9   118139
*/
//------------------------------------------------------------------------------

#endif //_FEATURES_SAM3Sxx_H