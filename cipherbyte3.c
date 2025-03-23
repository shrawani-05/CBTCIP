#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char name[50];
    float balance;
    char accountType[10];  // "Savings" or "Current"
};

struct Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

void createAccount() {
    struct Account acc;
    acc.accountNumber = totalAccounts + 1;

    printf("Enter Name: ");
    scanf("%s", acc.name);

    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    printf("Enter Account Type (Savings/Current): ");
    scanf("%s", acc.accountType);

    accounts[totalAccounts++] = acc;
    printf("Account Created Successfully! Account Number: %d\n", acc.accountNumber);
}

void deposit(int accountNumber) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[accountNumber - 1].balance += amount;
    printf("Amount Deposited Successfully!\n");
}

void withdraw(int accountNumber) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient Balance!\n");
    } else {
        accounts[accountNumber - 1].balance -= amount;
        printf("Amount Withdrawn Successfully!\n");
    }
}

void checkBalance(int accountNumber) {
    printf("Current Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void calculateInterest(int accountNumber) {
    float rate;
    if (strcmp(accounts[accountNumber - 1].accountType, "Savings") == 0) {
        rate = 0.05;  // 5% for Savings
    } else {
        rate = 0.03;  // 3% for Current
    }

    float interest = accounts[accountNumber - 1].balance * rate;
    printf("Annual Interest: %.2f\n", interest);
}

int main() {
    int choice, accountNumber;

    while (1) {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                deposit(accountNumber);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                withdraw(accountNumber);
                break;
            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                checkBalance(accountNumber);
                break;
            case 5:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                calculateInterest(accountNumber);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
