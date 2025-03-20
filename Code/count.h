/** @file count.h
 *  @brief Função responsável por mostrar as contagens do número de terramotos de um intervalo de magnitude.
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
 * @brief Mostra as contagens para um determinado intervalo de magnitude pedido
 * ao utilizador
 * @param PtList Lista de terramotos.
 */
void COUNT(PtList earthquake);