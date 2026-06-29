#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define LOW_STOCK_THRESHOLD 5

struct Item {
    char item_id[20];
    char name[50];
    int quantity;
    float price;
};

struct InventorySystem {
    struct Item items[MAX_ITEMS];
    int count;
};

void add_item(struct InventorySystem *inv) {
    printf("\n--- Add New Inventory Item ---\n");
    if (inv->count >= MAX_ITEMS) {
        printf("❌ Error: Inventory storage database is full!\n");
        return;
    }

    char item_id[20];
    printf("Enter Unique Item ID: ");
    scanf(" %s", item_id);

    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].item_id, item_id) == 0) {
            printf("❌ Error: An item with this ID already exists!\n");
            return;
        }
    }

    strcpy(inv->items[inv->count].item_id, item_id);
    
    printf("Enter Item Name: ");
    scanf(" %[^\n]s", inv->items[inv->count].name);
    
    printf("Enter Initial Quantity: ");
    scanf(" %d", &inv->items[inv->count].quantity);
    
    printf("Enter Unit Price: $");
    scanf(" %f", &inv->items[inv->count].price);

    inv->count++;
    printf("✅ Item added to inventory successfully!\n");
}

void view_inventory(struct InventorySystem *inv) {
    printf("\n--- Current Stock Ledger ---\n");
    if (inv->count == 0) {
        printf("The inventory is currently empty.\n");
        return;
    }

    printf("%-12s %-25s %-12s %-12s %-15s\n", "Item ID", "Item Name", "Quantity", "Price", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < inv->count; i++) {
        char status[20] = "🟢 In Stock";
        if (inv->items[i].quantity == 0) {
            strcpy(status, "🔴 Out of Stock");
        } else if (inv->items[i].quantity <= LOW_STOCK_THRESHOLD) {
            strcpy(status, "⚠️ Low Stock");
        }

        printf("%-12s %-25s %-12d $%-11.2f %-15s\n", 
               inv->items[i].item_id, 
               inv->items[i].name, 
               inv->items[i].quantity, 
               inv->items[i].price,
               status);
    }
}

void update_stock(struct InventorySystem *inv) {
    printf("\n--- Update Stock Quantity ---\n");
    char item_id[20];
    int choice, amt;
    
    printf("Enter Item ID: ");
    scanf(" %s", item_id);

    for (int i = 0; i < inv->count; i++) {
        if (strcmp(inv->items[i].item_id, item_id) == 0) {
            printf("Item Found: %s (Current Stock: %d)\n", inv->items[i].name, inv->items[i].quantity);
            printf("1. Restock (Add Items)\n");
            printf("2. Dispatch (Remove Items)\n");
            printf("Enter choice (1-2): ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Enter quantity to add: ");
                scanf("%d", &amt);
                if (amt > 0) {
                    inv->items[i].quantity += amt;
                    printf("✅ Stock updated! New quantity: %d\n", inv->items[i].quantity);
                } else {
                    printf("❌ Invalid quantity.\n");
                }
            } else if (choice == 2) {
                printf("Enter quantity to remove: ");
                scanf("%d", &amt);
                if (amt > 0 && amt <= inv->items[i].quantity) {
                    inv->items[i].quantity -= amt;
                    printf("🗑️ Stock dispatched! New quantity: %d\n", inv->items[i].quantity);
                } else {
                    printf("❌ Error: Invalid quantity or insufficient stock available!\n");
                }
            } else {
                printf("❌ Invalid selection.\n");
            }
            return;
        }
    }
    printf("❌ Item ID not found.\n");
}

void check_total_value(struct InventorySystem *inv) {
    float total_value = 0;
    printf("\n--- Inventory Financial Valuation ---\n");
    
    for (int i = 0; i < inv->count; i++) {
        total_value += (inv->items[i].quantity * inv->items[i].price);
    }

    printf("Total Unique Items Stocked: %d\n", inv->count);
    printf("💰 Gross Valuation of Asset Inventory: $%.2f\n", total_value);
}

int main() {
    struct InventorySystem inv;
    inv.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("    INVENTORY MANAGEMENT SYSTEM  \n");
        printf("=================================\n");
        printf("1. Add New Item to Stock\n");
        printf("2. View Current Stock Ledger\n");
        printf("3. Update Item Stock (Add/Remove)\n");
        printf("4. Check Total Asset Valuation\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_item(&inv);
        } else if (choice == 2) {
            view_inventory(&inv);
        } else if (choice == 3) {
            update_stock(&inv);
        } else if (choice == 4) {
            check_total_value(&inv);
        } else if (choice == 5) {
            printf("\nExiting Inventory System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-5.\n");
        }
    }

    return 0;
}