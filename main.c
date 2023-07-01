#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Authentication.h"
#include "User.h"

int main() {
    User users[MAX_USERS]; // Array to store user data
    int num_users = 1; // Variable to store the number of users (initialized to 1)

    // Initializing the first user
    strcpy(users[0].username, "admin"); // Setting the username
    strcpy(users[0].password, "admin"); // Setting the password
    users[0].electricity_usage_per_day = 15; // Setting the electricity usage per day
    users[0].electricity_units = 200; // Setting the electricity units

    system("cls"); // Clearing the screen

    int choice;
    do {
        printf("Welcome to your electricity meter app\n"); // Displaying the menu options
        printf("\n1. Login\n2. Create account\n3. Exit\nPlease enter your choice: ");
        if (scanf("%d", &choice) != 1) { // Checking if the input is valid
            handleInvalidInput(3); // Handling invalid input
            continue; // Skipping the rest of the loop and starting from the beginning
        }
        switch (choice) {
            case 1:
                login(users, num_users); // Calling the login function
                break;
            case 2:
                create_account(users, &num_users); // Calling the create_account function
                break;
            case 3:
                break; // Exiting the loop and ending the program
            default:
                handleInvalidInput(3); // Handling invalid input
        }
    } while (choice != 3); // Continuing the loop until the user chooses to exit

    return 0; // Exiting the program
}
