#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

struct Student {
    int rollNumber;
    char name[NAME_LENGTH];
    float marks;
};

void addStudent(struct Student records[], int *count);
void displayStudents(struct Student records[], int count);
void searchStudent(struct Student records[], int count);

int main() {
    struct Student records[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(records, &studentCount);
                break;
            case 2:
                displayStudents(records, studentCount);
                break;
            case 3:
                searchStudent(records, studentCount);
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

void addStudent(struct Student records[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &records[*count].rollNumber);
    
    getchar(); 
    
    printf("Enter Student Name: ");
    fgets(records[*count].name, NAME_LENGTH, stdin);
    records[*count].name[strcspn(records[*count].name, "\n")] = '\0';

    printf("Enter Total Marks: ");
    scanf("%f", &records[*count].marks);

    (*count)++;
    printf("Record added successfully!\n");
}

void displayStudents(struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo records found. Please add students first.\n");
        return;
    }

    printf("\n---------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n", records[i].rollNumber, records[i].name, records[i].marks);
    }
    printf("---------------------------------------------\n");
}

void searchStudent(struct Student records[], int count) {
    if (count == 0) {
        printf("\nNo records to search through.\n");
        return;
    }

    int targetRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if (records[i].rollNumber == targetRoll) {
            printf("\nRecord Found!\n");
            printf("Roll Number: %d\n", records[i].rollNumber);
            printf("Name       : %s\n", records[i].name);
            printf("Marks      : %.2f\n", records[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}