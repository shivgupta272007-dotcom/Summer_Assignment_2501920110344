#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

struct Book {
    int bookId;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    float price;
};

void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void searchBook(struct Book library[], int count);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\n=== MINI LIBRARY SYSTEM ===\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchBook(library, bookCount);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &library[*count].bookId);
    
    getchar(); 

    printf("Enter Book Title: ");
    fgets(library[*count].title, TITLE_LENGTH, stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(library[*count].author, AUTHOR_LENGTH, stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = '\0';

    printf("Enter Book Price: ");
    scanf("%f", &library[*count].price);

    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("%-10s %-35s %-25s %-10s\n", "Book ID", "Title", "Author", "Price");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-35s %-25s %-10.2f\n", library[i].bookId, library[i].title, library[i].author, library[i].price);
    }
    printf("---------------------------------------------------------------------------------\n");
}

void searchBook(struct Book library[], int count) {
    if (count == 0) {
        printf("\nNo books in the library to search.\n");
        return;
    }

    int targetId;
    int found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &targetId);

    for (int i = 0; i < count; i++) {
        if (library[i].bookId == targetId) {
            printf("\nBook Found!\n");
            printf("ID    : %d\n", library[i].bookId);
            printf("Title : %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Price : $%.2f\n", library[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", targetId);
    }
}