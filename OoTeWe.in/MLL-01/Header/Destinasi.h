#ifndef DESTINASI_H_INCLUDED
#define DESTINASI_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct InfotypeChild {
    string id_destinasi;
    string nama_destinasi;
    string lokasi;
    string kategori_wisata;
};

typedef struct NodeChild* adrChild;

struct NodeChild {
    InfotypeChild info;
    adrChild next;
};

struct ListChild {
    adrChild first;
};

void createListChild(ListChild &L);
adrChild createElementChild(InfotypeChild x);
void insertFirstChild(ListChild &L, adrChild C);
void insertLastChild(ListChild &L, adrChild C);
void insertAfterChild(ListChild &L, adrChild Prec, adrChild C);
void deleteFirstChild(ListChild &L, adrChild &C);
void deleteLastChild(ListChild &L, adrChild &C);
void deleteAfterChild(ListChild &L, adrChild Prec, adrChild &C);
adrChild searchChild(ListChild L, string id_destinasi);
void printListChild(ListChild L);

#endif // DESTINASI_H_INCLUDED
