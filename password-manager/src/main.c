#include <stdio.h>
#include <string.h>
#include "password_manager.h"

#define INPUT_SIZE 256

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    PasswordManager pm;
    char service[INPUT_SIZE];
    char password[INPUT_SIZE];
    int choice;
    init_password_manager(&pm);

    // Carica password da file
    if (load_passwords(&pm, PASSWORD_FILE)) {
        printf("Passwords loaded from file.\n");
    } else {
        printf("No saved passwords found. Starting fresh.\n");
    }

    while (1) {
        printf("\n=== Password Manager ===\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Delete Password\n");
        printf("4. List All Passwords\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            clear_stdin();
            continue;
        }
        clear_stdin();

        switch (choice) {
            case 1:
                printf("Enter service name: ");
                fgets(service, INPUT_SIZE, stdin);
                service[strcspn(service, "\n")] = 0;
                printf("Enter password: ");
                fgets(password, INPUT_SIZE, stdin);
                password[strcspn(password, "\n")] = 0;
                if (add_password(&pm, service, password))
                    printf("Password added!\n");
                else
                    printf("Failed to add password (list full).\n");
                break;
            case 2:
                printf("Enter service name: ");
                fgets(service, INPUT_SIZE, stdin);
                service[strcspn(service, "\n")] = 0;
                if (retrieve_password(&pm, service, password))
                    printf("Password for '%s': %s\n", service, password);
                else
                    printf("No password found for '%s'.\n", service);
                break;
            case 3:
                printf("Enter service name: ");
                fgets(service, INPUT_SIZE, stdin);
                service[strcspn(service, "\n")] = 0;
                if (delete_password(&pm, service) == 0)
                    printf("Password deleted!\n");
                else
                    printf("No password found for '%s'.\n", service);
                break;
            case 4:
                printf("Saved passwords:\n");
                list_passwords(&pm);
                break;
            case 5:
                if (save_passwords(&pm, PASSWORD_FILE))
                    printf("Passwords saved. Exiting...\n");
                else
                    printf("Error saving passwords!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}