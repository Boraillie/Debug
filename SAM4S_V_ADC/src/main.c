// -----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
// -----------------------------------------------------------------------------
//  The software is delivered "AS IS" without warranty or condition of any
//  kind, either express, implied or statutory. This includes without
//  limitation any warranty or condition with respect to merchantability or
//  fitness for any particular purpose, or against the infringements of
//  intellectual property rights of others.
// -----------------------------------------------------------------------------
//  File Name           : main.c
//  Object              : main application written in C
//  Creation            : ERr / sept 2011
// -----------------------------------------------------------------------------


#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"
#include "board.h"


// ---- Peripherals (ASF drivers)
#include "drivers/pmc/pmc.h"
#include "drivers/pio/pio.h"

// ---- Validation libraries
#include "v_startup/v_relocate.h"
#include "v_drivers/v_pio.h"
#include "v_drivers/v_pmc.h"
#include "v_drivers/v_wdt.h"
#include "v_drivers/v_supc.h"
#include "v_debug.h"
#include "v_utils.h"

// ---- Project files (local)
#include "menu.h"


// ---- Information section feed -----------------------------------------------
#pragma data_alignment=0x10
INFO_SECTION const char _date[] = __DATE__;
#pragma required=_date
#pragma data_alignment=0x10
INFO_SECTION const char _time[] = __TIME__;
#pragma required=_time
// -----------------------------------------------------------------------------



// global variables
unsigned int  MCK_clock_speed;
unsigned int binary_tag; //ERr


// -----------------------------------------------------------------------------
//  Function Name       : PIO_Init
// -----------------------------------------------------------------------------
void PIO_Init (void)
{
  #if (BRD_PIOA_HAS_IO==1)
    // First, enable the clock of the PIO
    pmc_enable_periph_clk(ID_PIOA);
    // then, we configure the PIO Lines
    pio_configure(PIOA,PIO_INPUT,BRD_PIOA_INPUT_MASK,PIO_PULLUP);
    pio_configure(PIOA,PIO_OUTPUT_1,BRD_PIOA_LED_MASK,PIO_DEFAULT);
  #endif
  #if (BRD_PIOB_HAS_IO==1)
    pmc_enable_periph_clk(ID_PIOB);
    pio_configure(PIOB,PIO_INPUT,BRD_PIOB_INPUT_MASK,PIO_PULLUP);
    pio_configure(PIOB,PIO_OUTPUT_1,BRD_PIOB_LED_MASK,PIO_DEFAULT);
  #endif
  #if (BRD_PIOC_HAS_IO==1)
    pmc_enable_periph_clk(ID_PIOC);
    pio_configure(PIOC,PIO_INPUT,BRD_PIOC_INPUT_MASK,PIO_PULLUP);
    pio_configure(PIOC,PIO_OUTPUT_1,BRD_PIOC_LED_MASK,PIO_DEFAULT);
  #endif
}


// -----------------------------------------------------------------------------
//  Function Name       : set_PCK_output
//  Object              : Enable PCK0 on AT91C_PA6_PCK0
//                        Enable PCK1 on AT91C_PA17_PCK1
// -----------------------------------------------------------------------------

void set_PCK_output (void)
{
   // Configure PIO controllers to periph mode
   pio_set_peripheral(PIOB,PIO_PERIPH_B,(uint32_t)(PIO_PB13B_PCK0));
   pio_set_peripheral(PIOA,PIO_PERIPH_B,(uint32_t)(PIO_PA21B_PCK1));
   pio_set_peripheral(PIOA,PIO_PERIPH_B,(uint32_t)(PIO_PA31B_PCK2));
   
   // PCK 0 = output MAIN on PB13
   //pmc_mck_set_source();
   pmc_switch_pck_to_mainck(0,0);
   pmc_enable_pck(0);

   // PCK 1 = output Slow Clock on PA21
   pmc_switch_pck_to_sclk(1,0);
   pmc_enable_pck(1);
   
   
   // PCK 2 = output Master clock on PA31
   pmc_switch_pck_to_mck(2,0);
   // PCK 2 = output PLLA on PA31
   // pmc_switch_pck_to_pllack(2,0);
   pmc_enable_pck(2);
   // warning for PLL : SAM3S chip's pad max frequency limitation
}



// -----------------------------------------------------------------------------
//  Function Name       : run_main
//  Object              : 
// -----------------------------------------------------------------------------
void run_main()
{
  while(1);
}


// -----------------------------------------------------------------------------
//  Function Name       : main
//  Object              : Software entry point
// -----------------------------------------------------------------------------
int main()
{
 //uint32_t reset_cause;
 
   // ------------ Check last reset cause
   //reset_cause = check_reset_source();
  
   #ifdef BUG_WDT  
     // ------------ Watchdog Initialization 
     if(ENABLE_WDT)watchdog_enable(WDT,WDT_TIME);
     else wdt_disable(WDT);
  #endif

   // ------------ Internal voltage regulator settings
   if(ENABLE_VREG)supc_enable_voltage_regulator(SUPC);
   else supc_disable_voltage_regulator(SUPC);
   
   // ------------ Brownout detector settings
   if(ENABLE_BOD) brownout_detector_enable();
   else supc_disable_brownout_detector(SUPC);

   // ------------ Supply Monitor settings
   if(ENABLE_SM) supply_monitor_enable();
   else supply_monitor_disable();
   
   // ------------ Uset reset (board NRST) Initialization
   if(ENABLE_USER_RESET)external_reset_enable();
   else external_reset_disable();

  // ------------ Board level - LEDs and PCK
  PIO_Init();
  #if (USE_PCK == 1)
    set_PCK_output();  // check all clock frequency using PCKx on output PIO
  #endif
   
  // ------------ Clocks configurations
  if(config_clocks())
    while(1); // stop in case of error //ERr

  // Relocate interrupt table
  relocate_int_table(1);

  // ------------ Debug traces configuration
  #ifdef USE_DEBUG 
    DEBUG_Initialize(MCK_clock_speed);
  #endif

  Valid_DebugTrace("\n\r\n\r");  
  Valid_DebugTrace( "*******************************\n\r");
  Valid_DebugTrace( "* ATSAM4S VALID Template TEST *\n\r");
  Valid_DebugTrace( "*******************************\n\r");
  Valid_DebugTrace("Build: ");
  Valid_DebugTrace((char*)_date);
  Valid_DebugTrace(" - ");
  Valid_DebugTrace((char*)_time);
  Valid_DebugTrace("\n\r");

  binary_tag = *(BINARY_TAG_ADDR);

  #if USE_DEBUG_MENU
    run_menu();
  #else
    run_main();
  #endif
}

