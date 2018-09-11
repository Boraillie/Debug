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
 * File Name           : v_it_management.c
 *----------------------------------------------------------------------------
*/

#include "v_it_management.h"






//------------------------------------------------------------------------------
//* Function Name : enable_interrupt                                          --
//* Object        : enables an interrupt line                                 --
//* Parameter     : periph_id = peripheral identifier                         --
//------------------------------------------------------------------------------
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void enable_interrupt(uint32_t periph_id)
{
#ifndef SAMA5
    #ifndef SAM9X6  
      nvic_enable_it(periph_id);
    #else 
      aic_enable_it(AIC,periph_id);
    #endif //MNn SAM9X6  
#else // SAMA5
  //#if ( ISLERO==1)
  #if (DEVICE_HAS_SAIC==1)
    #warning debug config: for any peripheral, both AIC & SAIC will be configured
             aic_enable_it(SAIC,periph_id);
  #endif
      aic_enable_it(AIC,periph_id);
#endif 
}

//------------------------------------------------------------------------------
//* Function Name : disable_interrupt                                          --
//* Object        : disables an interrupt line                                 --
//* Parameter     : periph_id = peripheral identifier                         --
//------------------------------------------------------------------------------
#pragma location = ".prg_used_utils_functions" //used by prg mode linker
__root extern void disable_interrupt(uint32_t periph_id)
{
#ifndef SAMA5 
    #ifndef SAM9X6  
      nvic_disable_it(periph_id);
    #else 
      aic_disable_it(AIC,periph_id);
    #endif //MNn SAM9X6

#else // SAMA5
  #if (DEVICE_HAS_SAIC==1)
    #warning debug config: for any peripheral, both AIC & SAIC will be configured
            aic_disable_it(SAIC,periph_id);
  #endif
      aic_disable_it(AIC,periph_id);
#endif 
}
//------------------------------------------------------------------------------


#ifndef SAMA5
  //NVIC_ClearPendingIRQ(periph_id); (inline func declared in .h)
#else
  #warning clear_pending_interrupt function not supported yet
#endif
