#include <stdio.h>

int main() {
    FILE *f = fopen("input.txt", "r");
    if (!f) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }
    int lines = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {
        lines++;
    }
    fclose(f);
    printf("Numero di righe: %d\n", lines);
    return 0;
}