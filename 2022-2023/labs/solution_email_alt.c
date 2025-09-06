/*
 * solution_email_alt.c — Mirror the exact I/O of the original solution_email.c.
 * Behavior:
 *   - Prompt EXACTLY: "Enter Your Name:"
 *   - Read a single token (no spaces) into a buffer.
 *   - No further output (to match original minimal behavior).
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50

int main(void) {
    char first[MAX_STRING_LENGTH];

    // Exact prompt preserved
    printf("Enter Your Name:");
    (void)scanf("%49s", first);

    // No additional output per original behavior
    return EXIT_SUCCESS;
}
