#include "../../Header/Penyelenggara.h"

void createListParent(ListParent &L) {
    L.first = nullptr;
}

adrParent createElementParent(InfotypeParent x) {
    adrParent newNode = new NodeParent;
    if (newNode != nullptr) {
        newNode->info = x;
        newNode->firstRelasi = nullptr;
        newNode->next = nullptr;
    }
    return newNode;
}

void insertFirstParent(ListParent &L, adrParent P) {
    if (P == nullptr) return;
    P->next = L.first;
    L.first = P;
}

// Fungsi bantuan rekursif untuk menyambung node parent di akhir list
void appendParentRecursive(adrParent &curr, adrParent P) {
    if (curr == nullptr) {
        curr = P;
    } else {
        appendParentRecursive(curr->next, P);
    }
}

void insertLastParent(ListParent &L, adrParent P) {
    if (P == nullptr) return;
    appendParentRecursive(L.first, P);
}

void insertAfterParent(ListParent &L, adrParent Prec, adrParent P) {
    if (Prec == nullptr || P == nullptr) return;
    P->next = Prec->next;
    Prec->next = P;
}

void deleteFirstParent(ListParent &L, adrParent &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }
    P = L.first;
    L.first = P->next;
    P->next = nullptr;
}

// Menggunakan dua pointer (prev & curr) sebagai ganti pengecekan next->next
void deleteLastParent(ListParent &L, adrParent &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }

    adrParent curr = L.first;
    adrParent prev = nullptr;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    P = curr;
    if (prev == nullptr) {
        L.first = nullptr;
    } else {
        prev->next = nullptr;
    }
}

void deleteAfterParent(ListParent &L, adrParent Prec, adrParent &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    P->next = nullptr;
}

// Pencarian rekursif pada list parent
adrParent searchParentRecursive(adrParent curr, const string &id_penyelenggara) {
    if (curr == nullptr) return nullptr;
    if (curr->info.id_penyelenggara == id_penyelenggara) return curr;
    return searchParentRecursive(curr->next, id_penyelenggara);
}

adrParent searchParent(ListParent L, string id_penyelenggara) {
    return searchParentRecursive(L.first, id_penyelenggara);
}

void printListParent(ListParent L) {
    cout << "--- DATA PENYELENGGARA OPEN TRIP ---" << endl;
    if (L.first == nullptr) {
        cout << "(Belum ada data penyelenggara)" << endl;
        return;
    }

    int nomor = 1;
    for (adrParent curr = L.first; curr != nullptr; curr = curr->next) {
        cout << nomor++ << ". ID: " << curr->info.id_penyelenggara
             << " | Nama: " << curr->info.nama
             << " | Alamat: " << curr->info.alamat
             << " | Kontak: " << curr->info.kontak << endl;
    }
    cout << "====================================" << endl;
}
