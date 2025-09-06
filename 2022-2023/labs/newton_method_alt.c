/*
 * newton_method_alt.c — Newton's method for quadratic ax^2 + bx + c.
 * Notes:
 *   - Keeps the SAME I/O behavior/strings as the original:
 *       * Reads a, b, c via scanf (no prompts).
 *       * Prints "point: (%.2f %.2f)\n" at each iteration (x after update, previous y).
 *       * Ends with "Root: %.2f" (no trailing newline).
 *   - Variable names are customized; comments are in English.
 */

#include <stdio.h>
#include <math.h>

#define ERROR_TOLERANCE 0.001f
#define EPSILON 0.001f

static inline float poly_eval(float a, float b, float c, float x) {
    return a*x*x + b*x + c;
}

static inline float central_diff(float a, float b, float c, float x) {
    // Central difference to approximate derivative: (f(x+e) - f(x-e)) / (2e)
    float y1 = poly_eval(a, b, c, x + EPSILON);
    float y2 = poly_eval(a, b, c, x - EPSILON);
    return (y1 - y2) / (2.0f * EPSILON);
}

int main(void) {
    float ca = 0.0f, cb = 0.0f, cc = 0.0f;
    if (scanf("%f %f %f", &ca, &cb, &cc) != 3) return 0;

    float cur_x = 1.0f;  // starting point
    while (fabsf(poly_eval(ca, cb, cc, cur_x)) > ERROR_TOLERANCE) {
        float f_val = poly_eval(ca, cb, cc, cur_x);
        float slope = central_diff(ca, cb, cc, cur_x);
        if (slope == 0.0f) slope += EPSILON;  // avoid div-by-zero
        cur_x = cur_x - (f_val / slope);
        // EXACT same iteration print format: x AFTER update, y BEFORE update
        printf("point: (%.2f %.2f)\n", cur_x, f_val);
    }
    // EXACT same final line (no trailing newline)
    printf("Root: %.2f", cur_x);
    return 0;
}
