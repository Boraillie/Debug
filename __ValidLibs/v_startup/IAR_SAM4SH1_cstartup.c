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
// Updated for SOC : AYi 10/01/2013


// ------ Compatibility list (compliant devices) ------------------------------
// SAM4SH1
// ---------------------- (file created for SAM4SH1) ----------------------------
//-----------------------------------------------------------------------------


#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "exceptions.h"


//------------------------------------------------------------------------------
/// This is the code that gets called on processor reset. To initialize the
/// device.
//------------------------------------------------------------------------------
//#define AT91C_EFC_FWS_6WS (6  <<  8) // (EFC) 6 Wait States

int __low_level_init( void )
{  
   unsigned int  read_reg;
   
       
   //  --------- EFC Init
   //REG_EFC_FMR = AT91C_EFC_FWS_6WS; // 1 Wait State necessary to work at more than 30 MHz
#ifdef REG_EFC_FMR
   REG_EFC_FMR = EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
#endif
#ifdef REG_EFC0_FMR
   REG_EFC0_FMR = EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
#endif
#ifdef REG_EFC1_FMR
   REG_EFC1_FMR = EEFC_FMR_FWS(6); // 6 Wait states, other fields=0 (defaults)
#endif
   
   
   //  --------- select Slow clock as input clock for MCK
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_SLOW_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   
   // restore HW startup clock settings if ROMBOOT was executed (RAM debug)
   REG_CKGR_MOR = CKGR_MOR_KEY(MOR_KEY_VAL)         |
                             CKGR_MOR_MOSCXTST(0xFF)| // ERr(0x3F<<8)|
                             CKGR_MOR_MOSCRCF_8_MHz  |
                             CKGR_MOR_MOSCRCEN      ;//|
                             //CKGR_MOR_MOSCXTEN      ;

   while( !(REG_PMC_SR & PMC_SR_MOSCRCS) );//CJn

   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_PRES_Msk;
   read_reg |= PMC_MCKR_PRES_CLK_1;
   REG_PMC_MCKR = read_reg;
   //---------------------------------
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_MAIN_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn

   
  return 1; 
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
/// Exceptions handlers
//------------------------------------------------------------------------------
/* Cortex-M4 core handlers */
//#pragma weak Reset_Handler=Dummy_Handler
#pragma weak NMI_Handler
#pragma weak HardFault_Handler
#pragma weak MemManage_Handler
#pragma weak BusFault_Handler
#pragma weak UsageFault_Handler
#pragma weak SVC_Handler
#pragma weak DebugMon_Handler
#pragma weak PendSV_Handler
#pragma weak SysTick_Handler
#pragma weak IrqHandlerNotUsed

/* Peripherals handlers */
#pragma weak SUPC_IrqHandler	=Dummy_Handler   
#pragma weak RSTC_IrqHandler	=Dummy_Handler 
#pragma weak RTC_IrqHandler	=Dummy_Handler 
#pragma weak RTT_IrqHandler	=Dummy_Handler
#pragma weak WDT_IrqHandler	=Dummy_Handler
#pragma weak PMC_IrqHandler	=Dummy_Handler
#pragma weak EFC_IrqHandler	=Dummy_Handler
#pragma weak UART0_IrqHandler	=Dummy_Handler
#pragma weak UART1_IrqHandler	=Dummy_Handler2
#pragma weak PIOA_IrqHandler	=Dummy_Handler
#pragma weak PIOB_IrqHandler	=Dummy_Handler
#pragma weak USART_IrqHandler	=Dummy_Handler
#pragma weak MEM2MEM_IrqHandler =Dummy_Handler
#pragma weak TWI0_IrqHandler	=Dummy_Handler
#pragma weak TWI1_IrqHandler	=Dummy_Handler
#pragma weak SPI_IrqHandler	=Dummy_Handler
#pragma weak TWI2_IrqHandler	=Dummy_Handler 
#pragma weak TC0_IrqHandler	=Dummy_Handler
#pragma weak TC1_IrqHandler	=Dummy_Handler 
#pragma weak TC2_IrqHandler	=Dummy_Handler 
#pragma weak ADC_IrqHandler	=Dummy_Handler
#pragma weak ARM_IrqHandler  	=Dummy_Handler 
#pragma weak ARM_IrqHandler  	=Dummy_Handler  

//------------------------------------------------------------------------------
/// Exceptions default routines
//------------------------------------------------------------------------------
void NMI_Handler(void) {   
    while(1);
}
//------------------------------------------------------------------------------
void HardFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void MemManage_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void BusFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void UsageFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void SVC_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void DebugMon_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void PendSV_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
void SysTick_Handler( void ){
      while(1);
}
//------------------------------------------------------------------------------
void IrqHandlerNotUsed(void){
    while(1);
}
//------------------------------------------------------------------------------
void IrqDBGUBHandler(void) {   
    while(1);
}
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Exception Vector Tables -----------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#pragma language=extended
#pragma segment="CSTACK"

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

extern int  __low_level_init( void );
extern void main( void );
extern void __iar_program_start( void );


//------------------------------------------------------------------------------
#pragma location = ".intvec"
#pragma data_alignment=0x100
const intvec_elem __vector_table[] =
{
  { .__ptr = __sfe( "CSTACK" ) },
  __iar_program_start,
  
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  (0UL),           /* Reserved */
  (0UL),           /* Reserved */
  (0UL),           /* Reserved */
  (0UL),           /* Reserved */
  SVC_Handler,
  DebugMon_Handler,
  (0UL),           /* Reserved */
  PendSV_Handler,
  SysTick_Handler,
  
  /* Configurable interrupts */
  SUPC_IrqHandler,    /* 0  Supply Controller */
  RSTC_IrqHandler,    /* 1  Reset Controller */
  RTC_IrqHandler,     /* 2  Real Time Clock */
  RTT_IrqHandler,     /* 3  Real Time Timer */
  WDT_IrqHandler,     /* 4  Watchdog Timer */
  PMC_IrqHandler,     /* 5  Power Management Controller */
  EFC_IrqHandler,     /* 6  Enhanced Flash Controller */
  (0UL),              /* 7  Reserved */
  UART0_IrqHandler,   /* 8  UART 0 */
  UART1_IrqHandler,   /* 9  UART 1 */
  (0UL),              /* 10  Reserved */
  PIOA_IrqHandler,    /* 11 Parallel I/O Controller A */
  PIOB_IrqHandler,    /* 12 Parallel I/O Controller B */
  (0UL),              /* 13  Reserved */
  USART_IrqHandler,   /* 14 USART */
  MEM2MEM_IrqHandler, /* 15 MEM2MEM */
  (0UL),              /* 16  Reserved */
  (0UL),              /* 17  Reserved */
  (0UL),              /* 18  Reserved */
  TWI0_IrqHandler,    /* 19 Two Wire Interface 0 HS */
  TWI1_IrqHandler,    /* 20 Two Wire Interface 1 */
  SPI_IrqHandler,     /* 21 Serial Peripheral Interface */
  TWI2_IrqHandler,    /* 22 Two Wire Interface 2 */
  TC0_IrqHandler,     /* 23 Timer/Counter 0 */
  TC1_IrqHandler,     /* 24 Timer/Counter 1 */
  TC2_IrqHandler,     /* 25 Timer/Counter 2 */
  (0UL),              /* 26  Reserved */
  (0UL),              /* 27  Reserved */
  (0UL),              /* 28  Reserved */
  ADC_IrqHandler,     /* 29 Analog To Digital Converter */
  ARM_IrqHandler      /* 30 FPU */
};



//------------------------------------------------------------------------------
#pragma data_alignment=0x100
intvec_elem new_vector_table[] =
{
    { .__ptr = __sfe( "CSTACK" ) },
    __iar_program_start,

    NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  (0UL),           /* Reserved */
  (0UL),           /* Reserved */
  (0UL),           /* Reserved */
  (0UL),           /* Reserved */
  SVC_Handler,
  DebugMon_Handler,
  (0UL),           /* Reserved */
  PendSV_Handler,
  SysTick_Handler,
  
  /* Configurable interrupts */
  SUPC_IrqHandler,    /* 0  Supply Controller */
  RSTC_IrqHandler,    /* 1  Reset Controller */
  RTC_IrqHandler,     /* 2  Real Time Clock */
  RTT_IrqHandler,     /* 3  Real Time Timer */
  WDT_IrqHandler,     /* 4  Watchdog Timer */
  PMC_IrqHandler,     /* 5  Power Management Controller */
  EFC_IrqHandler,     /* 6  Enhanced Flash Controller */
  (0UL),              /* 7  Reserved */
  UART0_IrqHandler,   /* 8  UART 0 */
  UART1_IrqHandler,   /* 9  UART 1 */
  (0UL),              /* 10  Reserved */
  PIOA_IrqHandler,    /* 11 Parallel I/O Controller A */
  PIOB_IrqHandler,    /* 12 Parallel I/O Controller B */
  (0UL),              /* 13  Reserved */
  USART_IrqHandler,   /* 14 USART */
  MEM2MEM_IrqHandler, /* 15 MEM2MEM */
  (0UL),              /* 16  Reserved */
  (0UL),              /* 17  Reserved */
  (0UL),              /* 18  Reserved */
  TWI0_IrqHandler,    /* 19 Two Wire Interface 0 HS */
  TWI1_IrqHandler,    /* 20 Two Wire Interface 1 */
  SPI_IrqHandler,     /* 21 Serial Peripheral Interface */
  TWI2_IrqHandler,    /* 22 Two Wire Interface 2 */
  TC0_IrqHandler,     /* 23 Timer/Counter 0 */
  TC1_IrqHandler,     /* 24 Timer/Counter 1 */
  TC2_IrqHandler,     /* 25 Timer/Counter 2 */
  (0UL),              /* 26  Reserved */
  (0UL),              /* 27  Reserved */
  (0UL),              /* 28  Reserved */
  ADC_IrqHandler,     /* 29 Analog To Digital Converter */
  ARM_IrqHandler      /* 30 FPU */
};


//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
void Dummy_Handler2( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


