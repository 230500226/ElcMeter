#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "User.h"
#include "Authentication.h"

// Function prototypes
void topUp(User *user);
void changeElectricityUsage(User *user);

void login(User *users, int numUsers) {
    char username[20], password[20];

    // Prompt the user to enter their username and password
    printf("Please enter your username: ");
    scanf("%s", username);
    getPassword(password);

    // Iterate over the users to find a match for the provided username and password
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            int choice;
            do {
                printf("Welcome %s\n", users[i].username);
                printf("Electricity usage per month: %.2f Kw\n", users[i].electricityUsagePerMonth);
                printf("Electricity units: %d\n", users[i].electricityUnits);
                printf("\n1. Top up\n2. Change electricity usage per month\n3. Logout (exit)\nPlease enter your choice: ");
                if (scanf("%d", &choice) != 1) {
                    handleInvalidInput(3);
                    continue;
                }
                switch (choice) {
                    case 1:
                        topUp(&users[i]); // Call the topUp function
                        break;
                    case 2:
                        changeElectricityUsage(&users[i]); // Call the changeElectricityUsage function
                        break;
                    case 3:
                        break; // Exit the loop and logout
                    default:
                        handleInvalidInput(3); // Handling invalid input
                }
            } while (choice != 3);
            system("cls"); 
            return;
        }
    }
    system("cls"); 
    printf("Invalid username or password.\n");
}

void topUp(User *user) {
    char input[20];
    int units;
    float costPerUnit = user->electricityUsagePerMonth <= 350 ? 1.80 : 3.63; // If the usage p/m is <= to 350 then the statement is true and cost per unit is 1.80 else it is 3.63

    system("cls"); 

    // Display the current balance
    printf("Your balance is: %d\n", user->electricityUnits);

    // Prompt the user to enter the amount of electricity they want to buy
    printf("Please enter how much electricity would you like to buy (use R for rands or type a number for units): ");
    scanf("%s", input);

    if (input[0] == 'R' || input[0] == 'r') {
        // Calculate units based on the amount in rands
        float rands = atof(input + 1); // Ascii to float for calculations and removes the R
        if (rands < 0) {
            printf("Invalid value. You cannot top up a negative value.\n");
            return;
        }
        units = rands / costPerUnit; // Calculates units
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
    printf("You are about to buy %d units for R%.2f. Your new balance will be %d.\n", units, cost, user->electricityUnits + units);
    printf("Do you want to proceed? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Perform the top-up
        user->electricityUnits += units;
        printf("Top-up successful. Your new balance is %d.\n", user->electricityUnits);
    } else {
        printf("Top-up cancelled.\n");
    }
}

void changeElectricityUsage(User *user) {
    float new_usage;
    system("cls"); 
    printf("Enter new Electricity usage per month (in Kw): ");
    scanf("%f", &new_usage);
    if (new_usage < 0 || new_usage > 60000) {
        printf("Invalid value. Electricity usage per month must be between 0 and 60000.\n");
        return;
    }
    // Update the Electricity usage per month
    user->electricityUsagePerMonth = new_usage;
    printf("Electricity usage per month updated to %.2f Kw\n", user->electricityUsagePerMonth);
}
