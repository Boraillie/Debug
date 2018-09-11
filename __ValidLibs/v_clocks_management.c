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
 * File Name           : v_clocks_management.c
 *----------------------------------------------------------------------------
*/


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"

#warning temporary include: Old clk management functions reused from utils.c, just a little awkward. To be left in.
#warning EXT_CLOCK_FREQ is always value from project.h
#include "v_utils.h"


#include "v_clocks_management.h"


// global variables
extern unsigned int  MCK_clock_speed; //main.c
Clk_Setting project_h_clk_set;

// -----------------------------------------------------------------------------
//  Function Name  : clk_apply_project_h_settings
//  Object         : configure clocks using project.h definitions
// -----------------------------------------------------------------------------
//
extern uint32_t clk_apply_project_h_settings(void)
{
 
////////////////////////////////////////////////////////////////////////////////
#if (PMC_HAS_MCKR_FIELD_MDIV==0)
  #undef  MCK_MDIV
  #define MCK_MDIV 0 //not used
#endif
#if (PLLA_HAS_DIVIDER==0)
  #undef PLLA_DIV
  #define PLLA_DIV (0x01)
#endif
#if (DEVICE_HAS_PLLB==0)
  #define PLLB_MUL (0)
  #define PLLB_DIV (0)
#endif
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

#warning To implement: feed project_h_clk_set with project.h definitions
  return(clk_apply_settings(&project_h_clk_set)); 
}



// -----------------------------------------------------------------------------
//  Function Name       : clk_apply_settings
//  Object              : configure clocks from setting dedicated structure
// -----------------------------------------------------------------------------
//  Parameters:
//       clk_set   : clocks settings structure
////////////////////////////////////////////////////////////////////////////////
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
// __root function (linked even if never called)
__root extern uint32_t clk_apply_settings(Clk_Setting* clk_set)
{
#warning: sanity check on tag could be added
  
#warning: this is a wrapper to previous set_clocks code
 uint32_t old_set_clocks_result;
 uint8_t main_clk_config; //from clk_set structure
 uint8_t mck_config;      //from clk_set structure
 uint32_t plla_mul;       //from clk_set structure
 uint32_t plla_div;       //from clk_set structure
 uint32_t pllb_mul;       //from clk_set structure
 uint32_t pllb_div;       //from clk_set structure
 uint8_t pck_prescaler;   //from clk_set structure
 uint8_t mck_div;         //from clk_set structure
 uint8_t plldiv2;         //from clk_set structure
 
  uint8_t PmcWpmrValue;         //to be used for checking write protection
 
 //uint32_t prescaler, mdiv, main_clk_speed, pll_speed, slow_ck_freq;
  
  //retrieve parameters
  switch(CLK_SET_FIELD(clk_set,MAIN_CK,RC_FREQ_MHZ_DIV2))
  {
  case  2: main_clk_config = (uint8_t)USE_RC_4MHZ;  break;
  case  4: main_clk_config = (uint8_t)USE_RC_8MHZ;  break;
  case  6: main_clk_config = (uint8_t)USE_RC_12MHZ; break;
  case  8: main_clk_config = (uint8_t)USE_RC_16MHZ; break;
  case 12: main_clk_config = (uint8_t)USE_RC_24MHZ; break;
  case  0: if(CLK_SET_FIELD(clk_set,MAIN_CK,USE_XTAL)){main_clk_config = USE_XTAL;}
           else {main_clk_config = (uint8_t)USE_EXT_CLK;}
           break;
  default: return(CLK_SET_UNSUPPORTED_CFG_ERR);
  }
  
  if(CLK_SET_FIELD(clk_set,MASTER_CK,USE_MAIN)){mck_config=(uint8_t)USE_MAIN_CLK;} else
  if(CLK_SET_FIELD(clk_set,MASTER_CK,USE_SLOW)){mck_config=(uint8_t)USE_SLOW_CLK;} else
  if(CLK_SET_FIELD(clk_set,MASTER_CK,USE_PLLA)){mck_config=(uint8_t)USE_PLLA;}     else
  if(CLK_SET_FIELD(clk_set,MASTER_CK,USE_PLLB)){mck_config=(uint8_t)USE_PLLB;}     else
  if(CLK_SET_FIELD(clk_set,MASTER_CK,USE_PLLU)){return(CLK_SET_UNSUPPORTED_CFG_ERR);}
  
  pck_prescaler=(uint8_t)CLK_SET_FIELD(clk_set,MASTER_CK,PROC_PRESCALER);
  mck_div=(uint8_t)CLK_SET_FIELD(clk_set,MASTER_CK,BUS_MDIV);
  
  plla_div=(uint32_t)CLK_SET_FIELD(clk_set,PLL,PRE_DIV);
  plla_mul=(uint32_t)CLK_SET_FIELD(clk_set,PLL,MUL);
  plldiv2=(uint8_t)CLK_SET_FIELD(clk_set,PLL,POST_DIV2);
  
#warning plla parameters reported
  pllb_mul=(uint32_t)plla_mul;
  pllb_div=(uint32_t)plla_div;
  //pllu_mul=plla_div;
  //pllu_div=plla_div;

  // Configure max flash wait states on MCU products //#warning not generic!!!
  #if(DEVICE_HAS_EFC0==1)
   //covered with next case
  #endif
  #if(DEVICE_HAS_EFC1==1)
    REG_EFC0_FMR |= EEFC_FMR_FWS_Msk; //set to max
    REG_EFC1_FMR |= EEFC_FMR_FWS_Msk; //set to max
  #elif (DEVICE_HAS_EFC==1)
    REG_EFC_FMR |= EEFC_FMR_FWS_Msk; //set to max
  #else
    //MPU: nothing to do...
  #endif

    
//#warning: PMC wp status should be checked prior to accessing register
    
  PmcWpmrValue = REG_PMC_WPMR;
  REG_PMC_WPMR = PMC_WPMR_WPKEY_PASSWD | 0x00; // Unprotect PMC
  old_set_clocks_result = set_clocks(main_clk_config,mck_config,plla_mul,plla_div,pllb_mul,pllb_div,pck_prescaler,mck_div,plldiv2);
  //old_set_clocks_result = set_clocks(0x11,0x22,0x33333333,0x44444444,0x55555555,0x66666666,0x77,0x88,0x99);  
  REG_PMC_WPMR = PMC_WPMR_WPKEY_PASSWD | PmcWpmrValue; // Restore PMC WPMR value as before
  
  // Configure flash wait states on MCU products //#warning not generic!!!
  #if(DEVICE_HAS_EFC0==1)
   //covered with next case
  #endif
  #if(DEVICE_HAS_EFC1==1)
    REG_EFC0_FMR = (REG_EFC0_FMR&(~EEFC_FMR_FWS_Msk)|(EEFC_FMR_FWS(CLK_SET_FIELD(clk_set,EFC,EFC0_WS))));
    REG_EFC1_FMR = (REG_EFC1_FMR&(~EEFC_FMR_FWS_Msk)|(EEFC_FMR_FWS(CLK_SET_FIELD(clk_set,EFC,EFC1_WS))));
  #elif (DEVICE_HAS_EFC==1)
    REG_EFC_FMR = (REG_EFC_FMR&(~EEFC_FMR_FWS_Msk)|(EEFC_FMR_FWS(CLK_SET_FIELD(clk_set,EFC,EFC0_WS))));
  #else
    //MPU: nothing to do...
  #endif

  return(old_set_clocks_result);
}


