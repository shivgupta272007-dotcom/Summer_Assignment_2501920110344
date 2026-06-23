#include <stdio.h>

void findDiagonalSum(int n, int matrix[n][n]) {
    int i;
    int primarySum = 0;
    int secondarySum = 0;

    for (i = 0; i < n; i++) {
        primarySum += matrix[i][i];
        secondarySum += matrix[i][n - i - 1];
    }

    printf("Primary Diagonal Sum: %d\n", primarySum);
    printf("Secondary Diagonal Sum: %d\n", secondarySum);
}

int main() {
    int n = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    findDiagonalSum(n, matrix);

    return 0;
}