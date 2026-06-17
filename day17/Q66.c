#include <stdio.h>

void printUnion(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < i; j++) {
            if (arr1[i] == arr1[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate == 0) {
            printf("%d ", arr1[i]);
        }
    }

    for (int i = 0; i < size2; i++) {
        int isDuplicate = 0;
        
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (isDuplicate == 0) {
            for (int j = 0; j < i; j++) {
                if (arr2[i] == arr2[j]) {
                    isDuplicate = 1;
                    break;
                }
            }
        }

        if (isDuplicate == 0) {
            printf("%d ", arr2[i]);
        }
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter elements of first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter elements of second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Union of arrays: ");
    printUnion(arr1, size1, arr2, size2);

    return 0;
}