#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "DLL.h"

void CreateEmptyHead(CityList* awal){
    awal->head = Nil;
}

void InsertKota( CityList* awal , const char* namaKota){
    CityNode kotaBaru = (CityNode)malloc(sizeof(City));
    kotaBaru->kt = malloc(strlen(namaKota) + 1);
    strcpy(kotaBaru->kt, namaKota);
    kotaBaru->next = Nil;
    kotaBaru->persons = Nil;
    if(awal->head == Nil){
        awal->head = kotaBaru;
    }else{
        CityNode temp = awal->head;
        while (temp->next != Nil){\
            temp = temp->next;
        }
        temp->next = kotaBaru;
    }
}

void InsertPerson( CityList* awal ,const char* namaKota, const char* name){
    CityNode current = awal->head;
    while(current != NULL){
        if(strcmp(current->kt, namaKota) == 0){
            List tempList;
            tempList.First = current->persons;
            InsVLast(&tempList, name);
            current->persons = tempList.First;
            return;
        }
        current = current->next;
    }
}