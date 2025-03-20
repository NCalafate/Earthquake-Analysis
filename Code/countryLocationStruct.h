/** @file countryLocationStruct.h
 *  @brief Ficheiro separado para implementar a estrutura de CountryLocation.
 * 
 *  @bug No known bugs.
 */
#pragma once

/** @brief Estrutura das localizações dos países.
 *
 */
typedef struct countryLocation {
    char code[3];
    float latitude;
    float longitude;
    char territoryName[45];
    char countryName[45];
    char territoryRegion[30];
} CountryLocation;