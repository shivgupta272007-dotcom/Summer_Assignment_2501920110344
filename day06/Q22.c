#include <stdio.h>

int main() {
    int binary, decimal = 0, base = 1, rem;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    int temp = binary;
    while (temp > 0) {
        rem = temp % 10;
        decimal = decimal + rem * base;
        temp = temp / 10;
        base = base * 2;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}