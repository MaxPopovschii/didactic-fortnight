#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[32];
    int eta;
} Persona;

int main() {
    Persona p1 = {"Mario", 30};
    FILE *f = fopen("persone.bin", "wb");
    if (!f) {
        printf("Errore apertura file.\n");
        return 1;
    }
    fwrite(&p1, sizeof(Persona), 1, f);
    fclose(f);

    // Lettura
    Persona p2;
    f = fopen("persone.bin", "rb");
    if (!f) {
        printf("Errore apertura file.\n");
        return 1;
    }
    fread(&p2, sizeof(Persona), 1, f);
    fclose(f);
    printf("Letto da file: %s, %d\n", p2.nome, p2.eta);
    return 0;
}