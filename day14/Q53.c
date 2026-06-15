#include <stdio.h>

int main() {
    int size, target, found = 0;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Not found\n");
    }

    return 0;
}