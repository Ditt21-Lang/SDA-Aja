#ifndef DLL_H
#define DLL_H
#include "linked.h"
typedef address personNode;

typedef struct City* CityNode;
typedef struct City
{   
    char* kt;
    personNode persons;
    CityNode next;
}City;

typedef struct
{
    CityNode head;
}CityList;

void CreateEmptyHead(CityList *awal);
void InsertKota(CityList* awal , const char* namaKota);
void InsertPerson( CityList* awal ,const char* namaKota, const char* name);

#endif