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
// SAMG53
// ---------------------- (file created for SAMG53) ---------------------------
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
   REG_EFC_FMR |= EEFC_FMR_FWS(0xF); // 6 Wait states, other fields=0 (defaults)
#endif
#ifdef REG_EFC0_FMR
   REG_EFC0_FMR |= EEFC_FMR_FWS(0xF); // 6 Wait states, other fields=0 (defaults)
#endif
#ifdef REG_EFC1_FMR
   REG_EFC1_FMR |= EEFC_FMR_FWS(0xF); // 6 Wait states, other fields=0 (defaults)
#endif
   
   //  --------- unprotec PMC
   REG_PMC_WPMR = PMC_WPMR_WPKEY_PASSWD | 0x00; 
   
   //  --------- select Slow clock as input clock for MCK
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_SLOW_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );//CJn
   
   
   // restore HW startup clock settings if ROMBOOT was executed (RAM debug)
   //REG_CKGR_MOR = CKGR_MOR_KEY(MOR_KEY_VAL)         |
   REG_CKGR_MOR = CKGR_MOR_KEY_PASSWD    |
                  CKGR_MOR_MOSCXTST(0xFF)| // ERr(0x3F<<8)|
                  CKGR_MOR_MOSCRCF_8_MHz |
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

//FLEXCOMX handlers 

#pragma weak FLEXCOM0_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM1_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM2_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM3_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM4_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM5_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM6_Handler=FLEXCOM_Handler
#pragma weak FLEXCOM7_Handler=FLEXCOM_Handler


/* Cortex-M4 core handlers */
////#pragma weak Reset_Handler=Dummy_Handler
//#pragma weak NMI_Handler
//#pragma weak HardFault_Handler
//#pragma weak MemManage_Handler
//#pragma weak BusFault_Handler
//#pragma weak UsageFault_Handler
//#pragma weak SVC_Handler
//#pragma weak DebugMon_Handler
//#pragma weak PendSV_Handler
//#pragma weak SysTick_Handler
//#pragma weak IrqHandlerNotUsed

/* Peripherals handlers */
#pragma weak SUPC_Handler=Dummy_Handler
#pragma weak RSTC_Handler=Dummy_Handler
#pragma weak RTC_Handler=Dummy_Handler
#pragma weak RTT_Handler=Dummy_Handler
#pragma weak WDT_Handler=Dummy_Handler
#pragma weak PMC_Handler=Dummy_Handler
#pragma weak EFC_Handler=Dummy_Handler
//#ifdef _SAMG55_USART7_INSTANCE_
//#pragma weak USART7_Handler=FLEXCOM7_Handler
//#endif /* _SAMG55_USART7_INSTANCE_ */
//#ifdef _SAMG55_SPI7_INSTANCE_
//#pragma weak SPI7_Handler=FLEXCOM7_Handler
//#endif /* _SAMG55_SPI7_INSTANCE_ */
//#ifdef _SAMG55_TWI7_INSTANCE_
//#pragma weak TWI7_Handler=FLEXCOM7_Handler
//#endif /* _SAMG55_TWI7_INSTANCE_ */
//#pragma weak USART0_Handler=FLEXCOM0_Handler
//#pragma weak SPI0_Handler=FLEXCOM0_Handler
//#pragma weak TWI0_Handler=FLEXCOM0_Handler
//#pragma weak USART1_Handler=FLEXCOM1_Handler
//#pragma weak SPI1_Handler=FLEXCOM1_Handler
//#pragma weak TWI1_Handler=FLEXCOM1_Handler
#pragma weak PIOA_Handler=Dummy_Handler
#pragma weak PIOB_Handler=Dummy_Handler
#pragma weak PDMIC0_Handler=Dummy_Handler
//#pragma weak USART2_Handler=FLEXCOM2_Handler
//#pragma weak SPI2_Handler=FLEXCOM2_Handler
//#pragma weak TWI2_Handler=FLEXCOM2_Handler
#pragma weak MEM2MEM_Handler=Dummy_Handler
#pragma weak I2SC0_Handler=Dummy_Handler
#pragma weak I2SC1_Handler=Dummy_Handler
#pragma weak PDMIC1_Handler=Dummy_Handler
//#pragma weak USART3_Handler=FLEXCOM3_Handler
//#pragma weak SPI3_Handler=FLEXCOM3_Handler
//#pragma weak TWI3_Handler=FLEXCOM3_Handler
//#pragma weak USART4_Handler=FLEXCOM4_Handler
//#pragma weak SPI4_Handler=FLEXCOM4_Handler
//#pragma weak TWI4_Handler=FLEXCOM4_Handler
//#pragma weak USART5_Handler=FLEXCOM5_Handler
//#pragma weak SPI5_Handler=FLEXCOM5_Handler
//#pragma weak TWI5_Handler=FLEXCOM5_Handler
//#pragma weak USART6_Handler=FLEXCOM6_Handler
//#pragma weak SPI6_Handler=FLEXCOM6_Handler
//#pragma weak TWI6_Handler=FLEXCOM6_Handler
#pragma weak TC0_Handler=Dummy_Handler
#pragma weak TC1_Handler=Dummy_Handler
#pragma weak TC2_Handler=Dummy_Handler
#pragma weak TC3_Handler=Dummy_Handler
#pragma weak TC4_Handler=Dummy_Handler
#pragma weak TC5_Handler=Dummy_Handler
#pragma weak ADC_Handler=Dummy_Handler
#pragma weak ARM_Handler=Dummy_Handler
#pragma weak UHP_Handler=Dummy_Handler
#pragma weak UDP_Handler=Dummy_Handler





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
void FLEXCOM_Handler(void)
{
  while(1);
}

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
        SUPC_Handler,    /* 0+16  Supply Controller */
        RSTC_Handler,    /* 1  Reset Controller */
        RTC_Handler,     /* 2  Real Time Clock */
        RTT_Handler,     /* 3  Real Time Timer */
        WDT_Handler,     /* 4  Watchdog Timer */
        PMC_Handler,     /* 5  Power Management Controller */
        EFC_Handler,     /* 6  Enhanced Flash Controller */
        
        FLEXCOM7_Handler,  /* 7  FLEXCOM 7 */           
//        USART7_Handler,  // 7  FLEXCOM 7 
//        SPI7_Handler,    // 7  FLEXCOM 7
//        TWI7_Handler,    /* 7  FLEXCOM 7 */ 
          
          FLEXCOM0_Handler, /* 8  FLEXCOM 0 */ 
//        USART0_Handler,  /* 8  FLEXCOM 0 */
//        SPI0_Handler,    /* 8  FLEXCOM 0 */
//        TWI0_Handler,    /* 8  FLEXCOM 0 */
        
        FLEXCOM1_Handler, /* 9  FLEXCOM 1 */ 
//        USART1_Handler,  /* 9  FLEXCOM 1 */
//        SPI1_Handler,    /* 9  FLEXCOM 1 */
//        TWI1_Handler,    /* 9  FLEXCOM 1 */
        (0UL),           /* 10 Reserved */
        PIOA_Handler,    /* 11 Parallel I/O Controller A */
        PIOB_Handler,    /* 12 Parallel I/O Controller B */
        PDMIC0_Handler,  /* 13 PDM 0 */
        FLEXCOM2_Handler, /* 14  FLEXCOM 2 */
//        USART2_Handler,  /* 14 FLEXCOM2 */
//        SPI2_Handler,    /* 14 FLEXCOM2 */
//        TWI2_Handler,    /* 14 FLEXCOM2 */
        MEM2MEM_Handler, /* 15 MEM2MEM */
        I2SC0_Handler,   /* 16 I2SC0 */
        I2SC1_Handler,   /* 17 I2SC1 */
        PDMIC1_Handler,  /* 18 PDM 1 */
        FLEXCOM3_Handler, /* 19  FLEXCOM 3 */
//        USART3_Handler,  /* 19 FLEXCOM3 */
//        SPI3_Handler,    /* 19 FLEXCOM3 */
//        TWI3_Handler,    /* 19 FLEXCOM3 */
        FLEXCOM4_Handler, /* 20  FLEXCOM 4 */
//        USART4_Handler,  /* 20 FLEXCOM4 */
//        SPI4_Handler,    /* 20 FLEXCOM4 */
//        TWI4_Handler,    /* 20 FLEXCOM4 */
        FLEXCOM5_Handler, /* 21  FLEXCOM 5 */
//        USART5_Handler,  /* 21 FLEXCOM5 */
//        SPI5_Handler,    /* 21 FLEXCOM5 */
//        TWI5_Handler,    /* 21 FLEXCOM5 */
        FLEXCOM6_Handler, /* 22  FLEXCOM 6 */
//        USART6_Handler,  /* 22 FLEXCOM6 */
//        SPI6_Handler,    /* 22 FLEXCOM6 */
//        TWI6_Handler,    /* 22 FLEXCOM6 */
        TC0_Handler,     /* 23 Timer/Counter 0 */
        TC1_Handler,     /* 24 Timer/Counter 1 */
        TC2_Handler,     /* 25 Timer/Counter 2 */
        TC3_Handler,     /* 26 Timer/Counter 3 */
        TC4_Handler,     /* 27 Timer/Counter 4 */
        TC5_Handler,     /* 28 Timer/Counter 5 */
        ADC_Handler,     /* 29 Analog To Digital Converter */
        ARM_Handler,     /* 30 FPU */
        (0UL),           /* 31 Reserved */
        (0UL),           /* 32 Reserved */
        (0UL),           /* 33 Reserved */
        (0UL),           /* 34 Reserved */
        (0UL),           /* 35 Reserved */
        (0UL),           /* 36 Reserved */
        (0UL),           /* 37 Reserved */
        (0UL),           /* 38 Reserved */
        (0UL),           /* 39 Reserved */
        (0UL),           /* 40 Reserved */
        (0UL),           /* 41 Reserved */
        (0UL),           /* 42 Reserved */
        (0UL),           /* 43 Reserved */
        (0UL),           /* 44 Reserved */
        (0UL),           /* 45 Reserved */
        (0UL),           /* 46 Reserved */
        UHP_Handler,     /* 47 USB OHCI */
        UDP_Handler,     /* 48 USB Device FS */
        (0UL)            /* 49 Reserved */
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
        SUPC_Handler,    /* 0+16  Supply Controller */
        RSTC_Handler,    /* 1  Reset Controller */
        RTC_Handler,     /* 2  Real Time Clock */
        RTT_Handler,     /* 3  Real Time Timer */
        WDT_Handler,     /* 4  Watchdog Timer */
        PMC_Handler,     /* 5  Power Management Controller */
        EFC_Handler,     /* 6  Enhanced Flash Controller */
        
        FLEXCOM7_Handler,  /* 7  FLEXCOM 7 */           
//        USART7_Handler,  // 7  FLEXCOM 7 
//        SPI7_Handler,    // 7  FLEXCOM 7
//        TWI7_Handler,    /* 7  FLEXCOM 7 */ 
          
          FLEXCOM0_Handler, /* 8  FLEXCOM 0 */ 
//        USART0_Handler,  /* 8  FLEXCOM 0 */
//        SPI0_Handler,    /* 8  FLEXCOM 0 */
//        TWI0_Handler,    /* 8  FLEXCOM 0 */
        
        FLEXCOM1_Handler, /* 9  FLEXCOM 1 */ 
//        USART1_Handler,  /* 9  FLEXCOM 1 */
//        SPI1_Handler,    /* 9  FLEXCOM 1 */
//        TWI1_Handler,    /* 9  FLEXCOM 1 */
        (0UL),           /* 10 Reserved */
        PIOA_Handler,    /* 11 Parallel I/O Controller A */
        PIOB_Handler,    /* 12 Parallel I/O Controller B */
        PDMIC0_Handler,  /* 13 PDM 0 */
        FLEXCOM2_Handler, /* 14  FLEXCOM 2 */
//        USART2_Handler,  /* 14 FLEXCOM2 */
//        SPI2_Handler,    /* 14 FLEXCOM2 */
//        TWI2_Handler,    /* 14 FLEXCOM2 */
        MEM2MEM_Handler, /* 15 MEM2MEM */
        I2SC0_Handler,   /* 16 I2SC0 */
        I2SC1_Handler,   /* 17 I2SC1 */
        PDMIC1_Handler,  /* 18 PDM 1 */
        FLEXCOM3_Handler, /* 19  FLEXCOM 3 */
//        USART3_Handler,  /* 19 FLEXCOM3 */
//        SPI3_Handler,    /* 19 FLEXCOM3 */
//        TWI3_Handler,    /* 19 FLEXCOM3 */
        FLEXCOM4_Handler, /* 20  FLEXCOM 4 */
//        USART4_Handler,  /* 20 FLEXCOM4 */
//        SPI4_Handler,    /* 20 FLEXCOM4 */
//        TWI4_Handler,    /* 20 FLEXCOM4 */
        FLEXCOM5_Handler, /* 21  FLEXCOM 5 */
//        USART5_Handler,  /* 21 FLEXCOM5 */
//        SPI5_Handler,    /* 21 FLEXCOM5 */
//        TWI5_Handler,    /* 21 FLEXCOM5 */
        FLEXCOM6_Handler, /* 22  FLEXCOM 6 */
//        USART6_Handler,  /* 22 FLEXCOM6 */
//        SPI6_Handler,    /* 22 FLEXCOM6 */
//        TWI6_Handler,    /* 22 FLEXCOM6 */
        TC0_Handler,     /* 23 Timer/Counter 0 */
        TC1_Handler,     /* 24 Timer/Counter 1 */
        TC2_Handler,     /* 25 Timer/Counter 2 */
        TC3_Handler,     /* 26 Timer/Counter 3 */
        TC4_Handler,     /* 27 Timer/Counter 4 */
        TC5_Handler,     /* 28 Timer/Counter 5 */
        ADC_Handler,     /* 29 Analog To Digital Converter */
        ARM_Handler,     /* 30 FPU */
        (0UL),           /* 31 Reserved */
        (0UL),           /* 32 Reserved */
        (0UL),           /* 33 Reserved */
        (0UL),           /* 34 Reserved */
        (0UL),           /* 35 Reserved */
        (0UL),           /* 36 Reserved */
        (0UL),           /* 37 Reserved */
        (0UL),           /* 38 Reserved */
        (0UL),           /* 39 Reserved */
        (0UL),           /* 40 Reserved */
        (0UL),           /* 41 Reserved */
        (0UL),           /* 42 Reserved */
        (0UL),           /* 43 Reserved */
        (0UL),           /* 44 Reserved */
        (0UL),           /* 45 Reserved */
        (0UL),           /* 46 Reserved */
        UHP_Handler,     /* 47 USB OHCI */
        UDP_Handler,     /* 48 USB Device FS */
        (0UL)            /* 49 Reserved */
};


//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


