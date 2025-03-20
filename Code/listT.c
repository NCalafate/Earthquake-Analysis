#include "listT.h"

void LIST_T(PtList list, int numRecords){

    int startIndex = 0;

    PtMap map = mapCreate(numRecords);

    int listsz = 0;
    listSize(list, &listsz);
    
    // Capacidade inicial de 100 países.
    MapValue mv;
    ListElem elem;
    for(int i = 0; i < listsz; i++) {
        listGet(list, i, &elem);
        StringWrap code = stringWrapCreate(elem.countryCode);
        if(!mapContains(map, code)) mapPut(map, code, mv);
    }

    int mpsz = 0;
    mapSize(map, &mpsz);
    printf("Number of records found: %d\n", mpsz);

    MapKey* keys = mapKeys(map);

    printf("===========================================================================================================================================================\n");
    printf("                                          LIST OF COUNTRIES THAT HAD EARTHQUAKES IN THE PAST [ALPHABETICALLY ASCENDENT]                                    \n");
    printf("===========================================================================================================================================================\n");

    int k = 0;
    for(int i = 1; i < mpsz; i++) {
        printf("[%s]   ", keys[k++].text);
        if(i % 10 == 0) printf("\n");
    }
    printf("\n");

    free(keys);
    mapDestroy(&map);
}