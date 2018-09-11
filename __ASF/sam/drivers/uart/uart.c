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

#include  "uart.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

#define UART_MCK_DIV			16	/* UART internal div factor for sampling */
#define UART_MCK_DIV_MIN_FACTOR		1	/* Div factor to get the maximum baud rate */
#define UART_MCK_DIV_MAX_FACTOR		65535	/* Div factor to get the minimum baud rate */

/**
 * \brief Configure UART with the specified parameters.
 * The PMC and PIOs must be configured first.
 *
 * \param p_uart Pointer to the UART peripheral to configure.
 * \param p_uart_opt Pointer to sam_uart_opt_t instance.
 *
 * \retval 0 Success.
 * \retval 1 Bad baud rate generator value.
 */
uint32_t uart_init(Uart * p_uart, const sam_uart_opt_t * p_uart_opt)
{
	uint32_t cd = 0;

	/* Reset and disable receiver & transmitter */
	p_uart->UART_CR = UART_CR_RSTRX | UART_CR_RSTTX
			| UART_CR_RXDIS | UART_CR_TXDIS;

	/* Check and configure baudrate */
	/* Asynchronous, no oversampling */
	cd = (p_uart_opt->dw_mck / p_uart_opt->dw_baudrate) / UART_MCK_DIV;
	if (cd < UART_MCK_DIV_MIN_FACTOR || cd > UART_MCK_DIV_MAX_FACTOR)
		return 1;

	p_uart->UART_BRGR = cd;
	/* Configure mode */
	p_uart->UART_MR = p_uart_opt->dw_mode;

	/* Disable PDC channel */
#ifndef SAMA5 //ERr SAMA5
	#if UART_HAS_PDC
	p_uart->UART_PTCR = UART_PTCR_RXTDIS | UART_PTCR_TXTDIS;
	#else
	#endif
#endif //ERr SAMA5
        
	/* Enable receiver and transmitter */
	p_uart->UART_CR = UART_CR_RXEN | UART_CR_TXEN;

	return 0;
}

/**
 * \brief Enable UART transmitter.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_enable_tx(Uart * p_uart)
{
	/* Enable transmitter */
	p_uart->UART_CR = UART_CR_TXEN;
}

/**
 * \brief Disable UART transmitter.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_disable_tx(Uart * p_uart)
{
	/* Disable transmitter */
	p_uart->UART_CR = UART_CR_TXDIS;
}

/**
 * \brief Immediately stop and disable UART transmitter.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_reset_tx(Uart * p_uart)
{
	/* Reset transmitter */
	p_uart->UART_CR = UART_CR_TXDIS;
}

/**
 * \brief Enable UART receiver.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_enable_rx(Uart * p_uart)
{
	/* Enable receiver */
	p_uart->UART_CR = UART_CR_RXEN;
}

/**
 * \brief Disable UART receiver.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_disable_rx(Uart * p_uart)
{
	/* Disable receiver */
	p_uart->UART_CR = UART_CR_RXDIS;
}

/**
 * \brief Immediately stop and disable UART receiver.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_reset_rx(Uart * p_uart)
{
	/* Reset receiver */
	p_uart->UART_CR = UART_CR_RXDIS;
}

/**
 * \brief Enable UART receiver and transmitter.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_enable(Uart * p_uart)
{
	/* Enable receiver and transmitter */
	p_uart->UART_CR = UART_CR_RXEN | UART_CR_TXEN;
}

/**
 * \brief Disable UART receiver and transmitter.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_disable(Uart * p_uart)
{
	/* Disable receiver and transmitter */
	p_uart->UART_CR = UART_CR_RXDIS | UART_CR_TXDIS;
}

/**
 * \brief Reset UART receiver and transmitter.
 *
 * \param p_uart Pointer to an UART peripheral.
 */
void uart_reset(Uart * p_uart)
{
	/* Reset and disable receiver & transmitter */
	p_uart->UART_CR = UART_CR_RSTRX | UART_CR_RSTTX
			| UART_CR_RXDIS | UART_CR_TXDIS;
}

/** \brief Enable UART interrupts.
 *
 *  \param p_uart pointer to an Uart instance.
 *  \param dw_sources interrupt sources bit map.
 */
void uart_enable_interrupt(Uart * p_uart, uint32_t dw_sources)
{
	p_uart->UART_IER = dw_sources;
}

/** \brief Disable UART interrupts.
 *
 *  \param p_uart pointer to an Uart instance.
 *  \param dw_sources interrupt sources bit map.
 */
void uart_disable_interrupt(Uart * p_uart, uint32_t dw_sources)
{
	p_uart->UART_IDR = dw_sources;
}

/** \brief Read UART interrupt mask.
 *
 *  \param p_uart pointer to an Uart instance.
 *
 *  \return The interrupt mask value.
 */
uint32_t uart_get_interrupt_mask(Uart * p_uart)
{
	return p_uart->UART_IMR;
}

/**
 * \brief   Get current status.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \return The current UART status.
 */
uint32_t uart_get_status(Uart * p_uart)
{
	return p_uart->UART_SR;
}

/**
 * \brief Check if Transmit is Ready.
 * Check if Data has been loaded in UART_THR and is waiting to be loaded in the Transmit Shift Register (TSR).
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 Data has been transmitted.
 * \retval 0 Transmit is not ready, data pending.
 */
uint32_t uart_is_tx_ready(Uart * p_uart)
{
	return (p_uart->UART_SR & UART_SR_TXRDY) > 0;
}

/**
 * \brief Check if Transmit Hold Register is empty.
 * Check if Last data written in UART_THR has been loaded in TSR and last data loaded in TSR has been transmitted.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 Transmit is emtpy.
 * \retval 0 Transmit is not emtpy.
 */
uint32_t uart_is_tx_empty(Uart * p_uart)
{
	return (p_uart->UART_SR & UART_SR_TXEMPTY) > 0;
}

/**
 * \brief Check if Received data is ready.
 * Check if Data has been received and loaded in UART_RHR.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 One data has been received.
 * \retval 0 No data has been received.
 */
uint32_t uart_is_rx_ready(Uart * p_uart)
{
	return (p_uart->UART_SR & UART_SR_RXRDY) > 0;
}

/**
 * \brief Check if one receive buffer is filled.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 Receive complete.
 * \retval 0 Receive is still pending.
 */
#ifndef SAMA5 //ERr SAMA5
#if (UART_HAS_PDC == 1)
uint32_t uart_is_rx_buf_end(Uart * p_uart)
{

	return (p_uart->UART_SR & UART_SR_ENDRX) > 0;
}
/**
 * \brief Check if one transmit buffer is sent out.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 Transmit complete.
 * \retval 0 Transmit is still pending.
 */
uint32_t uart_is_tx_buf_end(Uart * p_uart)
{
	return (p_uart->UART_SR & UART_SR_ENDTX) > 0;
}
/**
 * \brief Check if both receive buffers are full.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 Receive buffers are full.
 * \retval 0 Receive buffers are not full.
 */
uint32_t uart_is_rx_buf_full(Uart * p_uart)
{
	return (p_uart->UART_SR & UART_SR_RXBUFF) > 0;
}
#endif //PDC

#endif //ERr SAMA5


/**
 * \brief Check if both transmit buffers are sent out.
 *
 * \param p_uart Pointer to an Uart instance.
 *
 * \retval 1 Transmit buffer is empty.
 * \retval 0 Transmit buffer is not empty.
 */
uint32_t uart_is_tx_buf_empty(Uart * p_uart)
{
	return (p_uart->UART_SR & UART_SR_TXEMPTY) > 0;
}

/**
 * \brief Write to UART Transmit Holding Register
 * Before writing user should check if tx is ready (or empty).
 *
 * \param p_uart Pointer to an UART peripheral.
 * \param data Data to be sent.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, UART is not ready.
 */
uint32_t uart_write(Uart * p_uart, const uint8_t uc_data)
{
	/* Check if the transmitter is ready */
	if (!(p_uart->UART_SR & UART_SR_TXRDY))
		return 1;

	/* Send character */
	p_uart->UART_THR = uc_data;
	return 0;
}

/**
 * \brief Read from UART Receive Holding Register.
 * Before reading user should check if rx is ready.
 *
 * \param p_uart Pointer to an UART peripheral.
 *
 * \retval 0 Success.
 * \retval 1 I/O Failure, UART is not ready.
 */
uint32_t uart_read(Uart * p_uart, uint8_t * puc_data)
{
	/* Check if the receiver is ready */
	if ((p_uart->UART_SR & UART_SR_RXRDY) == 0)
		return 1;

	/* Read character */
	*puc_data = (uint8_t) p_uart->UART_RHR;
	return 0;
}

/**
 * \brief Get PDC registers base address
 *
 * \param p_uart Pointer to an UART peripheral.
 *
 * \return PDC registers base for PDC driver to access.
 */
#ifndef SAMA5 //ERr SAMA5
#if DEVICE_HAS_PDC
Pdc *uart_get_pdc_base(Uart * p_uart)
{
	Pdc *p_pdc_base;
#if DEVICE_HAS_UART
  #ifdef UART
    if (p_uart == UART) p_pdc_base = PDC_UART;
  #endif
#endif
#if DEVICE_HAS_UART0
  #ifdef UART0
    #if UART0_HAS_PDC
      if (p_uart == UART0) p_pdc_base = PDC_UART0;
    #endif
  #endif
#endif
#if DEVICE_HAS_UART1
  #if UART1_HAS_PDC
    if (p_uart == UART1) p_pdc_base = PDC_UART1;
  #endif
#endif
#if DEVICE_HAS_UART2
  #if UART2_HAS_PDC
    if (p_uart == UART2) p_pdc_base = PDC_UART2;
  #endif
#endif
#if DEVICE_HAS_UART3
  #if UART3_HAS_PDC
    if (p_uart == UART3) p_pdc_base = PDC_UART3;
  #endif
#endif
#if DEVICE_HAS_UART4
  #if UART4_HAS_PDC
    if (p_uart == UART4) p_pdc_base = PDC_UART4;
  #endif
#endif
/* //ERr
#if (SAM3S || SAM3S8 || SAM3N) //ERr SAM3S8
	if (p_uart == UART0)
		p_pdc_base = PDC_UART0;
#elif (SAM3XA || SAM3U || LIMES) //ERr LIMES
	if (p_uart == UART)
		p_pdc_base = PDC_UART;
//ERr SAM4S ////////////////////////////////////////////////////////////////////
#elif (SIRIUS ||SAM4S || SAM4N || CM4P2 || SAM4C || SAM4SH1 || SAMG53) // ERr SAM4N CM4P2 AYi SAM4C
	if (p_uart == UART0)
		p_pdc_base = PDC_UART0;
//ERr SAM4S ////////////////////////////////////////////////////////////////////
#else
#error "Unsupported device"
#endif

#if (SAM3S)
	if (p_uart == UART1)
		p_pdc_base = PDC_UART1;
#endif
*/
	return p_pdc_base;
}
#endif //DEVICE_HAS_PDC
#endif //SAMA5 //ERr SAMA5

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond
