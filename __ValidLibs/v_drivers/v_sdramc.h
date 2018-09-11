
#ifndef _V_SDRAMC_H
#define _V_SDRAMC_H


#include "project.h"

// ---- General purpose include files
#include "device.h"

extern void v_sdram_cs_set(unsigned int CS);
extern void ConfigureSdram(Sdramc * sdram_pt);

#endif // _V_SDRAMC_H