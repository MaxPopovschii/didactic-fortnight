#include <stdio.h>

int main() {
    FILE *f = fopen("numeri.txt", "w");
    if (!f) {
        printf("Impossibile aprire il file per scrittura.\n");
        return 1;
    }
    for (int i = 1; i <= 10; i++) {
        fprintf(f, "%d\n", i);
    }
    fclose(f);
    printf("Numeri scritti su numeri.txt\n");
    return 0;
}