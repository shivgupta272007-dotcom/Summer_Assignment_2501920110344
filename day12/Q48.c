#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum = sum + i;
        }
    }

    if (sum == num && num != 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfect(num)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}