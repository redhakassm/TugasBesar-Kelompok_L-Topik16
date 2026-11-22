#include "../../Header/Destinasi.h"

void createListChild(ListChild &L) {
    L.first = nullptr;
}

adrChild createElementChild(InfotypeChild x) {
    adrChild newNode = new NodeChild;
    if (newNode != nullptr) {
        newNode->info = x;
        newNode->next = nullptr;
    }
    return newNode;
}

void insertFirstChild(ListChild &L, adrChild C) {
    if (C == nullptr) return;
    C->next = L.first;
    L.first = C;
}

void appendChildRecursive(adrChild &curr, adrChild C) {
    if (curr == nullptr) {
        curr = C;
    } else {
        appendChildRecursive(curr->next, C);
    }
}

void insertLastChild(ListChild &L, adrChild C) {
    if (C == nullptr) return;
    appendChildRecursive(L.first, C);
}

void insertAfterChild(ListChild &L, adrChild Prec, adrChild C) {
    if (Prec == nullptr || C == nullptr) return;
    C->next = Prec->next;
    Prec->next = C;
}

void deleteFirstChild(ListChild &L, adrChild &C) {
    if (L.first == nullptr) {
        C = nullptr;
        return;
    }
    C = L.first;
    L.first = C->next;
    C->next = nullptr;
}

void deleteLastChild(ListChild &L, adrChild &C) {
    if (L.first == nullptr) {
        C = nullptr;
        return;
    }

    adrChild curr = L.first;
    adrChild prev = nullptr;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    C = curr;
    if (prev == nullptr) {
        L.first = nullptr;
    } else {
        prev->next = nullptr;
    }
}

void deleteAfterChild(ListChild &L, adrChild Prec, adrChild &C) {
    if (Prec == nullptr || Prec->next == nullptr) {
        C = nullptr;
        return;
    }
    C = Prec->next;
    Prec->next = C->next;
    C->next = nullptr;
}

adrChild searchChildRecursive(adrChild curr, const string &id_destinasi) {
    if (curr == nullptr) return nullptr;
    if (curr->info.id_destinasi == id_destinasi) return curr;
    return searchChildRecursive(curr->next, id_destinasi);
}

adrChild searchChild(ListChild L, string id_destinasi) {
    return searchChildRecursive(L.first, id_destinasi);
}

void printListChild(ListChild L) {
    cout << "--- DATA DESTINASI WISATA ---" << endl;
    if (L.first == nullptr) {
        cout << "(Belum ada data destinasi)" << endl;
        return;
    }

    int nomor = 1;
    for (adrChild curr = L.first; curr != nullptr; curr = curr->next) {
        cout << nomor++ << ". ID: " << curr->info.id_destinasi
             << " | Nama: " << curr->info.nama_destinasi
             << " (" << curr->info.lokasi << " - " << curr->info.kategori_wisata << ")" << endl;
    }
    cout << "=============================" << endl;
}
