#include "header/alat.h"

void menuAdmin() {
    int pilihan;

    do {
        printf("\n=== MENU ADMIN ===");
        printf("\n1. Tambah Alat");
        printf("\n2. Tampilkan Alat");
        printf("\n3. Edit Alat");
        printf("\n4. Hapus Alat");
        printf("\n0. Logout");
        printf("\nPilih: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: tambahAlat(); break;
            case 2: tampilAlat(); break;
            case 3: editAlat(); break;
            case 4: hapusAlat(); break;
        }
    } while(pilihan != 0);
}