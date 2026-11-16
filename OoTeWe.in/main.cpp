#include "interface.h"

int main() {
    ListParent LP;
    ListChild LC;
    adrBST rootBST;

    createListParent(LP);
    createListChild(LC);
    createTree(rootBST);

    // Inisialisasi Data Dummy Minimal (5 Parent, 5 Child, 10 Relasi, 10 Node BST)
    generateDummyData(LP, LC, rootBST);

    int pilihan;
    do {
        showMenu();
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                printListParent(LP);
                printListChild(LC);
                printListRelasiAll(LP);
                break;
            case 2:
                cout << "=== BST TRAVERSAL (Key: Jumlah Peserta) ===" << endl;
                cout << "\n--- In-Order Traversal ---" << endl;
                inOrder(rootBST);
                cout << "\n--- Pre-Order Traversal ---" << endl;
                preOrder(rootBST);
                cout << "\n--- Post-Order Traversal ---" << endl;
                postOrder(rootBST);
                break;
            case 3: {
                cout << "=== TREE STATISTICS ===" << endl;
                adrBST minN = findMinBST(rootBST);
                adrBST maxN = findMaxBST(rootBST);
                cout << "Jumlah Peserta Terkecil (Min) : " << (minN ? minN->info.jumlah_peserta : 0) << endl;
                cout << "Jumlah Peserta Terbanyak (Max): " << (maxN ? maxN->info.jumlah_peserta : 0) << endl;
                cout << "Jumlah Node BST               : " << countNodes(rootBST) << endl;
                cout << "Tinggi Pohon (Height)         : " << getTreeHeight(rootBST) << endl;
                break;
            }
            case 4: {
                string idP, idK, namaP;
                int jml;
                cout << "=== INPUT PENDAFTARAN TRIP ===" << endl;
                cout << "ID Penyelenggara : "; cin >> idP;
                cout << "ID Paket Trip    : "; cin >> idK;
                cout << "Nama Peserta     : "; cin.ignore(); getline(cin, namaP);
                cout << "Jumlah Peserta   : "; cin >> jml;
                mendaftarOpenTrip(LP, rootBST, idP, idK, namaP, jml);
                break;
            }
            case 5:
                tampilkanPenyelenggaraPendapatanTertinggi(LP, rootBST);
                break;
            case 6:
                tampilkanTotalPendapatanAplikasi(rootBST);
                break;
            case 7:
                tampilkanPaketPesertaTerbanyak(rootBST);
                break;
            case 8: {
                string idD;
                cout << "Masukkan ID Destinasi (misal: DEST01): ";
                cin >> idD;
                tampilkanPenyelenggaraTermurah(LP, idD);
                break;
            }
            case 9: {
                string namaP;
                cout << "Masukkan Nama Peserta: ";
                cin.ignore();
                getline(cin, namaP);
                tampilkanRiwayatPeserta(rootBST, namaP);
                break;
            }
            case 0:
                cout << "Terima kasih telah menggunakan sistem OoTeWe.in!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
