/*
 * c_protected.c
 *
 *  Created on: 12 oct. 2023
 *      Author: Ch.Leclercq
 */

#include <math.h>
#include "c_protected.h"

static bool_t floatCompare(float f1, float f2);

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
    }while(floatCompare(f1,f2) == FALSE);
    *ptrDest = f1;
    return ret;
}


static bool_t floatCompare(float f1, float f2)
{
    static const float epsilon = 1.0e-05f;
    if (fabsf(f1 - f2) <= epsilon)
        return TRUE;
    return fabsf(f1 - f2) <= epsilon * fmaxf(fabsf(f1), fabsf(f2));
}
