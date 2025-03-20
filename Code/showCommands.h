/** @file shows.h
 *  @brief Funções responsáveis por mostrar os diversos dados.
 *
 *  @bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "list.h"
#include "input.h"

#define PAGE_SIZE 50

/**
 * @brief Mostra os dados dos terramotos na consola.
 * @param PtList Lista de terramotos.
 */
void SHOWALL(PtList list);

/**
 * @brief Mostra os dados dos terramotos de um certo ano na consola.
 * @param PtList Lista de terramotos.
 */
void SHOW_Y(PtList list);

/**
 * @brief Mostra os dados dos terramotos de um certo país na consola.
 * @param PtList Lista de terramotos.
 */
void SHOW_T(PtList list);

/**
 * @brief Mostra os dados dos terramotos de um determinado ano e país.
 * @param PtList Lista de terramotos.
 * @param year Ano a procurar.
 * @param code Código de país/território do país a procurar.
*/
void SHOW_YT(PtList list);



