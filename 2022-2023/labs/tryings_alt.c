/*
 * tryings_alt.c — Concatenate name+surname and print first two chars.
 * Behavior (must match original exactly):
 *   - Prompts:
 *       "give name: "
 *       "give surname: "
 *   - Outputs:
 *       Line 1: concatenated string (name followed by surname)
 *       Line 2: first two characters of the concatenated string
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char name[50] = {0};
    char surname[50] = {0};
    char combined[110] = {0};
    char first2[3] = {0};

    // Exact prompts (note the space after colon)
    printf("give name: ");
    if (scanf("%49s", name) != 1) return EXIT_SUCCESS;

    printf("give surname: ");
    if (scanf("%49s", surname) != 1) return EXIT_SUCCESS;

    // Build combined = name + surname
    int k = 0;
    for (int i = 0; name[i] != '\0'; ++i) combined[k++] = name[i];
    for (int i = 0; surname[i] != '\0'; ++i) combined[k++] = surname[i];
    combined[k] = '\0';

    // First two characters (if available)
    first2[0] = combined[0];
    if (combined[1] != '\0') first2[1] = combined[1];
    first2[2] = '\0';

    // Print EXACTLY two lines as original
    printf("%s\n", combined);
    printf("%s\n", first2);

    return EXIT_SUCCESS;
}
