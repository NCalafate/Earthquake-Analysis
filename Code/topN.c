#include "topN.h"

void calculateCountryData(PtList earthquakes, CountryLocation* countryLocations, int locationsImported, CountryData* countries) {
    // Percorra a lista de localizações dos países
    for (int i = 0; i < locationsImported; i++) {
        // Inicialize os dados do país
        strcpy(countries[i].code, countryLocations[i].code);
        strcpy(countries[i].territoryName, countryLocations[i].territoryName);
        countries[i].numberOfEarthquakes = 0;
        countries[i].averageDepth = 0.0;
        countries[i].averageMagnitude = 0.0;
        Earthquake qk;

        // Percorra a lista de terramotos
        int earthquakesSize;
        listSize(earthquakes, &earthquakesSize);
        for (int j = 0; j < earthquakesSize; j++) {
            Earthquake* earthquake;
            listGet(earthquakes, j, &qk);
            if (strcmp(earthquake->countryCode, countryLocations[i].code) == 0) {
                // Atualize os dados do país com base no terremoto
                countries[i].numberOfEarthquakes++;
                countries[i].averageDepth += earthquake->depth;
                countries[i].averageMagnitude += earthquake->magnitude;
            }
        }

        // Calcule as médias se houver terremotos registrados para o país
        if (countries[i].numberOfEarthquakes > 0) {
            countries[i].averageDepth /= countries[i].numberOfEarthquakes;
            countries[i].averageMagnitude /= countries[i].numberOfEarthquakes;
        }
    }
}

void getTopNCountries(CountryData* countries, int numCountries, int N, CountryData* topCountries) {
    // Copie os dados dos países para uma lista temporária
    CountryData* tempCountries = malloc(numCountries * sizeof(CountryData));
    memcpy(tempCountries, countries, numCountries * sizeof(CountryData));

    // Ordene a lista temporária em ordem decrescente com base no número de terremotos
    for (int i = 0; i < numCountries - 1; i++) {
        for (int j = 0; j < numCountries - i - 1; j++) {
            if (tempCountries[j].numberOfEarthquakes < tempCountries[j + 1].numberOfEarthquakes) {
                CountryData temp = tempCountries[j];
                tempCountries[j] = tempCountries[j + 1];
                tempCountries[j + 1] = temp;
            }
        }
    }

    // Copie os N primeiros países ordenados para o array topCountries
    for (int i = 0; i < N; i++) {
        topCountries[i] = tempCountries[i];
    }

    // Libere a memória alocada para a lista temporária
    free(tempCountries);
}

void showTopNCountries(CountryData* countries, int N) {
    printf("Top %d countries with most earthquakes:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Country Code: %s\n", countries[i].code);
        printf("Territory Name: %s\n", countries[i].territoryName);
        printf("Number of Earthquakes: %d\n", countries[i].numberOfEarthquakes);
        printf("Average Depth: %.2f\n", countries[i].averageDepth);
        printf("Average Magnitude: %.2f\n", countries[i].averageMagnitude);
        printf("-------------------------\n");
    }
}