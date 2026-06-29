#include <stdio.h>

#define MAX_SIZE 100

void display_array(int arr[], int size) {
    printf("\n--- Current Array Elements ---\n");
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }
    
    printf("Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTotal Count: %d\n", size);
}

void insert_element(int arr[], int *size) {
    printf("\n--- Insert Element ---\n");
    if (*size >= MAX_SIZE) {
        printf("❌ Error: Array overflow! Cannot insert more elements.\n");
        return;
    }

    int element, position;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (0 to %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("❌ Error: Invalid position! Position must be between 0 and %d.\n", *size);
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    (*size)++;
    printf("✅ Element %d inserted successfully at position %d.\n", element, position);
}

void delete_element(int arr[], int *size) {
    printf("\n--- Delete Element ---\n");
    if (*size == 0) {
        printf("❌ Error: Array underflow! Nothing to delete.\n");
        return;
    }

    int position;
    printf("Enter the position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("❌ Error: Invalid position!\n");
        return;
    }

    int deleted_value = arr[position];
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("🗑️ Element %d removed successfully from position %d.\n", deleted_value, position);
}

void search_element(int arr[], int size) {
    printf("\n--- Search Element ---\n");
    if (size == 0) {
        printf("The array is empty.\n");
        return;
    }

    int target, found = 0;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("🔍 Element found at index/position: %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("❌ Element %d not found in the array.\n", target);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("     ARRAY OPERATIONS SYSTEM     \n");
        printf("=================================\n");
        printf("1. Traverse / Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            display_array(arr, size);
        } else if (choice == 2) {
            insert_element(arr, &size);
        } else if (choice == 3) {
            delete_element(arr, &size);
        } else if (choice == 4) {
            search_element(arr, size);
        } else if (choice == 5) {
            printf("\nExiting Array System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-5.\n");
        }
    }

    return 0;
}