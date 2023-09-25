/*
 * c_error_test.c
 *
 *  Created on: Sep 7, 2023
 *      Author: Christophe
 */

#include "c_error_test.h"
#include "c_error.h"
#include "__plugins/unity.h"

#ifdef R_LIB_UNIT_TEST_MODE
void c_error_test1(void);
void c_error_test2(void);


void c_error_test1(void)
{

}

void c_error_test2(void)
{



}



void c_error_test(void)
{

    RUN_TEST(c_error_test1);
    RUN_TEST(c_error_test2);

}
#endif
