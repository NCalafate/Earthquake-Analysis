/** @file listT.h
 *  @brief Função responsável por mostrar lista de países com dados de
 * terramotos.
 *
 *  @bug No known bugs.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "list.h"
#include "map.h"

#define PAGE_SIZE 50

/**
 * @brief Mostra o countrycode de todos os paises/territórios que têm dados de
 * terramotos.
 * @param PtList Lista de terramotos.
 */
void LIST_T(PtList list, int numRecords);