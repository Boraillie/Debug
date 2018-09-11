/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : device.h
* Object              : ATSAM Definition File.
*
* Creation            : ERr / Aug 2011
*----------------------------------------------------------------------------
*/
#ifndef _DEVICE_H
#define _DEVICE_H


//---- SAM3S -------------------------------------------------------------------
#if defined __SAM3S1A__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S1 1
#elif defined __SAM3S1B__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S1 1
#elif defined __SAM3S1C__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S1 1
#elif defined __SAM3S2A__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S2 1
#elif defined __SAM3S2B__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S2 1
#elif defined __SAM3S2C__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S2 1
#elif defined __SAM3S4A__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S4 1
#elif defined __SAM3S4B__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S4 1
#elif defined __SAM3S4C__
  #define SAM3 1
  #define SAM3S 1
  #define SAM3S4 1
//---- SAM3S8 ------------------------------------------------------------------
/*
#elif defined __SAM3S8A__
  #define SAM3 1
  #define SAM3S8 1
*/
#elif defined __SAM3S8B__
  #define SAM3 1
  #define SAM3S8 1
#elif defined __SAM3S8C__
  #define SAM3 1
  #define SAM3S8 1
#elif defined __SAM3SD8A__
  #define SAM3 1
  #define SAM3SD8 1
#elif defined __SAM3SD8B__
  #define SAM3 1
  #define SAM3SD8 1
#elif defined __SAM3SD8C__
  #define SAM3 1
  #define SAM3SD8 1
//---- SAM3X/A -----------------------------------------------------------------
#elif defined __SAM3X8E__
  #define SAM3   (1)
  #define SAM3XA (1)
  #define SAM3X  (1)
  #define SAM3X8 (1)
#elif defined __SAM3X8C__
  #define SAM3   (1)
  #define SAM3XA (1)
  #define SAM3X  (1)
  #define SAM3X8 (1)
#elif defined __SAM3X4E__
  #define SAM3   (1)
  #define SAM3XA (1)
  #define SAM3X  (1)
  #define SAM3X4 (1)
#elif defined __SAM3X4C__
  #define SAM3   (1)
  #define SAM3XA (1)
  #define SAM3X  (1)
  #define SAM3X4 (1)
#elif defined __SAM3A8C__
  #define SAM3   (1)
  #define SAM3XA (1)
  #define SAM3A  (1)
  #define SAM3A8 (1)
#elif defined __SAM3A4C__
  #define SAM3   (1)
  #define SAM3XA (1)
  #define SAM3A  (1)
  #define SAM3A4 (1)
//---- SAM4S -------------------------------------------------------------------
#elif defined __SAM4S2A__
  #define SAM4   (1)
  #define SAM4S  (1)
  #define SAM4S2 (1)
#elif defined __SAM4S2B__
  #define SAM4   (1)
  #define SAM4S  (1)
  #define SAM4S2 (1)
#elif defined __SAM4S2C__
  #define SAM4   (1)
  #define SAM4S  (1)
  #define SAM4S2 (1)
#elif defined __SAM4S4A__
  #define SAM4   (1)
  #define SAM4S  (1)
  #define SAM4S4 (1)
#elif defined __SAM4S4B__
  #define SAM4   (1)
  #define SAM4S  (1)
  #define SAM4S4 (1)
#elif defined __SAM4S4C__
  #define SAM4   (1)
  #define SAM4S  (1)
  #define SAM4S4 (1)
#elif defined __SAM4S8B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S8 1
#elif defined __SAM4S8C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S8 1
#elif defined __SAM4S16B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S16 1
#elif defined __SAM4S16C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4S16 1
#elif defined __SAM4SA16B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SA16 1
#elif defined __SAM4SA16C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SA16 1
#elif defined __SAM4SD16B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD16 1
#elif defined __SAM4SD16C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD16 1
#elif defined __SAM4SD32B__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD32 1
#elif defined __SAM4SD32C__
  #define SAM4 1
  #define SAM4S 1
  #define SAM4SD32 1
#elif defined __SIRIUS__
  #define SIRIUS 1
 // #define SAM4S 1
 // #define SAM4SD64 1
//---- SAM4N -------------------------------------------------------------------
#elif defined __SAM4N8A__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N8 1
#elif defined __SAM4N8B__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N8 1
#elif defined __SAM4N8C__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N8 1
#elif defined __SAM4N16B__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N16 1
#elif defined __SAM4N16C__
  #define SAM4 1
  #define SAM4N 1
  #define SAM4N16 1
//---- SAMA5 -------------------------------------------------------------------
#elif defined __SAMA5D31__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D31 1
#elif defined __SAMA5D33__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D33 1
#elif defined __SAMA5D34__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D34 1
#elif defined __SAMA5D35__
  #define SAMA5 1
  #define SAMA5D 1
  #define SAMA5D35 1
//---- ISLERO -------------------------------------------------------------------
#elif defined __ISLERO__
  #define SAMA5 1
  #define ISLERO 1

//---- CM4P2 -------------------------------------------------------------------
//#elif defined __CM4P2B__
//  #define CM4P2 1
//  #define CM4P2B 1
#elif defined __CM4P2E__
  #define CM4P2 1
  #define CM4P2E 1
//---- SAM4C /SAM4CM -----------------------------------------------------------
/*
#elif defined __SAM4CMS32E__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C32 1
#elif defined __SAM4CMP32E__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C32 1
*/
#elif defined __SAM4CMS32C__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C32 1
#elif defined __SAM4CMP32C__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C32 1
#elif defined __SAM4C32E__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C32 1
#elif defined __SAM4C32C__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C32 1
#elif defined __SAM4C16C__
  #define SAM4 1
  #define SAM4C 1
  #define SAM4C16 1
#elif defined __SAM4C8C__
  #define SAM4 		1
  #define SAM4C 	1
  #define SAM4C8 	1
#elif defined __SAM4CMP16C__
  #define SAM4 		1
  #define SAM4CMP 	1
  #define SAM4CMP16 	1
#elif defined __SAM4CMP8C__
  #define SAM4 		1
  #define SAM4CMP 	1
  #define SAM4CMP8 	1
#elif defined __SAM4CMS16C__
  #define SAM4 		1
  #define SAM4CMS 	1
  #define SAM4CMS16 	1
#elif defined __SAM4CMS8C__
  #define SAM4 		1
  #define SAM4CMS 	1
  #define SAM4CMS8 	1
#elif defined __SAM4MP16C__
  #define SAM4 		1
  #define SAM4MP 	1
  #define SAM4MP16 	1
#elif defined __SAM4MP8C__
  #define SAM4 		1
  #define SAM4MP 	1
  #define SAM4MP8 	1
#elif defined __SAM4MS16C__
  #define SAM4 		1
  #define SAM4MS 	1
  #define SAM4MS16 	1
#elif defined __SAM4MS8C__
  #define SAM4 		1
  #define SAM4MS 	1
  #define SAM4MS8 	1
//---- SAM4SH1 -----------------------------------------------------------------
#elif defined __SAM4SH1__
  #define SAM4    (1)
  #define SAM4SH  (1)
  #define SAM4SH1 (1)
//---- SAMG53 ------------------------------------------------------------------
#elif defined __SAMG53__
  #define SAM4    (1)
  #define SAM4SH  (1)
//#define SAM4SH2 1
  #define SAMG53  (1)
//---- SAMG55 -----------------------------------------------------------------
#elif defined __SAMG55G18__
  #define SAM4    (1)
  #define SAM4SH  (1)
  #define SAMG55  (1)
#elif defined __SAMG55G19__
  #define SAM4    (1)
  #define SAM4SH  (1)
  #define SAMG55  (1)
#elif defined __SAMG55J18__
  #define SAM4    (1)
  #define SAM4SH  (1)
  #define SAMG55  (1)
#elif defined __SAMG55J19__
  #define SAM4    (1)
  #define SAM4SH  (1)
  #define SAMG55  (1)
#elif defined __SAMG55N19__
  #define SAM4    (1)
  #define SAM4SH  (1)
  #define SAMG55  (1)
//---- SAM4SH1 -----------------------------------------------------------------
#elif defined __LIMES__
  #define LIMES (1)
  #define SAM4  (1)

//---- CANOPUS -----------------------------------------------------------------
#elif    defined __SAMV71Q21__ || defined __SAMV71Q20__|| defined __SAMV71Q19__\
      || defined __SAMV71N21__ || defined __SAMV71N20__|| defined __SAMV71N19__\
      || defined __SAMV71J21__ || defined __SAMV71J20__|| defined __SAMV71J19__
   #define CANOPUS (1)
   #define SAMV71  (1)
#elif    defined __SAMV70Q20__ || defined __SAMV70Q19__|| defined __SAMV70N20__\
      || defined __SAMV70N19__ || defined __SAMV70J20__|| defined __SAMV70J19__
   #define CANOPUS (1)
   #define SAMV70  (1)
#elif    defined __SAMS70Q21__ || defined __SAMS70Q20__|| defined __SAMS70Q19__\
      || defined __SAMS70N21__ || defined __SAMS70N20__|| defined __SAMS70N19__\
      || defined __SAMS70J21__ || defined __SAMS70J20__|| defined __SAMS70J19__
   #define CANOPUS (1)
   #define SAMS70  (1)
#elif    defined __SAME70Q21__ || defined __SAME70Q20__|| defined __SAME70Q19__\
      || defined __SAME70N21__ || defined __SAME70N20__|| defined __SAME70N19__\
      || defined __SAME70J21__ || defined __SAME70J20__|| defined __SAME70J19__
   #define CANOPUS (1)
   #define SAME70  (1)
        
//---- CANOPUSB ----------------------------------------------------------------
#elif    defined __SAMV71Q21B__ || defined __SAMV71Q20B__|| defined __SAMV71Q19B__\
      || defined __SAMV71N21B__ || defined __SAMV71N20B__|| defined __SAMV71N19B__\
      || defined __SAMV71J21B__ || defined __SAMV71J20B__|| defined __SAMV71J19B__
  #define CANOPUS  (1)
  #define CANOPUSB (1)
  #define SAMV71B  (1)
#elif    defined __SAMV70Q20B__ || defined __SAMV70Q19B__\
      || defined __SAMV70N20B__ || defined __SAMV70N19B__\
      || defined __SAMV70J20B__ || defined __SAMV70J19B__
  #define CANOPUS  (1)
  #define CANOPUSB (1)
  #define SAMV70B  (1)
#elif    defined __SAMS70Q21B__ || defined __SAMS70Q20B__|| defined __SAMS70Q19B__\
      || defined __SAMS70N21B__ || defined __SAMS70N20B__|| defined __SAMS70N19B__\
      || defined __SAMS70J21B__ || defined __SAMS70J20B__|| defined __SAMS70J19B__
  #define CANOPUS  (1)
  #define CANOPUSB (1)
  #define SAMS70B  (1)
#elif    defined __SAME70Q21B__ || defined __SAME70Q20B__|| defined __SAME70Q19B__\
      || defined __SAME70N21B__ || defined __SAME70N20B__|| defined __SAME70N19B__\
      || defined __SAME70J21B__ || defined __SAME70J20B__|| defined __SAME70J19B__
  #define CANOPUS  (1)
  #define CANOPUSB (1)
  #define SAME70B  (1)
//---- CAPELLA -----------------------------------------------------------------
#elif defined __SAMU70N20__ || defined __SAMU70N20__ || defined __SAMU70N20__\
	     || defined __SAMU70Q20__ || defined __SAMU70Q20__ || defined __SAMU70Q20__\
	     || defined __SAMU70S20__ || defined __SAMU70S20__ || defined __SAMU70N19__\
	     || defined __SAMU70N19__ || defined __SAMU70N19__ || defined __SAMU70Q19__\
	     || defined __SAMU70Q19__ || defined __SAMU70Q19__ || defined __SAMU70S19__\
	     || defined __SAMU70S19__ || defined __SAMV72N19__ || defined __SAMV72N20__\
	     || defined __SAMV72Q20__ || defined __SAMV72N20__ || defined __SAMV72Q19__\
	     || defined __SAMV72N19__ || defined __SAMV72Q19__ || defined __SAMV72Q20__
#define CAPELLA (1)
                      
//---- SAMA5D2 -----------------------------------------------------------------
#elif defined __SAMA5D21__ || defined __SAMA5D22_|| defined __SAMA5D23__\
   || defined __SAMA5D24__|| defined __SAMA5D26__|| defined __SAMA5D27__\
   || defined __SAMA5D28__
  #define SAMA5   (1)
  #define SAMA5D  (1)
  #define SAMA5D2 (1)

//---- SAM9X6 -----------------------------------------------------------------
#elif defined __SAM9X56__ || defined __SAM9X56D0M__ || defined __SAM9X56D5M__\
	     || defined __SAM9X56D1G__
#define SAM9X6 (1)





//---- Not implemented ---------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//---- SOC headers include
//------------------------------------------------------------------------------
#if (SAM3S==1)
  #include "Devices/SAM3S/split/SAM3S.h"
  #include "SOC_Patches/valid_patch_SAM3S.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM3S8==1)
  //#include "Devices/SAM3S8/header/SAM3S8.h"
  #include "Devices/SAM3S8/include/SAM3S8.h"
  #include "SOC_Patches/valid_patch_SAM3S8.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM3XA==1)
  #include "Devices/SAM3XA/include/SAM3XA.h"
  #include "SOC_Patches/valid_patch_SAM3XA.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM4S==1)
  #include "Devices/SAM4S/split/SAM4S.h"
  #include "SOC_Patches/valid_patch_SAM4S.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAM4N==1)
  #define DONT_USE_CMSIS_INIT //ERr
  #include "Devices/SAM4N/split/SAM4N.h"
  #include "SOC_Patches/valid_patch_SAM4N.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (CM4P2==1)
  #define DONT_USE_CMSIS_INIT //ERr
  #include "Devices/CM4P2/split/CM4P2.h"
  #include "SOC_Patches/valid_patch_CM4P2.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAMA5==1)  
  #if (ISLERO==1)
    #include "Devices\ISLERO\SAMA5D4.h"
    #include "SOC_Patches/valid_patch_ISLERO.h"    
  #elif (SAMA5D2==1)
      //#warning temporary defines
      #define   __I  volatile const ///< Defines 'read-only'  permissions
      #define   __O  volatile       ///< Defines 'write-only' permissions
      #define   __IO volatile       ///< Defines 'read/write' permissions
    #include "Devices\SAMA5D2\include\sama5d2.h"
    #include "SOC_Patches/valid_patch_SAMA5D2.h"    
    #include "../__ValidLibs/v_drivers/v_flexcom_wrapper.h"
  #else
    #include "Devices/SAMA5/include/SAMA5.h"
    #include "SOC_Patches/valid_patch_SAMA5.h"
  #endif
#elif (SAM4C==1)
  #if (SAM4C_C0==1)
    #include "Devices/SAM4C/SAM4C-0.h"
    #include "SOC_Patches/valid_patch_SAM4C.h"
    #include "Devices/iflash_info.h" // Embedded Flash definitions
  #elif (SAM4C_C1==1)
    #include "Devices/SAM4C/SAM4C-1.h"
    #include "SOC_Patches/valid_patch_SAM4C.h"
    #include "Devices/iflash_info.h" // Embedded Flash definitions
  #else
    #error CORE not specified.  
  #endif
#elif (SAM4SH1==1)
  #define DONT_USE_CMSIS_INIT 
  #include "Devices/SAM4SH1/split/sam4sh.h"
  #include "SOC_Patches/valid_patch_SAM4SH1.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SIRIUS==1)
  #include "Devices/SIRIUS/split/sam4sd64c.h"
  #include "SOC_Patches/valid_patch_SIRIUS.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
/*
#elif (SAM4SH1==1)
  #define DONT_USE_CMSIS_INIT 
  #include "Devices/SAM4SH1/split/sam4sh.h"
  #include "SOC_Patches/valid_patch_SAM4SH1.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
*/
#elif (SAMG53==1)
  #define DONT_USE_CMSIS_INIT 
  #include "Devices/SAMG53/split/SAMG53.h"
  #include "SOC_Patches/valid_patch_SAMG53.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (SAMG55==1)
  #define DONT_USE_CMSIS_INIT 
  #include "Devices/SAMG55/split/SAMG55.h"
  #include "SOC_Patches/valid_patch_SAMG55.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (LIMES==1)
  #define DONT_USE_CMSIS_INIT 
  #include "Devices/LIMES/split/LIMES.h"
  #include "SOC_Patches/valid_patch_LIMES.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions
#elif (CANOPUS==1)
  #define DONT_USE_CMSIS_INIT 
  //#include "Devices/CANOPUS/split/canopus.h"
  #include "Devices/CANOPUS/canopus.h"
  #include "SOC_Patches/valid_patch_CANOPUS.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions	
#elif (CANOPUSB==1)
  #define DONT_USE_CMSIS_INIT 
  //#include "Devices/CANOPUS/split/canopus.h"
  #include "Devices/CANOPUS/canopus.h"
  #include "SOC_Patches/valid_patch_CANOPUS.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions	
#elif (CAPELLA==1)
  #define DONT_USE_CMSIS_INIT 
  //#include "Devices/CAPELLA/split/capella.h"
  #include "Devices/CAPELLA/capella.h"
  #include "SOC_Patches/valid_patch_CAPELLA.h"
  #include "../__ValidLibs/v_drivers/v_flexcom_wrapper.h"
  #include "Devices/iflash_info.h" // Embedded Flash definitions	
/*added by MNn*/
#elif (SAM9X6==1)
      //#warning temporary defines
      #define   __I  volatile const ///< Defines 'read-only'  permissions
      #define   __O  volatile       ///< Defines 'write-only' permissions
      #define   __IO volatile       ///< Defines 'read/write' permissions
    #include "Devices\SAM9X6\include\sam9x.h"
    #include "SOC_Patches/valid_patch_SAM9X6.h"    
    #include "../__ValidLibs/v_drivers/v_flexcom_wrapper.h"

#else
  #error Library does not support the specified device.
#endif
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//---- Additional informations (not included in SOC deliverables)
//------------------------------------------------------------------------------
#include "Devices/packages.h" // Keys values
//#include "Devices/keys.h" // ERr (moved in device features file)
//------------------------------------------------------------------------------


#endif /* _DEVICE_H */
