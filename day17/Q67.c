#include <stdio.h>

void printIntersection(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        int isAlreadyPrinted = 0;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isAlreadyPrinted = 1;
                break;
            }
        }

        if (isAlreadyPrinted == 0) {
            for (int j = 0; j < size2; j++) {
                if (arr1[i] == arr2[j]) {
                    printf("%d ", arr1[i]);
                    break;
                }
            }
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

    printf("Intersection of arrays: ");
    printIntersection(arr1, size1, arr2, size2);

    return 0;
}