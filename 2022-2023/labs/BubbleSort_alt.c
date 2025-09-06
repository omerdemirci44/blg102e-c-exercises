/*
 * BubbleSort_alt.c — Sort 10 integers ascending then descending.
 * Notes:
 *   - All prompts and output strings are kept EXACT to satisfy tests.
 *   - Comments are in English; function names are customized.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void sort_desc(int *a) {
    bool active = true;
    while (active) {
        int swaps = 0;
        for (int i = 0; i < 9; ++i) {
            if (a[i] < a[i + 1]) {
                int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
                ++swaps;
            }
        }
        active = (swaps != 0);
    }
}

static void sort_asc(int *a) {
    bool active = true;
    while (active) {
        int swaps = 0;
        for (int i = 0; i < 9; ++i) {
            if (a[i] > a[i + 1]) {
                int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
                ++swaps;
            }
        }
        active = (swaps != 0);
    }
}

int main(void) {
    int my_array[10];

    // EXACT prompts/labels
    printf("Enter 10 numbers:");
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &my_array[i]);
    }

    printf("Original Array:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", my_array[i]);
    }

    sort_asc(my_array);

    printf("\nSorted Array(Ascending):");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", my_array[i]);
    }

    sort_desc(my_array);

    printf("\nSorted Array(Descending):");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", my_array[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
