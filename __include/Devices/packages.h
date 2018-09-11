#ifndef _PACKAGES_H
#define _PACKAGES_H



//---- Packages ----------------------------------------------------------------
#define _QFP48_    (1048)
#define _QFP64_    (1064)
#define _QFP100_   (1100)
#define _QFP128_   (1128)
#define _QFP144_   (1144)
#define _QFP176_   (1176)
#define _QFN48_    (2048)
#define _QFN64_    (2064)
#define _BGA96_    (3096)
#define _BGA100_   (3100)
#define _BGA144_   (3144)
#define _BGA176_   (3176)
#define _BGA196_   (3196)
#define _BGA228_   (3228)    /* MNN added for SAM9X6*/
#define _BGA256_   (3256)
#define _BGA289_   (3289)
#define _BGA324_   (3324)
#define _BGA361_   (3361)

#define _TFBGA100_ (4100)
#define _TFBGA144_ (4144)
#define _TFBGA176_ (4176)

#define _UFBGA144_ (5144)

#define _VFBGA100_ (6100)



//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
#if   (DEVICE_PACKAGE == _QFP48_)
  #define _DEVICE_PIN_COUNT_ (48)
#elif (DEVICE_PACKAGE == _QFP64_)
  #define _DEVICE_PIN_COUNT_ (64)
#elif (DEVICE_PACKAGE == _QFP100_)
  #define _DEVICE_PIN_COUNT_ (100)
#elif (DEVICE_PACKAGE == _QFP128_)
  #define _DEVICE_PIN_COUNT_ (128)
#elif (DEVICE_PACKAGE == _QFP144_)
  #define _DEVICE_PIN_COUNT_ (144)
#elif (DEVICE_PACKAGE == _QFP176_)
  #define _DEVICE_PIN_COUNT_ (176)
#elif (DEVICE_PACKAGE == _QFN48_)
  #define _DEVICE_PIN_COUNT_ (48)
#elif (DEVICE_PACKAGE == _QFN64_)
  #define _DEVICE_PIN_COUNT_ (64)
#elif (DEVICE_PACKAGE == _BGA96_)
  #define _DEVICE_PIN_COUNT_ (96)
#elif (DEVICE_PACKAGE == _BGA100_)
  #define _DEVICE_PIN_COUNT_ (100)
#elif (DEVICE_PACKAGE == _BGA144_)
  #define _DEVICE_PIN_COUNT_ (144)
#elif (DEVICE_PACKAGE == _BGA176_)
  #define _DEVICE_PIN_COUNT_ (176)
#elif (DEVICE_PACKAGE == _BGA196_)
  #define _DEVICE_PIN_COUNT_ (196)
/* MNN added for SAM9X6*/
#elif (DEVICE_PACKAGE == _BGA228_)
  #define _DEVICE_PIN_COUNT_ (228)

#elif (DEVICE_PACKAGE == _BGA256_)
  #define _DEVICE_PIN_COUNT_ (256)
#elif (DEVICE_PACKAGE == _BGA289_)
  #define _DEVICE_PIN_COUNT_ (289)
#elif (DEVICE_PACKAGE == _BGA324_)
  #define _DEVICE_PIN_COUNT_ (324)
#elif (DEVICE_PACKAGE == _BGA361_)
  #define _DEVICE_PIN_COUNT_ (361)
  
#elif (DEVICE_PACKAGE == _TFBGA176_)
  #define _DEVICE_PIN_COUNT_ (176)
#elif (DEVICE_PACKAGE == _TFBGA144_)
  #define _DEVICE_PIN_COUNT_ (144)
#elif (DEVICE_PACKAGE == _TFBGA100_)
  #define _DEVICE_PIN_COUNT_ (100)

#elif (DEVICE_PACKAGE == _UFBGA144_)
  #define _DEVICE_PIN_COUNT_ (144)

#elif (DEVICE_PACKAGE == _VFBGA100_)
  #define _DEVICE_PIN_COUNT_ (100)


/*
define _TFBGA100_ (4100)
#define _TFBGA144_ (4144)
#define _TFBGA176_ (4176)

#define _UFBGA144_ (5144)

#define _VFBGA100_ (6100)
*/







#else
  #error Library does not support the specified package
#endif
//------------------------------------------------------------------------------





#endif //_PACKAGES_H
