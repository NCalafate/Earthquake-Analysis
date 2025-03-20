/** @file earthquakeData.h
 *  @brief Funções responsáveis por implementar a lista de terramotos.
 *
 *  @bug No known bugs.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "countryLocationStruct.h"
#include "input.h"
#include "list.h"

/* @brief Estrutura auxiliar para armazenar os dados dos países */
typedef struct CountryData {
    char code[3];
    char territoryName[45];
    int numberOfEarthquakes;
    float averageDepth;
    float averageMagnitude;
} CountryData;

/** @brief Lista com cada um dos países e dados calculados.
 *
 *  @param PtList Lista de terramotos.
 *  @param CountryLocation Array de localizações.
 *  @param int Número de localizações.
 *  @param CountryData Array de dados dos países.
 */
void calculateCountryData(PtList earthquakes, CountryLocation *countryLocations,
                          int locationsImported, CountryData *countries);

/** @brief N elementos com mais terramotos ordenados por ordem decrescente.
 *
 *  @param CountryData Array de dados dos países.
 *  @param int Número de países.
 *  @param int N.
 *  @param CountryData Array de dados dos países.
 */
void getTopNCountries(CountryData *countries, int numCountries, int N,
                      CountryData *topCountries);

/** @brief N elementos com mais terramotos ordenados por ordem decrescente.
 *
 *  @param CountryData Países.
 *  @param int N.
 */
void showTopNCountries(CountryData *countries, int N);