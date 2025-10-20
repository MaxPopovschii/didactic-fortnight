#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nome[32];
    float saldo;
} Cliente;

int main() {
    Cliente c1 = {1, "Anna", 1234.56f};
    FILE *f = fopen("clienti.bin", "wb");
    if (!f) {
        perror("Errore apertura file");
        return 1;
    }
    fwrite(&c1, sizeof(Cliente), 1, f);
    fclose(f);

    Cliente c2;
    f = fopen("clienti.bin", "rb");
    if (!f) {
        perror("Errore apertura file");
        return 1;
    }
    fread(&c2, sizeof(Cliente), 1, f);
    fclose(f);
    printf("Letto da file: id=%d, nome=%s, saldo=%.2f\n", c2.id, c2.nome, c2.saldo);
    return 0;
}