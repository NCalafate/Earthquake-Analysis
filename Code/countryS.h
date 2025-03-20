/** @file countryS.h
 *  @brief Função que Mostra os dados dos países ordenados por % (percentagem) de literacia e por GDP (per capita)
 *
 *  @bug No known bugs.
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

#include "map.h"
#include "countryStatistic.h"


/**
 * @brief Mostra os dados dos países ordenados por % (percentagem) de literacia e por GDP (per capita).
 * 
 * @param PtMap Mapa com dados estatísticos dos países.
 */
void COUNTRY_S(PtMap country);