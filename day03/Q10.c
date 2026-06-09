#include <stdio.h>

int main() {
    int lower, upper;
    printf("Enter lower limit: ");
    scanf("%d", &lower);
    printf("Enter upper limit: ");
    scanf("%d", &upper);

    printf("Prime numbers between %d and %d are:\n", lower, upper);
    for (int num = lower; num <= upper; num++) {
        if (num <= 1) {
            continue;
        }
        int isPrime = 1; 
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0; 
                break;       
            }
        }
        if (isPrime == 1) {
            printf("%d ", num);
        }
    }

    printf("\n");
    return 0;
}