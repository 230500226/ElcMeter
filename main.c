/************* AUTHOR INFO **************/
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

/**************** MAIN FUNCTION *******************/

int main() {
    User users[MAX_USERS]; // Array to store user data
    int numUsers = 1; // Variable to store the number of users (initialized to 1)

    // Initializing the first user
    strcpy(users[0].username, "admin"); // Setting the username
    strcpy(users[0].password, "admin"); // Setting the password
    users[0].electricityUsagePerMonth = 15; // Setting the Electricity usage per month
    users[0].electricityUnits = 200; // Setting the electricity units

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
                login(users, numUsers); // Calling the login function
                break;
            case 2:
                createAccount(users, &numUsers); // Calling the createAccount function
                break;
            case 3:
                break; // Exiting the loop and ending the program
            default:
                handleInvalidInput(3); // Handling invalid input
        }
    } while (choice != 3); // Continuing the loop until the user chooses to exit

    return 0; // Exiting the program
}