#include <stdio.h>
#include <string.h>

int main() {
    char words[5][50] = {"elephant", "cat", "banana", "dog", "it"};
    int n = 5;
    char temp[50];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}