

/*! \file *********************************************************************
 *
 * \brief systick demodriver for SAM3.
 *
 * Power Management Controller (PMC) driver module for SAM MCUs.
 *
 * - Compiler:           IAR EWARM and GNU GCC for SAM.
 * - Supported devices:  All SAM devices.
 * - AppNote:
 *
 ******************************************************************************/

#include "v_test_sys.h"

extern uint32_t MCK_clock_speed;

/**
 * \brief toogle output level on all the PIOs defined in the given Pin instance.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will memorize the value they are changed to outputs.
 *
 * \param pin  Pointer to a Pin instance describing one or more pins.
 */


void v_systick_init(void)
{
        float one_ms = (1.0/1000);
        float reload_value = (MCK_clock_speed*one_ms)-1;
        //print systick every msecond
        if (SysTick_Config((uint32_t)reload_value))
        {
                printf("SysTick init error");
                while(1);
        }
}
         
         
         
         
         
         
         
         
void SysTick_Handler(void) {
    static uint32_t tick   = 0;
    static uint8_t second = 0;
    static uint8_t minute = 0;
    static uint8_t hour = 0;
    
    switch (tick++) {
      case 0:
            // task 0 here
            break;
      case 1:
            // task 1 here
            break;
            
      case 999:
            tick = 0;
            second = (second < 59) ? (second + 1) : 0;
            minute = (second == 0) ? ((minute < 59) ? (minute + 1) : 0) : minute;
            hour = ((second == 0) && (minute == 0)) ? ((hour < 23) ? (hour + 1) : 0) : hour;
            printf("%d:%d:%d \r",hour,minute,second);
            break;  
    }
}