#include <stdio.h>

int main() {
    int answer;
    int score = 0;

    printf("=================================\n");
    printf("     WELCOME TO THE QUIZ GAME    \n");
    printf("=================================\n\n");

    // Question 1
    printf("Q1. Which data type is used to store a single character in C?\n");
    printf("1. int\n2. char\n3. float\n4. double\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! The correct answer was 2. char\n\n");
    }

    // Question 2
    printf("Q2. What is the indexing format of arrays in C?\n");
    printf("1. Starts from 1\n2. Starts from -1\n3. Starts from 0\n4. Random\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! The correct answer was 3. Starts from 0\n\n");
    }

    // Question 3
    printf("Q3. Which of the following is used to terminate a statement in C?\n");
    printf("1. Colon (:)\n2. Semicolon (;)\n3. Period (.)\n4. Comma (,)\n");
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    if (answer == 2) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong! The correct answer was 2. Semicolon (;)\n\n");
    }

    // Quiz Summary
    printf("=================================\n");
    printf("            GAME OVER            \n");
    printf("=================================\n");
    printf("Your final score is: %d out of 3\n", score);

    if (score == 3) {
        printf("Perfect score! Excellent job.\n");
    } else if (score >= 1) {
        printf("Good effort! Keep learning.\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}