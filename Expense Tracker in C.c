#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char category[30];
    float amount;
};

void addExpense(struct Expense *expenses, int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached.\n");
        return;
    }
    printf("Enter expense category: ");
    scanf("%s", expenses[*count].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
}

void displayExpenses(struct Expense *expenses, int count) {
    printf("\nExpense Report:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}