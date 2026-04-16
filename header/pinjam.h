#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

#define MAX 100

// struct untuk data peminjaman
typedef struct {
    char nama[50];
    char namaAlat[50];
} Peminjaman;

// variabel global
extern Peminjaman data[MAX];
extern int jumlah;

// fungsi
void pinjamAlat();
void kurangistok(char alatDipinjam[], int jumlahPinjam);

#endif