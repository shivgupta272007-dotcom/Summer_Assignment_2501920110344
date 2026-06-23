#include <stdio.h>

int isPalindrome(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int start = 0;
    int end = len - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[] = "radar";

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}