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
 * File Name           : menu.c
 *----------------------------------------------------------------------------
*/

#include "menu.h"




// global variables
char message[80];
unsigned int MenuChoice;
extern unsigned int MCK_clock_speed;       // main.c
extern const char reset_source_msg[7][10]; // v_utils.c



// -----------------------------------------------------------------------------
#define MENU_NB_OPTIONS     4 // max=10
#define MENU_STRING_LENGTH 50
char menu_choice_msg[MENU_NB_OPTIONS][MENU_STRING_LENGTH]={\
//                          "====================MAXLENGTH====================
                            " 0 -> Perform a Software Reset  \n\r",\
                            " 1 -> Turn off D0 LED \n\r",\
                            " 2 -> Turn on D0 LED   \n\r",\
                            " 3 -> Get SW0 state \n\r",\
                            " 4 -> Start Sleep mode \n\r",\  
                            " 5 -> Start Wait mode \n\r"};

//                          "====================MAXLENGTH====================
// -----------------------------------------------------------------------------
//  Function Name       : menu_option_xx
//  Object              : menu option routines
// -----------------------------------------------------------------------------

void menu_option_0(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Performing a Software Reset ==\n\r");
  rstc_software_reset(RSTC,RSTC_PROCRST) ;
  //DEBUG_Printk("  =========== Press a key ===============\n\r");
}
void menu_option_1(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Turning off LEDs D0 =======\n\r");
  BRD_TURN_OFF_D0;
  DEBUG_Printk("\n\r");
  DEBUG_Printk("  =========== Press a key ===============\n\r");
}
void menu_option_2(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Turning on LEDs D0 ========\n\r");
  BRD_TURN_ON_D0;
  DEBUG_Printk("\n\r");
  DEBUG_Printk("  =========== Press a key ===============\n\r");
}
void menu_option_3(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Get SW0 state ==\n\r");
  sprintf(message,"SW0 state : %d \n\r",BRD_GET_SW0);
  DEBUG_Printk(message);
  //DEBUG_Printk("  =========== Press a key ===============\n\r");
}


void menu_option_4(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Enter wait modee ==\n\r");
  
  //DEBUG_Printk("  =========== Press a key ===============\n\r");
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



/*----------------------------------------------------------------------------*/
//* Function Name       : IRQ_DEBUG_HANDLER
//* Object              : Interrupt handler
//*---------------------------------------------------------------------------*/
void IRQ_DEBUG_HANDLER(void)
{
  uint8_t rxchar;
  DEBUG_read(BASE_DEBUG,&rxchar);
  MenuChoice = (char)rxchar;
}
// -----------------------------------------------------------------------------



// -----------------------------------------------------------------------------
//  Function Name       : Print_menu
//  Object              : 
// -----------------------------------------------------------------------------
void Print_menu(void)
{
 int i;
   
   DEBUG_Printk(" ------------------------------------------\n\r");
   DEBUG_Printk("\n\r");
   DEBUG_Printk(" Select an option :\n\r");
   for(i=0;i<MENU_NB_OPTIONS;++i)DEBUG_Printk(menu_choice_msg[i]);
   DEBUG_Printk(" =>");
}


// -----------------------------------------------------------------------------
//  Function Name       : Print_menu
//  Object              : 
// -----------------------------------------------------------------------------
void Print_device_info(void)
{
  uint32_t reset_cause, chip_id, chip_exid;
 
   // ------------ Check last reset cause
   reset_cause = check_reset_source();

   // ---- Check Chip ID
   get_and_check_chipid(&chip_id, &chip_exid);

   // Send Chip IP on debug
   sprintf (message,"ChipID: %X \n\r",chip_id);
   DEBUG_Printk(message);   
   if(chip_exid){
     sprintf(message,"ExtID : %X \n\r",chip_exid);
     DEBUG_Printk(message);
     }

   // Send MCK freq value on debug
   sprintf (message,"MCK clock speed is %d Hz\n\r",MCK_clock_speed);
   DEBUG_Printk(message);
   
   // Send last reset cause on debug
   sprintf (message,"Last reset : %s \n\r",reset_source_msg[reset_cause]);
   DEBUG_Printk(message);

   DEBUG_Printk("\n\n\r");
}


// -----------------------------------------------------------------------------
//  Function Name       : get_and_check_chipid
//  Object              : 
// -----------------------------------------------------------------------------
void get_and_check_chipid(uint32_t* chip_id, uint32_t* chip_exid)
{
 uint8_t bad_setting;
  
  *chip_id   = CHIP_ID_REGISTER;
  *chip_exid = CHIP_EXID_REGISTER;

  bad_setting=0;
  #ifdef _DEVICE_CHIP_ID_
    if (*chip_id!=_DEVICE_CHIP_ID_){bad_setting=1;}
  #endif

  if(bad_setting){
    DEBUG_Printk("\n\n\n\rxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    DEBUG_Printk("\n\rxx Warning CHIP ID and compilation setting mismatch !!!");
    DEBUG_Printk("\n\rxx ...check device definition in \"project.h\" file\n\r");
    DEBUG_Printk("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n\r");
    }
}


// -----------------------------------------------------------------------------
//  Function Name       : run_menu
//  Object              : 
// -----------------------------------------------------------------------------
void run_menu(void)
{
   Print_device_info();
   Print_menu();
 

#if (DEMO_PIO_MEASURE_ATOMIC == 1 )
   //Set state to 1
   PIOA->PIO_SODR = PIO_PA24;
#elif (DEMO_PIO_MEASURE_CALL == 1 )
   pio_set(BRD_BASE_PIO_D0,BRD_D0_MASK);
#endif
        MenuChoice = 0;
   while (1)
   {
      switch (MenuChoice)
      {
         case '0':
                  // --------------- Menu option 0
                  menu_option_0();
                  MenuChoice=0;
                  Print_menu();
 	 break;
         
         case '1':
                  // --------------- Menu option 1
                  menu_option_1();
                  MenuChoice=0;
                  Print_menu();
 	 break;
       
         case '2':
                  // --------------- Menu option 2
                  menu_option_2();
                  MenuChoice=0;
                  Print_menu();
 	 break;

        
         case 0:
                // -- loop ---------------------
 	        break;

         default:
                  // --------------- Error message
                  DEBUG_Printk("\n\r\n\r");
                  DEBUG_Printk("  =========== Not a valid option ========\n\r");
                  DEBUG_Printk("\n\r");
                  //DEBUG_Printk("  =========== Press a key ===============\n\r");
                  MenuChoice=0;
                  Print_menu();
         break;//default
      }// switch
   }// while
}