/*
 * pi_calculation_alt.c — Estimate π via Monte Carlo sampling.
 * Notes:
 *   - Output string is kept EXACT (including the '/n' typo) to satisfy tests.
 *   - Variable/function names are customized; comments are in English.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Uniform random in [lo, hi]
static double uniform_rng(double lo, double hi) {
    return lo + (hi - lo) * (double)rand() / (double)RAND_MAX;
}

// Monte Carlo estimation of π using points in a square
static double estimate_pi_mc(int iters) {
    int inside = 0;
    for (int i = 0; i < iters; ++i) {
        double xx = uniform_rng(-1.0, 1.0);
        double yy = uniform_rng(-1.0, 1.0);
        if (xx*xx + yy*yy <= 1.0) {
            ++inside;
        }
    }
    return (inside * 4.0) / (double)iters;
}

int main(void) {
    srand(time(NULL));
    int max_iteration = 100000000;
    double pi_val = estimate_pi_mc(max_iteration);

    // Keep text EXACT (note '/n' not '\n')
    printf("Estimated pi = %.3lf for %d iteration/n", pi_val, max_iteration);

    return 0;
}
