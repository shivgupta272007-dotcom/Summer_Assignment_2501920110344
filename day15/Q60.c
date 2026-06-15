#include <stdio.h>

void moveZerosToEnd(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
            count++;
        }
    }
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

    moveZerosToEnd(arr, size);

    printf("Result array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}