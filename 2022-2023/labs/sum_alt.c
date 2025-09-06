// sum_alt.c — Alternative solution with identical I/O
// Behavior: reads two integers separately and prints their sum.
// Note: Output strings match the original exactly to satisfy tests.

#include <stdio.h>

// Tiny helper to emphasize "alternative structure"
static int add_two_fast(int lhs, int rhs) {
    // Simple pure function
    return lhs + rhs;
}

int main(void) {
    // Custom naming
    int alpha = 0;
    int beta  = 0;
    int combo = 0;

    // Keep prompts/output EXACT to pass tests
    printf("Please enter the first number: ");
    if (scanf("%d", &alpha) != 1) return 0;

    printf("Please enter the second number: ");
    if (scanf("%d", &beta) != 1) return 0;

    combo = add_two_fast(alpha, beta);
    printf("The sum of the two numbers %d, and %d is: %d\n", alpha, beta, combo);

    return 0;
}
