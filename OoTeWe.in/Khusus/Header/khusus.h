#ifndef KHUSUS_H_INCLUDED
#define KHUSUS_H_INCLUDED

#include "../../MLL-01/Header/Penyelenggara.h"
#include "../../MLL-01/Header/Destinasi.h"
#include "../../MLL-01/Header/Paket.h"
#include "../../BST/Header/pendaftaranBST.h"

bool mendaftarOpenTrip(ListParent LP, adrBST &rootBST, string idPenyelenggara, string idPaket, string namaPeserta, int jmlPeserta);
void hitungPendapatanPenyelenggara(adrBST root, adrParent P, double &total);
void tampilkanPenyelenggaraPendapatanTertinggi(ListParent LP, adrBST rootBST);
void tampilkanTotalPendapatanAplikasi(adrBST rootBST);

#endif // KHUSUS_H_INCLUDED
