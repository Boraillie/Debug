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

#include <string.h>
#include "menu.h"

#define ACTIVE_MODE 0
#define WAIT_MODE 1
#define SLEEP_MODE 2
#define BACKUP_MODE 3

/** (SCR) Sleep deep bit */
#define SCR_SLEEPDEEP   (0x1 <<  2)

// global variables
char message[80];
unsigned int MenuChoice;
extern unsigned int MCK_clock_speed;       // main.c
extern const char reset_source_msg[7][10]; // v_utils.c
#pragma location = 0x200080cc
uint32_t dummy_table[100]={0};

/*----------------------------------------------------------------------------
 *        Local variables
 *----------------------------------------------------------------------------*/


static uint32_t lowPowerMode = ACTIVE_MODE;

static uint32_t interruptType;


// -----------------------------------------------------------------------------
#define MENU_NB_OPTIONS     10 // max=10

#if ( BUG_PRINTF == 1 )
  #define MENU_STRING_LENGTH 34
  #pragma location = 0x20008000
#else 
  #define MENU_STRING_LENGTH 40
#endif



char menu_choice_msg[MENU_NB_OPTIONS][MENU_STRING_LENGTH]={\
  //                          "====================MAXLENGTH===================
                              " 0 -> Perform a Software Reset  \n\r",\
                              " 1 -> Turn off D0 LED \n\r",\
                              " 2 -> Turn on D0 LED   \n\r",\
                              " 3 -> Get SW0 state \n\r",\
                              " 4 -> Low Power Prepare ==\n\r",\
                              " 5 -> Enter Backup mode ==\n\r",\
                              " 6 -> Enter wait mode ==\n\r",\
                              " 7 -> Enter Sleep mode ==\n\r",\
                              " 8 -> Low Power Exit           \n\r",\
                              " 9 -> Print memory info         \n\r"}; // Ensure the last line is always 34 char to garantee printf bug 
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
  DEBUG_Printk("  =========== Low Power Prepare... ==\n\r");
  _LowPower_Prepare(); 
  DEBUG_Printk("  =========== Low Power Preparation done... ==\n\r");
}

void menu_option_5(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Enter Backup mode ==\n\r");
  _EnterBackupMode();

}

void menu_option_6(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Enter wait mode ==\n\r");
  _EnterWaitMode();
}


void menu_option_7(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Enter Sleep mode ==\n\r");
  _EnterSleepMode();

}

void menu_option_8(void)
{
  DEBUG_Printk("\n\r\n\r");
  DEBUG_Printk("  =========== Low Power Exit ==\n\r");
  Exit_LP_Mode();
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
//  Function Name       : Low poer mode librairie
// -----------------------------------------------------------------------------
/**  IRQ pin handler */
void PIOA_IrqHandler( )
{
   uint32_t status;

   /* Read PIO controller status */
   status = PIOA->PIO_ISR;
   status &= PIOA->PIO_IMR;

   if(lowPowerMode == WAIT_MODE)
      interruptType = WAIT_MODE;
   else if(lowPowerMode == BACKUP_MODE)
      interruptType = BACKUP_MODE;
   else if(lowPowerMode == SLEEP_MODE)
      interruptType = SLEEP_MODE;
   else
      interruptType = ACTIVE_MODE;
}

// initialize push button for state transition

static void _Init_Pushbutton_Trigger(void)
{
    uint32_t cuttoff = 10;

    disable_interrupt(BRD_ID_PIO_SW0);

    // then, we configure the PIO Lines
    pio_configure(PIOA,PIO_INPUT,BRD_SW0_MASK,PIO_PULLUP);
    
    // PIO SetDebounce Filter cuttoff = 10 Hz
    BRD_BASE_PIO_SW0->PIO_IFSCER = BRD_SW0_MASK; /* set Debouncing, 0 bit field no effect */
    BRD_BASE_PIO_SW0->PIO_SCDR = ((32678/(2*(cuttoff))) - 1) & 0x3FFF; //\TODO: Check the formula
    
    //Enable PA2 as interrupt source
   BRD_BASE_PIO_SW0->PIO_IER = BRD_SW0_MASK;
   
   // Enable PIOA interrupts
   enable_interrupt(BRD_ID_PIO_SW0);
}

/**
 * \brief Initialize the chip.
 */
static void _LowPower_Prepare( void )
{
    
    /* Disable Systick interrupt */
    SysTick->CTRL=0x04;
    
    //TODO1.0 write dummy table to check i memory stays on
    
    
    /* TODO1.1: Disable all the peripheral clocks */
    
    

    /* TODO1.2: Disable USB Clock */
    REG_PMC_SCDR = PMC_SCER_UDP;

   /* TODO1.3: Enable PIO function except on PA2 (IRQ pin) */

    
   /* TODO1.4: Set all I/Os as Input except on PA2 (IRQ pin) */

    
   /* TODO1.5: Disable all I/Os pull-up except on PA2 (IRQ pin) */

    
    //Set back UART LINK \TODO : Introduce unclocked + Pio bug
    DEBUG_Initialize(MCK_clock_speed);

}

/**
 * \brief Test Backup Mode.
 */


static void _EnterBackupMode(void)
{
  

//    _LowPower_Prepare();
   
    // initialize push button for state transition
//    _Init_Pushbutton_Trigger();
      // then, we configure the PIO Lines
   
    /* GPBR0 is for recording times of entering backup mode */
    GPBR->SYS_GPBR[0] += 1;

    /* TODO4.1: Enable the PA2 IRQ pin as the wake-up source */

    /* TOD4.2: Entry in the Backup Mode: */
    /* Set SLEEPDEEP bit */

    
    /* Set VROFF bit  */
    SUPC->SUPC_CR |= (SUPC_CR_KEY(0xA5) | SUPC_CR_VROFF_STOP_VREG);
}


/**
 * \brief Enter Wait Mode */
static void _EnterWaitMode( void )
{
    /* Initialize PIOs for low power */
    //_LowPower_Prepare();
    
    _Init_Pushbutton_Trigger();

    /* Disable Brownout Detector */
    SUPC->SUPC_MR |= (uint32_t)(0xA5 << 24) | (0x01 << 13) ;

    /* TODO2.1: Switch MCK to the fast RC oscillator */
    //SwitchMck2FastRC(FAST_RC_OSC_4MHZ, PMC_MCKR_PRES_CLK);
    set_clocks((uint8_t)USE_RC_4MHZ,USE_MAIN_CLK,0,0,0,0,1,0,0);
    /* TODO2.2: Set WKUP2 (IRQ pin) as the fast startup event */
    PMC->PMC_FSMR &= (uint32_t)~0xFFFF;
    PMC->PMC_FSMR |= PMC_FSMR_FSTT2;

    /* TODO2.3:  Entry in the Wait Mode: */
    /* Set LPM bit */
    PMC->PMC_FSMR |= PMC_FSMR_LPM;
    /*Set FLPM bit */
    PMC->PMC_FSMR |= 0x00300000;
    /* Clear SLEEPDEEP bit */
    SCB->SCR &= ~SCR_SLEEPDEEP;
    /* Set Flash Wait State at 0 */
    EFC0->EEFC_FMR = (0 << 8);     
    /* Set waitmode bit*/
    PMC->CKGR_MOR |= (CKGR_MOR_KEY(0x37) | CKGR_MOR_WAITMODE);
    while( !(PMC->PMC_SR & PMC_SR_MCKRDY) );

    /* Waiting for MOSCRCEN bit is cleared is strongly recommended
    to ensure that the core will not execute undesired instructions */
    while ( !(PMC->CKGR_MOR & CKGR_MOR_MOSCRCEN) ) ;

}

/**
 * \brief Enter Sleep Mode */
static void _EnterSleepMode( void )
{
    /* Initialize PIOs for low power */
    //_LowPower_Prepare();

    /* Disable Brownout Detector */
    SUPC->SUPC_MR |= (uint32_t)(0xA5 << 24) | (0x01 << 13);



    /* Initialize PA2 as the wake-up interrupt */
    _Init_Pushbutton_Trigger();

    /* TODO3.1: Switch to the Fast RC Oscillator - 4MHz */
    set_clocks((uint8_t)USE_RC_4MHZ,USE_MAIN_CLK,0,0,0,0,4,0,0);
    /* TODO3.2: Entry in the Sleep Mode: */
    /* Clear LPM bit */
    PMC->PMC_FSMR &= ~PMC_FSMR_LPM;
    /* Clear SLEEPDEEP bit */
    SCB->SCR &= ~SCR_SLEEPDEEP;
    /* Execute __WFI() function */
    __WFI();

    /* Waiting for MOSCRCEN bit is cleared is strongly recommended
    to ensure that the core will not execute undesired instructions */
    while ( !(PMC->CKGR_MOR & CKGR_MOR_MOSCRCEN) ) ;
}
static void Exit_LP_Mode(void)
{
    uint32_t temp;

    /* Set FWS for Embedded Flash Access */
    EFC0->EEFC_FMR = (6 << 8);
    
   /* Restore working clock */
    if(config_clocks())
      while(1); // stop in case of error
    DEBUG_Initialize(MCK_clock_speed);


    /* Enable Brownout Detector */
    temp = SUPC->SUPC_MR & 0x00FFFFFF;
    SUPC->SUPC_MR = (uint32_t)(0xA5 << 24) | (temp & (uint32_t)(~(0x01 << 13)));
    
    /* Disable interrupt on IRQ pin to avoid wrong detect */
    if(interruptType==SLEEP_MODE) {
    disable_interrupt(BRD_ID_PIO_SW0) ;
        //Disable PA2 as interrupt source
    BRD_BASE_PIO_SW0->PIO_IDR = BRD_SW0_MASK;
    }

    interruptType = ACTIVE_MODE;
    Valid_DebugTrace( "* Low power mode exited *\n\r");

    /* Init interrupt on BP2 pin to switch in Low Power mode */
    _Init_Pushbutton_Trigger();
}
// -----------------------------------------------------------------------------
//  Function Name       : run_menu
//  Object              : 
// -----------------------------------------------------------------------------
void run_menu(void)
{
  
   volatile int keep_dummy_table = dummy_table[0];
   memset((void *) dummy_table,0x40,sizeof(dummy_table));
   
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
               
           case '3':
               // --------------- Menu option 2
               menu_option_3();
               MenuChoice=0;
               break;
               
           case '4':
               // --------------- Menu option 2
               menu_option_4();
               MenuChoice=0;
               break;
               
           case '5':
               // --------------- Menu option 2
               menu_option_5();
               lowPowerMode = BACKUP_MODE;
               MenuChoice=0;
               break;
               
           case '6':
               // --------------- Menu option 2
               menu_option_6();
               lowPowerMode = WAIT_MODE;
               MenuChoice=0;
               break;
               
           case '7':
               // --------------- Menu option 2
               menu_option_7();
               lowPowerMode = SLEEP_MODE;
               MenuChoice=0;
               break;
               
           case '8':
               // --------------- Menu option 2
               menu_option_8();
               MenuChoice=0;
               Print_menu();
               break;
         case '9':
           // --------------- Printf GPBR 0
           
           
           MenuChoice=0;
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