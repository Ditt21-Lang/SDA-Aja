#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "linked.h"
#include "ArraySLL.h"

int main(){
    CityArr array_kota;
    char name[100];
    char nameKota[100];
    char namaOrang[100];
    char oh;
    int opsi;
    boolean isLagi = true;

    printf("Masukkan jumlah Kota: ");
    scanf("%d", &array_kota.size);

    if(array_kota.size < 5){
        printf("Kecil bro, minimal 5");
        return -1;
    }else{
        CreateEmpty(&array_kota, array_kota.size);
    }

	int i;
    for(i = 0; i < array_kota.size; i++){
        printf("Masukkan Kota ke-%d: ", i);
        scanf("%s", name);
        
        array_kota.kotas[i].kt = (char*)malloc(sizeof(char) * (strlen(name) + 1));
        strcpy(array_kota.kotas[i].kt, name);
        
    }
    PrintInfoKota(&array_kota);

    while (isLagi){
        printf("Pilih Opsi: \n");
        printf("1. Insert Person\n2. Delete Person\n3. Delete Kota\nPilih 1,2, atau 3: ");
        scanf("%d", &opsi);

        if(opsi == 1){
            printf("Masukkan dimana orang tersebut akan dimasukkan: ");
            scanf("%s", nameKota);
            printf("Masukkan nama orang tersebut: ");
            scanf("%s", namaOrang);
			
            InsertPerson(&array_kota, nameKota, strdup(namaOrang));
			PrintInfoKota(&array_kota);
        }
        else if (opsi == 2){
            printf("Masukkan dimana orang tersebut berada: ");
            scanf("%s", nameKota);
            printf("Masukkan nama orang tersebut: ");
            scanf("%s", namaOrang);

            DeletePerson(&array_kota, nameKota, namaOrang);
            PrintInfoKota(&array_kota);
        }
        else if(opsi == 3){
            printf("Masukkan nama kota tersebut: ");
            scanf("%s", nameKota);

            DeleteKota(&array_kota, nameKota);
            PrintInfoKota(&array_kota);
        }

        printf("Mau lagi? (Y/N): ");
        scanf(" %c", &oh);
        if(oh == 'N' || oh == 'n'){
            isLagi = false;
        }
    }

    PrintInfoKota(&array_kota);
    return 0;
}
