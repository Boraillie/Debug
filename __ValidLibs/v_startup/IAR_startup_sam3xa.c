/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Atmel Corporation                                        */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

#include "project.h"
#include "device.h"
#include "board.h"
//#include "sam3xa.h"

typedef void (*intfunc) (void);
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

void __iar_program_start(void);
int __low_level_init(void);

/* Default empty handler */
void Dummy_Handler(void);

/* Cortex-M3 core handlers */
#pragma weak NMI_Handler=Dummy_Handler
#pragma weak HardFault_Handler=Dummy_Handler
#pragma weak MemManage_Handler=Dummy_Handler
#pragma weak BusFault_Handler=Dummy_Handler
#pragma weak UsageFault_Handler=Dummy_Handler
#pragma weak SVC_Handler=Dummy_Handler
#pragma weak DebugMon_Handler=Dummy_Handler
#pragma weak PendSV_Handler=Dummy_Handler
#pragma weak SysTick_Handler=Dummy_Handler

/* Peripherals handlers */
#pragma weak SUPC_Handler=Dummy_Handler
#pragma weak RSTC_Handler=Dummy_Handler
#pragma weak RTC_Handler=Dummy_Handler
#pragma weak RTT_Handler=Dummy_Handler
#pragma weak WDT_Handler=Dummy_Handler
#pragma weak PMC_Handler=Dummy_Handler
#pragma weak EFC0_Handler=Dummy_Handler
#pragma weak EFC1_Handler=Dummy_Handler

//#pragma weak UART_Handler=Dummy_Handler
#pragma weak UART0_Handler=Dummy_Handler //ERr

#ifdef ID_SMC
#pragma weak SMC_Handler=Dummy_Handler
#endif /* ID_SMC */
#ifdef ID_SDRAMC
#pragma weak SDRAMC_Handler=Dummy_Handler
#endif /* ID_SDRAMC */
#pragma weak PIOA_Handler=Dummy_Handler
#pragma weak PIOB_Handler=Dummy_Handler
#ifdef ID_PIOC
#pragma weak PIOC_Handler=Dummy_Handler
#endif /* ID_PIOC */
#ifdef ID_PIOD
#pragma weak PIOD_Handler=Dummy_Handler
#endif /* ID_PIOD */
#ifdef ID_PIOE
#pragma weak PIOE_Handler=Dummy_Handler
#endif /* ID_PIOE */
#ifdef ID_PIOF
#pragma weak PIOF_Handler=Dummy_Handler
#endif /* ID_PIOF */
#pragma weak USART0_Handler=Dummy_Handler
#pragma weak USART1_Handler=Dummy_Handler
#pragma weak USART2_Handler=Dummy_Handler
#ifdef ID_USART3
#pragma weak USART3_Handler=Dummy_Handler
#endif /* ID_USART3 */
#pragma weak HSMCI_Handler=Dummy_Handler
#pragma weak TWI0_Handler=Dummy_Handler
#pragma weak TWI1_Handler=Dummy_Handler
#pragma weak SPI0_Handler=Dummy_Handler
#ifdef ID_SPI1
#pragma weak SPI1_Handler=Dummy_Handler
#endif /* ID_SPI1 */
#pragma weak SSC_Handler=Dummy_Handler
#pragma weak TC0_Handler=Dummy_Handler
#pragma weak TC1_Handler=Dummy_Handler
#pragma weak TC2_Handler=Dummy_Handler
#pragma weak TC3_Handler=Dummy_Handler
#pragma weak TC4_Handler=Dummy_Handler
#pragma weak TC5_Handler=Dummy_Handler
#ifdef ID_TC2
#pragma weak TC6_Handler=Dummy_Handler
#endif /* ID_TC2 */
#ifdef ID_TC2
#pragma weak TC7_Handler=Dummy_Handler
#endif /* ID_TC2 */
#ifdef ID_TC2
#pragma weak TC8_Handler=Dummy_Handler
#endif /* ID_TC2 */
#pragma weak PWM_Handler=Dummy_Handler
#pragma weak ADC_Handler=Dummy_Handler
#pragma weak DACC_Handler=Dummy_Handler
#pragma weak DMAC_Handler=Dummy_Handler
#pragma weak UOTGHS_Handler=Dummy_Handler
#pragma weak TRNG_Handler=Dummy_Handler
#ifdef ID_EMAC
#pragma weak EMAC_Handler=Dummy_Handler
#endif /* ID_EMAC */
#pragma weak CAN0_Handler=Dummy_Handler
#pragma weak CAN1_Handler=Dummy_Handler

/* Exception Table */
#pragma language = extended
#pragma segment = "CSTACK"

/* The name "__vector_table" has special meaning for C-SPY: */
/* it is where the SP start value is found, and the NVIC vector */
/* table register (VTOR) is initialized to this address if != 0 */

#pragma section = ".intvec"
#pragma location = ".intvec"
const DeviceVectors __vector_table = {
        (void*) __sfe("CSTACK"),
        
        .pfnReset_Handler      = (void*) Reset_Handler,
        .pfnNMI_Handler        = (void*) NMI_Handler,
        .pfnHardFault_Handler  = (void*) HardFault_Handler,
        .pfnMemManage_Handler  = (void*) MemManage_Handler,
        .pfnBusFault_Handler   = (void*) BusFault_Handler,
        .pfnUsageFault_Handler = (void*) UsageFault_Handler,
        .pfnReserved1_Handler  = (void*) (0UL),          /* Reserved */
        .pfnReserved2_Handler  = (void*) (0UL),          /* Reserved */
        .pfnReserved3_Handler  = (void*) (0UL),          /* Reserved */
        .pfnReserved4_Handler  = (void*) (0UL),          /* Reserved */
        .pfnSVC_Handler        = (void*) SVC_Handler,
        .pfnDebugMon_Handler   = (void*) DebugMon_Handler,
        .pfnReserved5_Handler  = (void*) (0UL),          /* Reserved */
        .pfnPendSV_Handler     = (void*) PendSV_Handler,
        .pfnSysTick_Handler    = (void*) SysTick_Handler,

        /* Configurable interrupts */
        .pfnSUPC_Handler   = (void*) SUPC_Handler,   /* 0  Supply Controller */
        .pfnRSTC_Handler   = (void*) RSTC_Handler,   /* 1  Reset Controller */
        .pfnRTC_Handler    = (void*) RTC_Handler,    /* 2  Real Time Clock */
        .pfnRTT_Handler    = (void*) RTT_Handler,    /* 3  Real Time Timer */
        .pfnWDT_Handler    = (void*) WDT_Handler,    /* 4  Watchdog Timer */
        .pfnPMC_Handler    = (void*) PMC_Handler,    /* 5  Power Management Controller */
        .pfnEFC0_Handler   = (void*) EFC0_Handler,   /* 6  Enhanced Flash Controller 0 */
        .pfnEFC1_Handler   = (void*) EFC1_Handler,   /* 7  Enhanced Flash Controller 1 */
        
         //ERr
        .pfnUART_Handler   = (void*) UART0_Handler,   /* 8  Universal Asynchronous Receiver Transceiver */

#ifdef ID_SMC
        .pfnSMC_Handler    = (void*) SMC_Handler,    /* 9  Static Memory Controller */
#else
        .pvReserved9       = (void*) (0UL),          /* 9  Reserved */
#endif /* ID_SMC */
#ifdef ID_SDRAMC
        .pfnSDRAMC_Handler = (void*) SDRAMC_Handler, /* 10 Synchronous Dynamic RAM Controller */
#else
        .pvReserved10      = (void*) (0UL),          /* 10 Reserved */
#endif /* ID_SDRAMC */
        .pfnPIOA_Handler   = (void*) PIOA_Handler,   /* 11 Parallel I/O Controller A, */
        .pfnPIOB_Handler   = (void*) PIOB_Handler,   /* 12 Parallel I/O Controller B */
#ifdef ID_PIOC
        .pfnPIOC_Handler   = (void*) PIOC_Handler,   /* 13 Parallel I/O Controller C */
#else
        .pvReserved13      = (void*) (0UL),          /* 13 Reserved */
#endif /* ID_PIOC */
#ifdef ID_PIOD
        .pfnPIOD_Handler   = (void*) PIOD_Handler,   /* 14 Parallel I/O Controller D */
#else
        .pvReserved14      = (void*) (0UL),          /* 14 Reserved */
#endif /* ID_PIOD */
#ifdef ID_PIOE
        .pfnPIOE_Handler   = (void*) PIOE_Handler,   /* 15 Parallel I/O Controller E */
#else
        .pvReserved15      = (void*) (0UL),          /* 15 Reserved */
#endif /* ID_PIOE */
#ifdef ID_PIOF
        .pfnPIOF_Handler   = (void*) PIOF_Handler,   /* 16 Parallel I/O Controller F */
#else
        .pvReserved16      = (void*) (0UL),          /* 16 Reserved */
#endif /* ID_PIOF */
        .pfnUSART0_Handler = (void*) USART0_Handler, /* 17 USART 0 */
        .pfnUSART1_Handler = (void*) USART1_Handler, /* 18 USART 1 */
        .pfnUSART2_Handler = (void*) USART2_Handler, /* 19 USART 2 */
#ifdef ID_USART3
        .pfnUSART3_Handler = (void*) USART3_Handler, /* 20 USART 3 */
#else
        .pvReserved20      = (void*) (0UL),          /* 20 Reserved */
#endif /* ID_USART3 */
        .pfnHSMCI_Handler  = (void*) HSMCI_Handler,  /* 21 Multimedia Card Interface */
        .pfnTWI0_Handler   = (void*) TWI0_Handler,   /* 22 Two-Wire Interface 0 */
        .pfnTWI1_Handler   = (void*) TWI1_Handler,   /* 23 Two-Wire Interface 1 */
        .pfnSPI0_Handler   = (void*) SPI0_Handler,   /* 24 Serial Peripheral Interface */
#ifdef ID_SPI1
        .pfnSPI1_Handler   = (void*) SPI1_Handler,   /* 25 Serial Peripheral Interface */
#else
        .pvReserved25      = (void*) (0UL),          /* 25 Reserved */
#endif /* ID_SPI1 */
        .pfnSSC_Handler    = (void*) SSC_Handler,    /* 26 Synchronous Serial Controller */
        .pfnTC0_Handler    = (void*) TC0_Handler,    /* 27 Timer Counter 0 */
        .pfnTC1_Handler    = (void*) TC1_Handler,    /* 28 Timer Counter 1 */
        .pfnTC2_Handler    = (void*) TC2_Handler,    /* 29 Timer Counter 2 */
        .pfnTC3_Handler    = (void*) TC3_Handler,    /* 30 Timer Counter 3 */
        .pfnTC4_Handler    = (void*) TC4_Handler,    /* 31 Timer Counter 4 */
        .pfnTC5_Handler    = (void*) TC5_Handler,    /* 32 Timer Counter 5 */
#ifdef ID_TC2
        .pfnTC6_Handler    = (void*) TC6_Handler,    /* 33 Timer Counter 6 */
#else
        .pvReserved33      = (void*) (0UL),          /* 33 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        .pfnTC7_Handler    = (void*) TC7_Handler,    /* 34 Timer Counter 7 */
#else
        .pvReserved34      = (void*) (0UL),          /* 34 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        .pfnTC8_Handler    = (void*) TC8_Handler,    /* 35 Timer Counter 8 */
#else
        .pvReserved35      = (void*) (0UL),          /* 35 Reserved */
#endif /* ID_TC2 */
        .pfnPWM_Handler    = (void*) PWM_Handler,    /* 36 Pulse Width Modulation Controller */
        .pfnADC_Handler    = (void*) ADC_Handler,    /* 37 ADC Controller */
        .pfnDACC_Handler   = (void*) DACC_Handler,   /* 38 DAC Controller */
        .pfnDMAC_Handler   = (void*) DMAC_Handler,   /* 39 DMA Controller */
        .pfnUOTGHS_Handler = (void*) UOTGHS_Handler, /* 40 USB OTG High Speed */
        .pfnTRNG_Handler   = (void*) TRNG_Handler,   /* 41 True Random Number Generator */
#ifdef ID_EMAC
        .pfnEMAC_Handler   = (void*) EMAC_Handler,   /* 42 Ethernet MAC */
#else
        .pvReserved42      = (void*) (0UL),          /* 42 Reserved */
#endif /* ID_EMAC */
        .pfnCAN0_Handler   = (void*) CAN0_Handler,   /* 43 CAN Controller 0 */
        .pfnCAN1_Handler   = (void*) CAN1_Handler    /* 44 CAN Controller 1 */
};


//------------------------------------------------------------------------------
#pragma data_alignment=0x100
DeviceVectors new_vector_table[] = {
        (void*) __sfe("CSTACK") ,
        
        (void*) Reset_Handler,
        (void*) NMI_Handler,
        (void*) HardFault_Handler,
        (void*) MemManage_Handler,
        (void*) BusFault_Handler,
        (void*) UsageFault_Handler,
        (void*) (0UL),          /* Reserved */
        (void*) (0UL),          /* Reserved */
        (void*) (0UL),          /* Reserved */
        (void*) (0UL),          /* Reserved */
        (void*) SVC_Handler,
        (void*) DebugMon_Handler,
        (void*) (0UL),          /* Reserved */
        (void*) PendSV_Handler,
        (void*) SysTick_Handler,

        /* Configurable interrupts */
        (void*) SUPC_Handler,   /* 0  Supply Controller */
        (void*) RSTC_Handler,   /* 1  Reset Controller */
        (void*) RTC_Handler,    /* 2  Real Time Clock */
        (void*) RTT_Handler,    /* 3  Real Time Timer */
        (void*) WDT_Handler,    /* 4  Watchdog Timer */
        (void*) PMC_Handler,    /* 5  Power Management Controller */
        (void*) EFC0_Handler,   /* 6  Enhanced Flash Controller 0 */
        (void*) EFC1_Handler,   /* 7  Enhanced Flash Controller 1 */
        
         //ERr
        (void*) UART0_Handler,   /* 8  Universal Asynchronous Receiver Transceiver */
        
#ifdef ID_SMC
        (void*) SMC_Handler,    /* 9  Static Memory Controller */
#else
        (void*) (0UL),          /* 9  Reserved */
#endif /* ID_SMC */
#ifdef ID_SDRAMC
        (void*) SDRAMC_Handler, /* 10 Synchronous Dynamic RAM Controller */
#else
        (void*) (0UL),          /* 10 Reserved */
#endif /* ID_SDRAMC */
        (void*) PIOA_Handler,   /* 11 Parallel I/O Controller A, */
        (void*) PIOB_Handler,   /* 12 Parallel I/O Controller B */
#ifdef ID_PIOC
        (void*) PIOC_Handler,   /* 13 Parallel I/O Controller C */
#else
        (void*) (0UL),          /* 13 Reserved */
#endif /* ID_PIOC */
#ifdef ID_PIOD
        (void*) PIOD_Handler,   /* 14 Parallel I/O Controller D */
#else
        (void*) (0UL),          /* 14 Reserved */
#endif /* ID_PIOD */
#ifdef ID_PIOE
        (void*) PIOE_Handler,   /* 15 Parallel I/O Controller E */
#else
        (void*) (0UL),          /* 15 Reserved */
#endif /* ID_PIOE */
#ifdef ID_PIOF
        (void*) PIOF_Handler,   /* 16 Parallel I/O Controller F */
#else
        (void*) (0UL),          /* 16 Reserved */
#endif /* ID_PIOF */
        (void*) USART0_Handler, /* 17 USART 0 */
        (void*) USART1_Handler, /* 18 USART 1 */
        (void*) USART2_Handler, /* 19 USART 2 */
#ifdef ID_USART3
        (void*) USART3_Handler, /* 20 USART 3 */
#else
        (void*) (0UL),          /* 20 Reserved */
#endif /* ID_USART3 */
        (void*) HSMCI_Handler,  /* 21 Multimedia Card Interface */
        (void*) TWI0_Handler,   /* 22 Two-Wire Interface 0 */
        (void*) TWI1_Handler,   /* 23 Two-Wire Interface 1 */
        (void*) SPI0_Handler,   /* 24 Serial Peripheral Interface */
#ifdef ID_SPI1
        (void*) SPI1_Handler,   /* 25 Serial Peripheral Interface */
#else
        (void*) (0UL),          /* 25 Reserved */
#endif /* ID_SPI1 */
        (void*) SSC_Handler,    /* 26 Synchronous Serial Controller */
        (void*) TC0_Handler,    /* 27 Timer Counter 0 */
        (void*) TC1_Handler,    /* 28 Timer Counter 1 */
        (void*) TC2_Handler,    /* 29 Timer Counter 2 */
        (void*) TC3_Handler,    /* 30 Timer Counter 3 */
        (void*) TC4_Handler,    /* 31 Timer Counter 4 */
        (void*) TC5_Handler,    /* 32 Timer Counter 5 */
#ifdef ID_TC2
        (void*) TC6_Handler,    /* 33 Timer Counter 6 */
#else
        (void*) (0UL),          /* 33 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        (void*) TC7_Handler,    /* 34 Timer Counter 7 */
#else
        (void*) (0UL),          /* 34 Reserved */
#endif /* ID_TC2 */
#ifdef ID_TC2
        (void*) TC8_Handler,    /* 35 Timer Counter 8 */
#else
        (void*) (0UL),          /* 35 Reserved */
#endif /* ID_TC2 */
        (void*) PWM_Handler,    /* 36 Pulse Width Modulation Controller */
        (void*) ADC_Handler,    /* 37 ADC Controller */
        (void*) DACC_Handler,   /* 38 DAC Controller */
        (void*) DMAC_Handler,   /* 39 DMA Controller */
        (void*) UOTGHS_Handler, /* 40 USB OTG High Speed */
        (void*) TRNG_Handler,   /* 41 True Random Number Generator */
#ifdef ID_EMAC
        (void*) EMAC_Handler,   /* 42 Ethernet MAC */
#else
        (void*) (0UL),          /* 42 Reserved */
#endif /* ID_EMAC */
        (void*) CAN0_Handler,   /* 43 CAN Controller 0 */
        (void*) CAN1_Handler    /* 44 CAN Controller 1 */
};
//------------------------------------------------------------------------------


/**------------------------------------------------------------------------------
 * This is the code that gets called on processor reset. To initialize the
 * device.
 *------------------------------------------------------------------------------*/
int __low_level_init(void)
{
        uint32_t *pSrc = __section_begin(".intvec");

#ifdef REG_EFC_FMR
   REG_EFC_FMR |= EEFC_FMR_FWS(0xF); // F Wait states
#endif
#ifdef REG_EFC0_FMR
   REG_EFC0_FMR |= EEFC_FMR_FWS(0xF); // F Wait states
#endif
#ifdef REG_EFC1_FMR
   REG_EFC1_FMR |= EEFC_FMR_FWS(0xF); // F Wait states
#endif

        
        SCB->VTOR = ((uint32_t) pSrc & SCB_VTOR_TBLOFF_Msk);

        
#ifdef _LINK_TO_ISRAM_ // restore HW reset config after ROM boot exec
 {
 uint32_t read_reg;

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
 }
#endif
        
        return 1; /* if return 0, the data sections will not be initialized */
}

/**------------------------------------------------------------------------------
 * This is the code that gets called on processor reset. To initialize the
 * device.
 *------------------------------------------------------------------------------*/
void Reset_Handler(void)
{
        __iar_program_start();
}

/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
        while (1) {
        }
}





/*
        (void*) HardFault_Handler,
        (void*) MemManage_Handler,
        (void*) BusFault_Handler,
        (void*) UsageFault_Handler,
        (void*) (0UL),
        (void*) (0UL),
        (void*) (0UL),
        (void*) (0UL),
        (void*) SVC_Handler,
        (void*) DebugMon_Handler,
        (void*) (0UL),
        (void*) PendSV_Handler,
        (void*) SysTick_Handler,
*/

