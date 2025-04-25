#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "linked_city.h"
#include "DLL.h"



void InsertKota(ListCity* awal , const char* namaKota){
    infotype_city ingfo = {
        .kt = strdup(namaKota),
        .persons = NULL,
    };
    address_city city = AlokasiCity(ingfo);
    InsertLastCity(awal, city);
}

void InsertPerson( ListCity* awal , const char* namaKota, const char* name){
    infotype_city ingfo = {
        .kt = namaKota,
        .persons = Nil,
    };

    address_city ketemu =  SearchCity(*awal, ingfo);

    if(!ketemu) {
        printf("Nama kota yang kamu cari tidak ditemukan :<");
        return;
    }   
    List l;
    l.First = ketemu->info.persons;

    InsVLast(&l, name);
    ketemu->info.persons = l.First;
}