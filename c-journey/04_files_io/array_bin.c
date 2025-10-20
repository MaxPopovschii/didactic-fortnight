#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    FILE *f = fopen("array.bin", "wb");
    if (!f) {
        perror("Errore apertura file");
        return 1;
    }
    fwrite(arr, sizeof(int), 5, f);
    fclose(f);

    int arr2[5] = {0};
    f = fopen("array.bin", "rb");
    if (!f) {
        perror("Errore apertura file");
        return 1;
    }
    fread(arr2, sizeof(int), 5, f);
    fclose(f);

    printf("Array letto da file binario:\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    return 0;
}