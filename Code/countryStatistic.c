/** @file countryStatistic.c
 *  @brief Funções responsáveis pela implementação do map de estatísticas de países.
 *
 *  @bug No known bugs.
*/
#include "countryStatistic.h"

CountryStatistics statisticCreate(
        char *code, 
        char *name, 
        char *region,
        long population,
        long area,
        long gdp_capita,  
        float literacy,  
        float birthrate, 
        float deathrate
    ) {

        CountryStatistics stat;

        strcpy(stat.code, code);
        strcpy(stat.name, name);
        strcpy(stat.region, region);
        stat.population = population;
        stat.area = area;
        stat.gdp_capita = gdp_capita;
        stat.literacy = literacy;
        stat.birthrate = birthrate;
        stat.deathrate = deathrate;

        return stat;
}

bool valid(char s[]) {
    char invalid[] = "N.A."; 
    return (strcmp(s, invalid) == 0);
}

PtMap LOADST(int* numImported) {

    // Ficheiro CSV.
    FILE *file = fopen("datasets/world_country_statistics.csv", "r");
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

    // Cria-se o mapa, aborta se for nulo.
    PtMap map = mapCreate(count);
    if(map == NULL) return NULL;

    // Skip primeira linha.
    fgets(line, sizeof(line), file);

    int c = 0;
    while (fgets(line, 1024, file))
    {
        char* tmp = strdup(line);
        char** tokens = splitString(tmp, 9, ";");

        StringWrap code = stringWrapCreate(tokens[0]);

        long gdp = 0;
        if(valid(tokens[5]))
            gdp = -1;
        else 
            gdp = atof(tokens[5]);

        float lit = 0;
        if(valid(tokens[6]))
            lit = -1;
        else 
            lit = atof(tokens[6]);

        float bir = 0;
        if(valid(tokens[7]))
            bir = -1;
        else 
            bir = atof(tokens[7]);

        float dea = 0;
        if(valid(tokens[8]))
            dea = -1;
        else 
            dea = atof(tokens[8]);

        mapPut(map, code, statisticCreate(
            tokens[0],
            tokens[1],
            tokens[2],
            atol(tokens[3]),
            atol(tokens[4]),
            gdp,
            lit,
            bir,
            dea
        ));

        free(tokens);
        free(tmp);

        c++;
    }

    *numImported = c;

    fclose(file);

    return map;
}