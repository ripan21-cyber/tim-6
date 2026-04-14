#ifndef PENGEMBALIAN_H
#define PENGEMBALIAN_H

// Struktur data buku pinjaman
typedef struct {
    int idBuku;
    char judul[100];
    char peminjam[100];
    int status; // 1 = dipinjam, 0 = dikembalikan
} Pinjaman;

/* =========================
   FUNGSI-FUNGSI PENGEMBALIAN
   ========================= */

// Menampilkan semua data pinjaman
void tampilkanPinjaman(Pinjaman data[], int jumlah);

// Proses pengembalian buku berdasarkan ID
void kembalikanBuku(Pinjaman data[], int *jumlah, int idBuku);

// Menghapus data setelah buku dikembalikan
void hapusPinjaman(Pinjaman data[], int *jumlah, int index);

// Menu CLI pengembalian
void menuPengembalian(Pinjaman data[], int *jumlah);

#endif