#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "programming";
    int len = strlen(str);
    int index = 0;

    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == i) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';

    printf("%s\n", str);

    return 0;
}