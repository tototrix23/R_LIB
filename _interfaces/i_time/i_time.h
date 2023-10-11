/*
 * i_time.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef INTERFACES_I_TIME_I_TIME_H_
#define INTERFACES_I_TIME_I_TIME_H_

#include "_core/c_typedefs.h"
#include "_core/c_error/c_error.h"
#include "_core/c_timespan/c_timespan.h"


/// <summary>
/// Interface logiciel entre les librairies et l'implementation spécifique
/// sur une carte éléctronique.
/// </summary>
typedef struct i_time_t
{
    return_t(*func_init)();
    return_t(*func_time_update)( c_timespan_h handler);
}i_time_t;

typedef i_time_t* i_time_h;
/// <summary>
/// Permet de configurer l'interface
/// </summary>
/// <param name="err">pointeur vers l'instance de gestion des erreurs</param>
/// <param name="func_init">fonction d'initialisation </param>
/// <param name="func_get_time">fonction pour récupérer le temps</param>
/// <returns></returns>

return_t i_time_init(i_time_h handler, void* func_init, void* func_time_update);

#endif /* INTERFACES_I_TIME_I_TIME_H_ */
