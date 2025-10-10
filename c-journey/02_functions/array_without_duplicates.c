#include <stdio.h>
#include <stdlib.h>

void riempi_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 20; // Valori casuali da 0 a 19
    }
}

void stampa_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int rimuovi_duplicati(const int arr[], int size, int out[]) {
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        int duplicato = 0;
        for (int j = 0; j < new_size; j++) {
            if (arr[i] == out[j]) {
                duplicato = 1;
                break;
            }
        }
        if (!duplicato) {
            out[new_size++] = arr[i];
        }
    }
    return new_size;
}

int main() {
    int arr[20];
    int unici[20];
    riempi_array(arr, 20);
    printf("Array originale:\n");
    stampa_array(arr, 20);

    int new_size = rimuovi_duplicati(arr, 20, unici);
    printf("Array senza duplicati:\n");
    stampa_array(unici, new_size);

    return 0;
}