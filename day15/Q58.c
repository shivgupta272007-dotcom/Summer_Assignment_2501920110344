#include <stdio.h>

void rotateLeft(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int temp = arr[0];

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[size - 1] = temp;
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

    rotateLeft(arr, size);

    printf("Rotated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}