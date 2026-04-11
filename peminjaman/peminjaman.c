#include <stdio.h>
#include <string.h>
#include "peminjaman.h"

void kurangistok(char alatDipinjam[], int jumlahPinjam) {
    FILE *fp, *temp;
    char nama[100];
    int stok;
    int ditemukan = 0;

    fp = fopen("alat.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File alat tidak ditemukan!\n");
        return;
    }

    while (fscanf(fp, "%[^|]|%d\n", nama, &stok) != EOF) {
        if (strcmp(nama, alatDipinjam) == 0) {
            ditemukan = 1;

            if (stok >= jumlahPinjam) {
                stok -= jumlahPinjam;
            } else {
                printf("Stok tidak cukup untuk %s!\n", nama);
            }
        }
        fprintf(temp, "%s|%d\n", nama, stok);
    }

    fclose(fp);
    fclose(temp);

    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    if (!ditemukan) {
        printf("Alat tidak ditemukan!\n");
    }
}

void pinjamAlat() {
    FILE *fp;
    char nama[100];
    char alat[100];
    int jumlah;

    printf("\n=== PEMINJAMAN ALAT ===\n");

    printf("Nama Peminjam : ");
    scanf(" %[^\n]", nama);

    printf("Nama Alat : ");
    scanf(" %[^\n]", alat);

    printf("Jumlah : ");
    scanf("%d", &jumlah);

    fp = fopen("pinjam.txt", "a");
    if (fp == NULL) {
        printf("Gagal membuka file pinjam.txt!\n");
        return;
    }

    fprintf(fp, "%s|%s|%d\n", nama, alat, jumlah);
    fclose(fp);

    // stok di update
    updateStok(alat, jumlah);

    printf("Peminjaman berhasil!\n");
}