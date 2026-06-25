#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "common";
    char str2[] = "characters";
    
    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; str1[i] != '\0'; i++) {
        count1[(unsigned char)str1[i]]++;
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        count2[(unsigned char)str2[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (count1[i] > 0 && count2[i] > 0) {
            int min = (count1[i] < count2[i]) ? count1[i] : count2[i];
            for (int j = 0; j < min; j++) {
                printf("%c ", i);
            }
        }
    }
    printf("\n");

    return 0;
}