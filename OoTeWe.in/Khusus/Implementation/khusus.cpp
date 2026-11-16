#include "../Header/khusus.h"

bool mendaftarOpenTrip(ListParent LP, adrBST &rootBST, string idPenyelenggara, string idPaket, string namaPeserta, int jmlPeserta) {
    adrParent P = searchParent(LP, idPenyelenggara);
    if (P == NULL) {
        cout << "[ERROR] Penyelenggara tidak ditemukan!" << endl;
        return false;
    }

    adrParent dummyP;
    adrRelasi R = searchRelasi(LP, idPaket, dummyP);
    if (R == NULL || dummyP != P) {
        cout << "[ERROR] Paket perjalanan tidak ditemukan pada penyelenggara tersebut!" << endl;
        return false;
    }

    if (R->info.kuota < jmlPeserta) {
        cout << "[ERROR] Kuota tidak mencukupi! Sisa kuota: " << R->info.kuota << endl;
        return false;
    }

    // Update Kuota
    R->info.kuota -= jmlPeserta;

    // Simpan Ke BST
    InfotypeBST data;
    data.jumlah_peserta = jmlPeserta;
    data.nama_peserta = namaPeserta;
    data.id_penyelenggara = idPenyelenggara;
    data.id_destinasi = (R->child != NULL ? R->child->info.id_destinasi : "N/A");
    data.id_paket = idPaket;
    data.total_biaya = jmlPeserta * R->info.biaya_perjalanan;
    data.status_pembayaran = "Lunas";

    adrBST nodeBaru = createElementBST(data);
    insertBST(rootBST, nodeBaru);

    cout << "[SUKSES] Pendaftaran berhasil disimpan ke BST! Sisa kuota paket: " << R->info.kuota << endl;
    return true;
}

void hitungPendapatanPenyelenggara(adrBST root, string idPenyelenggara, double &total) {
    if (root != NULL) {
        hitungPendapatanPenyelenggara(root->left, idPenyelenggara, total);
        if (root->info.id_penyelenggara == idPenyelenggara) {
            total += root->info.total_biaya;
        }
        hitungPendapatanPenyelenggara(root->right, idPenyelenggara, total);
    }
}

void tampilkanPenyelenggaraPendapatanTertinggi(ListParent LP, adrBST rootBST) {
    adrParent P = LP.first;
    adrParent maxP = NULL;
    double maxIncome = -1;

    while (P != NULL) {
        double currentIncome = 0;
        hitungPendapatanPenyelenggara(rootBST, P->info.id_penyelenggara, currentIncome);

        if (currentIncome > maxIncome) {
            maxIncome = currentIncome;
            maxP = P;
        }
        P = P->next;
    }

    if (maxP != NULL && maxIncome > 0) {
        cout << "=== PENYELENGGARA PENDAPATAN TERTINGGI ===" << endl;
        cout << "ID Penyelenggara: " << maxP->info.id_penyelenggara << endl;
        cout << "Nama            : " << maxP->info.nama << endl;
        cout << "Total Pendapatan: Rp " << maxIncome << endl;
    } else {
        cout << "Belum ada transaksi pendaftaran terdata." << endl;
    }
}

void hitungTotalTransaksi(adrBST root, double &total) {
    if (root != NULL) {
        hitungTotalTransaksi(root->left, total);
        total += root->info.total_biaya;
        hitungTotalTransaksi(root->right, total);
    }
}

void tampilkanTotalPendapatanAplikasi(adrBST rootBST) {
    double totalGross = 0;
    hitungTotalTransaksi(rootBST, totalGross);
    double potongan = totalGross * 0.05;
    double nettoApp = potongan;

    cout << "=== TOTAL PENDAPATAN APLIKASI OoTeWe.in ===" << endl;
    cout << "Total Omset Bruto Perjalanan : Rp " << totalGross << endl;
    cout << "Potongan Komisi Aplikasi (5%): Rp " << nettoApp << endl;
}
