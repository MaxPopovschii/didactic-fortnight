#include <stdio.h>

int determinante_3x3(int mat[3][3]) {
    int det = 0;
    det = mat[0][0]*(mat[1][1]*mat[2][2] - mat[1][2]*mat[2][1])
        - mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0])
        + mat[0][2]*(mat[1][0]*mat[2][1] - mat[1][1]*mat[2][0]);
    return det;
}

int main() {
    int mat[3][3];
    printf("Inserisci gli elementi della matrice 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            printf("mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }

    printf("\nMatrice inserita:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%4d ", mat[i][j]);
        printf("\n");
    }

    int det = determinante_3x3(mat);
    printf("\nDeterminante della matrice: %d\n", det);

    return 0;
}