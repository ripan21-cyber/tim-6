#include <stdio.h>
#include <string.h>

#define MAX 100

// Struct (kalau belum ada .h, ditulis di sini dulu)
struct Peminjaman {
    char nama[50];
    char namaAlat[50];
};

// Data dari file lain (misalnya main.c)
extern struct Peminjaman data[MAX];
extern int jumlah;

// Fungsi tampilkan (biar bisa dipakai di sini juga)
void tampilkan() {
    printf("\n=== Daftar Peminjaman Alat ===\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%d. %s - %s\n", i + 1, data[i].nama, data[i].namaAlat);
    }
}

// Fungsi pengembalian
void pengembalian() {
    int index;

    if (jumlah == 0) {
        printf("Tidak ada alat yang dipinjam.\n");
        return;
    }

    tampilkan();

    printf("\nPilih nomor alat yang dikembalikan: ");
    scanf("%d", &index);

    if (index < 1 || index > jumlah) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    // Hapus data (geser array)
    for (int i = index - 1; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }

    jumlah--;

    printf("Alat berhasil dikembalikan!\n");
}
