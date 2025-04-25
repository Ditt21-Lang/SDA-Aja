/* File        : spNRSLL.h */
/* Deskripsi   : ADT ListCity berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#ifndef LINKED_CITY_H
#define LINKED_CITY_H
#include "boolean.h"
#include <stdio.h>
#include "linked.h"
typedef address personNode;

typedef struct City
{   
    char* kt;
    personNode persons;
}City;

#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef City infotype_city;
typedef struct tElmtListCity *address_city;
typedef struct tElmtListCity {
	 infotype_city info;
	 address_city  next;
	 } ElmtListCity;

/* Definisi ListCity : */
/* ListCity kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir ListCity ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct {
	  address_city First;
} ListCity;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan ListCity  ****/
boolean ListCityEmpty (ListCity L);
/* Mengirim true jika ListCity Kosong */

/**** Konstruktor/Kreator ListCity Kosong ****/
void CreateListCity (ListCity * L);
/* IS : L sembarang */
/* FS : Terbentuk ListCity Kosong */

/**** Manajemen Memory ****/
address_city AlokasiCity (infotype_city X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlokasiCity (address_city P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** Pencarian sebuah elemen ListCity ****/
address_city SearchCity (ListCity L, infotype_city X);
/* Mencari apakah ada elemen ListCity dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

boolean FSearchCity (ListCity L, address_city P);
/* Mencari apakah ada elemen ListCity yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

address_city SearchPrecCity (ListCity L, infotype_city X);
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen ListCity dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirstCity (ListCity * L, infotype_city X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLastCity (ListCity * L, infotype_city X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListCity di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */

/**** Penghapusan Elemen ****/
void DelVFirstCity (ListCity * L, infotype_city * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama ListCity dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

void DelVLastCity (ListCity * L, infotype_city * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir ListCity dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirstCity (ListCity * L, address_city P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfterCity (ListCity * L, address_city P, address_city Prec);
/* IS : Prec pastilah elemen ListCity dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert PCity sebagai elemen sesudah elemen beralamat Prec */

void InsertLastCity (ListCity * L, address_city P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

/**** Penghapusan sebuah elemen ****/
void DelFirstCity (ListCity * L, address_city * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama ListCity sebelum penghapusan */
/*	elemen ListCity berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void DelPCity (ListCity * L, infotype_city X);
/* IS : L sembarang */
/* FS : Jika ada elemen ListCity beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari ListCity dan di dealokasi */
/* Jika tidak ada elemen ListCity dengan Info(P) = X, maka ListCity tetap */
/* ListCity mungkin menjadi kosong karena penghapusan */

void DelLastCity (ListCity * L, address_city * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir ListCity sebelum penghapusan */
/*	Elemen ListCity berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

void DelAfterCity (ListCity * L, address_city * Pdel, address_city Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota ListCity */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen ListCity yang dihapus */

/**** PROSES SEMUA ELEMEN ListCity  ****/
void PrintInfoCity (ListCity L);
/* IS : L mungkin kosong */
/* FS : Jika ListCity tidak kosong, semua info yang disimpan pada elemen ListCity */
/*	diprint. Jika ListCity kosong, hanya menuliskan "ListCity Kosong" */


/***************************************/
/*******  PROSES TERHADAP ListCity  ********/
/***************************************/

void DelAllCity (ListCity * L);
/* Delete semua elemen ListCity dan alamat elemen di dealokasi */

#endif
