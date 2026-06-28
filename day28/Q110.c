#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct BankAccount {
    char acc_no[20];
    char name[50];
    float balance;
};

struct BankSystem {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int count;
};

void create_account(struct BankSystem *bank) {
    printf("\n--- Create New Bank Account ---\n");
    if (bank->count >= MAX_ACCOUNTS) {
        printf("❌ Error: Bank database capacity is full!\n");
        return;
    }

    char acc_no[20];
    printf("Enter Unique Account Number: ");
    scanf(" %s", acc_no);

    for (int i = 0; i < bank->count; i++) {
        if (strcmp(bank->accounts[i].acc_no, acc_no) == 0) {
            printf("❌ Error: An account with this number already exists!\n");
            return;
        }
    }

    strcpy(bank->accounts[bank->count].acc_no, acc_no);
    
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]s", bank->accounts[bank->count].name);
    
    printf("Enter Initial Deposit Amount: $");
    scanf(" %f", &bank->accounts[bank->count].balance);

    if (bank->accounts[bank->count].balance < 0) {
        printf("❌ Error: Initial deposit cannot be negative!\n");
        return;
    }

    bank->count++;
    printf("✅ Account created successfully!\n");
}

void deposit_money(struct BankSystem *bank) {
    printf("\n--- Deposit Money ---\n");
    char acc_no[20];
    float amount;
    printf("Enter Account Number: ");
    scanf(" %s", acc_no);

    for (int i = 0; i < bank->count; i++) {
        if (strcmp(bank->accounts[i].acc_no, acc_no) == 0) {
            printf("Enter Amount to Deposit: $");
            scanf(" %f", &amount);
            
            if (amount <= 0) {
                printf("❌ Error: Deposit amount must be greater than zero!\n");
            } else {
                bank->accounts[i].balance += amount;
                printf("✅ Success! $%.2f deposited. New Balance: $%.2f\n", amount, bank->accounts[i].balance);
            }
            return;
        }
    }
    printf("❌ Account number not found.\n");
}

void withdraw_money(struct BankSystem *bank) {
    printf("\n--- Withdraw Money ---\n");
    char acc_no[20];
    float amount;
    printf("Enter Account Number: ");
    scanf(" %s", acc_no);

    for (int i = 0; i < bank->count; i++) {
        if (strcmp(bank->accounts[i].acc_no, acc_no) == 0) {
            printf("Enter Amount to Withdraw: $");
            scanf(" %f", &amount);
            
            if (amount <= 0) {
                printf("❌ Error: Withdrawal amount must be greater than zero!\n");
            } else if (amount > bank->accounts[i].balance) {
                printf("❌ Error: Insufficient funds! Current Balance: $%.2f\n", bank->accounts[i].balance);
            } else {
                bank->accounts[i].balance -= amount;
                printf("✅ Success! $%.2f withdrawn. New Balance: $%.2f\n", amount, bank->accounts[i].balance);
            }
            return;
        }
    }
    printf("❌ Account number not found.\n");
}

void check_balance(struct BankSystem *bank) {
    printf("\n--- Check Account Balance ---\n");
    char acc_no[20];
    printf("Enter Account Number: ");
    scanf(" %s", acc_no);

    for (int i = 0; i < bank->count; i++) {
        if (strcmp(bank->accounts[i].acc_no, acc_no) == 0) {
            printf("\n=====================================\n");
            printf("           ACCOUNT DETAILS           \n");
            printf("=====================================\n");
            printf("Account No: %s\n", bank->accounts[i].acc_no);
            printf("Holder Name: %s\n", bank->accounts[i].name);
            printf("Current Balance: $%.2f\n", bank->accounts[i].balance);
            printf("=====================================\n");
            return;
        }
    }
    printf("❌ Account number not found.\n");
}

void display_all_accounts(struct BankSystem *bank) {
    printf("\n--- Master Account Ledger ---\n");
    if (bank->count == 0) {
        printf("No registered bank accounts found.\n");
        return;
    }

    printf("%-15s %-25s %-15s\n", "Account No", "Account Holder", "Balance");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < bank->count; i++) {
        printf("%-15s %-25s $%-14.2f\n", 
               bank->accounts[i].acc_no, 
               bank->accounts[i].name, 
               bank->accounts[i].balance);
    }
}

int main() {
    struct BankSystem bank;
    bank.count = 0;
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("     BANK MANAGEMENT SYSTEM      \n");
        printf("=================================\n");
        printf("1. Open New Bank Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. Check Balance / Details\n");
        printf("5. Display Master Account Ledger\n");
        printf("6. Exit\n");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            create_account(&bank);
        } else if (choice == 2) {
            deposit_money(&bank);
        } else if (choice == 3) {
            withdraw_money(&bank);
        } else if (choice == 4) {
            check_balance(&bank);
        } else if (choice == 5) {
            display_all_accounts(&bank);
        } else if (choice == 6) {
            printf("\nExiting Banking System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}