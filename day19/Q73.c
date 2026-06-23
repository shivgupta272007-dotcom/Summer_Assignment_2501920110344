#include <stdio.h>

void addMatrices(int r, int c, int A[r][c], int B[r][c], int C[r][c]) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
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
    int r = 2, c = 3;
    
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int B[2][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };
    
    int C[2][3];
    
    addMatrices(r, c, A, B, C);
    printMatrix(r, c, C);
    
    return 0;
}