#include <stdio.h>
#include <string.h>
#include "header/login.h"
#include "header/menu.h"

// stub function (biar nyambung)
void menuAdmin() {
    printf("Menu Admin (belum lengkap)\n");
}

void menuUser() {
    printf("Menu User (belum lengkap)\n");
}

int main(int argc, char *argv[]) {
    char role[10];

    if (!login(argc, argv, role)) {
        return 0;
    }

    printf("Login berhasil sebagai: %s\n", role);

    if (strcmp(role, "admin") == 0) {
        menuAdmin();
    } else if (strcmp(role, "user") == 0) {
        menuUser();
    } else {
        printf("Role tidak dikenali!\n");
    }

    return 0;
}