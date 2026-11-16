#include "../Header/bonus.h"

void tampilkanPaketPesertaTerbanyak(adrBST rootBST) {
    if (rootBST == NULL) {
        cout << "Belum ada pendaftaran di BST." << endl;
        return;
    }
    adrBST maxNode = findMaxBST(rootBST);
    cout << "=== PAKET DENGAN JUMLAH PESERTA TERBANYAK ===" << endl;
    cout << "ID Paket       : " << maxNode->info.id_paket << endl;
    cout << "Jumlah Peserta : " << maxNode->info.jumlah_peserta << " orang" << endl;
    cout << "Atas Nama      : " << maxNode->info.nama_peserta << endl;
    cout << "Total Biaya    : Rp " << maxNode->info.total_biaya << endl;
}

void tampilkanPenyelenggaraTermurah(ListParent LP, string idDestinasi) {
    adrParent P = LP.first;
    adrParent bestP = NULL;
    adrRelasi bestR = NULL;
    double minPrice = 1e18;

    while (P != NULL) {
        adrRelasi R = P->firstRelasi;
        while (R != NULL) {
            if (R->child != NULL && R->child->info.id_destinasi == idDestinasi) {
                if (R->info.biaya_perjalanan < minPrice) {
                    minPrice = R->info.biaya_perjalanan;
                    bestP = P;
                    bestR = R;
                }
            }
            R = R->next;
        }
        P = P->next;
    }

    if (bestP != NULL && bestR != NULL) {
        cout << "=== PENYELENGGARA TERMURAH UNTUK DESTINASI " << idDestinasi << " ===" << endl;
        cout << "Penyelenggara : " << bestP->info.nama << " [" << bestP->info.id_penyelenggara << "]" << endl;
        cout << "Nama Paket    : " << bestR->info.nama_paket << endl;
        cout << "Biaya         : Rp " << bestR->info.biaya_perjalanan << endl;
    } else {
        cout << "Destinasi tersebut tidak ditemukan pada paket open trip manapun." << endl;
    }
}

void searchRiwayatHelper(adrBST root, string namaPeserta, bool &found) {
    if (root != NULL) {
        searchRiwayatHelper(root->left, namaPeserta, found);
        if (root->info.nama_peserta == namaPeserta) {
            found = true;
            cout << "  └─ Paket: " << root->info.id_paket
                 << " | Jumlah Peserta: " << root->info.jumlah_peserta
                 << " | Total: Rp " << root->info.total_biaya
                 << " | Status: " << root->info.status_pembayaran << endl;
        }
        searchRiwayatHelper(root->right, namaPeserta, found);
    }
}

void tampilkanRiwayatPeserta(adrBST rootBST, string namaPeserta) {
    cout << "=== RIWAYAT PERJALANAN PESERTA: " << namaPeserta << " ===" << endl;
    bool found = false;
    searchRiwayatHelper(rootBST, namaPeserta, found);
    if (!found) {
        cout << "Tidak ditemukan riwayat pendaftaran atas nama " << namaPeserta << endl;
    }
}
