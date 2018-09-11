/*! \file *********************************************************************
For ASF libs compliance
*******************************************************************************/

#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include "project.h"


/* Default empty handler */
extern void Dummy_Handler( void ) ;
//------------------------------------------------------------------------------
#if (SAM3S==1 || SAM3S8==1)
  #include "Exceptions/SAM3S_Exceptions.h"
#elif (SAM4S==1)
  #include "Exceptions/SAM3S_Exceptions.h" // identical to SAM3S
#elif (SAM4N==1)
  #include "Exceptions/SAM3S_Exceptions.h" // identical to SAM3S
#elif (CM4P2==1)
  #include "Exceptions/CM4P2_Exceptions.h" // identical to SAM3S
#elif (SAMA5==1)
  #if (ISLERO==1)
    #include "Exceptions/ISLERO_Exceptions.h"
  #elif (SAMA5D2==1)
    #include "Exceptions/SAMA5D2_Exceptions.h"
  #else
    #include "Exceptions/SAMA5_Exceptions.h"
  #endif
#elif (SAM4C==1)
  #include "Exceptions/SAM4C_Exceptions.h" 
#elif (SAM4SH1==1)
  #include "Exceptions/SAM4SH1_Exceptions.h" 
#elif (SIRIUS==1)
  #include "Exceptions/SAM3S_Exceptions.h" 
#elif (LIMES==1)
  //#include "Exceptions/LIMES_Exceptions.h" //ERr: covered by iSOCK headers
#elif (SAMG53==1)
  //#include "Exceptions/SAMG53_Exceptions.h" //ERr: covered by iSOCK headers
#elif (SAMG55==1) 
  //ERr: covered by iSOCK headers
#elif ( CANOPUS == 1) || (CANOPUSB == 1)
  //ERr: covered by iSOCK headers
#elif ( CAPELLA == 1) 
  //ERr: covered by iSOCK headers
#elif (SAM3XA==1)
  //#include "Exceptions/SAM3XA_Exceptions.h" //ERr: covered by iSOCK headers
#elif (SAMA5D2==1) 
  //#include "Exceptions/SAMA5D2_Exceptions.h" //ERr: covered by iSOCK headers
#elif (SAM9X56==1) 
  #include "Exceptions/SAM9X6_Exceptions.h" //MNn
#elif (SAM9X6==1) 
  #include "Exceptions/SAM9X6_Exceptions.h" //MNn

//------------------------------------------------------------------------------
#else
  #error Library does not support the specified device.
#endif



#endif  // __EXCEPTIONS_H
