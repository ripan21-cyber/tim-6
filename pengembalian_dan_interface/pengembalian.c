#include <stdio.h>
#include <string.h>

void pengembalian() {
    FILE *fp, *temp;
    char nama[100], alat[100];
    int jumlah;
    char cari[100];
    int found = 0;

    fp = fopen("pinjam.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("Tidak ada data peminjaman.\n");
        return;
    }

    printf("Masukkan nama alat yang dikembalikan: ");
    scanf(" %[^\n]", cari);

    while (fscanf(fp, "%[^|]|%[^|]|%d\n", nama, alat, &jumlah) != EOF) {
        if (strcmp(alat, cari) == 0 && found == 0) {
            found = 1;
            printf("Alat berhasil dikembalikan!\n");
            continue;
        }

        fprintf(temp, "%s|%s|%d\n", nama, alat, jumlah);
    }

    fclose(fp);
    fclose(temp);

    remove("pinjam.txt");
    rename("temp.txt", "pinjam.txt");

    if (!found) {
        printf("Data tidak ditemukan.\n");
    }
}