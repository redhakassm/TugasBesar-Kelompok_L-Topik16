#include "../../Header/Paket.h"

adrRelasi createElementRelasi(InfotypeRelasi x, adrChild C) {
    adrRelasi R = new NodeRelasi;
    R -> info = x;
    R -> child = C;
    R -> next = NULL;
    return R;
}

void insertFirstRelasi(adrParent P, adrRelasi R) {
    if (P != NULL) {
        R -> next = P -> firstRelasi;
        P -> firstRelasi = R;
    }
}

void insertLastRelasi(adrParent P, adrRelasi R) {
    if (P != NULL) {
        if (P -> firstRelasi == NULL) {
            P -> firstRelasi = R;
        } else {
            adrRelasi Q = P -> firstRelasi;
            while (Q -> next != NULL) {
                Q = Q -> next;
            }
            Q -> next = R;
        }
    }
}

void insertAfterRelasi(adrParent P, adrRelasi Prec, adrRelasi R) {
    if (Prec != NULL) {
        R -> next = Prec -> next;
        Prec -> next = R;
    }
}

void deleteFirstRelasi(adrParent P, adrRelasi &R) {
    if (P != NULL && P -> firstRelasi != NULL) {
        R = P -> firstRelasi;
        P -> firstRelasi = P -> firstRelasi -> next;
        R -> next = NULL;
    } else {
        R = NULL;
    }
}

void deleteLastRelasi(adrParent P, adrRelasi &R) {
    if (P == NULL || P -> firstRelasi == NULL) {
        R = NULL;
    } else if (P -> firstRelasi -> next == NULL) {
        R = P -> firstRelasi;
        P -> firstRelasi = NULL;
    } else {
        adrRelasi Q = P -> firstRelasi;
        while (Q -> next -> next != NULL) {
            Q = Q -> next;
        }
        R = Q -> next;
        Q -> next = NULL;
    }
}

void deleteAfterRelasi(adrParent P, adrRelasi Prec, adrRelasi &R) {
    if (Prec != NULL && Prec -> next != NULL) {
        R = Prec -> next;
        Prec -> next = R -> next;
        R -> next = NULL;
    } else {
        R = NULL;
    }
}

adrRelasi searchRelasi(ListParent L, string id_paket, adrParent &parentOut) {
    adrParent P = L.first;
    while (P != NULL) {
        adrRelasi R = P->firstRelasi;
        while (R != NULL) {
            if (R -> info.id_paket == id_paket) {
                parentOut = P;
                return R;
            }
            R = R -> next;
        }
        P = P -> next;
    }
    parentOut = NULL;
    return NULL;
}

void printListRelasiAll(ListParent L) {
    adrParent P = L.first;
    cout << "=== DAFTAR PAKET OPEN TRIP (RELASI MLL) ===" << endl;
    while (P != NULL) {
        cout << "Penyelenggara: " << P -> info.nama << " [" << P -> info.id_penyelenggara << "]" << endl;
        adrRelasi R = P -> firstRelasi;
        if (R == NULL) {
            cout << "  (Belum ada paket trip)" << endl;
        }
        while (R != NULL) {
            cout << " [" << R -> info.id_paket << "] " << R -> info.nama_paket
                 << " | Tgl: " << R -> info.tanggal_keberangkatan
                 << " | Biaya: Rp " << R -> info.biaya_perjalanan
                 << " | Kuota: " << R->info.kuota
                 << " | Destinasi: " << (R -> child != NULL ? R -> child -> info.nama_destinasi : "N/A") << endl;
            R = R -> next;
        }
        P = P -> next;
    }
    cout << "------------------------------------------" << endl;
}
