/* ============================================================================= */
/*  SOFTWARE API DEFINITION FOR PPP                                              */
/*    Stephane GALEA - 06/12/2014                                                */
/*    ATMEL ROUSSET                                                              */
/* ============================================================================= */

#ifndef _PPP_
#define _PPP_

#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief HSDHC hardware registers */
typedef struct {
  __I  uint32_t Reserved1[8];
  __IO uint32_t PPP_CONFIG;         /**< \brief (Ppp Offset: 0x20) CONFIG Register */
  __IO uint32_t PPP_CTRL;           /**< \brief (Ppp Offset: 0x24) CTRL Register */
  __IO uint32_t PPP_CMD;            /**< \brief (Ppp Offset: 0x28) CMD Register */
  __IO uint32_t PPP_PC;             /**< \brief (Ppp Offset: 0x2C) PC Register */
  __IO uint32_t PPP_HF;             /**< \brief (Ppp Offset: 0x30) HF Register */
  __O  uint32_t PPP_HFCTRL;         /**< \brief (Ppp Offset: 0x34) HFCTRL Register */
  __O  uint32_t PPP_HFCS01;         /**< \brief (Ppp Offset: 0x38) HFCS01 Register */
  __O  uint32_t PPP_HFCS23;         /**< \brief (Ppp Offset: 0x3C) HFCS23 Register */
  __I  uint32_t Reserved2[5];
} Ppp;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

/* ************************************************************************** */
/*   BASE ADDRESS DEFINITIONS FOR SAMA5D2 */
/* ************************************************************************** */
#if (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
#define PPP    (0xFC060000) /**< \brief (PPP   ) Base Address */
#else
#define PPP    ((Ppp     *)0xFC060000) /**< \brief (PPP   ) Base Address */
#endif /* (defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#endif //_PPP_