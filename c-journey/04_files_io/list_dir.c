#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("Impossibile aprire la directory");
        return 1;
    }
    struct dirent *entry;
    printf("File nella directory corrente:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}