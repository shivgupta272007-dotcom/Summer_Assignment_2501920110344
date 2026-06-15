#include <stdio.h>

int findFrequency(int arr[], int size, int target) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int size, target;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to find frequency: ");
    scanf("%d", &target);

    int frequency = findFrequency(arr, size, target);
    printf("Frequency of %d = %d\n", target, frequency);

    return 0;
}