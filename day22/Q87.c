#include <stdio.h>

void countFrequency(char str[]) {
    int freq[256] = {0};
    int i = 0;

    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' = %d\n", i, freq[i]);
        }
    }
}

int main() {
    char str[] = "apple";

    countFrequency(str);

    return 0;
}