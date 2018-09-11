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
 * File Name           : v_utils.h
 * Object              :
 * Creation            : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_UTILS_H
#define _V_UTILS_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"


// ---- Peripherals (ASF drivers)
#include "drivers/pmc/pmc.h"
#if (DEVICE_HAS_PIOV4==1)
 #include "v_drivers/v_pioV4.h"
#else
 #include "drivers/pio/pio.h"
#endif

// ---- Validation libraries
#include "v_debug.h"
#if DEVICE_HAS_DWDT==1 
#include "v_drivers/v_dwdt.h"
#endif

#if DEVICE_HAS_WDT==1 
#include "v_drivers/v_wdt.h"
#endif



#include "v_drivers/v_pmc.h"
#if DEVICE_HAS_SUPC
  #include "v_drivers/v_supc.h"
#endif
#if DEVICE_HAS_EFC0
  #include "v_drivers/v_efc.h"
#endif
 

/*----------------------------------------------------------------------------*/
/* Reset sources (define values are device dependant)                         */
/*----------------------------------------------------------------------------*/
#define POR_RESET 0x0 // (SAM3S) power up
#define BUP_RESET 0x1 // (SAM3S) return from backup mode
#define WDT_RESET 0x2 // (SAM3S) watchdog fault detect
#define SW_RESET  0x3 // (SAM3S) software reset
#define USR_RESET 0x4 // (SAM3S) user reset (external NRST)
#define RESERVED_RESET 0x5 // added on 65108
#define CPUFAIL_RESET  0x6 // added on 65108
#define SLCKXTAL_RST   0x7 // added on 65108
//RSTC_SR_RSTTYP_GENERAL_RST (0x0u << 8)
//RSTC_SR_RSTTYP_BACKUP_RST (0x1u << 8)
//RSTC_SR_RSTTYP_WDT_RST (0x2u << 8)
//RSTC_SR_RSTTYP_SOFT_RST (0x3u << 8)
//RSTC_SR_RSTTYP_USER_RST (0x4u << 8)
#if (DEVICE_HAS_SUPC == 1)
  #define NB_RST_SOURCE  10
  #define BOD_RESET 0x8 // brownout detect
  #define SM_RESET  0x9 // supply monitor detect
#else
  #define NB_RST_SOURCE  8
#endif
#define RST_LABEL_SIZE 15
/*----------------------------------------------------------------------------*/

// ----------------------------------------------------------------------------
//  Watchdog Timer
// ----------------------------------------------------------------------------
#define WDT_MAX 0
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//  Dual Watchdog Timer
// ----------------------------------------------------------------------------
#define DWDT_MAX 0
// ----------------------------------------------------------------------------


//*---------------------------------------------------------------------------*/
//* Timeout macro
//* Object       : wait until cond is true with timeout=val
//*---------------------------------------------------------------------------*/
#define WAIT_UNTIL(cond, val) for(uint32_t _i__=0;!cond && _i__++<val;)
#define WAIT_WHILE(cond, val) for(uint32_t _i__=0;cond && _i__++<val;)
//*---------------------------------------------------------------------------*/


#ifndef WAIT_LOOP_ITER_CYCLES
  #define WAIT_LOOP_ITER_CYCLES 9 // number of MCK cycles to execute 1 increment
#endif



/*----------------------------------------------------------------------------*/
/* Prototypes                                                                 */
/*----------------------------------------------------------------------------*/
#ifndef SAMA5 //ERr SAMA5
extern void external_reset_enable(void);
extern void external_reset_disable(void);
#endif //ERr SAMA5

#if DEVICE_HAS_WDT==1 
extern void watchdog_enable(Wdt* p_wdt, uint32_t time);
#endif

#if DEVICE_HAS_DWDT==1 
extern void dual_watchdog_enable(Dwdt* p_dwdt, uint32_t time);
#endif

extern uint32_t config_clocks(void);
uint32_t set_clocks(uint8_t main_clk_config, uint8_t mck_config, \
             uint32_t plla_mul, uint32_t plla_div, uint32_t pllb_mul, uint32_t pllb_div,
             uint8_t pck_prescaler, uint8_t mck_div, uint8_t plldiv2);
extern uint32_t check_reset_source();
extern void wait_loop(uint32_t count);
extern void wait_time(uint32_t time);
#if DEVICE_HAS_SUPC
extern void brownout_detector_enable();
extern void supply_monitor_enable();
extern void supply_monitor_disable();
#endif
#if DEVICE_HAS_EFC0
extern void display_flash_desc_dbgu(iflash_descriptor_t* fdes);
#endif
#if (__DTCM_PRESENT==1)
extern void DTCM_Enable(void);
#endif
#if (__ITCM_PRESENT==1)
extern void ITCM_Enable(void);
#endif
#if (__ICACHE_PRESENT==1)
extern void EnableICache(void);
extern void DisableICache(void);
#endif
//*---------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------*/
/* Inline functions definitions                                               */


/*----------------------------------------------------------------------------*/
//* Function Name : Valid_DebugTrace
//* Object       : debug trace (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
#pragma inline=forced
inline void Valid_DebugTrace(char *buffer)
{
#if (DEBUG_MODE==SERIAL_DEBUG)
  DEBUG_Printk(buffer);
#else
  return;
#endif
}


/*----------------------------------------------------------------------------*/
//* Function Name : Valid_DebugPrintReg
//* Object       : print reg value (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
#pragma inline=forced
inline void Valid_DebugPrintReg(uint32_t reg_addr32)
{
#if (DEBUG_MODE==SERIAL_DEBUG)
  DEBUG_PrintReg(reg_addr32);
#else
  return;
#endif
}


/*----------------------------------------------------------------------------*/
//* Function Name : Valid_DebugPrintRegX
//* Object       : print reg value (depend on DEBUG_MODE defined in project.h)
//*---------------------------------------------------------------------------*/
#pragma inline=forced
inline void Valid_DebugPrintRegX(uint32_t reg_addr32)
{
#if (DEBUG_MODE==SERIAL_DEBUG)
  DEBUG_PrintRegX(reg_addr32);
#else
  return;
#endif
}


/*----------------------------------------------------------------------------*/

#endif //_V_UTILS_H