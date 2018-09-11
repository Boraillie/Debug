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
// Prototypes ------------------------------------------------------------------
//------------------------------------------------------------------------------
void IT_Init(void);
void Secure_IT_Init(void);
void clock_config(void);
void sram_remap(void);
void Dummy_Handler(void);
int  __low_level_init( void );
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
  sram_remap();  //H64 Matrix0 

  
  
  // Instruction Cache disable
  //v_DisableICache();

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


//------------------------------------------------------------------------------
#pragma weak SAIC0_Handler=Dummy_Handler
#pragma weak SYS_IrqHandler=Dummy_Handler
#pragma weak ARM_IrqHandler=Dummy_Handler
#pragma weak PIT_IrqHandler=Dummy_Handler
#pragma weak WDT_IrqHandler=Dummy_Handler
#pragma weak PIOD_IrqHandler=Dummy_Handler
#pragma weak USART0_IrqHandler=Dummy_Handler
#pragma weak USART1_IrqHandler=Dummy_Handler
#pragma weak XDMAC0_IrqHandler=Dummy_Handler
#pragma weak ICM_IrqHandler=Dummy_Handler
#pragma weak PKCC_IrqHandler=Dummy_Handler
#pragma weak SCI_IrqHandler=Dummy_Handler
#pragma weak AES_IrqHandler=Dummy_Handler
#pragma weak AESOTF_IrqHandler=Dummy_Handler
#pragma weak TDES_IrqHandler=Dummy_Handler
#pragma weak SHA_IrqHandler=Dummy_Handler
#pragma weak MPDDRC_IrqHandler=Dummy_Handler
#pragma weak H32MX_IrqHandler=Dummy_Handler
#pragma weak H64MX_IrqHandler=Dummy_Handler
#pragma weak VDEC_IrqHandler=Dummy_Handler
#pragma weak SECUMOD_IrqHandler=Dummy_Handler
#pragma weak MSADCC_IrqHandler=Dummy_Handler
#pragma weak HSMC_IrqHandler=Dummy_Handler
#pragma weak PIOA_IrqHandler=Dummy_Handler
#pragma weak PIOB_IrqHandler=Dummy_Handler
#pragma weak PIOC_IrqHandler=Dummy_Handler
#pragma weak PIOE_IrqHandler=Dummy_Handler
#pragma weak UART0_IrqHandler=Dummy_Handler
#pragma weak UART1_IrqHandler=Dummy_Handler
#pragma weak USART2_IrqHandler=Dummy_Handler
#pragma weak USART3_IrqHandler=Dummy_Handler
#pragma weak USART4_IrqHandler=Dummy_Handler
#pragma weak TWI0_IrqHandler=Dummy_Handler
#pragma weak TWI1_IrqHandler=Dummy_Handler
#pragma weak TWI2_IrqHandler=Dummy_Handler
#pragma weak HSMCI0_IrqHandler=Dummy_Handler
#pragma weak HSMCI1_IrqHandler=Dummy_Handler
#pragma weak SPI0_IrqHandler=Dummy_Handler
#pragma weak SPI1_IrqHandler=Dummy_Handler
#pragma weak SPI2_IrqHandler=Dummy_Handler
#pragma weak TC0_IrqHandler=Dummy_Handler
#pragma weak TC1_IrqHandler=Dummy_Handler
#pragma weak TC2_IrqHandler=Dummy_Handler
#pragma weak PWM_IrqHandler=Dummy_Handler
#pragma weak ADC_IrqHandler=Dummy_Handler
#pragma weak DBGU_IrqHandler=Dummy_Handler
#pragma weak UHPHS_IrqHandler=Dummy_Handler
#pragma weak UDPHS_IrqHandler=Dummy_Handler
#pragma weak SSC0_IrqHandler=Dummy_Handler
#pragma weak SSC1_IrqHandler=Dummy_Handler
#pragma weak XDMAC1_IrqHandler=Dummy_Handler
#pragma weak LCDC_IrqHandler=Dummy_Handler
#pragma weak ISI_IrqHandler=Dummy_Handler
#pragma weak TRNG_IrqHandler=Dummy_Handler
#pragma weak GMAC0_IrqHandler=Dummy_Handler
#pragma weak GMAC1_IrqHandler=Dummy_Handler
#pragma weak AIC0_IrqHandler=Dummy_Handler
#pragma weak SFC_IrqHandler=Dummy_Handler             
#pragma weak SECURAM_IrqHandler=Dummy_Handler
#pragma weak CTB_IrqHandler=Dummy_Handler
#pragma weak SMD_IrqHandler=Dummy_Handler 
#pragma weak TWI3_IrqHandler=Dummy_Handler
#pragma weak CATB_IrqHandler=Dummy_Handler
#pragma weak SFR_IrqHandler=Dummy_Handler
#pragma weak AIC1_IrqHandler=Dummy_Handler
#pragma weak SAIC1_IrqHandler=Dummy_Handler
#pragma weak L2CC_IrqHandler=Dummy_Handler
#pragma weak Spurious_handler=Dummy_Handler

//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------



// -----------------------------------------------------------------------------
// IT management
//  Function Name : IT_Init
// -----------------------------------------------------------------------------
void IT_Init (void)
{
 unsigned int i;
  
  // Assign handler addesses
  AIC->AIC_SSR = 0;  AIC->AIC_SVR = (unsigned int) SAIC0_Handler;
  AIC->AIC_SSR = 1;  AIC->AIC_SVR = (unsigned int) SYS_IrqHandler;
  AIC->AIC_SSR = 2;  AIC->AIC_SVR = (unsigned int) ARM_IrqHandler;
  AIC->AIC_SSR = 3;  AIC->AIC_SVR = (unsigned int) PIT_IrqHandler;
  AIC->AIC_SSR = 4;  AIC->AIC_SVR = (unsigned int) WDT_IrqHandler;
  AIC->AIC_SSR = 5;  AIC->AIC_SVR = (unsigned int) PIOD_IrqHandler;
  AIC->AIC_SSR = 6;  AIC->AIC_SVR = (unsigned int) USART0_IrqHandler;
  AIC->AIC_SSR = 7;  AIC->AIC_SVR = (unsigned int) USART1_IrqHandler;
  AIC->AIC_SSR = 8;  AIC->AIC_SVR = (unsigned int) XDMAC0_IrqHandler;
  AIC->AIC_SSR = 9;  AIC->AIC_SVR = (unsigned int) ICM_IrqHandler;
  AIC->AIC_SSR = 10; AIC->AIC_SVR = (unsigned int) PKCC_IrqHandler;
  AIC->AIC_SSR = 11; AIC->AIC_SVR = (unsigned int) SCI_IrqHandler;
  AIC->AIC_SSR = 12; AIC->AIC_SVR = (unsigned int) AES_IrqHandler;
  AIC->AIC_SSR = 13; AIC->AIC_SVR = (unsigned int) AESOTF_IrqHandler;
  AIC->AIC_SSR = 14; AIC->AIC_SVR = (unsigned int) TDES_IrqHandler;
  AIC->AIC_SSR = 15; AIC->AIC_SVR = (unsigned int) SHA_IrqHandler;
  AIC->AIC_SSR = 16; AIC->AIC_SVR = (unsigned int) MPDDRC_IrqHandler;
  AIC->AIC_SSR = 17; AIC->AIC_SVR = (unsigned int) H32MX_IrqHandler;
  AIC->AIC_SSR = 18; AIC->AIC_SVR = (unsigned int) H64MX_IrqHandler;
  AIC->AIC_SSR = 19; AIC->AIC_SVR = (unsigned int) VDEC_IrqHandler;
  AIC->AIC_SSR = 20; AIC->AIC_SVR = (unsigned int) SECUMOD_IrqHandler;
  AIC->AIC_SSR = 21; AIC->AIC_SVR = (unsigned int) MSADCC_IrqHandler;
  AIC->AIC_SSR = 22; AIC->AIC_SVR = (unsigned int) HSMC_IrqHandler;
  AIC->AIC_SSR = 23; AIC->AIC_SVR = (unsigned int) PIOA_IrqHandler;
  AIC->AIC_SSR = 24; AIC->AIC_SVR = (unsigned int) PIOB_IrqHandler;
  AIC->AIC_SSR = 25; AIC->AIC_SVR = (unsigned int) PIOC_IrqHandler;
  AIC->AIC_SSR = 26; AIC->AIC_SVR = (unsigned int) PIOE_IrqHandler;
  AIC->AIC_SSR = 27; AIC->AIC_SVR = (unsigned int) UART0_IrqHandler;
  AIC->AIC_SSR = 28; AIC->AIC_SVR = (unsigned int) UART1_IrqHandler;
  AIC->AIC_SSR = 29; AIC->AIC_SVR = (unsigned int) USART2_IrqHandler;
  AIC->AIC_SSR = 30; AIC->AIC_SVR = (unsigned int) USART3_IrqHandler;
  AIC->AIC_SSR = 31; AIC->AIC_SVR = (unsigned int) USART4_IrqHandler;
  AIC->AIC_SSR = 32; AIC->AIC_SVR = (unsigned int) TWI0_IrqHandler;
  AIC->AIC_SSR = 33; AIC->AIC_SVR = (unsigned int) TWI1_IrqHandler;
  AIC->AIC_SSR = 34; AIC->AIC_SVR = (unsigned int) TWI2_IrqHandler;
  AIC->AIC_SSR = 35; AIC->AIC_SVR = (unsigned int) HSMCI0_IrqHandler;
  AIC->AIC_SSR = 36; AIC->AIC_SVR = (unsigned int) HSMCI1_IrqHandler;
  AIC->AIC_SSR = 37; AIC->AIC_SVR = (unsigned int) SPI0_IrqHandler;
  AIC->AIC_SSR = 38; AIC->AIC_SVR = (unsigned int) SPI1_IrqHandler;
  AIC->AIC_SSR = 39; AIC->AIC_SVR = (unsigned int) SPI2_IrqHandler;
  AIC->AIC_SSR = 40; AIC->AIC_SVR = (unsigned int) TC0_IrqHandler;
  AIC->AIC_SSR = 41; AIC->AIC_SVR = (unsigned int) TC1_IrqHandler;
  AIC->AIC_SSR = 42; AIC->AIC_SVR = (unsigned int) TC2_IrqHandler;
  AIC->AIC_SSR = 43; AIC->AIC_SVR = (unsigned int) PWM_IrqHandler;
  AIC->AIC_SSR = 44; AIC->AIC_SVR = (unsigned int) ADC_IrqHandler;
  AIC->AIC_SSR = 45; AIC->AIC_SVR = (unsigned int) DBGU_IrqHandler;
  AIC->AIC_SSR = 46; AIC->AIC_SVR = (unsigned int) UHPHS_IrqHandler;
  AIC->AIC_SSR = 47; AIC->AIC_SVR = (unsigned int) UDPHS_IrqHandler;
  AIC->AIC_SSR = 48; AIC->AIC_SVR = (unsigned int) SSC0_IrqHandler;
  AIC->AIC_SSR = 49; AIC->AIC_SVR = (unsigned int) SSC1_IrqHandler;
  AIC->AIC_SSR = 50; AIC->AIC_SVR = (unsigned int) XDMAC1_IrqHandler;
  AIC->AIC_SSR = 51; AIC->AIC_SVR = (unsigned int) LCDC_IrqHandler;
  AIC->AIC_SSR = 52; AIC->AIC_SVR = (unsigned int) ISI_IrqHandler;
  AIC->AIC_SSR = 53; AIC->AIC_SVR = (unsigned int) TRNG_IrqHandler;
  AIC->AIC_SSR = 54; AIC->AIC_SVR = (unsigned int) GMAC0_IrqHandler;
  AIC->AIC_SSR = 55; AIC->AIC_SVR = (unsigned int) GMAC1_IrqHandler;
  AIC->AIC_SSR = 56; AIC->AIC_SVR = (unsigned int) AIC0_IrqHandler;
  AIC->AIC_SSR = 57; AIC->AIC_SVR = (unsigned int) SFC_IrqHandler;
  AIC->AIC_SSR = 59; AIC->AIC_SVR = (unsigned int) SECURAM_IrqHandler;
  AIC->AIC_SSR = 60; AIC->AIC_SVR = (unsigned int) CTB_IrqHandler;
  AIC->AIC_SSR = 61; AIC->AIC_SVR = (unsigned int) SMD_IrqHandler;
  AIC->AIC_SSR = 62; AIC->AIC_SVR = (unsigned int) TWI3_IrqHandler;
  AIC->AIC_SSR = 63; AIC->AIC_SVR = (unsigned int) CATB_IrqHandler;
  AIC->AIC_SSR = 64; AIC->AIC_SVR = (unsigned int) SFR_IrqHandler;
  AIC->AIC_SSR = 65; AIC->AIC_SVR = (unsigned int) AIC1_IrqHandler;
  AIC->AIC_SSR = 66; AIC->AIC_SVR = (unsigned int) SAIC1_IrqHandler;
  AIC->AIC_SSR = 67; AIC->AIC_SVR = (unsigned int) L2CC_IrqHandler;

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
  SAIC->AIC_SSR = 0;  SAIC->AIC_SVR = (unsigned int) SAIC0_Handler;
  SAIC->AIC_SSR = 1;  SAIC->AIC_SVR = (unsigned int) SYS_IrqHandler;
  SAIC->AIC_SSR = 2;  SAIC->AIC_SVR = (unsigned int) ARM_IrqHandler;
  SAIC->AIC_SSR = 3;  SAIC->AIC_SVR = (unsigned int) PIT_IrqHandler;
  SAIC->AIC_SSR = 4;  SAIC->AIC_SVR = (unsigned int) WDT_IrqHandler;
  SAIC->AIC_SSR = 5;  SAIC->AIC_SVR = (unsigned int) PIOD_IrqHandler;
  SAIC->AIC_SSR = 6;  SAIC->AIC_SVR = (unsigned int) USART0_IrqHandler;
  SAIC->AIC_SSR = 7;  SAIC->AIC_SVR = (unsigned int) USART1_IrqHandler;
  SAIC->AIC_SSR = 8;  SAIC->AIC_SVR = (unsigned int) XDMAC0_IrqHandler;
  SAIC->AIC_SSR = 9;  SAIC->AIC_SVR = (unsigned int) ICM_IrqHandler;
  SAIC->AIC_SSR = 10; SAIC->AIC_SVR = (unsigned int) PKCC_IrqHandler;
  SAIC->AIC_SSR = 11; SAIC->AIC_SVR = (unsigned int) SCI_IrqHandler;
  SAIC->AIC_SSR = 12; SAIC->AIC_SVR = (unsigned int) AES_IrqHandler;
  SAIC->AIC_SSR = 13; SAIC->AIC_SVR = (unsigned int) AESOTF_IrqHandler;
  SAIC->AIC_SSR = 14; SAIC->AIC_SVR = (unsigned int) TDES_IrqHandler;
  SAIC->AIC_SSR = 15; SAIC->AIC_SVR = (unsigned int) SHA_IrqHandler;
  SAIC->AIC_SSR = 16; SAIC->AIC_SVR = (unsigned int) MPDDRC_IrqHandler;
  SAIC->AIC_SSR = 17; SAIC->AIC_SVR = (unsigned int) H32MX_IrqHandler;
  SAIC->AIC_SSR = 18; SAIC->AIC_SVR = (unsigned int) H64MX_IrqHandler;
  SAIC->AIC_SSR = 19; SAIC->AIC_SVR = (unsigned int) VDEC_IrqHandler;
  SAIC->AIC_SSR = 20; SAIC->AIC_SVR = (unsigned int) SECUMOD_IrqHandler;
  SAIC->AIC_SSR = 21; SAIC->AIC_SVR = (unsigned int) MSADCC_IrqHandler;
  SAIC->AIC_SSR = 22; SAIC->AIC_SVR = (unsigned int) HSMC_IrqHandler;
  SAIC->AIC_SSR = 23; SAIC->AIC_SVR = (unsigned int) PIOA_IrqHandler;
  SAIC->AIC_SSR = 24; SAIC->AIC_SVR = (unsigned int) PIOB_IrqHandler;
  SAIC->AIC_SSR = 25; SAIC->AIC_SVR = (unsigned int) PIOC_IrqHandler;
  SAIC->AIC_SSR = 26; SAIC->AIC_SVR = (unsigned int) PIOE_IrqHandler;
  SAIC->AIC_SSR = 27; SAIC->AIC_SVR = (unsigned int) UART0_IrqHandler;
  SAIC->AIC_SSR = 28; SAIC->AIC_SVR = (unsigned int) UART1_IrqHandler;
  SAIC->AIC_SSR = 29; SAIC->AIC_SVR = (unsigned int) USART2_IrqHandler;
  SAIC->AIC_SSR = 30; SAIC->AIC_SVR = (unsigned int) USART3_IrqHandler;
  SAIC->AIC_SSR = 31; SAIC->AIC_SVR = (unsigned int) USART4_IrqHandler;
  SAIC->AIC_SSR = 32; SAIC->AIC_SVR = (unsigned int) TWI0_IrqHandler;
  SAIC->AIC_SSR = 33; SAIC->AIC_SVR = (unsigned int) TWI1_IrqHandler;
  SAIC->AIC_SSR = 34; SAIC->AIC_SVR = (unsigned int) TWI2_IrqHandler;
  SAIC->AIC_SSR = 35; SAIC->AIC_SVR = (unsigned int) HSMCI0_IrqHandler;
  SAIC->AIC_SSR = 36; SAIC->AIC_SVR = (unsigned int) HSMCI1_IrqHandler;
  SAIC->AIC_SSR = 37; SAIC->AIC_SVR = (unsigned int) SPI0_IrqHandler;
  SAIC->AIC_SSR = 38; SAIC->AIC_SVR = (unsigned int) SPI1_IrqHandler;
  SAIC->AIC_SSR = 39; SAIC->AIC_SVR = (unsigned int) SPI2_IrqHandler;
  SAIC->AIC_SSR = 40; SAIC->AIC_SVR = (unsigned int) TC0_IrqHandler;
  SAIC->AIC_SSR = 41; SAIC->AIC_SVR = (unsigned int) TC1_IrqHandler;
  SAIC->AIC_SSR = 42; SAIC->AIC_SVR = (unsigned int) TC2_IrqHandler;
  SAIC->AIC_SSR = 43; SAIC->AIC_SVR = (unsigned int) PWM_IrqHandler;
  SAIC->AIC_SSR = 44; SAIC->AIC_SVR = (unsigned int) ADC_IrqHandler;
  SAIC->AIC_SSR = 45; SAIC->AIC_SVR = (unsigned int) DBGU_IrqHandler;
  SAIC->AIC_SSR = 46; SAIC->AIC_SVR = (unsigned int) UHPHS_IrqHandler;
  SAIC->AIC_SSR = 47; SAIC->AIC_SVR = (unsigned int) UDPHS_IrqHandler;
  SAIC->AIC_SSR = 48; SAIC->AIC_SVR = (unsigned int) SSC0_IrqHandler;
  SAIC->AIC_SSR = 49; SAIC->AIC_SVR = (unsigned int) SSC1_IrqHandler;
  SAIC->AIC_SSR = 50; SAIC->AIC_SVR = (unsigned int) XDMAC1_IrqHandler;
  SAIC->AIC_SSR = 51; SAIC->AIC_SVR = (unsigned int) LCDC_IrqHandler;
  SAIC->AIC_SSR = 52; SAIC->AIC_SVR = (unsigned int) ISI_IrqHandler;
  SAIC->AIC_SSR = 53; SAIC->AIC_SVR = (unsigned int) TRNG_IrqHandler;
  SAIC->AIC_SSR = 54; SAIC->AIC_SVR = (unsigned int) GMAC0_IrqHandler;
  SAIC->AIC_SSR = 55; SAIC->AIC_SVR = (unsigned int) GMAC1_IrqHandler;
  SAIC->AIC_SSR = 56; SAIC->AIC_SVR = (unsigned int) AIC0_IrqHandler;
  SAIC->AIC_SSR = 57; SAIC->AIC_SVR = (unsigned int) SFC_IrqHandler;
  SAIC->AIC_SSR = 59; SAIC->AIC_SVR = (unsigned int) SECURAM_IrqHandler;
  SAIC->AIC_SSR = 60; SAIC->AIC_SVR = (unsigned int) CTB_IrqHandler;
  SAIC->AIC_SSR = 61; SAIC->AIC_SVR = (unsigned int) SMD_IrqHandler;
  SAIC->AIC_SSR = 62; SAIC->AIC_SVR = (unsigned int) TWI3_IrqHandler;
  SAIC->AIC_SSR = 63; SAIC->AIC_SVR = (unsigned int) CATB_IrqHandler;
  SAIC->AIC_SSR = 64; SAIC->AIC_SVR = (unsigned int) SFR_IrqHandler;
  SAIC->AIC_SSR = 65; SAIC->AIC_SVR = (unsigned int) AIC1_IrqHandler;
  SAIC->AIC_SSR = 66; SAIC->AIC_SVR = (unsigned int) SAIC1_IrqHandler;
  SAIC->AIC_SSR = 67; SAIC->AIC_SVR = (unsigned int) L2CC_IrqHandler;

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
   read_reg |= PMC_MCKR_CSS_MAIN_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   
   // restore HW startup clock settings if ROMBOOT was executed (RAM debug)
   REG_CKGR_MOR = CKGR_MOR_KEY(MOR_KEY_VAL)         |
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
//  Function Name : clock_config
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

