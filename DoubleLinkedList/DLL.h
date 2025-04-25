#ifndef DLL_H
#define DLL_H
#include "linked_city.h"


typedef struct City* CityNode;


// typedef struct
// {
//     CityNode head;
// }CityList;

void CreateEmptyHead(ListCity *awal);
void InsertKota(ListCity* awal , const char* namaKota);
void InsertPerson( ListCity* awal ,const char* namaKota, const char* name);

#endif