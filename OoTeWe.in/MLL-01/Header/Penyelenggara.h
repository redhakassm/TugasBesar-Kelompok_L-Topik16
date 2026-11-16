#ifndef PENYELENGGARA_H_INCLUDED
#define PENYELENGGARA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct InfotypeParent {
    string id_penyelenggara;
    string nama;
    string alamat;
    string kontak;
};

typedef struct NodeParent* adrParent;
typedef struct NodeRelasi* adrRelasi;

struct NodeParent {
    InfotypeParent info;
    adrRelasi firstRelasi;
    adrParent next;
};

struct ListParent {
    adrParent first;
};

void createListParent(ListParent &L);
adrParent createElementParent(InfotypeParent x);
void insertFirstParent(ListParent &L, adrParent P);
void insertLastParent(ListParent &L, adrParent P);
void insertAfterParent(ListParent &L, adrParent Prec, adrParent P);
void deleteFirstParent(ListParent &L, adrParent &P);
void deleteLastParent(ListParent &L, adrParent &P);
void deleteAfterParent(ListParent &L, adrParent Prec, adrParent &P);
adrParent searchParent(ListParent L, string id_penyelenggara);
void printListParent(ListParent L);

#endif // PENYELENGGARA_H_INCLUDED
