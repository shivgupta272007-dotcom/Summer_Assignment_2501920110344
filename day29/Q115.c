#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 100

void get_string_length() {
    char str[MAX_LIMIT];
    int length = 0;

    printf("\n--- String Length ---\n");
    printf("Enter a string: ");
    scanf(" %[^\n]s", str);

    while (str[length] != '\0') {
        length++;
    }

    printf("✅ The length of the string is: %d\n", length);
}

void copy_string() {
    char source[MAX_LIMIT];
    char destination[MAX_LIMIT];
    int i = 0;

    printf("\n--- String Copy ---\n");
    printf("Enter source string: ");
    scanf(" %[^\n]s", source);

    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; 

    printf("✅ Original (Source):      %s\n", source);
    printf("✅ Duplicated (Destination): %s\n", destination);
}

void concatenate_strings() {
    char str1[MAX_LIMIT * 2]; 
    char str2[MAX_LIMIT];
    int i = 0, j = 0;

    printf("\n--- String Concatenation ---\n");
    printf("Enter first string: ");
    scanf(" %[^\n]s", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]s", str2);

    while (str1[i] != '\0') {
        i++;
    }

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0'; 

    printf("✅ Merged String: %s\n", str1);
}

void compare_strings() {
    char str1[MAX_LIMIT];
    char str2[MAX_LIMIT];

    printf("\n--- String Comparison ---\n");
    printf("Enter first string: ");
    scanf(" %[^\n]s", str1);
    printf("Enter second string: ");
    scanf(" %[^\n]s", str2);

    int result = strcasecmp(str1, str2);

    if (result == 0) {
        printf("✅ Both strings are perfectly equal (case-insensitive).\n");
    } else if (result > 0) {
        printf("ℹ️ The first string is lexicographically greater than the second.\n");
    } else {
        printf("ℹ️ The second string is lexicographically greater than the first.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("     STRING OPERATIONS SYSTEM    \n");
        printf("=================================\n");
        printf("1. Find String Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Compare Two Strings\n");
        printf("5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            get_string_length();
        } else if (choice == 2) {
            copy_string();
        } else if (choice == 3) {
            concatenate_strings();
        } else if (choice == 4) {
            compare_strings();
        } else if (choice == 5) {
            printf("\nExiting String System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-5.\n");
        }
    }

    return 0;
}