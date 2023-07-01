#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "User.h"
#include "Authentication.h"

// Function prototypes
void topup(User *user);
void change_electricity_usage(User *user);

void login(User *users, int num_users) {
    char username[20], password[20];

    // Prompt the user to enter their username and password
    printf("Please enter your username: ");
    scanf("%s", username);
    getPassword(password);

    // Iterate over the users to find a match for the provided username and password
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            int choice;
            do {
                printf("Welcome %s!\n", users[i].username);
                printf("Electricity usage per day: %.2f Kw\n", users[i].electricity_usage_per_day);
                printf("Electricity units: %d\n", users[i].electricity_units);
                printf("\n1. Top up\n2. Change electricity usage per day\n3. Logout (exit)\nEnter your choice: ");
                if (scanf("%d", &choice) != 1) {
                    handleInvalidInput(3);
                    continue;
                }
                switch (choice) {
                    case 1:
                        topup(&users[i]); // Call the topup function
                        break;
                    case 2:
                        change_electricity_usage(&users[i]); // Call the change_electricity_usage function
                        break;
                    case 3:
                        break; // Exit the loop and logout
                    default:
                        handleInvalidInput(3); // Handling invalid input
                }
            } while (choice != 3);
            system("cls"); // Clear the screen
            return;
        }
    }
    system("cls"); // Clear the screen
    printf("Invalid username or password.\n");
}

void topup(User *user) {
    char input[20];
    int units;
    float costPerUnit = user->electricity_usage_per_day * 30 <= 350 ? 1.80 : 3.63;

    system("cls"); // Clear the screen

    // Display the current balance
    printf("Your balance is: %d\n", user->electricity_units);

    // Prompt the user to enter the amount of electricity they want to buy
    printf("Enter how much electricity would you like to buy (use R for rands or type a number for units): ");
    scanf("%s", input);

    if (input[0] == 'R' || input[0] == 'r') {
        // Calculate units based on the amount in rands
        float rands = atof(input + 1);
        if (rands < 0) {
            printf("Invalid value. You cannot top up a negative value.\n");
            return;
        }
        units = rands / costPerUnit;
    } else {
        // Convert input to units (assuming it's a valid number)
        units = atoi(input);
        if (units < 0) {
            printf("Invalid value. You cannot top up a negative value.\n");
            return;
        }
    }

    // Calculate the cost based on the units
    float cost = units * costPerUnit;

    // Display the details of the top-up and confirm the user's choice
    printf("You are about to buy %d units for R%.2f. Your new balance will be %d.\n", units, cost, user->electricity_units + units);
    printf("Do you want to proceed? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Perform the top-up
        user->electricity_units += units;
        printf("Top-up successful. Your new balance is %d.\n", user->electricity_units);
    } else {
        printf("Top-up cancelled.\n");
    }
}

void change_electricity_usage(User *user) {
    float new_usage;
    system("cls"); // Clear the screen
    printf("Enter new electricity usage per day (in Kw): ");
    scanf("%f", &new_usage);
    if (new_usage < 0 || new_usage > 60000) {
        printf("Invalid value. Electricity usage per day must be between 0 and 60000.\n");
        return;
    }
    // Update the electricity usage per day
    user->electricity_usage_per_day = new_usage;
    printf("Electricity usage per day updated to %.2f Kw\n", user->electricity_usage_per_day);
}
