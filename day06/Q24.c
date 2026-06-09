#include <stdio.h>

int main() {
    int x, n;
    int result = 1;

    printf("Enter base (x): ");
    scanf("%d", &x);
    printf("Enter exponent (n): ");
    scanf("%d", &n);

    int exponent = n;
    if (exponent < 0) {
        exponent = -exponent;
    }

    for (int i = 0; i < exponent; i++) {
        result *= x;
    }

    if (n < 0) {
        printf("%d^%d = 1/%d\n", x, n, result);
    } else {
        printf("%d^%d = %d\n", x, n, result);
    }

    return 0;
}