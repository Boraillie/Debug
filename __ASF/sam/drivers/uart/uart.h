/*! \file *********************************************************************
 *
 * \brief UART driver for SAM3.
 *
 * $asf_license$
 *
 * \par Purpose
 *
 * This file contains basic functions for the SAM3 UART, with support for all
 * modes, settings and clock speeds.
 *
 * \par Usage
 *
 * -# Enable the UART peripheral clock in the PMC.
 * -# Enable the required UART PIOs (see pio.h).
 * -# Configure the UART by calling uart_init.
 * -# Send data through the UART using the uart_write.
 * -# Receive data from the UART using the uart_read; 
 *    the availability of data can be polled with 
 *    uart_is_rx_ready.
 * -# Disable the transmitter and/or the receiver of the UART with
 *    uart_disable_tx and uart_disable_rx.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM3
 * - Supported devices:  All SAM3 devices with a UART module can be used.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 ******************************************************************************/

#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

#include  "compiler.h"

/*! \brief Option list for UART peripheral initialize */
typedef struct sam_uart_opt {
	//! MCK for UART
	uint32_t dw_mck;
	//! Expected baud rate
	uint32_t dw_baudrate;
	//! Initialize value for UART mode register
	uint32_t dw_mode;
	//! Configure channel mode (Normal, Automatic, Local_loopback or Remote_loopback)
	uint32_t dw_chmode;
} sam_uart_opt_t;

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

extern uint32_t uart_init(Uart * p_uart, const sam_uart_opt_t * p_uart_opt);
extern void uart_enable_tx(Uart * p_uart);
extern void uart_disable_tx(Uart * p_uart);
extern void uart_reset_tx(Uart * p_uart);
extern void uart_enable_rx(Uart * p_uart);
extern void uart_disable_rx(Uart * p_uart);
extern void uart_reset_rx(Uart * p_uart);
extern void uart_enable(Uart * p_uart);
extern void uart_disable(Uart * p_uart);
extern void uart_reset(Uart * p_uart);
extern void uart_enable_interrupt(Uart * p_uart, uint32_t dw_sources);
extern void uart_disable_interrupt(Uart * p_uart, uint32_t dw_sources);
extern uint32_t uart_get_interrupt_mask(Uart * p_uart);
extern uint32_t uart_get_status(Uart * p_uart);
extern uint32_t uart_is_tx_ready(Uart * p_uart);
extern uint32_t uart_is_tx_empty(Uart * p_uart);
extern uint32_t uart_is_rx_ready(Uart * p_uart);

#ifndef SAMA5 //ERr SAMA5
extern uint32_t uart_is_rx_buf_end(Uart * p_uart);
extern uint32_t uart_is_tx_buf_end(Uart * p_uart);
extern uint32_t uart_is_rx_buf_full(Uart * p_uart);
#endif //ERr SAMA5

extern uint32_t uart_is_tx_buf_empty(Uart * p_uart);
extern uint32_t uart_write(Uart * p_uart, const uint8_t uc_data);
extern uint32_t uart_read(Uart * p_uart, uint8_t * puc_data);

#ifndef SAMA5 //ERr SAMA5
	#if DEVICE_HAS_DMAC

	#else
		extern Pdc *uart_get_pdc_base(Uart * p_uart);
	#endif
#endif

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* UART_H_INCLUDED */
