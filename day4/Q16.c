#include <stdio.h>
#include <math.h>

int main() {
    int lower, upper, remainder, digits;
    int result;
    printf("Enter lower limit: ");
    scanf("%d", &lower);
    printf("Enter upper limit: ");
    scanf("%d", &upper);
    printf("Armstrong numbers between %d and %d are:\n", lower, upper);
    for (int num = lower; num <= upper; num++) {
        if (num < 0) {
            continue;
        }
        int temp = num;
        digits = 0;
        result = 0.0;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }
        temp = num; 
        while (temp != 0) {
            remainder = temp % 10;
            result += pow(remainder, digits);
            temp /= 10;
        }
        if ((int)result == num) {
            printf("%d ", num);
        }
    }

    printf("\n");
    return 0;
}