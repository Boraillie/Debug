/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */


// Base functions extracted from softpack


#include "v_sdramc.h"
/**
 * \brief xxx
 *
 * \param yxy desc

 */
void v_sdram_cs_set(unsigned int CS)
{
  if (CS == 0) SFR->SFR_EBICFG |= (1<<8);   // SDRAMCS0
  if (CS == 1) SFR->SFR_EBICFG |= (1<<9);   // SDRAMCS1
  if (CS == 3) SFR->SFR_EBICFG |= (3<<8);   // SDRAMCS0 & SDRAMCS1
}

void ConfigureSdram(Sdramc * sdram_pt)
{
	volatile uint32_t i;
	volatile uint8_t *pSdram = (uint8_t *) SDRAM_CS_ADDR;

	/* 1. SDRAM features must be set in the configuration register:
	asynchronous timings (TRC, TRAS, etc.), number of columns, rows,
	CAS latency, and the data bus width. */
                
          //\TODO Place SDRAM in headers (Boards section)
	//  SDRAM Type: Alliance AS4C16M16SA-6BIN
#ifdef CAPELLA_TFBGA176_XPLAIN
        sdram_pt->SDRAMC_CR =
		  SDRAMC_CR_NC_COL8      // 8 column bits
		| SDRAMC_CR_NR_ROW12     // 12 row bits (4K)
		| SDRAMC_CR_CAS_LATENCY3 // CAS Latency 
		| SDRAMC_CR_NB_BANK4     // banks
		| SDRAMC_CR_DBW          // 16 bits
		| SDRAMC_CR_TWR(5)       // Write Recovery Delay
		| SDRAMC_CR_TRC_TRFC(13) // 63ns   min
		| SDRAMC_CR_TRP(5)       // Command period (PRE to ACT) 21 ns min
		| SDRAMC_CR_TRCD(5)      // Active Command to read/Write Command delay time 21ns min
		| SDRAMC_CR_TRAS(9)      // Command period (ACT to PRE)  42ns min
		| SDRAMC_CR_TXSR(15U);   // Exit self-refresh to active time  70ns Min
#else

        //  SDRAM Type: Alliance AS4C4M16SA-5TCN (PC200)
                    sdram_pt->SDRAMC_CR =
                               SDRAMC_CR_NC_COL8        // 8 column bits
                               | SDRAMC_CR_NR_ROW12     // 12 row bits (8K)
                               | SDRAMC_CR_CAS_LATENCY3 // CAS Latency 3
                               | SDRAMC_CR_NB_BANK4     // 4 banks
                               | SDRAMC_CR_DBW          // 16 bit
                               | SDRAMC_CR_TWR(3)       // 2 write recovery time tCK STEF 
                               | SDRAMC_CR_TRC_TRFC(11)  // 55ns   min STEF
                               | SDRAMC_CR_TRP(3)       // Command period (PRE to ACT) 15 ns min STEF
                               | SDRAMC_CR_TRCD(3)      // Active Command to read/Write Command delay time 15 ns min
                               | SDRAMC_CR_TRAS(9)      // Command period (ACT to PRE)  40ns min STEF
                               | SDRAMC_CR_TXSR(11U);   // Exit self-refresh to active time  75ns Min

     
#endif           
        sdram_pt->SDRAMC_CFR1 |= SDRAMC_CFR1_UNAL;
        
       
	/* 2. For mobile SDRAM, temperature-compensated self refresh (TCSR), drive
	strength (DS) and partial array self refresh (PASR) must be set in the
	Low Power Register. */

	/* 3. The SDRAM memory type must be set in the Memory Device Register.*/
	sdram_pt->SDRAMC_MDR = SDRAMC_MDR_MD_SDRAM;

	/* 4. A minimum pause of 200 ¦Ìs is provided to precede any signal toggle.*/
	for (i = 0; i < 100000; i++);

	/* 5. (1)A NOP command is issued to the SDRAM devices. The application must
	set Mode to 1 in the Mode Register and perform a write access to
	any SDRAM address.*/
	sdram_pt->SDRAMC_MR = SDRAMC_MR_MODE_NOP;
	*pSdram = 0;

	for (i = 0; i < 100000; i++);

	/* 6. An All Banks Precharge command is issued to the SDRAM devices.
	The application must set Mode to 2 in the Mode Register and perform a write
	access to any SDRAM address. */
	sdram_pt->SDRAMC_MR = SDRAMC_MR_MODE_ALLBANKS_PRECHARGE;
	*pSdram = 0;

	for (i = 0; i < 100000; i++);

	/* 7. Eight auto-refresh (CBR) cycles are provided. The application must
	set the Mode to 4 in the Mode Register and perform a write access to any
	SDRAM location eight times.*/
	for (i = 0; i < 8; i++) {
		sdram_pt->SDRAMC_MR = SDRAMC_MR_MODE_AUTO_REFRESH;
		*pSdram = 0;
	}

	for (i = 0; i < 100000; i++);

	/*8. A Mode Register set (MRS) cycle is issued to program the parameters of
	the SDRAM devices, in particular CAS latency and burst length. The
	application must set Mode to 3 in the Mode Register and perform a write
	access to the SDRAM. The write address must be chosen so that BA[1:0]
	are set to 0. For example, with a 16-bit 128 MB SDRAM (12 rows, 9 columns,
	4 banks) bank address, the SDRAM write access should be done at the address
	0x70000000.*/
	sdram_pt->SDRAMC_MR = SDRAMC_MR_MODE_LOAD_MODEREG;
	*pSdram = 0;

	for (i = 0; i < 100000; i++);

	/*9. For mobile SDRAM initialization, an Extended Mode Register set (EMRS)
	cycle is issued to program the SDRAM parameters (TCSR, PASR, DS). The
	application must set Mode to 5 in the Mode Register and perform a write
	access to the SDRAM. The write address must be chosen so that BA[1] or BA[0]
	are set to 1.
	For example, with a 16-bit 128 MB SDRAM, (12 rows, 9 columns, 4 banks) bank
	address the SDRAM write access should be done at the address 0x70800000 or
	0x70400000. */
	//sdram_pt->SDRAMC_MR = SDRAMC_MR_MODE_EXT_LOAD_MODEREG;
	// *((uint8_t *)(pSdram + SDRAM_BA0)) = 0;

	/* 10. The application must go into Normal Mode, setting Mode to 0 in the
	Mode Register and performing a write access at any location in the SDRAM. */
	sdram_pt->SDRAMC_MR = SDRAMC_MR_MODE_NORMAL;
	*pSdram = 0;

	for (i = 0; i < 100000; i++);

	/* 11. Write the refresh rate into the count field in the sdram_pt Refresh
	Timer register. (Refresh rate = delay between refresh cycles).
	The SDRAM device requires a refresh every 15.625 ¦Ìs or 7.81 ¦Ìs.
	With a 100 MHz frequency, the Refresh Timer Counter Register must be set
	with the value 1562(15.625 ¦Ìs x 100 MHz) or 781(7.81 ¦Ìs x 100 MHz). */
	// For IS42S16100E, 2048 refresh cycle every 32ms, every 15.625 ¦Ìs
	/* ((32 x 10(^-3))/2048) x150 x (10^6) */
	//sdram_pt->SDRAMC_TR = 1562;  // test
	sdram_pt->SDRAMC_TR = 1562;  // 100MHz
        //sdram_pt->SDRAMC_TR = 390; // 25MHz
	
	/* After initialization, the SDRAM devices are fully functional. */
}