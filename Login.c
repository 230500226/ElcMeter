#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "User.h"
#include "Authentication.h"

void topup() {
    // TODO: Implement topup functionality
}

void change_electricity_usage(User *user) {
    // TODO: Implement change electricity usage functionality
}

void login(User *users, int num_users) {
    char username[20], password[20];
    printf("Please enter your username: ");
    scanf("%s", username);
    getPassword(password);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            system("cls");
            printf("Welcome %s!\n", users[i].username);
            printf("Electricity usage per day: %.2f Kw\n", users[i].electricity_usage_per_day);
            printf("Electricity units: %d\n", users[i].electricity_units);

            int choice;
            do {
                printf("\n1. Top up\n2. Change electricity usage per day\n3. Logout (exit)\nEnter your choice: ");
                if (scanf("%d", &choice) != 1) {
                    handleInvalidInput(3);
                    continue;
                }
                switch (choice) {
                    case 1:
                        topup();
                        break;
                    case 2:
                        change_electricity_usage(&users[i]);
                        break;
                    case 3:
                        break;
                    default:
                        handleInvalidInput(3);
                }
            } while (choice != 3);
            system("cls");
            return;
        }
    }
    printf("Invalid username or password.\n");
}

