/** @file countryStatistic.h
 *  @brief Funções responsáveis por implementar o map de estatísticas de países.
 *
 *  @bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "map.h"
#include "stringWrap.h"

/** @brief Importa os dados das estatísticas dos países.
 *
 *  @param int Passa número de dados importados por referência.
 *  @return PtMap ADT Map de estatísticas de países.
 */
PtMap LOADST(int *numImports);