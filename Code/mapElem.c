/**
 * @file mapElem.c
 * @brief Implements operations for types MapKey and MapValue.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "mapElem.h"
#include <string.h>
#include <stdio.h>

void mapKeyPrint(MapKey key) {
	printf("Map Key: %s\n", key.text);
}

void mapValuePrint(MapValue value) {
	printf("Map Value: {\n");
	printf("\tCountry Code: %s\n", value.code);
	printf("\tCountry: %s\n", value.name);
    printf("\tRegion: %s\n", value.region);
	printf("\tPopulation: %ld\n", value.population);
	printf("\tArea: %ld\n", value.area);
	printf("\tGDP: %ld\n", value.gdp_capita);
	printf("\tLiteracy: %f\n", value.literacy);
	printf("\tBirthrate: %f\n", value.birthrate);
	printf("\tDeathrate: %f\n", value.deathrate);
	printf("}\n");
}

bool mapKeyEquals(MapKey key1, MapKey key2) {
	return (strcmp(key1.text, key2.text) == 0);
}