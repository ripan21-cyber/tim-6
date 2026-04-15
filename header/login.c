#include <stdio.h>
#include <string.h>
#include "login.h"

int login(char *username, char *password, char *role) {
    FILE *file;
    char fileUser[50], filePass[50], fileRole[10];

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