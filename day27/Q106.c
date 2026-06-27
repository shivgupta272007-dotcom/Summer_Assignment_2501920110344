#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char emp_id[20];
    char name[50];
    char department[30];
    float salary;
};

struct EmployeeManagementSystem {
    struct Employee employees[MAX_EMPLOYEES];
    int count;
};

void add_employee(struct EmployeeManagementSystem *ems) {
    printf("\n--- Add New Employee ---\n");
    if (ems->count >= MAX_EMPLOYEES) {
        printf("❌ Error: System storage is full!\n");
        return;
    }

    char emp_id[20];
    printf("Enter Employee ID: ");
    scanf(" %s", emp_id);

    for (int i = 0; i < ems->count; i++) {
        if (strcmp(ems->employees[i].emp_id, emp_id) == 0) {
            printf("❌ Error: Employee with this ID already exists!\n");
            return;
        }
    }

    strcpy(ems->employees[ems->count].emp_id, emp_id);
    
    printf("Enter Name: ");
    scanf(" %[^\n]s", ems->employees[ems->count].name);
    
    printf("Enter Department: ");
    scanf(" %[^\n]s", ems->employees[ems->count].department);
    
    printf("Enter Salary: ");
    scanf(" %f", &ems->employees[ems->count].salary);

    ems->count++;
    printf("✅ Employee added successfully!\n");
}

void view_all_employees(struct EmployeeManagementSystem *ems) {
    printf("\n--- All Employee Records ---\n");
    if (ems->count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("%-15s %-25s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < ems->count; i++) {
        printf("%-15s %-25s %-20s %-10.2f\n", 
               ems->employees[i].emp_id, 
               ems->employees[i].name, 
               ems->employees[i].department, 
               ems->employees[i].salary);
    }
}

void search_employee(struct EmployeeManagementSystem *ems) {
    printf("\n--- Search Employee ---\n");
    char emp_id[20];
    printf("Enter Employee ID to search: ");
    scanf(" %s", emp_id);

    for (int i = 0; i < ems->count; i++) {
        if (strcmp(ems->employees[i].emp_id, emp_id) == 0) {
            printf("\nEmployee Found:\n");
            printf("%-15s %-25s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
            printf("----------------------------------------------------------------------------\n");
            printf("%-15s %-25s %-20s %-10.2f\n", 
                   ems->employees[i].emp_id, 
                   ems->employees[i].name, 
                   ems->employees[i].department, 
                   ems->employees[i].salary);
            return;
        }
    }
    printf("❌ Employee not found.\n");
}

void delete_employee(struct EmployeeManagementSystem *ems) {
    printf("\n--- Delete Employee ---\n");
    char emp_id[20];
    printf("Enter Employee ID to delete: ");
    scanf(" %s", emp_id);

    for (int i = 0; i < ems->count; i++) {
        if (strcmp(ems->employees[i].emp_id, emp_id) == 0) {
            for (int j = i; j < ems->count - 1; j++) {
                ems->employees[j] = ems->employees[j + 1];
            }
            ems->count--;
            printf("🗑️ Employee record deleted successfully.\n");
            return;
        }
    }
    printf("❌ Employee not found.\n");
}

int main() {
    struct EmployeeManagementSystem ems;
    ems.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("   EMPLOYEE MANAGEMENT SYSTEM    \n");
        printf("=================================\n");
        printf("1. Add Employee Record\n");
        printf("2. View All Employee Records\n");
        printf("3. Search Employee Record\n");
        printf("4. Delete Employee Record\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_employee(&ems);
        } else if (choice == 2) {
            view_all_employees(&ems);
        } else if (choice == 3) {
            search_employee(&ems);
        } else if (choice == 4) {
            delete_employee(&ems);
        } else if (choice == 5) {
            printf("\nExiting system. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}