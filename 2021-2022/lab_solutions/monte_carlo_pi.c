// monte_carlo_pi.c
// Week 06 — Monte Carlo estimation of pi
// Spec: Implement getRandomNumber(lower, upper) and calculatePi(max_iteration).
// I/O: ask for iteration count and RNG seed for reproducibility.
// Reference task: Week 6 Monte Carlo pi. 
// Comments in English.

#include <stdio.h>
#include <stdlib.h>

static double getRandomNumber(double lower_limit, double upper_limit) {
    // Uniform random number in [lower_limit, upper_limit]
    double u = (double)rand() / (double)RAND_MAX; // in [0,1]
    return lower_limit + u * (upper_limit - lower_limit);
}

static double calculatePi(int max_iteration) {
    // Unit square [-1,1] x [-1,1]; count points inside unit circle x^2+y^2<=1
    // pi ≈ 4 * (inside / total)
    int inside = 0;
    for (int i = 0; i < max_iteration; ++i) {
        double x = getRandomNumber(-1.0, 1.0);
        double y = getRandomNumber(-1.0, 1.0);
        if (x*x + y*y <= 1.0) inside++;
    }
    return 4.0 * (double)inside / (double)max_iteration;
}

int main(void) {
    int iters;
    unsigned int seed;
    if (scanf("%d %u", &iters, &seed) != 2) return 0;
    srand(seed);
    double pi = calculatePi(iters);
    printf("pi ~= %.6f\n", pi);
    return 0;
}
