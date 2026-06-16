#include <stdio.h>

int findMaxFrequencyElement(int arr[], int size) {
    int maxElement = arr[0];
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        int count = 0;
        
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }

    return maxElement;
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

    int result = findMaxFrequencyElement(arr, size);
    printf("Element with maximum frequency: %d\n", result);

    return 0;
}