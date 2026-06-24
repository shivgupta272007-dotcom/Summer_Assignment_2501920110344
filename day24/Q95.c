#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Deep learning and artificial intelligence are transforming the world";
    char longest[100] = "";
    char word[100];
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';
            if (strlen(word) > strlen(longest)) {
                strcpy(longest, word);
            }
            j = 0;
        }
        i++;
    }
    
    word[j] = '\0';
    if (strlen(word) > strlen(longest)) {
        strcpy(longest, word);
    }

    printf("%s\n", longest);

    return 0;
}