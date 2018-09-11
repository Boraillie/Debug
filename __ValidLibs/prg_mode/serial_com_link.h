/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : serial_com_link.h
* Object              : wrapper between monitor and communication driver
*
* Creation            : ERr / Feb 2015
*----------------------------------------------------------------------------
*/
#ifndef _SERIAL_COM_LINK_H
#define _SERIAL_COM_LINK_H


#include "project.h"



#define SERIAL_COM_LINK_TYPE         MERGE(TYPE_              ,SERIAL_COM_LINK_USED         ,                       ,       )
//#define ID_SERIAL_COM_LINK                (MERGE(ID_               , SERIAL_COM_LINK_USED        , SERIAL_COM_LINK_IDX     ,       ))

//#define COM_LINK_RESET {rx_full = 0; tx_empty = 1;}

// ----------------------------------------------------------------------------
// -- Communication link abstraction level ------------------------------------
// ----------------------------------------------------------------------------
#if (SERIAL_COM_LINK_TYPE == TYPE_SSPI) // SSPI: SW emualted SPI (PIO) or HW SPI if available
  #define SSPI_WRAPPER_SPI_IDX SERIAL_COM_LINK_IDX // can be <void>, 0, 1... comment out for pure software SSPI
  #include "sspi.h"
  #define COM_LINK_RESET    {sspi_init();sspi_reset();}
  #define COM_LINK_ENABLE   sspi_enable()
  #define COM_LINK_DISABLE  sspi_disable()
  #define SET_RX_MODE       sspi_set_mode(SSPI_MODE_RECEIVE)
  #define SET_TX_MODE       sspi_set_mode(SSPI_MODE_TRANSMIT)
  #define RX_CHAR           sspi_read_rdr()   //rx_char
  #define TX_CHAR(c)        sspi_write_tdr(c) //tx_char 
  #define RX_FULL           sspi_is_rdr_full()
  #define TX_EMPTY          sspi_is_tdr_empty()
  //#define COM_LINK_HANDLER  MERGE(SERIAL_COM_LINK_PERIPH,HANDLER_SUFFIX,,)
  //#define COM_LINK_HANDLER  MERGE(SPI,SSPI_WRAPPER_SPI_IDX,HANDLER_SUFFIX,)
//-----------------------------------------------------------------------------
#elif (SERIAL_COM_LINK_TYPE == TYPE_UART)
// UART: for engineering on application board only (not supported on tester)
#warning NOT SUPPORTED: SERIAL_COM_LINK_TYPE == TYPE_UART
  #warning Asynchronous communication not supported on tester ! Do not use this code for production !!!
  #include "v_drivers/v_uart.h"
  #define COM_LINK_RESET 
  #define COM_LINK_ENABLE
  #define COM_LINK_DISABLE
  #define SET_RX_MODE
  #define SET_TX_MODE
  #define RX_CHAR
  #define TX_CHAR
  #define RX_FULL
  #define TX_EMPTY
  #define COM_LINK_HANDLER 
//-----------------------------------------------------------------------------
#elif (SERIAL_COM_LINK_TYPE == TYPE_USART)
// UART: for engineering on application board only (not supported on tester)
#warning NOT SUPPORTED 
  #warning Asynchronous communication not supported on tester ! Do not use this code for production !!!
  #include "v_drivers/v_usart.h"
  #define COM_LINK_RESET
  #define COM_LINK_ENABLE
  #define COM_LINK_DISABLE
  #define SET_RX_MODE
  #define SET_TX_MODE
  #define RX_CHAR
  #define TX_CHAR
  #define RX_FULL
  #define TX_EMPTY
  #define COM_LINK_HANDLER 
//-----------------------------------------------------------------------------
#else
// Not supported
  #error Communication link type not supported
#endif
// ----------------------------------------------------------------------------


#endif //_SERIAL_COM_LINK_H

