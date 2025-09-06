// taxi_office_order_reverse.c
// Week 09 — Taxi Office: random order then reverse order next day.
// Reads N and seed; prints random order and its reverse on separate lines.
// Comments in English.

#include <stdio.h>
#include <stdlib.h>

static void fill_identity(int *a, int n) {
    for (int i = 0; i < n; ++i) a[i] = i;
}

static void fisher_yates_shuffle(int *a, int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    }
}

static void reverse_copy(const int *src, int *dst, int n) {
    for (int i = 0; i < n; ++i) dst[i] = src[n - 1 - i];
}

static void print_array(const int *a, int n) {
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main(void) {
    int N; unsigned int seed;
    if (scanf("%d %u", &N, &seed) != 2) return 0;
    if (N <= 0 || N > 1000) return 0;
    srand(seed);
    int order[1000], rev[1000];
    fill_identity(order, N);
    fisher_yates_shuffle(order, N);
    reverse_copy(order, rev, N);
    print_array(order, N);
    print_array(rev, N);
    return 0;
}
