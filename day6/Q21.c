#include <stdio.h>

int main() {
    int decimal, remainder;
    int binary = 0, place = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    int temp = decimal;
    while (temp > 0) {
        remainder = temp % 2;
        binary = binary + (remainder * place);
        place = place * 10;
        temp = temp / 2;
    }

    printf("Binary equivalent: %d\n", binary);

    return 0;
}