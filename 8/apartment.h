#ifndef apartment_h
#define apartment_h

#include "apartment.cpp"

bool isFamilySuitable(int roomCount, int livingSpace);
Apartment *createArr (int size);
Apartment *appendArr (Apartment *arr, int size, char* address, int roomCount, int livingSpace, bool hasBalcony);
Apartment *removeArr(Apartment *arr, int size, int index);
void showApartments(Apartment *arr, int size);
void showSortedApartments(Apartment *arr, int* sortPattern, int size);
int* sortArrMax(Apartment *arr, int len, int value);
int* sortArrMin(Apartment *arr, int len, int value);

#endif