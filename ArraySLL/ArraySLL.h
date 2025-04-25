#ifndef ARRAYSLL_H
#define ARRAYSLL_H
#include "lINKED.H"
typedef address personNode;

typedef struct City* CityNode;
typedef struct City
{   
    char* kt;
    personNode persons;
    CityNode next;
}City;

typedef struct CityArr {
    City *kotas;
    int size;
} CityArr;

void CreateEmpty(CityArr *K, int size);
personNode CreatePerson(const char* name);
void PrintInfoKota(CityArr *K);
void DeletePerson(CityArr *K, const char *namaKota,const char *name);
void InsertPerson(CityArr *K, const char *namaKota, const char *name);
void DeleteKota(CityArr *K, const char *namaKota);

#endif