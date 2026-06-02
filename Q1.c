#include <stdio.h>

int main() {
    int N, i;
    int sum = 0; 

    printf("Enter a positive integer (N): ");
    scanf("%d", &N);

    if (N < 1) {
        printf("Please enter a valid natural number (greater than 0).\n");
    } else {
        
        for(i = 1; i <= N; i++) {
            sum += i; 
        }
        printf("The sum of the first %d natural numbers is: %d \n", N,  sum);
    }

    return 0;
}
