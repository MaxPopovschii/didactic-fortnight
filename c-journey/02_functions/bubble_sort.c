#include <stdio.h>

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void riempi_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }
}

void stampa_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[15];
    int size = sizeof(numbers) / sizeof(numbers[0]);
    riempi_array(numbers, size);
    printf("Array generato:\n");
    stampa_array(numbers, size);
    bubble_sort(numbers, size);

    printf("Array ordinato:\n");
    stampa_array(numbers, size);

    return 0;
}