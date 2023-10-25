/*
 * c_protected.h
 *
 *  Created on: 12 oct. 2023
 *      Author: Ch.Leclercq
 */

#ifndef CORE_C_PROTECTED_C_PROTECTED_H_
#define CORE_C_PROTECTED_C_PROTECTED_H_

#include <_core/c_common.h>


return_t c_protected_get_float(float* ptrSrc,float* ptrDest);
return_t c_protected_get_object(void* ptrSrc,void* ptrDest,size_t size);

#endif /* CORE_C_PROTECTED_C_PROTECTED_H_ */
