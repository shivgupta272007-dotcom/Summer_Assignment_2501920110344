#include <stdio.h>

void reverseString(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int start = 0;
    int end = len - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "Structures";
    
    reverseString(str);
    printf("Reversed string: %s\n", str);
    
    return 0;
}