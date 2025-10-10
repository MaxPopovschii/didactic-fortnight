#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float media(int arr[], int size) {
    if (size == 0) return 0.0f;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

void riempi_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Numeri casuali tra 0 e 99
    }
}

int main() {
    srand(time(NULL)); // Inizializza il generatore di numeri casuali
    int numbers[100];
    riempi_array(numbers, 100);
    int size = sizeof(numbers) / sizeof(numbers[0]);
    float avg = media(numbers, size);
    printf("Media: %.2f\n", avg);
    return 0;
}