#include <stdio.h>
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int main() {
    int n1, n2, gcd, lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);
    gcd = findGCD(n1, n2);
    lcm = (n1 / gcd) * n2;

    printf("LCM of %d and %d is: %d\n", n1, n2, lcm);

    return 0;
}