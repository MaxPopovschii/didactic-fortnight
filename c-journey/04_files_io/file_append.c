#include <stdio.h>

int main() {
    FILE *f = fopen("log.txt", "a");
    if (!f) {
        printf("Impossibile aprire il file per aggiunta.\n");
        return 1;
    }
    fprintf(f, "Nuova riga di log\n");
    fclose(f);
    printf("Riga aggiunta a log.txt\n");
    return 0;
}