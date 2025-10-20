#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char nome[50];
    char telefono[20];
} Contatto;

void aggiungi_contatto(Contatto rubrica[], int *n) {
    if (*n >= MAX_CONTACTS) {
        printf("Rubrica piena!\n");
        return;
    }
    printf("Nome: ");
    scanf("%49s", rubrica[*n].nome);
    printf("Telefono: ");
    scanf("%19s", rubrica[*n].telefono);
    (*n)++;
}

void cerca_contatto(Contatto rubrica[], int n) {
    char nome[50];
    printf("Cerca nome: ");
    scanf("%49s", nome);
    for (int i = 0; i < n; i++) {
        if (strcmp(rubrica[i].nome, nome) == 0) {
            printf("Trovato: %s - %s\n", rubrica[i].nome, rubrica[i].telefono);
            return;
        }
    }
    printf("Contatto non trovato.\n");
}

void mostra_rubrica(Contatto rubrica[], int n) {
    printf("Rubrica:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %s\n", i + 1, rubrica[i].nome, rubrica[i].telefono);
    }
}

int main() {
    Contatto rubrica[MAX_CONTACTS];
    int n = 0;
    int scelta;
    do {
        printf("\n1. Aggiungi contatto\n2. Cerca contatto\n3. Mostra rubrica\n0. Esci\nScelta: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1: aggiungi_contatto(rubrica, &n); break;
            case 2: cerca_contatto(rubrica, n); break;
            case 3: mostra_rubrica(rubrica, n); break;
            case 0: printf("Uscita.\n"); break;
            default: printf("Scelta non valida.\n");
        }
    } while (scelta != 0);
    return 0;
}