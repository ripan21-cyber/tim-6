#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alat.h"

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
    FILE *temp = fopen("data/temp.txt", "w");

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
    FILE *temp = fopen("data/temp.txt", "w");

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