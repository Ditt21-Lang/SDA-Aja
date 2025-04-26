#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "linked_city.h"
#include "DLL.h"

int main(){
    
    City Kota; 
    ListCity awal;
    char nameKota[100];
    char namaOrang[100];
    char oh;
    int opsi, baru;
    boolean isLagi = true;


    printf("Masukkan jumlah Kota: ");
    scanf("%d", &baru);

    if(baru < 5){
        printf("Kecil bro, minimal 5");
        return -1;
    }else{
        CreateListCity(&awal);
    }
	
	int i;
    for( i = 0; i < baru; i++){
        printf("Masukkan Kota ke-%d: ", i);
        scanf("%s", nameKota);
        
        InsertKota(&awal, nameKota);
    }
    PrintInfoCity(awal);
    printf("\n");
    while (isLagi){
        printf("Pilih Opsi: \n");
        printf("1. Insert Person\n2. Delete Person\n3. Delete Kota\nPilih 1,2, atau 3: ");
        scanf("%d", &opsi);

        if(opsi == 1){
            printf("Masukkan dimana orang tersebut akan dimasukkan: ");
            scanf("%s", nameKota);
            printf("Masukkan nama orang tersebut: ");
            scanf("%s", namaOrang);

            InsertPerson(&awal, nameKota, strdup(namaOrang));
            printf("\n");
            PrintInfoCity(awal);
        }
        else if (opsi == 2){
            printf("Masukkan dimana orang tersebut berada: ");
            scanf("%s", nameKota);
            printf("Masukkan nama orang tersebut: ");
            scanf("%s", namaOrang);

            DeletePerson(&awal, nameKota, namaOrang);
            printf("\n");
            PrintInfoCity(awal);
        }
        else if(opsi == 3){
            printf("Masukkan nama kota tersebut: ");
            scanf("%s", nameKota);

            DeleteCity(&awal, nameKota);
            printf("\n");
            PrintInfoCity(awal);
        }

        printf("Mau lagi? (Y/N): ");
        scanf(" %c", &oh);
        if(oh == 'N' || oh == 'n'){
            isLagi = false;
        }
        printf("\n");
    }

    return 0;
}
