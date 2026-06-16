#include <stdio.h>

int findMissingNumber(int arr[], int size) {
    int n = size + 1;
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;

    for (int i = 0; i < size; i++) {
        arraySum = arraySum + arr[i];
    }

    return totalSum - arraySum;
}

int main() {
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements (from 1 to %d with one missing):\n", size + 1);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findMissingNumber(arr, size);
    printf("The missing number is: %d\n", missing);

    return 0;
}