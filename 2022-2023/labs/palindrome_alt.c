/*
 * palindrome_alt.c — Check whether an integer is a palindrome.
 * Notes:
 *   - Prompts and output strings are preserved EXACTLY.
 *   - Variable/function names are customized; comments are in English.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Reverse digits of a non-negative integer
static int reverse_digits(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

// Palindrome check (non-negative). Negative values are treated as non-palindrome.
static bool is_pal_num(int x) {
    if (x < 0) return false;
    // Numbers 0..9 are palindromes
    if (x < 10) return true;
    return x == reverse_digits(x);
}

int main(void) {
    int token = 0;

    // First prompt — must be exact
    printf("Enter a number or (-1) to quit: ");
    scanf("%d", &token);

    while (token != -1) {
        if (is_pal_num(token)) {
            printf("This number is a palindrome.\n");
        } else {
            printf("This number is not a palindrome.\n");
        }

        // Re-prompt — exact text
        printf("Enter a number or (-1) to quit: ");
        scanf("%d", &token);
    }

    return EXIT_SUCCESS;
}
