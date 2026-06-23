#include <stdio.h>

int countWords(char str[]) {
    int count = 0;
    int i = 0;
    int inWord = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    char str[] = "   Count the total  words in   this sentence. ";
    
    int words = countWords(str);
    printf("Total number of words: %d\n", words);
    
    return 0;
}