#include <stdio.h>

void removeSpaces(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[] = "  C  P r o g r a m m i n g  ";
    
    removeSpaces(str);
    printf("String after removing spaces: %s\n", str);
    
    return 0;
}