#ifndef PEMINJAMAN_H
#define PEMINJAMAN_H

#define MAX 100

// Struktur data buku
typedef struct {
    char nama[50];
    int dipinjam; // 1 = dipinjam, 0 = tersedia
} Buku;

// Variabel global (dipakai antar file)
extern Buku daftarBuku[MAX];
extern int jumlahBuku;

// ====== Fungsi Peminjaman ======
void tambahBuku(char nama[]);
void tampilkanBuku();
void pinjamBuku();

// ====== Fungsi Umum ======
void tampilkanPinjaman();

#endif
