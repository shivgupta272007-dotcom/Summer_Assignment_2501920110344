#include <stdio.h>

char findFirstNonRepeating(char str[]) {
    int freq[256] = {0};
    int i = 0;

    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    i = 0;
    while (str[i] != '\0') {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
        i++;
    }

    return '\0';
}

int main() {
    char str[] = "racecar";
    char result = findFirstNonRepeating(str);

    if (result != '\0') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("All characters repeat.\n");
    }

    return 0;
}