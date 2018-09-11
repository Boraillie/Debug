/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : 
* Object              : 
*
* Creation            : 
*----------------------------------------------------------------------------
*/
#ifndef _PRG_SETTINGS_H
#define _PRG_SETTINGS_H


// ---- Project settings includes -------------------------------------------
#include "project.h"
#include "device.h"
//#include "board.h"


// -- PRG memory mapping definition -------------------------------------------
#include "prg_mode\prg_memory_map.h"

// -- Communication link abstraction level ------------------------------------
// ERr: following definitions were moved to project.h
//#define SERIAL_COM_LINK_USED  SSPI // SSPI, UART, USART
//#define SERIAL_COM_LINK_IDX   0    // 0, 1, 2...
#include "serial_com_link.h"
// ----------------------------------------------------------------------------



// -- PRG product dependant definitions ---------------------------------------
#if (CAPELLA==1)
  #include "products_settings/prg_settings_65108.h"
#elif (CANOPUS==1)
  #include "products_settings/prg_settings_65103.h"
//#elif (SAM3S==1)
//#elif (SAM3S8==1)
//#elif (SAM3XA==1)
//#elif (SAM4S==1)
//#elif (SAM4N==1)
//#elif (CM4P2==1)
//#elif (ISLERO==1)
#elif (SAMA5D2==1)
  #include "products_settings/prg_settings_92U03.h"
#elif (SAM9X6==1)
  #include "products_settings/prg_settings_SAM9X6.h"
//#elif (SAM4C==1)
//#elif (SIRIUS==1)
//#elif (SAM4SH1==1)
//#elif (SAMG53==1)
//#elif (SAMG55==1)
//#elif (LIMES==1)
#elif (SAMA5D2==1)
  #include "products_settings/prg_settings_92U03.h"
#else
  #error PRG library does not support the specified device.
#endif
//------------------------------------------------------------------------------



#endif //_PRG_SETTINGS_H

