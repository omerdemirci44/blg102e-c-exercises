// vectors2d.c
// Week 12 — 2D Vectors with dynamic allocation; implement operations.
// Comments in English.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { double x, y; } Vector2;

static void printVector(const Vector2 *v) {
    printf("(%.3f, %.3f)\n", v->x, v->y);
}

static Vector2* addVectors(const Vector2 *a, const Vector2 *b) {
    Vector2 *r = (Vector2*)malloc(sizeof(Vector2));
    r->x = a->x + b->x; r->y = a->y + b->y; return r;
}

static Vector2* substractVectors(const Vector2 *a, const Vector2 *b) {
    Vector2 *r = (Vector2*)malloc(sizeof(Vector2));
    r->x = a->x - b->x; r->y = a->y - b->y; return r;
}

static double magnitudeOfVector(const Vector2 *a) {
    return sqrt(a->x*a->x + a->y*a->y);
}

static double angleOfVector(const Vector2 *a) {
    return atan2(a->y, a->x); // radians
}

static double dotProduct(const Vector2 *a, const Vector2 *b) {
    return a->x*b->x + a->y*b->y;
}

static double angleBetweenVectors(const Vector2 *a, const Vector2 *b) {
    double denom = magnitudeOfVector(a)*magnitudeOfVector(b);
    if (denom == 0.0) return 0.0;
    double c = dotProduct(a,b)/denom;
    if (c > 1.0) c = 1.0; if (c < -1.0) c = -1.0;
    return acos(c); // radians
}

int main(void) {
    Vector2 *a = (Vector2*)malloc(sizeof(Vector2));
    Vector2 *b = (Vector2*)malloc(sizeof(Vector2));
    if (!a || !b) return 0;
    if (scanf("%lf %lf %lf %lf", &a->x, &a->y, &b->x, &b->y) != 4) return 0;
    Vector2 *sum = addVectors(a,b);
    Vector2 *dif = substractVectors(a,b);
    printf("a = "); printVector(a);
    printf("b = "); printVector(b);
    printf("a+b = "); printVector(sum);
    printf("a-b = "); printVector(dif);
    printf("|a| = %.3f\n|b| = %.3f\n", magnitudeOfVector(a), magnitudeOfVector(b));
    printf("angle(a) = %.3f rad\nangle(b) = %.3f rad\n", angleOfVector(a), angleOfVector(b));
    printf("dot(a,b) = %.3f\n", dotProduct(a,b));
    printf("angle(a,b) = %.3f rad\n", angleBetweenVectors(a,b));
    free(a); free(b); free(sum); free(dif);
    return 0;
}
