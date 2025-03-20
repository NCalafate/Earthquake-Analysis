#include "regionAvg.h"

void REGION_AVG(PtMap map) {
    int size;
    mapSize(map, &size);
	char region[30];

	printf("Enter the desired region: ");
    readString(region, 30);

    // Verificar se a região é válida
    int regionExists = 0;
    MapKey* keysAux = mapKeys(map);

    for (int i = 0; i < size; i++) {
        MapValue val;
        mapGet(map, keysAux[i], &val);
        if (strcasecmp(val.region, region) == 0) {
            regionExists = 1;
            break;
        }
    }
    free(keysAux);

    if (!regionExists) {
        printf("Invalid region: %s\n", region);
        return;
    }


    int ignoredCountries=0;
    int global_ignoredCountries=0;
    long global_population=0;
    long global_area=0;
    long global_gdp_capita=0; 
    float global_literacy=0; 
    long population=0;
    long area=0;
    long gdp_capita=0; 
    float literacy=0;  


    MapKey* keys = mapKeys(map);
    MapValue val;

    for (int i = 0; i < size; i++) {
        mapGet(map, keys[i], &val);
        if (strcasecmp(val.region, region) == 0) {
            if (val.literacy < 0.0 || val.gdp_capita < 0.0) {
                ignoredCountries++;
                continue;
            }
            population += val.population;
            area += val.area;
            gdp_capita += val.gdp_capita;
            literacy += val.literacy;
        }
    }

    for (int i = 0; i < size; i++) {
        mapGet(map, keys[i], &val);
            if (val.literacy < 0.0 || val.gdp_capita < 0.0) {
                global_ignoredCountries++;
                continue;
            }
            global_population += val.population;
            global_area += val.area;
            global_gdp_capita += val.gdp_capita;
            global_literacy += val.literacy;
    }

    // Calcular médias
    int validCountries = size - ignoredCountries;
    if (validCountries > 0) {
        literacy /= validCountries;
    }

    int global_validCountries = size - global_ignoredCountries;
    if (global_validCountries > 0) {
        global_literacy /= global_validCountries;
    }

    printf("Averages for region: %s\n", region);
    printf("Region: %s\n", region);
    printf("Considered countries: %d\n", validCountries);
    printf("Ignored countries: %d\n", ignoredCountries);
    printf("Population: %ld\n", population);
    printf("Area: %ld\n", area);
    printf("Population Density: %ld\n", population/area);
    printf("GDP REGION: %ld\n", gdp_capita*population);
    printf("GDP per Capita: %ld\n", gdp_capita);
    printf("Literacy: %.2f\n", literacy);

    printf("Global Averages:\n");
    printf("Considered countries: %d\n", global_validCountries);
    printf("Ignored Countries: %d\n", global_ignoredCountries);
    printf("Population: %ld\n", global_population);
    printf("Area: %ld\n", global_area);
    printf("Population Density: %ld\n", global_population/global_area);
    printf("GDP total: %ld\n", global_gdp_capita*global_population);
    printf("GDP per Capita: %ld\n", global_gdp_capita);
    printf("Literacy: %.2f\n", global_literacy);

    free(keys);
}