// alt_m3q2_alt.c
// Purpose: Generate n random integers in [a..b] with a given seed and print them.
// Alternative structure: no dynamic allocation; print on-the-fly.
// I/O contract (prompt text and spacing) matches the tests exactly.
// Comments are in English.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, a, b, seed;

    // Exact prompt as in tests
    printf("n, a, b, seed: ");
    if (scanf("%d %d %d %d", &n, &a, &b, &seed) != 4) {
        return 0;
    }

    // Seed the PRNG (deterministic sequence for a given environment)
    srand(seed);

    // Inclusive span (assumed a <= b in the test data)
    int span = b - a + 1;

    // Generate and print numbers without storing them
    for (int i = 0; i < n; i++) {
        int x = a + (rand() % span);
        if (i > 0) printf(" ");
        printf("%d", x);
    }
    printf("\n");
    return 0;
}
