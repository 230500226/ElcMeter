#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Authentication.h"
#include "User.h"

// Function to check if a username is unique among existing users
int is_username_unique(User *users, int num_users, char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

void create_account(User *users, int *num_users) {
    system("cls"); // Clear the screen
    
    if (*num_users >= MAX_USERS) {
        printf("Sorry, the maximum number of users has been reached.\n");
        return;
    }
    
    // Prompt the user to enter a username
    printf("Please enter a username: ");
    scanf("%s", users[*num_users].username);
    
    // Check if the username is unique
    if (!is_username_unique(users, *num_users, users[*num_users].username)) {
        printf("Sorry, that username is already taken.\n");
        return;
    }
    
    getPassword(users[*num_users].password); // Prompt the user to enter a password
    
    // Prompt the user to enter the electricity usage per day
    while (1) {
        printf("Enter electricity usage per day (in Kw): ");
        if (scanf("%f", &users[*num_users].electricity_usage_per_day) != 1) {
            handleInvalidInput(60000);
            continue;
        }
        if (users[*num_users].electricity_usage_per_day < 0 || users[*num_users].electricity_usage_per_day > 60000) {
            printf("Invalid value. Electricity usage per day must be between 0 and 60000.\n");
            continue;
        }
        break;
    }
    
    users[*num_users].electricity_units = 100; // Set the initial electricity units to 100
    
    // Confirm the user's information
    printf("\nPlease confirm the following information:\n");
    printf("Username: %s\n", users[*num_users].username);
    printf("Electricity usage per day: %.2f Kw\n", users[*num_users].electricity_usage_per_day);
    printf("\nIs this information correct? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        (*num_users)++; // Increment the number of users
        printf("Account created successfully.\n");
    } else {
        printf("Account creation cancelled.\n");
    }
    
    system("cls"); // Clear the screen
}
