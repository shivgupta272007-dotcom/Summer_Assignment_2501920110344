#include <stdio.h>

int isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int remainder;

    while (num > 0) {
        remainder = num % 10;
        sum = sum + (remainder * remainder * remainder);
        num = num / 10;
    }

    if (sum == original) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}