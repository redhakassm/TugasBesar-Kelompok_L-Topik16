#include "../../Header/Paket.h"

void createListRelasi(adrParent P) {
    if (P != nullptr) {
        P->firstRelasi = nullptr;
    }
}

adrRelasi createElementRelasi(InfotypeRelasi x, adrChild C) {
    adrRelasi newNode = new NodeRelasi;
    if (newNode != nullptr) {
        newNode->info = x;
        newNode->child = C;
        newNode->next = nullptr;
    }
    return newNode;
}

void insertFirstRelasi(adrParent P, adrRelasi R) {
    if (P == nullptr || R == nullptr) return;
    R->next = P->firstRelasi;
    P->firstRelasi = R;
}

void appendRelasiRecursive(adrRelasi &curr, adrRelasi R) {
    if (curr == nullptr) {
        curr = R;
    } else {
        appendRelasiRecursive(curr->next, R);
    }
}

void insertLastRelasi(adrParent P, adrRelasi R) {
    if (P == nullptr || R == nullptr) return;
    appendRelasiRecursive(P->firstRelasi, R);
}

void insertAfterRelasi(adrParent P, adrRelasi Prec, adrRelasi R) {
    if (P == nullptr || Prec == nullptr || R == nullptr) return;
    R->next = Prec->next;
    Prec->next = R;
}

void deleteFirstRelasi(adrParent P, adrRelasi &R) {
    if (P == nullptr || P->firstRelasi == nullptr) {
        R = nullptr;
        return;
    }
    R = P->firstRelasi;
    P->firstRelasi = R->next;
    R->next = nullptr;
}

void deleteLastRelasi(adrParent P, adrRelasi &R) {
    if (P == nullptr || P->firstRelasi == nullptr) {
        R = nullptr;
        return;
    }

    adrRelasi curr = P->firstRelasi;
    adrRelasi prev = nullptr;

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    R = curr;
    if (prev == nullptr) {
        P->firstRelasi = nullptr;
    } else {
        prev->next = nullptr;
    }
}

void deleteAfterRelasi(adrParent P, adrRelasi Prec, adrRelasi &R) {
    if (P == nullptr || Prec == nullptr || Prec->next == nullptr) {
        R = nullptr;
        return;
    }
    R = Prec->next;
    Prec->next = R->next;
    R->next = nullptr;
}

adrRelasi findRelasiInParent(adrRelasi curr, const string &id_paket) {
    if (curr == nullptr) return nullptr;
    if (curr->info.id_paket == id_paket) return curr;
    return findRelasiInParent(curr->next, id_paket);
}

adrRelasi searchRelasi(ListParent L, string id_paket, adrParent &parentOut) {
    parentOut = nullptr;
    for (adrParent P = L.first; P != nullptr; P = P->next) {
        adrRelasi found = findRelasiInParent(P->firstRelasi, id_paket);
        if (found != nullptr) {
            parentOut = P;
            return found;
        }
    }
    return nullptr;
}

void printListRelasiAll(ListParent L) {
    cout << "--- LIST PAKET OPEN TRIP (MLL) ---" << endl;
    if (L.first == nullptr) {
        cout << "(Belum ada data penyelenggara)" << endl;
        return;
    }

    for (adrParent P = L.first; P != nullptr; P = P->next) {
        cout << "Penyelenggara: " << P->info.nama << " (ID: " << P->info.id_penyelenggara << ")" << endl;
        if (P->firstRelasi == nullptr) {
            cout << "   -> Tidak ada paket tersedia" << endl;
        } else {
            int idx = 1;
            for (adrRelasi R = P->firstRelasi; R != nullptr; R = R->next) {
                string namaDest = (R->child != nullptr) ? R->child->info.nama_destinasi : "Belum ditentukan";
                cout << "   " << idx++ << ". [" << R->info.id_paket << "] " << R->info.nama_paket
                     << " | Tgl: " << R->info.tanggal_keberangkatan
                     << " | Biaya: Rp " << R->info.biaya_perjalanan
                     << " | Kuota: " << R->info.kuota
                     << " | Destinasi: " << namaDest << endl;
            }
        }
    }
    cout << "==================================" << endl;
}
