/** @file countryLocation.h
 * 
 *  @brief Funções responsáveis por implementar o array de localizações dos países.
 *
 *  @bug No known bugs.
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

#include "countryLocationStruct.h"

/** @brief Importa os dados das localizações dos países.
 *
 *  @param int Passa número de dados importados por referência.
 *  @return CountryLocation Array de localizações de países.
 */
CountryLocation* LOADCL(int* numImported);

