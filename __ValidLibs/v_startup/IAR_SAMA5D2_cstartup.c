/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
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
// Based on IAR software example
// Updated for SOC : ERr / 08/2011


// ------ Compatibility list (compliant devices) ------------------------------

// ---------------------- (file created for ISLERO) ----------------------------
//-----------------------------------------------------------------------------


#include "project.h"


// ---- General purpose include files
#include "device.h"
//#include "board.h"
#include "exceptions.h"


// ---- Validation libraries
#include "v_startup\v_mmu.h"
#include "v_startup\v_core.h"

#warning Files to rewrite and merge with asm cstartup 
//------------------------------------------------------------------------------
typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Prototypes (forward declarations)--------------------------------------------
//------------------------------------------------------------------------------
extern void IT_Init(void);
extern void Secure_IT_Init(void);
extern void clock_config(void);
extern void sram_remap(void);
extern void Dummy_Handler(void);
extern int  __low_level_init( void );
extern void main( void );
extern void __iar_program_start( void );
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
/// This is the code that gets called on processor reset. To initialize the
/// device.
//------------------------------------------------------------------------------
int __low_level_init( void )
{  
  //v_EnableICache();// Instruction Cache enable
  // Instruction Cache disable
  v_DisableICache();
  
  // Perform SRAM remap at address 0x0
#ifndef __SRAM_BOOT__
  sram_remap();  //H64 Matrix0 JCK 19may17 removed for SRAM_BOOT
#endif

  // Interrupt management initializations
  IT_Init();
  
  // Secure Interrupt management initializations
  Secure_IT_Init();
  
  // Restore initial HW clock settings (after ROMBOOT modifications)
  clock_config();
  
  return 1; 
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


#warning __iar_init_vfp surcharged with dummy function
int __iar_init_vfp()
{
     return 1;
}


//------------------------------------------------------------------------------
/// Exceptions default routines
//------------------------------------------------------------------------------
void Undefined_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void SWI_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void Prefetch_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void Abort_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
/*
void IRQ_Handler(void)
{
 intfunc it_routine;
 
  it_routine=(intfunc)AIC->AIC_IVR;
  it_routine();
  AIC->AIC_EOICR=0; // Acknoledge IT at AIC level
  //asm("MSR CPSR,SPSR_IRQ");  // Set new value
}
*/
//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
#pragma weak PIT_Handler=Dummy_Handler              /**<  3 SAMA5D27 Periodic Interval Timer Interrupt (PIT) */
#pragma weak WDT_Handler=Dummy_Handler              /**<  4 SAMA5D27 Watchdog timer Interrupt (WDT) */
#pragma weak GMAC_Handler=Dummy_Handler             /**<  5 SAMA5D27 Ethernet MAC (GMAC) */
#pragma weak XDMAC0_Handler=Dummy_Handler           /**<  6 SAMA5D27 DMA Controller 0 (XDMAC0) */
#pragma weak XDMAC1_Handler=Dummy_Handler           /**<  7 SAMA5D27 DMA Controller 1 (XDMAC1) */
#pragma weak ICM_Handler=Dummy_Handler              /**<  8 SAMA5D27 Integritry Check Monitor (ICM) */
#pragma weak AES_Handler=Dummy_Handler              /**<  9 SAMA5D27 Advanced Enion Standard (AES) */
#pragma weak AESB_Handler=Dummy_Handler             /**< 10 SAMA5D27 AES bridge (AESB) */
#pragma weak TDES_Handler=Dummy_Handler             /**< 11 SAMA5D27 Triple Data Enion Standard (TDES) */
#pragma weak SHA_Handler=Dummy_Handler              /**< 12 SAMA5D27 SHA Signature (SHA) */
#pragma weak MPDDRC_Handler=Dummy_Handler           /**< 13 SAMA5D27 MPDDR controller (MPDDRC) */
#pragma weak MATRIX1_Handler=Dummy_Handler          /**< 14 SAMA5D27 H32MX, 32-bit AHB Matrix (MATRIX1) */
#pragma weak MATRIX0_Handler=Dummy_Handler          /**< 15 SAMA5D27 H64MX, 64-bit AHB Matrix (MATRIX0) */
#pragma weak HSMC_Handler=Dummy_Handler             /**< 17 SAMA5D27 Multi-bit ECC Interrupt (HSMC) */
#pragma weak PIOA_Handler=Dummy_Handler             /**< 18 SAMA5D27 Parallel I/O Controller (PIOA) */
#pragma weak FLEXCOM0_Handler=Dummy_Handler         /**< 19 SAMA5D27 FLEXCOM 0 (FLEXCOM0) */
#pragma weak FLEXCOM1_Handler=Dummy_Handler         /**< 20 SAMA5D27 FLEXCOM 1 (FLEXCOM1) */
#pragma weak FLEXCOM2_Handler=Dummy_Handler         /**< 21 SAMA5D27 FLEXCOM 2 (FLEXCOM2) */
#pragma weak FLEXCOM3_Handler=Dummy_Handler         /**< 22 SAMA5D27 FLEXCOM 3 (FLEXCOM3) */
#pragma weak FLEXCOM4_Handler=Dummy_Handler         /**< 23 SAMA5D27 FLEXCOM 4 (FLEXCOM4) */
#pragma weak UART0_Handler=Dummy_Handler            /**< 24 SAMA5D27 UART 0 (UART0) */
#pragma weak UART1_Handler=Dummy_Handler            /**< 25 SAMA5D27 UART 1 (UART1) */
#pragma weak UART2_Handler=Dummy_Handler            /**< 26 SAMA5D27 UART 2 (UART2) */
#pragma weak UART3_Handler=Dummy_Handler            /**< 27 SAMA5D27 UART 3 (UART3) */
#pragma weak UART4_Handler=Dummy_Handler            /**< 28 SAMA5D27 UART 4 (UART4) */
#pragma weak TWIHS0_Handler=Dummy_Handler           /**< 29 SAMA5D27 Two-Wire Interface 0 (TWIHS0) */
#pragma weak TWIHS1_Handler=Dummy_Handler           /**< 30 SAMA5D27 Two-Wire Interface 1 (TWIHS1) */
#pragma weak SPI0_Handler=Dummy_Handler             /**< 33 SAMA5D27 Serial Peripheral Interface 0 (SPI0) */
#pragma weak SPI1_Handler=Dummy_Handler             /**< 34 SAMA5D27 Serial Peripheral Interface 1 (SPI1) */
#pragma weak TC0_Handler=Dummy_Handler              /**< 35 SAMA5D27 Timer Counter 0 (ch. 0, 1, 2) (TC0) */
#pragma weak TC1_Handler=Dummy_Handler              /**< 36 SAMA5D27 Timer Counter 1 (ch. 3, 4, 5) (TC1) */
#pragma weak PWM_Handler=Dummy_Handler              /**< 38 SAMA5D27 Pulse Width Modulation Controller0 (ch. 0, 1, 2, 3) (PWM) */
#pragma weak ADC_Handler=Dummy_Handler              /**< 40 SAMA5D27 Touch Screen ADC Controller (ADC) */
#pragma weak UHPHS_Handler=Dummy_Handler            /**< 41 SAMA5D27 USB Host High Speed (UHPHS) */
#pragma weak UDPHS_Handler=Dummy_Handler            /**< 42 SAMA5D27 USB Device High Speed (UDPHS) */
#pragma weak SSC0_Handler=Dummy_Handler             /**< 43 SAMA5D27 Synchronous Serial Controller 0 (SSC0) */
#pragma weak SSC1_Handler=Dummy_Handler             /**< 44 SAMA5D27 Synchronous Serial Controller 1 (SSC1) */
#pragma weak LCDC_Handler=Dummy_Handler             /**< 45 SAMA5D27 LCD Controller (LCDC) */
#pragma weak TRNG_Handler=Dummy_Handler             /**< 47 SAMA5D27 True Random Number Generator (TRNG) */
#pragma weak PDMIC_Handler=Dummy_Handler            /**< 48 SAMA5D27 Pulse Density Modulation Interface Controller (PDMIC) */
#pragma weak SFC_Handler=Dummy_Handler              /**< 50 SAMA5D27 Fuse Controller (SFC) */
#pragma weak QSPI0_Handler=Dummy_Handler            /**< 52 SAMA5D27 QSPI 0 (QSPI0) */
#pragma weak QSPI1_Handler=Dummy_Handler            /**< 53 SAMA5D27 QSPI 1 (QSPI1) */
#pragma weak I2SC0_Handler=Dummy_Handler            /**< 54 SAMA5D27 Inter-IC Sound Controller 0 (I2SC0) */
#pragma weak I2SC1_Handler=Dummy_Handler            /**< 55 SAMA5D27 Inter-IC Sound Controller 1 (I2SC1) */

#pragma weak PTC_Handler=Dummy_Handler              /**< 58 SAMA5D2 Peripheral Touch Controller (PTC) */

#pragma weak CLASSD_Handler=Dummy_Handler           /**< 59 SAMA5D27 Audio Class D amplifier (CLASSD) */
#pragma weak SFR_Handler=Dummy_Handler              /**< 60 SAMA5D27 Special Function Register  (SFR) */
#pragma weak SAIC_Handler=Dummy_Handler             /**< 61 SAMA5D27 Secured Advanced Interrupt Controller  (SAIC) */
#pragma weak AIC_Handler=Dummy_Handler              /**< 62 SAMA5D27 Advanced Interrupt Controller  (AIC) */
#pragma weak L2CC_Handler=Dummy_Handler             /**< 63 SAMA5D27 L2 Cache Controller (L2CC) */
#pragma weak PIOB_Handler=Dummy_Handler             /**< 68 SAMA5D27  (PIOB) */
#pragma weak PIOC_Handler=Dummy_Handler             /**< 69 SAMA5D27  (PIOC) */
#pragma weak PIOD_Handler=Dummy_Handler             /**< 70 SAMA5D27  (PIOD) */
#pragma weak ACC_Handler=Dummy_Handler              /**< 75 SAMA5D27 Analog Comparator (ACC) */
#pragma weak RXLP_Handler=Dummy_Handler             /**< 76 SAMA5D27 Uart Low Power (RXLP) */
#pragma weak CHIPID_Handler=Dummy_Handler           /**< 78 SAMA5D27 Chip ID (CHIPID) */

#pragma weak Spurious_handler=Dummy_Handler

//------------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// IT management
//  Function Name : IT_Init
// -----------------------------------------------------------------------------
void IT_Init (void)
{
 unsigned int i;
  
  // Assign handler addesses
  AIC->AIC_SSR =  3; AIC->AIC_SVR = (unsigned int) PIT_Handler;              /**<  3 SAMA5D27 Periodic Interval Timer Interrupt (PIT) */
  AIC->AIC_SSR =  4; AIC->AIC_SVR = (unsigned int) WDT_Handler;              /**<  4 SAMA5D27 Watchdog timer Interrupt (WDT) */
  AIC->AIC_SSR =  5; AIC->AIC_SVR = (unsigned int) GMAC_Handler;             /**<  5 SAMA5D27 Ethernet MAC (GMAC) */
  AIC->AIC_SSR =  6; AIC->AIC_SVR = (unsigned int) XDMAC0_Handler;           /**<  6 SAMA5D27 DMA Controller 0 (XDMAC0) */
  AIC->AIC_SSR =  7; AIC->AIC_SVR = (unsigned int) XDMAC1_Handler;           /**<  7 SAMA5D27 DMA Controller 1 (XDMAC1) */
  AIC->AIC_SSR =  8; AIC->AIC_SVR = (unsigned int) ICM_Handler;              /**<  8 SAMA5D27 Integritry Check Monitor (ICM) */
  AIC->AIC_SSR =  9; AIC->AIC_SVR = (unsigned int) AES_Handler;              /**<  9 SAMA5D27 Advanced Enion Standard (AES) */
  AIC->AIC_SSR = 10; AIC->AIC_SVR = (unsigned int) AESB_Handler;             /**< 10 SAMA5D27 AES bridge (AESB) */
  AIC->AIC_SSR = 11; AIC->AIC_SVR = (unsigned int) TDES_Handler;             /**< 11 SAMA5D27 Triple Data Enion Standard (TDES) */
  AIC->AIC_SSR = 12; AIC->AIC_SVR = (unsigned int) SHA_Handler;              /**< 12 SAMA5D27 SHA Signature (SHA) */
  AIC->AIC_SSR = 13; AIC->AIC_SVR = (unsigned int) MPDDRC_Handler;           /**< 13 SAMA5D27 MPDDR controller (MPDDRC) */
  AIC->AIC_SSR = 14; AIC->AIC_SVR = (unsigned int) MATRIX1_Handler;          /**< 14 SAMA5D27 H32MX, 32-bit AHB Matrix (MATRIX1) */
  AIC->AIC_SSR = 15; AIC->AIC_SVR = (unsigned int) MATRIX0_Handler;          /**< 15 SAMA5D27 H64MX, 64-bit AHB Matrix (MATRIX0) */
  AIC->AIC_SSR = 17; AIC->AIC_SVR = (unsigned int) HSMC_Handler;             /**< 17 SAMA5D27 Multi-bit ECC Interrupt (HSMC) */
  AIC->AIC_SSR = 18; AIC->AIC_SVR = (unsigned int) PIOA_Handler;             /**< 18 SAMA5D27 Parallel I/O Controller (PIOA) */
  AIC->AIC_SSR = 19; AIC->AIC_SVR = (unsigned int) FLEXCOM0_Handler;         /**< 19 SAMA5D27 FLEXCOM 0 (FLEXCOM0) */
  AIC->AIC_SSR = 20; AIC->AIC_SVR = (unsigned int) FLEXCOM1_Handler;         /**< 20 SAMA5D27 FLEXCOM 1 (FLEXCOM1) */
  AIC->AIC_SSR = 21; AIC->AIC_SVR = (unsigned int) FLEXCOM2_Handler;         /**< 21 SAMA5D27 FLEXCOM 2 (FLEXCOM2) */
  AIC->AIC_SSR = 22; AIC->AIC_SVR = (unsigned int) FLEXCOM3_Handler;         /**< 22 SAMA5D27 FLEXCOM 3 (FLEXCOM3) */
  AIC->AIC_SSR = 23; AIC->AIC_SVR = (unsigned int) FLEXCOM4_Handler;         /**< 23 SAMA5D27 FLEXCOM 4 (FLEXCOM4) */
  AIC->AIC_SSR = 24; AIC->AIC_SVR = (unsigned int) UART0_Handler;            /**< 24 SAMA5D27 UART 0 (UART0) */
  AIC->AIC_SSR = 25; AIC->AIC_SVR = (unsigned int) UART1_Handler;            /**< 25 SAMA5D27 UART 1 (UART1) */
  AIC->AIC_SSR = 26; AIC->AIC_SVR = (unsigned int) UART2_Handler;            /**< 26 SAMA5D27 UART 2 (UART2) */
  AIC->AIC_SSR = 27; AIC->AIC_SVR = (unsigned int) UART3_Handler;            /**< 27 SAMA5D27 UART 3 (UART3) */
  AIC->AIC_SSR = 28; AIC->AIC_SVR = (unsigned int) UART4_Handler;            /**< 28 SAMA5D27 UART 4 (UART4) */
  AIC->AIC_SSR = 29; AIC->AIC_SVR = (unsigned int) TWIHS0_Handler;           /**< 29 SAMA5D27 Two-Wire Interface 0 (TWIHS0) */
  AIC->AIC_SSR = 30; AIC->AIC_SVR = (unsigned int) TWIHS1_Handler;           /**< 30 SAMA5D27 Two-Wire Interface 1 (TWIHS1) */
  AIC->AIC_SSR = 33; AIC->AIC_SVR = (unsigned int) SPI0_Handler;             /**< 33 SAMA5D27 Serial Peripheral Interface 0 (SPI0) */
  AIC->AIC_SSR = 34; AIC->AIC_SVR = (unsigned int) SPI1_Handler;             /**< 34 SAMA5D27 Serial Peripheral Interface 1 (SPI1) */
  AIC->AIC_SSR = 35; AIC->AIC_SVR = (unsigned int) TC0_Handler;              /**< 35 SAMA5D27 Timer Counter 0 (ch. 0, 1, 2) (TC0) */
  AIC->AIC_SSR = 36; AIC->AIC_SVR = (unsigned int) TC1_Handler;              /**< 36 SAMA5D27 Timer Counter 1 (ch. 3, 4, 5) (TC1) */
  AIC->AIC_SSR = 38; AIC->AIC_SVR = (unsigned int) PWM_Handler;              /**< 38 SAMA5D27 Pulse Width Modulation Controller0 (ch. 0, 1, 2, 3) (PWM) */
  AIC->AIC_SSR = 40; AIC->AIC_SVR = (unsigned int) ADC_Handler;              /**< 40 SAMA5D27 Touch Screen ADC Controller (ADC) */
  AIC->AIC_SSR = 41; AIC->AIC_SVR = (unsigned int) UHPHS_Handler;            /**< 41 SAMA5D27 USB Host High Speed (UHPHS) */
  AIC->AIC_SSR = 42; AIC->AIC_SVR = (unsigned int) UDPHS_Handler;            /**< 42 SAMA5D27 USB Device High Speed (UDPHS) */
  AIC->AIC_SSR = 43; AIC->AIC_SVR = (unsigned int) SSC0_Handler;             /**< 43 SAMA5D27 Synchronous Serial Controller 0 (SSC0) */
  AIC->AIC_SSR = 44; AIC->AIC_SVR = (unsigned int) SSC1_Handler;             /**< 44 SAMA5D27 Synchronous Serial Controller 1 (SSC1) */
  AIC->AIC_SSR = 45; AIC->AIC_SVR = (unsigned int) LCDC_Handler;             /**< 45 SAMA5D27 LCD Controller (LCDC) */
  AIC->AIC_SSR = 47; AIC->AIC_SVR = (unsigned int) TRNG_Handler;             /**< 47 SAMA5D27 True Random Number Generator (TRNG) */
  AIC->AIC_SSR = 48; AIC->AIC_SVR = (unsigned int) PDMIC_Handler;            /**< 48 SAMA5D27 Pulse Density Modulation Interface Controller (PDMIC) */
  AIC->AIC_SSR = 50; AIC->AIC_SVR = (unsigned int) SFC_Handler;              /**< 50 SAMA5D27 Fuse Controller (SFC) */
  AIC->AIC_SSR = 52; AIC->AIC_SVR = (unsigned int) QSPI0_Handler;            /**< 52 SAMA5D27 QSPI 0 (QSPI0) */
  AIC->AIC_SSR = 53; AIC->AIC_SVR = (unsigned int) QSPI1_Handler;            /**< 53 SAMA5D27 QSPI 1 (QSPI1) */
  AIC->AIC_SSR = 54; AIC->AIC_SVR = (unsigned int) I2SC0_Handler;            /**< 54 SAMA5D27 Inter-IC Sound Controller 0 (I2SC0) */
  AIC->AIC_SSR = 55; AIC->AIC_SVR = (unsigned int) I2SC1_Handler;            /**< 55 SAMA5D27 Inter-IC Sound Controller 1 (I2SC1) */

  AIC->AIC_SSR = 58; AIC->AIC_SVR = (unsigned int) PTC_Handler;              /**< 58 SAMA5D2 Peripheral Touch Controller (PTC) */

  AIC->AIC_SSR = 59; AIC->AIC_SVR = (unsigned int) CLASSD_Handler;           /**< 59 SAMA5D27 Audio Class D amplifier (CLASSD) */
  AIC->AIC_SSR = 60; AIC->AIC_SVR = (unsigned int) SFR_Handler;              /**< 60 SAMA5D27 Special Function Register  (SFR) */
  AIC->AIC_SSR = 61; AIC->AIC_SVR = (unsigned int) SAIC_Handler;             /**< 61 SAMA5D27 Secured Advanced Interrupt Controller  (SAIC) */
  AIC->AIC_SSR = 62; AIC->AIC_SVR = (unsigned int) AIC_Handler;              /**< 62 SAMA5D27 Advanced Interrupt Controller  (AIC) */
  AIC->AIC_SSR = 63; AIC->AIC_SVR = (unsigned int) L2CC_Handler;             /**< 63 SAMA5D27 L2 Cache Controller (L2CC) */
  AIC->AIC_SSR = 68; AIC->AIC_SVR = (unsigned int) PIOB_Handler;             /**< 68 SAMA5D27  (PIOB) */
  AIC->AIC_SSR = 69; AIC->AIC_SVR = (unsigned int) PIOC_Handler;             /**< 69 SAMA5D27  (PIOC) */
  AIC->AIC_SSR = 70; AIC->AIC_SVR = (unsigned int) PIOD_Handler;             /**< 70 SAMA5D27  (PIOD) */
  AIC->AIC_SSR = 75; AIC->AIC_SVR = (unsigned int) ACC_Handler;              /**< 75 SAMA5D27 Analog Comparator (ACC) */
  AIC->AIC_SSR = 76; AIC->AIC_SVR = (unsigned int) RXLP_Handler;             /**< 76 SAMA5D27 Uart Low Power (RXLP) */
  AIC->AIC_SSR = 78; AIC->AIC_SVR = (unsigned int) CHIPID_Handler;           /**< 78 SAMA5D27 Chip ID (CHIPID) */

  AIC->AIC_SPU = (unsigned int) Spurious_handler;
    
// ------------ Disable all interrupts
  for (i=1;i<DEVICE_NB_INTERRUPTS;i++){
    AIC->AIC_SSR=i;
    AIC->AIC_IDCR=AIC_IDCR_INTD;
    }

// ------------ Clear All pending interrupts flags
  for (i=0;i<DEVICE_NB_INTERRUPTS;i++){
    AIC->AIC_SSR  = i;
    AIC->AIC_ICCR = AIC_ICCR_INTCLR;
    }
    
// ------------ Perform 8 IT acknoledge (write any value in EOICR) (VPy)
  for (i=0;i<8;i++){
    AIC->AIC_EOICR=0;
    }
  
  // ---- Enable IRQ and FIQ at core level
  //i = v_ARM_GetCPSR(void);
  v_ARM_ClrCPSR_bits(CPSR_MASK_IRQ|CPSR_MASK_FIQ);
  
}
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// IT management
//  Function Name : Secure_IT_Init
// -----------------------------------------------------------------------------
void Secure_IT_Init (void)
{
 unsigned int i;
  
  // Assign handler addesses
  SAIC->AIC_SSR =  3; SAIC->AIC_SVR = (unsigned int) PIT_Handler;              /**<  3 SAMA5D27 Periodic Interval Timer Interrupt (PIT) */
  SAIC->AIC_SSR =  4; SAIC->AIC_SVR = (unsigned int) WDT_Handler;              /**<  4 SAMA5D27 Watchdog timer Interrupt (WDT) */
  SAIC->AIC_SSR =  5; SAIC->AIC_SVR = (unsigned int) GMAC_Handler;             /**<  5 SAMA5D27 Ethernet MAC (GMAC) */
  SAIC->AIC_SSR =  6; SAIC->AIC_SVR = (unsigned int) XDMAC0_Handler;           /**<  6 SAMA5D27 DMA Controller 0 (XDMAC0) */
  SAIC->AIC_SSR =  7; SAIC->AIC_SVR = (unsigned int) XDMAC1_Handler;           /**<  7 SAMA5D27 DMA Controller 1 (XDMAC1) */
  SAIC->AIC_SSR =  8; SAIC->AIC_SVR = (unsigned int) ICM_Handler;              /**<  8 SAMA5D27 Integritry Check Monitor (ICM) */
  SAIC->AIC_SSR =  9; SAIC->AIC_SVR = (unsigned int) AES_Handler;              /**<  9 SAMA5D27 Advanced Enion Standard (AES) */
  SAIC->AIC_SSR = 10; SAIC->AIC_SVR = (unsigned int) AESB_Handler;             /**< 10 SAMA5D27 AES bridge (AESB) */
  SAIC->AIC_SSR = 11; SAIC->AIC_SVR = (unsigned int) TDES_Handler;             /**< 11 SAMA5D27 Triple Data Enion Standard (TDES) */
  SAIC->AIC_SSR = 12; SAIC->AIC_SVR = (unsigned int) SHA_Handler;              /**< 12 SAMA5D27 SHA Signature (SHA) */
  SAIC->AIC_SSR = 13; SAIC->AIC_SVR = (unsigned int) MPDDRC_Handler;           /**< 13 SAMA5D27 MPDDR controller (MPDDRC) */
  SAIC->AIC_SSR = 14; SAIC->AIC_SVR = (unsigned int) MATRIX1_Handler;          /**< 14 SAMA5D27 H32MX, 32-bit AHB Matrix (MATRIX1) */
  SAIC->AIC_SSR = 15; SAIC->AIC_SVR = (unsigned int) MATRIX0_Handler;          /**< 15 SAMA5D27 H64MX, 64-bit AHB Matrix (MATRIX0) */
  SAIC->AIC_SSR = 17; SAIC->AIC_SVR = (unsigned int) HSMC_Handler;             /**< 17 SAMA5D27 Multi-bit ECC Interrupt (HSMC) */
  SAIC->AIC_SSR = 18; SAIC->AIC_SVR = (unsigned int) PIOA_Handler;             /**< 18 SAMA5D27 Parallel I/O Controller (PIOA) */
  SAIC->AIC_SSR = 19; SAIC->AIC_SVR = (unsigned int) FLEXCOM0_Handler;         /**< 19 SAMA5D27 FLEXCOM 0 (FLEXCOM0) */
  SAIC->AIC_SSR = 20; SAIC->AIC_SVR = (unsigned int) FLEXCOM1_Handler;         /**< 20 SAMA5D27 FLEXCOM 1 (FLEXCOM1) */
  SAIC->AIC_SSR = 21; SAIC->AIC_SVR = (unsigned int) FLEXCOM2_Handler;         /**< 21 SAMA5D27 FLEXCOM 2 (FLEXCOM2) */
  SAIC->AIC_SSR = 22; SAIC->AIC_SVR = (unsigned int) FLEXCOM3_Handler;         /**< 22 SAMA5D27 FLEXCOM 3 (FLEXCOM3) */
  SAIC->AIC_SSR = 23; SAIC->AIC_SVR = (unsigned int) FLEXCOM4_Handler;         /**< 23 SAMA5D27 FLEXCOM 4 (FLEXCOM4) */
  SAIC->AIC_SSR = 24; SAIC->AIC_SVR = (unsigned int) UART0_Handler;            /**< 24 SAMA5D27 UART 0 (UART0) */
  SAIC->AIC_SSR = 25; SAIC->AIC_SVR = (unsigned int) UART1_Handler;            /**< 25 SAMA5D27 UART 1 (UART1) */
  SAIC->AIC_SSR = 26; SAIC->AIC_SVR = (unsigned int) UART2_Handler;            /**< 26 SAMA5D27 UART 2 (UART2) */
  SAIC->AIC_SSR = 27; SAIC->AIC_SVR = (unsigned int) UART3_Handler;            /**< 27 SAMA5D27 UART 3 (UART3) */
  SAIC->AIC_SSR = 28; SAIC->AIC_SVR = (unsigned int) UART4_Handler;            /**< 28 SAMA5D27 UART 4 (UART4) */
  SAIC->AIC_SSR = 29; SAIC->AIC_SVR = (unsigned int) TWIHS0_Handler;           /**< 29 SAMA5D27 Two-Wire Interface 0 (TWIHS0) */
  SAIC->AIC_SSR = 30; SAIC->AIC_SVR = (unsigned int) TWIHS1_Handler;           /**< 30 SAMA5D27 Two-Wire Interface 1 (TWIHS1) */
  SAIC->AIC_SSR = 33; SAIC->AIC_SVR = (unsigned int) SPI0_Handler;             /**< 33 SAMA5D27 Serial Peripheral Interface 0 (SPI0) */
  SAIC->AIC_SSR = 34; SAIC->AIC_SVR = (unsigned int) SPI1_Handler;             /**< 34 SAMA5D27 Serial Peripheral Interface 1 (SPI1) */
  SAIC->AIC_SSR = 35; SAIC->AIC_SVR = (unsigned int) TC0_Handler;              /**< 35 SAMA5D27 Timer Counter 0 (ch. 0, 1, 2) (TC0) */
  SAIC->AIC_SSR = 36; SAIC->AIC_SVR = (unsigned int) TC1_Handler;              /**< 36 SAMA5D27 Timer Counter 1 (ch. 3, 4, 5) (TC1) */
  SAIC->AIC_SSR = 38; SAIC->AIC_SVR = (unsigned int) PWM_Handler;              /**< 38 SAMA5D27 Pulse Width Modulation Controller0 (ch. 0, 1, 2, 3) (PWM) */
  SAIC->AIC_SSR = 40; SAIC->AIC_SVR = (unsigned int) ADC_Handler;              /**< 40 SAMA5D27 Touch Screen ADC Controller (ADC) */
  SAIC->AIC_SSR = 41; SAIC->AIC_SVR = (unsigned int) UHPHS_Handler;            /**< 41 SAMA5D27 USB Host High Speed (UHPHS) */
  SAIC->AIC_SSR = 42; SAIC->AIC_SVR = (unsigned int) UDPHS_Handler;            /**< 42 SAMA5D27 USB Device High Speed (UDPHS) */
  SAIC->AIC_SSR = 43; SAIC->AIC_SVR = (unsigned int) SSC0_Handler;             /**< 43 SAMA5D27 Synchronous Serial Controller 0 (SSC0) */
  SAIC->AIC_SSR = 44; SAIC->AIC_SVR = (unsigned int) SSC1_Handler;             /**< 44 SAMA5D27 Synchronous Serial Controller 1 (SSC1) */
  SAIC->AIC_SSR = 45; SAIC->AIC_SVR = (unsigned int) LCDC_Handler;             /**< 45 SAMA5D27 LCD Controller (LCDC) */
  SAIC->AIC_SSR = 47; SAIC->AIC_SVR = (unsigned int) TRNG_Handler;             /**< 47 SAMA5D27 True Random Number Generator (TRNG) */
  SAIC->AIC_SSR = 48; SAIC->AIC_SVR = (unsigned int) PDMIC_Handler;            /**< 48 SAMA5D27 Pulse Density Modulation Interface Controller (PDMIC) */
  SAIC->AIC_SSR = 50; SAIC->AIC_SVR = (unsigned int) SFC_Handler;              /**< 50 SAMA5D27 Fuse Controller (SFC) */
  SAIC->AIC_SSR = 52; SAIC->AIC_SVR = (unsigned int) QSPI0_Handler;            /**< 52 SAMA5D27 QSPI 0 (QSPI0) */
  SAIC->AIC_SSR = 53; SAIC->AIC_SVR = (unsigned int) QSPI1_Handler;            /**< 53 SAMA5D27 QSPI 1 (QSPI1) */
  SAIC->AIC_SSR = 54; SAIC->AIC_SVR = (unsigned int) I2SC0_Handler;            /**< 54 SAMA5D27 Inter-IC Sound Controller 0 (I2SC0) */
  SAIC->AIC_SSR = 55; SAIC->AIC_SVR = (unsigned int) I2SC1_Handler;            /**< 55 SAMA5D27 Inter-IC Sound Controller 1 (I2SC1) */
  
  SAIC->AIC_SSR = 58; SAIC->AIC_SVR = (unsigned int) PTC_Handler;              /**< 58 SAMA5D2 Peripheral Touch Controller (PTC) */
  
  SAIC->AIC_SSR = 59; SAIC->AIC_SVR = (unsigned int) CLASSD_Handler;           /**< 59 SAMA5D27 Audio Class D amplifier (CLASSD) */
  SAIC->AIC_SSR = 60; SAIC->AIC_SVR = (unsigned int) SFR_Handler;              /**< 60 SAMA5D27 Special Function Register  (SFR) */
  SAIC->AIC_SSR = 61; SAIC->AIC_SVR = (unsigned int) SAIC_Handler;             /**< 61 SAMA5D27 Secured Advanced Interrupt Controller  (SAIC) */
  SAIC->AIC_SSR = 62; SAIC->AIC_SVR = (unsigned int) AIC_Handler;              /**< 62 SAMA5D27 Advanced Interrupt Controller  (AIC) */
  SAIC->AIC_SSR = 63; SAIC->AIC_SVR = (unsigned int) L2CC_Handler;             /**< 63 SAMA5D27 L2 Cache Controller (L2CC) */
  SAIC->AIC_SSR = 68; SAIC->AIC_SVR = (unsigned int) PIOB_Handler;             /**< 68 SAMA5D27  (PIOB) */
  SAIC->AIC_SSR = 69; SAIC->AIC_SVR = (unsigned int) PIOC_Handler;             /**< 69 SAMA5D27  (PIOC) */
  SAIC->AIC_SSR = 70; SAIC->AIC_SVR = (unsigned int) PIOD_Handler;             /**< 70 SAMA5D27  (PIOD) */
  SAIC->AIC_SSR = 75; SAIC->AIC_SVR = (unsigned int) ACC_Handler;              /**< 75 SAMA5D27 Analog Comparator (ACC) */
  SAIC->AIC_SSR = 76; SAIC->AIC_SVR = (unsigned int) RXLP_Handler;             /**< 76 SAMA5D27 Uart Low Power (RXLP) */
  SAIC->AIC_SSR = 78; SAIC->AIC_SVR = (unsigned int) CHIPID_Handler;           /**< 78 SAMA5D27 Chip ID (CHIPID) */

  SAIC->AIC_SPU = (unsigned int) Spurious_handler;
    
// ------------ Disable all interrupts
  for (i=1;i<DEVICE_NB_INTERRUPTS;i++){
    SAIC->AIC_SSR=i;
    SAIC->AIC_IDCR=AIC_IDCR_INTD;
    }

// ------------ Clear All pending interrupts flags
  for (i=0;i<DEVICE_NB_INTERRUPTS;i++){
    SAIC->AIC_SSR  = i;
    SAIC->AIC_ICCR = AIC_ICCR_INTCLR;
    }
    
// ------------ Perform 8 IT acknoledge (write any value in EOICR) (VPy)
  for (i=0;i<8;i++){
    SAIC->AIC_EOICR=0;
    }
  
  // ---- Enable IRQ and FIQ at core level
  //i = v_ARM_GetCPSR(void);
  v_ARM_ClrCPSR_bits(CPSR_MASK_IRQ|CPSR_MASK_FIQ);
  
/*
  // ------------ Enable all interrupts
  for (i=24;i< 28 ;i++){
    SAIC->AIC_SSR=i;
    SAIC->AIC_IECR=AIC_IECR_INTEN;
    }
*/
}
// -----------------------------------------------------------------------------




// -----------------------------------------------------------------------------
//  Clocks setting
//  Function Name : clock_config
// -----------------------------------------------------------------------------
void clock_config(void)
{
 volatile unsigned int  read_reg;

 
   //  --------- select Slow clock as input clock for MCK
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_SLOW_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   
   // restore HW startup clock settings if ROMBOOT was executed (RAM debug)
   REG_CKGR_MOR = CKGR_MOR_KEY_PASSWD        |
                  CKGR_MOR_MOSCXTST(0xFF)| // ERr(0x3F<<8)|
                  CKGR_MOR_MOSCRCEN      |//32K RC osc and 12MHz RC osc always ON when VDDBU is present
                  CKGR_MOR_MOSCXTEN      ;

   while( !(REG_PMC_SR & PMC_SR_MOSCRCS) );//CJn

   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_PRES_Msk;
   read_reg |= PMC_MCKR_PRES_CLK_1;
   REG_PMC_MCKR = read_reg;
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   read_reg &= ~PMC_MCKR_MDIV_Msk;
   read_reg |= PMC_MCKR_MDIV_EQ_PCK;
   REG_PMC_MCKR = read_reg;
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   //---------------------------------

   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_MAIN_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
}
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
//  SRAM remap function
//  Function Name : 
// -----------------------------------------------------------------------------
#define MATRIX_MRCR_RCB_ALL 0xFFFF
void sram_remap(void)
{
 volatile unsigned int i;
 // AHB remap 
  /*matrix->MATRIX_WPMR = MATRIX_WPMR_WPKEY_PASSWD;
  matrix->MATRIX_MRCR = MATRIX_MRCR_RCB0;
  matrix->MATRIX_WPMR = MATRIX_WPMR_WPKEY_PASSWD | MATRIX_WPMR_WPEN;
*/
  // AXI remap
  AXIMX->AXIMX_REMAP = AXIMX_REMAP_REMAP0;
  
  for(i=1000;--i;);
}
// -----------------------------------------------------------------------------

