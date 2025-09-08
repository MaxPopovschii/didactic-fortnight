#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 256
#define MAX_SERVICE_LENGTH 50
#define MAX_PASSWORDS 100
#define PASSWORD_FILE "passwords.dat"

typedef struct {
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

typedef struct {
    PasswordEntry entries[MAX_PASSWORDS];
    int count;
} PasswordManager;

void init_password_manager(PasswordManager *pm);
bool add_password(PasswordManager *pm, const char *service, const char *password);
bool retrieve_password(PasswordManager *pm, const char *service, char *password);
int delete_password(PasswordManager *pm, const char *service);
void list_passwords(PasswordManager *pm);
bool save_passwords(PasswordManager *pm, const char *filename);
bool load_passwords(PasswordManager *pm, const char *filename);

#endif // PASSWORD_MANAGER_H