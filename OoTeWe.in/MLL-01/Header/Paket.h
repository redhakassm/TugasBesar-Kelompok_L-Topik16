#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED

#include "penyelenggara.h"
#include "destinasi.h"

struct InfotypeRelasi {
    string id_paket;
    string nama_paket;
    string tanggal_keberangkatan;
    double biaya_perjalanan;
    int kuota;
    string status_paket;
};

struct NodeRelasi {
    InfotypeRelasi info;
    adrChild child;
    adrRelasi next;
};

void createListRelasi(adrParent P);
adrRelasi createElementRelasi(InfotypeRelasi x, adrChild C);
void insertFirstRelasi(adrParent P, adrRelasi R);
void insertLastRelasi(adrParent P, adrRelasi R);
void insertAfterRelasi(adrParent P, adrRelasi Prec, adrRelasi R);
void deleteFirstRelasi(adrParent P, adrRelasi &R);
void deleteLastRelasi(adrParent P, adrRelasi &R);
void deleteAfterRelasi(adrParent P, adrRelasi Prec, adrRelasi &R);
adrRelasi searchRelasi(ListParent L, string id_paket, adrParent &parentOut);
void printListRelasiAll(ListParent L);

#endif // PAKET_H_INCLUDED
