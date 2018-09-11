/*-----------------------------------------------------------------------------
 *           ATMEL Microcontroller Software Support  -  ROUSSET  -
 *-----------------------------------------------------------------------------
 * DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------
 * File Name           : v_utils.c
 *----------------------------------------------------------------------------
*/
#include "project.h"


// ---- General purpose include files
#include "device.h"
#include "board.h"


// ---- Specific include files
#include "v_utils.h"


#if (DEVICE_CORE_0_TYPE==CORE_TYPE_CA5)
  #include "v_startup/v_mmu.h"
#endif


// global variables
extern unsigned int  MCK_clock_speed;


#if SAM9X6
  #define SLOW_CLOCK_SELECTED ((PMC->PMC_CPU_CKR & PMC_CPU_CKR_CSS_Msk)==(PMC_CPU_CKR_CSS_SLOW_CLK & PMC_CPU_CKR_CSS_Msk))
#else
  #define SLOW_CLOCK_SELECTED ((PMC->PMC_MCKR & PMC_MCKR_CSS_Msk)==(PMC_MCKR_CSS_SLOW_CLK & PMC_MCKR_CSS_Msk))
#endif // MNn SAM9X6

/*----------------------------------------------------------------------------*/
/* Reset sources messages                                                     */
/*----------------------------------------------------------------------------*/
#if (DEVICE_HAS_SUPC == 1)
const char reset_source_msg[NB_RST_SOURCE][RST_LABEL_SIZE]={"POR_RESET",\
  "WUP_RESET","WDT_RESET","SW_RESET","USR_RESET",                       \
  "__RESERVED__","CPU_FAIL_RST","SLCK_XTAL_RST",                        \
  "BOD_RESET","SM_RESET"};
#else
const char reset_source_msg[NB_RST_SOURCE][RST_LABEL_SIZE]={"POR_RESET",\
  "WUP_RESET","WDT_RESET","SW_RESET","USR_RESET",                       \
  "__RESERVED__","CPU_FAIL_RST","SLCK_XTAL_RST"}; //added on 65108
#endif
/*----------------------------------------------------------------------------*/


#ifndef SAMA5 //ERr SAMA5
/*----------------------------------------------------------------------------*/
//* Function Name       : external_reset_enable
//* Object              : enable external reset
//*---------------------------------------------------------------------------*/

////#define RSTC_MR_URSTEN (0x1u << 0) /**< \brief (RSTC_MR) User Reset Enable */
////#define RSTC_MR_URSTIEN (0x1u << 4) /**< \brief (RSTC_MR) User Reset Interrupt Enable */
////#define RSTC_MR_ERSTL_Pos 8
////#define RSTC_MR_ERSTL_Msk (0xfu << RSTC_MR_ERSTL_Pos) /**< \brief (RSTC_MR) External Reset Length */
////#define RSTC_MR_ERSTL(value) ((RSTC_MR_ERSTL_Msk & ((value) << RSTC_MR_ERSTL_Pos)))
////#define RSTC_MR_KEY_Pos 24
////#define RSTC_MR_KEY_Msk (0xffu << RSTC_MR_KEY_Pos) /**< \brief (RSTC_MR) Write Access Password */
////#define RSTC_MR_KEY(value) ((RSTC_MR_KEY_Msk & ((value) << RSTC_MR_KEY_Pos)))
////#define   RSTC_MR_KEY_PASSWD (0xA5u << 24) /**< \brief (RSTC_MR) Writing any other value in this field aborts the write operation.Always reads as 0. */



#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void external_reset_enable(void)
{
#if SAM9X6
   REG_RSTC_MR = RSTC_MR_KEY_PASSWD | RSTC_MR_URSTEN; 
#else  
  REG_RSTC_MR = RSTC_CR_KEY(RSTC_KEY_VAL) | RSTC_MR_URSTEN;
#endif //MNn SAM9X6
}

/*----------------------------------------------------------------------------*/
//* Function Name       : external_reset_disable
//* Object              : disable external reset
//*---------------------------------------------------------------------------*/
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void external_reset_disable(void)
{

#if SAM9X6
   REG_RSTC_MR = RSTC_MR_KEY_PASSWD & (~RSTC_MR_URSTEN); 
#else  
  REG_RSTC_MR = RSTC_CR_KEY(RSTC_KEY_VAL) & (~RSTC_MR_URSTEN);
#endif //MNn SAM9X6

}
#endif //ERr SAMA5

#if DEVICE_HAS_DWDT==1
/*----------------------------------------------------------------------------*/
//* Function Name       : watchdog_enable
//* Object              : enable watchdog with predefined parameters
//                          * time parameter (ms)
//                          * delay window disabled
//                          * wdt halts for debug state
//                          * wdt runs for idle mode
//                          * wdt fault triggers reset
//                                * wdt fault activates all resets
//                          * wdt fault asserts interrupt
//*---------------------------------------------------------------------------*/
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void dual_watchdog_enable(Dwdt* p_dwdt, uint32_t time)
{
  uint32_t ul_dwdv;

  if (time == DWDT_MAX)ul_dwdv = 0xFFF; // 12bits value
  else{
    ul_dwdv = (time*1000)/(128*1000000/SLOW_CLOCK_FREQ);
    if (ul_dwdv > 0xFFF)ul_dwdv=0xFFF;
  }
  
  dwdt_enable(p_dwdt,ul_dwdv,ul_dwdv,DWDT_INT_EN,DWDT_RST_EN,ALL_RESET,STOP_DBG_STATE,RUN_IDLE_STATE);
}
#endif




#if DEVICE_HAS_WDT==1 
/*----------------------------------------------------------------------------*/
//* Function Name       : watchdog_enable
//* Object              : enable watchdog with predefined parameters
//                          * time parameter (ms)
//                          * delay window disabled
//                          * wdt halts for debug state
//                          * wdt runs for idle mode
//                          * wdt fault triggers reset
//                                * wdt fault activates all resets
//                          * wdt fault asserts interrupt
//*---------------------------------------------------------------------------*/
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void watchdog_enable(Wdt* p_wdt, uint32_t time)
{
  uint32_t ul_wdv;

  if (time == WDT_MAX)ul_wdv = 0xFFF; // 12bits value
  else{
    ul_wdv = (time*1000)/(128*1000000/SLOW_CLOCK_FREQ);
    if (ul_wdv > 0xFFF)ul_wdv=0xFFF;
  }
  
  wdt_enable(p_wdt,ul_wdv,ul_wdv,WDT_INT_EN,WDT_RST_EN,ALL_RESET,STOP_DBG_STATE,RUN_IDLE_STATE);
}
#endif







// -----------------------------------------------------------------------------
//  Function Name       : config_clocks
//  Object              : configure master clock using project.h definitions
// -----------------------------------------------------------------------------
//
// Check RC oscillator frequency selection
#if (MAIN_CLK_CONFIG==USE_RC_4MHZ)
  #ifndef CKGR_MOR_MOSCRCF_4_MHz
    #error PMC: 4MHz RC not available on this device
  #endif
#elif (MAIN_CLK_CONFIG==USE_RC_8MHZ)
  #ifndef CKGR_MOR_MOSCRCF_8_MHz
    #error PMC: 8MHz RC not available on this device
  #endif
#elif (MAIN_CLK_CONFIG==USE_RC_12MHZ)
  #ifndef CKGR_MOR_MOSCRCF_12_MHz
    #error PMC: 12MHz RC not available on this device
  #endif
#elif (MAIN_CLK_CONFIG==USE_RC_16MHZ)
  #ifndef CKGR_MOR_MOSCRCF_16_MHz
    #error PMC: 16MHz RC not available on this device
  #endif
#elif (MAIN_CLK_CONFIG==USE_RC_24MHZ)
  #ifndef CKGR_MOR_MOSCRCF_24_MHz
    #error PMC: 24MHz RC not available on this device
  #endif
#endif
////////////////////////////////////////////////////////////////////////////////
#if (PMC_HAS_MCKR_FIELD_MDIV==0)
  #undef  MCK_MDIV
  #define MCK_MDIV 0 //not used
#endif
extern uint32_t config_clocks(void)
{
#if (PLLA_HAS_DIVIDER==0)
  #undef PLLA_DIV
  #define PLLA_DIV (0x01)
#endif
#if (DEVICE_HAS_PLLB==0)
  #define PLLB_MUL (0)
  #define PLLB_DIV (0)
#endif
  return (set_clocks((uint8_t)MAIN_CLK_CONFIG,MCK_CONFIG,PLLA_MUL,PLLA_DIV,PLLB_MUL,PLLB_DIV,PCK_PRESCALER,MCK_MDIV,0));
}



// -----------------------------------------------------------------------------
//  Function Name       : set_clocks
//  Object              : configure master clock
// -----------------------------------------------------------------------------
//  Parameters:
//       main_clk_config   : USE_RC_xMHZ or USE_EXT_CLK or USE_XTAL
//       mck_config        : USE_MAIN_CLK or USE_PLLA or USE_SLOW_CLOCK
//       plla_mul          : PLLA multiplier value
//       plla_div          : PLLA divider value
//       pck_prescaler     : processor clock divider value = 1,8,16,32,64
//       mck_div           : master clock divider value 1,2,4,3 (device dependant)
////////////////////////////////////////////////////////////////////////////////
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
#ifndef SAM9X6
uint32_t set_clocks(uint8_t main_clk_config, uint8_t mck_config,
             uint32_t plla_mul, uint32_t plla_div, uint32_t pllb_mul, uint32_t pllb_div,
             uint8_t pck_prescaler, uint8_t mck_div, uint8_t plldiv2)
{ 
 //unsigned int  main_clk_speed, pll_speed;
 uint32_t prescaler, mdiv, main_clk_speed, pll_speed, slow_ck_freq;
 
  if(SLOW_CLOCK_SELECTED)pmc_switch_mck_to_mainck(0); 
    // Slow clock setting
   switch(SLOW_CLK_CONFIG)
   {
   case USE_XTAL:
     v_pmc_switch_td_sclk_to_32kxtal(0); // v_pmc_switch_sclk_to_32kxtal(0);
     slow_ck_freq = CHIP_FREQ_XTAL_32K;
     break;
   case USE_EXT_CLK:
     v_pmc_switch_td_sclk_to_32kxtal(1); // Bypass v_pmc_switch_sclk_to_32kxtal(1);
     slow_ck_freq = SLOW_CLOCK_FREQ;
     break;
   default: // USE_RC_32KHZ
     slow_ck_freq = CHIP_FREQ_SLCK_RC; // typical freq for trimmed parts
     break;
   }//switch SLOW_CLK_CONFIG

   
   // Prescaler
   switch(pck_prescaler)
   {
   case 1:
     prescaler = PMC_MCKR_PRES_CLK_1;
     break;
   case 2:
     prescaler = PMC_MCKR_PRES_CLK_2;
     break;
   case 4:
     prescaler = PMC_MCKR_PRES_CLK_4;
     break;
   case 8:
     prescaler = PMC_MCKR_PRES_CLK_8;
     break;
   case 16:
     prescaler = PMC_MCKR_PRES_CLK_16;
     break;
   case 32:
     prescaler = PMC_MCKR_PRES_CLK_32;
     break;
   case 64:
     prescaler = PMC_MCKR_PRES_CLK_64;
     break;
   // ERr: prescaler=3 not supported on all products
   //case 3:
   //  prescaler = PMC_MCKR_PRES_CLK_3;
   //  break;
   default:
     prescaler = PMC_MCKR_PRES_CLK_1;
     break;
   }//switch pck_prescaler

   if(!SLOW_CLOCK_SELECTED)pmc_switch_mck_to_sclk(prescaler); 


   // Main clock
   switch(main_clk_config)
   {
   case USE_RC_4MHZ:
          //select internal RC / RC=12MHz
          //pmc_switch_mainck_to_fastrc(2);
          #ifdef CKGR_MOR_MOSCRCF_4_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_4_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 4000000;
          #endif
          break;
   case USE_RC_8MHZ:
          #ifdef CKGR_MOR_MOSCRCF_8_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_8_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 8000000;
          #endif
          break;
   case USE_RC_12MHZ:
           #warning Temporary patch : need to be reviewed!!!
            //select internal RC / RC=12MHz
            //pmc_switch_mainck_to_fastrc(2);
          #ifdef CKGR_MOR_MOSCRCF_12_MHz
            #if (CKGR_MOR_MOSCRCF_12_MHz!=(0x8C05C12)) //ERr patch
              pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_12_MHz>>CKGR_MOR_MOSCRCF_Pos);
            #else
              pmc_switch_mainck_to_fastrc(0); // parameter not used
            #endif
            main_clk_speed = 12000000;
          #endif
          break;
   case USE_RC_16MHZ:
          #ifdef CKGR_MOR_MOSCRCF_16_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_16_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 16000000;
          #endif
          break;
   case USE_RC_24MHZ:
          #ifdef CKGR_MOR_MOSCRCF_24_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_24_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 24000000;
          #endif
          break;
          
   case USE_EXT_CLK:
           pmc_switch_mainck_to_xtal(1); // xtal / bypass mode
           main_clk_speed = EXT_CLOCK_FREQ;
           break;
 
   case USE_XTAL:
           pmc_switch_mainck_to_xtal(0); // xtal no bypass 
           main_clk_speed = BRD_MAIN_XTAL_FREQ; // board.h definition
           break;
   
   default:
           pmc_switch_mainck_to_xtal(0); // xtal no bypass (test)
           main_clk_speed = BRD_MAIN_XTAL_FREQ;
           break;
   }//End Switch main_clk_config

   
#if (PMC_HAS_MCKR_FIELD_MDIV==1)
  switch(mck_div)
   {
   case 1:
     mdiv = PMC_MCKR_MDIV_EQ_PCK;
     break;
   case 2:
     mdiv = PMC_MCKR_MDIV_PCK_DIV2;
     break;
   case 4:
     mdiv = PMC_MCKR_MDIV_PCK_DIV4;
     break;
   case 3:
     mdiv = PMC_MCKR_MDIV_PCK_DIV3;
     break;
   default:
     mdiv = PMC_MCKR_MDIV_PCK_DIV2;
     break;
   }//switch mck_div
#else
   mdiv = 0;
#endif

   
   switch(mck_config)
   {
   case USE_PLLA:
          // (PLLACOUNT max)
          pmc_enable_pllack((plla_mul-1),(0x3F),plla_div);
          if(PLLA_INPUT_IS_SLOW_CK){pll_speed=(slow_ck_freq*plla_mul)/plla_div;}
          else{pll_speed=(main_clk_speed*plla_mul)/plla_div;}
          if(v_pmc_switch_mck_to_pllack(prescaler,mdiv,plldiv2)){return 1;}
          MCK_clock_speed = (pll_speed / pck_prescaler) >> plldiv2;
          break;
          
#if DEVICE_HAS_PLLB
   case USE_PLLB:
           v_pmc_enable_pllbck((pllb_mul-1),CKGR_PLLBR_PLLBCOUNT_Msk,pllb_div);
           if(v_pmc_switch_mck_to_pllbck(prescaler,mdiv,0)){return 1;}
           //pmc_switch_mck_to_pllbck(prescaler);
           pll_speed = main_clk_speed*pllb_mul/pllb_div;
           MCK_clock_speed = pll_speed / pck_prescaler;
           break;
#endif
           
   case USE_MAIN_CLK:
           if(v_pmc_switch_mck_to_mainck(prescaler,mdiv)){return 1;}
           MCK_clock_speed = main_clk_speed / pck_prescaler;
           break;
   
   default: // Use slow clock
           //pmc_switch_mck_to_sclk(prescaler);
           MCK_clock_speed = 32768 / pck_prescaler;
           break;
   }//End Switch mck_config

#if (PMC_HAS_MCKR_FIELD_MDIV==1)
  MCK_clock_speed = MCK_clock_speed / mck_div;
#endif

   return 0;
}
#endif // MNn ifndef SAM9X6 


#if (SAM9X6)
uint32_t set_clocks(uint8_t main_clk_config, uint8_t mck_config,
             uint32_t plla_mul, uint32_t plla_div, uint32_t pllb_mul, uint32_t pllb_div,
             uint8_t pck_prescaler, uint8_t mck_div, uint8_t plldiv2)
{ 
 //unsigned int  main_clk_speed, pll_speed;
 uint32_t prescaler, mdiv, main_clk_speed, pll_speed, slow_ck_freq;
 
  if(SLOW_CLOCK_SELECTED)pmc_switch_mck_to_mainck(0); 
    // Slow clock setting
   switch(SLOW_CLK_CONFIG)
   {
   case USE_XTAL:
     v_pmc_switch_sclk_to_32kxtal(0);
     slow_ck_freq = CHIP_FREQ_XTAL_32K;
     break;
   case USE_EXT_CLK:
     v_pmc_switch_sclk_to_32kxtal(1); // Bypass
     slow_ck_freq = SLOW_CLOCK_FREQ;
     break;
   default: // USE_RC_32KHZ
     slow_ck_freq = CHIP_FREQ_SLCK_RC; // typical freq for trimmed parts
     break;
   }//switch SLOW_CLK_CONFIG

   
   // Prescaler
   switch(pck_prescaler)
   {
   case 1:
     prescaler = PMC_CPU_CKR_PRES_CLK_1;
     break;
   case 2:
     prescaler = PMC_CPU_CKR_PRES_CLK_2;
     break;
   case 4:
     prescaler = PMC_CPU_CKR_PRES_CLK_4;
     break;
   case 8:
     prescaler = PMC_CPU_CKR_PRES_CLK_8;
     break;
   case 16:
     prescaler = PMC_CPU_CKR_PRES_CLK_16;
     break;
   case 32:
     prescaler = PMC_CPU_CKR_PRES_CLK_32;
     break;
   case 64:
     prescaler = PMC_CPU_CKR_PRES_CLK_64;
     break;
   // ERr: prescaler=3 not supported on all products
   //case 3:
   //  prescaler = PMC_MCKR_PRES_CLK_3;
   //  break;
   default:
     prescaler = PMC_CPU_CKR_PRES_CLK_1;
     break;
   }//switch pck_prescaler

   if(!SLOW_CLOCK_SELECTED)pmc_switch_mck_to_sclk(prescaler); 


   // Main clock
   switch(main_clk_config)
   {
   case USE_RC_4MHZ:
          //select internal RC / RC=12MHz
          //pmc_switch_mainck_to_fastrc(2);
          #ifdef CKGR_MOR_MOSCRCF_4_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_4_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 4000000;
          #endif
          break;
   case USE_RC_8MHZ:
          #ifdef CKGR_MOR_MOSCRCF_8_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_8_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 8000000;
          #endif
          break;
   case USE_RC_12MHZ:
           #warning Temporary patch : need to be reviewed!!!
            //select internal RC / RC=12MHz
            //pmc_switch_mainck_to_fastrc(2);
          #ifdef CKGR_MOR_MOSCRCF_12_MHz
            #if (CKGR_MOR_MOSCRCF_12_MHz!=(0x8C05C12)) //ERr patch
              pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_12_MHz>>CKGR_MOR_MOSCRCF_Pos);
            #else
              pmc_switch_mainck_to_fastrc(0); // parameter not used
            #endif
            main_clk_speed = 12000000;
          #endif
          break;
   case USE_RC_16MHZ:
          #ifdef CKGR_MOR_MOSCRCF_16_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_16_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 16000000;
          #endif
          break;
   case USE_RC_24MHZ:
          #ifdef CKGR_MOR_MOSCRCF_24_MHz
            pmc_switch_mainck_to_fastrc(CKGR_MOR_MOSCRCF_24_MHz>>CKGR_MOR_MOSCRCF_Pos);
            main_clk_speed = 24000000;
          #endif
          break;
          
   case USE_EXT_CLK:
           pmc_switch_mainck_to_xtal(1); // xtal / bypass mode
           main_clk_speed = EXT_CLOCK_FREQ;
           break;
 
   case USE_XTAL:
           pmc_switch_mainck_to_xtal(0); // xtal no bypass 
           main_clk_speed = BRD_MAIN_XTAL_FREQ; // board.h definition
           break;
   
   default:
           pmc_switch_mainck_to_xtal(0); // xtal no bypass (test)
           main_clk_speed = BRD_MAIN_XTAL_FREQ;
           break;
   }//End Switch main_clk_config

   
#if (PMC_HAS_MCKR_FIELD_MDIV==1)
  switch(mck_div)
   {
   case 1:
     mdiv = PMC_CPU_CKR_MDIV_EQ_PCK;
     break;
   case 2:
     mdiv = PMC_CPU_CKR_MDIV_PCK_DIV2;
     break;
   case 4:
     mdiv = PMC_CPU_CKR_MDIV_PCK_DIV4;
     break;
   case 3:
     mdiv = PMC_CPU_CKR_MDIV_PCK_DIV3;
     break;
   default:
     mdiv = PMC_CPU_CKR_MDIV_PCK_DIV2;
     break;
   }//switch mck_div
#else
   mdiv = 0;
#endif

   
   switch(mck_config)
   {
   case USE_PLLA:
          // (PLLACOUNT max)
          pmc_enable_pllack((plla_mul-1),(0x3F),plla_div);
          if(PLLA_INPUT_IS_SLOW_CK){pll_speed=(slow_ck_freq*plla_mul)/plla_div;}
          else{pll_speed=(main_clk_speed*plla_mul)/plla_div;}
          if(v_pmc_switch_mck_to_pllack(prescaler,mdiv,plldiv2)){return 1;}
          MCK_clock_speed = (pll_speed / pck_prescaler) >> plldiv2;
          break;
          
#if DEVICE_HAS_PLLB
   case USE_PLLB:
           v_pmc_enable_pllbck((pllb_mul-1),CKGR_PLLBR_PLLBCOUNT_Msk,pllb_div);
           if(v_pmc_switch_mck_to_pllbck(prescaler,mdiv,0)){return 1;}
           //pmc_switch_mck_to_pllbck(prescaler);
           pll_speed = main_clk_speed*pllb_mul/pllb_div;
           MCK_clock_speed = pll_speed / pck_prescaler;
           break;
#endif
           
   case USE_MAIN_CLK:
           if(v_pmc_switch_mck_to_mainck(prescaler,mdiv)){return 1;}
           MCK_clock_speed = main_clk_speed / pck_prescaler;
           break;
   
   default: // Use slow clock
           //pmc_switch_mck_to_sclk(prescaler);
           MCK_clock_speed = 32768 / pck_prescaler;
           break;
   }//End Switch mck_config

#if (PMC_HAS_MCKR_FIELD_MDIV==1)
  MCK_clock_speed = MCK_clock_speed / mck_div;
#endif

   return 0;
}
#endif // MNn SAM9X6 


/*----------------------------------------------------------------------------*/
//* Function Name       : check_reset_source
//* Object              : returns last reset cause code (v_utils.h definitions):
//                          * POR_RESET : power up
//                          * BUP_RESET : return from backup mode
//                          * WDT_RESET : watchdog fault detect
//                          * SW_RESET  : software reset
//                          * USR_RESET : user reset (external NRST)
//                          * BOD_RESET : brownout detect
//                          * SM_RESET  : supply monitor detect
//*---------------------------------------------------------------------------*/
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern uint32_t check_reset_source()
{
 uint32_t reset_cause;
#if (DEVICE_HAS_SUPC == 1)
   if (SUPC->SUPC_SR & SUPC_SR_BODRSTS) reset_cause = BOD_RESET;
   else if (SUPC->SUPC_SR & SUPC_SR_SMRSTS) reset_cause = SM_RESET;
   else reset_cause = (RSTC->RSTC_SR & RSTC_SR_RSTTYP_Msk)>>RSTC_SR_RSTTYP_Pos;
#else
   reset_cause = (RSTC->RSTC_SR & RSTC_SR_RSTTYP_Msk)>>RSTC_SR_RSTTYP_Pos;
#endif
 return reset_cause;
}


/*----------------------------------------------------------------------------*/
//* Function Name       : wait_loop
//* Object              : basic counter loop
//*---------------------------------------------------------------------------*/
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void wait_loop(uint32_t count)
{
 volatile unsigned int i;

  for(i=0;i<count;++i);
}


/*----------------------------------------------------------------------------*/
//* Function Name       : wait_loop
//* Object              : counter loop based wait time function (approximation)
//*                       time = time to wait (ms)
//*---------------------------------------------------------------------------*/
#pragma location = ".wait_time"
__root void wait_time_loop(uint32_t iterations)
{
  for(;iterations--;);

  //asm("nop"); //add to shift code (not 64bits aligned => slow exec)
  //asm("label:SUBS  R1, #1\n "
  //    "      BNE.N label    ");
}
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void wait_time(uint32_t time)
{
 uint32_t count;

   count = ((MCK_clock_speed/1000)/WAIT_LOOP_ITER_CYCLES)*time;
   asm("nop"); //32bits alignment
  
   wait_time_loop(count);
   //for(;count--;);
}




/*----------------------------------------------------------------------------*/
//* Function Name       : brownout_detector_enable
//* Object              : enable BOD with predefined parameters
//                          * vddcore_nreset asserted on brownout detection
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_SUPC
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void brownout_detector_enable()
{
  supc_enable_brownout_resetsignal(SUPC);
  supc_enable_brownout_detector(SUPC);
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : supply_monitor_enable
//* Object              : enable SM with predefined parameters
//                          * threshold value defined in project.h
//                          * continuous sampling
//                          * vddcore_nreset asserted on SM detection
//                          * SUPC interrupt signal asserted on SM detection
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_SUPC
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void supply_monitor_enable()
{
  supc_set_monitor_threshold(SUPC,SM_THRESHOLD);
  supc_enable_monitor_reset(SUPC);
  supc_enable_monitor_interrupt(SUPC);
  supc_set_monitor_sampling_period(SUPC,SUPC_SMMR_SMSMPL_CSM); //enable
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : supply_monitor_disable
//* Object              : disable Supply Monitor
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_SUPC
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void supply_monitor_disable()
{
  supc_set_monitor_sampling_period(SUPC,SUPC_SMMR_SMSMPL_SMD); 
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : display_flash_desc_dbgu
//* Object              : Display embedded flash descriptor on DBGU
//*---------------------------------------------------------------------------*/
#if DEVICE_HAS_EFC0
extern void display_flash_desc_dbgu(iflash_descriptor_t* fdes)
{
  uint32_t i;
  char msg[50];
  
    DEBUG_Printk("  ============================================\n\r");
    sprintf(msg,"  ========> Flash ID = %X\n\r",fdes->fl_id); DEBUG_Printk(msg);
    sprintf(msg,"  ======> Flash Size = %d\n\r",fdes->fl_size); DEBUG_Printk(msg);
    sprintf(msg,"  => Flash Page Size = %d\n\r",fdes->fl_page_size); DEBUG_Printk(msg);
    sprintf(msg,"  => Flash Nb Planes = %d\n\r",fdes->fl_nb_plane); DEBUG_Printk(msg);
    sprintf(msg,"  ==> Flash Nb Locks = %d\n\r",fdes->fl_nb_lock); DEBUG_Printk(msg);
    DEBUG_Printk("  --------------------------------------------\n\r");
  for(i=0;i<fdes->fl_nb_plane;++i){
    sprintf(msg,"  => Flash Plane %d: %d Bytes\n\r",i,fdes->fl_plane[i]); DEBUG_Printk(msg);
    }
    DEBUG_Printk("  --------------------------------------------\n\r");
  for(i=0;i<fdes->fl_nb_lock;++i){
    sprintf(msg,"  => Lock Region %d: %d Bytes\n\r",i,fdes->fl_lock[i]); DEBUG_Printk(msg);
    }
    DEBUG_Printk("  --------------------------------------------\n\r");
    DEBUG_Printk("  ============================================\n\r");
    DEBUG_Printk("\n\r");
    DEBUG_Printk("\n\r");
}
#endif



/*----------------------------------------------------------------------------*/
//* Function Name       : DTCM_Enable
//* Object              : Enable tighly coupled memory for data
//*---------------------------------------------------------------------------*/
#if (__DTCM_PRESENT==1)
extern void DTCM_Enable(void)
{
 __ASM ("dsb");
 __ASM ("isb");
 SCB->DTCMCR = (SCB_DTCMCR_EN_Msk | SCB_DTCMCR_RMW_Msk | SCB_DTCMCR_RETEN_Msk);
 __ASM ("dsb");
 __ASM ("isb");
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : ITCM_Enable
//* Object              : Enable tighly coupled memory for code
//*---------------------------------------------------------------------------*/
#if (__ITCM_PRESENT==1)
extern void ITCM_Enable(void)
{
 __ASM ("dsb");
 __ASM ("isb");
 SCB->ITCMCR = (SCB_ITCMCR_EN_Msk | SCB_ITCMCR_RMW_Msk | SCB_ITCMCR_RETEN_Msk);
 __ASM ("dsb");
 __ASM ("isb");
}
#endif




/*----------------------------------------------------------------------------*/
//* Function Name       : EnableICache
//* Object              : Enable Core Instruction cache
//*---------------------------------------------------------------------------*/
#if (__ICACHE_PRESENT==1)
extern void EnableICache(void)
{
#if (DEVICE_CORE_0_TYPE==CORE_TYPE_CM7)
  __ASM ("dsb");
  __ASM ("isb");
  SCB->ICIALLU = 0; // invalidate I-Cache
  SCB->CCR |= SCB_CCR_IC_Msk; // enable I-Cache
  __ASM ("dsb");
  __ASM ("isb");
#elif (DEVICE_CORE_0_TYPE==CORE_TYPE_CA5)
  v_EnableICache(); //mmu.c
  //#warning EnableICache Not implemented on CortexA5 products 
#else
  #warning EnableICache Not implemented on this products
#endif
}
#endif


/*----------------------------------------------------------------------------*/
//* Function Name       : DisableICache
//* Object              : Disable Core Instruction cache
//*---------------------------------------------------------------------------*/

#if (__ICACHE_PRESENT==1)
extern void DisableICache(void)
{
#if (DEVICE_CORE_0_TYPE==CORE_TYPE_CM7)
  __ASM ("dsb");
  __ASM ("isb");
  SCB->CCR &= ~SCB_CCR_IC_Msk; // disable I-Cache
  SCB->ICIALLU = 0;            // invalidate I-Cache
  __ASM ("dsb");
  __ASM ("isb");
#elif (DEVICE_CORE_0_TYPE==CORE_TYPE_CA5)
  v_DisableICache(); //mmu.c
  //#warning DisableICache Not implemented on CortexA5 products 
#else
  #warning DisableICache Not implemented on this products 
#endif
}
#endif
