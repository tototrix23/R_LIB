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

typedef struct c_error_t
{
    return_t code;
    char* file;
    const char* function;
    uint16_t line;
}c_error_t;
typedef c_error_t* c_error_h;

return_t c_error_init(c_error_h err);

c_error_t c_error_create_t(void);
void c_error_set(c_error_h handler, return_t code, char* file,const char* function, uint16_t line);



#define RLIB_ERROR_RETURN(a, code)                                    \
    {                                                                 \
        if ((a))                                                      \
        {                                                             \
            (void) 0;                  /* Do nothing */               \
        }                                                             \
        else                                                          \
        {                                                             \
        	c_error_set(err,code,__FILENAME__,__FUNCTION__,__LINE__); \
        	LOG_E(LOG_STD,"ERROR %d",code);                           \
            return code;                                              \
        }                                                             \
    }


#define RLIB_ERROR_ASSERT(a, code)                                    \
    {                                                                 \
        if ((a))                                                      \
        {                                                             \
            (void) 0;                  /* Do nothing */               \
        }                                                             \
        else                                                          \
        {                                                             \
            LOG_E(LOG_STD,"ERROR %d",code);                           \
            while(1);                                                 \
        }                                                             \
    }


#define RLIB_ERROR_SET_AND_RETURN(err, code)                          \
    {                                                                 \
	    c_error_set(err,code,__FILENAME__,__FUNCTION__,__LINE__);     \
	    LOG_E(LOG_STD,"SET ERROR %d",code);                           \
        return code;                                                  \
    }


#define ERROR_CHECK(err)                                                           \
    {                                                                              \
      if(err->code != X_RET_OK)                                                    \
      {                                                                            \
        c_error_set(err,X_RET_ERROR_EXIST,__FILENAME__,__FUNCTION__,__LINE__);     \
        LOG_E(LOG_STD,"SET ERROR %d",X_RET_ERROR_EXIST);                           \
        return X_RET_ERROR_EXIST;                                                  \
      }                                                                            \
    }

#define    ERROR_RETURN(a, code)              RLIB_ERROR_RETURN(a, code)
#define    ASSERT(a)                          RLIB_ERROR_ASSERT(a, X_RET_ASSERTION)
#define    ERROR_SET_AND_RETURN(err, code)    RLIB_ERROR_SET_AND_RETURN(err, code)




#endif /* CORE_C_ERROR_H_ */
