/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*/

//!
// \file FEAUTURES_CAPELLA.h
// \brief File containing CAPELLA device features
// \author AYi
// \version 0.1
// \date 12 Feb 2016
//
// Detailed description
// \todo Files imorted from canopus. must be reviewed 
//!

#ifndef _FEATURES_CAPELLA_H
#define _FEATURES_CAPELLA_H


#include "global.h"


//------------------------------------------------------------------------------
// ----     VDE specific Definitions       ----
//---------------------------------------------
//------------------------------------------------------------------------------
// M7: no I-cache / best case alignment / 1 iter = 4 instr (IAR compiler...) 
#define WAIT_LOOP_ITER_CYCLES (2)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----     Devices specific Definitions       ----
//-------------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----       Core Definitions           ----
//-------------------------------------------
#define DEVICE_CORE_0_TYPE     CORE_TYPE_CM7
#define DEVICE_CORE_0_VERSION  0
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_NB_INTERRUPTS ID_PERIPH_COUNT
#define DEVICE_HAS_SUPC      (1)
#define DEVICE_HAS_AIC       (0)
//...
#define DEVICE_HAS_ACC       (1)
#define DEVICE_HAS_ADC       (1)
#define DEVICE_HAS_AES       (1)
#define DEVICE_HAS_CAN0      (1)
#define DEVICE_HAS_CAN1      (1)
#define DEVICE_HAS_CRCCU     (0)
#define DEVICE_HAS_DAC       (1)
#define DEVICE_HAS_DBGU      (1)
#define DEVICE_HAS_DMAC      (0) // changing to be compatible with updated sfot pack software
#define DEVICE_HAS_EFC0      (1)
#define DEVICE_HAS_EFC1      (0)
#define DEVICE_HAS_EMAC      (0)
#define DEVICE_HAS_GMAC      (1)
#define DEVICE_HAS_HSMCI0    (1)
#define DEVICE_HAS_HSMCI1    (0)
#define DEVICE_HAS_HSMCI2    (0)

//#define DEVICE_HAS_I2SC      (0)
#define DEVICE_HAS_I2SC0     (1)//added MNn 5/9/'16
#define DEVICE_HAS_I2SC1     (1)//added MNn 5/9/'16

#define DEVICE_HAS_ISI       (1)
#define DEVICE_HAS_LCDC      (1)//added MNn 5/9/'16
#define DEVICE_HAS_MPDDRC    (0)
#define DEVICE_HAS_PDC       (0)

//#define DEVICE_HAS_PDMIC      (0)
#define DEVICE_HAS_PDMIC0    (1)//added MNn 5/9/'16
#define DEVICE_HAS_PDMIC1    (1)//added MNn 5/9/'16

#define DEVICE_HAS_PIOA      (1)
#define DEVICE_HAS_PIOB      (1)
#define DEVICE_HAS_PIOC      (1)
#define DEVICE_HAS_PIOD      (1)
#define DEVICE_HAS_PIOE      (1)

#define DEVICE_HAS_PLLA      (1)
#define DEVICE_HAS_PLLB      (0)  // 1 but let 0 waiting to correct some lib files to support pllb 
#define DEVICE_HAS_UPLL      (1)
#define DEVICE_HAS_APLL      (1)

#define DEVICE_HAS_PWM       (1)
#define DEVICE_HAS_RTC       (1)
#define DEVICE_HAS_RTT       (1)
#define DEVICE_HAS_SHA       (1)//added MNn 5/9/'16
#define DEVICE_HAS_SPI0      (1)
#define DEVICE_HAS_SPI1      (1)
#define DEVICE_HAS_SSC0      (1)
#define DEVICE_HAS_SSC1      (0)

#define DEVICE_HAS_SUPC      (1)

#define DEVICE_HAS_TC0       (1) 
#define DEVICE_HAS_TC1       (1) 
#define DEVICE_HAS_TC2       (1)
#define DEVICE_HAS_TC3       (1)
#define DEVICE_HAS_TC4       (0)
#define DEVICE_HAS_TC5       (0)
#define DEVICE_HAS_TDES      (0)
#define DEVICE_HAS_TRNG      (1)
#define DEVICE_HAS_TWI0      (1)
#define DEVICE_HAS_TWI1      (1)
#define DEVICE_HAS_TWI2      (1)
#define DEVICE_HAS_UART0     (0)//was 1 MNN
#define DEVICE_HAS_UART1     (0)//was 1 MNN
#define DEVICE_HAS_UART2     (0)
#define DEVICE_HAS_UART3     (0)
#define DEVICE_HAS_UDP       (1)
#define DEVICE_HAS_UHP       (1)
#define DEVICE_HAS_USART0    (1)
#define DEVICE_HAS_USART1    (1)
#define DEVICE_HAS_USART2    (1)
#define DEVICE_HAS_USART3    (1)//was 0 MNN
#define DEVICE_HAS_USART4    (1)
#define DEVICE_HAS_USART5    (1)
#define DEVICE_HAS_USART6    (1)
#define DEVICE_HAS_USART7    (1)
#define DEVICE_HAS_USART8    (1)
#define DEVICE_HAS_USART9    (1)

#define DEVICE_HAS_WDT       (1)
#define DEVICE_HAS_FLEXCOM   (1)
//...
#define DEVICE_HAS_CAN       DEVICE_HAS_CAN0
#define DEVICE_HAS_DACC      DEVICE_HAS_DAC // DAC=DACC
#define DEVICE_HAS_EFC       DEVICE_HAS_EFC0
#define DEVICE_HAS_HSMCI     DEVICE_HAS_HSMCI0
#define DEVICE_HAS_I2SC      DEVICE_HAS_I2SC0
#define DEVICE_HAS_PDMIC     DEVICE_HAS_PDMIC0
#define DEVICE_HAS_SPI       DEVICE_HAS_SPI0
#define DEVICE_HAS_SSC       DEVICE_HAS_SSC0
#define DEVICE_HAS_TWI       DEVICE_HAS_TWI0
#define DEVICE_HAS_UART      DEVICE_HAS_UART0
#define DEVICE_HAS_USART     DEVICE_HAS_USART0

#define DEVICE_HAS_XDMAC    (1)  // adding xdmac definition for softpack software compatibility

//New additions MNn 5/9/'16
#define DEVICE_HAS_CAN2      (1)
#define DEVICE_HAS_CAN3      (1)
#define DEVICE_HAS_PDMIC2    (1)
#define DEVICE_HAS_PDMIC3    (1)
#define DEVICE_HAS_GCLK      (1)


//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//
// ---- ADC ---------------------------------
#define ADC_CHANNELS    	(16)  //updated from to 12 to 16 MNn 5/9/16
#define ADC_HAS_PDC         	(0)
#define ADC_HAS_TRIGGER_REG 	(0)
//-------------------------------------------

// ---- DAC ---------------------------------
//-------------------------------------------
// ---- I2SC --------------------------------
//#define I2SC_HAS_PDC         (1)
#define I2SC0_HAS_PDC         (0)
#define I2SC1_HAS_PDC         (0)
//-------------------------------------------

// ---- MATRIX ------------------------------
#define MATRIX_NB_MASTERS         (12)
#define MATRIX_NB_SLAVES          (9)
//-------------------------------------------

// ---- PDMIC -------------------------------
//#define PDMIC_HAS_PDC         (1)
#define PDMIC0_HAS_PDC         (0)
#define PDMIC1_HAS_PDC         (0)
//-------------------------------------------

// ---- PIO ---------------------------------
#define DEVICE_HAS_PIOV4          (1) 

#define PIO_HAS_PERIPH_A          (1)
#define PIO_HAS_PERIPH_B          (1)
#define PIO_HAS_PERIPH_C          (1) 
#define PIO_HAS_PERIPH_D          (1)
#define PIO_HAS_PERIPH_E          (1)
#define PIO_HAS_PERIPH_F          (1)
#define PIO_HAS_PERIPH_G          (1)
#define PIO_HAS_PARALLEL_CAPTURE  (0)
#define PIO_HAS_PDC               (0)
#define PIO_HAS_TAMPER_CONFIG     (1)
//...
#define PIOA_HAS_PDC    (PIO_HAS_PDC)
#define PIOB_HAS_PDC    (PIO_HAS_PDC)
//-------------------------------------------

// ---- PMC ---------------------------------
#define PMC_HAS_MCKR_FIELD_MDIV     (1)
#define PMC_HAS_PLLA_TUNING         (0)
#define PMC_HAS_PCR_NO_MORE_PCxR    (1)
//#define PLLA_INPUT_IS_SLOW_CK       (0)

#define PLLA_INPUT_IS_SLOW_CK       (0)
#define PLLA_INPUT_IS_MAIN_CK       (1)
#define PLLA_HAS_DIVIDER            (1)
//-------------------------------------------

// ---- SPI ---------------------------------
#define SPI_HAS_PDC       (0)
#define SPI0_HAS_PDC      SPI_HAS_PDC
// ------------
#define SPI_IS_FLEXCOM (1)
#define SPI0_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI1_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI2_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI3_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI4_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI5_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI6_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI7_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI8_IS_FLEXCOM SPI_IS_FLEXCOM
#define SPI9_IS_FLEXCOM SPI_IS_FLEXCOM
//--------------------------------------------


// ---- SUPC ---------------------------------
#define SUPC_HAS_MONITORING_DOMAIN  (1)
//--------------------------------------------


// ---- TC  ---------------------------------
#define TC_CHANNELS       (12)
#define TC_BMR_HAS_FILTER  (0)
#define TC_HAS_SMMR        (1)
#define TC_HAS_QDEC        (1) 
#define TC_HAS_WR_PROTECT  (1)
#define TC_HAS_PDC         (0)
//--------------------------------------------
#define TC0_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
#define TC1_BMR_HAS_FILTER  TC_BMR_HAS_FILTER
//--------------------------------------------
#define TC0_HAS_SMMR  TC_HAS_SMMR
#define TC1_HAS_SMMR  TC_HAS_SMMR
//--------------------------------------------
#define TC0_HAS_QDEC  TC_HAS_QDEC
#define TC1_HAS_QDEC  TC_HAS_QDEC
//--------------------------------------------
#define TC0_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
#define TC1_HAS_WR_PROTECT  TC_HAS_WR_PROTECT
//-------------------------------------------
#define TC0_HAS_PDC  (0)
#define TC1_HAS_PDC  (0)
//-------------------------------------------


// ---- TWI ---------------------------------
#define TWI_HAS_PDC       (0)
#define TWI0_HAS_PDC      TWI_HAS_PDC
#define TWI1_HAS_PDC      TWI_HAS_PDC
#define TWI2_HAS_PDC      TWI_HAS_PDC
// ------------
#define TWI_IS_FLEXCOM (1)
#define TWI0_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI1_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI2_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI3_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI4_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI5_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI6_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI7_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI8_IS_FLEXCOM TWI_IS_FLEXCOM
#define TWI9_IS_FLEXCOM TWI_IS_FLEXCOM
//--------------------------------------------

// ---- UART --------------------------------
/*#define UART_HAS_PDC     (0)
#define UART0_HAS_PDC    (0)
#define UART1_HAS_PDC    (0)
// ------------
#define UART_IS_FLEXCOM (1)
#define UART0_IS_FLEXCOM UART_IS_FLEXCOM
#define UART1_IS_FLEXCOM UART_IS_FLEXCOM
#define UART2_IS_FLEXCOM UART_IS_FLEXCOM
#define UART3_IS_FLEXCOM UART_IS_FLEXCOM
//#define UART4_IS_FLEXCOM UART_IS_FLEXCOM
//-------------------------------------------
*/
// ---- USART -------------------------------
#define USART_HAS_PDC    (0)
#define USART0_HAS_PDC   (USART_HAS_PDC)
// ------------
#define USART_IS_FLEXCOM (1)
#define USART0_IS_FLEXCOM USART_IS_FLEXCOM
#define USART1_IS_FLEXCOM USART_IS_FLEXCOM
#define USART2_IS_FLEXCOM USART_IS_FLEXCOM
#define USART3_IS_FLEXCOM USART_IS_FLEXCOM
#define USART4_IS_FLEXCOM USART_IS_FLEXCOM
#define USART5_IS_FLEXCOM USART_IS_FLEXCOM
#define USART6_IS_FLEXCOM USART_IS_FLEXCOM
#define USART7_IS_FLEXCOM USART_IS_FLEXCOM
#define USART8_IS_FLEXCOM USART_IS_FLEXCOM
#define USART9_IS_FLEXCOM USART_IS_FLEXCOM


//#define USART4_IS_FLEXCOM USART_IS_FLEXCOM
//TODO : All uart are flexcom
//-------------------------------------------

//-------------------------------------------
//...
//------------------------------------------------------------------------------





//------------------------------------------------------------------------------
// ----    Keys Definition         ---- //
//-------------------------------------
// ERr: definitions to check
#define ACC_KEY_VAL             0x414343u //datasheet OK
#define ADC_KEY_VAL             0x414443u //datasheet OK
#define EFC_KEY_VAL             0x5Au //datasheet OK
#define MATRIX_KEY_VAL          0x4D4154u //datasheet OK
#define MOR_KEY_VAL             0x37u //datasheet OK
#define PIO_KEY_VAL             0x50494Fu //datasheet OK
#define PMC_KEY_VAL             0x504D43u //datasheet OK
#define PWM_KEY_VAL             0x50574Du //datasheet OK
#define RSTC_KEY_VAL            0xA5u//datasheet OK
#define SMC_KEY_VAL             0x534D43u //datasheet OK
#define SPI_KEY_VAL             0x535049u //datasheet OK
#define SSC_KEY_VAL             0x535343u //datasheet OK
#define SUPC_KEY_VAL            0xA5u  //datasheet OK
#define TC_KEY_VAL              0x54494Du //datasheet OK
#define TWI_KEY_VAL             0x545749u //datasheet OK
#define USART_KEY_VAL           0x555341u //datasheet OK
#define WDT_KEY_VAL             0xA5u //datasheet OK
#define SCB_VECTKEY_VAL        0xFA05u //????
#define SYSC_WPKEY_VAL        0x525443u //datasheet OK
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

#endif //_FEATURES_CAPELLA_H
