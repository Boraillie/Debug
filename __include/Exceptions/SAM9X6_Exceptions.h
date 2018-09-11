/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
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
 * \file
 * Interface for default exception handlers.
 */

#ifndef _SAM9X6_EXCEPTIONS_H
#define _SAM9X6_EXCEPTIONS_H

/*----------------------------------------------------------------------------
 *        Types
 *----------------------------------------------------------------------------*/

/* Function prototype for exception table items (interrupt handler). */
//typedef void( *IntFunc )( void ) ;



/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/* Cortex-A5 core handlers */
/*
*/
// SAMA5D2 exceptions
////extern void SYS_IrqHandler( void ) ;
////extern void Spurious_handler( void ) ;
////
/////* Peripherals handlers */
////extern void PIT_Handler( void );              /**<  3 SAMA5D27 Periodic Interval Timer Interrupt (PIT) */
////extern void WDT_Handler( void );              /**<  4 SAMA5D27 Watchdog timer Interrupt (WDT) */
////extern void GMAC_Handler( void );             /**<  5 SAMA5D27 Ethernet MAC (GMAC) */
////extern void XDMAC0_Handler( void );           /**<  6 SAMA5D27 DMA Controller 0 (XDMAC0) */
////extern void XDMAC1_Handler( void );           /**<  7 SAMA5D27 DMA Controller 1 (XDMAC1) */
////extern void ICM_Handler( void );              /**<  8 SAMA5D27 Integritry Check Monitor (ICM) */
////extern void AES_Handler( void );              /**<  9 SAMA5D27 Advanced Enion Standard (AES) */
////extern void AESB_Handler( void );             /**< 10 SAMA5D27 AES bridge (AESB) */
////extern void TDES_Handler( void );             /**< 11 SAMA5D27 Triple Data Enion Standard (TDES) */
////extern void SHA_Handler( void );              /**< 12 SAMA5D27 SHA Signature (SHA) */
////extern void MPDDRC_Handler( void );           /**< 13 SAMA5D27 MPDDR controller (MPDDRC) */
////extern void MATRIX1_Handler( void );          /**< 14 SAMA5D27 H32MX, 32-bit AHB Matrix (MATRIX1) */
////extern void MATRIX0_Handler( void );          /**< 15 SAMA5D27 H64MX, 64-bit AHB Matrix (MATRIX0) */
////extern void HSMC_Handler( void );             /**< 17 SAMA5D27 Multi-bit ECC Interrupt (HSMC) */
////extern void PIOA_Handler( void );             /**< 18 SAMA5D27 Parallel I/O Controller (PIOA) */
////extern void FLEXCOM0_Handler( void );         /**< 19 SAMA5D27 FLEXCOM 0 (FLEXCOM0) */
////extern void FLEXCOM1_Handler( void );         /**< 20 SAMA5D27 FLEXCOM 1 (FLEXCOM1) */
////extern void FLEXCOM2_Handler( void );         /**< 21 SAMA5D27 FLEXCOM 2 (FLEXCOM2) */
////extern void FLEXCOM3_Handler( void );         /**< 22 SAMA5D27 FLEXCOM 3 (FLEXCOM3) */
////extern void FLEXCOM4_Handler( void );         /**< 23 SAMA5D27 FLEXCOM 4 (FLEXCOM4) */
////extern void UART0_Handler( void );            /**< 24 SAMA5D27 UART 0 (UART0) */
////extern void UART1_Handler( void );            /**< 25 SAMA5D27 UART 1 (UART1) */
////extern void UART2_Handler( void );            /**< 26 SAMA5D27 UART 2 (UART2) */
////extern void UART3_Handler( void );            /**< 27 SAMA5D27 UART 3 (UART3) */
////extern void UART4_Handler( void );            /**< 28 SAMA5D27 UART 4 (UART4) */
////extern void TWIHS0_Handler( void );           /**< 29 SAMA5D27 Two-Wire Interface 0 (TWIHS0) */
////extern void TWIHS1_Handler( void );           /**< 30 SAMA5D27 Two-Wire Interface 1 (TWIHS1) */
////extern void SPI0_Handler( void );             /**< 33 SAMA5D27 Serial Peripheral Interface 0 (SPI0) */
////extern void SPI1_Handler( void );             /**< 34 SAMA5D27 Serial Peripheral Interface 1 (SPI1) */
////extern void TC0_Handler( void );              /**< 35 SAMA5D27 Timer Counter 0 (ch. 0, 1, 2) (TC0) */
////extern void TC1_Handler( void );              /**< 36 SAMA5D27 Timer Counter 1 (ch. 3, 4, 5) (TC1) */
////extern void PWM_Handler( void );              /**< 38 SAMA5D27 Pulse Width Modulation Controller0 (ch. 0, 1, 2, 3) (PWM) */
////extern void ADC_Handler( void );              /**< 40 SAMA5D27 Touch Screen ADC Controller (ADC) */
////extern void UHPHS_Handler( void );            /**< 41 SAMA5D27 USB Host High Speed (UHPHS) */
////extern void UDPHS_Handler( void );            /**< 42 SAMA5D27 USB Device High Speed (UDPHS) */
////extern void SSC0_Handler( void );             /**< 43 SAMA5D27 Synchronous Serial Controller 0 (SSC0) */
////extern void SSC1_Handler( void );             /**< 44 SAMA5D27 Synchronous Serial Controller 1 (SSC1) */
////extern void LCDC_Handler( void );             /**< 45 SAMA5D27 LCD Controller (LCDC) */
////extern void TRNG_Handler( void );             /**< 47 SAMA5D27 True Random Number Generator (TRNG) */
////extern void PDMIC_Handler( void );            /**< 48 SAMA5D27 Pulse Density Modulation Interface Controller (PDMIC) */
////extern void SFC_Handler( void );              /**< 50 SAMA5D27 Fuse Controller (SFC) */
////extern void QSPI0_Handler( void );            /**< 52 SAMA5D27 QSPI 0 (QSPI0) */
////extern void QSPI1_Handler( void );            /**< 53 SAMA5D27 QSPI 1 (QSPI1) */
////extern void I2SC0_Handler( void );            /**< 54 SAMA5D27 Inter-IC Sound Controller 0 (I2SC0) */
////extern void I2SC1_Handler( void );            /**< 55 SAMA5D27 Inter-IC Sound Controller 1 (I2SC1) */
////extern void PTC_Handler( void );              /**< 58 SAMA5D2 Peripheral Touch Controller (PTC) */
////extern void CLASSD_Handler( void );           /**< 59 SAMA5D27 Audio Class D amplifier (CLASSD) */
////extern void SFR_Handler( void );              /**< 60 SAMA5D27 Special Function Register  (SFR) */
////extern void SAIC_Handler( void );             /**< 61 SAMA5D27 Secured Advanced Interrupt Controller  (SAIC) */
////extern void AIC_Handler( void );              /**< 62 SAMA5D27 Advanced Interrupt Controller  (AIC) */
////extern void L2CC_Handler( void );             /**< 63 SAMA5D27 L2 Cache Controller (L2CC) */
////extern void PIOB_Handler( void );             /**< 68 SAMA5D27  (PIOB) */
////extern void PIOC_Handler( void );             /**< 69 SAMA5D27  (PIOC) */
////extern void PIOD_Handler( void );             /**< 70 SAMA5D27  (PIOD) */
////extern void ACC_Handler( void );              /**< 75 SAMA5D27 Analog Comparator (ACC) */
////extern void RXLP_Handler( void );             /**< 76 SAMA5D27 Uart Low Power (RXLP) */
////extern void CHIPID_Handler( void );           /**< 78 SAMA5D27 Chip ID (CHIPID) */
            
//SAM9X6 SAM926 Handlers

  extern void SYSC_Handler( void );        /**<  1 SAM9X6 Sys */
  extern void PIOA_Handler( void );        /**<  2 SAM9X6 Pioa */
  extern void PIOB_Handler( void );        /**<  3 SAM9X6 Piob */
  extern void PIOC_Handler( void );        /**<  4 SAM9X6 Pioc */
  extern void FLEXCOM0_Handler( void );    /**<  5 SAM9X6 FLEXCOM0 */
  extern void FLEXCOM1_Handler( void );    /**<  6 SAM9X6 FLEXCOM1 */
  extern void FLEXCOM2_Handler( void );    /**<  7 SAM9X6 FLEXCOM2 */
  extern void FLEXCOM3_Handler( void );    /**<  8 SAM9X6 FLEXCOM3 */
  extern void FLEXCOM6_Handler( void );    /**<  9 SAM9X6 FLEXCOM6 */
  extern void FLEXCOM7_Handler( void );    /**< 10 SAM9X6 FLEXCOM7 */
  extern void FLEXCOM8_Handler( void );    /**< 11 SAM9X6 FLEXCOM8 */
  extern void SDMMC0_Handler( void );      /**< 12 SAM9X6 SDMMC0 */
  extern void FLEXCOM4_Handler( void );    /**< 13 SAM9X6 FLEXCOM4 */
  extern void FLEXCOM5_Handler( void );    /**< 14 SAM9X6 FLEXCOM5 */
  extern void FLEXCOM9_Handler( void );    /**< 15 SAM9X6 FLEXCOM9 */
  extern void FLEXCOM10_Handler( void );   /**< 16 SAM9X6 FLEXCOM10 */
  extern void TC0_Handler( void );         /**< 17 SAM9X6 TC0 */
  extern void PWM_Handler( void );         /**< 18 SAM9X6 PWM */
  extern void ADC_Handler( void );         /**< 19 SAM9X6 ADC */
  extern void XDMAC_Handler( void );       /**< 20 SAM9X6 XDMAC */
  extern void MATRIX_Handler( void );      /**< 21 SAM9X6 MATRIX */
  extern void UHPHS_Handler( void );       /**< 22 SAM9X6 UHPHS */
  extern void UDPHS_Handler( void );       /**< 23 SAM9X6 UDPHS */
  extern void EMAC0_Handler( void );       /**< 24 SAM9X6 EMAC0 */
  extern void LCDC_Handler( void );        /**< 25 SAM9X6 LCDC */
  extern void SDMMC1_Handler( void );      /**< 26 SAM9X6 SDMMC1 */
  extern void EMAC1_Handler( void );       /**< 27 SAM9X6 EMAC1 */
  extern void SSC_Handler( void );         /**< 28 SAM9X6 SSC */
  extern void CAN0_Handler( void );        /**< 29 SAM9X6 CAN0 */
  extern void CAN1_Handler( void );        /**< 30 SAM9X6 CAN1 */

  extern void FLEXCOM11_Handler( void );   /**< 32 SAM9X6 FLEXCOM11 */
  extern void FLEXCOM12_Handler( void );   /**< 33 SAM9X6 FLEXCOM12 */
  extern void I2SMCC_Handler( void );      /**< 34 SAM9X6 I2SMCC */
  extern void QSPI_Handler( void );        /**< 35 SAM9X6 QSPI */
  extern void GFX2D_Handler( void );       /**< 36 SAM9X6 GFX2D */
  extern void PIT64B_Handler( void );      /**< 37 SAM9X6 PIT64B */
  extern void TRNG_Handler( void );        /**< 38 SAM9X6 TRNG */
  extern void AES_Handler( void );         /**< 39 SAM9X6 AES */
  extern void TDES_Handler( void );        /**< 40 SAM9X6 TDES */
  extern void SHA_Handler( void );         /**< 41 SAM9X6 SHA */
  extern void CLASSD_Handler( void );      /**< 42 SAM9X6 CLASSD */
  extern void ISI_Handler( void );         /**< 43 SAM9X6 ISI */
  extern void PIOD_Handler( void );        /**< 44 SAM9X6 PIOD */
  extern void TC1_Handler( void );         /**< 45 SAM9X6 TC1 */
  extern void OTPC_Handler( void );        /**< 46 SAM9X6 OTPC */
  extern void DBGU_Handler( void );        /**< 47 SAM9X6 DBGU */
  extern void PMECC_Handler( void );       /**< 48 SAM9X6 PMECC */
  extern void SDRAM_Handler( void );       /**< 49 SAM9X6 SDRAM */
  
  extern void Spurious_handler( void );


#endif //_SAM9X6_EXCEPTIONS_H
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            