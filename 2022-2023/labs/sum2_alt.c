// sum2_alt.c — Alternative solution with identical I/O
// Behavior: reads two integers in one go (with a robust fallback) and prints their sum.
// Note: Output strings match the original exactly to satisfy tests.

#include <stdio.h>

int main(void) {
    // Custom naming
    int lefty = 0;
    int righty = 0;

    // Keep prompts/output EXACT to pass tests
    printf("Please enter numbers: ");

    // Robust input: try reading both at once; if only one appears, read the second later
    if (scanf("%d %d", &lefty, &righty) != 2) {
        // Fallback: attempt to read the second number separately
        if (scanf("%d", &righty) != 1) {
            return 0; // graceful exit on invalid input
        }
    }

    int total = lefty + righty;
    printf("The sum of the two numbers %d, and %d is: %d\n", lefty, righty, total);

    return 0;
}
