/** @file countryLocation.c
 *  @brief Funções responsáveis pela implementação do array CountryLocation.
 *
 *  @bug No known bugs.
 */
#include "countryLocation.h"

CountryLocation countryCreate(
        char *code, 
        float latitude, 
        float longitude, 
        char *territoryName, 
        char *countryName, 
        char *territoryRegion
    ) {

    // É criado um novo país.
    CountryLocation country;

    strcpy(country.code, code);
    country.latitude = latitude;
    country.longitude = longitude;
    strcpy(country.territoryName, territoryName);
    strcpy(country.countryName, countryName);
    strcpy(country.territoryRegion, territoryRegion);

    return country;
}

CountryLocation* LOADCL(int* numImported) {

    // Ficheiro CSV.
    FILE *file = fopen("datasets/world_country_locations.csv", "r");
    char line[1024];

    // Verifica se o ficheiro existe.
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    // Tamanho do ficheiro CSV para alocação de memória.
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
    }
    rewind(file);

    // Alocar memória para o array de CountryLocation
    CountryLocation* arr = (CountryLocation*)malloc(count * sizeof(CountryLocation));
    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        fclose(file);
        return NULL;
    }

    // Ignorar a primeira linha.
    fgets(line, sizeof(line), file);

    count = 0; 
    while (fgets(line, sizeof(line), file)) {

        char* tmp = strdup(line);
        char** tokens = splitString(tmp, 6, ";");

        arr[count++] = countryCreate(tokens[0], atof(tokens[1]), atof(tokens[2]), tokens[3], tokens[4], tokens[5]);

        free(tokens);
        free(tmp);
    }

    fclose(file);

    *numImported = count;

    return arr;
}



