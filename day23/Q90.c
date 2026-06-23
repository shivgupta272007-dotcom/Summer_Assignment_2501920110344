#include <stdio.h>

char findFirstRepeating(char str[]) {
    int freq[256] = {0};
    int i = 0;

    while (str[i] != '\0') {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
        freq[(unsigned char)str[i]]++;
        i++;
    }

    return '\0';
}

int main() {
    char str[] = "abcdefba";
    char result = findFirstRepeating(str);

    if (result != '\0') {
        printf("The first repeating character is: %c\n", result);
    } else {
        printf("No repeating characters found.\n");
    }

    return 0;
}