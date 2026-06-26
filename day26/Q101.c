#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess;

    srand(time(NULL));
    secret = (rand() % 100) + 1;

    printf("Guess a number between 1 and 100\n");

    do {
        printf("Enter guess: ");
        scanf("%d", &guess);

        if (guess > secret) {
            printf("Too high!\n");
        } else if (guess < secret) {
            printf("Too low!\n");
        } else {
            printf("Correct!\n");
        }
    } while (guess != secret);

    return 0;
}