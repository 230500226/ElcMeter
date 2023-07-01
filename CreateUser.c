#include <stdio.h>
#include <string.h>
#include "Authentication.h"
#include "User.h"

void create_account(User *users, int *num_users) {
    if (*num_users >= MAX_USERS) {
        printf("Sorry, the maximum number of users has been reached.\n");
        return;
    }
    printf("Please enter a username: ");
    scanf("%s", users[*num_users].username);
    getPassword(users[*num_users].password);
    printf("Enter electricity usage per day (in Kw): ");
    scanf("%f", &users[*num_users].electricity_usage_per_day);
    users[*num_users].electricity_units = 100;
    (*num_users)++;
}
