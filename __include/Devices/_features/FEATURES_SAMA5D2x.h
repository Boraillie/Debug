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
#ifndef _FEATURES_SAMA5D2x_H
#define _FEATURES_SAMA5D2x_H

#include "global.h"


//------------------------------------------------------------------------------
// ----       Core Definitions           ----
//-------------------------------------------
#define DEVICE_CORE_0_TYPE     CORE_TYPE_CA5
#define DEVICE_CORE_0_VERSION  0
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_NB_INTERRUPTS ID_PERIPH_COUNT
#define DEVICE_HAS_SUPC      0  // SUPply Controller
#define DEVICE_HAS_AIC       1  // Advanced Interrupt Controller
#define DEVICE_HAS_SAIC      1  // Secure Advanced Interrupt Controller
//...
#define DEVICE_HAS_ACC       1  // Analog Comparator Controller
#define DEVICE_HAS_ADC       1  // Analog to Digital Converter
#define DEVICE_HAS_AES       1  // Advanced Encryption Standard
#define DEVICE_HAS_CAN0      0  // Controller Area Network 0
#define DEVICE_HAS_CAN1      0  // Controller Area Network 1
#define DEVICE_HAS_CHIPID    1  // Chip Identifier
#define DEVICE_HAS_DAC       0  // Digital to Analog Converter
#define DEVICE_HAS_DBGU      1  // DeBuG Unit
//#define DEVICE_HAS_DMAC      1  // D-type Medium Access Control
#define DEVICE_HAS_DMAC0     0  // D-type Medium Access Control 0
#define DEVICE_HAS_DMAC1     0  // D-type Medium Access Control 1
#define DEVICE_HAS_EFC0      0  // Enhanced Flash Controller 0
#define DEVICE_HAS_EFC1      0  // Enhanced Flash Controller 1
//#define DEVICE_HAS_EMAC      1  // E-type 
#define DEVICE_HAS_GMAC      1  // G-type Medium Access Control
#define DEVICE_HAS_HSMCI0    0
#define DEVICE_HAS_HSMCI1    0
//#define DEVICE_HAS_HSMCI2    1
#define DEVICE_HAS_ISI       1 // Image Sensor Interface (name may change)
#define DEVICE_HAS_LCDC      0 // Liquid Crystal Display Controller
#define DEVICE_HAS_MPDDRC    1 // Multi-Port DDR (SDRAM) Controller
//#define DEVICE_HAS_PDC       0  // Peripheral DMA Controller
#define DEVICE_HAS_PIOA     1  // general Purpose Input Output Group A
#define DEVICE_HAS_PIOB     1  // general Purpose Input Output Group B
#define DEVICE_HAS_PIOC     1  // general Purpose Input Output Group C
#define DEVICE_HAS_PIOD     1  // general Purpose Input Output Group D
#define DEVICE_HAS_PIOE     0  // general Purpose Input Output Group E
#define DEVICE_HAS_PWM      1  // Pulse Width Modulation
#define DEVICE_HAS_RTC      1  // Real Time Clock
#define DEVICE_HAS_RTT      0  // Real Time Timer
#define DEVICE_HAS_SCKC     1  // Slow clock controler
#define DEVICE_HAS_SHA      1  // SHA Signature
#define DEVICE_HAS_SPI0     1  // Serial Protocol Interface 0
#define DEVICE_HAS_SPI1     1  // Serial Protocol Interface 1
#define DEVICE_HAS_SPI2     1  // Serial Protocol Interface 2
#define DEVICE_HAS_SSC0     1  // Synchronous Serial Controller 0
#define DEVICE_HAS_SSC1     1  // Synchronous Serial Controller 1
#define DEVICE_HAS_TC0      1  // Timer Counter 0
#define DEVICE_HAS_TC1      1  // Timer Counter 1
#define DEVICE_HAS_TC2      0  // Timer Counter 2
#define DEVICE_HAS_TC3      0  // Timer Counter 3
#define DEVICE_HAS_TC4      0  // Timer Counter 4
#define DEVICE_HAS_TC5      0  // Timer Counter 5
#define DEVICE_HAS_TC6      0  // Timer Counter 6
#define DEVICE_HAS_TC7      0  // Timer Counter 7
#define DEVICE_HAS_TC8      0  // Timer Counter 8
#define DEVICE_HAS_TDES     1  // Triple DES
#define DEVICE_HAS_TRNG     1  // True Random Generator
#define DEVICE_HAS_TWI0     0  // Two Wire Interface 0
#define DEVICE_HAS_TWI1     0  // Two Wire Interface 1
#define DEVICE_HAS_TWI2     0  // Two Wire Interface 2
#define DEVICE_HAS_TWI3     0  // Two Wire Interface 3
#define DEVICE_HAS_TWIHS0   1  // High-Speed Two Wire Interface 0
#define DEVICE_HAS_TWIHS1   1  // High-Speed Two Wire Interface 1
#define DEVICE_HAS_UART0    1  // Universal Asynchronous Receiver Transceiver 0
#define DEVICE_HAS_UART1    1  // Universal Asynchronous Receiver Transceiver 1
#define DEVICE_HAS_UART2    1  // Universal Asynchronous Receiver Transceiver 2
#define DEVICE_HAS_UART3    1  // Universal Asynchronous Receiver Transceiver 3
//#define DEVICE_HAS_UART4    1  // Universal Asynchronous Receiver Transceiver 4
#define DEVICE_HAS_UDP      1  // USB Device (High Speed)
#define DEVICE_HAS_UHP      1  // USB Host   (High Speed)
#define DEVICE_HAS_USART0   1  // Universal Synchronous/Asynchronous Receiver Transceiver 0 (mapped to FLEXCOM0 by software wrapper)
#define DEVICE_HAS_USART1   1  // Universal Synchronous/Asynchronous Receiver Transceiver 1 (mapped to FLEXCOM1 by software wrapper)
#define DEVICE_HAS_USART2   1  // Universal Synchronous/Asynchronous Receiver Transceiver 2 (mapped to FLEXCOM2 by software wrapper)
#define DEVICE_HAS_USART3   1  // Universal Synchronous/Asynchronous Receiver Transceiver 3 (mapped to FLEXCOM3 by software wrapper)
//#define DEVICE_HAS_USART4   1  // Universal Synchronous/Asynchronous Receiver Transceiver 4 (mapped to FLEXCOM4 by software wrapper)
#define DEVICE_HAS_WDT      1  // WatchDog Timer
#define DEVICE_HAS_FLEXCOM  1  // operates as USART or SPI or TWI (not same version as SAMG55)
#define DEVICE_HAS_PIOV4    1  // PIO controller complies with PIOv4 user interface 
//...
#define DEVICE_HAS_CAN       DEVICE_HAS_CAN0
#define DEVICE_HAS_DMAC      DEVICE_HAS_DMAC0
#define DEVICE_HAS_HSMCI     DEVICE_HAS_HSMCI0
#define DEVICE_HAS_SPI       DEVICE_HAS_SPI0
#define DEVICE_HAS_SSC       DEVICE_HAS_SSC0
#define DEVICE_HAS_TC        DEVICE_HAS_TC0
#define DEVICE_HAS_TWI       DEVICE_HAS_TWI0
#define DEVICE_HAS_TWIHS     DEVICE_HAS_TWIHS0
#define DEVICE_HAS_UART      DEVICE_HAS_UART0
#define DEVICE_HAS_USART     DEVICE_HAS_USART0
#define DEVICE_HAS_GCLK     (0)

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//
// ---- ADC ---------------------------------
#define ADC_CHANNELS        (12)
#define ADC_HAS_PDC         (0)
#define ADC_HAS_TRIGGER_REG (1)
//-------------------------------------------

// ---- DBGU --------------------------------
#define DBGU_HAS_PDC     0
//-------------------------------------------

// ---- HSMCI -------------------------------
#define HSMCI_HAS_PDC     (0)
#define HSMCI0_HAS_PDC    (HSMCI_HAS_PDC)
#define HSMCI1_HAS_PDC    (HSMCI_HAS_PDC)
//#define HSMCI2_HAS_PDC    (HSMCI_HAS_PDC)
//--------------------------------------------

// ---- PIO ---------------------------------
#define PIO_HAS_PERIPH_A  1
#define PIO_HAS_PERIPH_B  1
#define PIO_HAS_PERIPH_C  1
#define PIO_HAS_PERIPH_D  1
#define PIO_HAS_PERIPH_E  1
#define PIO_HAS_PERIPH_F  1
#define PIO_HAS_PERIPH_G  0
#define PIO_HAS_PERIPH_H  0
#define PIO_HAS_PERIPH_I  0
#define PIO_HAS_PERIPH_J  0
#define PIO_HAS_PARALLEL_CAPTURE (0)
#define PIO_HAS_TAMPER_CONFIG (0)
//-------------------------------------------

// ---- PMC ---------------------------------
#define PMC_HAS_MCKR_FIELD_MDIV     1
#define PMC_HAS_PCR_NO_MORE_PCxR    1 // can no more perform Peripheral Clocks settings in parallel
#define PMC_HAS_PLLA_TUNING         1 // defined in datasheet ; to be double checked...
#define PLLA_INPUT_IS_SLOW_CK       0

// ************ PLLA TUNING *****************
// (electrical characteristics dependant)
#define PMC_HAS_PLLAR_FIELD_OUTA    1
#define PMC_HAS_REG_PLLICPR         1
//#define PLLA_TUNING_F_LOW   400000000
//#define PLLA_TUNING_F_HIGH  800000000
//#define PLLA_TUNING_F_STEP   50000000
// ******************************************

// **************** PLLICPR *****************
// (electrical characteristics dependant)
// ******************************************

// ---- PWM ---------------------------------
#define PWM_HAS_PDC        (0)
#define PWM_HAS_SMMR       (1)
#define PWM_HAS_FPV2       (1)
//--------------------------------------------

// ---- RSTC----------------------------------
#define NRST_IS_INPUT_ONLY (1)
//--------------------------------------------

// ---- SCKC ---------------------------------
#define SLOW_OSC_ALWAYS_ON      (1)
#define SLOW_OSC_HAS_NO_BYPASS  (1)
#define SLOW_RC_ALWAYS_ON       (1)
//--------------------------------------------

// ---- SPI ----------------------------------
#define SPI_HAS_PDC       (0)
#define SPI0_HAS_PDC      SPI_HAS_PDC
#define SPI1_HAS_PDC      SPI_HAS_PDC
// ------------
#define SPI_IS_FLEXCOM (0)
#define SPI0_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI1_IS_FLEXCOM SPI_IS_FLEXCOM
//--------------------------------------------

// ---- SSC ----------------------------------
#define SSC_HAS_PDC       (0)
#define SSC0_HAS_PDC      SSC_HAS_PDC
#define SSC1_HAS_PDC      SSC_HAS_PDC
//--------------------------------------------

// ---- TC  ---------------------------------
//#define TC_CHANNELS        (9)
#define TC_BMR_HAS_FILTER  (1)
#define TC_HAS_SMMR        (1)
//#define TC_HAS_QDEC        (1)
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
#define TWI_HAS_PDC       (0)
#define TWI0_HAS_PDC      TWI_HAS_PDC
#define TWI1_HAS_PDC      TWI_HAS_PDC
//--------------------------------------------

// ---- UART --------------------------------
#define UART_HAS_PDC     (0)
#define UART0_HAS_PDC    (UART_HAS_PDC)
#define UART1_HAS_PDC    (UART_HAS_PDC)
#define UART2_HAS_PDC    (UART_HAS_PDC)
#define UART3_HAS_PDC    (UART_HAS_PDC)
//#define UART4_HAS_PDC    (UART_HAS_PDC)
// ------------
#define UART_IS_FLEXCOM (0)
#define UART0_IS_FLEXCOM UART_IS_FLEXCOM
#define UART1_IS_FLEXCOM UART_IS_FLEXCOM
#define UART2_IS_FLEXCOM UART_IS_FLEXCOM
#define UART3_IS_FLEXCOM UART_IS_FLEXCOM
//#define UART4_IS_FLEXCOM UART_IS_FLEXCOM
//-------------------------------------------


// ---- USART -------------------------------
#define USART_HAS_PDC    (0)
#define USART0_HAS_PDC   (USART_HAS_PDC)
#define USART1_HAS_PDC   (USART_HAS_PDC)
#define USART2_HAS_PDC   (USART_HAS_PDC)
#define USART3_HAS_PDC   (USART_HAS_PDC)
//#define USART4_HAS_PDC   (USART_HAS_PDC)
// ------------
#define USART_IS_FLEXCOM (1)
#define USART0_IS_FLEXCOM USART_IS_FLEXCOM
#define USART1_IS_FLEXCOM USART_IS_FLEXCOM
#define USART2_IS_FLEXCOM USART_IS_FLEXCOM
#define USART3_IS_FLEXCOM USART_IS_FLEXCOM
//#define USART4_IS_FLEXCOM USART_IS_FLEXCOM
//-------------------------------------------

//...
//-------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----    Keys Definition         ----
//-------------------------------------

#define WDT_KEY_VAL    (WDT_CR_KEY_PASSWD >> WDT_CR_KEY_Pos)     // required by v_drivers/v_wdt.c
#define MOR_KEY_VAL    (CKGR_MOR_KEY_PASSWD >> CKGR_MOR_KEY_Pos) // required by some asf/pmc.c
#define SPI_KEY_VAL    (SPI_WPMR_WPKEY_PASSWD >> SPI_WPMR_WPKEY_Pos) //used in prg_monitor.c
/*
#define ADC_KEY_VAL    (0x414443u)
#define AIC_KEY_VAL    (0x414943u)
#define MATRIX_KEY_VAL (0x4D4154u)
#define PIO_KEY_VAL    (0x50494Fu)
#define PMC_KEY_VAL    (0x504D43u)
#define PWM_KEY_VAL    (0x50574Du)
#define RSTC_KEY_VAL   (0xA5u)
#define SHDW_KEY_VAL   (0xA5u)
#define SMC_KEY_VAL    (0x534D43u)
#define SSC_KEY_VAL    (0x535343u)
////#define SUPC_KEY_VAL   0xA5u  
#define TC_KEY_VAL     (0x54494Du)
#define TWI_KEY_VAL    (0x545749u)
#define TRNG_KEY_VAL   (0x524E47u)
#define USART_KEY_VAL  (0x555341u)
*/
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----     Devices specific Definitions       ----
//-------------------------------------------------
#if defined __SAMA5D21__
  #include "SAMA5D2/SAMA5D21_FEATURES.h"
#elif defined __SAMA5D22__
  #include "SAMA5D2/ SAMA5D22_FEATURES.h"
#elif defined __SAMA5D23__
  #include "SAMA5D2/SAMA5D23_FEATURES.h"
#elif defined __SAMA5D24__
  #include "SAMA5D2/SAMA5D24_FEATURES.h"
#elif defined __SAMA5D26__
  #include "SAMA5D2/SAMA5D26_FEATURES.h"
#elif defined __SAMA5D27__
  #include "SAMA5D2/SAMA5D27_FEATURES.h"
#elif defined __SAMA5D28__
  #include "SAMA5D2/SAMA5D28_FEATURES.h"
#else
  #error Library does not support the specified device.
#endif

#endif //_FEATURES_SAMA5D2x_H
