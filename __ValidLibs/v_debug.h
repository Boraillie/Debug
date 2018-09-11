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
 * File Name           : v_debug.h
 * Object              :
 * Creation            : JPP   04/Sep/2006
 *                     : ERr   Sep/2011
 *----------------------------------------------------------------------------
*/
#ifndef _V_DEBUG_H
#define _V_DEBUG_H


#include "project.h"

// ---- General purpose include files
#include <stdio.h> //IAR
#include "device.h"
#include "board.h"


// ---- Peripherals (ASF drivers)
#include "drivers/pmc/pmc.h"

// ---- Validation libraries
#include "v_it_management.h"


//------------------------------------------------------------------------------
// DEBUG Definition ----
//----------------------
#define DEFAULT_DEBUG_BAUD_RATE  DEBUG_BAUD_RATE //defined in project.h



#if ( DEBUG_LINK_USED == DBG_UNIT ) 
      #define DEBUG_LINK_TYPE      TYPE_DBGU
      #define ID_DEBUG             ID_DBGU
      #define BASE_DEBUG           DBGU
      #define BRD_BASE_PIO_DEBUG   BRD_BASE_PIO_DBGU
      #define BRD_ID_PIO_DEBUG     BRD_ID_PIO_DBGU      
      #define PIO_PERIPH_DEBUG     BRD_PERIPH_DBGU
      #define DEBUG_RXD	           BRD_DBGU_RXD
      #define DEBUG_TXD	           BRD_DBGU_TXD
 //     #define IRQ_DEBUG_HANDLER    DBGU##HANDLER_SUFFIX
#ifndef DB
#ifndef GU
      #define IRQ_DEBUG_HANDLER     MERGE(DB  , GU ,       ,HANDLER_SUFFIX)
#else
#error GU already defined elsewhere and will cause a conflict here
#endif //GU
#else
#error DB already defined elsewhere and will cause a conflict here
#endif //DB
    
#else 

    #define DEBUG_LINK_TYPE          MERGE(TYPE_              ,DEBUG_LINK_USED         ,                       ,       )
    //#define ID_DEBUG                (MERGE(ID_               , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,       ))
    #define BASE_DEBUG              (MERGE(DEBUG_LINK_USED   , DEBUG_LINK_NUMBER      ,                       ,       ))
    #define BRD_BASE_PIO_DEBUG      (MERGE(BRD_BASE_PIO_     , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,       ))
    #define BRD_ID_PIO_DEBUG        (MERGE(BRD_ID_PIO_       , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,       ))
    #define PIO_PERIPH_DEBUG        (MERGE(BRD_PERIPH_       , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,       ))
    #define DEBUG_RXD	            (MERGE(BRD_              , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,_RXD   ))
    #define DEBUG_TXD	            (MERGE(BRD_              , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,_TXD   ))

    #if DEVICE_HAS_FLEXCOM
      #define DEBUG_IS_FLEXCOM       (MERGE(DEBUG_LINK_USED   , DEBUG_LINK_NUMBER      ,                       ,_IS_FLEXCOM   ))
      #if (DEBUG_IS_FLEXCOM==1)
        #define FLEXCOM_DEBUG        (MERGE(FLEXCOM           , DEBUG_LINK_NUMBER      ,                       ,       ))                                                              
        #define IRQ_DEBUG_HANDLER     MERGE(FLEXCOM           , DEBUG_LINK_NUMBER      , HANDLER_SUFFIX        ,        )
        #define ID_DEBUG             (MERGE(ID_               , FLEXCOM                , DEBUG_LINK_NUMBER     ,       ))
      #else
        #define IRQ_DEBUG_HANDLER     MERGE(DEBUG_LINK_USED    , DEBUG_LINK_NUMBER      , HANDLER_SUFFIX        ,        )
        #define ID_DEBUG             (MERGE(ID_               , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,       ))
      #endif    
    #else
      #define IRQ_DEBUG_HANDLER     MERGE(DEBUG_LINK_USED    , DEBUG_LINK_NUMBER      , HANDLER_SUFFIX        ,        )
      #define ID_DEBUG             (MERGE(ID_               , DEBUG_LINK_USED        , DEBUG_LINK_NUMBER     ,       ))
    #endif

#endif 

#if (DEBUG_LINK_TYPE==TYPE_DBGU)
  #include "v_drivers/v_dbgu.h"
  #define DEBUG_is_rx_ready        dbgu_is_rx_ready
  #define DEBUG_is_tx_ready        dbgu_is_tx_ready
  #define DEBUG_is_tx_empty        dbgu_is_tx_empty
  #define DEBUG_write              dbgu_write
  #define DEBUG_read               dbgu_read
  #define DEBUG_init               dbgu_init
  #define DEBUG_reset_rx           dbgu_reset_rx
  #define DEBUG_enable_tx          dbgu_enable_tx
  #define DEBUG_enable_rx          dbgu_enable_rx
  #define DEBUG_enable_interrupt   dbgu_enable_interrupt
  #define DEBUG_PERIPH_T           Dbgu
  #define DEBUG_PERIPH_OPTIONS_T   sam_dbgu_opt_t
#if SAM9X6
  #define DEBUG_PERIPH_mode        DBGU_MR_PAR_NO// DBGU_MR_PAR_NONE
  #define DEBUG_PERIPH_chmode      DBGU_MR_CHMODE_NORMAL// DBGU_MR_CHMODE_NORM
#else
  #define DEBUG_PERIPH_mode        DBGU_MR_PAR_NONE
  #define DEBUG_PERIPH_chmode      DBGU_MR_CHMODE_NORM
#endif // MNn SAM9X6
  #define DEBUG_IER_RXRDY          DBGU_IER_RXRDY



#elif (DEBUG_LINK_TYPE==TYPE_UART)
  #include "drivers/uart/uart.h"
  #define DEBUG_is_rx_ready        uart_is_rx_ready
  #define DEBUG_is_tx_ready        uart_is_tx_ready
  #define DEBUG_is_tx_empty        uart_is_tx_empty
  #define DEBUG_write              uart_write
  #define DEBUG_read               uart_read
  #define DEBUG_init               uart_init
  #define DEBUG_reset_rx           uart_reset_rx
  #define DEBUG_enable_tx          uart_enable_tx
  #define DEBUG_enable_rx          uart_enable_rx
  #define DEBUG_enable_interrupt   uart_enable_interrupt
  #define DEBUG_PERIPH_T           Uart
  #define DEBUG_PERIPH_OPTIONS_T   sam_uart_opt_t
  #define DEBUG_PERIPH_mode        UART_MR_PAR_NO
  #define DEBUG_PERIPH_chmode      UART_MR_CHMODE_NORMAL
  #define DEBUG_IER_RXRDY          UART_IER_RXRDY
#elif (DEBUG_LINK_TYPE==TYPE_USART)
  #include "v_drivers/v_usart.h"
  #define DEBUG_is_rx_ready        usart_is_rx_ready
  #define DEBUG_is_tx_ready        usart_is_tx_ready
  #define DEBUG_is_tx_empty        usart_is_tx_empty
  #define DEBUG_write              usart_write
  #define DEBUG_read               usart_read
  #define DEBUG_init               usart_init
  #define DEBUG_reset_rx           usart_reset_rx
  #define DEBUG_enable_tx          usart_enable_tx
  #define DEBUG_enable_rx          usart_enable_rx
  #define DEBUG_enable_interrupt   usart_enable_interrupt
  #define DEBUG_PERIPH_T           Usart
  #define DEBUG_PERIPH_OPTIONS_T   sam_usart_opt_t
  #define DEBUG_PERIPH_mode        (US_MR_USART_MODE_NORMAL | US_MR_CHRL_8_BIT | US_MR_PAR_NO)
  #define DEBUG_PERIPH_chmode      US_MR_CHMODE_NORMAL
  #define DEBUG_IER_RXRDY          US_IER_RXRDY
#endif
//------------------------------------------------------------------------------



/*------------------*/
/* Prototypes       */
/*------------------*/
extern void DEBUG_Ready(void);
extern void DEBUG_Printk(char *buffer);
extern void DEBUG_PrintReg(uint32_t val32);
extern void DEBUG_PrintRegX(uint32_t val32);
extern void DEBUG_PrintRegX16(uint32_t val32);
extern void DEBUG_PrintRegX8(uint32_t val32);
extern int DEBUG_Get(char *val);
extern void DEBUG_Initialize (unsigned int uBaud);



#endif //_V_DEBUG_H