#include <stdio.h>

void calculateSumAndAverage(int arr[], int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    
    float average = (float)sum / size;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
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

    calculateSumAndAverage(arr, size);

    return 0;
}