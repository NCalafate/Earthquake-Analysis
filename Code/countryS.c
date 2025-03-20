#include "countryS.h"

void COUNTRY_S(PtMap country)
{
    int sizeST;
    mapSize(country, &sizeST);

    PtMap mapAux = mapCreate(sizeST); // cria mapa auxiliar com os paises ordenados
    PtMap aux = mapCreate(sizeST);

    MapKey *keyST = mapKeys(country);
    for (int i = 0; i < sizeST; i++)
    {
        MapValue value;
        mapGet(country, keyST[i], &value);
        mapPut(aux, keyST[i], value);
    }
    free(keyST);

    int sizeMap;
    mapSize(aux, &sizeMap);

    int sortOrder; // 0 para crescente, 1 para decrescente
    char order[4];
    MapValue a;
    MapValue b;
    MapKey *keys;

    printf("Enter sorting order (0 for ascending, 1 for descending): ");
    readInteger(&sortOrder);

    printf("Enter criterion order literacy or per GDP: ");
    readString(order, 4);
    switch (sortOrder)
    {
    case 0: // Ordem crescente
        if (strcasecmp(order, "lit") == 0)
        {
            while (sizeMap > 0)
            {
                keys = mapKeys(aux); // atualiza as keys
                mapGet(aux, keys[0], &a);

                int minIndex = 0;

                for (int k = 1; k < sizeMap; k++)
                {
                    mapGet(aux, keys[k], &b);

                    if (a.literacy > b.literacy)
                    {
                        minIndex = k;
                        a = b;
                    }
                    else if (a.literacy == b.literacy && a.gdp_capita > b.gdp_capita)
                    {
                        minIndex = k;
                        a = b;
                    }
                }
                MapValue lixo;
                mapRemove(aux, keys[minIndex], &lixo); // remove o pais com a menor literacy
                mapPut(mapAux, keys[minIndex], lixo); // coloca o pais no mapa auxiliar                
                mapSize(aux, &sizeMap); // atualiza o tamanho do mapa
                free(keys); // libera a memoria das chaves antigas
            }
        }
        else if (strcasecmp(order, "GDP") == 0)
        {
            while (sizeMap > 0)
            {
                keys = mapKeys(aux); // atualiza as keys
                mapGet(aux, keys[0], &a);

                int minIndex = 0;

                for (int k = 1; k < sizeMap; k++)
                {
                    mapGet(aux, keys[k], &b);

                    if (a.gdp_capita > b.gdp_capita)
                    {
                        minIndex = k;
                        a = b;
                    }
                    else if (a.gdp_capita == b.gdp_capita && a.literacy > b.literacy)
                    {
                        minIndex = k;
                        a = b;
                    }
                }
                MapValue lixo;
                mapRemove(aux, keys[minIndex], &lixo); // remove o pais com a menor literacy
                mapPut(mapAux, keys[minIndex], lixo); // coloca o pais no mapa auxiliar                
                mapSize(aux, &sizeMap); // atualiza o tamanho do mapa
                free(keys); // libera a memoria das chaves antigas
            }
        }
        else
        {
            printf("Invalid criterion order\n");
        }
        break;

    case 1: // Ordem decrescente
        if (strcasecmp(order, "lit") == 0)
        {
            while (sizeMap > 0)
            {
                keys = mapKeys(aux); // atualiza as keys 
                mapGet(aux, keys[0], &a);

                int minIndex = 0;

                for (int k = 1; k < sizeMap; k++)
                {
                    mapGet(aux, keys[k], &b);

                    if (a.literacy < b.literacy)
                    {
                        minIndex = k;
                        a = b;
                    }
                    else if (a.literacy == b.literacy && a.gdp_capita < b.gdp_capita)
                    {
                        minIndex = k;
                        a = b;
                    }
                }
                MapValue lixo;
                mapRemove(aux, keys[minIndex], &lixo); // remove o pais com a maior literacy
                mapPut(mapAux, keys[minIndex], lixo); // coloca o pais no mapa auxiliar                
                mapSize(aux, &sizeMap); // atualiza o tamanho do mapa
                free(keys); // libera a memoria das chaves antigas
            }
        }
        else if (strcasecmp(order, "GDP") == 0)
        {
            while (sizeMap > 0)
            {
                keys = mapKeys(aux); // atualiza as keys
                mapGet(aux, keys[0], &a);

                int minIndex = 0;

                for (int k = 1; k < sizeMap; k++)
                {
                    mapGet(aux, keys[k], &b);

                    if (a.gdp_capita < b.gdp_capita)
                    {
                        minIndex = k;
                        a = b;
                    }
                    else if (a.gdp_capita == b.gdp_capita && a.literacy < b.literacy)
                    {
                        minIndex = k;
                        a = b;
                    }
                }
                MapValue lixo;
                mapRemove(aux, keys[minIndex], &lixo); // remove o pais com a maior literacy
                mapPut(mapAux, keys[minIndex], lixo); // coloca o pais no mapa auxiliar                
                mapSize(aux, &sizeMap); // atualiza o tamanho do mapa
                free(keys); // libera a memoria das chaves antigas
            }
        }
        else
            printf("Invalid criterion order\n");
        break;

    default:
        printf("Invalid sorting order\n");
        break;
    }

    if (mapAux != NULL)
    {
        mapPrint(mapAux);
    }

    mapDestroy(&aux);
    mapDestroy(&mapAux);
}
