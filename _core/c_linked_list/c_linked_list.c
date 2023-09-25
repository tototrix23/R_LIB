/*
 * c_linked_list.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Christophe
 */


#include <_config_compiler/config.h>
#include <_core/c_common.h>
#include "c_linked_list.h"
#include <_core/c_salloc/c_salloc.h>
#include <_core/c_log.h>


#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE    R_LIB_LOG_MODULE

return_t c_linked_list_init(c_linked_list_h list)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(list  != NULL)
#endif
    memset(list,0x00,sizeof(c_linked_list_t));
    return X_RET_OK;
}

return_t  c_linked_list_append(c_linked_list_h list, void* item)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(list  != NULL)
    ASSERT(item  != NULL)
#endif


    c_linked_list_h new_item;
    return_t ret = C_SALLOC(sizeof(c_linked_list_t),(void**)&new_item);
    if(ret != X_RET_OK) return ret;

    new_item->item = item;
    new_item->next = NULL;
    new_item->prev = NULL;


    if (list->item == NULL)
    {
        list->item = item;
    }
    else
    {
        c_linked_list_h last = list;
        if (last->next == NULL)
        {

        }
        else
        {
            while (last->next != NULL)
                last = last->next;
        }
        new_item->prev = last;
        last->next = new_item;
    }

    return X_RET_OK;
}

return_t c_linked_list_get_count(c_linked_list_h list, uint32_t* result)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(list  != NULL)
    ASSERT(result  != NULL)
#endif

    uint32_t count = 0;

    if (list->item != NULL)
        count++;

    while (list->next != NULL)
    {
        count++;
        list = list->next;
    }
    *result = count;
    return X_RET_OK;
}



return_t c_linked_list_get_by_index(c_linked_list_h list, uint32_t index,void** ptr)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(list  != NULL)
    ASSERT(ptr  != NULL)
#endif


    uint32_t count = 0;
    return_t ret = c_linked_list_get_count( list, &count);
    if(ret != X_RET_OK) return ret;

    if(index > (count-1))
        return X_RET_PARAM_RANGE;

    c_linked_list_h obj = list;
    uint32_t i = 0;
    for (i = 0;i < index;i++)
    {
        obj = obj->next;
    }

    *ptr= obj->item;

    return X_RET_OK;

}

