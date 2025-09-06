/*
 * length_alt.c — String length utility with optional sub-length.
 * I/O contract (kept EXACT):
 *   - "Enter a string:"
 *   - "Get the full length of the string? (y/n):"
 *   - If answer != 'y': "Enter a character to get the length up to it:"
 *   - Debug echo: "getfull = %c\n"
 *   - Final: "The length of the string is: %d\n"
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50

// Compute length either full ('y') or up to first occurrence of subChar.
// If subChar isn't found, returns full length (original semantics).
static int strlength_alt(const char* s, char subChar, char getFull) {
    char terminator = (getFull == 'y') ? '\0' : subChar;

    int i = 0;
    for (int j = 0; j < MAX_STRING_LENGTH; ++j) {
        if (s[i] == terminator || s[i] == '\0') {
            break;
        }
        ++i;
    }
    return i;
}

int main(void) {
    char buf[MAX_STRING_LENGTH];
    char askFull;
    char cutoff = '\0';

    printf("Enter a string:");
    scanf("%49s", buf);

    printf("Get the full length of the string? (y/n):");
    scanf(" %c", &askFull);

    // Debug line present in the original; keep it
    printf("getfull = %c\n", askFull);

    if (askFull != 'y') {
        printf("Enter a character to get the length up to it:");
        scanf(" %c", &cutoff);
    }

    int len = strlength_alt(buf, cutoff, askFull);
    printf("The length of the string is: %d\n", len);

    return 0;
}
