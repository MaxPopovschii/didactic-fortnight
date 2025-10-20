#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10

void stampa_matrice(int mat[MAX_N][MAX_N], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

void ruota_matrice(int mat[MAX_N][MAX_N], int N) {
    // Ruota la matrice di 90° in senso orario (in-place)
    for (int layer = 0; layer < N / 2; layer++) {
        int first = layer;
        int last = N - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = mat[first][i];
            // sinistra -> sopra
            mat[first][i] = mat[last - offset][first];
            // sotto -> sinistra
            mat[last - offset][first] = mat[last][last - offset];
            // destra -> sotto
            mat[last][last - offset] = mat[i][last];
            // sopra -> destra
            mat[i][last] = top;
        }
    }
}

int main() {
    int N;
    int mat[MAX_N][MAX_N];

    srand(time(NULL));
    printf("Inserisci la dimensione della matrice quadrata (max %d): ", MAX_N);
    scanf("%d", &N);
    if (N < 1 || N > MAX_N) {
        printf("Dimensione non valida.\n");
        return 1;
    }

    // Riempie la matrice con numeri casuali
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = rand() % 100;

    printf("\nMatrice originale:\n");
    stampa_matrice(mat, N);

    ruota_matrice(mat, N);

    printf("\nMatrice ruotata di 90 gradi:\n");
    stampa_matrice(mat, N);

    return 0;
}