# TugasBesar_Kelompok-L_OoTeWe.in

## Deskripsi
Aplikasi pengelolaan open trip (OoTeWe.in) mencatat penyelenggara perjalanan dan destinasi wisata yang ditawarkan. Seorang penyelenggara dapat menawarkan perjalanan ke banyak destinasi dan satu destinasi dapat ditawarkan oleh beberapa penyelenggara. Setiap penawaran memiliki jadwal, biaya, dan kuota yang berbeda. Data paket perjalanan dikelola melalui Multi Linked List, sedangkan pendaftaran peserta dicatat dalam Binary Search Tree.

---

## Struktur Data

| List | Deskripsi |
|---|---|
| Parent | Penyelenggara (id penyelenggara, nama, alamat, kontak) |
| Child | Destinasi (id destinasi, nama destinasi, lokasi, kategori wisata) |
| Relasi | Paket Open Trip (id paket, nama paket, tanggal keberangkatan, biaya perjalanan, kuota, status paket) |
| Binary Search Tree | Pendaftaran peserta dengan key jumlah peserta (nama peserta, id penyelenggara, id destinasi, id paket, jumlah peserta, total biaya, status pembayaran) |

---

## Arsitektur
Arsitektur pada topik tugas besar ini menggunakan multi linked list tipe-01 dan binary search tree.

### 1. Multi Linked List Tipe-01
![Multi Linked List Tipe-01](https://i.imgur.com/iBBVDiM.png)

## Fitur / Fungsional Program

### Fungsional Umum

Fungsionalitas yang harus terpenuhi untuk **Multi-Linked list** adalah:
1. Menyisipkan elemen parent, child dan relasi (first, last, after).
2. Menghapus elemen parent, child dan relasi (first, last, after).
3. Mencari elemen parent, child dan relasi.
5. Menampilkan seluruh data pada list (parent, child, relasi).
6. Membuat data dummy untuk masing-masing list minimal 5 data (parent, child) dan 10 data (relasi).
7. Melengkapi Main Program (interface).

Fungsionalitas yang harus terpenuhi untuk **Binary Search tree** adalah:
1. Menyisipkan node berdasarkan key pada masing-masing topik.
2. Menghapus node berdasarkan key pada masing-masing topik.
3. Mencari node berdasarkan key pada masing-masing topik.
4. Menampilkan seluruh data traversal (in-order, pre-order, dan post-order).
5. Menampilkan nilai minimum, maksimum, tinggi pohon, dan jumlah node.
6. Membuat data dummy untuk BST minimal 10 node.
7. Melengkapi Main Program (interface).

### Fungsional Khusus
1. Melakukan pendaftaran open trip dengan memilih penyelenggara dan paket perjalanan yang tersedia serta memastikan kuota mencukupi dan diperbaharui.
2. Menyimpan pendaftaran peserta ke BST berdasarkan jumlah peserta.
3. Menampilkan informasi penyelenggara dengan pendapatan perjalanan tertinggi.
4. Menampilkan total pendapatan aplikasi jika potongan pendapatan sebesar 5%.

### Fungsional Tambahan (Bonus)
1. Menampilkan informasi paket dengan jumlah peserta terbanyak.
2. Menampilkan informasi penyelenggara dengan biaya perjalanan termurah untuk destinasi tertentu.
3. Menampilkan riwayat perjalanan untuk peserta tertentu.
