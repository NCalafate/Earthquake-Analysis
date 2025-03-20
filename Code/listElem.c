#include <stdio.h>
#include "listElem.h"

void listElemPrint(ListElem elem) {
    printf("List Element: {\n");
	printf("\tID: %d\n", elem.id);
	printf("\tCountry Code: %s\n", elem.countryCode);
    printf("\tDate: {\n");
	printf("\t\tDay: %d\n", elem.date.day);
	printf("\t\tMonth: %d\n", elem.date.month);
	printf("\t\tYear: %d\n", elem.date.year);
	printf("\t}\n");
	printf("\tTime: {\n");
	printf("\t\tHours: %d\n", elem.time.hour);
	printf("\t\tMinutes: %d\n", elem.time.min);
	printf("\t\tSeconds: %d\n", elem.time.sec);
	printf("\t}\n");
	printf("\tLatitude: %f\n", elem.latitude);
	printf("\tLongitude: %f\n", elem.longitude);
	printf("\tType: %s\n", elem.type);
	printf("\tDepth: %f\n", elem.depth);
	printf("\tMagnitude: %f\n", elem.magnitude); 
	printf("\tMagnitude Type: %s\n", elem.magnitudeType);
	printf("}\n");
}