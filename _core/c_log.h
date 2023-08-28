/*
 * c_log.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef CORE_C_LOG_H_
#define CORE_C_LOG_H_

#include <string.h>
#include "_core/c_typedefs.h"
#include "_hal/h_log/h_log.h"

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)





#if LOG_ENABLE == 1

#define LOG_E(m,s,...) if(LOG_LEVEL>=LOG_LVL_ERROR){\
                     h_log_write_e(m,LOG_MODULE,s,__FILENAME__,__FUNCTION__,__LINE__,##__VA_ARGS__);\
                     }


#define LOG_W(m,s,...) if(LOG_LEVEL>=LOG_LVL_WARN){\
                     h_log_write_w(m,LOG_MODULE,s,__FILENAME__,__FUNCTION__,__LINE__,##__VA_ARGS__);\
                     }

#define LOG_I(m,s,...) if(LOG_LEVEL>=LOG_LVL_INFO){\
                     h_log_write_i(m,LOG_MODULE,s,__FILENAME__,__FUNCTION__,__LINE__,##__VA_ARGS__);\
                     }

#define LOG_D(m,s,...) if(LOG_LEVEL>=LOG_LVL_DEBUG){\
                     h_log_write_d(m,LOG_MODULE,s,__FILENAME__,__FUNCTION__,__LINE__, ##__VA_ARGS__);\
                     }
#else
#define LOG_E(m,s,...)
#define LOG_W(m,s,...)
#define LOG_I(m,s,...)
#define LOG_D(m,s,...)
#endif

#endif /* CORE_C_LOG_H_ */
