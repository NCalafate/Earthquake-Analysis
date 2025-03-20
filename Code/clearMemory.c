/** @file clear.c
 *  @brief Implementação das funções responsáveis pela limpeza da memória.
 *
 *  @bug No know bugs.
*/
#include "clearMemory.h"

int clearMemoryST(PtMap *map) 
{
    if (map == NULL) //if the map is empty
        return 0;

    int auxST=0; //auxiliar size

    if(!mapIsEmpty(*map)) { //if the map is not empty

        mapSize(*map, &auxST); //get the size of the map
        mapDestroy(map); //destroy the map
    }
    return auxST; //return the number of deleted elements
}

int clearMemoryCL(CountryLocation *countries, int size)
{   
    if (countries == NULL)return 0; //if the array is empty
    if (size == 0) return 0; //if the size is 0
                  
        free(countries); //free the array    

    return size; //return the number of deleted elements
}

int clearMemoryEA(PtList *list) {

    if(listIsEmpty(*list)) return 0; //if the list is empty

    int size; //auxiliar size

    listSize(*list, &size);     //get the size of the list
    listClear(*list);           //clear the 
    listDestroy(list);         //destroy the list

    return size;
}
