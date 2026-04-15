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

#include <stdio.h>
#include <string.h>

void pinjamAlat(char *username) {
    FILE *file = fopen("data/peminjaman.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    char nama[50];
    int jumlah;

    printf("=== PINJAM ALAT ===\n");
    printf("Masukkan nama alat: ");
    scanf("%s", nama);

    printf("Jumlah: ");
    scanf("%d", &jumlah);

    fprintf(file, "%s %s %d dipinjam\n", username, nama, jumlah);
    fclose(file);

    printf("Berhasil meminjam %d %s\n", jumlah, nama);
}
void lihatPeminjaman(char *username) {
    FILE *file = fopen("data/peminjaman.txt", "r");
    if (file == NULL) {
        printf("Belum ada data peminjaman.\n");
        return;
    }

    char user[50], alat[50], status[20];
    int jumlah;

    printf("=== DATA PEMINJAMAN ===\n");

    while (fscanf(file, "%s %s %d %s", user, alat, &jumlah, status) != EOF) {
        if (strcmp(user, username) == 0) {
            printf("Alat: %s | Jumlah: %d | Status: %s\n", alat, jumlah, status);
        }
    }

    fclose(file);
}
void returnAlat(char *username) {
    FILE *file = fopen("data/peminjaman.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    char user[50], alat[50], status[20];
    char nama[50];
    int jumlah;

    printf("Masukkan nama alat yang ingin dikembalikan: ");
    scanf("%s", nama);

    while (fscanf(file, "%s %s %d %s", user, alat, &jumlah, status) != EOF) {
        if (strcmp(user, username) == 0 && strcmp(alat, nama) == 0 && strcmp(status, "dipinjam") == 0) {
            fprintf(temp, "%s %s %d kembali\n", user, alat, jumlah);
            printf("Alat berhasil dikembalikan!\n");
        } else {
            fprintf(temp, "%s %s %d %s\n", user, alat, jumlah, status);
        }
    }

    fclose(file);
    fclose(temp);

    remove("data/peminjaman.txt");
    rename("data/temp.txt", "data/peminjaman.txt");
}