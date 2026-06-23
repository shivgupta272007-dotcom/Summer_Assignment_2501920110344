#include <stdio.h>

void findRowSum(int r, int c, int matrix[r][c]) {
    int i, j;
    for (i = 0; i < r; i++) {
        int rowSum = 0;
        for (j = 0; j < c; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, rowSum);
    }
}

int main() {
    int r = 3, c = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    findRowSum(r, c, matrix);

    return 0;
}