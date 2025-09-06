/*
 * mt2q2_alt.c — Split a phrase into equal-sized parts.
 * Behavior:
 *   - I/O strings and main() contract are kept EXACT (do not modify main).
 *   - Assumes phrase length is an exact multiple of n_parts.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 30

// Optional helper (not required by main, but useful if needed)
static int ascii_len(const char *s){
    int k = 0;
    while (s[k] != '\0') ++k;
    return k;
}

// Cut phrase into n_parts equal slices and store into parts[][MAX_LEN]
void cut(char* phrase, int n_parts, char  parts[][MAX_LEN]) {
    int phrase_len = (int)strlen(phrase);              // exact total length
    int part_len   = phrase_len / n_parts;             // guaranteed integral
    for (int i = 0; i < n_parts; ++i) {
        const char *src = phrase + i * part_len;
        // Copy exactly part_len chars; ensure NUL termination
        strncpy(parts[i], src, (size_t)part_len);
        parts[i][part_len] = '\0';
    }
}

// WARNING: Do not modify the below part!
int main() {
    char phrase[MAX_LEN];
    char parts[MAX_LEN][MAX_LEN];
    int n_parts;

    printf("Enter phrase: ");
    scanf("%s", phrase);

    printf("Enter number of parts: ");
    scanf("%d", &n_parts);

    cut(phrase, n_parts, parts);
    for (int i = 0; i < n_parts; i++) {
        printf("|%s|\n", parts[i]);
    }

    return 0;
}
