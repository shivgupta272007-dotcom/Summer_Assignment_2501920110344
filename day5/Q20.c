#include <stdio.h>

int main() {
    int num, maxPrimeFactor = -1;
    int i, temp;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    temp = num;

    while (temp % 2 == 0) {
        maxPrimeFactor = 2;
        temp /= 2;
    }

    for (i = 3; i * i <= temp; i += 2) {
        while (temp % i == 0) {
            maxPrimeFactor = i;
            temp /= i;
        }
    }

    if (temp > 2) {
        maxPrimeFactor = temp;
    }

    if (num <= 1) {
        printf("Numbers less than or equal to 1 do not have prime factors.\n");
    } else {
        printf("The largest prime factor of %d is: %d\n", num, maxPrimeFactor);
    }

    return 0;
}