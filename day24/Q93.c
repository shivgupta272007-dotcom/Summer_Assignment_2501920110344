#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isRotation(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return 0;
    }

    char *temp = (char *)malloc(sizeof(char) * (len1 * 2 + 1));
    if (temp == NULL) {
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);

    int result = 0;
    if (strstr(temp, str2) != NULL) {
        result = 1;
    }

    free(temp);

    return result;
}

int main() {
    char str1[] = "rotation";
    char str2[] = "tionrota";

    if (isRotation(str1, str2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}