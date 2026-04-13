#include <stdio.h>
#include <string.h>

#define MAX 100

// Struktur data buku yang dipinjam
typedef struct {
    char nama[50];
    int dipinjam; // 1 = dipinjam, 0 = tersedia
} Buku;

Buku daftarBuku[MAX];
int jumlahBuku = 0;