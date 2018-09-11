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
// Updated for SOC : AYi 2014


// ------ Compatibility list (compliant devices) ------------------------------
// CANOPUS FAMILY
// ---------------------- (file created for CANOPUS) ---------------------------
//-----------------------------------------------------------------------------

#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"
#include "exceptions.h"

#define GPNVM_TCM_CFG_Pos (7)
#define GPNVM_TCM_CFG_Msk (0x3<<7)
uint32_t gpnvm_value;


//------------------------------------------------------------------------------
/// This is the code that gets called on processor reset. To initialize the
/// device.
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
int __iar_init_vfp()
{
     return 1;
}


//#pragma location = ".cstartup" //used by prg mode linker
int __iar_init_TCM()
{
  switch(__TCM_CFG__){
    case 1: //32KB DTCM + 32KB ITCM
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB | EEFC_FCR_FARG(7));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      break;
    case 2: //64KB DTCM + 64KB ITCM
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(7));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB | EEFC_FCR_FARG(8));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      break;
    case 3: //128KB DTCM + 128KB ITCM
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB | EEFC_FCR_FARG(7));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_SGPB | EEFC_FCR_FARG(8));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      break;
    default: // default: no TCM
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(7));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      break;
    }
  
  /* ERr: moved to low_level_init function...
  if(__TCM_CFG__!=0){
    __ASM ("dsb");
    __ASM ("isb");
    SCB->DTCMCR = (SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk | SCB_DTCMCR_RETEN_Msk);
    SCB->ITCMCR = (SCB_ITCMCR_EN_Msk | SCB_ITCMCR_RMW_Msk | SCB_ITCMCR_RETEN_Msk);
    __ASM ("dsb");
    __ASM ("isb");
    }
  */
  
  return(0);
}



#pragma location = ".cstartup" //used by prg mode linker
void restore_hw_reset_settings( void )
{
 unsigned int  read_reg;
 
   //  --------- unprotect PMC
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
                  CKGR_MOR_MOSCRCF_12_MHz | //ERr 12RC is default HW setting
                  CKGR_MOR_MOSCRCEN      ;//
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
}

#pragma location = ".cstartup" //used by prg mode linker
int __low_level_init( void )
{ 
  // Read current TCM config
  EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_GGPB);
  while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
  gpnvm_value = EFC->EEFC_FRR;
  
/*
  if(gpnvm_value==0xFFFFFFFF){//ERr debug
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(8));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(7));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(6));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(5));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(4));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(3));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(2));
      while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      //EFC->EEFC_FCR = (EEFC_FCR_FKEY_PASSWD | EEFC_FCR_FCMD_CGPB | EEFC_FCR_FARG(1));
      //while(!((EFC->EEFC_FSR) & EEFC_FSR_FRDY));
      }
*/
  
  //  --------- EFC Init
  #ifdef REG_EFC_FMR
    REG_EFC_FMR |= EEFC_FMR_FWS(0xF); // F Wait states
  #endif
  #ifdef REG_EFC0_FMR3
    REG_EFC0_FMR |= EEFC_FMR_FWS(0xF); // F Wait states
  #endif
  #ifdef REG_EFC1_FMR
    REG_EFC1_FMR |= EEFC_FMR_FWS(0xF); // F Wait states
  #endif
   
  #ifdef _LINK_TO_ISRAM_ // execute only if ROM boot was executed
    restore_hw_reset_settings();
  #endif //_LINK_TO_ISRAM_

 
  // Configure GPNVM for TCM if current setting is not consistent with linker
  if(((gpnvm_value&GPNVM_TCM_CFG_Msk)>>GPNVM_TCM_CFG_Pos)!= __TCM_CFG__){
    __iar_init_TCM();
    RSTC->RSTC_CR = RSTC_CR_KEY_PASSWD | RSTC_CR_PROCRST;
    #warning Confirm SW reset (product datasheet indicate "user reboot..?)
    }
   
    if(__TCM_CFG__!=0){
    __ASM ("dsb");
    __ASM ("isb");
    SCB->DTCMCR = (SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk | SCB_DTCMCR_RETEN_Msk);
    SCB->ITCMCR = (SCB_ITCMCR_EN_Msk | SCB_ITCMCR_RMW_Msk | SCB_ITCMCR_RETEN_Msk);
    __ASM ("dsb");
    __ASM ("isb");
    }
  
  return 1; 
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
/// Exceptions handlers
//------------------------------------------------------------------------------


// Peripherals handlers
/*
#pragma weak  NMI_Handler=Dummy_Handler
#pragma weak  HardFault_Handler=Dummy_Handler
#pragma weak  MemManage_Handler=Dummy_Handler
#pragma weak  BusFault_Handler=Dummy_Handler
#pragma weak  UsageFault_Handler=Dummy_Handler
#pragma weak  SVC_Handler=Dummy_Handler
#pragma weak  PendSV_Handler=Dummy_Handler
#pragma weak  SysTick_Handler=Dummy_Handler
#pragma weak  IrqHandlerNotUsed=Dummy_Handler
#pragma weak  IrqDBGUBHandler=Dummy_Handler
#pragma weak  HardFault_Handler=Dummy_Handler
*/
#pragma weak  ACC_Handler=Dummy_Handler
#pragma weak  AES_Handler=Dummy_Handler
#pragma weak  AFEC0_Handler=Dummy_Handler
#pragma weak  AFEC1_Handler=Dummy_Handler
#pragma weak  DACC_Handler=Dummy_Handler
#pragma weak  EFC_Handler=Dummy_Handler
#pragma weak  GMAC_Handler=Dummy_Handler
#pragma weak  HSMCI_Handler=Dummy_Handler
#pragma weak  ICM_Handler=Dummy_Handler
#pragma weak  ISI_Handler=Dummy_Handler
#pragma weak  PIOA_Handler=Dummy_Handler
#pragma weak  PIOB_Handler=Dummy_Handler
#pragma weak  PIOC_Handler=Dummy_Handler
#pragma weak  PIOD_Handler=Dummy_Handler
#pragma weak  PIOE_Handler=Dummy_Handler
#pragma weak  PMC_Handler=Dummy_Handler
#pragma weak  PWM0_Handler=Dummy_Handler
#pragma weak  PWM1_Handler=Dummy_Handler
#pragma weak  QSPI_Handler=Dummy_Handler
#pragma weak  RSTC_Handler=Dummy_Handler
#pragma weak  RTC_Handler=Dummy_Handler
#pragma weak  RTT_Handler=Dummy_Handler
#pragma weak  SDRAMC_Handler=Dummy_Handler
#pragma weak  SPI0_Handler=Dummy_Handler
#pragma weak  SPI1_Handler=Dummy_Handler
#pragma weak  SSC_Handler=Dummy_Handler
#pragma weak  SUPC_Handler=Dummy_Handler
#pragma weak  TC0_Handler=Dummy_Handler
#pragma weak  TC1_Handler=Dummy_Handler
#pragma weak  TC2_Handler=Dummy_Handler
#pragma weak  TC3_Handler=Dummy_Handler
#pragma weak  TC4_Handler=Dummy_Handler
#pragma weak  TC5_Handler=Dummy_Handler
#pragma weak  TC6_Handler=Dummy_Handler
#pragma weak  TC7_Handler=Dummy_Handler
#pragma weak  TC8_Handler=Dummy_Handler
#pragma weak  TC9_Handler=Dummy_Handler
#pragma weak  TC10_Handler=Dummy_Handler
#pragma weak  TC11_Handler=Dummy_Handler
#pragma weak  TRNG_Handler=Dummy_Handler
#pragma weak  TWIHS0_Handler=Dummy_Handler
#pragma weak  TWIHS1_Handler=Dummy_Handler
#pragma weak  TWIHS2_Handler=Dummy_Handler
#pragma weak  UART0_Handler=Dummy_Handler
#pragma weak  UART1_Handler=Dummy_Handler
#pragma weak  UART2_Handler=Dummy_Handler
#pragma weak  UART3_Handler=Dummy_Handler
#pragma weak  UART4_Handler=Dummy_Handler
#pragma weak  USART0_Handler=Dummy_Handler
#pragma weak  USART1_Handler=Dummy_Handler
#pragma weak  USART2_Handler=Dummy_Handler
#pragma weak  USBHS_Handler=Dummy_Handler
#pragma weak  WDT_Handler=Dummy_Handler
#pragma weak  RSWDT_Handler=Dummy_Handler
#pragma weak  XDMAC_Handler=Dummy_Handler
#pragma weak  CAN0_Handler=Dummy_Handler
#pragma weak  CAN1_Handler=Dummy_Handler
#pragma weak  MLB_Handler =Dummy_Handler
#pragma weak  FPU_Handler =Dummy_Handler

//------------------------------------------------------------------------------
/// Exceptions default routines
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void NMI_Handler(void) {   
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void HardFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void MemManage_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void BusFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void UsageFault_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void SVC_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void DebugMon_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void PendSV_Handler(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void SysTick_Handler( void ){
      while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void IrqHandlerNotUsed(void){
    while(1);
}
//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void IrqDBGUBHandler(void) {   
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
        (0UL),          /* Reserved */
        (0UL),          /* Reserved */
        (0UL),          /* Reserved */
        (0UL),          /* Reserved */
        SVC_Handler,
        DebugMon_Handler,
        (0UL),          /* Reserved */
        PendSV_Handler,
        SysTick_Handler,

        /* Configurable interrupts */
        SUPC_Handler,   /* 0  Supply Controller */
        RSTC_Handler,   /* 1  Reset Controller */
        RTC_Handler,    /* 2  Real Time Clock */
        RTT_Handler,    /* 3  Real Time Timer */
        WDT_Handler,   /* 4  Watchdog Timer 0 */
        PMC_Handler,    /* 5  Power Management Controller */
        EFC_Handler,    /* 6  Enhanced Embedded Flash Controller */
        UART0_Handler,  /* 7  UART 0 */
        UART1_Handler,  /* 8  UART 1 */
        (0UL),          /* 9  Reserved */
        PIOA_Handler,   /* 10 Parallel I/O Controller A */
        PIOB_Handler,   /* 11 Parallel I/O Controller B */
#ifdef ID_PIOC
        PIOC_Handler,   /* 12 Parallel I/O Controller C */
#else
        (0UL),          /* 12 Reserved */
#endif /* ID_PIOC */
        USART0_Handler, /* 13 USART 0 */
        USART1_Handler, /* 14 USART 1 */
        USART2_Handler, /* 15 USART 2 */
        PIOD_Handler,   /* 16 Parallel I/O Controller D */
#ifdef ID_PIOE
        PIOE_Handler,   /* 17 Parallel I/O Controller E */
#else
        (0UL),          /* 17 Reserved */
#endif /* ID_PIOE */
#ifdef ID_HSMCI
        HSMCI_Handler,  /* 18 Multimedia Card Interface */
#else
        (0UL),          /* 18 Reserved */
#endif /* ID_HSMCI */
        TWIHS0_Handler,   /* 19 Two Wire Interface 0 HS */
        TWIHS1_Handler,   /* 20 Two Wire Interface 1 HS */
        SPI0_Handler,   /* 21 Serial Peripheral Interface 0 */
        SSC_Handler,    /* 22 Synchronous Serial Controller */
        TC0_Handler,    /* 23 Timer/Counter 0 */
        TC1_Handler,    /* 24 Timer/Counter 1 */
        TC2_Handler,    /* 25 Timer/Counter 2 */
#ifdef ID_TC1
        TC3_Handler,    /* 26 Timer/Counter 3 */
#else
        (0UL),          /* 26 Reserved */
#endif /* ID_TC1 */
#ifdef ID_TC1
        TC4_Handler,    /* 27 Timer/Counter 4 */
#else
        (0UL),          /* 27 Reserved */
#endif /* ID_TC1 */
#ifdef ID_TC1
        TC5_Handler,    /* 28 Timer/Counter 5 */
#else
       (0UL),          /* 28 Reserved */
#endif /* ID_TC1 */
       AFEC0_Handler,  /* 29 Analog Front End 0 */
#ifdef ID_DACC
        DACC_Handler,   /* 30 Digital To Analog Converter */
#else
        (0UL),          /* 30 Reserved */
#endif /* ID_DACC */
        PWM0_Handler,   /* 31 Pulse Width Modulation 0 */
        ICM_Handler,    /* 32 Integrity Check Monitor */
        ACC_Handler,    /* 33 Analog Comparator */
        USBHS_Handler,  /* 34 USB Host / Device Controller */
        CAN0_Handler,   /* 35 CAN Controller 0 */
        (0UL),          /* 36 Reserved */
        CAN1_Handler,   /* 37 CAN Controller 1 */
        (0UL),          /* 38 Reserved */
        GMAC_Handler,   /* 39 Ethernet MAC */
        AFEC1_Handler,  /* 40 Analog Front End 1 */
#ifdef ID_TWIHS2
        TWIHS2_Handler,   /* 41 Two Wire Interface 2 HS */
#else
        (0UL),          /* 41 Reserved */
#endif /* ID_TWIHS2 */
        SPI1_Handler,   /* 42 Serial Peripheral Interface 1 */
        QSPI_Handler,   /* 43 Quad I/O Serial Peripheral Interface */
        UART2_Handler,  /* 44 UART 2 */
        UART3_Handler,  /* 45 UART 3 */
        UART4_Handler,  /* 46 UART 4 */
#ifdef ID_TC2
        TC6_Handler,    /* 47 Timer/Counter 6 */
#else
        (0UL),          /* 47 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        TC7_Handler,    /* 48 Timer/Counter 7 */
#else
       (0UL),          /* 48 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        TC8_Handler,    /* 49 Timer/Counter 8 */
#else
        (0UL),          /* 49 Reserved */
#endif /* ID_TC2 */
        TC9_Handler,    /* 50 Timer/Counter 9 */
        TC10_Handler,   /* 51 Timer/Counter 10 */
        TC11_Handler,   /* 52 Timer/Counter 11 */
        MLB_Handler,    /* 53 MediaLB */
        (0UL),          /* 54 Reserved */
        (0UL),          /* 55 Reserved */
        AES_Handler,    /* 56 AES */
        TRNG_Handler,   /* 57 True Random Generator */
        XDMAC_Handler,  /* 58 DMA */
        ISI_Handler,    /* 59 Camera Interface */
        PWM1_Handler,   /* 60 Pulse Width Modulation 1 */
        FPU_Handler,    /* 61 Floating Point Unit */
#ifdef ID_SDRAMC
        SDRAMC_Handler, /* 62 SDRAM Controller */
#else
        (0UL),          /* 62 Reserved */
#endif /* ID_SDRAMC */
        RSWDT_Handler    /* 63 Watchdog Timer 1 */
};

//------------------------------------------------------------------------------
#pragma location = ".sram_intvec"
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
        (0UL),          /* Reserved */
        (0UL),          /* Reserved */
        (0UL),          /* Reserved */
        (0UL),          /* Reserved */
        SVC_Handler,
        DebugMon_Handler,
        (0UL),          /* Reserved */
        PendSV_Handler,
        SysTick_Handler,

        /* Configurable interrupts */
        SUPC_Handler,   /* 0  Supply Controller */
        RSTC_Handler,   /* 1  Reset Controller */
        RTC_Handler,    /* 2  Real Time Clock */
        RTT_Handler,    /* 3  Real Time Timer */
        WDT_Handler,   /* 4  Watchdog Timer 0 */
        PMC_Handler,    /* 5  Power Management Controller */
        EFC_Handler,    /* 6  Enhanced Embedded Flash Controller */
        UART0_Handler,  /* 7  UART 0 */
        UART1_Handler,  /* 8  UART 1 */
        (0UL),          /* 9  Reserved */
        PIOA_Handler,   /* 10 Parallel I/O Controller A */
        PIOB_Handler,   /* 11 Parallel I/O Controller B */
#ifdef ID_PIOC
        PIOC_Handler,   /* 12 Parallel I/O Controller C */
#else
        (0UL),          /* 12 Reserved */
#endif /* ID_PIOC */
        USART0_Handler, /* 13 USART 0 */
        USART1_Handler, /* 14 USART 1 */
        USART2_Handler, /* 15 USART 2 */
        PIOD_Handler,   /* 16 Parallel I/O Controller D */
#ifdef ID_PIOE
        PIOE_Handler,   /* 17 Parallel I/O Controller E */
#else
        (0UL),          /* 17 Reserved */
#endif /* ID_PIOE */
#ifdef ID_HSMCI
        HSMCI_Handler,  /* 18 Multimedia Card Interface */
#else
        (0UL),          /* 18 Reserved */
#endif /* ID_HSMCI */
        TWIHS0_Handler,   /* 19 Two Wire Interface 0 HS */
        TWIHS1_Handler,   /* 20 Two Wire Interface 1 HS */
        SPI0_Handler,   /* 21 Serial Peripheral Interface 0 */
        SSC_Handler,    /* 22 Synchronous Serial Controller */
        TC0_Handler,    /* 23 Timer/Counter 0 */
        TC1_Handler,    /* 24 Timer/Counter 1 */
        TC2_Handler,    /* 25 Timer/Counter 2 */
#ifdef ID_TC1
        TC3_Handler,    /* 26 Timer/Counter 3 */
#else
        (0UL),          /* 26 Reserved */
#endif /* ID_TC1 */
#ifdef ID_TC1
        TC4_Handler,    /* 27 Timer/Counter 4 */
#else
        (0UL),          /* 27 Reserved */
#endif /* ID_TC1 */
#ifdef ID_TC1
        TC5_Handler,    /* 28 Timer/Counter 5 */
#else
       (0UL),          /* 28 Reserved */
#endif /* ID_TC1 */
       AFEC0_Handler,  /* 29 Analog Front End 0 */
#ifdef ID_DACC
        DACC_Handler,   /* 30 Digital To Analog Converter */
#else
        (0UL),          /* 30 Reserved */
#endif /* ID_DACC */
        PWM0_Handler,   /* 31 Pulse Width Modulation 0 */
        ICM_Handler,    /* 32 Integrity Check Monitor */
        ACC_Handler,    /* 33 Analog Comparator */
        USBHS_Handler,  /* 34 USB Host / Device Controller */
        CAN0_Handler,   /* 35 CAN Controller 0 */
        (0UL),          /* 36 Reserved */
        CAN1_Handler,   /* 37 CAN Controller 1 */
        (0UL),          /* 38 Reserved */
        GMAC_Handler,   /* 39 Ethernet MAC */
        AFEC1_Handler,  /* 40 Analog Front End 1 */
#ifdef ID_TWIHS2
        TWIHS2_Handler,   /* 41 Two Wire Interface 2 HS */
#else
        (0UL),          /* 41 Reserved */
#endif /* ID_TWIHS2 */
        SPI1_Handler,   /* 42 Serial Peripheral Interface 1 */
        QSPI_Handler,   /* 43 Quad I/O Serial Peripheral Interface */
        UART2_Handler,  /* 44 UART 2 */
        UART3_Handler,  /* 45 UART 3 */
        UART4_Handler,  /* 46 UART 4 */
#ifdef ID_TC2
        TC6_Handler,    /* 47 Timer/Counter 6 */
#else
        (0UL),          /* 47 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        TC7_Handler,    /* 48 Timer/Counter 7 */
#else
       (0UL),          /* 48 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        TC8_Handler,    /* 49 Timer/Counter 8 */
#else
        (0UL),          /* 49 Reserved */
#endif /* ID_TC2 */
        TC9_Handler,    /* 50 Timer/Counter 9 */
        TC10_Handler,   /* 51 Timer/Counter 10 */
        TC11_Handler,   /* 52 Timer/Counter 11 */
        MLB_Handler,    /* 53 MediaLB */
        (0UL),          /* 54 Reserved */
        (0UL),          /* 55 Reserved */
        AES_Handler,    /* 56 AES */
        TRNG_Handler,   /* 57 True Random Generator */
        XDMAC_Handler,  /* 58 DMA */
        ISI_Handler,    /* 59 Camera Interface */
        PWM1_Handler,   /* 60 Pulse Width Modulation 1 */
        FPU_Handler,    /* 61 Floating Point Unit */
#ifdef ID_SDRAMC
        SDRAMC_Handler, /* 62 SDRAM Controller */
#else
        (0UL),          /* 62 Reserved */
#endif /* ID_SDRAMC */
        RSWDT_Handler    /* 63 Watchdog Timer 1 */
};


//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


