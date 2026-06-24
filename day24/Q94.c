#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compressString(const char *str) {
    int len = strlen(str);
    if (len == 0) return "";

    char *compressed = (char*)malloc(sizeof(char) * (len * 2 + 1));
    if (compressed == NULL) return NULL;

    int index = 0;
    int count = 1;

    for (int i = 0; i < len; i++) {
        if (i + 1 < len && str[i] == str[i + 1]) {
            count++;
        } else {
            index += sprintf(&compressed[index], "%c%d", str[i], count);
            count = 1;
        }
    }

    if (strlen(compressed) >= len) {
        free(compressed);
        return (char*)str;
    }

    return compressed;
}

int main() {
    char str[] = "aabcccccaaa";
    char *result = compressString(str);

    printf("Original: %s\n", str);
    printf("Compressed: %s\n", result);

    if (result != str) {
        free(result);
    }

    return 0;
}