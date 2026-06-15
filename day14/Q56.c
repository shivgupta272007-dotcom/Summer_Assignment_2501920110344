#include <stdio.h>

void findDuplicates(int arr[], int size) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                found = 1;
                break; 
            }
        }
    }

    if (found == 0) {
        printf("No duplicates found");
    }
    printf("\n");
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

    printf("Duplicate elements are: ");
    findDuplicates(arr, size);

    return 0;
}