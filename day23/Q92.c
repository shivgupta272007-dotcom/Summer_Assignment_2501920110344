#include <stdio.h>

char findMaxOccurringChar(char str[]) {
    int freq[256] = {0};
    int i = 0;

    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    int max = -1;
    char result = '\0';

    i = 0;
    while (str[i] != '\0') {
        if (max < freq[(unsigned char)str[i]]) {
            max = freq[(unsigned char)str[i]];
            result = str[i];
        }
        i++;
    }

    return result;
}

int main() {
    char str[] = "sample string";
    char result = findMaxOccurringChar(str);

    if (result != '\0') {
        printf("The maximum occurring character is: '%c'\n", result);
    }

    return 0;
}