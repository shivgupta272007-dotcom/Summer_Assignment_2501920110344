#include <stdio.h>

void countEvenOdd(int arr[], int size) {
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    printf("Even elements = %d\n", evenCount);
    printf("Odd elements = %d\n", oddCount);
}

int main() {
    int size;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    countEvenOdd(arr, size);

    return 0;
}