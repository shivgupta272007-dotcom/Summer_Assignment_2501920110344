#include <stdio.h>

int main() {
    int n, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++; 
        }
    }
    if (count == 2) {
        printf("Prime\n");
    } else {
        printf("Not Prime\n");
    }

    return 0;
}