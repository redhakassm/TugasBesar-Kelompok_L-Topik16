#include "dummy.h"

void generateDummyData(ListParent &LP, ListChild &LC, adrBST &rootBST) {
    // ----------------------------------------------------
    // 1. Data Dummy Child (Destinasi Wisata - Minimal 5 Data)
    // ----------------------------------------------------
    adrChild C1 = createElementChild({"DEST01", "Labuan Bajo", "Nusa Tenggara Timur", "Bahari"});
    adrChild C2 = createElementChild({"DEST02", "Candi Borobudur", "Magelang", "Budaya"});
    adrChild C3 = createElementChild({"DEST03", "Gunung Bromo", "Probolinggo", "Alam"});
    adrChild C4 = createElementChild({"DEST04", "Raja Ampat", "Papua Barat", "Bahari"});
    adrChild C5 = createElementChild({"DEST05", "Nusa Penida", "Bali", "Bahari"});

    insertLastChild(LC, C1);
    insertLastChild(LC, C2);
    insertLastChild(LC, C3);
    insertLastChild(LC, C4);
    insertLastChild(LC, C5);

    // ----------------------------------------------------
    // 2. Data Dummy Parent (Penyelenggara - Minimal 5 Data)
    // ----------------------------------------------------
    adrParent P1 = createElementParent({"PY01", "Nusantara Tour", "Bandung", "08123456789"});
    adrParent P2 = createElementParent({"PY02", "IndoExplore", "Jakarta", "08234567890"});
    adrParent P3 = createElementParent({"PY03", "Java Adventure", "Yogyakarta", "08345678901"});
    adrParent P4 = createElementParent({"PY04", "Borneo Travel", "Surabaya", "08456789012"});
    adrParent P5 = createElementParent({"PY05", "Exotic Trip", "Denpasar", "08567890123"});

    insertLastParent(LP, P1);
    insertLastParent(LP, P2);
    insertLastParent(LP, P3);
    insertLastParent(LP, P4);
    insertLastParent(LP, P5);

    // ----------------------------------------------------
    // 3. Data Dummy Relasi (Paket Open Trip - Minimal 10 Data)
    // ----------------------------------------------------
    insertLastRelasi(P1, createElementRelasi({"PK01", "Exotic Labuan Bajo 3D2N", "2026-12-01", 3500000, 15, "Tersedia"}, C1));
    insertLastRelasi(P1, createElementRelasi({"PK02", "Sunrise Bromo Backpacker", "2026-11-20", 850000, 20, "Tersedia"}, C3));

    insertLastRelasi(P2, createElementRelasi({"PK03", "Raja Ampat Paradise", "2026-12-15", 7500000, 10, "Tersedia"}, C4));
    insertLastRelasi(P2, createElementRelasi({"PK04", "Nusa Penida Island Tour", "2026-11-28", 1200000, 12, "Tersedia"}, C5));

    insertLastRelasi(P3, createElementRelasi({"PK05", "Heritage Borobudur Tour", "2026-11-25", 450000, 25, "Tersedia"}, C2));
    insertLastRelasi(P3, createElementRelasi({"PK06", "Labuan Bajo Sailing", "2026-12-10", 3800000, 8, "Tersedia"}, C1));

    insertLastRelasi(P4, createElementRelasi({"PK07", "Bromo Camping Experience", "2026-12-05", 950000, 15, "Tersedia"}, C3));
    insertLastRelasi(P4, createElementRelasi({"PK08", "Candi Borobudur Night", "2026-12-22", 600000, 30, "Tersedia"}, C2));

    insertLastRelasi(P5, createElementRelasi({"PK09", "Luxury Raja Ampat Cruise", "2026-12-20", 9800000, 6, "Tersedia"}, C4));
    insertLastRelasi(P5, createElementRelasi({"PK10", "Nusa Penida Snorkeling", "2026-12-08", 1400000, 18, "Tersedia"}, C5));

    // ----------------------------------------------------
    // 4. Data Dummy BST (Pendaftaran Peserta - Minimal 10 Node)
    //    Key BST: jumlah_peserta
    // ----------------------------------------------------
    mendaftarOpenTrip(LP, rootBST, "PY01", "PK01", "Redha Kassem", 4);
    mendaftarOpenTrip(LP, rootBST, "PY02", "PK03", "Ahmad Fauzi", 2);
    mendaftarOpenTrip(LP, rootBST, "PY03", "PK05", "Siti Aminah", 6);
    mendaftarOpenTrip(LP, rootBST, "PY01", "PK02", "Budi Santoso", 1);
    mendaftarOpenTrip(LP, rootBST, "PY04", "PK07", "Dewi Lestari", 3);
    mendaftarOpenTrip(LP, rootBST, "PY05", "PK09", "Eko Prasetyo", 5);
    mendaftarOpenTrip(LP, rootBST, "PY02", "PK04", "Fajar Nugraha", 7);
    mendaftarOpenTrip(LP, rootBST, "PY03", "PK06", "Gita Gutawa", 8);
    mendaftarOpenTrip(LP, rootBST, "PY04", "PK08", "Hendra Wijaya", 10);
    mendaftarOpenTrip(LP, rootBST, "PY05", "PK10", "Indah Permata", 9);
}
