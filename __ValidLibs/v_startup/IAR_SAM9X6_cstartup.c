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
// MNn / 02/2018 SAM9X6


// ------ Compatibility list (compliant devices) ------------------------------


#include "project.h"


// ---- General purpose include files
#include "device.h"
//#include "board.h"
#include "exceptions.h"
#include "v_utils.h"

// ---- Validation libraries
#include "v_startup\v_mmu.h"
#include "v_startup\v_core.h"

#warning Files to rewrite and merge with asm cstartup 
//------------------------------------------------------------------------------
typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;
//------------------------------------------------------------------------------

// global variables
extern unsigned int  MCK_clock_speed; //main.c

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
  // Instruction Cache disable
  v_DisableICache();
  
  // Perform SRAM remap at address 0x0
#ifndef __SRAM_BOOT__
  sram_remap();  //H64 Matrix0 JCK 19may17 removed for SRAM_BOOT
#endif

  // Interrupt management initializations
  IT_Init();
  
  // No Secure INterrupts on SAM9X6 MNn.
  
  // Restore initial HW clock settings (after ROMBOOT modifications)
#if (FPGA_PLATFORM==0)
  clock_config();
#else //FPGA_PLATFORM
  //MCK_clock_speed = 15000000; //done in main AFTER data init
#endif  
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
  Valid_DebugTrace( "!!! In Undefined_Handler !!!\n\r");
    while(1);
}
//------------------------------------------------------------------------------
void SWI_Handler(void){
 Valid_DebugTrace( "!!! In SWI_Handler !!!\n\r");
     while(1);
}
//------------------------------------------------------------------------------
void Prefetch_Handler(void){
 Valid_DebugTrace( "!!! In Prefetch_Handler !!!\n\r");
     while(1);
}
//------------------------------------------------------------------------------
void Abort_Handler(void){
  Valid_DebugTrace( "!!! In Abort_Handler !!!\n\r");
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
  Valid_DebugTrace( "!!! In Dummy_Handler !!!\n\r");
  while ( 1 ) ;
}

  #pragma weak SYSC_Handler=Dummy_Handler        /**<  1 SAM9X6 Sys */
  #pragma weak PIOA_Handler=Dummy_Handler        /**<  2 SAM9X6 Pioa */
  #pragma weak PIOB_Handler=Dummy_Handler        /**<  3 SAM9X6 Piob */
  #pragma weak PIOC_Handler=Dummy_Handler        /**<  4 SAM9X6 Pioc */
  #pragma weak FLEXCOM0_Handler=Dummy_Handler    /**<  5 SAM9X6 FLEXCOM0 */
  #pragma weak FLEXCOM1_Handler=Dummy_Handler    /**<  6 SAM9X6 FLEXCOM1 */
  #pragma weak FLEXCOM2_Handler=Dummy_Handler    /**<  7 SAM9X6 FLEXCOM2 */
  #pragma weak FLEXCOM3_Handler=Dummy_Handler    /**<  8 SAM9X6 FLEXCOM3 */
  #pragma weak FLEXCOM6_Handler=Dummy_Handler    /**<  9 SAM9X6 FLEXCOM6 */
  #pragma weak FLEXCOM7_Handler=Dummy_Handler    /**< 10 SAM9X6 FLEXCOM7 */
  #pragma weak FLEXCOM8_Handler=Dummy_Handler    /**< 11 SAM9X6 FLEXCOM8 */
  #pragma weak SDMMC0_Handler=Dummy_Handler      /**< 12 SAM9X6 SDMMC0 */
  #pragma weak FLEXCOM4_Handler=Dummy_Handler    /**< 13 SAM9X6 FLEXCOM4 */
  #pragma weak FLEXCOM5_Handler=Dummy_Handler    /**< 14 SAM9X6 FLEXCOM5 */
  #pragma weak FLEXCOM9_Handler=Dummy_Handler    /**< 15 SAM9X6 FLEXCOM9 */
  #pragma weak FLEXCOM10_Handler=Dummy_Handler   /**< 16 SAM9X6 FLEXCOM10 */
  #pragma weak TC0_Handler=Dummy_Handler         /**< 17 SAM9X6 TC0 */
  #pragma weak PWM_Handler=Dummy_Handler         /**< 18 SAM9X6 PWM */
  #pragma weak ADC_Handler=Dummy_Handler         /**< 19 SAM9X6 ADC */
  #pragma weak XDMAC_Handler=Dummy_Handler       /**< 20 SAM9X6 XDMAC */
  #pragma weak MATRIX_Handler=Dummy_Handler      /**< 21 SAM9X6 MATRIX */
  #pragma weak UHPHS_Handler=Dummy_Handler       /**< 22 SAM9X6 UHPHS */
  #pragma weak UDPHS_Handler=Dummy_Handler       /**< 23 SAM9X6 UDPHS */
  #pragma weak EMAC0_Handler=Dummy_Handler       /**< 24 SAM9X6 EMAC0 */
  #pragma weak LCDC_Handler=Dummy_Handler        /**< 25 SAM9X6 LCDC */
  #pragma weak SDMMC1_Handler=Dummy_Handler      /**< 26 SAM9X6 SDMMC1 */
  #pragma weak EMAC1_Handler=Dummy_Handler       /**< 27 SAM9X6 EMAC1 */
  #pragma weak SSC_Handler=Dummy_Handler         /**< 28 SAM9X6 SSC */
  #pragma weak CAN0_Handler=Dummy_Handler        /**< 29 SAM9X6 CAN0 */
  #pragma weak CAN1_Handler=Dummy_Handler        /**< 30 SAM9X6 CAN1 */
    // AIC_Handler is not applicable
  #pragma weak FLEXCOM11_Handler=Dummy_Handler   /**< 32 SAM9X6 FLEXCOM11 */
  #pragma weak FLEXCOM12_Handler=Dummy_Handler   /**< 33 SAM9X6 FLEXCOM12 */
  #pragma weak I2SMCC_Handler=Dummy_Handler      /**< 34 SAM9X6 I2SMCC */
  #pragma weak QSPI_Handler=Dummy_Handler        /**< 35 SAM9X6 QSPI */
  #pragma weak GFX2D_Handler=Dummy_Handler       /**< 36 SAM9X6 GFX2D */
  #pragma weak PIT64B_Handler=Dummy_Handler      /**< 37 SAM9X6 PIT64B */
  #pragma weak TRNG_Handler=Dummy_Handler        /**< 38 SAM9X6 TRNG */
  #pragma weak AES_Handler=Dummy_Handler         /**< 39 SAM9X6 AES */
  #pragma weak TDES_Handler=Dummy_Handler        /**< 40 SAM9X6 TDES */
  #pragma weak SHA_Handler=Dummy_Handler         /**< 41 SAM9X6 SHA */
  #pragma weak CLASSD_Handler=Dummy_Handler      /**< 42 SAM9X6 CLASSD */
  #pragma weak ISI_Handler=Dummy_Handler         /**< 43 SAM9X6 ISI */
  #pragma weak PIOD_Handler=Dummy_Handler        /**< 44 SAM9X6 PIOD */
  #pragma weak TC1_Handler=Dummy_Handler         /**< 45 SAM9X6 TC1 */
  #pragma weak OTPC_Handler=Dummy_Handler        /**< 46 SAM9X6 OTPC */
  #pragma weak DBGU_Handler=Dummy_Handler        /**< 47 SAM9X6 DBGU */
  #pragma weak PMECC_Handler=Dummy_Handler       /**< 48 SAM9X6 PMECC */
  #pragma weak SDRAM_Handler=Dummy_Handler       /**< 49 SAM9X6 SDRAM */

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
  AIC->AIC_SSR =  1; AIC->AIC_SVR = (unsigned int) SYSC_Handler;        /**<  1 SAM9X6 Sys */
  AIC->AIC_SSR =  2; AIC->AIC_SVR = (unsigned int) PIOA_Handler;        /**<  2 SAM9X6 Pioa */
  AIC->AIC_SSR =  3; AIC->AIC_SVR = (unsigned int) PIOB_Handler;        /**<  3 SAM9X6 Piob */
  AIC->AIC_SSR =  4; AIC->AIC_SVR = (unsigned int) PIOC_Handler;        /**<  4 SAM9X6 Pioc */
  AIC->AIC_SSR =  5; AIC->AIC_SVR = (unsigned int) FLEXCOM0_Handler;    /**<  5 SAM9X6 FLEXCOM0 */
  AIC->AIC_SSR =  6; AIC->AIC_SVR = (unsigned int) FLEXCOM1_Handler;    /**<  6 SAM9X6 FLEXCOM1 */
  AIC->AIC_SSR =  7; AIC->AIC_SVR = (unsigned int) FLEXCOM2_Handler;    /**<  7 SAM9X6 FLEXCOM2 */
  AIC->AIC_SSR =  8; AIC->AIC_SVR = (unsigned int) FLEXCOM3_Handler;    /**<  8 SAM9X6 FLEXCOM3 */
  AIC->AIC_SSR =  9; AIC->AIC_SVR = (unsigned int) FLEXCOM6_Handler;    /**<  9 SAM9X6 FLEXCOM6 */
  AIC->AIC_SSR = 10; AIC->AIC_SVR = (unsigned int) FLEXCOM7_Handler;    /**< 10 SAM9X6 FLEXCOM7 */
  AIC->AIC_SSR = 11; AIC->AIC_SVR = (unsigned int) FLEXCOM8_Handler;    /**< 11 SAM9X6 FLEXCOM8 */
  AIC->AIC_SSR = 12; AIC->AIC_SVR = (unsigned int) SDMMC0_Handler;      /**< 12 SAM9X6 SDMMC0 */
  AIC->AIC_SSR = 13; AIC->AIC_SVR = (unsigned int) FLEXCOM4_Handler;    /**< 13 SAM9X6 FLEXCOM4 */
  AIC->AIC_SSR = 14; AIC->AIC_SVR = (unsigned int) FLEXCOM5_Handler;    /**< 14 SAM9X6 FLEXCOM5 */
  AIC->AIC_SSR = 15; AIC->AIC_SVR = (unsigned int) FLEXCOM9_Handler;    /**< 15 SAM9X6 FLEXCOM9 */
  AIC->AIC_SSR = 16; AIC->AIC_SVR = (unsigned int) FLEXCOM10_Handler;   /**< 16 SAM9X6 FLEXCOM10 */
  AIC->AIC_SSR = 17; AIC->AIC_SVR = (unsigned int) TC0_Handler;         /**< 17 SAM9X6 TC0 */
  AIC->AIC_SSR = 18; AIC->AIC_SVR = (unsigned int) PWM_Handler;         /**< 18 SAM9X6 PWM */
  AIC->AIC_SSR = 19; AIC->AIC_SVR = (unsigned int) ADC_Handler;         /**< 19 SAM9X6 ADC */
  AIC->AIC_SSR = 20; AIC->AIC_SVR = (unsigned int) XDMAC_Handler;       /**< 20 SAM9X6 XDMAC */
  AIC->AIC_SSR = 21; AIC->AIC_SVR = (unsigned int) MATRIX_Handler;      /**< 21 SAM9X6 MATRIX */
  AIC->AIC_SSR = 22; AIC->AIC_SVR = (unsigned int) UHPHS_Handler;       /**< 22 SAM9X6 UHPHS */
  AIC->AIC_SSR = 23; AIC->AIC_SVR = (unsigned int) UDPHS_Handler;       /**< 23 SAM9X6 UDPHS */
  AIC->AIC_SSR = 24; AIC->AIC_SVR = (unsigned int) EMAC0_Handler;       /**< 24 SAM9X6 EMAC0 */
  AIC->AIC_SSR = 25; AIC->AIC_SVR = (unsigned int) LCDC_Handler;        /**< 25 SAM9X6 LCDC */
  AIC->AIC_SSR = 26; AIC->AIC_SVR = (unsigned int) SDMMC1_Handler;      /**< 26 SAM9X6 SDMMC1 */
  AIC->AIC_SSR = 27; AIC->AIC_SVR = (unsigned int) EMAC1_Handler;       /**< 27 SAM9X6 EMAC1 */
  AIC->AIC_SSR = 28; AIC->AIC_SVR = (unsigned int) SSC_Handler;         /**< 28 SAM9X6 SSC */
  AIC->AIC_SSR = 29; AIC->AIC_SVR = (unsigned int) CAN0_Handler;        /**< 29 SAM9X6 CAN0 */
  AIC->AIC_SSR = 30; AIC->AIC_SVR = (unsigned int) CAN1_Handler;        /**< 30 SAM9X6 CAN1 */
  //AIC->AIC_SSR = 31; AIC->AIC_SVR = (unsigned int) AIC_Handler;       /**< 31 SAM9X6 AIC does not have internal interrupt */
  AIC->AIC_SSR = 32; AIC->AIC_SVR = (unsigned int) FLEXCOM11_Handler;   /**< 32 SAM9X6 FLEXCOM11 */
  AIC->AIC_SSR = 33; AIC->AIC_SVR = (unsigned int) FLEXCOM12_Handler;   /**< 33 SAM9X6 FLEXCOM12 */
  AIC->AIC_SSR = 34; AIC->AIC_SVR = (unsigned int) I2SMCC_Handler;      /**< 34 SAM9X6 I2SMCC */
  AIC->AIC_SSR = 35; AIC->AIC_SVR = (unsigned int) QSPI_Handler;        /**< 35 SAM9X6 QSPI */
  AIC->AIC_SSR = 36; AIC->AIC_SVR = (unsigned int) GFX2D_Handler;       /**< 36 SAM9X6 GFX2D */
  AIC->AIC_SSR = 37; AIC->AIC_SVR = (unsigned int) PIT64B_Handler;      /**< 37 SAM9X6 PIT64B */
  AIC->AIC_SSR = 38; AIC->AIC_SVR = (unsigned int) TRNG_Handler;        /**< 38 SAM9X6 TRNG */
  AIC->AIC_SSR = 39; AIC->AIC_SVR = (unsigned int) AES_Handler;         /**< 39 SAM9X6 AES */
  AIC->AIC_SSR = 40; AIC->AIC_SVR = (unsigned int) TDES_Handler;        /**< 40 SAM9X6 TDES */
  AIC->AIC_SSR = 41; AIC->AIC_SVR = (unsigned int) SHA_Handler;         /**< 41 SAM9X6 SHA */
  AIC->AIC_SSR = 42; AIC->AIC_SVR = (unsigned int) CLASSD_Handler;      /**< 42 SAM9X6 CLASSD */
  AIC->AIC_SSR = 43; AIC->AIC_SVR = (unsigned int) ISI_Handler;         /**< 43 SAM9X6 ISI */
  AIC->AIC_SSR = 44; AIC->AIC_SVR = (unsigned int) PIOD_Handler;        /**< 44 SAM9X6 PIOD */
  AIC->AIC_SSR = 45; AIC->AIC_SVR = (unsigned int) TC1_Handler;         /**< 45 SAM9X6 TC1 */
  AIC->AIC_SSR = 46; AIC->AIC_SVR = (unsigned int) OTPC_Handler;        /**< 46 SAM9X6 OTPC */
  AIC->AIC_SSR = 47; AIC->AIC_SVR = (unsigned int) DBGU_Handler;        /**< 47 SAM9X6 DBGU */
  AIC->AIC_SSR = 48; AIC->AIC_SVR = (unsigned int) PMECC_Handler;       /**< 48 SAM9X6 PMECC */
  AIC->AIC_SSR = 49; AIC->AIC_SVR = (unsigned int) SDRAM_Handler;       /**< 49 SAM9X6 SDRAM */

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
//  Clocks setting
//  Function Name : clock_config
// -----------------------------------------------------------------------------
void clock_config(void)
{
 volatile unsigned int  read_reg;

 
   //  --------- select Slow clock as input clock for MCK

   read_reg = REG_PMC_CPU_CKR;    // was REG_PMC_MCKR for SAMA5D2 (MNn)
   read_reg &= ~PMC_CPU_CKR_CSS_Msk; // was PMC_MCKR_CSS_Msk for SAMA5D2 (MNn)
   read_reg |= PMC_CPU_CKR_CSS_SLOW_CLK; // was PMC_MCKR_CSS_SLOW_CLK for SAMA5D2 (MNn)
   REG_PMC_CPU_CKR = read_reg;  
   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
      
   // restore HW startup clock settings if ROMBOOT was executed (RAM debug)
   REG_CKGR_MOR = CKGR_MOR_KEY_PASSWD        |
                  CKGR_MOR_MOSCXTST(0xFF)| // ERr(0x3F<<8)|
                  CKGR_MOR_MOSCRCEN      |//32K RC osc and 12MHz RC osc always ON when VDDBU is present
                  CKGR_MOR_MOSCXTEN      ;

   while( !(REG_PMC_SR & PMC_SR_MOSCRCS) );//CJn

   read_reg = REG_PMC_CPU_CKR;     // was REG_PMC_MCKR for SAMA5D2 (MNn)
   read_reg &= ~PMC_CPU_CKR_PRES_Msk;   // was PMC_MCKR_PRES_Msk for SAMA5D2 (MNn)
   read_reg |= PMC_CPU_CKR_PRES_CLK_1;   // was PMC_MCKR_PRES_CLK_1 for SAMA5D2 (MNn)    
   REG_PMC_CPU_CKR = read_reg;   // was REG_PMC_MCKR for SAMA5D2 (MNn)  
   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   read_reg &= ~PMC_CPU_CKR_MDIV_Msk; // was ~PMC_MCKR_MDIV_Msk for SAMA5D2 (MNn)
   read_reg |= PMC_CPU_CKR_MDIV_EQ_PCK; // was PMC_MCKR_MDIV_EQ_PCK for SAMA5D2 (MNn)
   REG_PMC_CPU_CKR = read_reg;   // was REG_PMC_MCKR for SAMA5D2 (MNn)     
   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   //---------------------------------

   read_reg = REG_PMC_CPU_CKR;     // was REG_PMC_MCKR for SAMA5D2 (MNn)
   read_reg &= ~PMC_CPU_CKR_CSS_Msk;  // was PMC_MCKR_CSS_Msk for SAMA5D2 (MNn)
   read_reg |= PMC_CPU_CKR_CSS_MAIN_CLK; // was PMC_MCKR_CSS_SLOW_CLK for SAMA5D2 (MNn)
   
   REG_PMC_CPU_CKR = read_reg;   // was REG_PMC_MCKR for SAMA5D2 (MNn)   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   MCK_clock_speed = 12000000;
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
 
 // AHB remap    uncommenting here for SAM9X6 MNn 
  MATRIX->MATRIX_WPMR = MATRIX_WPMR_WPKEY_PASSWD;       // was matrix MNn
  MATRIX->MATRIX_MRCR = MATRIX_MRCR_RCB0;               // was matrix MNn
  MATRIX->MATRIX_WPMR = MATRIX_WPMR_WPKEY_PASSWD | MATRIX_WPMR_WPEN; // was matrix MNn
  
  for(i=1000;--i;);
}
// -----------------------------------------------------------------------------

