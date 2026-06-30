#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LENGTH 50

struct Item {
    int itemId;
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

void addItem(struct Item store[], int *count);
void displayInventory(struct Item store[], int count);
void searchItem(struct Item store[], int count);
void generateBill(struct Item store[], int count);

int main() {
    struct Item store[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    while (1) {
        printf("\n=== STORE INVENTORY & BILLING SYSTEM ===\n");
        printf("1. Add New Item\n");
        printf("2. View Inventory\n");
        printf("3. Search Item by ID\n");
        printf("4. Generate Customer Bill\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(store, &itemCount);
                break;
            case 2:
                displayInventory(store, itemCount);
                break;
            case 3:
                searchItem(store, itemCount);
                break;
            case 4:
                generateBill(store, itemCount);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

void addItem(struct Item store[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Store house full! Cannot add more items.\n");
        return;
    }

    printf("\nEnter Item ID: ");
    scanf("%d", &store[*count].itemId);
    
    getchar(); 

    printf("Enter Item Name: ");
    fgets(store[*count].name, NAME_LENGTH, stdin);
    store[*count].name[strcspn(store[*count].name, "\n")] = '\0';

    printf("Enter Stock Quantity: ");
    scanf("%d", &store[*count].quantity);

    printf("Enter Unit Price: ");
    scanf("%f", &store[*count].price);

    (*count)++;
    printf("Item added to inventory successfully!\n");
}

void displayInventory(struct Item store[], int count) {
    if (count == 0) {
        printf("\nInventory is currently empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "Item ID", "Item Name", "Qty Stock", "Price");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-12d %-10.2f\n", store[i].itemId, store[i].name, store[i].quantity, store[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

void searchItem(struct Item store[], int count) {
    if (count == 0) {
        printf("\nInventory is empty. No items to search.\n");
        return;
    }

    int targetId;
    int found = 0;

    printf("\nEnter Item ID to search: ");
    scanf("%d", &targetId);

    for (int i = 0; i < count; i++) {
        if (store[i].itemId == targetId) {
            printf("\nItem Found!\n");
            printf("ID       : %d\n", store[i].itemId);
            printf("Name     : %s\n", store[i].name);
            printf("In-Stock : %d\n", store[i].quantity);
            printf("Price    : $%.2f\n", store[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d not found.\n", targetId);
    }
}

void generateBill(struct Item store[], int count) {
    if (count == 0) {
        printf("\nCannot generate bill. Inventory is empty.\n");
        return;
    }

    int targetId, orderQty;
    int found = 0;
    float totalBill = 0.0;

    printf("\n--- CUSTOMER BILLING ---\n");
    printf("Enter Item ID to purchase: ");
    scanf("%d", &targetId);

    for (int i = 0; i < count; i++) {
        if (store[i].itemId == targetId) {
            found = 1;
            printf("Item Found: %s | Price: $%.2f | Available Stock: %d\n", store[i].name, store[i].price, store[i].quantity);
            printf("Enter quantity to purchase: ");
            scanf("%d", &orderQty);

            if (orderQty <= 0) {
                printf("Invalid quantity requested.\n");
            } else if (orderQty > store[i].quantity) {
                printf("Insufficient stock! Only %d units available.\n", store[i].quantity);
            } else {
                totalBill = orderQty * store[i].price;
                store[i].quantity -= orderQty; 

                printf("\n=============================\n");
                printf("        INVOICE RECEIPT      \n");
                printf("=============================\n");
                printf("Item:       %s\n", store[i].name);
                printf("Qty:        %d\n", orderQty);
                printf("Unit Price: $%.2f\n", store[i].price);
                printf("-----------------------------\n");
                printf("Total Due:  $%.2f\n", totalBill);
                printf("=============================\n");
                printf("Transaction complete!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Item with ID %d is not available in stock.\n", targetId);
    }
}