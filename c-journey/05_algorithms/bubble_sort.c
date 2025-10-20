#include <stdio.h>

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

int main() {
    int arr[5] = {5, 2, 4, 1, 3};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}