#include <stdio.h>

void transposeMatrix(int r, int c, int A[r][c], int B[c][r]) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            B[j][i] = A[i][j];
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
    
    int B[3][2];
    
    transposeMatrix(r, c, A, B);
    printMatrix(c, r, B);
    
    return 0;
}