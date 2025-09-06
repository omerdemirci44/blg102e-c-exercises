// alt_m2q2.c — BLG102E M2 Q2: same I/O, different implementation (toggle-based alternation)
#include <stdio.h>

#define SIZE 10 // up to 10 integers

double alternating_function(int numbers[], int choice, int size)
{
    if (choice == 1) {
        // Alternating sum: + - + - ...
        double total = 0.0;
        int sign = 1;
        for (int i = 0; i < size; i++) {
            total += sign * (double)numbers[i];
            sign = -sign;
        }
        return total;
    } else if (choice == 2) {
        // Alternating division: a0 / a1 * a2 / a3 * ...
        if (size == 0) return 1.0;
        double result = (double)numbers[0];
        int divide_next = 1;
        for (int i = 1; i < size; i++) {
            if (divide_next) {
                result /= (double)numbers[i];
            } else {
                result *= (double)numbers[i];
            }
            divide_next = !divide_next;
        }
        return result;
    }
    return 1.0;
}

int main(void)
{
    int numbers[SIZE];
    int size = 0;

    printf("Enter up to 10 non-negative integers (-1 to terminate):");

    while (size < SIZE) {
        int x;
        if (scanf("%d", &x) != 1) break;
        if (x == -1) break;
        numbers[size++] = x;
    }

    int choice;
    printf("\nEnter your choice (1 for alternating sum or 2 for alternating division):");
    scanf("%d", &choice);
    double result = alternating_function(numbers, choice, size);
    printf("The result is %.2f\n", result);
    return 0;
}
