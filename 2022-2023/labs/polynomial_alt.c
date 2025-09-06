/*
 * polynomial_alt.c — Alternative solution for quadratic roots.
 * Purpose : Read a, b, c and print two roots with the same text format.
 * I/O     : Prompts and print strings must be EXACT to satisfy tests.
 * Build   : gcc -std=c17 -O2 -Wall -Wextra polynomial_alt.c -lm -o polynomial_alt
 */

#include <stdio.h>
#include <math.h>

// Helper: compute two roots (may produce NaN if discriminant < 0, as per original).
static void quad_solve_pair(float a, float b, float c, float* r1, float* r2) {
    float disc = (b * b) - (4.0f * a * c);
    float sqrt_disc = sqrtf(disc);
    float two_a = 2.0f * a;
    *r1 = ((-b) + sqrt_disc) / two_a;
    *r2 = ((-b) - sqrt_disc) / two_a;
}

int main(void) {
    // Custom variable names
    float coef_a = 0.0f, coef_b = 0.0f, coef_c = 0.0f;
    float root_hi = 0.0f, root_lo = 0.0f;

    // Exact prompt text preserved.
    printf("Enter 3 coefficients for second-order polynomial:");
    if (scanf("%f %f %f", &coef_a, &coef_b, &coef_c) != 3) return 0;

    quad_solve_pair(coef_a, coef_b, coef_c, &root_hi, &root_lo);

    // Exact output text preserved.
    printf("Roots: x1: %.2f, x2: %.2f\n", root_hi, root_lo);
    return 0;
}
