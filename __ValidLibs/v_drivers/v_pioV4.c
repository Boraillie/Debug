/*! \file *********************************************************************
 *
 * \brief PIO V4 driver.
 *
 *
 * - Compiler:           tested on IAR EWARM
 * - Supported devices:  SAMA5D2x (92U01)
 * - AppNote:
 *
 ******************************************************************************/

#if !defined(V_PIOV4_FUNC_INLINE) || (V_PIOV4_FUNC_INLINE==0)
// the #defines below must appear BEFORE the #include
  #define _V_PIOV4_FUNC_QUALIFIER // void on purpose (other values: inline,extern)
  #define _V_PIOV4_FUNC_IMPLEMENT (1)
  #include "v_pioV4.h"
  
//Set output level before driving, to prevent any unexpected edge on pin.
uint32_t v_pioV4_iocfg_output_noedge(PioIo_group* IO_group, const uint32_t mask)
{
#warning v_pioV4_iocfg_output_noedge function still to implement!!!
}
    
   
#endif

