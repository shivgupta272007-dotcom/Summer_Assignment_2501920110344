#include <stdio.h>

int getStringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[] = "Hello, World!";
    
    int length = getStringLength(str);
    printf("Length of the string is: %d\n", length);
    
    return 0;
}