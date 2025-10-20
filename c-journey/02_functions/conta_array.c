#include <stdio.h>

void riempi_array(int arr[], size_t size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = random() % 10;
    }
}

int conta_array(int arr[], size_t size, int value) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int main() {
    const size_t SIZE = 10;
    int array[SIZE];


    riempi_array(array, SIZE);

    printf("Array: ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; ++i) {
        printf("Valore %d: %d volte\n", i, conta_array(array, SIZE, i));
    }

    return 0;
}