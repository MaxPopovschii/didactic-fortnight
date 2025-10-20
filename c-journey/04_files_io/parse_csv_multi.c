#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("prodotti.csv", "r");
    if (!f) {
        perror("Impossibile aprire prodotti.csv");
        return 1;
    }
    char line[128];
    while (fgets(line, sizeof(line), f)) {
        char nome[32], categoria[32];
        float prezzo;
        if (sscanf(line, "%31[^,],%31[^,],%f", nome, categoria, &prezzo) == 3) {
            printf("Prodotto: %s, Categoria: %s, Prezzo: %.2f\n", nome, categoria, prezzo);
        }
    }
    fclose(f);
    return 0;
}