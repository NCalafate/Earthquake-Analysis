/** @file clearMemory.h
 *  @brief Funções responsáveis por limpar a memória.
 *
 *  @bug No known bugs.
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "list.h"
#include "countryLocationStruct.h"

/** @brief Limpa a memória associada às CountryStatistics.
 *
 *  @param PtMap Mapa das CountryStatistics
 *  @return int Código de saída.
 */
int clearMemoryST(PtMap* map);

/** @brief Limpa a memória associada às CountryLocations.
 *
 *  @param CountryLocation Array das CountryLocation.
 *  @param size Tamanho do array.
 *  @return int Código de saída.
 */
int clearMemoryCL(CountryLocation* arrCL, int size);

/** @brief Limpa a memória associada aos terramotos.
 *
 *  @param PtList Lista dos terramotos.
 *  @return int Código de saída.
 */
int clearMemoryEA(PtList* list);
