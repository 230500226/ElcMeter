#ifndef User_H
#define User_H

typedef struct {
    char username[20];
    char password[20];
    float electricityUsagePerMonth;
    int electricityUnits;
} User;

#define MAX_USERS 100

void createAccount(User *users, int *numUsers);
void login(User *users, int numUsers);

#endif