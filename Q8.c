#include <stdio.h>

int main() {
    int num, temp, remainder, reversed_num = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    temp = num;
    while (temp > 0) {
        remainder = temp % 10;
        reversed_num = reversed_num * 10 + remainder;
        temp = temp / 10;
    }
    if (num == reversed_num) {
        printf("%d is a palindrome number.\n", num);
    } else {
        printf("%d is not a palindrome number.\n", num);
    }

    return 0;
}