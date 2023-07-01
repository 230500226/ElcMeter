#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Authentication.h"
#include "User.h"

int main() {
    User users[MAX_USERS];
    int num_users = 1;

    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin");
    users[0].electricity_usage_per_day = 15;
    users[0].electricity_units = 200;

    system("cls");
    
    int choice;
    do {
        printf("Welcom to your electricity meter app\n");
        printf("\n1. Login\n2. Create account\n3. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            handleInvalidInput(3);
            continue;
        }
        switch (choice) {
            case 1:
                login(users, num_users);
                break;
            case 2:
                create_account(users, &num_users);
                break;
            case 3:
                break;
            default:
                handleInvalidInput(3);
        }
    } while (choice != 3);

    return 0;
}