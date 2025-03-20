/** @file countryLocation.h
 *  @brief Funções responsáveis por implementar o array de localizações dos países.
 *
 *  @bug No known bugs.
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "map.h"
#include "list.h"
#include "input.h"

/**
 * @brief Estrutura dos dados do histograma.
 * 
 */
typedef struct countryQuakes {
    char countryCode[3];
    int magnValues[6];
} CountryQuakes;

/** @brief Devolve um histograma com os dados de terramotos dos países inseridos.
 * 
 *  Número de terramotos segue a escala logarítmica.
 * 
 *  @param PtList Lista de terramotos.
 */

void HISTOGRAM(PtList list);