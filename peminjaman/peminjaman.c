#include <stdio.h>
#include <string.h>

void pinjamAlat(char username[]) {
    FILE *alat = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    FILE *pinjam = fopen("pinjam.txt", "a");

    char nama[50];
    int stok, jumlah, found = 0;
    char pilih[50];

    printf("Masukkan nama alat: ");
    scanf("%s", pilih);

    printf("Jumlah pinjam: ");
    scanf("%d", &jumlah);

    while (fscanf(alat, "%s %d", nama, &stok) != EOF) {
        if (strcmp(nama, pilih) == 0) {
            found = 1;
            if (stok >= jumlah) {
                stok -= jumlah;
                fprintf(pinjam, "%s %s %d\n", username, nama, jumlah);
                printf("Peminjaman berhasil!\n");
            } else {
                printf("Stok tidak cukup!\n");
            }
        }
        fprintf(temp, "%s %d\n", nama, stok);
    }

    if (!found) {
        printf("Alat tidak ditemukan!\n");
    }

    fclose(alat);
    fclose(temp);
    fclose(pinjam);

    remove("alat.txt");
    rename("temp.txt", "alat.txt");
}