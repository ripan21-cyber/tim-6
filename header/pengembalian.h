#ifndef PENGEMBALIAN_H
#define PENGEMBALIAN_H

<<<<<<< HEAD
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
=======
#include <stdio.h>
#include <string.h>

#define MAX 100

/* Struct data peminjaman */
typedef struct {
    char nama[50];
    char namaAlat[50];
    char tanggalPinjam[20];
    char tanggalKembali[20];
    int sudahDikembalikan; /* 0 = belum, 1 = sudah */
} Peminjaman;

/* Deklarasi fungsi pengembalian */
void pengembalian(Peminjaman data[], int *jumlah);
int cariPeminjaman(Peminjaman data[], int jumlah, const char *nama, const char *namaAlat);
void tampilkanDaftarPeminjaman(Peminjaman data[], int jumlah);

#endif /* PENGEMBALIAN_H */
>>>>>>> 2029bddf072af14c962aa69dcd70c3be7d7aca64
