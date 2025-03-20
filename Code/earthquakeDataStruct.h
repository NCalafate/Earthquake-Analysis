/** @file earthquakeDataStruct.h
 *  @brief Estruturas relevantes à implementação dos terramotos.
 * 
 *  @bug No known bugs.
 */
#pragma once

/**
 * @brief Estrutura da data.
 * 
 */
typedef struct date {
    int day;
    int month;
    int year;
} Date;

/**
 * @brief Estrutura da hora.
 * 
 */ 
typedef struct time {
    int hour;
    int min;
    int sec;
} Time;

/**
 * @brief Estrutura do terramoto.
 * 
 */
typedef struct earthquake {
    int id;
    // Código de 2 letras do país ou território mais próximo (countryLocation)
    char countryCode[3]; // Calculado a partir das localizações durante importação
    Date date;
    Time time;
    float latitude;
    float longitude; 
    char type[20]; // Earthquake | Explosion | Nuclear Explosion | Rock Burst
    float depth;
    float magnitude;
    char magnitudeType[3]; // MB | MD | MH | ML | MS | MW
} Earthquake;
