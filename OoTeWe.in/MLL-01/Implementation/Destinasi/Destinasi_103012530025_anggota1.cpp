#include "../../Header/Destinasi.h"

void createListChild(ListChild &L) {
    L.first = NULL;
}

adrChild createElementChild(InfotypeChild x) {
    adrChild C = new NodeChild;
    C->info = x;
    C->next = NULL;
    return C;
}

void insertFirstChild(ListChild &L, adrChild C) {
    if (L.first == NULL) {
        L.first = C;
    } else {
        C->next = L.first;
        L.first = C;
    }
}

void insertLastChild(ListChild &L, adrChild C) {
    if (L.first == NULL) {
        L.first = C;
    } else {
        adrChild Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = C;
    }
}

void insertAfterChild(ListChild &L, adrChild Prec, adrChild C) {
    if (Prec != NULL) {
        C->next = Prec->next;
        Prec->next = C;
    }
}

void deleteFirstChild(ListChild &L, adrChild &C) {
    if (L.first != NULL) {
        C = L.first;
        L.first = L.first->next;
        C->next = NULL;
    } else {
        C = NULL;
    }
}

void deleteLastChild(ListChild &L, adrChild &C) {
    if (L.first == NULL) {
        C = NULL;
    } else if (L.first->next == NULL) {
        C = L.first;
        L.first = NULL;
    } else {
        adrChild Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        C = Q->next;
        Q->next = NULL;
    }
}

void deleteAfterChild(ListChild &L, adrChild Prec, adrChild &C) {
    if (Prec != NULL && Prec->next != NULL) {
        C = Prec->next;
        Prec->next = C->next;
        C->next = NULL;
    } else {
        C = NULL;
    }
}

adrChild searchChild(ListChild L, string id_destinasi) {
    adrChild C = L.first;
    while (C != NULL) {
        if (C->info.id_destinasi == id_destinasi) {
            return C;
        }
        C = C->next;
    }
    return NULL;
}

void printListChild(ListChild L) {
    adrChild C = L.first;
    cout << "=== DAFTAR DESTINASI (CHILD) ===" << endl;
    while (C != NULL) {
        cout << "[" << C->info.id_destinasi << "] " << C->info.nama_destinasi
             << " | Lokasi: " << C->info.lokasi
             << " | Kategori: " << C->info.kategori_wisata << endl;
        C = C->next;
    }
    cout << "--------------------------------" << endl;
}
