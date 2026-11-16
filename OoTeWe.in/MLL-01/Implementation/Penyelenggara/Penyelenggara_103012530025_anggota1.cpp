#include "../../Header/Penyelenggara.h"

void createListParent(ListParent &L) {
    L.first = NULL;
}

adrParent createElementParent(InfotypeParent x) {
    adrParent P = new NodeParent;
    P -> info = x;
    P -> firstRelasi = NULL;
    P -> next = NULL;
    return P;
}

void insertFirstParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P -> next = L.first;
        L.first = P;
    }
}

void insertLastParent(ListParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adrParent Q = L.first;
        while (Q -> next != NULL) {
            Q = Q -> next;
        }
        Q -> next = P;
    }
}

void insertAfterParent(ListParent &L, adrParent Prec, adrParent P) {
    if (Prec != NULL) {
        P -> next = Prec -> next;
        Prec -> next = P;
    }
}

void deleteFirstParent(ListParent &L, adrParent &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = L.first -> next;
        P -> next = NULL;
    } else {
        P = NULL;
    }
}

void deleteLastParent(ListParent &L, adrParent &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first -> next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        adrParent Q = L.first;
        while (Q -> next -> next != NULL) {
            Q = Q -> next;
        }
        P = Q -> next;
        Q -> next = NULL;
    }
}

void deleteAfterParent(ListParent &L, adrParent Prec, adrParent &P) {
    if (Prec != NULL && Prec -> next != NULL) {
        P = Prec -> next;
        Prec -> next = P->next;
        P -> next = NULL;
    } else {
        P = NULL;
    }
}

adrParent searchParent(ListParent L, string id_penyelenggara) {
    adrParent P = L.first;
    while (P != NULL) {
        if (P -> info.id_penyelenggara == id_penyelenggara) {
            return P;
        }
        P = P -> next;
    }
    return NULL;
}

void printListParent(ListParent L) {
    adrParent P = L.first;
    cout << "=== DAFTAR PENYELENGGARA (PARENT) ===" << endl;
    while (P != NULL) {
        cout << "[" << P->info.id_penyelenggara << "] " << P -> info.nama
             << " | Alamat: " << P -> info.alamat
             << " | Kontak: " << P -> info.kontak << endl;
        P = P -> next;
    }
    cout << "------------------------------------" << endl;
}
