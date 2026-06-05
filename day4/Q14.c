#include <stdio.h>

int main() {
    int n;
    int t1 = 0, t2 = 1, nextTerm = 0;
    printf("Enter the term position (n): ");
    scanf("%d", &n);
    if (n == 0) {
        printf("The 0th Fibonacci term is: %d \n", t1);
        return 0;
    } else if (n == 1) {
        printf("The 1st Fibonacci term is: %d \n", t2);
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    printf("The %d-th Fibonacci term is: %d ", n, t2);

    return 0;
}