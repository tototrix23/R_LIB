/*
 * h_time.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */


#include "h_time.h"

#undef  LOG_LEVEL
#define LOG_LEVEL      R_LIB_LOG_LEVEL
#undef  LOG_MODULE
#define LOG_MODULE     R_LIB_LOG_MODULE


// Instance de l'interface à utiliser pour l'implémentation custom
static i_time_t* i_time_global=NULL;


return_t h_time_init( i_time_h i_time)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(i_time != NULL)
#endif

    // Asserts
    if(i_time->func_init == NULL || i_time->func_time_update == NULL)
       return X_RET_MISSING_INTERFACE;
    // Sauvegarde du pointeur vers l'interface spécifique
    i_time_global = i_time;
    // Appel de la fonction spécifique d'initialisation
    return i_time_global->func_init();
    // Fin
}

return_t h_time_update(c_timespan_h timespan)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(timespan != NULL)
#endif

    // Appel de la fonction de l'interface pour récupérer la structure
    return i_time_global->func_time_update(timespan);
}

return_t h_time_is_elapsed_ms( c_timespan_h timespan, uint64_t value,bool_t *result)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(timespan != NULL)
    ASSERT(result != NULL)
#endif

    if (i_time_global == NULL)
        return X_RET_MISSING_INTERFACE;

    bool_t res = FALSE;

    c_timespan_t elasped_time;
    c_timespan_h elapsed_handler = &elasped_time;
    c_timespan_init( elapsed_handler);

    // Récupération du temps écoulé
    h_time_get_elapsed( timespan, elapsed_handler);

    // Comparaison
    if (elapsed_handler->ms >= value) res= TRUE;
    else res= FALSE;

    *result = res;
    return X_RET_OK;
}


return_t h_time_get_elapsed( c_timespan_h reference, c_timespan_h result)
{
#if R_LIB_CHECK_PARAM_ENABLE == 1
    ASSERT(reference != NULL)
    ASSERT(result != NULL)
#endif

    c_timespan_t current_time;
    c_timespan_h current_time_handler = &current_time;
    c_timespan_init( current_time_handler);
    i_time_global->func_time_update( current_time_handler);
    // Calcul de la différence par rapport à la référence
    uint64_t diff_ms = current_time_handler->ms-reference->ms;
    // Chargement dans le resultat
    result->ms=diff_ms;
    return X_RET_OK;
}
