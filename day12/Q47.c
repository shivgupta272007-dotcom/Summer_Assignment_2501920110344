#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return b;
}

int main() {
    int n;

    printf("Enter position: ");
    scanf("%d", &n);

    printf("Fibonacci number is: %d\n", fibonacci(n));

    return 0;
}