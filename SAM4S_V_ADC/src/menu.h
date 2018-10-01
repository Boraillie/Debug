/*-----------------------------------------------------------------------------
 *           ATMEL Microcontroller Software Support  -  ROUSSET  -
 *-----------------------------------------------------------------------------
 * DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *----------------------------------------------------------------------------
 * File Name           : menu.h
 *----------------------------------------------------------------------------
*/
#ifndef _MENU_H
#define _MENU_H

#include "project.h"

// ---- General purpose include files
//#include <stdio.h> //IAR
#include "device.h"
#include "board.h"

// ---- Peripherals (ASF drivers)
#include "drivers/rstc/rstc.h"

// ---- Validation libraries
#include "v_debug.h"
#include "v_utils.h"
#include "v_drivers/v_pio.h"


// -----------------------------------------------------------------------------
//  Chip IDs definitions
// -----------------------------------------------------------------------------
#define CHIP_ID_REGISTER   REG_CHIPID_CIDR
#define CHIP_EXID_REGISTER REG_CHIPID_EXID

#ifdef CHIPID_CIDR
  #define _DEVICE_CHIP_ID_ CHIPID_CIDR
#else
  #error Library does not support the specified device.
#endif


/*
#if defined __SAM4S8B__
  #define _DEVICE_CHIP_ID_
#elif defined __SAM4S8C__
  #define _DEVICE_CHIP_ID_
#elif defined __SAM4S16B__
  #define _DEVICE_CHIP_ID_
#elif defined __SAM4S16C__
  #define _DEVICE_CHIP_ID_ 
#elif defined __SAM4SA16B__
  #define _DEVICE_CHIP_ID_ 
#elif defined __SAM4SA16C__
  #define _DEVICE_CHIP_ID_ 
#elif defined __SAM4SD16B__
  #define _DEVICE_CHIP_ID_ 
#elif defined __SAM4SD16C__
  #define _DEVICE_CHIP_ID_ 
#elif defined __SAM4SD32B__
  #define _DEVICE_CHIP_ID_ 
#elif defined __SAM4SD32C__
  #define _DEVICE_CHIP_ID_ 
#else
  #error Library does not support the specified device.
#endif
*/
// -----------------------------------------------------------------------------


//static void menu(char val);
void Print_menu(void);
void run_menu(void);
void get_and_check_chipid(uint32_t* chip_id, uint32_t* chip_exid);

#endif //_MENU_H