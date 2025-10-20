#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("dati.csv", "r");
    if (!f) {
        printf("Impossibile aprire dati.csv\n");
        return 1;
    }
    char line[128];
    while (fgets(line, sizeof(line), f)) {
        char nome[32], cognome[32];
        int eta;
        if (sscanf(line, "%31[^,],%31[^,],%d", nome, cognome, &eta) == 3) {
            printf("Nome: %s, Cognome: %s, Età: %d\n", nome, cognome, eta);
        }
    }
    fclose(f);
    return 0;
}