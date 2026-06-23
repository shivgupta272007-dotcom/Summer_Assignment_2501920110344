#include <stdio.h>

void multiplyMatrices(int r1, int c1, int c2, int A[r1][c1], int B[c1][c2], int C[r1][c2]) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int r, int c, int matrix[r][c]) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 2;

    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int C[2][2];

    multiplyMatrices(r1, c1, c2, A, B, C);
    printMatrix(r1, c2, C);

    return 0;
}