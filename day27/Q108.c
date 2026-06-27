#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Marksheet {
    char roll_no[20];
    char name[50];
    float math;
    float science;
    float english;
    float total;
    float percentage;
    char grade[5];
};

struct MarksheetSystem {
    struct Marksheet records[MAX_STUDENTS];
    int count;
};

void calculate_grades(struct Marksheet *student) {
    student->total = student->math + student->science + student->english;
    student->percentage = (student->total / 300.0) * 100.0;

    if (student->percentage >= 90.0) {
        strcpy(student->grade, "A+");
    } else if (student->percentage >= 80.0) {
        strcpy(student->grade, "A");
    } else if (student->percentage >= 70.0) {
        strcpy(student->grade, "B");
    } else if (student->percentage >= 60.0) {
        strcpy(student->grade, "C");
    } else if (student->percentage >= 50.0) {
        strcpy(student->grade, "D");
    } else {
        strcpy(student->grade, "F");
    }
}

void add_student_marks(struct MarksheetSystem *mss) {
    printf("\n--- Add Student Marks ---\n");
    if (mss->count >= MAX_STUDENTS) {
        printf("❌ Error: System storage is full!\n");
        return;
    }

    char roll_no[20];
    printf("Enter Roll Number: ");
    scanf(" %s", roll_no);

    for (int i = 0; i < mss->count; i++) {
        if (strcmp(mss->records[i].roll_no, roll_no) == 0) {
            printf("❌ Error: Marks already entered for this Roll Number!\n");
            return;
        }
    }

    strcpy(mss->records[mss->count].roll_no, roll_no);
    
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", mss->records[mss->count].name);
    
    printf("Enter Math Marks (out of 100): ");
    scanf(" %f", &mss->records[mss->count].math);
    
    printf("Enter Science Marks (out of 100): ");
    scanf(" %f", &mss->records[mss->count].science);
    
    printf("Enter English Marks (out of 100): ");
    scanf(" %f", &mss->records[mss->count].english);

    calculate_grades(&mss->records[mss->count]);

    mss->count++;
    printf("✅ Performance metrics compiled successfully!\n");
}

void view_class_ledger(struct MarksheetSystem *mss) {
    printf("\n--- Class Performance Ledger ---\n");
    if (mss->count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("%-12s %-20s %-8s %-8s %-8s %-8s %-6s\n", "Roll No", "Name", "Math", "Sci", "Eng", "Total", "Grade");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < mss->count; i++) {
        printf("%-12s %-20s %-8.1f %-8.1f %-8.1f %-8.1f %-6s\n", 
               mss->records[i].roll_no, 
               mss->records[i].name, 
               mss->records[i].math, 
               mss->records[i].science, 
               mss->records[i].english, 
               mss->records[i].total, 
               mss->records[i].grade);
    }
}

void generate_report_card(struct MarksheetSystem *mss) {
    printf("\n--- Generate Marksheet ---\n");
    char roll_no[20];
    printf("Enter Student Roll Number: ");
    scanf(" %s", roll_no);

    for (int i = 0; i < mss->count; i++) {
        if (strcmp(mss->records[i].roll_no, roll_no) == 0) {
            struct Marksheet s = mss->records[i];
            printf("\n==================================================\n");
            printf("            OFFICIAL SCHOLASTIC REPORT            \n");
            printf("==================================================\n");
            printf("Roll No: %-15s Name: %-20s\n", s.roll_no, s.name);
            printf("--------------------------------------------------\n");
            printf("%-25s %-12s %-12s\n", "Subject", "Max Marks", "Marks Obtained");
            printf("--------------------------------------------------\n");
            printf("%-25s %-12d %-12.1f\n", "Mathematics", 100, s.math);
            printf("%-25s %-12d %-12.1f\n", "Science", 100, s.science);
            printf("%-25s %-12d %-12.1f\n", "English", 100, s.english);
            printf("--------------------------------------------------\n");
            printf("%-25s %-12d %-12.1f\n", "AGGREGATE TOTAL:", 300, s.total);
            printf("%-25s %-12s %-12.2f%%\n", "PERCENTAGE SCORE:", "", s.percentage);
            printf("%-25s %-12s %-12s\n", "FINAL EVALUATION:", "", s.grade);
            printf("==================================================\n");
            return;
        }
    }
    printf("❌ Roll number not found.\n");
}

int main() {
    struct MarksheetSystem mss;
    mss.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("    MARKSHEET GENERATION SYSTEM  \n");
        printf("=================================\n");
        printf("1. Add Student Marks Data\n");
        printf("2. View Class Performance Ledger\n");
        printf("3. Generate Individual Marksheet\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            add_student_marks(&mss);
        } else if (choice == 2) {
            view_class_ledger(&mss);
        } else if (choice == 3) {
            generate_report_card(&mss);
        } else if (choice == 4) {
            printf("\nExiting Report System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-4.\n");
        }
    }

    return 0;
}