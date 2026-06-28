#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char book_id[20];
    char title[50];
    char author[50];
    int is_issued; 
};

struct LibrarySystem {
    struct Book books[MAX_BOOKS];
    int count;
};

void add_book(struct LibrarySystem *libs) {
    printf("\n--- Add New Book ---\n");
    if (libs->count >= MAX_BOOKS) {
        printf("❌ Error: Library storage capacity is full!\n");
        return;
    }

    char book_id[20];
    printf("Enter Book ID: ");
    scanf(" %s", book_id);

    for (int i = 0; i < libs->count; i++) {
        if (strcmp(libs->books[i].book_id, book_id) == 0) {
            printf("❌ Error: A book with this ID already exists!\n");
            return;
        }
    }

    strcpy(libs->books[libs->count].book_id, book_id);
    
    printf("Enter Book Title: ");
    scanf(" %[^\n]s", libs->books[libs->count].title);
    
    printf("Enter Author Name: ");
    scanf(" %[^\n]s", libs->books[libs->count].author);
    
    libs->books[libs->count].is_issued = 0; 

    libs->count++;
    printf("✅ Book cataloged successfully!\n");
}

void view_books(struct LibrarySystem *libs) {
    printf("\n--- Library Book Catalog ---\n");
    if (libs->count == 0) {
        printf("No books found in the library database.\n");
        return;
    }

    printf("%-12s %-25s %-20s %-12s\n", "Book ID", "Title", "Author", "Status");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < libs->count; i++) {
        printf("%-12s %-25s %-20s %-12s\n", 
               libs->books[i].book_id, 
               libs->books[i].title, 
               libs->books[i].author, 
               libs->books[i].is_issued ? "Issued 📖" : "Available 🟢");
    }
}

void search_book(struct LibrarySystem *libs) {
    printf("\n--- Search Book Catalog ---\n");
    char book_id[20];
    printf("Enter Book ID to search: ");
    scanf(" %s", book_id);

    for (int i = 0; i < libs->count; i++) {
        if (strcmp(libs->books[i].book_id, book_id) == 0) {
            printf("\nBook Found:\n");
            printf("%-12s %-25s %-20s %-12s\n", "Book ID", "Title", "Author", "Status");
            printf("----------------------------------------------------------------------------\n");
            printf("%-12s %-25s %-20s %-12s\n", 
                   libs->books[i].book_id, 
                   libs->books[i].title, 
                   libs->books[i].author, 
                   libs->books[i].is_issued ? "Issued 📖" : "Available 🟢");
            return;
        }
    }
    printf("❌ Book not found.\n");
}

void issue_book(struct LibrarySystem *libs) {
    printf("\n--- Issue Book ---\n");
    char book_id[20];
    printf("Enter Book ID to issue: ");
    scanf(" %s", book_id);

    for (int i = 0; i < libs->count; i++) {
        if (strcmp(libs->books[i].book_id, book_id) == 0) {
            if (libs->books[i].is_issued == 1) {
                printf("❌ Error: Book is already checked out!\n");
            } else {
                libs->books[i].is_issued = 1;
                printf("✅ Success: Book '%s' has been issued successfully!\n", libs->books[i].title);
            }
            return;
        }
    }
    printf("❌ Book ID not found.\n");
}

void return_book(struct LibrarySystem *libs) {
    printf("\n--- Return Book ---\n");
    char book_id[20];
    printf("Enter Book ID to return: ");
    scanf(" %s", book_id);

    for (int i = 0; i < libs->count; i++) {
        if (strcmp(libs->books[i].book_id, book_id) == 0) {
            if (libs->books[i].is_issued == 0) {
                printf("⚠️ Alert: This book was never issued, it's already in shelves.\n");
            } else {
                libs->books[i].is_issued = 0;
                printf("✅ Success: Book '%s' has been returned safely!\n", libs->books[i].title);
            }
            return;
        }
    }
    printf("❌ Book ID not found.\n");
}

int main() {
    struct LibrarySystem libs;
    libs.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("     LIBRARY MANAGEMENT SYSTEM   \n");
        printf("=================================\n");
        printf("1. Add New Book Record\n");
        printf("2. View All Cataloged Books\n");
        printf("3. Search for a Book by ID\n");
        printf("4. Issue / Check-out Book\n");
        printf("5. Return Checked-out Book\n");
        printf("6. Exit\n");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_book(&libs);
        } else if (choice == 2) {
            view_books(&libs);
        } else if (choice == 3) {
            search_book(&libs);
        } else if (choice == 4) {
            issue_book(&libs);
        } else if (choice == 5) {
            return_book(&libs);
        } else if (choice == 6) {
            printf("\nExiting Library System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}