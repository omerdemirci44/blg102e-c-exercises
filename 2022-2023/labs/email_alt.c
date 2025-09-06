/*
 * email_alt.c — Build username from name+surname with identical I/O.
 * Behavior:
 *   - Prompts must be EXACT:
 *       "Enter Your Name:"
 *       "Enter Your Surname:"
 *   - Output: first letter of name concatenated with full surname, then '\n'.
 *     (Same as original behavior.)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char given[50] = {0};
    char family[50] = {0};

    // Exact prompts preserved
    printf("Enter Your Name:");
    if (scanf("%49s", given) != 1) return EXIT_SUCCESS;

    printf("Enter Your Surname:");
    if (scanf("%49s", family) != 1) return EXIT_SUCCESS;

    // Construct: initial of name + full surname
    char out[120] = {0};
    if (given[0] != '\0') {
        out[0] = given[0];
    }
    // Append surname starting at index (out[0] may contain initial)
    int k = (out[0] != '\0') ? 1 : 0;
    for (int i = 0; family[i] != '\0'; ++i, ++k) {
        out[k] = family[i];
    }
    out[k] = '\0';

    // Print only the combined username then newline, exactly one line
    printf("%s\n", out);
    return EXIT_SUCCESS;
}
