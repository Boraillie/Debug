/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : iflash_info.h
* Object              : ATSAM Definition File.
*
* Creation            : Oct/2011
*----------------------------------------------------------------------------
*/
#ifndef _IFLASH_INFO_H
#define _IFLASH_INFO_H


// ERr added Flash structure relative parameters -------------------------------
#if (SAM4S || SAM4N || CM4P2 || SAM4C)
  #define SMALL_SECTORS_NUMBER    (2)
  #define SMALL_SECTOR_NB_PAGES  (16)
  #define LARGER_SECTOR_NB_PAGES (NB_PAGES_PER_SECTOR-(SMALL_SECTORS_NUMBER*SMALL_SECTOR_NB_PAGES))
#endif


//---- SAM3S -------------------------------------------------------------------
#if (SAM3S1 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3S2 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3S4 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3S8 == 1)
  #define IFLASH_NB_PLANES (1u)
#elif (SAM3SD8 == 1)
  #define IFLASH_NB_PLANES (1u)
//---- SAM3X/A -----------------------------------------------------------------
#elif defined __SAM3X8E__
  #define IFLASH_NB_PLANES (2u)
#elif defined __SAM3X8C__
  #define IFLASH_NB_PLANES (2u)
#elif defined __SAM3X4E__
  #define IFLASH_NB_PLANES (2u)
#elif defined __SAM3X4C__
  #define IFLASH_NB_PLANES (2u)
#elif defined __SAM3A8C__
  #define IFLASH_NB_PLANES (2u)
#elif defined __SAM3A4C__
  #define IFLASH_NB_PLANES (2u)
//---- SAM4S -------------------------------------------------------------------
#elif (SAM4S2 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4S4 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4S8 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4S16 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4SA16 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4SD16 == 1)
  #define IFLASH_NB_PLANES        (2u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
  #define IFLASH1_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4SD32 == 1)
  #define IFLASH_NB_PLANES        (2u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
  #define IFLASH1_SECTOR_SIZE     (65536) //ERr added

#elif (SIRIUS == 1)
  #define IFLASH_NB_PLANES        (2u)
  #define IFLASH0_SECTOR_SIZE     (2*65536) //cjn added
  #define IFLASH1_SECTOR_SIZE     (2*65536) //cjn added


//---- SAM4N -------------------------------------------------------------------
#elif (SAM4N8 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
#elif (SAM4N16 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
//---- CM4P2 -------------------------------------------------------------------
#elif (CM4P2 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //ERr added
//---- SAM4C -------------------------------------------------------------------
#elif (SAM4C == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //AYi added
//---- SAM4SH1 -----------------------------------------------------------------
#elif (SAM4SH1 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536) //AYi added
//---- SAMG53 ------------------------------------------------------------------
#elif (SAMG53 == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536)
//---- SAMG55 ------------------------------------------------------------------
#elif (SAMG55 == 1)
// IFLASH INF O are in header files by default
//  #define IFLASH_NB_PLANES        (1u)
//  #define IFLASH0_SECTOR_SIZE     (65536)
//---- SAMG55 ------------------------------------------------------------------
#elif (CANOPUS == 1) || (CANOPUSB == 1)
// IFLASH INF O are in header files by default
//  #define IFLASH_NB_PLANES        (1u)
//  #define IFLASH0_SECTOR_SIZE     (65536)
#elif (CAPELLA == 1)
// IFLASH INFO are in header files by default
  //#define IFLASH_NB_PLANES        (1u)
  //#define IFLASH0_SECTOR_SIZE     (131072)
//---- LIMES -------------------------------------------------------------------
#elif (LIMES == 1)
  #define IFLASH_NB_PLANES        (1u)
  #define IFLASH0_SECTOR_SIZE     (65536)


//------------------------------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif



#endif //_IFLASH_INFO_H
