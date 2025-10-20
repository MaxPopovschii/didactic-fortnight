#include <stdio.h>

int main() {
    FILE *src = fopen("input.txt", "r");
    FILE *dst = fopen("output.txt", "w");
    if (!src || !dst) {
        printf("Errore nell'apertura dei file.\n");
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), src)) {
        fputs(buffer, dst);
    }
    fclose(src);
    fclose(dst);
    printf("Copia completata.\n");
    return 0;
}