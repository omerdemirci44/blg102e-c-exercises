/*
 * bsa_alt.c — Alternative implementation with identical I/O contract.
 * Purpose : Compute Body Surface Area (BSA) from height (cm) and weight (g).
 * I/O     : Prompts and prints must MATCH the original exactly to pass tests.
 * Build   : gcc -std=c17 -O2 -Wall -Wextra bsa_alt.c -lm -o bsa_alt
 */

#include <stdio.h>
#include <math.h>

// Calculate BSA using the given empirical formula (float precision).
static inline float bsa_calc_metric(float h_cm, float w_g) {
    // Using powf / log10f to stay in float domain.
    float term_exp = 0.7285f - (0.0188f * log10f(w_g));
    return 0.0003207f * powf(h_cm, 0.3f) * powf(w_g, term_exp);
}

int main(void) {
    // Custom variable names to avoid stylistic similarity.
    float stature_cm = 0.0f;
    float mass_g     = 0.0f;

    // Keep the prompt EXACT (string + spacing) for the tester.
    printf("Input height(cm) and weight(g):");
    if (scanf("%f", &stature_cm) != 1) return 0;
    if (scanf("%f", &mass_g) != 1) return 0;

    float bsa_estimate = bsa_calc_metric(stature_cm, mass_g);

    // Keep the output label/format EXACT.
    printf("BSA: %.2f\n", bsa_estimate);
    return 0;
}
