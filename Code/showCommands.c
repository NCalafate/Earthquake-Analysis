#include "showCommands.h"

void SHOWALL(PtList list) {
    int numRecords = 0;
    listSize(list ,&numRecords); // Obtém o número de registros na lista
    int startIndex = 0; // Índice inicial do grupo de registros a mostrar
   
    ListElem elem;
    // Mostra o número de registros encontrados
    printf("Number of records found: %d\n", numRecords);

    printf("===========================================================================================================================================================\n");
    printf("                                                                       Earthquakes                                                                         \n");
    printf("===========================================================================================================================================================\n");

    while (startIndex < numRecords)
    {
        int endIndex = startIndex + PAGE_SIZE;

        // Mostra a listagem dos terremotos
        printf("%-8s%-8s%-12s%-12s%-20s%-20s%-24s%-20s%-14s%-6s\n", "ID", " CODE", "DATE", "HOUR", "LATITUDE", "LONGITUDE", "TYPE", "DEPTH       ", "MAGNITUDE", "MAGNITUDE TYPE");
        for (int i = startIndex; i < endIndex && i < numRecords; i++)
        {     
            listGet(list, i, &elem);
            printf("%-9d%-7s%02d-%02d-%-6d%02d:%02d:%02d%s%-20f%-20f%-24s%-20f%-14f%-6s\n", elem.id, 
                                                                     elem.countryCode,
                                                                     elem.date.day, elem.date.month, elem.date.year,
                                                                     elem.time.hour, elem.time.min, elem.time.sec,  
                                                                     "    ",
                                                                     elem.latitude, 
                                                                     elem.longitude, 
                                                                     elem.type, 
                                                                     elem.depth, 
                                                                     elem.magnitude, 
                                                                     elem.magnitudeType
            );
        }
        // Verificar se há mais registos para imprimir
        if (endIndex >= numRecords)
        {
            printf("No more records to print.\n");
            break;
        }
        // Perguntar ao utilizador se deseja imprimir mais registos
        char choice;
        printf("Do you wish to print %d more records? (Y/N): ", PAGE_SIZE);
        readChar(&choice);

        // Verificar a escolha do utilizador
        if (choice == 'N' || choice == 'n')
        {
            printf("Quitting...\n");
            break;
        }

        // Atualizar o índice inicial para o próximo grupo
        startIndex += PAGE_SIZE;
    }
}

void SHOW_Y(PtList list) {
    int startIndex = 0, listsz = 0, year = 0;

    // Ano que o utilizador pretende pesquisar.
    printf("Enter the year: ");
	readInteger(&year);

    listSize(list, &listsz);

    int* arr = (int*)malloc(listsz * sizeof(int));

    ListElem elem;
    int j = 0;
    for(int i = 0; i < listsz; i++) {
        listGet(list, i, &elem);
        if(elem.date.year == year) arr[j++] = i;
    }

    printf("Number of records found: %d\n", j);

    if(j == 0) printf("Earthquake data not available for year [%d]. Quitting...", year);
    else {
        printf("===========================================================================================================================================================\n");
        printf("                                                                  Earthquakes [%d]                                                                   \n", year);
        printf("===========================================================================================================================================================\n");

        while (startIndex < j)
        {
            int endIndex = startIndex + PAGE_SIZE;

            // Mostra a listagem dos terremotos
            printf("%-8s%-8s%-12s%-12s%-20s%-20s%-24s%-20s%-14s%-6s\n", "ID", " CODE", "DATE", "HOUR", "LATITUDE", "LONGITUDE", "TYPE", "DEPTH       ", "MAGNITUDE", "MAGNITUDE TYPE");
            for (int i = startIndex; i < endIndex && i < j; i++)
            {     
                listGet(list, arr[i], &elem);
                printf("%-9d%-7s%02d-%02d-%-6d%02d:%02d:%02d%s%-20f%-20f%-24s%-20f%-14f%-6s\n", elem.id, 
                                                                        elem.countryCode,
                                                                        elem.date.day, elem.date.month, elem.date.year,
                                                                        elem.time.hour, elem.time.min, elem.time.sec,  
                                                                        "    ",
                                                                        elem.latitude, 
                                                                        elem.longitude, 
                                                                        elem.type, 
                                                                        elem.depth, 
                                                                        elem.magnitude, 
                                                                        elem.magnitudeType
                );
            }
            
            // Verificar se há mais registos para imprimir
            if (endIndex >= j)
            {
                printf("No more records to print.\n");
                break;
            }
            // Perguntar ao utilizador se deseja imprimir mais registos
            char choice;
            printf("Do you wish to print %d more records? (Y/N): ", PAGE_SIZE);
            readChar(&choice);

            // Verificar a escolha do utilizador
            if (choice == 'N' || choice == 'n')
            {
                printf("Quitting...\n");
                break;
            }

            // Atualizar o índice inicial para o próximo grupo
            startIndex += PAGE_SIZE;
        }
    }

    // Liberta-se o array de índices.
    free(arr);
}

void SHOW_T(PtList list) {
    int startIndex = 0, listsz = 0;

    // Território que o utilizador pretende pesquisar.
    char countryCode[3];
    printf("Enter the country code: ");
	readString(countryCode, 3);
    getchar();

    listSize(list, &listsz);

    int* arr = (int*)malloc(listsz * sizeof(int));

    ListElem elem;
    int j = 0;
    for(int i = 0; i < listsz; i++) {
        listGet(list, i, &elem);
        if(strcasecmp(elem.countryCode, countryCode) == 0) arr[j++] = i;
    }

    printf("Number of records found: %d\n", j);

    if(j == 0) printf("Earthquake data not available for country [%s]. Quitting...", countryCode);
    else {
        printf("===========================================================================================================================================================\n");
        printf("                                                                  Earthquakes [%s]                                                                   \n", countryCode);
        printf("===========================================================================================================================================================\n");

        int bf = 0;
        while (startIndex < j)
        {
            int endIndex = startIndex + PAGE_SIZE;

            // Mostra a listagem dos terremotos
            printf("%-8s%-8s%-12s%-12s%-20s%-20s%-24s%-20s%-14s%-6s\n", "ID", " CODE", "DATE", "HOUR", "LATITUDE", "LONGITUDE", "TYPE", "DEPTH       ", "MAGNITUDE", "MAGNITUDE TYPE");
            for (int i = startIndex; i < endIndex && i < j; i++)
            {     
                listGet(list, arr[i], &elem);
                printf("%-9d%-7s%02d-%02d-%-6d%02d:%02d:%02d%s%-20f%-20f%-24s%-20f%-14f%-6s\n", elem.id, 
                                                                        elem.countryCode,
                                                                        elem.date.day, elem.date.month, elem.date.year,
                                                                        elem.time.hour, elem.time.min, elem.time.sec,  
                                                                        "    ",
                                                                        elem.latitude, 
                                                                        elem.longitude, 
                                                                        elem.type, 
                                                                        elem.depth, 
                                                                        elem.magnitude, 
                                                                        elem.magnitudeType
                );
            }
            
            // Verificar se há mais registos para imprimir
            if (endIndex >= j)
            {
                printf("No more records to print.\n");
                break;
            }
            // Perguntar ao utilizador se deseja imprimir mais registos
            char choice;
            printf("Do you wish to print %d more records? (Y/N): ", PAGE_SIZE); 
            readChar(&choice);

            // Verificar a escolha do utilizador
            if (choice == 'N' || choice == 'n')
            {
                printf("Quitting...\n");
                break;
            }

            // Atualizar o índice inicial para o próximo grupo
            startIndex += PAGE_SIZE;
        }
    }

    // Liberta-se o array de índices.
    free(arr);
}

void SHOW_YT(PtList list) {

    int year;
	char countryCode[3];
	printf("Enter the year: ");
	readInteger(&year);
	printf("Enter the country code: ");
	readString(countryCode, 3);
    getchar();

    int listsz = 0, startIndex = 0;
    listSize(list, &listsz);

    int* arr = (int*)malloc(listsz * sizeof(int));

    ListElem elem;
    int j = 0;
    for(int i = 0; i < listsz; i++) {
        listGet(list, i, &elem);
        if(elem.date.year == year && strcasecmp(elem.countryCode, countryCode) == 0) arr[j++] = i;
    }

    printf("Number of records found: %d\n", j);

    if(j == 0) printf("Earthquake data not available for country [%s] and year [%d]. Quitting...", countryCode, year);
    else {
        printf("===========================================================================================================================================================\n");
        printf("                                                                Earthquakes [%s][%d]                                                                   \n", countryCode, year);
        printf("===========================================================================================================================================================\n");

        while (startIndex < j)
        {
            int endIndex = startIndex + PAGE_SIZE;

            // Mostra a listagem dos terremotos
            printf("%-8s%-8s%-12s%-12s%-20s%-20s%-24s%-20s%-14s%-6s\n", "ID", " CODE", "DATE", "HOUR", "LATITUDE", "LONGITUDE", "TYPE", "DEPTH       ", "MAGNITUDE", "MAGNITUDE TYPE");
            for (int i = startIndex; i < endIndex && i < j; i++)
            {     
                listGet(list, arr[i], &elem);
                printf("%-9d%-7s%02d-%02d-%-6d%02d:%02d:%02d%s%-20f%-20f%-24s%-20f%-14f%-6s\n", elem.id, 
                                                                        elem.countryCode,
                                                                        elem.date.day, elem.date.month, elem.date.year,
                                                                        elem.time.hour, elem.time.min, elem.time.sec,  
                                                                        "    ",
                                                                        elem.latitude, 
                                                                        elem.longitude, 
                                                                        elem.type, 
                                                                        elem.depth, 
                                                                        elem.magnitude, 
                                                                        elem.magnitudeType
                );
            }
            
            // Verificar se há mais registos para imprimir
            if (endIndex >= j)
            {
                printf("No more records to print.\n");
                break;
            }
            // Perguntar ao utilizador se deseja imprimir mais registos
            char choice;
            printf("Do you wish to print %d more records? (Y/N): ", PAGE_SIZE);
            readChar(&choice);

            // Verificar a escolha do utilizador
            if (choice == 'N' || choice == 'n')
            {
                printf("Quitting...\n");
                break;
            }

            // Atualizar o índice inicial para o próximo grupo
            startIndex += PAGE_SIZE;
        }
    }

    // Liberta-se o array de índices.
    free(arr);
}



    


    

