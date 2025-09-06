// alt_m3q1.c
// Purpose: Read a line and a trim type, then print the trimmed result enclosed in pipes.
// I/O contract must match the tests exactly (prompts and spacing).
// Comments are in English.
//
// Trim types:
//   l: left trim (remove leading spaces only)
//   r: right trim (remove trailing spaces only)
//   b: both trim (remove leading and trailing spaces)
//
#include <stdio.h>
#include <string.h>

#define MAXLEN 50  // as in original settings

// Copy src starting from first non-space into dst
static void lstrip(const char *src, char *dst) {
    const char *p = src;
    // advance while there are leading spaces
    while (*p == ' ') p++;
    // copy remainder including the terminating null
    while (*p) *dst++ = *p++;
    *dst = '\0';
}

// Copy src up to last non-space into dst
static void rstrip(const char *src, char *dst) {
    size_t len = strlen(src);
    // find index of last non-space char
    while (len > 0 && src[len - 1] == ' ') len--;

    // copy [0 .. len-1] into dst
    for (size_t i = 0; i < len; i++) dst[i] = src[i];
    dst[len] = '\0';
}

// Remove both leading and trailing spaces
static void strip(const char *src, char *dst) {
    char tmp[MAXLEN + 1];
    lstrip(src, tmp);   // remove leading
    rstrip(tmp, dst);   // then remove trailing on the intermediate
}

int main(void) {
    char line[MAXLEN + 1];
    char type;

    // Exact prompt text (matches test expectations)
    printf("enter the string: ");
    if (!fgets(line, sizeof(line), stdin)) {
        return 0; // no input
    }
    // drop trailing newline if any (we only trim spaces by spec)
    size_t L = strlen(line);
    if (L > 0 && line[L - 1] == '\n') line[L - 1] = '\0';

    // Exact second prompt text (matches test expectations)
    printf("enter the trim type (l, r, b): ");
    if (scanf(" %c", &type) != 1) {
        return 0;
    }

    if (type == 'l') {
        char out[MAXLEN + 1];
        lstrip(line, out);
        printf("|%s|\n", out);
    } else if (type == 'r') {
        char out[MAXLEN + 1];
        rstrip(line, out);
        printf("|%s|\n", out);
    } else if (type == 'b') {
        char out[MAXLEN + 1];
        strip(line, out);
        printf("|%s|\n", out);
    } else {
        // keep an error message in case an unexpected command is provided
        printf("unexpected command.");
    }
    return 0;
}
