/*
 * c_error.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_ERROR_H_
#define CORE_C_ERROR_H_

#include <_config_compiler/config.h>
#include "_core/c_typedefs.h"
#include "_core/c_return_codes.h"
#include "_core/c_error/c_error.h"
#include "_core/c_log.h"


#define RLIB_ERROR_RETURN(a, code)                                    \
    {                                                                 \
        if ((a))                                                      \
        {                                                             \
            (void) 0;                  /* Do nothing */               \
        }                                                             \
        else                                                          \
        {                                                             \
        	LOG_E(LOG_STD,"ERROR %d",code);                           \
            return code;                                              \
        }                                                             \
    }

#if (R_LIB_ASSERT_MODE == R_LIB_ASSERT_RETURN_CODE)
#define RLIB_ERROR_ASSERT(a)                                          \
    {                                                                 \
        if ((a))                                                      \
        {                                                             \
            (void) 0;                  /* Do nothing */               \
        }                                                             \
        else                                                          \
        {                                                             \
            LOG_E(LOG_STD,"ERROR %d",X_RET_ASSERTION);                \
            return X_RET_ASSERTION;                                   \
        }                                                             \
    }
#elif (R_LIB_ASSERT_MODE == R_LIB_ASSERT_WHILE)
#define RLIB_ERROR_ASSERT(a)                                          \
    {                                                                 \
        if ((a))                                                      \
        {                                                             \
            (void) 0;                  /* Do nothing */               \
        }                                                             \
        else                                                          \
        {                                                             \
            LOG_E(LOG_STD,"ERROR %d",X_RET_ASSERTION);               \
            while(1);                                                 \
        }                                                             \
    }
#elif (R_LIB_ASSERT_MODE == R_LIB_ASSERT_RESET)
#define RLIB_ERROR_ASSERT(a)                                          \
    {                                                                 \
        if ((a))                                                      \
        {                                                             \
            (void) 0;                  /* Do nothing */               \
        }                                                             \
        else                                                          \
        {                                                             \
            LOG_E(LOG_STD,"ERROR %d",-1);                             \
            RESET();                                                  \
        }                                                             \
    }
#endif


#define RLIB_ERROR_SET_AND_RETURN( code)                              \
    {                                                                 \
	    LOG_E(LOG_STD,"SET ERROR %d",code);                           \
        return code;                                                  \
    }




#define    ERROR_RETURN(a, code)              RLIB_ERROR_RETURN(a, code)
#define    ASSERT(a)                          RLIB_ERROR_ASSERT(a)
#define    ERROR_SET_AND_RETURN(code)         RLIB_ERROR_SET_AND_RETURN( code)




#endif /* CORE_C_ERROR_H_ */
