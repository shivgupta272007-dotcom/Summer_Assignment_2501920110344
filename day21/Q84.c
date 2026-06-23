#include <stdio.h>

void toUpperCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

int main() {
    char str[] = "hello WORLD 123";
    
    toUpperCase(str);
    printf("Uppercase string: %s\n", str);
    
    return 0;
}