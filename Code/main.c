#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "countryLocationStruct.h"
#include "countryStatisticStruct.h"
#include "earthquakeDataStruct.h"

#include "input.h"
#include "stringWrap.h"
#include "list.h"
#include "map.h"

#include "clearMemory.h"
#include "countryLocation.h"
#include "countryStatistic.h"
#include "earthquakeData.h"
#include "showCommands.h"
#include "countryS.h"
#include "histogram.h"
#include "listT.h"
#include "regionAvg.h"
#include "count.h"
#include "topN.h"

/**
 * @brief Prints the command menu.
 */
void printMenu();
/**
 * @brief Waits for user to press a key.
 */
void waitForKeypress();

/**
 * @brief Program entry point.
 * @return int error code: EXIT_SUCCESS or EXIT_FAILURE
 */
int main()
{

	// Localizações dos países.
	CountryLocation *countryLocations;
	int locationsImported = 0;

	// Lista de terramotos.
	PtList earthquakes;
	int earthquakesImported = 0;

	// Estatísticas dos países.
	PtMap countryStats;
	int statsImported = 0;

	/* Command interpreter. */
	char command[100];
	while (true)
	{

		printMenu();
		readString(command, 100);

		/* COMANDO LOADCL */
		if (strcasecmp(command, "LOADCL") == 0)
		{
			countryLocations = LOADCL(&locationsImported);
			if (countryLocations != NULL) printf("%d country location records imported\n", locationsImported);
		}

		/* COMANDO LOADEA */
		else if (strcasecmp(command, "LOADEA") == 0)
		{
			if (locationsImported == 0) printf("Please load country location data first\n");
			else
			{
				earthquakes = LOADEA(&earthquakesImported, countryLocations, locationsImported);
				if (earthquakes != NULL) printf("%d earthquake records imported\n", earthquakesImported);
			}
		}

		/* COMANDO LOADST */
		else if (strcasecmp(command, "LOADST") == 0)
		{
			countryStats = LOADST(&statsImported);
			if (countryStats != NULL) printf("%d country records imported\n", statsImported);
		}

		/* COMANDO CLEAR */
		else if (strcasecmp(command, "CLEAR") == 0)
		{
			int numClearedST = clearMemoryST(&countryStats);
			printf("%d country statistic records cleared\n", numClearedST);
			statsImported = 0;

			int numClearedCL = clearMemoryCL(countryLocations, locationsImported);
			printf("%d country location records cleared\n", locationsImported);
			locationsImported = 0;

			int numClearedEA = clearMemoryEA(&earthquakes);
			printf("%d earthquake records cleared\n", numClearedEA);
			earthquakesImported = 0;
		}

		/* COMANDO QUIT */
		else if (strcasecmp(command, "QUIT") == 0)
		{

			if (countryLocations != NULL)
				clearMemoryCL(countryLocations, locationsImported);
			if (earthquakes != NULL)
				clearMemoryEA(&earthquakes);
			if (countryStats != NULL)
				clearMemoryST(&countryStats);

			break;
		}

		/* COMANDO SHOWALL */
		else if (strcasecmp(command, "SHOWALL") == 0)
		{
			if(earthquakesImported == 0) printf("Please load earthquake data first\n");
			else SHOWALL(earthquakes);
		}

		/* COMANDO SHOW_Y */
		else if (strcasecmp(command, "SHOW_Y") == 0)
		{
			if(earthquakesImported == 0) printf("Please load earthquake data first\n");
			else SHOW_Y(earthquakes);
		}

		/* COMANDO SHOW_T */ 
		else if (strcasecmp(command, "SHOW_T") == 0)
		{
			if(earthquakesImported == 0) printf("Please load earthquake data first\n");
			else SHOW_T(earthquakes);
		}

		/* COMANDO SHOW_YT */
		else if (strcasecmp(command, "SHOW_YT") == 0)
		{	
			if(earthquakesImported == 0) printf("Please load earthquake data first\n");
			else SHOW_YT(earthquakes);
		}

		/* COMANDO LIST_T */
		else if (strcasecmp(command, "LIST_T") == 0)
		{	
			if(earthquakesImported == 0 || locationsImported == 0) printf("Please load earthquake and country location data first\n");
			else LIST_T(earthquakes, locationsImported);
		}

		/* COMANDO COUNT */
		else if (strcasecmp(command, "COUNT") == 0)
		{
			if(earthquakesImported == 0) printf("Please load earthquake data first\n");
			else COUNT(earthquakes);
		}

		/* COMANDO HISTOGRAM */
		else if (strcasecmp(command, "HISTOGRAM") == 0)
		{
			if(earthquakesImported == 0) printf("Please load earthquake data first\n");
			else HISTOGRAM(earthquakes);
		}

		/* COMANDO COUNTRY_S */
		else if (strcasecmp(command, "COUNTRY_S") == 0)
		{
			if(statsImported == 0) printf("Please load country statistic data first\n");
			else COUNTRY_S(countryStats);
		}

		/* COMANDO COUNT */
		else if (strcasecmp(command, "REGION_AVG") == 0)
		{
			if(statsImported == 0) printf("Please load country statistic data first\n");
			else REGION_AVG(countryStats);
		}

				/* COMANDO TOPN */
		else if (strcasecmp(command, "TOPN") == 0)
		{
			if (locationsImported == 0 || earthquakesImported == 0) printf("Please load country location data and earthquake data first\n");
			else
			{
				int N;
				printf("Enter the value of N: ");
				readInteger(&N);
				
				// Calcular os dados dos países
				CountryData *countries = malloc(locationsImported * sizeof(CountryData));
				calculateCountryData(earthquakes, countryLocations, locationsImported, countries);
				
				// Obter os N países com mais terremotos
				CountryData *topCountries;
				getTopNCountries(countries, locationsImported, N,topCountries);
				
				// Mostrar os dados dos N países
				showTopNCountries(topCountries, N);
				
				free(countries);
			}
		}

		/* COMANDO INVÁLIDO */
		else printf("Command not found.\n");

		waitForKeypress();
	}

	// TODO: Any memory cleanup before end of program?

	return EXIT_SUCCESS;
}

void printMenu()
{
	printf("\n\n===================================================================================\n");
	printf("                            EarthQuake Data Analysis \n");
	printf("===================================================================================\n");
	printf("A. Base commands (LOADCL, LOADEA, LOADST, CLEAR).\n");
	printf("B. Aggregated info about earthquakes (SHOWALL, SHOW_Y, SHOW_T, SHOW_YT, LIST_T, COUNT, HISTOGRAM\n");
	printf("C. Aggregated info about countries and regions (COUNTRY_S, REGION_AVG).\n");
	printf("D. Complex indicators; require earthquake and country data (TOPN).\n");
	printf("E. Exit (QUIT).\n");
	printf("\nCOMMAND?> ");
}

void waitForKeypress()
{
	printf("Press any key to continue...");
	getchar();
}
