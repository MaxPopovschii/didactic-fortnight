#include <stdio.h>

#define MAX_N 10

int main() {
    int N, mat[MAX_N][MAX_N];
    printf("Inserisci la dimensione della matrice quadrata (max %d): ", MAX_N);
    scanf("%d", &N);
    if (N < 1 || N > MAX_N) {
        printf("Dimensione non valida.\n");
        return 1;
    }

    printf("Inserisci gli elementi della matrice:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }

    int somma_principale = 0, somma_secondaria = 0;
    for (int i = 0; i < N; i++) {
        somma_principale += mat[i][i];
        somma_secondaria += mat[i][N - 1 - i];
    }

    printf("\nMatrice inserita:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }

    printf("\nSomma diagonale principale: %d\n", somma_principale);
    printf("Somma diagonale secondaria: %d\n", somma_secondaria);

    return 0;
}