/***************** AUTHOR INFO ******************/
// Name: Shahied Rustin
// Student No.: 230500226
// Course Title: Software Design 1 (SDN150S)
// Date: 02/07/2023

/************* HEADER FILES ***************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Authentication.h"
#include "User.h"

/********** FUNCTION IMPLEMENTATION **********/

// Function to check if a username is unique among existing users
int isUsernameUnique(User *users, int numUsers, char *username) {   
    for (int i = 0; i < numUsers; i++) { // loops through all the users to find a match
        if (strcmp(users[i].username, username) == 0) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

void createAccount(User *users, int *numUsers) {
    system("cls");

    //Check if the maximum number of users is reached
    if (*numUsers >= MAX_USERS) {
        printf("Sorry, the maximum number of users has been reached.\n");
        return;
    }

    // Prompt the user to enter a username
    printf("Please enter a username: ");
    scanf("%s", users[*numUsers].username);

    // Check if the username is unique
    if (!isUsernameUnique(users, *numUsers, users[*numUsers].username)) {
        printf("Sorry, that username is already taken.\n");
        return;
    }

    getPassword(users[*numUsers].password); // Prompt the user to enter a password

    // Prompt the user to enter the Electricity usage per month
    while (1) {
        printf("Enter Electricity usage per month (in Kw): ");
        if (scanf("%f", &users[*numUsers].electricityUsagePerMonth) != 1) { // Input must be a number (float)
            handleInvalidInput(60000);
            continue;
        } // Checks if Electricity usage per month must be between 0 and 60000
        if (users[*numUsers].electricityUsagePerMonth < 0 || users[*numUsers].electricityUsagePerMonth > 60000) {
            printf("Invalid value. Electricity usage per month must be between 0 and 60000.\n");
            continue;
        }
        break;
    }

    users[*numUsers].electricityUnits = 100; // Set the initial electricity units to 100

    // Confirm the user's information
    printf("\nPlease confirm the following information:\n");
    printf("Username: %s\n", users[*numUsers].username);
    printf("Electricity usage per month: %.2f Kw\n", users[*numUsers].electricityUsagePerMonth);
    printf("\nIs this information correct? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        (*numUsers)++; // Increment the number of users
                        // While the userdata has been pushed to the struct it will be overwrittien and not scanned for, unless the numUsers is updated
        printf("Account created successfully.\n"); // Success message
    } else {
        printf("Account creation cancelled.\n"); // Cancelled message
    }

    system("cls");
}
