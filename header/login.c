#include <stdio.h>
#include <string.h>
#include "login.h"

int login(int argc, char *argv[], char *role) {
    FILE *file;
    char username[50], password[50];
    char fileUser[50], filePass[50], fileRole[10];

    if (argc < 3) {
        printf("Gunakan: ./program username password\n");
        return 0;
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    file = fopen("data/akun.txt", "r");
    if (file == NULL) {
        printf("File akun tidak ditemukan!\n");
        return 0;
    }

    while (fscanf(file, "%s %s %s", fileUser, filePass, fileRole) != EOF) {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            strcpy(role, fileRole);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    printf("Login gagal!\n");
    return 0;
}