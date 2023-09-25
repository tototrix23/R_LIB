#ifndef C_TYPEDEFS_H
#define C_TYPEDEFS_H

#include <_config_compiler/config.h>
#include "_target/t_targets.h"

#ifndef FALSE
#define FALSE              0
#endif
#ifndef TRUE
#define TRUE               1
#endif
#ifndef NULL
#define NULL               0
#endif

#if TARGET == TARGET_RENESAS_RAM4
typedef unsigned char       bool_t;
typedef signed short        return_t;
typedef __INT8_TYPE__       int8_t ;
typedef __UINT8_TYPE__      uint8_t;
typedef __INT16_TYPE__      int16_t ;
typedef __UINT16_TYPE__     uint16_t;
typedef __INT32_TYPE__      int32_t ;
typedef __UINT32_TYPE__     uint32_t;
typedef __INT64_TYPE__      int64_t ;
typedef __UINT64_TYPE__     uint64_t;
typedef __INTMAX_TYPE__     intmax_t;
typedef __UINTMAX_TYPE__    uintmax_t;
typedef __SIZE_TYPE__       size_t;
typedef float               float_t;

#else
#error Error with 'Typedefs',TARGET is not defined.See targets.h for complete list
#endif

#endif
