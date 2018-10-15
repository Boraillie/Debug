/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : SAM4C_FEATURES_32C.h
* Object              : ATSAM Definition File.
*
* Creation            : Nov/2012
*----------------------------------------------------------------------------
*/
#ifndef _SAM4C_FEATURES_32E_H
#define _SAM4C_FEATURES_32E_H


//------------------------------------------------------------------------------
// ----      Device Definitions          ----
//-------------------------------------------
#define DEVICE_HAS_EFC1      (1)
#define DEVICE_HAS_PIOD      (1)
#define DEVICE_HAS_UDP       (1)
//#define DEVICE_HAS_TC1      1 // channels 3-5
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// ----        IP Definitions            ----
//-------------------------------------------
//

// ---- ADC ---------------------------------
//#define ADC_CHANNELS    (16)
//-------------------------------------------

// ---- PIO ---------------------------------
#define PIOD_HAS_PDC    (0)
//-------------------------------------------

// ---- TC  ---------------------------------
//#define TC_CHANNELS       (6)
//--------------------------------------------
//#define TC1_BMR_HAS_FILTER  TC_BMR_HAS_FILTER

//...
//-------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
#endif //_SAM4C_FEATURES_32E_H