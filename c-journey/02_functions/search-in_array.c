#include <stdio.h>  

void riempi_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Riempie l'array con valori casuali tra 0 e 99
    }
}

void stampa_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cerca_in_array(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Restituisce l'indice se trovato
        }
    }
    return -1; // Restituisce -1 se non trovato
}

int main() {
    int arr[10];
    riempi_array(arr, 10);
    printf("Array generato: ");
    stampa_array(arr, 10);

    int target;
    printf("Inserisci un numero da cercare: ");
    scanf("%d", &target);

    int index = cerca_in_array(arr, 10, target);
    if (index != -1) {
        printf("Numero %d trovato all'indice %d.\n", target, index);
    } else {
        printf("Numero %d non trovato nell'array.\n", target);
    }

    return 0;
}