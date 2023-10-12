/*
 * c_protected.c
 *
 *  Created on: 12 oct. 2023
 *      Author: Ch.Leclercq
 */

#include <math.h>
#include <_core/c_math/c_math.h>
#include "c_protected.h"


return_t c_protected_get_float(float* ptrSrc,float* ptrDest)
{

#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(ptrSrc  != NULL);
    ASSERT(ptrDest  != NULL);
#endif
    return_t ret = X_RET_OK;


    volatile float f1,f2;
    do
    {
        f1 = *ptrSrc;
        f2 = *ptrSrc;
    }while(c_math_float_equality(f1,f2) == FALSE);
    *ptrDest = f1;
    return ret;
}


