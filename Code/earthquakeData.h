/** @file earthquakeData.h
 *  @brief Funções responsáveis por implementar a lista de terramotos.

 *  @bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "input.h"
#include "list.h"
#include "countryLocationStruct.h"

/** @brief Importa os dados associados aos terramotos.
 *
 *  @param int Passa número de dados importados por referência.
 *  @return PtList Lista de terramotos.
 */
PtList LOADEA(int* numImported, CountryLocation* arr, int arrsz);


