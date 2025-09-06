/*
 * temp_conv_alt.c — Alternative Fahrenheit→Celsius converter.
 * Purpose : Read Fahrenheit and print Celsius with the same format & labels.
 * I/O     : Strings must be EXACT; note the spelling/case of "fahrenheit"/"celcius".
 * Build   : gcc -std=c17 -O2 -Wall -Wextra temp_conv_alt.c -o temp_conv_alt
 */

#include <stdio.h>

// Convert Fahrenheit to Celsius (float precision)
static inline float to_celsius_f(float f) {
    return (5.0f/9.0f) * (f - 32.0f);
}

int main(void) {
    float degF = 0.0f;
    float degC = 0.0f;

    // Exact prompt
    printf("Enter Fahrenheit:");
    if (scanf("%f", &degF) != 1) return 0;

    degC = to_celsius_f(degF);

    // Exact output (including decimals and labels)
    printf("%.2f fahrenheit is %.3f celcius\n", degF, degC);
    return 0;
}
