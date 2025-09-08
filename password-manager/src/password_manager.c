#include <stdio.h>
#include <string.h>
#include "password_manager.h"

#define XOR_KEY 0x5A

void init_password_manager(PasswordManager *pm) {
    pm->count = 0;
}

bool add_password(PasswordManager *pm, const char *service, const char *password) {
    if (pm->count >= MAX_PASSWORDS) return false;
    strncpy(pm->entries[pm->count].service, service, MAX_SERVICE_LENGTH - 1);
    pm->entries[pm->count].service[MAX_SERVICE_LENGTH - 1] = '\0';
    strncpy(pm->entries[pm->count].password, password, MAX_PASSWORD_LENGTH - 1);
    pm->entries[pm->count].password[MAX_PASSWORD_LENGTH - 1] = '\0';
    pm->count++;
    return true;
}

bool retrieve_password(PasswordManager *pm, const char *service, char *password) {
    for (int i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].service, service) == 0) {
            strncpy(password, pm->entries[i].password, MAX_PASSWORD_LENGTH);
            return true;
        }
    }
    return false;
}

int delete_password(PasswordManager *pm, const char *service) {
    for (int i = 0; i < pm->count; i++) {
        if (strcmp(pm->entries[i].service, service) == 0) {
            for (int j = i; j < pm->count - 1; j++) {
                pm->entries[j] = pm->entries[j + 1];
            }
            pm->count--;
            return 0;
        }
    }
    return -1;
}

void list_passwords(PasswordManager *pm) {
    if (pm->count == 0) {
        printf("No passwords saved.\n");
        return;
    }
    for (int i = 0; i < pm->count; i++) {
        printf("%d. %s\n", i + 1, pm->entries[i].service);
    }
}

void xor_crypt(char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= XOR_KEY;
    }
}

bool save_passwords(PasswordManager *pm, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) return false;
    fwrite(&pm->count, sizeof(int), 1, f);
    for (int i = 0; i < pm->count; i++) {
        PasswordEntry entry = pm->entries[i];
        xor_crypt(entry.password, strlen(entry.password));
        fwrite(&entry, sizeof(PasswordEntry), 1, f);
    }
    fclose(f);
    return true;
}

bool load_passwords(PasswordManager *pm, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return false;
    fread(&pm->count, sizeof(int), 1, f);
    for (int i = 0; i < pm->count; i++) {
        fread(&pm->entries[i], sizeof(PasswordEntry), 1, f);
        xor_crypt(pm->entries[i].password, strlen(pm->entries[i].password));
    }
    fclose(f);
    return true;
}