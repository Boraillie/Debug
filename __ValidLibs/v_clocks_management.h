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
 * File Name           : v_clocks_management.h
 *----------------------------------------------------------------------------
*/
#ifndef _V_CLOCKS_MANAGEMENT_H
#define _V_CLOCKS_MANAGEMENT_H


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
#include "board.h"



// Error codes definitions
#define CLK_SET_UNSUPPORTED_CFG_ERR  (0xC5EC0001)

// Definitions
#define CLK_SET_TAG_PATTERN (0xC10Cu)
#define CLK_SET_FIELD(clk_set,reg,field) (((clk_set->CLK_SET_##reg)&reg##_##field##_Msk)>>(reg##_##field##_Pos))

#if SAM9X6
  #define SLOW_CLOCK_SELECTED ((PMC->PMC_CPU_CKR & PMC_CPU_CKR_CSS_Msk)==(PMC_CPU_CKR_CSS_SLOW_CLK & PMC_CPU_CKR_CSS_Msk))
#else
  #define SLOW_CLOCK_SELECTED ((PMC->PMC_MCKR & PMC_MCKR_CSS_Msk)==(PMC_MCKR_CSS_SLOW_CLK & PMC_MCKR_CSS_Msk))
#endif // MNn SAM9X6

typedef struct {
  uint32_t CLK_SET_TAG;
  uint32_t CLK_SET_MAIN_CK;
  uint32_t CLK_SET_MASTER_CK;
  uint32_t CLK_SET_PLL;
  uint32_t CLK_SET_SLOW_CK;
  uint32_t CLK_SET_EFC;
  uint32_t Reserved[2];
} Clk_Setting;

//-----------------------------------------------------------------------------
//TAG
#define TAG_TAG_Pos (16)
#define TAG_TAG_Msk (0xFFFFu << TAG_TAG_Pos)
#define TAG_TAG(value) ((TAG_TAG_Msk & ((value) << TAG_TAG_Pos)))
#define TAG_IDX_Pos (0)
#define TAG_IDX_Msk (0xFFu << TAG_IDX_Pos)
#define TAG_IDX(value) ((TAG_IDX_Msk & ((value) << TAG_IDX_Pos)))
//-----------------------------------------------------------------------------
//MAIN_CK
#define MAIN_CK_RC_FREQ_MHZ_DIV2_Pos (0)
#define MAIN_CK_RC_FREQ_MHZ_DIV2_Msk (0x3Fu << MAIN_CK_RC_FREQ_MHZ_DIV2_Pos)
#define MAIN_CK_RC_FREQ_MHZ_DIV2(value) ((MAIN_CK_RC_FREQ_MHZ_DIV2_Msk & ((value) << MAIN_CK_RC_FREQ_MHZ_DIV2_Pos)))
#define MAIN_CK_USE_XTAL_Pos (6)
#define MAIN_CK_USE_XTAL_Msk (0x1u << MAIN_CK_USE_XTAL_Pos)
#define MAIN_CK_USE_XTAL      MAIN_CK_USE_XTAL_Msk
#define MAIN_CK_USE_EXTCLK_Pos (7)
#define MAIN_CK_USE_EXTCLK_Msk (0x1u << MAIN_CK_USE_EXTCLK_Pos)
#define MAIN_CK_USE_EXTCLK     MAIN_CK_USE_EXTCLK_Msk
#define EXT_FREQ_HZ_DIV8_Pos (8)
#define EXT_FREQ_HZ_DIV8_Msk (0xFFFFFFu << EXT_FREQ_HZ_DIV8_Pos)
#define EXT_FREQ_HZ_DIV8(value) ((EXT_FREQ_HZ_DIV8_Msk & ((value) << EXT_FREQ_HZ_DIV8_Pos)))
//-----------------------------------------------------------------------------
//MASTER_CK
#define MASTER_CK_USE_MAIN_Pos (0)
#define MASTER_CK_USE_MAIN_Msk (0x1u << MASTER_CK_USE_MAIN_Pos)
#define MASTER_CK_USE_MAIN      MASTER_CK_USE_MAIN_Msk
#define MASTER_CK_USE_SLOW_Pos (1)
#define MASTER_CK_USE_SLOW_Msk (0x1u << MASTER_CK_USE_SLOW_Pos)
#define MASTER_CK_USE_SLOW      MASTER_CK_USE_SLOW_Msk
#define MASTER_CK_USE_PLLA_Pos (2)
#define MASTER_CK_USE_PLLA_Msk (0x1u << MASTER_CK_USE_PLLA_Pos)
#define MASTER_CK_USE_PLLA      MASTER_CK_USE_PLLA_Msk
#define MASTER_CK_USE_PLLB_Pos (3)
#define MASTER_CK_USE_PLLB_Msk (0x1u << MASTER_CK_USE_PLLB_Pos)
#define MASTER_CK_USE_PLLB      MASTER_CK_USE_PLLB_Msk
#define MASTER_CK_USE_PLLU_Pos (4)
#define MASTER_CK_USE_PLLU_Msk (0x1u << MASTER_CK_USE_PLLU_Pos)
#define MASTER_CK_USE_PLLU      MASTER_CK_USE_PLLU_Msk
#define MASTER_CK_PROC_PRESCALER_Pos (8)
#define MASTER_CK_PROC_PRESCALER_Msk (0xFFu << MASTER_CK_PROC_PRESCALER_Pos)
#define MASTER_CK_PROC_PRESCALER(value) ((MASTER_CK_PROC_PRESCALER_Msk & ((value) << MASTER_CK_PROC_PRESCALER_Pos)))
#define MASTER_CK_BUS_MDIV_Pos (16)
#define MASTER_CK_BUS_MDIV_Msk (0xFFu << MASTER_CK_BUS_MDIV_Pos)
#define MASTER_CK_BUS_MDIV(value) ((MASTER_CK_BUS_MDIV_Msk & ((value) << MASTER_CK_BUS_MDIV_Pos)))
//-----------------------------------------------------------------------------
//PLL
#define PLL_PRE_DIV_Pos (0)
#define PLL_PRE_DIV_Msk (0xFFu << PLL_PRE_DIV_Pos)
#define PLL_PRE_DIV(value) ((PLL_PRE_DIV_Msk & ((value) << PLL_PRE_DIV_Pos)))
#define PLL_MUL_Pos (8)
#define PLL_MUL_Msk (0xFFFFu << PLL_MUL_Pos)
#define PLL_MUL(value) ((PLL_MUL_Msk & ((value) << PLL_MUL_Pos)))
#define PLL_POST_DIV2_Pos (24)
#define PLL_POST_DIV2_Msk (0x1u << PLL_POST_DIV2_Pos)
#define PLL_POST_DIV2     PLL_POST_DIV2_Msk
//-----------------------------------------------------------------------------
//SLOW_CK
#define SLOW_CK_USE_RC_Pos (0)
#define SLOW_CK_USE_RC_Msk (0x1u << SLOW_CK_USE_RC_Pos)
#define SLOW_CK_USE_RC     SLOW_CK_USE_RC_Msk
#define SLOW_CK_USE_XTAL_Pos (1)
#define SLOW_CK_USE_XTAL_Msk (0x1u << SLOW_CK_USE_XTAL_Pos)
#define SLOW_CK_USE_XTAL     SLOW_CK_USE_XTAL_Msk
#define SLOW_CK_USE_EXTCLK_Pos (2)
#define SLOW_CK_USE_EXTCLK_Msk (0x1u << SLOW_CK_USE_EXTCLK_Pos)
#define SLOW_CK_USE_EXTCLK     SLOW_CK_USE_EXTCLK_Msk
#define SLOW_CK_EXT_FREQ_Pos (8)
#define SLOW_CK_EXT_FREQ_Msk (0xFFFFFFu << SLOW_CK_EXT_FREQ_Pos)
#define SLOW_CK_EXT_FREQ(value) ((SLOW_CK_EXT_FREQ_Msk & ((value) << SLOW_CK_EXT_FREQ_Pos)))
//-----------------------------------------------------------------------------
//EFC
#define EFC_EFC0_WS_Pos (0)
#define EFC_EFC0_WS_Msk (0xFu << EFC_EFC0_WS_Pos)
#define EFC_EFC0_WS(value) ((EFC_EFC0_WS_Msk & ((value) << EFC_EFC0_WS_Pos)))
#define EFC_EFC1_WS_Pos (8)
#define EFC_EFC1_WS_Msk (0xFu << EFC_EFC1_WS_Pos)
#define EFC_EFC1_WS(value) ((EFC_EFC1_WS_Msk & ((value) << EFC_EFC1_WS_Pos)))
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


// Prototypes -----------------------------------------------------------------
extern uint32_t clk_apply_settings(Clk_Setting* clk_set);
extern uint32_t clk_apply_project_h_settings(void);
// ----------------------------------------------------------------------------


#endif //_V_CLOCKS_MANAGEMENT_H



////////////////////////////////////////////////////////////////////////////////
//#define EXT_FREQ_HZ(clk_set) (((clk_set->CLK_SET_MAIN_CK)&(0xFFFFFF00))>>8)
//#define EXT_CLK_USE(clk_set) ((clk_set->CLK_SET_MAIN_CK)>>8)