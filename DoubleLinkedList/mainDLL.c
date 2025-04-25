#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "DLL.h"

int main(){
    CityList awal;
    City Kota;


    CreateEmptyHead(&awal);
    InsertKota(&awal, "Bandung");
    InsertKota(&awal, "Jakarta");

    printf("%s", awal.head->kt);

    InsertPerson(&awal, "Bandung", "Amir");
    InsertPerson(&awal, "Jakarta", "Wafi");

    printf("%s", awal.head->persons->info);
    printf("\n");
    printf("%s", awal.head->next->persons->info);
    return 0;
}