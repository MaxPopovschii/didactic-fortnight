#include <stdio.h>

int main() {
    FILE *f = fopen("test.txt", "r");
    if (!f) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
    }
    fclose(f);
    return 0;
}