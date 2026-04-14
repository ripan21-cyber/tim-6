#include <stdio.h>
#include <string.h>

#define MAX 100

// Struktur data
typedef struct {
    char nama[50];
    int dipinjam; // 1 = dipinjam, 0 = tersedia
} Buku;

Buku daftarBuku[MAX];
int jumlahBuku = 0;

// Tambah data (contoh awal)
void tambahBuku(char nama[]) {
    strcpy(daftarBuku[jumlahBuku].nama, nama);
    daftarBuku[jumlahBuku].dipinjam = 1;
    jumlahBuku++;
}

// Tampilkan buku yang dipinjam
void tampilkanPinjaman() {
    printf("\n=== Daftar Buku Dipinjam ===\n");
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].dipinjam == 1) {
            printf("%d. %s\n", i + 1, daftarBuku[i].nama);
        }
    }
}

// Fitur pengembalian
void kembalikanBuku() 
{
    int pilihan;
    tampilkanPinjaman();

    printf("\nPilih nomor buku yang ingin dikembalikan: ");
    scanf("%d", &pilihan);
    if (pilihan < 1 || pilihan > jumlahBuku) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    if (daftarBuku[pilihan - 1].dipinjam == 0) {
        printf("Buku sudah dikembalikan.\n");
    } else {
        daftarBuku[pilihan - 1].dipinjam = 0;
        printf("Buku '%s' berhasil dikembalikan!\n",
               daftarBuku[pilihan - 1].nama);
    }
}

// Hapus dari list
void hapusPinjaman() {
    int pilihan;
    tampilkanPinjaman();

    printf("\nPilih nomor yang ingin dihapus: ");
    scanf("%d", &pilihan);

    if (pilihan < 1 || pilihan > jumlahBuku) {
        printf("Pilihan tidak valid!\n");
        return;
    }

    for (int i = pilihan - 1; i < jumlahBuku - 1; i++) {
        daftarBuku[i] = daftarBuku[i + 1];
    }

    jumlahBuku--;
    printf("Data berhasil dihapus.\n");
}

// Menu CLI
void menu() {
    int pilih;

    do {
        printf("\n===== MENU PENGEMBALIAN =====\n");
        printf("1. Tampilkan Buku Dipinjam\n");
        printf("2. Kembalikan Buku\n");
        printf("3. Hapus Data Pinjaman\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                tampilkanPinjaman();
                break;
            case 2:
                kembalikanBuku();
                break;
            case 3:
                hapusPinjaman();
                break;
            case 4:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan salah!\n");
        }
    } while (pilih != 4);
}

int main() {
    // Data awal (contoh)
    tambahBuku("Algoritma");
    tambahBuku("Struktur Data");
    tambahBuku("Basis Data");

    menu();
    return 0;
}