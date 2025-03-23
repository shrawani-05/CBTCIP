#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Expense {
    char category[50];
    float amount;
};

struct Expense expenses[MAX];
int expenseCount = 0;

void addExpense() {
    if (expenseCount >= MAX) {
        printf("Expense list is full!\n");
        return;
    }

    printf("Enter category of expense: ");
    scanf("%s", expenses[expenseCount].category);

    printf("Enter amount: ");
    scanf("%f", &expenses[expenseCount].amount);

    expenseCount++;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    printf("\nExpenses List:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. Category: %s, Amount: %.2f\n", i + 1, expenses[i].category, expenses[i].amount);
    }
}

void generateReport() {
    float total = 0;

    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal Expenses: %.2f\n", total);
}

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Generate Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}