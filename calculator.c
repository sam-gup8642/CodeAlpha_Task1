#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the calculator menu options to the console.
 */
void print_menu() {
    printf("====================================\n");
    printf("      BASIC ARITHMETIC CALCULATOR   \n");
    printf("====================================\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
    printf("====================================\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a number between 1 and 5.\n\n");
            // Clear standard input buffer to prevent infinite loop on invalid inputs
            while (getchar() != '\n');
            continue;
        }

        if (choice == 5) {
            printf("\nExiting the calculator program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("\n[Error] Invalid choice. Please select a valid option (1-5).\n\n");
            continue;
        }

        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("\n[Error] Invalid numeric input.\n\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter second number: ");
        if (scanf("%lf", &num2) != 1) {
            printf("\n[Error] Invalid numeric input.\n\n");
            while (getchar() != '\n');
            continue;
        }

        // Perform the chosen operation using switch-case selection
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\n>>> Result: %.4f + %.4f = %.4f <<<\n\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("\n>>> Result: %.4f - %.4f = %.4f <<<\n\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("\n>>> Result: %.4f * %.4f = %.4f <<<\n\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0.0) {
                    printf("\n[Error] Division by zero is mathematically undefined.\n\n");
                } else {
                    result = num1 / num2;
                    printf("\n>>> Result: %.4f / %.4f = %.4f <<<\n\n", num1, num2, result);
                }
                break;
            default:
                printf("\n[Error] An unexpected error occurred.\n\n");
                break;
        }
    }

    return 0;
}
