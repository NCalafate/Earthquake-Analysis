/** @file earthquakeData.c
 *  @brief Funções responsáveis pela implementação da lista de terramotos.

 *  @bug No known bugs.
*/
#include "earthquakeData.h"

Date createDate(char *date) {

    Date dt;

    char month[3];
    for(int i = 0; i < 2; i++) {
        month[i] = date[i];
    }
    month[2] = '\0';
    dt.month = atoi(month);
    
    char day[3];
    int t = 0;
    for(int i = 3; i < 5; i++) {
        day[t++] = date[i];
    }
    day[2] = '\0';
    dt.day = atoi(day);

    char year[5];
    t = 0;
    for(int i = 6; i < 10; i++) {
        year[t++] = date[i];
    }
    year[4] = '\0';
    dt.year = atoi(year);

    return dt;
}

Time createTime(char *time) {

    Time tm;

    char hour[3];
    for(int i = 0; i < 2; i++) {
        hour[i] = time[i];
    }
    hour[2] = '\0';
    tm.hour = atoi(hour);
    
    char min[3];
    int t = 0;
    for(int i = 3; i < 5; i++) {
        min[t++] = time[i];
    }
    min[2] = '\0';
    tm.min = atoi(min);

    char sec[3];
    t = 0;
    for(int i = 6; i < 8; i++) {
        sec[t++] = time[i];
    }
    sec[2] = '\0';
    tm.sec = atoi(sec);

    return tm;
}

Earthquake earthquakeCreate(
        int id,
        char *date, // Parametizado como char para efetuar conversão.
        char *time, // ||
        float latitude, 
        float longitude,
        char *type,
        float depth,
        float magnitude,
        char *magnitudeType,

        CountryLocation* locarr,
        int locsz
    ) {

        Earthquake qk;
        
        qk.id = id;

        int index;
        double min = 500;
        for(int i = 0; i < locsz - 1; i++) {
            double res = sqrt(pow(latitude - locarr[i].latitude, 2)+pow(longitude - locarr[i].longitude, 2));
            if(res < min) {
                min = res;
                index = i;
            }
        }

        strcpy(qk.countryCode, locarr[index].code); // Placeholder até se efetuarem os cálculos.
        qk.date = createDate(date);
        qk.time = createTime(time);
        qk.latitude = latitude;
        qk.longitude = longitude;
        strcpy(qk.type, type);
        qk.depth = depth;
        qk.magnitude = magnitude;
        strcpy(qk.magnitudeType, magnitudeType);

        return qk;
}

PtList LOADEA(int* numImported, CountryLocation* locarr, int locsz) {

    // Atributos do ficheiro e declaração do comprimento da linha de texto.
    FILE *file = fopen("datasets/earthquakes.csv", "r");
    char line[1024];

    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }
    
    // Aloca-se a memória da lista de earthquakes.
    PtList list = listCreate();
    if(list == NULL) return NULL;

    // Salta a primeira linha.
    fgets(line, 1024, file);

    int c = 0;
    while (fgets(line, sizeof(line), file)) {

        char* tmp = strdup(line);
        char** tokens = splitString(tmp, 9, ";");

        Earthquake qk = earthquakeCreate(
            atoi(tokens[0]),
            tokens[1],
            tokens[2],
            atof(tokens[3]),
            atof(tokens[4]),
            tokens[5],
            atof(tokens[6]),
            atof(tokens[7]),
            tokens[8],

            locarr,
            locsz
        );

        int size;
        listSize(list, &size);

        listAdd(list, size, qk);

        free(tokens);
        free(tmp);

        c++;
    }

    // Fecha-se o ficheiro.
    fclose(file);

    *numImported = c;

    return list;
}



