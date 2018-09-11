// $asf_license$

/*! \file *********************************************************************
 *
 * \brief PIO V4 driver.
 *
 *
 * - Compiler:           tested on IAR EWARM
 * - Supported devices:  SAMA5D2x (92U01)
 * - AppNote:
 *
 ******************************************************************************/

#ifndef _V_PIOV4_H
#define _V_PIOV4_H

#include "project.h"

// ---- General purpose include files
#include "device.h"



#if (PIO_HAS_TAMPER_CONFIG != 1)
  #define PIO_CFGR_TAMPEN_NO_FREEZE (0)
#else
  //PIO_CFGR_TAMPEN_NO_FREEZE should be defined in product definition headers
#endif



#define PIO_IS_WRITE_PROTECTED(pio_pt) ((pio_pt->PIO_WPMR) & PIO_WPMR_WPEN)



#define PIO_CFGR_DRVSTR_DEFAULT (pio_drive_str_t)PIO_CFGR_DRVSTR_ME // set medium as default

///////////////////////////////////////////////////////////////////////////////
typedef enum _pio_type {
  #if (PIO_HAS_PERIPH_A == 1) // The pin is controlled by the peripheral A.
    PIO_PERIPH_A = PIO_CFGR_FUNC_PERIPH_A,
  #endif
  #if (PIO_HAS_PERIPH_B == 1) // The pin is controlled by the peripheral B.
    PIO_PERIPH_B = PIO_CFGR_FUNC_PERIPH_B,
  #endif
  #if (PIO_HAS_PERIPH_C == 1) // The pin is controlled by the peripheral C.
    PIO_PERIPH_C = PIO_CFGR_FUNC_PERIPH_C,
  #endif
  #if (PIO_HAS_PERIPH_D == 1) // The pin is controlled by the peripheral D.
    PIO_PERIPH_D = PIO_CFGR_FUNC_PERIPH_D,
  #endif
  #if (PIO_HAS_PERIPH_E == 1) // The pin is controlled by the peripheral E.
    PIO_PERIPH_E = PIO_CFGR_FUNC_PERIPH_E,
  #endif
  #if (PIO_HAS_PERIPH_F == 1) // The pin is controlled by the peripheral F.
    PIO_PERIPH_F = PIO_CFGR_FUNC_PERIPH_F,
  #endif
  #if (PIO_HAS_PERIPH_G == 1) // The pin is controlled by the peripheral G.
    PIO_PERIPH_G = PIO_CFGR_FUNC_PERIPH_G,
  #endif
  #if (PIO_HAS_PERIPH_H == 1) // The pin is controlled by the peripheral H.
    PIO_PERIPH_H = PIO_CFGR_FUNC_PERIPH_H,
  #endif
  #if (PIO_HAS_PERIPH_I == 1) // The pin is controlled by the peripheral I.
    PIO_PERIPH_I = PIO_CFGR_FUNC_PERIPH_I,
  #endif
  #if (PIO_HAS_PERIPH_J == 1) // The pin is controlled by the peripheral J.
    PIO_PERIPH_J = PIO_CFGR_FUNC_PERIPH_J,
  #endif
    //PIO_INPUT,	// The pin is an input.
    //PIO_OUTPUT_0,	// The pin is an output and has a default level of 0.
    //PIO_OUTPUT_1,	// The pin is an output and has a default level of 1.
    PIO_GPIO = PIO_CFGR_FUNC_GPIO // The pin is not a function pin.
} pio_type_t;
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
typedef enum _pio_drive_str {
    PIO_DRIVE_HIGH   = PIO_CFGR_DRVSTR_HI,
    PIO_DRIVE_MEDIUM = PIO_CFGR_DRVSTR_ME,
    PIO_DRIVE_LOW    = PIO_CFGR_DRVSTR_LO
} pio_drive_str_t;
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
typedef enum _pio_event_sel {
    PIO_EVENT_FALLING    = PIO_CFGR_EVTSEL_FALLING,
    PIO_EVENT_RISING     = PIO_CFGR_EVTSEL_RISING,
    PIO_EVENT_ANY_EDGE   = PIO_CFGR_EVTSEL_BOTH,
    PIO_EVENT_LOW_LEVEL  = PIO_CFGR_EVTSEL_LOW,
    PIO_EVENT_HIGH_LEVEL = PIO_CFGR_EVTSEL_HIGH
} pio_event_sel_t;
///////////////////////////////////////////////////////////////////////////////


// Backward compatibility
///////////////////////////////////////////////////////////////////////////////
// Default pin configuration (no attribute).
#define PIO_DEFAULT      (0u << 0)
// The internal pin pull-up is active.
#define PIO_PULLUP        PIO_CFGR_PUEN_ENABLED
// The internal glitch filter is active.
#define PIO_DEGLITCH      PIO_CFGR_IFEN_ENABLED
// The pin is open-drain.
#define PIO_OPENDRAIN     PIO_CFGR_OPD_ENABLED

// The internal debouncing filter is active.
#define PIO_DEBOUNCE      PIO_CFGR_SCHMITT_ENABLED

/*
// Enable additional interrupt modes.
#define PIO_IT_AIME                 (1u << 4)

// Interrupt High Level/Rising Edge detection is active.
#define PIO_IT_RE_OR_HL             (1u << 5)
// Interrupt Edge detection is active.
#define PIO_IT_EDGE                 (1u << 6)
*/
// Low level interrupt is active
#define PIO_IT_LOW_LEVEL   PIO_CFGR_EVTSEL_LOW
// High level interrupt is active
#define PIO_IT_HIGH_LEVEL  PIO_CFGR_EVTSEL_HIGH
// Falling edge interrupt is active
#define PIO_IT_FALL_EDGE   PIO_CFGR_EVTSEL_FALLING
// Rising edge interrupt is active
#define PIO_IT_RISE_EDGE   PIO_CFGR_EVTSEL_RISING
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

#ifndef _V_PIOV4_FUNC_QUALIFIER
  #if defined(V_PIOV4_FUNC_INLINE) && (V_PIOV4_FUNC_INLINE==1)
    #define _V_PIOV4_FUNC_QUALIFIER inline
    #define _V_PIOV4_FUNC_IMPLEMENT (1)
  #else
    #define _V_PIOV4_FUNC_QUALIFIER extern
    #define _V_PIOV4_FUNC_IMPLEMENT (0)
  #endif
#endif

/**
 * \brief Returns 1 if one or more PIO of the given Pin instance currently have
 * a high level; otherwise returns 0. This method returns the actual value that
 * is being read on the pin. To return the supposed output value of a pin, use
 * pio_get_output_data_status() instead.
 *
 * \param IO_group Pointer to a PioIo_group

 * \param type     PIO type.
 * \param mask     Bitmask of one or more pin(s)
 *
 * \retval 1 at least one PIO currently has a high level.
 * \retval 0 all PIO have a low level.
 */
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_get(PioIo_group * IO_group, const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  if ((IO_group->PIO_PDSR & mask) == 0) {
    return 0;
  } else {
    return 1;
  }
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/**
 * \brief Sets a high output level on all the PIOs defined in mask.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will save the value if they are changed to outputs.
 *
 * \param IO_group Pointer to a PioIo_group
 * \param mask Bitmask of one or more pin(s)
 */
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_set(PioIo_group * IO_group, const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_SODR = mask;
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/**
 * \brief Sets a low output level on all the PIOs defined in mask.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will save the value if they are changed to outputs.
 *
 * \param IO_group Pointer to a PioIo_group
 * \param mask Bitmask of one or more pin(s)
 */
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_clear(PioIo_group * IO_group, const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_CODR = mask;
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/**
 * \brief toogle output level on all the PIOs defined in the given Pin instance.
 * This has no immediate effects on PIOs that are not output, but the PIO
 * controller will memorize the value they are changed to outputs.
 *
 * PIOV4 function only
 * \param IO_group Pointer to a PioIo_group
 * \param mask Bitmask of one or more pin(s)
 */
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_toggle(PioIo_group * IO_group, const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_MSKR = mask;
  IO_group->PIO_ODSR = ((IO_group->PIO_ODSR)^mask);
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/**
 * \brief Perform complete pins configuration; general attributes and PIO init 
 * if necessary.
 *
 * PIOV4 function only
 *
 * \param IO_group Pointer to a PioIo_group
 * \param mask Bitmask of one or more pin(s) to configure.
 * \param PIO_CFGR_FUNC_GPIO, PIO_CFGR_FUNC_PERIPH_A,...)
 * \param dir (PIO_CFGR_DIR_INPUT / PIO_CFGR_DIR_OUTPUT)
 * \param attribute Pins attributes.
 *          PIO_CFGR_PUEN_DISABLED / PIO_CFGR_PUEN_ENABLED
 *          | PIO_CFGR_PDEN_DISABLED / PIO_CFGR_PDEN_ENABLED
 *          | PIO_CFGR_IFEN_DISABLED / PIO_CFGR_IFEN_ENABLED
 *          | PIO_CFGR_IFSCEN_DISABLED / PIO_CFGR_IFSCEN_ENABLED
 *          | PIO_CFGR_OPD_DISABLED / PIO_CFGR_OPD_ENABLED
 *          | PIO_CFGR_SCHMITT_ENABLED / PIO_CFGR_SCHMITT_DISABLED
 * \param drvstr
 *          PIO_CFGR_DRVSTR_HI
 *          PIO_CFGR_DRVSTR_ME
 *          PIO_CFGR_DRVSTR_LO
 * \param evtsel
 *          PIO_CFGR_EVTSEL_FALLING
 *          PIO_CFGR_EVTSEL_RISING
 *          PIO_CFGR_EVTSEL_BOTH
 *          PIO_CFGR_EVTSEL_LOW
 *          PIO_CFGR_EVTSEL_HIGH
 * \param tampen (PIO_CFGR_TAMPEN_NO_FREEZE / PIO_CFGR_TAMPEN_FREEZE)
 * 
 * \return Whether the pins have been configured properly.
 */
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_configure(PioIo_group*          IO_group,
                                                   const uint32_t        mask,
                                                   const pio_type_t      pio_func,
                                                   const uint32_t        dir,
                                                   const uint32_t        attribute,
                                                   const pio_drive_str_t drvstr,
                                                   const pio_event_sel_t evtsel,
                                                   const uint32_t        tampen)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_MSKR = mask;
  IO_group->PIO_CFGR = ( pio_func | dir | attribute | drvstr \
                       | evtsel | tampen );
  return(1);
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_periph(PioIo_group*     IO_group,
                                                      const uint32_t   mask,
                                                      const pio_type_t pio_func)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  if(pio_func!=PIO_CFGR_FUNC_GPIO){
    return(v_pioV4_configure(IO_group,mask,pio_func,0,0,
                         PIO_CFGR_DRVSTR_DEFAULT,
                         (pio_event_sel_t)0,
                         PIO_CFGR_TAMPEN_NO_FREEZE));
    }
  else {return(0);}
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_output_default(PioIo_group*   IO_group,
                                                              const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  //IO_group->PIO_SODR = mask; //set to 1 before setting as output
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_OUTPUT,0,PIO_CFGR_DRVSTR_DEFAULT,
                            (pio_event_sel_t)0,PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_output_high(PioIo_group*   IO_group,
                                                              const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_SODR = mask; //set to 1 before setting as output
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_OUTPUT,0,PIO_CFGR_DRVSTR_DEFAULT,
                            (pio_event_sel_t)0,PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_output_low(PioIo_group*   IO_group,
                                                              const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_CODR = mask; //set to 0 before setting as output
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_OUTPUT,0,PIO_CFGR_DRVSTR_DEFAULT,
                            (pio_event_sel_t)0,PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//Set output level before driving, to prevent any unexpected edge on pin.
extern uint32_t v_pioV4_iocfg_output_noedge(PioIo_group*   IO_group,
                                                              const uint32_t mask);
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_output(PioIo_group*    IO_group,
                                                      const uint32_t  mask,
                                                      const uint32_t  attribute,
                                                      pio_drive_str_t drvstr)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_OUTPUT,attribute,drvstr,
                            (pio_event_sel_t)0,PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_input(PioIo_group*         IO_group,
                                                    const uint32_t        mask,
                                                    const uint32_t        attribute,
                                                    const pio_event_sel_t evtsel)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_INPUT,attribute,
                            PIO_CFGR_DRVSTR_DEFAULT,evtsel,
                            PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_input_pd(PioIo_group*   IO_group,
                                                        const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_INPUT,PIO_CFGR_PDEN_ENABLED,
                            PIO_CFGR_DRVSTR_DEFAULT,(pio_event_sel_t)0,
                            PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_iocfg_input_pu(PioIo_group*   IO_group,
                                                        const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  return (v_pioV4_configure(IO_group,mask,(pio_type_t)PIO_CFGR_FUNC_GPIO,
                            PIO_CFGR_DIR_INPUT,PIO_CFGR_PUEN_ENABLED,
                            PIO_CFGR_DRVSTR_DEFAULT,(pio_event_sel_t)0,
                            PIO_CFGR_TAMPEN_NO_FREEZE));
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_pio_wr_protect_disable(Pio* pio)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  pio->PIO_WPMR = PIO_WPMR_WPKEY_PASSWD & (~PIO_WPMR_WPEN);
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_pio_wr_protect_enable(Pio* pio)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  pio->PIO_WPMR = PIO_WPMR_WPKEY_PASSWD | PIO_WPMR_WPEN;
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_enable_interrupt(PioIo_group*   IO_group,
                                                          const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_IER = mask;
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER void v_pioV4_disable_interrupt(PioIo_group*   IO_group,
                                                          const uint32_t mask)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  IO_group->PIO_IDR = mask;
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_get_interrupt_status(PioIo_group* IO_group)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  return(IO_group->PIO_ISR);
}
#endif
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
_V_PIOV4_FUNC_QUALIFIER uint32_t v_pioV4_get_interrupt_mask(PioIo_group* IO_group)
#if (_V_PIOV4_FUNC_IMPLEMENT!=1)
;
#else
{
  return(IO_group->PIO_IMR);
}
#endif
///////////////////////////////////////////////////////////////////////////////



// PIO V3 functions TO BE IMPLEMENTED for V4 as well ?
/////////////////////////// draft /////////////////////////////////////////////
// Freeze status
/*
#define PIO_CFGR_PCFS (0x1u << 29)
#define   PIO_CFGR_PCFS_NOT_FROZEN (0x0u << 29)
#define   PIO_CFGR_PCFS_FROZEN (0x1u << 29)
#define PIO_CFGR_ICFS (0x1u << 30)
#define   PIO_CFGR_ICFS_NOT_FROZEN (0x0u << 30)
#define   PIO_CFGR_ICFS_FROZEN (0x1u << 30)
*/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/*
extern void pio_pull_up(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_pull_up_enable);
extern void pio_set_debounce_filter(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_cut_off);

extern uint32_t pio_get_output_data_status(const Pio * p_pio,
		const uint32_t dw_mask);

extern void pio_set_multi_driver(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_multi_driver_enable);
extern uint32_t pio_get_multi_driver_status(const Pio * p_pio);

extern void pio_pull_down(Pio * p_pio, const uint32_t dw_mask,
		const uint32_t dw_pull_down_enable);

extern void pio_enable_output_write(Pio * p_pio, const uint32_t dw_mask);
extern void pio_disable_output_write(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_get_output_write_status(const Pio * p_pio);
extern void pio_sync_output_write(Pio * p_pio, const uint32_t dw_mask);

extern void pio_set_schmitt_trigger(Pio * p_pio, const uint32_t dw_mask);
extern uint32_t pio_get_schmitt_trigger(const Pio * p_pio);

extern void pio_set_additional_interrupt_mode(Pio * p_pio,const uint32_t dw_mask, const uint32_t dw_attribute);
extern uint32_t pio_get_writeprotect_status(const Pio * p_pio);
*/
///////////////////////////////////////////////////////////////////////////////

#endif // _V_PIOV4_H

