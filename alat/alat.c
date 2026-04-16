#include <stdio.h>
#include <string.h>
#include "../header/alat.h"
#include "../header/menu.h"

typedef struct {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
} Alat;

void tambahAlat() {
    FILE *file = fopen("data/alat.txt", "a");

    if (file == NULL) {
        printf("file tidak bisa dibuka!\n");
        return;
    }

    Alat a;

    printf("ID: ");
    scanf("%u", &a.id);
    printf("Nama: ");
    scanf(" %[^\n]", a.nama);
    printf("Merek: ");
    scanf(" %[^\n]", a.merek);
    printf("Model: ");
    scanf(" %[^\n]", a.model);
    printf("Tahun: ");
    scanf("%u", &a.tahun);
    printf("Jumlah: ");
    scanf("%u", &a.jumlah);

    fprintf(file, "%u|%s|%s|%s|%u|%u\n",
            a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);

    fclose(file);
    printf("Data berhasil ditambahkan!\n");
}

void editAlat() {
    FILE *file = fopen("data/alat.txt", "r");

    if (file == NULL) {
        printf("file tidak ditemukan!\n");
        return;
    }

    FILE *temp = fopen("data/temp.txt", "w");

    if (temp == NULL) {
        printf("file sementara tidak bisa dibuat!\n");
        fclose(file);
        return;
    }

    Alat a;
    unsigned int idCari;
    int ketemu = 0;

    printf("Masukkan ID alat: ");
    scanf("%u", &idCari);

    while (fscanf(file, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if (a.id == idCari) {
            ketemu = 1;

            printf("Nama baru: ");
            scanf(" %[^\n]", a.nama);
            printf("Merek baru: ");
            scanf(" %[^\n]", a.merek);
            printf("Model baru: ");
            scanf(" %[^\n]", a.model);
            printf("Tahun baru: ");
            scanf("%u", &a.tahun);
            printf("Jumlah baru: ");
            scanf("%u", &a.jumlah);
        }

        fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
                a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(file);
    fclose(temp);

    remove("data/alat.txt");
    rename("data/temp.txt", "data/alat.txt");

    if (ketemu)
        printf("Data berhasil diedit!\n");
    else
        printf("Data tidak ditemukan!\n");
}

void hapusAlat() {
    FILE *file = fopen("data/alat.txt", "r");

     if (file == NULL) {
        printf("file tidak ditemukan!\n");
        return;
    }

    FILE *temp = fopen("data/temp.txt", "w");

    if (temp == NULL) {
        printf("file semenntara tidak bisa dibuat!\n");
        fclose(file);
        return;
    }

    Alat a;
    unsigned int idHapus;
    int ketemu = 0;

    printf("Masukkan ID alat: ");
    scanf("%u", &idHapus);

    while (fscanf(file, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if (a.id != idHapus) {
            fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
                    a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
        } else {
            ketemu = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("data/alat.txt");
    rename("data/temp.txt", "data/alat.txt");

    if (ketemu)
        printf("Data berhasil dihapus!\n");
    else
        printf("Data tidak ditemukan!\n");
}

void tampilAlat() {
    FILE *file = fopen("data/alat.txt", "r");

    if (file == NULL) {
        printf("file tidak bisa dibuka!\n");
        return;
    }

    Alat a;

    while (fscanf(file, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
                  &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        printf("\nID: %u", a.id);
        printf("\nNama: %s", a.nama);
        printf("\nMerek: %s", a.merek);
        printf("\nModel: %s", a.model);
        printf("\nTahun: %u", a.tahun);
        printf("\nJumlah: %u\n", a.jumlah);
    }

    fclose(file);
}
void menuAdmin() {
    int pilihan;

    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Tambah Alat\n");
        printf("2. Edit Alat\n");
        printf("3. Hapus Alat\n");
        printf("4. Tampil Alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahAlat();
                break;
            case 2:
                editAlat();
                break;
            case 3:
                hapusAlat();
                break;
            case 4:
                tampilAlat();
                break;
            case 0:
                printf("Keluar dari menu admin...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 0);
}