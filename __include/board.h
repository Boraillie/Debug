/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : Board.h
* Object              : ATSAM Definition File.
*
* Creation            : 
*----------------------------------------------------------------------------
*/
#ifndef _BOARD_H
#define _BOARD_H


///////////////// PROBE CARDS ///////////////////////////////////////////////
#ifdef _65103_PROBE_CARD_REV_A
  #include "Boards/ProbeCards/_65103_PROBE_CARD.h" // CANOPUS 65103
#elif defined CAPELLA_TESTPROD
  #include "Boards/CAPELLA_TESTPROD.h" // CAPELLA 65108
///////////////// APPLICATION BOARDS ////////////////////////////////////////
//---- SAM3S / SAM4S / SAM7S ------------------------------------------------
#elif defined SAM4S_XPLAINED
  #include "Boards/SAM4S_XPlained.h"
#elif defined SAM4S_EK_REVB
  #include "Boards/SAM4S_EK.h"
#elif defined SAM4S_XPLAINED_PRO
  #include "Boards/SAM4S_XPLAINED_PRO.h"
#elif defined SAM4S_VB_QFN64_LQFP64_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM4S_VB_SCH_BGA100_LQFP100_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM4S_VB_QFP48_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM4S_VB_QFN48_REVA
  #include "Boards/SAM4S_VB.h"
#elif defined SAM3S_VB_BGA100_LQFP100_REVB
  #include "Boards/SAM3S_VB.h"
#elif defined POE09_785_001
  #include "Boards/SAM4S_HTB.h"
#elif defined TEMP_63904_BIB_REF
  #include "Boards/SAM4S_QFP100_HTB.h"
#elif defined _63907_ADD1022_BIB_QFP128_REV_A // ATPL242/SAM4SP32
  #include "Boards/SAM4SP32_QFP128_HTB.h"
//---- SAM3X ----------------------------------------------------------------
#elif defined SAM3X_VB_BGA144_LQFP144_REVA
  #include "Boards/SAM3X_VB_BGA144_LQFP144.h"
#elif defined _58Z68_BIB_LQ144_REVA
  #include "Boards/SAM3X_BIB_LQ144.h"
//---- SAMA5 ----------------------------------------------------------------
#elif defined SAMA5_VB_BGA324_REVA
  #include "Boards/SAMA5_VB.h"
#elif defined SAMA5_BIB_BGA324
  #include "Boards/SAMA5_BIB.h"
//---------------------------------------------------------------------------
//---- CM4P2 ----------------------------------------------------------------
#elif defined CM4P2_VB_REVA
  #include "Boards/CM4P2_BGA144_VB.h"
#elif defined _63908_BIB_BGA144_REV_A
  #include "Boards/CM4P2_BIB.h"
//---- SAM4C ------------------------------------------------
#elif defined SAM4C_VB_LQFP100_REVA  
  #include "Boards/SAM4C_VB_V_Area.h"
#elif defined _63905_BIB_QFP100_REV_A
  #include "Boards/SAM4C_QFP100_BIB.h"
#elif defined SAM4C_VB_LQFP144_REVA  // ERr -> rename to SAM4C32_VB_LQFP144_REVA
  #include "Boards/SAM4C32_VB_V_Area.h"
#elif defined SAM4C32_VB_LQFP144_REVA  // ERr -> rename to SAM4C32_VB_LQFP144_REVA
  #include "Boards/SAM4C32_VB_V_Area.h"
#elif defined _63915_BIB_QFP144_REV_A
  #include "Boards/SAM4C32_QFP144_BIB.h"
//---- SAM4CM -----------------------------------------------
#elif defined SAM4CM_VB_LQFP100_REVA  
  #include "Boards/SAM4CM_VB_V_Area.h" //??? ERr
#elif defined _63905_56H30_BIB_QFP100_REV_A
  #include "Boards/SAM4CM_QFP100_BIB.h"
//---- SAM4SH1 ------------------------------------------------
#elif defined SAM4SH1_VB_SCH_BGA100_LQFP100_REVA  
  #include "Boards/SAM4SH1_VB_V_Area.h"
#elif defined _63917_BIB_QFP100_REV_A
  #include "Boards/SAM4SH1_QFP100_BIB.h"
//---- SAMG55 ------------------------------------------------
#elif defined SAMG55_VB_SCH_BGA100_QFN64_LQFP64_REVA  
  #include "Boards/SAMG55_QFN64_LQFP64_VB_REVA_V_Area.h"
#elif defined _65105_BIB_LQ64_REVA  
  #include "Boards/SAMG55_BIB_LQ64.h"
//---- ISLERO ------------------------------------------------
#elif defined ISLERO_VB_BGA361_REVA
  #include "Boards/ISLERO_VB.h"
#elif defined _92A02_BIB_BGA361_REV_A
  #include "Boards/ISLERO_BIB.h"
//---- LIMES ------------------------------------------------
#elif defined LIMES_MB_REVA  
  #include "Boards/LIMES_VB.h"
#elif defined _63913_BIB_BGA96_REV_A
  #include "Boards/LIMES_BIB.h"
//---- CANOPUS ------------------------------------------------
#elif defined CANOPUS_VB_SCH_LQFP144_BGA144_REVA
  #include "Boards/CANOPUS_LQFP144_BGA144_VB_REVA_V_Area.h"
#elif defined  SAMV71_XPLAINED_REV_A
  #include "Boards/SAMV71_XPlained.h"
#elif defined  _65103_BIB_LQ144_REV_A
  #include "Boards/CANOPUS_BIB_LQ144.h"
#elif defined  _65103_EMC_LQ144_REV_A
  #include "Boards/CANOPUS_EMC_LQ144.h"
#elif defined  _65103_EMC_LQ64_REV_A
  #include "Boards/CANOPUS_EMC_LQ64.h"
#elif defined  _65103_DBIC_TFBGA100_X112_REV_A
  #include "Boards/CANOPUS_DBIC_xxx.h"
#elif defined  _65103_DBIC_TFBGA144_X112_REV_A
  #include "Boards/CANOPUS_DBIC_xxx.h"
//---- SAMA5D2 ------------------------------------------------
#elif defined _92U01_BIB_BGA289_REV_A  
  #include "Boards/SAMA5D2_BIB.h"
#elif defined SAMA5D2_VB_REVA  
  #include "Boards/SAMA5D2_VB_BGA289_REVA_V_Area.h"
#elif defined SAMA5D2_CB_REVA  // characterization
  #include "Boards/SAMA5D2_CB_BGA289_REVA.h"
#elif defined SAMA5D2_SOM1_REVA  // SoM
  #include "Boards/SAMA5D2_SOM1_REVA.h"
//---- CAPELLA ------------------------------------------------
#elif defined CAPELLA_TESTPROD
  #include "Boards/CAPELLA_TESTPROD.h" // must be first case for Capella (supersedes other boards in PRG_MODE)
#elif defined CAPELLA_VB_TFBGA176_REVA
  #include "Boards/CAPELLA_TFBGA176_VB_REVA_V_Area.h"
#elif defined CAPELLA_TFBGA176_XPLAIN
  #include "Boards/CAPELLA_TFBGA176_XPLAIN.h"
#elif defined  _TYPHOON_FPGA_BOARD_
  #error Library does not support the specified board.
#elif defined CAPELLA_TFBGA176_EB
  #include "Boards/CAPELLA_TFBGA176_EB.h"
 // #include "Boards/CAPELLA_BIB_TFBGA100.h"
//---------------------------------------------------------------------------

//---- SAM9X6 ------------------------------------------------
#elif defined SAM9X6_BIB_REV_A  
  #include "Boards/SAM9X6_BIB.h"
#elif defined SAM9X6_VB_REVA  
  #include "Boards/SAM9X6_VB_BGA228_REVA_V_Area.h"
#elif defined SAM9X6_FPGA
  #include "Boards/SAM9X6_TYPHOON_FPGA.h"

#else
  #error Library does not support the specified board.
#endif
//---------------------------------------------------------------------------




#endif // _BOARD_H
