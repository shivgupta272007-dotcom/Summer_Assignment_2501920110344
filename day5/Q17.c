#include <stdio.h>

int main() {
    int num, sum = 0, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num && num > 0) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is NOT a perfect number.\n", num);
    }

    return 0;
}