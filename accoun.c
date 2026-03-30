#include <stdio.h>

int main(void)
{
int choice;

printf("\n=== Main Menu ===\n");
printf("1. Create account\n");
printf("2. Delete account\n");
printf("3. View balance\n");
printf("4. Deposit\n");
printf("5. Withdraw\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
printf("Creating new account...\n");
break;
case 2:
printf("Deleting account...\n");
break;
case 3:
printf("Your balance is $1000\n");
break;
case 4:
printf("Enter deposit amount: ");
// ... deposit logic
break;
case 5:
printf("Enter withdrawal amount: ");
// ... withdrawal logic
break;
case 6:
printf("Goodbye!\n");
break;
default:
printf("Invalid choice. Please try again.\n");
break;
}

return 0;
}