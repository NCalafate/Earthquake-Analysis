#include "count.h"

void COUNT(PtList earthquake) {

    double minMagnitude, maxMagnitude;
	char countryCode[3];

	printf("Enter the minimum magnitude: ");
	readDouble(&minMagnitude);

	printf("Enter the maximum magnitude: ");
	readDouble(&maxMagnitude);

	printf("Enter the country code: ");
	readString(countryCode, 3);
    getchar();

    int hasEarthquake = 0;
    int hasCountry = 0;
    int countEarthquakes = 0;

    double type1 = 0; // earthquake
    double type2 = 0; //explosion
    double type3 = 0; //nuclear explosion
    double type4 = 0; //rock burst

    ListElem eq;

    int size;
    listSize(earthquake, &size);
    /* Percorrer a lista de terramotos */
    
    for (int i = 0; i < size; i++) {
         listGet(earthquake, i, &eq);

        /* Verificar se o terramoto está no intervalo de magnitude */
        if (eq.magnitude >= minMagnitude && eq.magnitude <= maxMagnitude) {
            hasEarthquake = 1;

            /* Verificar se o terramoto é do país/território escolhido */
            if (strcasecmp(eq.countryCode, countryCode) == 0) {
                hasCountry = 1;
                countEarthquakes++;

                /* Contar o tipo de terramoto */
                if (strcasecmp(eq.type, "Earthquake") == 0)
                    type1++;
                else if(strcasecmp(eq.type, "Explosion") == 0)
                    type2++;
                else if(strcasecmp(eq.type, "Nuclear Explosion") == 0)
                    type3++;
                else if(strcasecmp(eq.type, "Rock Burst") == 0)
                    type4++;
                
            }
        }
    }
    /* Verificar se há dados disponíveis */
    if (!hasEarthquake)
        printf("Earthquake data not available for magnitude between [%.2lf, %.2lf]\n", minMagnitude, maxMagnitude);
    else if (!hasCountry)
        printf("Earthquake data not available for %s\n", countryCode);
    else {
        /* Calcular a percentagem de terramotos de cada tipo */
        double total = type1 + type2 + type3;
        double percentageType1 = (type1 / total) * 100;
        double percentageType2 = (type2 / total) * 100;
        double percentageType3 = (type3 / total) * 100;
        double percentageType4 = (type4 / total) * 100;

        /* Mostrar os resultados */
        printf("Number of earthquakes in [%.2lf, %.2lf]: %d\n", minMagnitude, maxMagnitude, countEarthquakes);
        printf("Percentage of earthquake types in %s:\n", countryCode);
        printf("Type Earthquake: %.2lf%%\n", percentageType1);
        printf("Type Explosion: %.2lf%%\n", percentageType2);
        printf("Type Nuclear Explosion: %.2lf%%\n", percentageType3);
        printf("Type Rock Burst: %.2lf%%\n",percentageType4);
    }
}