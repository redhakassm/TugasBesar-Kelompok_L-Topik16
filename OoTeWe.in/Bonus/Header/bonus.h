#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

#include "../../MLL-01/Header/Penyelenggara.h"
#include "../../MLL-01/Header/Destinasi.h"
#include "../../MLL-01/Header/Paket.h"
#include "../../BST/Header/pendaftaranBST.h"

void tampilkanPaketPesertaTerbanyak(adrBST rootBST);
void tampilkanPenyelenggaraTermurah(ListParent LP, string idDestinasi);
void tampilkanRiwayatPeserta(adrBST rootBST, string namaPeserta);

#endif // BONUS_H_INCLUDED
