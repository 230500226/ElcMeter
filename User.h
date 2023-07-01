#ifndef User_H
#define User_H

typedef struct {
    char username[20];
    char password[20];
    float electricity_usage_per_day;
    int electricity_units;
} User;

#define MAX_USERS 100

void create_account(User *users, int *num_users);
void login(User *users, int num_users);

#endif