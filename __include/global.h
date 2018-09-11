#ifndef _GLOBAL_H
#define _GLOBAL_H


// ----------------------------------------------------------------------------
//  Global macros
// ---------------------------------------------------------------------------
#define EXPANDER(a,b,c,d)       a##b##c##d
#define MERGE(a,b,c,d)          EXPANDER(a,b,c,d)
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//  Compiler definitions
// ---------------------------------------------------------------------------
#ifndef _FORCE_INLINE_DIRECTIVE_
  #ifdef __ICCARM__
    #define _FORCE_INLINE_DIRECTIVE_ _Pragma("inline=forced")
  #else
    #define _FORCE_INLINE_DIRECTIVE_
  #endif
#endif
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//  Clock config
// ----------------------------------------------------------------------------
#define USE_RC_32KHZ  (32u)

// Main clock values
#define USE_RC_4MHZ   (4u)
#define USE_RC_8MHZ   (8u)
#define USE_RC_12MHZ  (12u)
#define USE_RC_16MHZ  (16u)
#define USE_RC_24MHZ  (24u)
#define USE_EXT_CLK   (0xEE) // xtal in bypass mode
#define USE_XTAL      (0xCC) // xtal (no bypass)

// Master Clock values
#define USE_MAIN_CLK (0x1)
#define USE_SLOW_CLK (0x5)
#define USE_PLLA     (0xAA)
#define USE_PLLB     (0xBB)
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//  Code configuration
// ----------------------------------------------------------------------------
#define  CODE_DBG  (1)   // CODE_VERSION value => DEBUG code
#define  CODE_PRD  (0)   // CODE_VERSION value => production code
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//  Debug configuration / PRG mode serial com link
// ----------------------------------------------------------------------------
#define  NO_DEBUG      (0xFF)   // DEBUG_MODE value
#define  SERIAL_DEBUG  (0x01)   // DEBUG_MODE value

#define  TYPE_DBGU  (3) // DEBUG_LINK_TYPE value
#define  TYPE_UART  (1) // DEBUG_LINK_TYPE value
#define  TYPE_USART (2) // DEBUG_LINK_TYPE value
#define  DBG_UNIT   (4) // DEBUG_LINK_USED value
#define  TYPE_SSPI  (5) // 
//----------------------------------------------
//----------------------------------------------
#define ISRAM (2)   // ERRLOG_MODE value
#define FLASH (3)   // ERRLOG_MODE value
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//  Ethernet configurations
// ----------------------------------------------------------------------------
#define  PHY_KSZ8081MNX  (0x80810000)
#define  PHY_KSZ8081RNB  (0x80810001)

#define  MII_MODE             (0)
#define  RMII_MODE            (1)
#define  RMII25MHZ_MODE       (2)
#define  RMII50MHZ_MODE       (3)
// ----------------------------------------------------------------------------




//------------------------------------------------------------------------------
// ----  Core types Definitions          ----
//-------------------------------------------
#define CORE_TYPE_CA5    (315)
#define CORE_TYPE_CM3    (3133)
#define CORE_TYPE_CM4    (3134)
#define CORE_TYPE_CM7    (3137)
#define CORE_TYPE_ARM7   (118137)
#define CORE_TYPE_ARM9   (118139)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ----  Misc Definitions -----          ----
//-------------------------------------------
#define INFINITE_LOOP (0xFFFFFFFF)   // for test_nb_iter parameters
//------------------------------------------------------------------------------


#endif//_GLOBAL_H
