#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct SalaryRecord {
    char emp_id[20];
    char name[50];
    float basic_salary;
    float hra;
    float da;
    float pf;
    float tax;
    float gross_salary;
    float net_salary;
};

struct SalaryManagementSystem {
    struct SalaryRecord records[MAX_EMPLOYEES];
    int count;
};

void calculate_salary(struct SalaryRecord *emp) {
    emp->hra = emp->basic_salary * 0.20;
    emp->da = emp->basic_salary * 0.10;
    emp->pf = emp->basic_salary * 0.12;
    
    emp->gross_salary = emp->basic_salary + emp->hra + emp->da;
    
    if (emp->gross_salary > 50000) {
        emp->tax = emp->gross_salary * 0.15;
    } else if (emp->gross_salary > 30000) {
        emp->tax = emp->gross_salary * 0.05;
    } else {
        emp->tax = 0;
    }
    
    emp->net_salary = emp->gross_salary - (emp->pf + emp->tax);
}

void add_salary_record(struct SalaryManagementSystem *sms) {
    printf("\n--- Add Salary Record ---\n");
    if (sms->count >= MAX_EMPLOYEES) {
        printf("❌ Error: System storage is full!\n");
        return;
    }

    char emp_id[20];
    printf("Enter Employee ID: ");
    scanf(" %s", emp_id);

    for (int i = 0; i < sms->count; i++) {
        if (strcmp(sms->records[i].emp_id, emp_id) == 0) {
            printf("❌ Error: Record for this Employee ID already exists!\n");
            return;
        }
    }

    strcpy(sms->records[sms->count].emp_id, emp_id);
    
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", sms->records[sms->count].name);
    
    printf("Enter Base/Basic Salary: $");
    scanf(" %f", &sms->records[sms->count].basic_salary);

    calculate_salary(&sms->records[sms->count]);

    sms->count++;
    printf("✅ Salary record calculated and added successfully!\n");
}

void view_payroll_ledger(struct SalaryManagementSystem *sms) {
    printf("\n--- Payroll Summary Ledger ---\n");
    if (sms->count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("%-12s %-20s %-12s %-12s %-12s\n", "Emp ID", "Name", "Basic", "Gross", "Net Payout");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < sms->count; i++) {
        printf("%-12s %-20s $%-11.2f $%-11.2f $%-11.2f\n", 
               sms->records[i].emp_id, 
               sms->records[i].name, 
               sms->records[i].basic_salary, 
               sms->records[i].gross_salary, 
               sms->records[i].net_salary);
    }
}

void generate_payslip(struct SalaryManagementSystem *sms) {
    printf("\n--- Generate Payslip ---\n");
    char emp_id[20];
    printf("Enter Employee ID: ");
    scanf(" %s", emp_id);

    for (int i = 0; i < sms->count; i++) {
        if (strcmp(sms->records[i].emp_id, emp_id) == 0) {
            struct SalaryRecord emp = sms->records[i];
            printf("\n=============================================\n");
            printf("              OFFICIAL PAYSLIP               \n");
            printf("=============================================\n");
            printf("ID: %-15s Name: %-20s\n", emp.emp_id, emp.name);
            printf("---------------------------------------------\n");
            printf("%-25s $%15.2f\n", "Basic Salary:", emp.basic_salary);
            printf("%-25s $%15.2f\n", "House Rent Allow. (HRA):", emp.hra);
            printf("%-25s $%15.2f\n", "Dearness Allow. (DA):", emp.da);
            printf("---------------------------------------------\n");
            printf("%-25s $%15.2f\n", "GROSS EARNINGS:", emp.gross_salary);
            printf("---------------------------------------------\n");
            printf("%-25s $%15.2f\n", "Provident Fund (PF):", emp.pf);
            printf("%-25s $%15.2f\n", "Income Tax Deduction:", emp.tax);
            printf("---------------------------------------------\n");
            printf("%-25s $%15.2f\n", "NET PAYOUT:", emp.net_salary);
            printf("=============================================\n");
            return;
        }
    }
    printf("❌ Employee ID not found.\n");
}

int main() {
    struct SalaryManagementSystem sms;
    sms.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("     SALARY MANAGEMENT SYSTEM    \n");
        printf("=================================\n");
        printf("1. Add Employee Salary Record\n");
        printf("2. View Payroll Ledger Summary\n");
        printf("3. Generate Individual Payslip\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_salary_record(&sms);
        } else if (choice == 2) {
            view_payroll_ledger(&sms);
        } else if (choice == 3) {
            generate_payslip(&sms);
        } else if (choice == 4) {
            printf("\nExiting Salary System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-4.\n");
        }
    }

    return 0;
}