/*
 * h_time.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef HAL_H_TIME_H_TIME_H_
#define HAL_H_TIME_H_TIME_H_

#include "_core/c_typedefs.h"
#include "_core/c_return_codes.h"
#include "_core/c_error/c_error.h"
#include "_core/c_log.h"
#include "_hal/h_return_codes.h"
#include "_interfaces/i_time/i_time.h"


return_t h_time_init(i_time_h i_time);
return_t h_time_update( c_timespan_h timespan);
return_t h_time_is_elapsed_ms( c_timespan_h timespan, uint64_t value,bool_t *result);
return_t h_time_get_elapsed( c_timespan_h reference, c_timespan_h result);

#endif /* HAL_H_TIME_H_TIME_H_ */
