#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char roll_no[20];
    char name[50];
    int age;
    char grade[10];
};

struct StudentManagementSystem {
    struct Student students[MAX_STUDENTS];
    int count;
};

void add_student(struct StudentManagementSystem *sms) {
    printf("\n--- Add New Student ---\n");
    if (sms->count >= MAX_STUDENTS) {
        printf("❌ Error: System storage is full!\n");
        return;
    }

    char roll_no[20];
    printf("Enter Roll Number: ");
    scanf(" %s", roll_no); 

    for (int i = 0; i < sms->count; i++) {
        if (strcmp(sms->students[i].roll_no, roll_no) == 0) {
            printf("❌ Error: Student with this Roll Number already exists!\n");
            return;
        }
    }

    strcpy(sms->students[sms->count].roll_no, roll_no);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", sms->students[sms->count].name); 
    
    printf("Enter Age: ");
    scanf(" %d", &sms->students[sms->count].age);
    
    printf("Enter Grade/Class: ");
    scanf(" %s", sms->students[sms->count].grade);

    sms->count++;
    printf("✅ Student added successfully!\n");
}

void view_all_students(struct StudentManagementSystem *sms) {
    printf("\n--- All Student Records ---\n");
    if (sms->count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("%-15s %-20s %-10s %-10s\n", "Roll No", "Name", "Age", "Grade");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < sms->count; i++) {
        printf("%-15s %-20s %-10d %-10s\n", 
               sms->students[i].roll_no, 
               sms->students[i].name, 
               sms->students[i].age, 
               sms->students[i].grade);
    }
}

void search_student(struct StudentManagementSystem *sms) {
    printf("\n--- Search Student ---\n");
    char roll_no[20];
    printf("Enter Roll Number to search: ");
    scanf(" %s", roll_no);

    for (int i = 0; i < sms->count; i++) {
        if (strcmp(sms->students[i].roll_no, roll_no) == 0) {
            printf("\nStudent Found:\n");
            printf("%-15s %-20s %-10s %-10s\n", "Roll No", "Name", "Age", "Grade");
            printf("------------------------------------------------------------\n");
            printf("%-15s %-20s %-10d %-10s\n", 
                   sms->students[i].roll_no, 
                   sms->students[i].name, 
                   sms->students[i].age, 
                   sms->students[i].grade);
            return;
        }
    }
    printf("❌ Student not found.\n");
}

void delete_student(struct StudentManagementSystem *sms) {
    printf("\n--- Delete Student ---\n");
    char roll_no[20];
    printf("Enter Roll Number to delete: ");
    scanf(" %s", roll_no);

    for (int i = 0; i < sms->count; i++) {
        if (strcmp(sms->students[i].roll_no, roll_no) == 0) {
            for (int j = i; j < sms->count - 1; j++) {
                sms->students[j] = sms->students[j + 1];
            }
            sms->count--;
            printf("🗑️ Student record deleted successfully.\n");
            return;
        }
    }
    printf("❌ Student not found.\n");
}

int main() {
    struct StudentManagementSystem sms;
    sms.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf(" STUDENT RECORD MANAGEMENT SYSTEM \n");
        printf("=================================\n");
        printf("1. Add Student Record\n");
        printf("2. View All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_student(&sms);
        } else if (choice == 2) {
            view_all_students(&sms);
        } else if (choice == 3) {
            search_student(&sms);
        } else if (choice == 4) {
            delete_student(&sms);
        } else if (choice == 5) {
            printf("\nExiting system. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}