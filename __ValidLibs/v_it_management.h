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
 * File Name           : v_it_management.h
 * Object              :
 * Creation            : ERr   Dec/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_IT_MANAGEMENT_H
#define _V_IT_MANAGEMENT_H


#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "board.h"

// ---- Peripherals (ASF drivers)

// ---- Validation libraries
#if (DEVICE_HAS_AIC==1)
  #include "v_drivers/v_aic.h"
#else // CortexM / NVIC
  #include "v_drivers/v_nvic.h"
#endif
/*
#ifdef SAMA5
  #include "v_drivers/v_aic.h"
#else
  #include "v_drivers/v_nvic.h"
#endif
*/

//------------------------------------------------------------------------------
// Definitions     ----
//---------------------

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Inline functions ---
//---------------------
//------------------------------------------------------------------------------
//* Function Name : enable_interrupt                                          --
//* Object        : enables an interrupt line                                 --
//* Parameter     : periph_id = peripheral identifier                         --
//------------------------------------------------------------------------------
#pragma inline=forced
inline void clear_pending_interrupt(IRQn_Type periph_id)
{
#if (DEVICE_HAS_AIC==1)
  //#warning clear_pending_interrupt function not supported yet
#else // CortexM / NVIC
  NVIC_ClearPendingIRQ(periph_id);
#endif
/*
#ifndef SAMA5
  NVIC_ClearPendingIRQ(periph_id);
#else
  //#warning clear_pending_interrupt function not supported yet
#endif
*/
}


//------------------------------------------------------------------------------
// Prototypes      ----
//---------------------
extern void enable_interrupt(uint32_t periph_id);
extern void disable_interrupt(uint32_t periph_id);
//------------------------------------------------------------------------------



#endif //_V_IT_MANAGEMENT_H