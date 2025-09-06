/*
 * min_max_allocate_alt.c — Alternative dynamic array min/max finder.
 * I/O strings are kept EXACT:
 *   "give n: "
 *   For i=0..n-1: "array[%d] = "
 *   Then array printed without spaces/newlines between items, then "\n"
 *   Finally: "max = %d, min = %d" (no trailing newline)
 */

#include <stdio.h>
#include <stdlib.h>

static void print_array_raw(const int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

static int max_of(const int *arr, int n) {
    int m = arr[0];
    for (int i = 1; i < n; ++i) if (arr[i] > m) m = arr[i];
    return m;
}

static int min_of(const int *arr, int n) {
    int m = arr[0];
    for (int i = 1; i < n; ++i) if (arr[i] < m) m = arr[i];
    return m;
}

int main(void) {
    int n = 0;
    int *buf = NULL;

    printf("give n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        // Do not print anything else; original had no validation prints
        return EXIT_SUCCESS;
    }

    buf = (int*)malloc(sizeof(int) * (size_t)n);
    if (!buf) return EXIT_SUCCESS;

    for (int i = 0; i < n; ++i) {
        printf("array[%d] = ", i);
        scanf("%d", &buf[i]);
    }

    print_array_raw(buf, n);
    int mx = max_of(buf, n);
    int mn = min_of(buf, n);
    printf("max = %d, min = %d", mx, mn);

    free(buf);
    return EXIT_SUCCESS;
}
