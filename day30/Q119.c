#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define DEPT_LENGTH 30

struct Employee {
    int empId;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    float salary;
};

void addEmployee(struct Employee staff[], int *count);
void displayEmployees(struct Employee staff[], int count);
void searchEmployee(struct Employee staff[], int count);

int main() {
    struct Employee staff[MAX_EMPLOYEES];
    int empCount = 0;
    int choice;

    while (1) {
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Employee Record\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(staff, &empCount);
                break;
            case 2:
                displayEmployees(staff, empCount);
                break;
            case 3:
                searchEmployee(staff, empCount);
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

void addEmployee(struct Employee staff[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Database full! Cannot add more records.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &staff[*count].empId);
    
    getchar(); 

    printf("Enter Employee Name: ");
    fgets(staff[*count].name, NAME_LENGTH, stdin);
    staff[*count].name[strcspn(staff[*count].name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(staff[*count].department, DEPT_LENGTH, stdin);
    staff[*count].department[strcspn(staff[*count].department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &staff[*count].salary);

    (*count)++;
    printf("Employee record added successfully!\n");
}

void displayEmployees(struct Employee staff[], int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("%-10s %-25s %-18s %-10s\n", "Emp ID", "Name", "Department", "Salary");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-18s %-10.2f\n", staff[i].empId, staff[i].name, staff[i].department, staff[i].salary);
    }
    printf("-----------------------------------------------------------------\n");
}

void searchEmployee(struct Employee staff[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int targetId;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &targetId);

    for (int i = 0; i < count; i++) {
        if (staff[i].empId == targetId) {
            printf("\nRecord Found!\n");
            printf("ID        : %d\n", staff[i].empId);
            printf("Name      : %s\n", staff[i].name);
            printf("Department: %s\n", staff[i].department);
            printf("Salary    : $%.2f\n", staff[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", targetId);
    }
}