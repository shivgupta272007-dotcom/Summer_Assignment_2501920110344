#include <stdio.h>

int findSecondLargest(int arr[], int size) {
    int max1 = arr[0];
    int max2 = -1; 

    for (int i = 1; i < size; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
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

    int secondLargest = findSecondLargest(arr, size);

    if (secondLargest == -1) {
        printf("No second largest element found\n");
    } else {
        printf("Second largest element = %d\n", secondLargest);
    }

    return 0;
}