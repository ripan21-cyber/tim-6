#include <stdio.h>
#include <string.h>
#include "../header/menu.h"
#include "../header/alat.h"
#include "../header/pinjam.h"
#include "../header/alat.h"  // pastikan ini ada


// ================= MENU ADMIN =================
void menuAdmin() {
    int pilih;

    do {
        printf("\n===== MENU ADMIN =====\n");
        printf("1. Lihat Alat\n");
        printf("2. Tambah Alat\n");
        printf("3. Hapus Alat\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                tampilAlat();
                break;
            case 2:
                tambahAlat();
                break;
            case 3:
                hapusAlat();
                break;
            case 4:
                printf("Keluar dari menu admin...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilih != 4);
}

// ================= MENU USER =================
void menuUser(char username[]) {
    int pilih;

    do {
        printf("\n===== MENU USER =====\n");
        printf("1. Pinjam Alat\n");
        printf("2. Return Alat\n");
        printf("3. Lihat Peminjaman\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                pinjamAlat(username);   // 🔥 kirim username
                break;

            case 2:
                returnAlat(username);   // 🔥 aktifkan return
                break;

            case 3:
                lihatPeminjaman(username); // 🔥 lihat data
                break;

            case 4:
                printf("Keluar...\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilih != 4);
}