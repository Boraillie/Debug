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
// CAPELLA FAMILY
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

//TODO : vfp init todo
#pragma location = ".cstartup" //used by prg mode linker
int __iar_init_vfp()
{
#warning function __iar_init_vfp not implemented
     return 1;
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
                  CKGR_MOR_MOSCRCF_12_MHz |
                  CKGR_MOR_MOSCRCEN      ;//|
                  //CKGR_MOR_MOSCXTEN      ;
   
   while( !(REG_PMC_SR & PMC_SR_MOSCRCS) );
 //set the correct sequence according to datasheet. Still not functional 
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_CSS_Msk;
   read_reg |= PMC_MCKR_CSS_MAIN_CLK; 
   REG_PMC_MCKR = read_reg;   
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );
   
   read_reg = REG_PMC_MCKR;
   read_reg &= ~PMC_MCKR_PRES_Msk;
   read_reg |= PMC_MCKR_PRES_CLK_1;
   REG_PMC_MCKR = read_reg;
   while( !(REG_PMC_SR & PMC_SR_MCKRDY) );
   //---------------------------------

}



#pragma location = ".cstartup" //used by prg mode linker
int __low_level_init( void )
{ 
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
    #warning //restore_hw_reset_settings();
  #endif //_LINK_TO_ISRAM_

   //ERr: DTCM are enable by default at startup
  if(__DTCM_CFG__==0){
    __ASM ("dsb");
    __ASM ("isb");
    //SCB->DTCMCR = (SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk | SCB_DTCMCR_RETEN_Msk);
    SCB->DTCMCR = 0;
#warning DTCM CR access to check (0 for disable??)
    __ASM ("dsb");
    __ASM ("isb");
    }

  //ERr: ITCM are disable by default at startup
  if(__ITCM_CFG__==1){
    __ASM ("dsb");
    __ASM ("isb");
    SCB->ITCMCR = (SCB_ITCMCR_EN_Msk | SCB_ITCMCR_RMW_Msk | SCB_ITCMCR_RETEN_Msk);
    __ASM ("dsb");
    __ASM ("isb");
    }

  return 1; 
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
/// Exceptions handlers
//------------------------------------------------------------------------------


/* Peripherals handlers */
#pragma weak SUPC_Handler=Dummy_Handler
#pragma weak RSTC_Handler=Dummy_Handler
#pragma weak RTC_Handler=Dummy_Handler
#pragma weak RTT_Handler=Dummy_Handler
#pragma weak WDT_Handler=Dummy_Handler
#pragma weak PMC_Handler=Dummy_Handler
#pragma weak EFC_Handler=Dummy_Handler
#pragma weak FLEXCOM0_Handler=Dummy_Handler
#pragma weak FLEXCOM1_Handler=Dummy_Handler
#pragma weak PIOA_Handler=Dummy_Handler
#pragma weak PIOB_Handler=Dummy_Handler
#pragma weak PIOC_Handler=Dummy_Handler
#pragma weak FLEXCOM2_Handler=Dummy_Handler
#pragma weak FLEXCOM3_Handler=Dummy_Handler
#pragma weak FLEXCOM4_Handler=Dummy_Handler
#pragma weak PIOD_Handler=Dummy_Handler
#pragma weak PIOE_Handler=Dummy_Handler
#pragma weak SDMMC0_Handler=Dummy_Handler
#pragma weak SDMMC1_Handler=Dummy_Handler
#pragma weak FLEXCOM5_Handler=Dummy_Handler
#pragma weak FLEXCOM6_Handler=Dummy_Handler
#pragma weak FLEXCOM7_Handler=Dummy_Handler
#pragma weak SSC_Handler=Dummy_Handler
#pragma weak TC0_Handler=Dummy_Handler
#pragma weak TC1_Handler=Dummy_Handler
#pragma weak TC2_Handler=Dummy_Handler
#pragma weak TC3_Handler=Dummy_Handler
#pragma weak TC4_Handler=Dummy_Handler
#pragma weak TC5_Handler=Dummy_Handler
#pragma weak ADC_Handler=Dummy_Handler
#pragma weak DACC_Handler=Dummy_Handler
#pragma weak PWM0_Handler=Dummy_Handler
#pragma weak ICM_Handler=Dummy_Handler
#pragma weak ACC_Handler=Dummy_Handler
#pragma weak UHPHS_Handler=Dummy_Handler

#pragma weak MCAN0_INT0_Handler=Dummy_Handler
#pragma weak MCAN0_INT1_Handler=Dummy_Handler
#pragma weak MCAN1_INT0_Handler=Dummy_Handler
#pragma weak MCAN1_INT1_Handler=Dummy_Handler
#pragma weak MCAN2_INT0_Handler=Dummy_Handler
#pragma weak MCAN2_INT1_Handler=Dummy_Handler
#pragma weak MCAN3_INT0_Handler=Dummy_Handler
#pragma weak MCAN4_INT1_Handler=Dummy_Handler

#pragma weak GMAC_Handler=Dummy_Handler
#pragma weak FLEXCOM8_Handler=Dummy_Handler
#pragma weak FLEXCOM9_Handler=Dummy_Handler
#pragma weak PDMIC0_Handler=Dummy_Handler
#pragma weak PDMIC1_Handler=Dummy_Handler
#pragma weak QSPI_Handler=Dummy_Handler
#pragma weak LCDC_Handler=Dummy_Handler
#pragma weak PTC_Handler=Dummy_Handler
#pragma weak UDP_Handler=Dummy_Handler
#pragma weak TC6_Handler=Dummy_Handler
#pragma weak TC7_Handler=Dummy_Handler
#pragma weak TC8_Handler=Dummy_Handler
#pragma weak TC9_Handler=Dummy_Handler
#pragma weak TC10_Handler=Dummy_Handler
#pragma weak TC11_Handler=Dummy_Handler
#pragma weak CLASSD_Handler=Dummy_Handler
#pragma weak I2SC0_Handler=Dummy_Handler
#pragma weak I2SC1_Handler=Dummy_Handler
#pragma weak AES_Handler=Dummy_Handler
#pragma weak TRNG_Handler=Dummy_Handler
#pragma weak XDMAC_Handler=Dummy_Handler
#pragma weak ISI_Handler=Dummy_Handler
#pragma weak PWM1_Handler=Dummy_Handler
#pragma weak SDRAMC_Handler=Dummy_Handler
#pragma weak SHA_Handler=Dummy_Handler
#pragma weak UDPHS_Handler=Dummy_Handler
#pragma weak GFX2D_Handler=Dummy_Handler
#pragma weak QSPIS_Handler=Dummy_Handler

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
#pragma data_alignment=0x200
const intvec_elem __vector_table[] =
{
        { .__ptr = __sfe( "CSTACK" ) },
        __iar_program_start,
        
        NMI_Handler,
        HardFault_Handler,
        MemManage_Handler,
        BusFault_Handler,
        UsageFault_Handler,
        (0UL),            /* Reserved */
        (0UL),            /* Reserved */
        (0UL),            /* Reserved */
        (0UL),            /* Reserved */
        SVC_Handler,
        DebugMon_Handler,
        (0UL),            /* Reserved */
        PendSV_Handler,
        SysTick_Handler,
        
        
        SUPC_Handler,     /* 0  Supply Controller */
        RSTC_Handler,     /* 1  Reset Controller */
        RTC_Handler,      /* 2  Real Time Clock */
        RTT_Handler,      /* 3  Real Time Timer */
        WDT_Handler,      /* 4  Watchdog Timer */
        PMC_Handler,      /* 5  Power Management Controller */
        EFC_Handler,      /* 6  Enhanced Embedded Flash Controller */
        FLEXCOM0_Handler, /* 7  FLEXCOM 0 */
        FLEXCOM1_Handler, /* 8  FLEXCOM 1 */
        (0UL),            /* 9  Reserved */
        PIOA_Handler,     /* 10 Parallel I/O Controller A */
        PIOB_Handler,     /* 11 Parallel I/O Controller B */
        PIOC_Handler,     /* 12 Parallel I/O Controller C */
        FLEXCOM2_Handler, /* 13 FLEXCOM 2 */
        FLEXCOM3_Handler, /* 14 FLEXCOM 3 */
        FLEXCOM4_Handler, /* 15 FLEXCOM 4 */
        PIOD_Handler,     /* 16 Parallel I/O Controller D */
        PIOE_Handler,     /* 17 Parallel I/O Controller E */
        SDMMC0_Handler,   /* 18 Secure Digital Multimedia Card 0 */
        SDMMC1_Handler,   /* 19 Secure Digital Multimedia Card 1 */
        FLEXCOM5_Handler, /* 20 FLEXCOM 5 */
        FLEXCOM6_Handler, /* 21 FLEXCOM 6 */
        FLEXCOM7_Handler, /* 22 FLEXCOM 7 */
        SSC_Handler,      /* 23 Synchronous Serial Controller */
        TC0_Handler,      /* 24 Timer Counter Channel 0 */
        TC1_Handler,      /* 25 Timer Counter Channel 1 */
        TC2_Handler,      /* 26 Timer Counter Channel 2 */
        TC3_Handler,      /* 27 Timer Counter Channel 3 */
        TC4_Handler,      /* 28 Timer Counter Channel 4 */
        TC5_Handler,      /* 29 Timer Counter Channel 5 */
        ADC_Handler,      /* 30 Analog  to Digital Converter */
        DACC_Handler,     /* 31 Digital To Analog Converter */
        PWM0_Handler,     /* 32 Pulse Width Modulation 0 */
        ICM_Handler,      /* 33 Integrity Check Monitor */
        ACC_Handler,      /* 34 Analog Comparator */
        UHPHS_Handler,    /* 35 USB Host High-Speed */

        MCAN0_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN0_INT1_Handler,    /* 35 USB Host High-Speed */
        MCAN1_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN1_INT1_Handler,    /* 35 USB Host High-Speed */
        MCAN2_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN2_INT1_Handler,    /* 35 USB Host High-Speed */
        MCAN3_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN4_INT1_Handler,    /* 35 USB Host High-Speed */
/*
        (0UL),            // 36 Reserved
        (0UL),            // 37 Reserved
        (0UL),            // 38 Reserved
        (0UL),            // 39 Reserved
        (0UL),            // 40 Reserved
        (0UL),            // 41 Reserved
        (0UL),            // 42 Reserved
        (0UL),            // 43 Reserved
*/       
        GMAC_Handler,     /* 44 Ethernet MAC */
        FLEXCOM8_Handler, /* 45 FLEXCOM 8 */
        FLEXCOM9_Handler, /* 46 FLEXCOM 9 */
        PDMIC0_Handler,   /* 47 Pulse Density Modulation Interface 0 */
        PDMIC1_Handler,   /* 48 Pulse Density Modulation Interface 1 */
        QSPI_Handler,     /* 49 Quad I/O Serial Peripheral Interface */
        LCDC_Handler,     /* 50 LCD Controller */
        PTC_Handler,      /* 51 Peripheral Touch Controller */
        UDP_Handler,      /* 52 Full Speed USB Device Port */
        TC6_Handler,      /* 53 Timer Counter Channel 6 */
        TC7_Handler,      /* 54 Timer Counter Channel 7 */
        TC8_Handler,      /* 55 Timer Counter Channel 8 */
        TC9_Handler,      /* 56 Timer Counter Channel 9 */
        TC10_Handler,     /* 57 Timer Counter Channel 10 */
        TC11_Handler,     /* 58 Timer Counter Channel 11 */
        CLASSD_Handler,   /* 59 Audio Class D Amplifier */
        I2SC0_Handler,    /* 60 Inter-IC Sound Controller 0 */
        I2SC1_Handler,    /* 61 Inter-IC Sound Controller 1 */
        AES_Handler,      /* 62 AES */
        TRNG_Handler,     /* 63 True Random Generator */
        XDMAC_Handler,    /* 64 eXtended DMA Controller */
        ISI_Handler,      /* 65 Camera Interface */
        PWM1_Handler,     /* 66 Pulse Width Modulation 1 */
        (0UL),            /* 67 Reserved */
        SDRAMC_Handler,   /* 68 SDRAM Controller */
        (0UL),            /* 69 Reserved */
        (0UL),            /* 70 Reserved */
        (0UL),            /* 71 Reserved */
        (0UL),            /* 72 Reserved */
        (0UL),            /* 73 Reserved */
        (0UL),            /* 74 Reserved */
        (0UL),            /* 75 Reserved */
        (0UL),            /* 76 Reserved */
        (0UL),            /* 77 Reserved */
        SHA_Handler,      /* 78 Secure Hash Algorithm */
        UDPHS_Handler,    /* 79 USB Device High-Speed */
        (0UL),            /* 80 Reserved */
        (0UL),            /* 81 Reserved */
        (0UL),            /* 82 Reserved */
        (0UL),            /* 83 Reserved */
        (0UL),            /* 84 Reserved */
        (0UL),            /* 85 Reserved */
        (0UL),            /* 86 Reserved */
        (0UL),            /* 87 Reserved */
        (0UL),            /* 88 Reserved */
        (0UL),            /* 89 Reserved */
        (0UL),            /* 90 Reserved */
        (0UL),            /* 91 Reserved */
        (0UL),            /* 92 Reserved */
        GFX2D_Handler,    /* 93 2D Graphics Controller */
        QSPIS_Handler     /* 94 QSPI Slave Controller */
                
};

//------------------------------------------------------------------------------
#pragma location = ".sram_intvec"
#pragma data_alignment=0x200
intvec_elem new_vector_table[] =
{
        { .__ptr = __sfe( "CSTACK" ) },
        __iar_program_start,
        
        NMI_Handler,
        HardFault_Handler,
        MemManage_Handler,
        BusFault_Handler,
        UsageFault_Handler,
        (0UL),            /* Reserved */
        (0UL),            /* Reserved */
        (0UL),            /* Reserved */
        (0UL),            /* Reserved */
        SVC_Handler,
        DebugMon_Handler,
        (0UL),            /* Reserved */
        PendSV_Handler,
        SysTick_Handler,
        
        
        SUPC_Handler,     /* 0  Supply Controller */
        RSTC_Handler,     /* 1  Reset Controller */
        RTC_Handler,      /* 2  Real Time Clock */
        RTT_Handler,      /* 3  Real Time Timer */
        WDT_Handler,      /* 4  Watchdog Timer */
        PMC_Handler,      /* 5  Power Management Controller */
        EFC_Handler,      /* 6  Enhanced Embedded Flash Controller */
        FLEXCOM0_Handler, /* 7  FLEXCOM 0 */
        FLEXCOM1_Handler, /* 8  FLEXCOM 1 */
        (0UL),            /* 9  Reserved */
        PIOA_Handler,     /* 10 Parallel I/O Controller A */
        PIOB_Handler,     /* 11 Parallel I/O Controller B */
        PIOC_Handler,     /* 12 Parallel I/O Controller C */
        FLEXCOM2_Handler, /* 13 FLEXCOM 2 */
        FLEXCOM3_Handler, /* 14 FLEXCOM 3 */
        FLEXCOM4_Handler, /* 15 FLEXCOM 4 */
        PIOD_Handler,     /* 16 Parallel I/O Controller D */
        PIOE_Handler,     /* 17 Parallel I/O Controller E */
        SDMMC0_Handler,   /* 18 Secure Digital Multimedia Card 0 */
        SDMMC1_Handler,   /* 19 Secure Digital Multimedia Card 1 */
        FLEXCOM5_Handler, /* 20 FLEXCOM 5 */
        FLEXCOM6_Handler, /* 21 FLEXCOM 6 */
        FLEXCOM7_Handler, /* 22 FLEXCOM 7 */
        SSC_Handler,      /* 23 Synchronous Serial Controller */
        TC0_Handler,      /* 24 Timer Counter Channel 0 */
        TC1_Handler,      /* 25 Timer Counter Channel 1 */
        TC2_Handler,      /* 26 Timer Counter Channel 2 */
        TC3_Handler,      /* 27 Timer Counter Channel 3 */
        TC4_Handler,      /* 28 Timer Counter Channel 4 */
        TC5_Handler,      /* 29 Timer Counter Channel 5 */
        ADC_Handler,      /* 30 Analog  to Digital Converter */
        DACC_Handler,     /* 31 Digital To Analog Converter */
        PWM0_Handler,     /* 32 Pulse Width Modulation 0 */
        ICM_Handler,      /* 33 Integrity Check Monitor */
        ACC_Handler,      /* 34 Analog Comparator */
        UHPHS_Handler,    /* 35 USB Host High-Speed */

        MCAN0_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN0_INT1_Handler,    /* 35 USB Host High-Speed */
        MCAN1_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN1_INT1_Handler,    /* 35 USB Host High-Speed */
        MCAN2_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN2_INT1_Handler,    /* 35 USB Host High-Speed */
        MCAN3_INT0_Handler,    /* 35 USB Host High-Speed */
        MCAN4_INT1_Handler,    /* 35 USB Host High-Speed */
/*
        (0UL),            // 36 Reserved
        (0UL),            // 37 Reserved
        (0UL),            // 38 Reserved
        (0UL),            // 39 Reserved
        (0UL),            // 40 Reserved
        (0UL),            // 41 Reserved
        (0UL),            // 42 Reserved
        (0UL),            // 43 Reserved
*/       
        GMAC_Handler,     /* 44 Ethernet MAC */
        FLEXCOM8_Handler, /* 45 FLEXCOM 8 */
        FLEXCOM9_Handler, /* 46 FLEXCOM 9 */
        PDMIC0_Handler,   /* 47 Pulse Density Modulation Interface 0 */
        PDMIC1_Handler,   /* 48 Pulse Density Modulation Interface 1 */
        QSPI_Handler,     /* 49 Quad I/O Serial Peripheral Interface */
        LCDC_Handler,     /* 50 LCD Controller */
        PTC_Handler,      /* 51 Peripheral Touch Controller */
        UDP_Handler,      /* 52 Full Speed USB Device Port */
        TC6_Handler,      /* 53 Timer Counter Channel 6 */
        TC7_Handler,      /* 54 Timer Counter Channel 7 */
        TC8_Handler,      /* 55 Timer Counter Channel 8 */
        TC9_Handler,      /* 56 Timer Counter Channel 9 */
        TC10_Handler,     /* 57 Timer Counter Channel 10 */
        TC11_Handler,     /* 58 Timer Counter Channel 11 */
        CLASSD_Handler,   /* 59 Audio Class D Amplifier */
        I2SC0_Handler,    /* 60 Inter-IC Sound Controller 0 */
        I2SC1_Handler,    /* 61 Inter-IC Sound Controller 1 */
        AES_Handler,      /* 62 AES */
        TRNG_Handler,     /* 63 True Random Generator */
        XDMAC_Handler,    /* 64 eXtended DMA Controller */
        ISI_Handler,      /* 65 Camera Interface */
        PWM1_Handler,     /* 66 Pulse Width Modulation 1 */
        (0UL),            /* 67 Reserved */
        SDRAMC_Handler,   /* 68 SDRAM Controller */
        (0UL),            /* 69 Reserved */
        (0UL),            /* 70 Reserved */
        (0UL),            /* 71 Reserved */
        (0UL),            /* 72 Reserved */
        (0UL),            /* 73 Reserved */
        (0UL),            /* 74 Reserved */
        (0UL),            /* 75 Reserved */
        (0UL),            /* 76 Reserved */
        (0UL),            /* 77 Reserved */
        SHA_Handler,      /* 78 Secure Hash Algorithm */
        UDPHS_Handler,    /* 79 USB Device High-Speed */
        (0UL),            /* 80 Reserved */
        (0UL),            /* 81 Reserved */
        (0UL),            /* 82 Reserved */
        (0UL),            /* 83 Reserved */
        (0UL),            /* 84 Reserved */
        (0UL),            /* 85 Reserved */
        (0UL),            /* 86 Reserved */
        (0UL),            /* 87 Reserved */
        (0UL),            /* 88 Reserved */
        (0UL),            /* 89 Reserved */
        (0UL),            /* 90 Reserved */
        (0UL),            /* 91 Reserved */
        (0UL),            /* 92 Reserved */
        GFX2D_Handler,    /* 93 2D Graphics Controller */
        QSPIS_Handler     /* 94 QSPI Slave Controller */
                
};

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
#pragma location = ".cstartup" //used by prg mode linker
void Dummy_Handler( void )
{
  while ( 1 ) ;
}
//------------------------------------------------------------------------------


