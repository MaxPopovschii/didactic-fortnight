#include <stdio.h>

int main() {
    FILE *f = fopen("non_esiste.txt", "r");
    if (!f) {
        perror("Errore apertura file");
        return 1;
    }
    // ... eventuale lettura ...
    fclose(f);
    return 0;
}