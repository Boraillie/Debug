/*! \file *********************************************************************
 *
 * \brief PMC driver for PMC2 (Starting from SAM9X6).
 *
 * Power Management Controller (PMC) driver module for Microchi MPUs.
 *
 * - Compiler:           IAR EWARM and GNU.
 * - Supported devices:  SAM9X6.
 * - AppNote:
 *
 ******************************************************************************/

#ifndef _V_PMC_V2_H
#define _V_PMC_V2_H

#include "project.h"

// ---- General purpose include files
#include "device.h"
#include "drivers\peripherals\sp_pmc.h" //softpack path to change to be more explicit 


void v2_pmc_switch_mck_to_mainck(void);




#endif // _V_PMC_V2_H

