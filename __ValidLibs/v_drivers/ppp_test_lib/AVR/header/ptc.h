
#ifndef _PTC_H
#define _PTC_H

/* ========================================================================== */
/**  SOFTWARE API DEFINITION FOR PTC */
/* ========================================================================== */
/** \addtogroup U3008_PTC Peripheral Touch Controller */
/*@{*/

#define PTC_U2215
#define REV_PTC                     0x300

/* -------- PTC_CTRLA : (PTC Offset: 0x00) (R/W 16) Control A -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t SWRST:1;          /*!< bit:      0  Software Reset                     */
    volatile uint16_t ENABLE:1;         /*!< bit:      1  Enable                             */
    volatile uint16_t ADRS:1;           /*!< bit:      2  ADC Resolution                     */
    volatile uint16_t FREERUN:1;        /*!< bit:      3  Free Running                       */
    volatile uint16_t LOWPOWER:1;       /*!< bit:      4  CTS system in Low Power Mode       */
    volatile uint16_t :1;               /*!< bit:      5  Reserved                           */
    volatile uint16_t RUNSTDBY:1;       /*!< bit:      6  Run in Standby                     */
    volatile uint16_t :1;               /*!< bit:      7  Reserved                           */
    volatile uint16_t PRSC:2;           /*!< bit:  8.. 9  Clock Prescaler                    */
    volatile uint16_t :2;               /*!< bit: 10..11  Reserved                           */
    volatile uint16_t SAMPLEN:3;        /*!< bit: 12..14  ADC sampling length                */
    volatile uint16_t :1;               /*!< bit:     15  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_CTRLA_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_CTRLA_OFFSET            0x00         /**< \brief (PTC_CTRLA offset) Control A */
#define PTC_CTRLA_RESETVALUE        0x0000       /**< \brief (PTC_CTRLA reset_value) Control A */

#define PTC_CTRLA_SWRST_Pos         0            /**< \brief (PTC_CTRLA) Software Reset */
#define PTC_CTRLA_SWRST             (0x1u << PTC_CTRLA_SWRST_Pos)
#define PTC_CTRLA_ENABLE_Pos        1            /**< \brief (PTC_CTRLA) Enable */
#define PTC_CTRLA_ENABLE            (0x1u << PTC_CTRLA_ENABLE_Pos)
#define PTC_CTRLA_ADRS_Pos          2            /**< \brief (PTC_CTRLA) ADC Resolution */
#define PTC_CTRLA_ADRS              (0x1u << PTC_CTRLA_ADRS_Pos)
#define PTC_CTRLA_FREERUN_Pos       3            /**< \brief (PTC_CTRLA) Free Running */
#define PTC_CTRLA_FREERUN           (0x1u << PTC_CTRLA_FREERUN_Pos)
#define PTC_CTRLA_LOWPOWER_Pos      4            /**< \brief (PTC_CTRLA) CTS system in Low Power Mode */
#define PTC_CTRLA_LOWPOWER          (0x1u << PTC_CTRLA_LOWPOWER_Pos)
#define PTC_CTRLA_RUNSTDBY_Pos      6            /**< \brief (PTC_CTRLA) Run in Standby */
#define PTC_CTRLA_RUNSTDBY          (0x1u << PTC_CTRLA_RUNSTDBY_Pos)
#define PTC_CTRLA_PRSC_Pos          8            /**< \brief (PTC_CTRLA) Clock Prescaler */
#define PTC_CTRLA_PRSC_Msk          (0x3u << PTC_CTRLA_PRSC_Pos)
#define PTC_CTRLA_PRSC(value)       ((PTC_CTRLA_PRSC_Msk & ((value) << PTC_CTRLA_PRSC_Pos)))
#define   PTC_CTRLA_PRSC_OFF_Val          0x0u   /**< \brief (PTC_CTRLA) No division */
#define   PTC_CTRLA_PRSC_DIV2_Val         0x1u   /**< \brief (PTC_CTRLA) Peripheral clock divided by 2 */
#define   PTC_CTRLA_PRSC_DIV4_Val         0x2u   /**< \brief (PTC_CTRLA) Peripheral clock divided by 4 */
#define   PTC_CTRLA_PRSC_DIV8_Val         0x3u   /**< \brief (PTC_CTRLA) Peripheral clock divided by 8 */
#define PTC_CTRLA_PRSC_OFF          (PTC_CTRLA_PRSC_OFF_Val        << PTC_CTRLA_PRSC_Pos)
#define PTC_CTRLA_PRSC_DIV2         (PTC_CTRLA_PRSC_DIV2_Val       << PTC_CTRLA_PRSC_Pos)
#define PTC_CTRLA_PRSC_DIV4         (PTC_CTRLA_PRSC_DIV4_Val       << PTC_CTRLA_PRSC_Pos)
#define PTC_CTRLA_PRSC_DIV8         (PTC_CTRLA_PRSC_DIV8_Val       << PTC_CTRLA_PRSC_Pos)
#define PTC_CTRLA_SAMPLEN_Pos       12           /**< \brief (PTC_CTRLA) ADC sampling length */
#define PTC_CTRLA_SAMPLEN_Msk       (0x7u << PTC_CTRLA_SAMPLEN_Pos)
#define PTC_CTRLA_SAMPLEN(value)    ((PTC_CTRLA_SAMPLEN_Msk & ((value) << PTC_CTRLA_SAMPLEN_Pos)))
#define PTC_CTRLA_MASK              0x735Fu      /**< \brief (PTC_CTRLA) Register Bits Mask */

/* -------- PTC_EVCTRL : (PTC Offset: 0x04) (R/W  8) Event Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  STCONVEI:1;       /*!< bit:      0  Start Conversion Event Input Enable */
    volatile uint8_t  EOCEO:1;          /*!< bit:      1  End of Conversion Event Output Enable */
    volatile uint8_t  WCOMPEO:1;        /*!< bit:      2  Window Comparator Event Output Enable */
    volatile uint8_t  :1;               /*!< bit:      3  Reserved                           */
    volatile uint8_t  STCONVINV:1;      /*!< bit:      4  Start Conversion Event Invert Enable */
    volatile uint8_t  :3;               /*!< bit:  5.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_EVCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_EVCTRL_OFFSET           0x04         /**< \brief (PTC_EVCTRL offset) Event Control */
#define PTC_EVCTRL_RESETVALUE       0x00         /**< \brief (PTC_EVCTRL reset_value) Event Control */

#define PTC_EVCTRL_STCONVEI_Pos     0            /**< \brief (PTC_EVCTRL) Start Conversion Event Input Enable */
#define PTC_EVCTRL_STCONVEI         (0x1u << PTC_EVCTRL_STCONVEI_Pos)
#define PTC_EVCTRL_EOCEO_Pos        1            /**< \brief (PTC_EVCTRL) End of Conversion Event Output Enable */
#define PTC_EVCTRL_EOCEO            (0x1u << PTC_EVCTRL_EOCEO_Pos)
#define PTC_EVCTRL_WCOMPEO_Pos      2            /**< \brief (PTC_EVCTRL) Window Comparator Event Output Enable */
#define PTC_EVCTRL_WCOMPEO          (0x1u << PTC_EVCTRL_WCOMPEO_Pos)
#define PTC_EVCTRL_STCONVINV_Pos    4            /**< \brief (PTC_EVCTRL) Start Conversion Event Invert Enable */
#define PTC_EVCTRL_STCONVINV        (0x1u << PTC_EVCTRL_STCONVINV_Pos)
#define PTC_EVCTRL_MASK             0x17u        /**< \brief (PTC_EVCTRL) Register Bits Mask */

/* -------- PTC_WINCTRL : (PTC Offset: 0x05) (R/W  8) Window Comparator Control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  WINCM:3;          /*!< bit:  0.. 2  Window Comparator Mode             */
    volatile uint8_t  WINSS:1;          /*!< bit:      3  Window Single Sample               */
    volatile uint8_t  :4;               /*!< bit:  4.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_WINCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_WINCTRL_OFFSET          0x05         /**< \brief (PTC_WINCTRL offset) Window Comparator Control */
#define PTC_WINCTRL_RESETVALUE      0x00         /**< \brief (PTC_WINCTRL reset_value) Window Comparator Control */

#define PTC_WINCTRL_WINCM_Pos       0            /**< \brief (PTC_WINCTRL) Window Comparator Mode */
#define PTC_WINCTRL_WINCM_Msk       (0x7u << PTC_WINCTRL_WINCM_Pos)
#define PTC_WINCTRL_WINCM(value)    ((PTC_WINCTRL_WINCM_Msk & ((value) << PTC_WINCTRL_WINCM_Pos)))
#define   PTC_WINCTRL_WINCM_DISABLE_Val   0x0u   /**< \brief (PTC_WINCTRL) No window mode (default) */
#define   PTC_WINCTRL_WINCM_MODE1_Val     0x1u   /**< \brief (PTC_WINCTRL) RESULT < WINLT */
#define   PTC_WINCTRL_WINCM_MODE2_Val     0x2u   /**< \brief (PTC_WINCTRL) RESULT > WINHT */
#define   PTC_WINCTRL_WINCM_MODE3_Val     0x3u   /**< \brief (PTC_WINCTRL) WINLT < RESULT < WINHT */
#define   PTC_WINCTRL_WINCM_MODE4_Val     0x4u   /**< \brief (PTC_WINCTRL) !(WINLT < RESULT < WINHT) */
#define PTC_WINCTRL_WINCM_DISABLE   (PTC_WINCTRL_WINCM_DISABLE_Val << PTC_WINCTRL_WINCM_Pos)
#define PTC_WINCTRL_WINCM_MODE1     (PTC_WINCTRL_WINCM_MODE1_Val   << PTC_WINCTRL_WINCM_Pos)
#define PTC_WINCTRL_WINCM_MODE2     (PTC_WINCTRL_WINCM_MODE2_Val   << PTC_WINCTRL_WINCM_Pos)
#define PTC_WINCTRL_WINCM_MODE3     (PTC_WINCTRL_WINCM_MODE3_Val   << PTC_WINCTRL_WINCM_Pos)
#define PTC_WINCTRL_WINCM_MODE4     (PTC_WINCTRL_WINCM_MODE4_Val   << PTC_WINCTRL_WINCM_Pos)
#define PTC_WINCTRL_WINSS_Pos       3            /**< \brief (PTC_WINCTRL) Window Single Sample */
#define PTC_WINCTRL_WINSS           (0x1u << PTC_WINCTRL_WINSS_Pos)
#define PTC_WINCTRL_MASK            0x0Fu        /**< \brief (PTC_WINCTRL) Register Bits Mask */

/* -------- PTC_INTENCLR : (PTC Offset: 0x08) (R/W  8) Interrupt Enable Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  EOC:1;            /*!< bit:      0  End of Conversion Interrupt Enable */
    volatile uint8_t  WCOMP:1;          /*!< bit:      1  Window Comparator Interrupt Enable */
    volatile uint8_t  :6;               /*!< bit:  2.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_INTENCLR_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_INTENCLR_OFFSET         0x08         /**< \brief (PTC_INTENCLR offset) Interrupt Enable Clear */
#define PTC_INTENCLR_RESETVALUE     0x00         /**< \brief (PTC_INTENCLR reset_value) Interrupt Enable Clear */

#define PTC_INTENCLR_EOC_Pos        0            /**< \brief (PTC_INTENCLR) End of Conversion Interrupt Enable */
#define PTC_INTENCLR_EOC            (0x1u << PTC_INTENCLR_EOC_Pos)
#define PTC_INTENCLR_WCOMP_Pos      1            /**< \brief (PTC_INTENCLR) Window Comparator Interrupt Enable */
#define PTC_INTENCLR_WCOMP          (0x1u << PTC_INTENCLR_WCOMP_Pos)
#define PTC_INTENCLR_MASK           0x03u        /**< \brief (PTC_INTENCLR) Register Bits Mask */

/* -------- PTC_INTENSET : (PTC Offset: 0x09) (R/W  8) Interrupt Enable Set -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  EOC:1;            /*!< bit:      0  End of Conversion Interrupt Enable */
    volatile uint8_t  WCOMP:1;          /*!< bit:      1  Window Comparator Interrupt Enable */
    volatile uint8_t  :6;               /*!< bit:  2.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_INTENSET_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_INTENSET_OFFSET         0x09         /**< \brief (PTC_INTENSET offset) Interrupt Enable Set */
#define PTC_INTENSET_RESETVALUE     0x00         /**< \brief (PTC_INTENSET reset_value) Interrupt Enable Set */

#define PTC_INTENSET_EOC_Pos        0            /**< \brief (PTC_INTENSET) End of Conversion Interrupt Enable */
#define PTC_INTENSET_EOC            (0x1u << PTC_INTENSET_EOC_Pos)
#define PTC_INTENSET_WCOMP_Pos      1            /**< \brief (PTC_INTENSET) Window Comparator Interrupt Enable */
#define PTC_INTENSET_WCOMP          (0x1u << PTC_INTENSET_WCOMP_Pos)
#define PTC_INTENSET_MASK           0x03u        /**< \brief (PTC_INTENSET) Register Bits Mask */

/* -------- PTC_INTFLAG : (PTC Offset: 0x0A) (R/W  8) Interrupt Flag Status and Clear -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  EOC:1;            /*!< bit:      0  End of Conversion Interrupt Flag   */
    volatile uint8_t  WCOMP:1;          /*!< bit:      1  Window Comparator Interrupt Flag   */
    volatile uint8_t  :6;               /*!< bit:  2.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_INTFLAG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_INTFLAG_OFFSET          0x0A         /**< \brief (PTC_INTFLAG offset) Interrupt Flag Status and Clear */
#define PTC_INTFLAG_RESETVALUE      0x00         /**< \brief (PTC_INTFLAG reset_value) Interrupt Flag Status and Clear */

#define PTC_INTFLAG_EOC_Pos         0            /**< \brief (PTC_INTFLAG) End of Conversion Interrupt Flag */
#define PTC_INTFLAG_EOC             (0x1u << PTC_INTFLAG_EOC_Pos)
#define PTC_INTFLAG_WCOMP_Pos       1            /**< \brief (PTC_INTFLAG) Window Comparator Interrupt Flag */
#define PTC_INTFLAG_WCOMP           (0x1u << PTC_INTFLAG_WCOMP_Pos)
#define PTC_INTFLAG_MASK            0x03u        /**< \brief (PTC_INTFLAG) Register Bits Mask */

/* -------- PTC_STATUS : (PTC Offset: 0x0B) (R/   8) Status -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  SYNCBUSY:1;       /*!< bit:      0  CTS Busy Status                    */
    volatile uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_STATUS_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_STATUS_OFFSET           0x0B         /**< \brief (PTC_STATUS offset) Status */
#define PTC_STATUS_RESETVALUE       0x00         /**< \brief (PTC_STATUS reset_value) Status */

#define PTC_STATUS_SYNCBUSY_Pos     0            /**< \brief (PTC_STATUS) CTS Busy Status */
#define PTC_STATUS_SYNCBUSY         (0x1u << PTC_STATUS_SYNCBUSY_Pos)
#define PTC_STATUS_MASK             0x01u        /**< \brief (PTC_STATUS) Register Bits Mask */

/* -------- PTC_SYNCBUSY : (PTC Offset: 0x0C) (R/  16) Synchronisation Busy -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t SWRST:1;          /*!< bit:      0  SWRST Synchronization Busy         */
    volatile uint16_t ENABLE:1;         /*!< bit:      1  ENABLE Synchronization Busy        */
    volatile uint16_t :1;               /*!< bit:      2  Reserved                           */
    volatile uint16_t WINCTRL:1;        /*!< bit:      3  WINCTRL Synchronization Busy       */
    volatile uint16_t CTRLB:1;          /*!< bit:      4  CTRLB Synchronization Busy         */
    volatile uint16_t SWTRIG:1;         /*!< bit:      5  SWTRIG Synchronization Busy        */
    volatile uint16_t :2;               /*!< bit:  6.. 7  Reserved                           */
    volatile uint16_t XSEL:1;           /*!< bit:      8  XSEL Synchronization Busy          */
    volatile uint16_t ACCCTRL:1;        /*!< bit:      9  ACCCTRL Synchronization Busy       */
    volatile uint16_t YSEL:1;           /*!< bit:     10  YSEL Synchronization Busy          */
    volatile uint16_t CTRLC:1;          /*!< bit:     11  CTRLC Synchronization Busy         */
    volatile uint16_t :1;               /*!< bit:     12  Reserved                           */
    volatile uint16_t WINLT:1;          /*!< bit:     13  WINLT Synchronization Busy         */
    volatile uint16_t WINHT:1;          /*!< bit:     14  WINHT Synchronization Busy         */
    volatile uint16_t :1;               /*!< bit:     15  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_SYNCBUSY_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_SYNCBUSY_OFFSET         0x0C         /**< \brief (PTC_SYNCBUSY offset) Synchronisation Busy */
#define PTC_SYNCBUSY_RESETVALUE     0x0000       /**< \brief (PTC_SYNCBUSY reset_value) Synchronisation Busy */

#define PTC_SYNCBUSY_SWRST_Pos      0            /**< \brief (PTC_SYNCBUSY) SWRST Synchronization Busy */
#define PTC_SYNCBUSY_SWRST          (0x1u << PTC_SYNCBUSY_SWRST_Pos)
#define PTC_SYNCBUSY_ENABLE_Pos     1            /**< \brief (PTC_SYNCBUSY) ENABLE Synchronization Busy */
#define PTC_SYNCBUSY_ENABLE         (0x1u << PTC_SYNCBUSY_ENABLE_Pos)
#define PTC_SYNCBUSY_WINCTRL_Pos    3            /**< \brief (PTC_SYNCBUSY) WINCTRL Synchronization Busy */
#define PTC_SYNCBUSY_WINCTRL        (0x1u << PTC_SYNCBUSY_WINCTRL_Pos)
#define PTC_SYNCBUSY_CTRLB_Pos      4            /**< \brief (PTC_SYNCBUSY) CTRLB Synchronization Busy */
#define PTC_SYNCBUSY_CTRLB          (0x1u << PTC_SYNCBUSY_CTRLB_Pos)
#define PTC_SYNCBUSY_SWTRIG_Pos     5            /**< \brief (PTC_SYNCBUSY) SWTRIG Synchronization Busy */
#define PTC_SYNCBUSY_SWTRIG         (0x1u << PTC_SYNCBUSY_SWTRIG_Pos)
#define PTC_SYNCBUSY_XSEL_Pos       8            /**< \brief (PTC_SYNCBUSY) XSEL Synchronization Busy */
#define PTC_SYNCBUSY_XSEL           (0x1u << PTC_SYNCBUSY_XSEL_Pos)
#define PTC_SYNCBUSY_ACCCTRL_Pos    9            /**< \brief (PTC_SYNCBUSY) ACCCTRL Synchronization Busy */
#define PTC_SYNCBUSY_ACCCTRL        (0x1u << PTC_SYNCBUSY_ACCCTRL_Pos)
#define PTC_SYNCBUSY_YSEL_Pos       10           /**< \brief (PTC_SYNCBUSY) YSEL Synchronization Busy */
#define PTC_SYNCBUSY_YSEL           (0x1u << PTC_SYNCBUSY_YSEL_Pos)
#define PTC_SYNCBUSY_CTRLC_Pos      11           /**< \brief (PTC_SYNCBUSY) CTRLC Synchronization Busy */
#define PTC_SYNCBUSY_CTRLC          (0x1u << PTC_SYNCBUSY_CTRLC_Pos)
#define PTC_SYNCBUSY_WINLT_Pos      13           /**< \brief (PTC_SYNCBUSY) WINLT Synchronization Busy */
#define PTC_SYNCBUSY_WINLT          (0x1u << PTC_SYNCBUSY_WINLT_Pos)
#define PTC_SYNCBUSY_WINHT_Pos      14           /**< \brief (PTC_SYNCBUSY) WINHT Synchronization Busy */
#define PTC_SYNCBUSY_WINHT          (0x1u << PTC_SYNCBUSY_WINHT_Pos)
#define PTC_SYNCBUSY_MASK           0x6F3Bu      /**< \brief (PTC_SYNCBUSY) Register Bits Mask */

/* -------- PTC_CTRLB : (PTC Offset: 0x10) (R/W 32) Control B -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t CTSM:4;           /*!< bit:  0.. 3  Capacitive Touch Sensing Mode      */
    volatile uint32_t :4;               /*!< bit:  4.. 7  Reserved                           */
    volatile uint32_t SDS:4;            /*!< bit:  8..11  Sampling Delay Selection           */
    volatile uint32_t ASDV:1;           /*!< bit:     12  Automatic Sampling Delay Variation */
    volatile uint32_t CCDS:2;           /*!< bit: 13..14  Channel Change Delay Selection     */
    volatile uint32_t :1;               /*!< bit:     15  Reserved                           */
    volatile uint32_t ADAS:3;           /*!< bit: 16..18  ADC Accumulation Number            */
    volatile uint32_t :1;               /*!< bit:     19  Reserved                           */
    volatile uint32_t RSEL:2;           /*!< bit: 20..21  Resistor Selection                 */
    volatile uint32_t :10;              /*!< bit: 22..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_CTRLB_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_CTRLB_OFFSET            0x10         /**< \brief (PTC_CTRLB offset) Control B */
#define PTC_CTRLB_RESETVALUE        0x00000000   /**< \brief (PTC_CTRLB reset_value) Control B */

#define PTC_CTRLB_CTSM_Pos          0            /**< \brief (PTC_CTRLB) Capacitive Touch Sensing Mode */
#define PTC_CTRLB_CTSM_Msk          (0xFu << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM(value)       ((PTC_CTRLB_CTSM_Msk & ((value) << PTC_CTRLB_CTSM_Pos)))
#define   PTC_CTRLB_CTSM_0_Val            0x0u   /**< \brief (PTC_CTRLB) Disabled (When CTS is Disabled, the ADC will still work, if ENABLE bit in the CTRL register is set) */
#define   PTC_CTRLB_CTSM_8_Val            0x8u   /**< \brief (PTC_CTRLB) Mutual Capacitance, Differential Integration */
#define   PTC_CTRLB_CTSM_9_Val            0x9u   /**< \brief (PTC_CTRLB) Mutual Capacitance, Differential Integration -inverted polarity */
#define   PTC_CTRLB_CTSM_10_Val           0xAu   /**< \brief (PTC_CTRLB) Self Capacitance, Differential Integration */
#define   PTC_CTRLB_CTSM_11_Val           0xBu   /**< \brief (PTC_CTRLB) Self Capacitance, Differential Integration -inverted polarity */
#define   PTC_CTRLB_CTSM_12_Val           0xCu   /**< \brief (PTC_CTRLB) Mutual Capacitance, Single-ended Integration */
#define   PTC_CTRLB_CTSM_13_Val           0xDu   /**< \brief (PTC_CTRLB) Mutual Capacitance, Single-ended Integration -inverted polarity */
#define   PTC_CTRLB_CTSM_14_Val           0xEu   /**< \brief (PTC_CTRLB) Self Capacitance, Single-ended Integration */
#define   PTC_CTRLB_CTSM_15_Val           0xFu   /**< \brief (PTC_CTRLB) Self Capacitance, Single-ended Integration -inverted polarity */
#define PTC_CTRLB_CTSM_0            (PTC_CTRLB_CTSM_0_Val          << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_8            (PTC_CTRLB_CTSM_8_Val          << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_9            (PTC_CTRLB_CTSM_9_Val          << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_10           (PTC_CTRLB_CTSM_10_Val         << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_11           (PTC_CTRLB_CTSM_11_Val         << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_12           (PTC_CTRLB_CTSM_12_Val         << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_13           (PTC_CTRLB_CTSM_13_Val         << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_14           (PTC_CTRLB_CTSM_14_Val         << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_CTSM_15           (PTC_CTRLB_CTSM_15_Val         << PTC_CTRLB_CTSM_Pos)
#define PTC_CTRLB_SDS_Pos           8            /**< \brief (PTC_CTRLB) Sampling Delay Selection */
#define PTC_CTRLB_SDS_Msk           (0xFu << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS(value)        ((PTC_CTRLB_SDS_Msk & ((value) << PTC_CTRLB_SDS_Pos)))
#define   PTC_CTRLB_SDS_OFF_Val           0x0u   /**< \brief (PTC_CTRLB) No sampling delay */
#define   PTC_CTRLB_SDS_DLY1_Val          0x1u   /**< \brief (PTC_CTRLB) 1 CLKPTC cycle sampling delay */
#define   PTC_CTRLB_SDS_DLY2_Val          0x2u   /**< \brief (PTC_CTRLB) 2 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY3_Val          0x3u   /**< \brief (PTC_CTRLB) 3 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY4_Val          0x4u   /**< \brief (PTC_CTRLB) 4 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY5_Val          0x5u   /**< \brief (PTC_CTRLB) 5 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY6_Val          0x6u   /**< \brief (PTC_CTRLB) 6 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY7_Val          0x7u   /**< \brief (PTC_CTRLB) 7 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY8_Val          0x8u   /**< \brief (PTC_CTRLB) 8 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY9_Val          0x9u   /**< \brief (PTC_CTRLB) 9 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY10_Val         0xAu   /**< \brief (PTC_CTRLB) 10 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY11_Val         0xBu   /**< \brief (PTC_CTRLB) 11 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY12_Val         0xCu   /**< \brief (PTC_CTRLB) 12 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY13_Val         0xDu   /**< \brief (PTC_CTRLB) 13 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY14_Val         0xEu   /**< \brief (PTC_CTRLB) 14 CLKPTC cycles sampling delay */
#define   PTC_CTRLB_SDS_DLY15_Val         0xFu   /**< \brief (PTC_CTRLB) 15 CLKPTC cycles sampling delay */
#define PTC_CTRLB_SDS_OFF           (PTC_CTRLB_SDS_OFF_Val         << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY1          (PTC_CTRLB_SDS_DLY1_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY2          (PTC_CTRLB_SDS_DLY2_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY3          (PTC_CTRLB_SDS_DLY3_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY4          (PTC_CTRLB_SDS_DLY4_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY5          (PTC_CTRLB_SDS_DLY5_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY6          (PTC_CTRLB_SDS_DLY6_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY7          (PTC_CTRLB_SDS_DLY7_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY8          (PTC_CTRLB_SDS_DLY8_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY9          (PTC_CTRLB_SDS_DLY9_Val        << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY10         (PTC_CTRLB_SDS_DLY10_Val       << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY11         (PTC_CTRLB_SDS_DLY11_Val       << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY12         (PTC_CTRLB_SDS_DLY12_Val       << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY13         (PTC_CTRLB_SDS_DLY13_Val       << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY14         (PTC_CTRLB_SDS_DLY14_Val       << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_SDS_DLY15         (PTC_CTRLB_SDS_DLY15_Val       << PTC_CTRLB_SDS_Pos)
#define PTC_CTRLB_ASDV_Pos          12           /**< \brief (PTC_CTRLB) Automatic Sampling Delay Variation */
#define PTC_CTRLB_ASDV              (0x1u << PTC_CTRLB_ASDV_Pos)
#define PTC_CTRLB_CCDS_Pos          13           /**< \brief (PTC_CTRLB) Channel Change Delay Selection */
#define PTC_CTRLB_CCDS_Msk          (0x3u << PTC_CTRLB_CCDS_Pos)
#define PTC_CTRLB_CCDS(value)       ((PTC_CTRLB_CCDS_Msk & ((value) << PTC_CTRLB_CCDS_Pos)))
#define   PTC_CTRLB_CCDS_DLY0_Val         0x0u   /**< \brief (PTC_CTRLB) 0, 0, 0 Programmable CC Delay, Pipeline Delay, Total CC Delay [CLKPTC cycles] */
#define   PTC_CTRLB_CCDS_DLY27_Val        0x1u   /**< \brief (PTC_CTRLB) 16, 11, 27 Programmable CC Delay, Pipeline Delay, Total CC Delay [CLKPTC cycles] */
#define   PTC_CTRLB_CCDS_DLY43_Val        0x2u   /**< \brief (PTC_CTRLB) 32, 11, 43 Programmable CC Delay, Pipeline Delay, Total CC Delay [CLKPTC cycles] */
#define   PTC_CTRLB_CCDS_DLY75_Val        0x3u   /**< \brief (PTC_CTRLB) 64, 11, 75 Programmable CC Delay, Pipeline Delay, Total CC Delay [CLKPTC cycles] */
#define PTC_CTRLB_CCDS_DLY0         (PTC_CTRLB_CCDS_DLY0_Val       << PTC_CTRLB_CCDS_Pos)
#define PTC_CTRLB_CCDS_DLY27        (PTC_CTRLB_CCDS_DLY27_Val      << PTC_CTRLB_CCDS_Pos)
#define PTC_CTRLB_CCDS_DLY43        (PTC_CTRLB_CCDS_DLY43_Val      << PTC_CTRLB_CCDS_Pos)
#define PTC_CTRLB_CCDS_DLY75        (PTC_CTRLB_CCDS_DLY75_Val      << PTC_CTRLB_CCDS_Pos)
#define PTC_CTRLB_ADAS_Pos          16           /**< \brief (PTC_CTRLB) ADC Accumulation Number */
#define PTC_CTRLB_ADAS_Msk          (0x7u << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS(value)       ((PTC_CTRLB_ADAS_Msk & ((value) << PTC_CTRLB_ADAS_Pos)))
#define   PTC_CTRLB_ADAS_ACC1_Val         0x0u   /**< \brief (PTC_CTRLB) 1 result accumulation */
#define   PTC_CTRLB_ADAS_ACC2_Val         0x1u   /**< \brief (PTC_CTRLB) 2 results accumulation */
#define   PTC_CTRLB_ADAS_ACC4_Val         0x2u   /**< \brief (PTC_CTRLB) 4 results accumulation */
#define   PTC_CTRLB_ADAS_ACC8_Val         0x3u   /**< \brief (PTC_CTRLB) 8 results accumulation */
#define   PTC_CTRLB_ADAS_ACC16_Val        0x4u   /**< \brief (PTC_CTRLB) 16 results accumulation */
#define   PTC_CTRLB_ADAS_ACC32_Val        0x5u   /**< \brief (PTC_CTRLB) 32 results accumulation */
#define   PTC_CTRLB_ADAS_ACC64_Val        0x6u   /**< \brief (PTC_CTRLB) 64 results accumulation */
#define PTC_CTRLB_ADAS_ACC1         (PTC_CTRLB_ADAS_ACC1_Val       << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS_ACC2         (PTC_CTRLB_ADAS_ACC2_Val       << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS_ACC4         (PTC_CTRLB_ADAS_ACC4_Val       << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS_ACC8         (PTC_CTRLB_ADAS_ACC8_Val       << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS_ACC16        (PTC_CTRLB_ADAS_ACC16_Val      << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS_ACC32        (PTC_CTRLB_ADAS_ACC32_Val      << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_ADAS_ACC64        (PTC_CTRLB_ADAS_ACC64_Val      << PTC_CTRLB_ADAS_Pos)
#define PTC_CTRLB_RSEL_Pos          20           /**< \brief (PTC_CTRLB) Resistor Selection */
#define PTC_CTRLB_RSEL_Msk          (0x3u << PTC_CTRLB_RSEL_Pos)
#define PTC_CTRLB_RSEL(value)       ((PTC_CTRLB_RSEL_Msk & ((value) << PTC_CTRLB_RSEL_Pos)))
#define   PTC_CTRLB_RSEL_OFF_Val          0x0u   /**< \brief (PTC_CTRLB) No resistor */
#define   PTC_CTRLB_RSEL_R20K_Val         0x1u   /**< \brief (PTC_CTRLB) 20 kohm */
#define   PTC_CTRLB_RSEL_R50K_Val         0x2u   /**< \brief (PTC_CTRLB) 50 kohm */
#define   PTC_CTRLB_RSEL_R100K_Val        0x3u   /**< \brief (PTC_CTRLB) 100 kohm */
#define PTC_CTRLB_RSEL_OFF          (PTC_CTRLB_RSEL_OFF_Val        << PTC_CTRLB_RSEL_Pos)
#define PTC_CTRLB_RSEL_R20K         (PTC_CTRLB_RSEL_R20K_Val       << PTC_CTRLB_RSEL_Pos)
#define PTC_CTRLB_RSEL_R50K         (PTC_CTRLB_RSEL_R50K_Val       << PTC_CTRLB_RSEL_Pos)
#define PTC_CTRLB_RSEL_R100K        (PTC_CTRLB_RSEL_R100K_Val      << PTC_CTRLB_RSEL_Pos)
#define PTC_CTRLB_MASK              0x00377F0Fu  /**< \brief (PTC_CTRLB) Register Bits Mask */

/* -------- PTC_XEN : (PTC Offset: 0x14) (R/W 16) X-Line Enable -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t XEN:16;           /*!< bit:  0..15  X-Line Enable                      */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_XEN_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_XEN_OFFSET              0x14         /**< \brief (PTC_XEN offset) X-Line Enable */
#define PTC_XEN_RESETVALUE          0x0000       /**< \brief (PTC_XEN reset_value) X-Line Enable */

#define PTC_XEN_XEN_Pos             0            /**< \brief (PTC_XEN) X-Line Enable */
#define PTC_XEN_XEN_Msk             (0xFFFFu << PTC_XEN_XEN_Pos)
#define PTC_XEN_XEN(value)          ((PTC_XEN_XEN_Msk & ((value) << PTC_XEN_XEN_Pos)))
#define PTC_XEN_MASK                0xFFFFu      /**< \brief (PTC_XEN) Register Bits Mask */

/* -------- PTC_YEN : (PTC Offset: 0x18) (R/W 32) Y-Line Enable -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t YEN:32;           /*!< bit:  0..31  Y-Line Enable                      */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_YEN_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_YEN_OFFSET              0x18         /**< \brief (PTC_YEN offset) Y-Line Enable */
#define PTC_YEN_RESETVALUE          0x00000000   /**< \brief (PTC_YEN reset_value) Y-Line Enable */

#define PTC_YEN_YEN_Pos             0            /**< \brief (PTC_YEN) Y-Line Enable */
#define PTC_YEN_YEN_Msk             (0xFFFFFFFFu << PTC_YEN_YEN_Pos)
#define PTC_YEN_YEN(value)          ((PTC_YEN_YEN_Msk & ((value) << PTC_YEN_YEN_Pos)))
#define PTC_YEN_MASK                0xFFFFFFFFu  /**< \brief (PTC_YEN) Register Bits Mask */

/* -------- PTC_SWTRIG : (PTC Offset: 0x1C) (R/W  8) Software Trigger -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  STCONV:1;         /*!< bit:      0  Start Conversion                   */
    volatile uint8_t  :7;               /*!< bit:  1.. 7  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_SWTRIG_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_SWTRIG_OFFSET           0x1C         /**< \brief (PTC_SWTRIG offset) Software Trigger */
#define PTC_SWTRIG_RESETVALUE       0x00         /**< \brief (PTC_SWTRIG reset_value) Software Trigger */

#define PTC_SWTRIG_STCONV_Pos       0            /**< \brief (PTC_SWTRIG) Start Conversion */
#define PTC_SWTRIG_STCONV           (0x1u << PTC_SWTRIG_STCONV_Pos)
#define PTC_SWTRIG_MASK             0x01u        /**< \brief (PTC_SWTRIG) Register Bits Mask */

/* -------- PTC_DSEQCTRL : (PTC Offset: 0x30) (R/W 32) DMA sequence control -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t XSEL0:1;          /*!< bit:      0  Update XSEL register               */
    volatile uint32_t ACCCTRL:1;        /*!< bit:      1  Update ACCCTRL register            */
    volatile uint32_t YSEL0:1;          /*!< bit:      2  Update YSEL lower half word register */
    volatile uint32_t YSEL1:1;          /*!< bit:      3  Update YSEL higher half word register */
    volatile uint32_t CC_CI:1;          /*!< bit:      4  Update CTRLC  register             */
    volatile uint32_t CSD:1;            /*!< bit:      5  Update CTRLC register              */
    volatile uint32_t :2;               /*!< bit:  6.. 7  Reserved                           */
    volatile uint32_t WINLT:1;          /*!< bit:      8  Update WINLT register              */
    volatile uint32_t WINHT:1;          /*!< bit:      9  Update WINHT register              */
    volatile uint32_t :21;              /*!< bit: 10..30  Reserved                           */
    volatile uint32_t AUTOSTART:1;      /*!< bit:     31  Start conv automatic               */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_DSEQCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_DSEQCTRL_OFFSET         0x30         /**< \brief (PTC_DSEQCTRL offset) DMA sequence control */
#define PTC_DSEQCTRL_RESETVALUE     0x00000000   /**< \brief (PTC_DSEQCTRL reset_value) DMA sequence control */

#define PTC_DSEQCTRL_XSEL0_Pos      0            /**< \brief (PTC_DSEQCTRL) Update XSEL register */
#define PTC_DSEQCTRL_XSEL0          (0x1u << PTC_DSEQCTRL_XSEL0_Pos)
#define PTC_DSEQCTRL_ACCCTRL_Pos    1            /**< \brief (PTC_DSEQCTRL) Update ACCCTRL register */
#define PTC_DSEQCTRL_ACCCTRL        (0x1u << PTC_DSEQCTRL_ACCCTRL_Pos)
#define PTC_DSEQCTRL_YSEL0_Pos      2            /**< \brief (PTC_DSEQCTRL) Update YSEL lower half word register */
#define PTC_DSEQCTRL_YSEL0          (0x1u << PTC_DSEQCTRL_YSEL0_Pos)
#define PTC_DSEQCTRL_YSEL1_Pos      3            /**< \brief (PTC_DSEQCTRL) Update YSEL higher half word register */
#define PTC_DSEQCTRL_YSEL1          (0x1u << PTC_DSEQCTRL_YSEL1_Pos)
#define PTC_DSEQCTRL_CC_CI_Pos      4            /**< \brief (PTC_DSEQCTRL) Update CTRLC  register */
#define PTC_DSEQCTRL_CC_CI          (0x1u << PTC_DSEQCTRL_CC_CI_Pos)
#define PTC_DSEQCTRL_CSD_Pos        5            /**< \brief (PTC_DSEQCTRL) Update CTRLC register */
#define PTC_DSEQCTRL_CSD            (0x1u << PTC_DSEQCTRL_CSD_Pos)
#define PTC_DSEQCTRL_WINLT_Pos      8            /**< \brief (PTC_DSEQCTRL) Update WINLT register */
#define PTC_DSEQCTRL_WINLT          (0x1u << PTC_DSEQCTRL_WINLT_Pos)
#define PTC_DSEQCTRL_WINHT_Pos      9            /**< \brief (PTC_DSEQCTRL) Update WINHT register */
#define PTC_DSEQCTRL_WINHT          (0x1u << PTC_DSEQCTRL_WINHT_Pos)
#define PTC_DSEQCTRL_AUTOSTART_Pos  31           /**< \brief (PTC_DSEQCTRL) Start conv automatic */
#define PTC_DSEQCTRL_AUTOSTART      (0x1u << PTC_DSEQCTRL_AUTOSTART_Pos)
#define PTC_DSEQCTRL_MASK           0x8000033Fu  /**< \brief (PTC_DSEQCTRL) Register Bits Mask */

/* -------- PTC_DSEQSTAT : (PTC Offset: 0x34) (R/  32) DMA sequence status -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t XSEL0:1;          /*!< bit:      0                                     */
    volatile uint32_t ACCCTRL:1;        /*!< bit:      1                                     */
    volatile uint32_t YSEL0:1;          /*!< bit:      2                                     */
    volatile uint32_t YSEL1:1;          /*!< bit:      3                                     */
    volatile uint32_t CC_CI:1;          /*!< bit:      4                                     */
    volatile uint32_t CSD:1;            /*!< bit:      5                                     */
    volatile uint32_t :2;               /*!< bit:  6.. 7  Reserved                           */
    volatile uint32_t WINLT:1;          /*!< bit:      8                                     */
    volatile uint32_t WINHT:1;          /*!< bit:      9                                     */
    volatile uint32_t :22;              /*!< bit: 10..31  Reserved                           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_DSEQSTAT_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_DSEQSTAT_OFFSET         0x34         /**< \brief (PTC_DSEQSTAT offset) DMA sequence status */
#define PTC_DSEQSTAT_RESETVALUE     0x00000000   /**< \brief (PTC_DSEQSTAT reset_value) DMA sequence status */

#define PTC_DSEQSTAT_XSEL0_Pos      0            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_XSEL0          (0x1u << PTC_DSEQSTAT_XSEL0_Pos)
#define PTC_DSEQSTAT_ACCCTRL_Pos    1            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_ACCCTRL        (0x1u << PTC_DSEQSTAT_ACCCTRL_Pos)
#define PTC_DSEQSTAT_YSEL0_Pos      2            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_YSEL0          (0x1u << PTC_DSEQSTAT_YSEL0_Pos)
#define PTC_DSEQSTAT_YSEL1_Pos      3            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_YSEL1          (0x1u << PTC_DSEQSTAT_YSEL1_Pos)
#define PTC_DSEQSTAT_CC_CI_Pos      4            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_CC_CI          (0x1u << PTC_DSEQSTAT_CC_CI_Pos)
#define PTC_DSEQSTAT_CSD_Pos        5            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_CSD            (0x1u << PTC_DSEQSTAT_CSD_Pos)
#define PTC_DSEQSTAT_WINLT_Pos      8            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_WINLT          (0x1u << PTC_DSEQSTAT_WINLT_Pos)
#define PTC_DSEQSTAT_WINHT_Pos      9            /**< \brief (PTC_DSEQSTAT)  */
#define PTC_DSEQSTAT_WINHT          (0x1u << PTC_DSEQSTAT_WINHT_Pos)
#define PTC_DSEQSTAT_MASK           0x0000033Fu  /**< \brief (PTC_DSEQSTAT) Register Bits Mask */

/* -------- PTC_DSEQDATA : (PTC Offset: 0x38) (R/W 32) DMA sequence data -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t DATA:32;          /*!< bit:  0..31  DMA sequence DATA                  */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_DSEQDATA_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_DSEQDATA_OFFSET         0x38         /**< \brief (PTC_DSEQDATA offset) DMA sequence data */
#define PTC_DSEQDATA_RESETVALUE     0x00000000   /**< \brief (PTC_DSEQDATA reset_value) DMA sequence data */

#define PTC_DSEQDATA_DATA_Pos       0            /**< \brief (PTC_DSEQDATA) DMA sequence DATA */
#define PTC_DSEQDATA_DATA_Msk       (0xFFFFFFFFu << PTC_DSEQDATA_DATA_Pos)
#define PTC_DSEQDATA_DATA(value)    ((PTC_DSEQDATA_DATA_Msk & ((value) << PTC_DSEQDATA_DATA_Pos)))
#define PTC_DSEQDATA_MASK           0xFFFFFFFFu  /**< \brief (PTC_DSEQDATA) Register Bits Mask */

/* -------- PTC_XSEL : (PTC Offset: 0x40) (R/W 16) X-Line Selection -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t XSEL:16;          /*!< bit:  0..15  X-Line Selection                   */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_XSEL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_XSEL_OFFSET             0x40         /**< \brief (PTC_XSEL offset) X-Line Selection */
#define PTC_XSEL_RESETVALUE         0x0000       /**< \brief (PTC_XSEL reset_value) X-Line Selection */

#define PTC_XSEL_XSEL_Pos           0            /**< \brief (PTC_XSEL) X-Line Selection */
#define PTC_XSEL_XSEL_Msk           (0xFFFFu << PTC_XSEL_XSEL_Pos)
#define PTC_XSEL_XSEL(value)        ((PTC_XSEL_XSEL_Msk & ((value) << PTC_XSEL_XSEL_Pos)))
#define PTC_XSEL_MASK               0xFFFFu      /**< \brief (PTC_XSEL) Register Bits Mask */

/* -------- PTC_ACCCTRL : (PTC Offset: 0x43) (R/W  8)  -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint8_t  ADAS:3;           /*!< bit:  0.. 2  ADC Accumulation Number            */
    volatile uint8_t  :4;               /*!< bit:  3.. 6  Reserved                           */
    volatile uint8_t  LAST:1;           /*!< bit:      7  Last conversion request            */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint8_t reg;                 /*!< Type      used for register access              */
} PTC_ACCCTRL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_ACCCTRL_OFFSET          0x43         /**< \brief (PTC_ACCCTRL offset)  */
#define PTC_ACCCTRL_RESETVALUE      0x00         /**< \brief (PTC_ACCCTRL reset_value)  */

#define PTC_ACCCTRL_ADAS_Pos        0            /**< \brief (PTC_ACCCTRL) ADC Accumulation Number */
#define PTC_ACCCTRL_ADAS_Msk        (0x7u << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS(value)     ((PTC_ACCCTRL_ADAS_Msk & ((value) << PTC_ACCCTRL_ADAS_Pos)))
#define   PTC_ACCCTRL_ADAS_ACC1_Val       0x0u   /**< \brief (PTC_ACCCTRL) 1 result accumulation */
#define   PTC_ACCCTRL_ADAS_ACC2_Val       0x1u   /**< \brief (PTC_ACCCTRL) 2 result accumulation */
#define   PTC_ACCCTRL_ADAS_ACC4_Val       0x2u   /**< \brief (PTC_ACCCTRL) 4 result accumulation */
#define   PTC_ACCCTRL_ADAS_ACC8_Val       0x3u   /**< \brief (PTC_ACCCTRL) 8 result accumulation */
#define   PTC_ACCCTRL_ADAS_ACC16_Val      0x4u   /**< \brief (PTC_ACCCTRL) 16 result accumulation */
#define   PTC_ACCCTRL_ADAS_ACC32_Val      0x5u   /**< \brief (PTC_ACCCTRL) 32 result accumulation */
#define   PTC_ACCCTRL_ADAS_ACC64_Val      0x6u   /**< \brief (PTC_ACCCTRL) 64 result accumulation */
#define PTC_ACCCTRL_ADAS_ACC1       (PTC_ACCCTRL_ADAS_ACC1_Val     << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS_ACC2       (PTC_ACCCTRL_ADAS_ACC2_Val     << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS_ACC4       (PTC_ACCCTRL_ADAS_ACC4_Val     << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS_ACC8       (PTC_ACCCTRL_ADAS_ACC8_Val     << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS_ACC16      (PTC_ACCCTRL_ADAS_ACC16_Val    << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS_ACC32      (PTC_ACCCTRL_ADAS_ACC32_Val    << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_ADAS_ACC64      (PTC_ACCCTRL_ADAS_ACC64_Val    << PTC_ACCCTRL_ADAS_Pos)
#define PTC_ACCCTRL_LAST_Pos        7            /**< \brief (PTC_ACCCTRL) Last conversion request */
#define PTC_ACCCTRL_LAST            (0x1u << PTC_ACCCTRL_LAST_Pos)
#define PTC_ACCCTRL_MASK            0x87u        /**< \brief (PTC_ACCCTRL) Register Bits Mask */

/* -------- PTC_YSEL : (PTC Offset: 0x44) (R/W 32) Y-Line Selection -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t YSEL:32;          /*!< bit:  0..31  Y-Line Selection                   */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_YSEL_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_YSEL_OFFSET             0x44         /**< \brief (PTC_YSEL offset) Y-Line Selection */
#define PTC_YSEL_RESETVALUE         0x00000000   /**< \brief (PTC_YSEL reset_value) Y-Line Selection */

#define PTC_YSEL_YSEL_Pos           0            /**< \brief (PTC_YSEL) Y-Line Selection */
#define PTC_YSEL_YSEL_Msk           (0xFFFFFFFFu << PTC_YSEL_YSEL_Pos)
#define PTC_YSEL_YSEL(value)        ((PTC_YSEL_YSEL_Msk & ((value) << PTC_YSEL_YSEL_Pos)))
#define PTC_YSEL_MASK               0xFFFFFFFFu  /**< \brief (PTC_YSEL) Register Bits Mask */

/* -------- PTC_CTRLC : (PTC Offset: 0x48) (R/W 32) Control C -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint32_t CCA:4;            /*!< bit:  0.. 3  Compensation Capacitor Accurate Value */
    volatile uint32_t CCF:4;            /*!< bit:  4.. 7  Compensation Capacitor Fine Value  */
    volatile uint32_t CCC:4;            /*!< bit:  8..11  Compensation Capacitor Coarse Value */
    volatile uint32_t CCR:2;            /*!< bit: 12..13  Compensation Capacitor Rough Value */
    volatile uint32_t :2;               /*!< bit: 14..15  Reserved                           */
    volatile uint32_t CIF:4;            /*!< bit: 16..19  Integration Capacitor Coarse Value */
    volatile uint32_t CIC:2;            /*!< bit: 20..21  Integration Capacitor Fine Value   */
    volatile uint32_t :2;               /*!< bit: 22..23  Reserved                           */
    volatile uint32_t CSD:8;            /*!< bit: 24..31  Charge Share Delay Value           */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint32_t reg;                /*!< Type      used for register access              */
} PTC_CTRLC_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_CTRLC_OFFSET            0x48         /**< \brief (PTC_CTRLC offset) Control C */
#define PTC_CTRLC_RESETVALUE        0x00000000   /**< \brief (PTC_CTRLC reset_value) Control C */

#define PTC_CTRLC_CCA_Pos           0            /**< \brief (PTC_CTRLC) Compensation Capacitor Accurate Value */
#define PTC_CTRLC_CCA_Msk           (0xFu << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA(value)        ((PTC_CTRLC_CCA_Msk & ((value) << PTC_CTRLC_CCA_Pos)))
#define   PTC_CTRLC_CCA_0_Val             0x0u   /**< \brief (PTC_CTRLC) 0 */
#define   PTC_CTRLC_CCA_1_Val             0x1u   /**< \brief (PTC_CTRLC) 0.00675 */
#define   PTC_CTRLC_CCA_2_Val             0x2u   /**< \brief (PTC_CTRLC) 0.01350 */
#define   PTC_CTRLC_CCA_3_Val             0x3u   /**< \brief (PTC_CTRLC) 0.02025 */
#define   PTC_CTRLC_CCA_4_Val             0x4u   /**< \brief (PTC_CTRLC) 0.02700 */
#define   PTC_CTRLC_CCA_5_Val             0x5u   /**< \brief (PTC_CTRLC) 0.03375 */
#define   PTC_CTRLC_CCA_6_Val             0x6u   /**< \brief (PTC_CTRLC) 0.04050 */
#define   PTC_CTRLC_CCA_7_Val             0x7u   /**< \brief (PTC_CTRLC) 0.04725 */
#define   PTC_CTRLC_CCA_8_Val             0x8u   /**< \brief (PTC_CTRLC) 0.05400 */
#define   PTC_CTRLC_CCA_9_Val             0x9u   /**< \brief (PTC_CTRLC) 0.06075 */
#define   PTC_CTRLC_CCA_10_Val            0xAu   /**< \brief (PTC_CTRLC) 0.06750 */
#define   PTC_CTRLC_CCA_11_Val            0xBu   /**< \brief (PTC_CTRLC) 0.07425 */
#define   PTC_CTRLC_CCA_12_Val            0xCu   /**< \brief (PTC_CTRLC) 0.08100 */
#define   PTC_CTRLC_CCA_13_Val            0xDu   /**< \brief (PTC_CTRLC) 0.08775 */
#define   PTC_CTRLC_CCA_14_Val            0xEu   /**< \brief (PTC_CTRLC) 0.09450 */
#define   PTC_CTRLC_CCA_15_Val            0xFu   /**< \brief (PTC_CTRLC) 0.10125 */
#define PTC_CTRLC_CCA_0             (PTC_CTRLC_CCA_0_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_1             (PTC_CTRLC_CCA_1_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_2             (PTC_CTRLC_CCA_2_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_3             (PTC_CTRLC_CCA_3_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_4             (PTC_CTRLC_CCA_4_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_5             (PTC_CTRLC_CCA_5_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_6             (PTC_CTRLC_CCA_6_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_7             (PTC_CTRLC_CCA_7_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_8             (PTC_CTRLC_CCA_8_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_9             (PTC_CTRLC_CCA_9_Val           << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_10            (PTC_CTRLC_CCA_10_Val          << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_11            (PTC_CTRLC_CCA_11_Val          << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_12            (PTC_CTRLC_CCA_12_Val          << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_13            (PTC_CTRLC_CCA_13_Val          << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_14            (PTC_CTRLC_CCA_14_Val          << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCA_15            (PTC_CTRLC_CCA_15_Val          << PTC_CTRLC_CCA_Pos)
#define PTC_CTRLC_CCF_Pos           4            /**< \brief (PTC_CTRLC) Compensation Capacitor Fine Value */
#define PTC_CTRLC_CCF_Msk           (0xFu << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF(value)        ((PTC_CTRLC_CCF_Msk & ((value) << PTC_CTRLC_CCF_Pos)))
#define   PTC_CTRLC_CCF_0_Val             0x0u   /**< \brief (PTC_CTRLC) 0 */
#define   PTC_CTRLC_CCF_1_Val             0x1u   /**< \brief (PTC_CTRLC) 0.0675 */
#define   PTC_CTRLC_CCF_2_Val             0x2u   /**< \brief (PTC_CTRLC) 0.1350 */
#define   PTC_CTRLC_CCF_3_Val             0x3u   /**< \brief (PTC_CTRLC) 0.2025 */
#define   PTC_CTRLC_CCF_4_Val             0x4u   /**< \brief (PTC_CTRLC) 0.2700 */
#define   PTC_CTRLC_CCF_5_Val             0x5u   /**< \brief (PTC_CTRLC) 0.3375 */
#define   PTC_CTRLC_CCF_6_Val             0x6u   /**< \brief (PTC_CTRLC) 0.4050 */
#define   PTC_CTRLC_CCF_7_Val             0x7u   /**< \brief (PTC_CTRLC) 0.4725 */
#define   PTC_CTRLC_CCF_8_Val             0x8u   /**< \brief (PTC_CTRLC) 0.5400 */
#define   PTC_CTRLC_CCF_9_Val             0x9u   /**< \brief (PTC_CTRLC) 0.6075 */
#define   PTC_CTRLC_CCF_10_Val            0xAu   /**< \brief (PTC_CTRLC) 0.6750 */
#define   PTC_CTRLC_CCF_11_Val            0xBu   /**< \brief (PTC_CTRLC) 0.7425 */
#define   PTC_CTRLC_CCF_12_Val            0xCu   /**< \brief (PTC_CTRLC) 0.8100 */
#define   PTC_CTRLC_CCF_13_Val            0xDu   /**< \brief (PTC_CTRLC) 0.8775 */
#define   PTC_CTRLC_CCF_14_Val            0xEu   /**< \brief (PTC_CTRLC) 0.9450 */
#define   PTC_CTRLC_CCF_15_Val            0xFu   /**< \brief (PTC_CTRLC) 1.0125 */
#define PTC_CTRLC_CCF_0             (PTC_CTRLC_CCF_0_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_1             (PTC_CTRLC_CCF_1_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_2             (PTC_CTRLC_CCF_2_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_3             (PTC_CTRLC_CCF_3_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_4             (PTC_CTRLC_CCF_4_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_5             (PTC_CTRLC_CCF_5_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_6             (PTC_CTRLC_CCF_6_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_7             (PTC_CTRLC_CCF_7_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_8             (PTC_CTRLC_CCF_8_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_9             (PTC_CTRLC_CCF_9_Val           << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_10            (PTC_CTRLC_CCF_10_Val          << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_11            (PTC_CTRLC_CCF_11_Val          << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_12            (PTC_CTRLC_CCF_12_Val          << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_13            (PTC_CTRLC_CCF_13_Val          << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_14            (PTC_CTRLC_CCF_14_Val          << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCF_15            (PTC_CTRLC_CCF_15_Val          << PTC_CTRLC_CCF_Pos)
#define PTC_CTRLC_CCC_Pos           8            /**< \brief (PTC_CTRLC) Compensation Capacitor Coarse Value */
#define PTC_CTRLC_CCC_Msk           (0xFu << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC(value)        ((PTC_CTRLC_CCC_Msk & ((value) << PTC_CTRLC_CCC_Pos)))
#define   PTC_CTRLC_CCC_0_Val             0x0u   /**< \brief (PTC_CTRLC) 0 */
#define   PTC_CTRLC_CCC_1_Val             0x1u   /**< \brief (PTC_CTRLC) 0.675 */
#define   PTC_CTRLC_CCC_2_Val             0x2u   /**< \brief (PTC_CTRLC) 1.350 */
#define   PTC_CTRLC_CCC_3_Val             0x3u   /**< \brief (PTC_CTRLC) 2.025 */
#define   PTC_CTRLC_CCC_4_Val             0x4u   /**< \brief (PTC_CTRLC) 2.700 */
#define   PTC_CTRLC_CCC_5_Val             0x5u   /**< \brief (PTC_CTRLC) 3.375 */
#define   PTC_CTRLC_CCC_6_Val             0x6u   /**< \brief (PTC_CTRLC) 4.050 */
#define   PTC_CTRLC_CCC_7_Val             0x7u   /**< \brief (PTC_CTRLC) 4.725 */
#define   PTC_CTRLC_CCC_8_Val             0x8u   /**< \brief (PTC_CTRLC) 5.400 */
#define   PTC_CTRLC_CCC_9_Val             0x9u   /**< \brief (PTC_CTRLC) 6.075 */
#define   PTC_CTRLC_CCC_10_Val            0xAu   /**< \brief (PTC_CTRLC) 6.750 */
#define   PTC_CTRLC_CCC_11_Val            0xBu   /**< \brief (PTC_CTRLC) 7.425 */
#define   PTC_CTRLC_CCC_12_Val            0xCu   /**< \brief (PTC_CTRLC) 8.100 */
#define   PTC_CTRLC_CCC_13_Val            0xDu   /**< \brief (PTC_CTRLC) 8.775 */
#define   PTC_CTRLC_CCC_14_Val            0xEu   /**< \brief (PTC_CTRLC) 9.450 */
#define   PTC_CTRLC_CCC_15_Val            0xFu   /**< \brief (PTC_CTRLC) 10.125 */
#define PTC_CTRLC_CCC_0             (PTC_CTRLC_CCC_0_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_1             (PTC_CTRLC_CCC_1_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_2             (PTC_CTRLC_CCC_2_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_3             (PTC_CTRLC_CCC_3_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_4             (PTC_CTRLC_CCC_4_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_5             (PTC_CTRLC_CCC_5_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_6             (PTC_CTRLC_CCC_6_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_7             (PTC_CTRLC_CCC_7_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_8             (PTC_CTRLC_CCC_8_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_9             (PTC_CTRLC_CCC_9_Val           << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_10            (PTC_CTRLC_CCC_10_Val          << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_11            (PTC_CTRLC_CCC_11_Val          << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_12            (PTC_CTRLC_CCC_12_Val          << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_13            (PTC_CTRLC_CCC_13_Val          << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_14            (PTC_CTRLC_CCC_14_Val          << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCC_15            (PTC_CTRLC_CCC_15_Val          << PTC_CTRLC_CCC_Pos)
#define PTC_CTRLC_CCR_Pos           12           /**< \brief (PTC_CTRLC) Compensation Capacitor Rough Value */
#define PTC_CTRLC_CCR_Msk           (0x3u << PTC_CTRLC_CCR_Pos)
#define PTC_CTRLC_CCR(value)        ((PTC_CTRLC_CCR_Msk & ((value) << PTC_CTRLC_CCR_Pos)))
#define   PTC_CTRLC_CCR_0_Val             0x0u   /**< \brief (PTC_CTRLC) 0 */
#define   PTC_CTRLC_CCR_1_Val             0x1u   /**< \brief (PTC_CTRLC) 6.75 */
#define   PTC_CTRLC_CCR_2_Val             0x2u   /**< \brief (PTC_CTRLC) 13.5 */
#define   PTC_CTRLC_CCR_3_Val             0x3u   /**< \brief (PTC_CTRLC) 21.25 */
#define PTC_CTRLC_CCR_0             (PTC_CTRLC_CCR_0_Val           << PTC_CTRLC_CCR_Pos)
#define PTC_CTRLC_CCR_1             (PTC_CTRLC_CCR_1_Val           << PTC_CTRLC_CCR_Pos)
#define PTC_CTRLC_CCR_2             (PTC_CTRLC_CCR_2_Val           << PTC_CTRLC_CCR_Pos)
#define PTC_CTRLC_CCR_3             (PTC_CTRLC_CCR_3_Val           << PTC_CTRLC_CCR_Pos)
#define PTC_CTRLC_CIF_Pos           16           /**< \brief (PTC_CTRLC) Integration Capacitor Coarse Value */
#define PTC_CTRLC_CIF_Msk           (0xFu << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF(value)        ((PTC_CTRLC_CIF_Msk & ((value) << PTC_CTRLC_CIF_Pos)))
#define   PTC_CTRLC_CIF_0_Val             0x0u   /**< \brief (PTC_CTRLC) 0 */
#define   PTC_CTRLC_CIF_1_Val             0x1u   /**< \brief (PTC_CTRLC) 0.675 */
#define   PTC_CTRLC_CIF_2_Val             0x2u   /**< \brief (PTC_CTRLC) 1.350 */
#define   PTC_CTRLC_CIF_3_Val             0x3u   /**< \brief (PTC_CTRLC) 2.025 */
#define   PTC_CTRLC_CIF_4_Val             0x4u   /**< \brief (PTC_CTRLC) 2.700 */
#define   PTC_CTRLC_CIF_5_Val             0x5u   /**< \brief (PTC_CTRLC) 3.375 */
#define   PTC_CTRLC_CIF_6_Val             0x6u   /**< \brief (PTC_CTRLC) 4.050 */
#define   PTC_CTRLC_CIF_7_Val             0x7u   /**< \brief (PTC_CTRLC) 4.725 */
#define   PTC_CTRLC_CIF_8_Val             0x8u   /**< \brief (PTC_CTRLC) 5.400 */
#define   PTC_CTRLC_CIF_9_Val             0x9u   /**< \brief (PTC_CTRLC) 6.075 */
#define   PTC_CTRLC_CIF_10_Val            0xAu   /**< \brief (PTC_CTRLC) 6.750 */
#define   PTC_CTRLC_CIF_11_Val            0xBu   /**< \brief (PTC_CTRLC) 7.425 */
#define   PTC_CTRLC_CIF_12_Val            0xCu   /**< \brief (PTC_CTRLC) 8.100 */
#define   PTC_CTRLC_CIF_13_Val            0xDu   /**< \brief (PTC_CTRLC) 8.775 */
#define   PTC_CTRLC_CIF_14_Val            0xEu   /**< \brief (PTC_CTRLC) 9.450 */
#define   PTC_CTRLC_CIF_15_Val            0xFu   /**< \brief (PTC_CTRLC) 10.125 */
#define PTC_CTRLC_CIF_0             (PTC_CTRLC_CIF_0_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_1             (PTC_CTRLC_CIF_1_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_2             (PTC_CTRLC_CIF_2_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_3             (PTC_CTRLC_CIF_3_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_4             (PTC_CTRLC_CIF_4_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_5             (PTC_CTRLC_CIF_5_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_6             (PTC_CTRLC_CIF_6_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_7             (PTC_CTRLC_CIF_7_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_8             (PTC_CTRLC_CIF_8_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_9             (PTC_CTRLC_CIF_9_Val           << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_10            (PTC_CTRLC_CIF_10_Val          << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_11            (PTC_CTRLC_CIF_11_Val          << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_12            (PTC_CTRLC_CIF_12_Val          << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_13            (PTC_CTRLC_CIF_13_Val          << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_14            (PTC_CTRLC_CIF_14_Val          << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIF_15            (PTC_CTRLC_CIF_15_Val          << PTC_CTRLC_CIF_Pos)
#define PTC_CTRLC_CIC_Pos           20           /**< \brief (PTC_CTRLC) Integration Capacitor Fine Value */
#define PTC_CTRLC_CIC_Msk           (0x3u << PTC_CTRLC_CIC_Pos)
#define PTC_CTRLC_CIC(value)        ((PTC_CTRLC_CIC_Msk & ((value) << PTC_CTRLC_CIC_Pos)))
#define   PTC_CTRLC_CIC_0_Val             0x0u   /**< \brief (PTC_CTRLC) 0 */
#define   PTC_CTRLC_CIC_1_Val             0x1u   /**< \brief (PTC_CTRLC) 6.75 */
#define   PTC_CTRLC_CIC_2_Val             0x2u   /**< \brief (PTC_CTRLC) 13.5 */
#define   PTC_CTRLC_CIC_3_Val             0x3u   /**< \brief (PTC_CTRLC) 21.25 */
#define PTC_CTRLC_CIC_0             (PTC_CTRLC_CIC_0_Val           << PTC_CTRLC_CIC_Pos)
#define PTC_CTRLC_CIC_1             (PTC_CTRLC_CIC_1_Val           << PTC_CTRLC_CIC_Pos)
#define PTC_CTRLC_CIC_2             (PTC_CTRLC_CIC_2_Val           << PTC_CTRLC_CIC_Pos)
#define PTC_CTRLC_CIC_3             (PTC_CTRLC_CIC_3_Val           << PTC_CTRLC_CIC_Pos)
#define PTC_CTRLC_CSD_Pos           24           /**< \brief (PTC_CTRLC) Charge Share Delay Value */
#define PTC_CTRLC_CSD_Msk           (0xFFu << PTC_CTRLC_CSD_Pos)
#define PTC_CTRLC_CSD(value)        ((PTC_CTRLC_CSD_Msk & ((value) << PTC_CTRLC_CSD_Pos)))
#define PTC_CTRLC_MASK              0xFF3F3FFFu  /**< \brief (PTC_CTRLC) Register Bits Mask */

/* -------- PTC_WINLT : (PTC Offset: 0x50) (R/W 16) Window Comparator Low Threshold -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t WCLT:16;          /*!< bit:  0..15  Window Comparator Low Threshold Register */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_WINLT_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_WINLT_OFFSET            0x50         /**< \brief (PTC_WINLT offset) Window Comparator Low Threshold */
#define PTC_WINLT_RESETVALUE        0x0000       /**< \brief (PTC_WINLT reset_value) Window Comparator Low Threshold */

#define PTC_WINLT_WCLT_Pos          0            /**< \brief (PTC_WINLT) Window Comparator Low Threshold Register */
#define PTC_WINLT_WCLT_Msk          (0xFFFFu << PTC_WINLT_WCLT_Pos)
#define PTC_WINLT_WCLT(value)       ((PTC_WINLT_WCLT_Msk & ((value) << PTC_WINLT_WCLT_Pos)))
#define PTC_WINLT_MASK              0xFFFFu      /**< \brief (PTC_WINLT) Register Bits Mask */

/* -------- PTC_WINHT : (PTC Offset: 0x52) (R/W 16) Window Comparator High Threshold -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t WCHT:16;          /*!< bit:  0..15  Window Comparator High Threshold Register */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_WINHT_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_WINHT_OFFSET            0x52         /**< \brief (PTC_WINHT offset) Window Comparator High Threshold */
#define PTC_WINHT_RESETVALUE        0x0000       /**< \brief (PTC_WINHT reset_value) Window Comparator High Threshold */

#define PTC_WINHT_WCHT_Pos          0            /**< \brief (PTC_WINHT) Window Comparator High Threshold Register */
#define PTC_WINHT_WCHT_Msk          (0xFFFFu << PTC_WINHT_WCHT_Pos)
#define PTC_WINHT_WCHT(value)       ((PTC_WINHT_WCHT_Msk & ((value) << PTC_WINHT_WCHT_Pos)))
#define PTC_WINHT_MASK              0xFFFFu      /**< \brief (PTC_WINHT) Register Bits Mask */

/* -------- PTC_RES : (PTC Offset: 0x58) (R/  16) ADC/Accumulator Result Data Register -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t RES:16;           /*!< bit:  0..15  ADC/Accumulator Result Data Register */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_RES_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_RES_OFFSET              0x58         /**< \brief (PTC_RES offset) ADC/Accumulator Result Data Register */
#define PTC_RES_RESETVALUE          0x0000       /**< \brief (PTC_RES reset_value) ADC/Accumulator Result Data Register */

#define PTC_RES_RES_Pos             0            /**< \brief (PTC_RES) ADC/Accumulator Result Data Register */
#define PTC_RES_RES_Msk             (0xFFFFu << PTC_RES_RES_Pos)
#define PTC_RES_RES(value)          ((PTC_RES_RES_Msk & ((value) << PTC_RES_RES_Pos)))
#define PTC_RES_MASK                0xFFFFu      /**< \brief (PTC_RES) Register Bits Mask */

/* -------- PTC_RESS : (PTC Offset: 0x5C) (R/  16) Last ADC conversion result -------- */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef union {
  struct {
    volatile uint16_t RESS:16;          /*!< bit:  0..15  Last ADC conversion result         */
  } bit;                       /*!< Structure used for bit  access                  */
  volatile uint16_t reg;                /*!< Type      used for register access              */
} PTC_RESS_Type;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */

#define PTC_RESS_OFFSET             0x5C         /**< \brief (PTC_RESS offset) Last ADC conversion result */
#define PTC_RESS_RESETVALUE         0x0000       /**< \brief (PTC_RESS reset_value) Last ADC conversion result */

#define PTC_RESS_RESS_Pos           0            /**< \brief (PTC_RESS) Last ADC conversion result */
#define PTC_RESS_RESS_Msk           (0xFFFFu << PTC_RESS_RESS_Pos)
#define PTC_RESS_RESS(value)        ((PTC_RESS_RESS_Msk & ((value) << PTC_RESS_RESS_Pos)))
#define PTC_RESS_MASK               0xFFFFu      /**< \brief (PTC_RESS) Register Bits Mask */

/** \brief PTC hardware registers */
#if !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__))
typedef struct {
  __IO PTC_CTRLA_Type            CTRLA;       /**< \brief Offset: 0x00 (R/W 16) Control A */
       RoReg8                    Reserved1[0x2];
  __IO PTC_EVCTRL_Type           EVCTRL;      /**< \brief Offset: 0x04 (R/W  8) Event Control */
  __IO PTC_WINCTRL_Type          WINCTRL;     /**< \brief Offset: 0x05 (R/W  8) Window Comparator Control */
       RoReg8                    Reserved2[0x2];
  __IO PTC_INTENCLR_Type         INTENCLR;    /**< \brief Offset: 0x08 (R/W  8) Interrupt Enable Clear */
  __IO PTC_INTENSET_Type         INTENSET;    /**< \brief Offset: 0x09 (R/W  8) Interrupt Enable Set */
  __IO PTC_INTFLAG_Type          INTFLAG;     /**< \brief Offset: 0x0A (R/W  8) Interrupt Flag Status and Clear */
  __I  PTC_STATUS_Type           STATUS;      /**< \brief Offset: 0x0B (R/   8) Status */
  __I  PTC_SYNCBUSY_Type         SYNCBUSY;    /**< \brief Offset: 0x0C (R/  16) Synchronisation Busy */
       RoReg8                    Reserved3[0x2];
  __IO PTC_CTRLB_Type            CTRLB;       /**< \brief Offset: 0x10 (R/W 32) Control B */
  __IO PTC_XEN_Type              XEN;         /**< \brief Offset: 0x14 (R/W 16) X-Line Enable */
       RoReg8                    Reserved4[0x2];
  __IO PTC_YEN_Type              YEN;         /**< \brief Offset: 0x18 (R/W 32) Y-Line Enable */
  __IO PTC_SWTRIG_Type           SWTRIG;      /**< \brief Offset: 0x1C (R/W  8) Software Trigger */
       RoReg8                    Reserved5[0x13];
  __IO PTC_DSEQCTRL_Type         DSEQCTRL;    /**< \brief Offset: 0x30 (R/W 32) DMA sequence control */
  __I  PTC_DSEQSTAT_Type         DSEQSTAT;    /**< \brief Offset: 0x34 (R/  32) DMA sequence status */
  __IO PTC_DSEQDATA_Type         DSEQDATA;    /**< \brief Offset: 0x38 (R/W 32) DMA sequence data */
       RoReg8                    Reserved6[0x4];
  __IO PTC_XSEL_Type             XSEL;        /**< \brief Offset: 0x40 (R/W 16) X-Line Selection */
       RoReg8                    Reserved7[0x1];
  __IO PTC_ACCCTRL_Type          ACCCTRL;     /**< \brief Offset: 0x43 (R/W  8)  */
  __IO PTC_YSEL_Type             YSEL;        /**< \brief Offset: 0x44 (R/W 32) Y-Line Selection */
  __IO PTC_CTRLC_Type            CTRLC;       /**< \brief Offset: 0x48 (R/W 32) Control C */
       RoReg8                    Reserved8[0x4];
  __IO PTC_WINLT_Type            WINLT;       /**< \brief Offset: 0x50 (R/W 16) Window Comparator Low Threshold */
  __IO PTC_WINHT_Type            WINHT;       /**< \brief Offset: 0x52 (R/W 16) Window Comparator High Threshold */
       RoReg8                    Reserved9[0x4];
  __I  PTC_RES_Type              RES;         /**< \brief Offset: 0x58 (R/  16) ADC/Accumulator Result Data Register */
       RoReg8                    Reserved10[0x2];
  __I  PTC_RESS_Type             RESS;        /**< \brief Offset: 0x5C (R/  16) Last ADC conversion result */
} Ptc;
#endif /* !(defined(__ASSEMBLY__) || defined(__IAR_SYSTEMS_ASM__)) */


#endif //_PTC_H