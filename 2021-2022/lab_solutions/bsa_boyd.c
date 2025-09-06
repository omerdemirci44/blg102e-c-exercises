// bsa_boyd.c
#include <stdio.h>
#include <math.h>
int main(void) { double h_cm, w_g; if (scanf("%lf %lf", &h_cm, &w_g) != 2) return 0;
    double expo = 0.7285 - (0.0188 * log10(w_g)); double bsa = 0.0003207 * pow(h_cm, 0.3) * pow(w_g, expo);
    printf("BSA: %.4f\n", bsa); return 0; }
