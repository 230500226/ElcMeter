#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Authentication.h"

// Function to handle invalid user input
void handleInvalidInput(int options) {
    system("cls");
    printf("Invalid choice. Please enter a number from 1 to %d.\n", options);
    // Clear the input buffer to remove any remaining characters
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
    // This effectively restarts the input part of the program while preserving previous data
}

//function to get the Password
void getPassword(char *password) {
    char ch; // Variable to store the input character
    int index = 0;

    printf("Please enter your password: ");
        
    while ((ch = getch()) != '\r') { // Reads input characters until the Enter key is pressed ('\r' represents the Enter key)
        if (isalnum(ch) || ispunct(ch)) { // Checks if the input character is a letter, a digit, or a special character
            printf("*"); // Prints an asterisk instead of the actual character
            password[index++] = ch; // Appends the character to the end of the password string
        }
    }
    password[index] = '\0'; // Adds a null terminator to the end of the password string
    
    printf("\n"); // Prints a new line after the password is entered
}
