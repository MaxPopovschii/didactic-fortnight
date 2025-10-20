#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quanti elementi? ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}