#include <stdio.h>

void findPairWithSum(int arr[], int size, int targetSum) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == targetSum) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
                return; 
            }
        }
    }

    if (found == 0) {
        printf("No pair found with the given sum\n");
    }
}

int main() {
    int size, targetSum;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    findPairWithSum(arr, size, targetSum);

    return 0;
}