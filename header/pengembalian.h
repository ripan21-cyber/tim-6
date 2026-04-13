#ifndef PENGEMBALIAN_H
#define PENGEMBALIAN_H

#define MAX 100

// Struct data peminjaman
struct Peminjaman {
    char nama[50];
    char namaAlat[50];
};

// Deklarasi fungsi pengembalian
void pengembalian(struct Peminjaman data[], int *jumlah);

#endif