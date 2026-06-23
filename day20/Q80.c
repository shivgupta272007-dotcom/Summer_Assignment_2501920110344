#include <stdio.h>

void findColumnSum(int r, int c, int matrix[r][c]) {
    int i, j;
    for (j = 0; j < c; j++) {
        int colSum = 0;
        for (i = 0; i < r; i++) {
            colSum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }
}

int main() {
    int r = 3, c = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    findColumnSum(r, c, matrix);

    return 0;
}