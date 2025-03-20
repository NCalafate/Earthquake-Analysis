# Earthquake Analysis - Statistical Processing and Data Visualization

## Table of Contents
- [Introduction](#introduction)
- [Abstract Data Types (ADTs) Used](#abstract-data-types-adts-used)
- [Algorithm Complexities](#algorithm-complexities)
- [Implemented Algorithms](#implemented-algorithms)
- [Project Limitations](#project-limitations)
- [Conclusions](#conclusions)

---

## Introduction
This project involves the development of a C program designed to extract and present useful insights from a dataset containing information about natural and artificial earthquakes occurring in various countries. 

The program functions as a command-line interpreter, allowing users to obtain statistical data on recorded earthquakes. Data is managed through specific Abstract Data Types (ADTs), ensuring efficient storage and retrieval. 

The earthquake data is stored in a **List ADT** called `Earthquake`, which contains details such as date, time, location, and other event specifics. The statistical information for each country is represented by the `CountryStatistics` structure, while geographical locations are stored in the `CountryLocation` structure.

---

## Abstract Data Types (ADTs) Used

### **List ADT**
- **Sequential Access**: Allows iteration through the list in a sequential order.
- **Direct Index Access**: Enables retrieving a specific element using an index.

| Operation  | Array List | Linked List |
|------------|-----------|------------|
| `stackPush` | O(1) | O(1) |
| `stackPop` | O(1) | O(1) |
| `stackPeek` | O(1) | O(1) |

### **Map ADT**
- **Key-Based Access**: Retrieves values associated with specific keys.

| Operation  | Array List | Linked List |
|------------|-----------|------------|
| `mapPut` | O(n) | O(n) |
| `mapRemove` | O(n) | O(n) |
| `mapGet` | O(n) | O(n) |
| `mapContains` | O(n) | O(n) |

---

## Algorithm Complexities

### **Data Loading Functions**
| Function | Complexity | Justification |
|----------|------------|---------------|
| `LOADCL(int* numImported)` | O(n) | Reads a CSV file and creates an array of `CountryLocation` structures. |
| `LOADEA(int* numImported, CountryLocation* locarr, int locsz)` | O(n) | Reads a CSV file and creates a list of `Earthquake` records. |
| `LOADST(int* numImported)` | O(n) | Reads a CSV file and creates a `Map` with earthquake statistics. |
| `clearMemoryST(PtMap *map)` | O(n) | Frees memory allocated for the map. |
| `clearMemoryCL(CountryLocation *countries, int size)` | O(1) | Frees memory allocated for the `CountryLocation` array. |
| `clearMemoryEA(PtList *list)` | O(n) | Frees memory allocated for the earthquake list. |
| `QUIT()` | O(1) | Exits the program with no complex operations. |

### **Data Query Functions**
| Function | Complexity | Description |
|----------|------------|-------------|
| `SHOWALL(PtList list)` | O(n) | Iterates through the list to display earthquake records. |
| `SHOW_Y(PtList list)` | O(n) | Filters and displays records by year. |
| `SHOW_T(PtList list)` | O(n) | Filters and displays records by country code. |
| `SHOW_YT(PtList list)` | O(n) | Filters records by both year and country code. |
| `LIST_T(PtList list, int numRecords)` | O(n) | Displays earthquake data grouped by country. |
| `COUNT(PtList earthquake)` | O(n) | Counts the number of earthquakes meeting user-specified criteria. |

---

## Implemented Algorithms

### **SHOWALL**
This function displays earthquake records in a structured table format. It includes pagination, allowing users to navigate through records efficiently.

### **COUNT**
This function allows users to filter earthquakes by magnitude range and country code. It calculates the percentage distribution of different earthquake types.

### **Histogram Generation**
A histogram function was implemented to provide a visual representation of earthquake occurrences by magnitude range.

### **Top N Countries**
This function sorts countries based on earthquake activity, considering factors such as literacy rate and GDP per capita. Sorting is performed using a selection-based approach.

---

## Project Limitations
- The **Top N Countries** function currently does not handle all cases correctly, requiring further optimization.
- Performance may degrade for very large datasets due to the use of O(n²) sorting methods.

---

## Conclusions
This project successfully developed a C program to process and analyze earthquake data using Abstract Data Types. 

Key achievements include:
- **Efficient Data Organization**: Implemented `List` and `Map` ADTs for structured data storage.
- **Comprehensive Statistics**: Users can retrieve country-specific earthquake statistics.
- **Scalability Considerations**: Designed functions with optimized algorithmic complexity.
