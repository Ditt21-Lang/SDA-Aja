#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <malloc.h>
#include "linked.h"
#include "ArraySLL.h"

void CreateEmpty(CityArr *K, int size){
    K->kotas = (City*)malloc(sizeof(City) * size);
    int i;
	for( i = 0; i < size; i++){
        K->kotas[i].persons = Nil;
    } 
    K->size = size;
}


void PrintInfoKota(CityArr *cityArr){
    City* K = cityArr->kotas;
    int i;
	for ( i = 0; i < cityArr->size; i++){
        printf("%s -> ", K[i].kt);
        personNode current = K[i].persons;
        while (current != NULL){
            printf("%s -> ", current->info);
            current = current->next;
        }
        printf("NULL");
        printf("\n");
    }
    printf("\n");
}

void DeletePerson(CityArr *cityArr, const char *namaKota ,const char *name){
    City* K = cityArr->kotas;
    int i;
	for ( i = 0; i < cityArr->size; i++){
        if(strcmp(K[i].kt, namaKota) == 0){
            personNode current = K[i].persons;
            List Biji;
            personNode simpan;
            Biji.First = current;
            simpan = Search(Biji, name);

            if (simpan != NULL){
                DelP(&Biji, name);
                printf("Deleted from kota %s\n", K[i].kt);
                K[i].persons = Biji.First;
            } 
        }
    }
}

void InsertPerson(CityArr *cityArr, const char *namaKota, const char *name){
    City* K = cityArr->kotas;
    int i;
	for ( i = 0; i < cityArr->size; i++){
        if (strcmp(K[i].kt, namaKota) == 0){
            List Biji;
            personNode current = K[i].persons;
            Biji.First = current;
            InsVLast(&Biji, name);
            K[i].persons = Biji.First;
            printf("Insert Berhasil\n");
            return;
        }
    printf("\n");
    }
}

void DeleteKota(CityArr *cityArr, const char *name){
    City* K = cityArr->kotas;
    int i;
	for ( i = 0; i < cityArr->size; i++){
        if(strcmp(K[i].kt, name) == 0){
            List Biji;
            Biji.First = K[i].persons;
            DelAll(&Biji);
            K[i].persons = Biji.First;
            K[i].kt[0] = '\0';
        }
    }
}
