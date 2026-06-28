#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct ContactManagementSystem {
    struct Contact contacts[MAX_CONTACTS];
    int count;
};

void add_contact(struct ContactManagementSystem *cms) {
    printf("\n--- Add New Contact ---\n");
    if (cms->count >= MAX_CONTACTS) {
        printf("❌ Error: Address book is full!\n");
        return;
    }

    char name[50];
    printf("Enter Contact Name: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < cms->count; i++) {
        if (strcasecmp(cms->contacts[i].name, name) == 0) {
            printf("❌ Error: A contact with this name already exists!\n");
            return;
        }
    }

    strcpy(cms->contacts[cms->count].name, name);
    
    printf("Enter Phone Number: ");
    scanf(" %s", cms->contacts[cms->count].phone);
    
    printf("Enter Email Address: ");
    scanf(" %s", cms->contacts[cms->count].email);

    cms->count++;
    printf("✅ Contact saved successfully!\n");
}

void view_all_contacts(struct ContactManagementSystem *cms) {
    printf("\n--- Contact List ---\n");
    if (cms->count == 0) {
        printf("Your address book is empty.\n");
        return;
    }

    printf("%-25s %-20s %-30s\n", "Name", "Phone Number", "Email Address");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < cms->count; i++) {
        printf("%-25s %-20s %-30s\n", 
               cms->contacts[i].name, 
               cms->contacts[i].phone, 
               cms->contacts[i].email);
    }
}

void search_contact(struct ContactManagementSystem *cms) {
    printf("\n--- Search Contact ---\n");
    char name[50];
    printf("Enter Name to search: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < cms->count; i++) {
        if (strcasecmp(cms->contacts[i].name, name) == 0) {
            printf("\nContact Found:\n");
            printf("-------------------------------------\n");
            printf("Name:  %s\n", cms->contacts[i].name);
            printf("Phone: %s\n", cms->contacts[i].phone);
            printf("Email: %s\n", cms->contacts[i].email);
            printf("-------------------------------------\n");
            return;
        }
    }
    printf("❌ Contact not found.\n");
}

void delete_contact(struct ContactManagementSystem *cms) {
    printf("\n--- Delete Contact ---\n");
    char name[50];
    printf("Enter Name to delete: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < cms->count; i++) {
        if (strcasecmp(cms->contacts[i].name, name) == 0) {
            for (int j = i; j < cms->count - 1; j++) {
                cms->contacts[j] = cms->contacts[j + 1];
            }
            cms->count--;
            printf("🗑️ Contact deleted successfully.\n");
            return;
        }
    }
    printf("❌ Contact not found.\n");
}

int main() {
    struct ContactManagementSystem cms;
    cms.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("    CONTACT MANAGEMENT SYSTEM    \n");
        printf("=================================\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_contact(&cms);
        } else if (choice == 2) {
            view_all_contacts(&cms);
        } else if (choice == 3) {
            search_contact(&cms);
        } else if (choice == 4) {
            delete_contact(&cms);
        } else if (choice == 5) {
            printf("\nExiting Contact System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-5.\n");
        }
    }

    return 0;
}