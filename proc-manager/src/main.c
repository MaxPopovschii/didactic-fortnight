#include <stdio.h>
#include <string.h>
#include "proc.h"

int main() {
    int choice, pid;
    char name[128];

    while (1) {
        printf("\n=== Process Manager ===\n");
        printf("1. List processes\n");
        printf("2. Search process by name\n");
        printf("3. Kill process by PID\n");
        printf("4. Exit\n");
        printf("Choose: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                printf("Enter process name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                search_process(name);
                break;
            case 3:
                printf("Enter PID to kill: ");
                if (scanf("%d", &pid) == 1)
                    kill_process(pid);
                while (getchar() != '\n');
                break;
            case 4:
                printf("Bye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}