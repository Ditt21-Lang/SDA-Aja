#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "linked_city.h"
#include "DLL.h"

int main(){
    
    City Kota; 
    ListCity awal;


    CreateListCity(&awal);
    InsertKota(&awal, "Bandung");
    InsertKota(&awal, "Jakarta");

    InsertPerson(&awal, "Bandung", "Amir");
    InsertPerson(&awal, "Jakarta", "Wafi");

    PrintInfoCity(awal);
    
    return 0;
}