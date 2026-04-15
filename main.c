#include <stdio.h>
#include <string.h>
#include "header/login.h"
#include "header/menu.h"   

int main() {
    char username[50], password[50], role[10];
    int status;

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    status = login(username, password, role);

    if (status == 1) {
        printf("Login berhasil! Role: %s\n", role);

        
        if (strcmp(role, "admin") == 0) {
            menuAdmin();
        } 
        else if (strcmp(role, "user") == 0) {
            menuUser(username);  
        }

    } else {
        printf("Login gagal!\n");
    }

    return 0;
}