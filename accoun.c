#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void displayMenu(void);
void createAccount(void);
void deleteAccount(void);
void viewBalance(double balance);
void deposit(double *balance);
void withdraw(double *balance);
void clearInputBuffer(void);

int main(void) {
    int choice;
    double balance = 0.0;
    bool running = true;

    while (running) {
        displayMenu();
        
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        
        switch (choice) {
            case 1:
                createAccount();
                balance = 0.0; // Reset balance for new account
                break;
            case 2:
                deleteAccount();
                balance = 0.0; // Reset balance after deletion
                break;
            case 3:
                viewBalance(balance);
                break;
            case 4:
                deposit(&balance);
                break;
            case 5:
                withdraw(&balance);
                break;
            case 6:
                printf("Thank you for using our banking system. Goodbye!\n");
                running = false;
                break;
            default:
                printf("Error: Invalid choice. Please enter a number between 1 and 6.\n");
                break;
        }
        printf("\n"); // Add spacing between menu iterations
    }
    
    return 0;
}

void displayMenu(void) {
    printf("\n=================================\n");
    printf("        BANKING SYSTEM MENU       \n");
    printf("=================================\n");
    printf("  1. Create account\n");
    printf("  2. Delete account\n");
    printf("  3. View balance\n");
    printf("  4. Deposit\n");
    printf("  5. Withdraw\n");
    printf("  6. Exit\n");
    printf("=================================\n");
}

void createAccount(void) {
    printf("✓ Creating new account...\n");
    printf("  Account created successfully!\n");
}

void deleteAccount(void) {
    char confirm;
    printf("⚠ WARNING: This will permanently delete your account.\n");
    printf("Are you sure? (y/n): ");
    scanf(" %c", &confirm);
    
    if (confirm == 'y' || confirm == 'Y') {
        printf("✓ Account deleted successfully!\n");
    } else {
        printf("  Account deletion cancelled.\n");
    }
    clearInputBuffer();
}

void viewBalance(double balance) {
    printf("💰 Current balance: $%.2f\n", balance);
}

void deposit(double *balance) {
    double amount;
    
    printf("Enter deposit amount: $");
    if (scanf("%lf", &amount) != 1) {
        printf("Error: Invalid amount entered.\n");
        clearInputBuffer();
        return;
    }
    
    if (amount <= 0) {
        printf("Error: Deposit amount must be positive.\n");
    } else {
        *balance += amount;
        printf("✓ Successfully deposited $%.2f\n", amount);
        printf("  New balance: $%.2f\n", *balance);
    }
    clearInputBuffer();
}

void withdraw(double *balance) {
    double amount;
    
    printf("Enter withdrawal amount: $");
    if (scanf("%lf", &amount) != 1) {
        printf("Error: Invalid amount entered.\n");
        clearInputBuffer();
        return;
    }
    
    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive.\n");
    } else if (amount > *balance) {
        printf("Error: Insufficient funds. Current balance: $%.2f\n", *balance);
    } else {
        *balance -= amount;
        printf("✓ Successfully withdrew $%.2f\n", amount);
        printf("  Remaining balance: $%.2f\n", *balance);
    }
    clearInputBuffer();
}

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}