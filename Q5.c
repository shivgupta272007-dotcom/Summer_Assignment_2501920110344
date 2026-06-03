#include <stdio.h>

int main() {
    int num, temp, remainder, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    temp = num;
    while (temp > 0) {
        remainder = temp % 10;  
        sum += remainder;      
        temp = temp / 10;       
    }
    printf("The sum of the digits of %d is: %d\n", num, sum);

    return 0;
}