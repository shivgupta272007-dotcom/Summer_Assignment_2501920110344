#include <stdio.h>

int findFactorial(int num);

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d = %d\n", n, findFactorial(n));
    }

    return 0;
}

int findFactorial(int num) {
    int factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    return factorial;
}
