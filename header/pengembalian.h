#ifndef PENGEMBALIAN_H
#define PENGEMBALIAN_H

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