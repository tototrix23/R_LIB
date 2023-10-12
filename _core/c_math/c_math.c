/*
 * c_math.c
 *
 *  Created on: 12 oct. 2023
 *      Author: Ch.Leclercq
 */
#include "c_math.h"
#include <math.h>
bool_t c_math_float_equality(float f1,float f2)
{
    static const float epsilon = 1.0e-05f;
    if (fabsf(f1 - f2) <= epsilon)
        return TRUE;
    return fabsf(f1 - f2) <= epsilon * fmaxf(fabsf(f1), fabsf(f2));
}

