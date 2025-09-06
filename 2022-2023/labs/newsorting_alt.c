/*
 * newsorting_alt.c — Same I/O as original "newsorting.c", corrected pointer returns.
 * Notes:
 *   - Output strings are IDENTICAL to the original to satisfy tests.
 *   - Ascending function returns int* so that main prints via pointer safely.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int* sort_desc_ptr(int *array) {
    bool looping = true;
    while (looping) {
        int swaps = 0;
        for (int i = 0; i < 9; ++i) {
            if (array[i] < array[i + 1]) {
                int t = array[i]; array[i] = array[i + 1]; array[i + 1] = t;
                ++swaps;
            }
        }
        looping = (swaps != 0);
    }
    return array;
}

static int* sort_asc_ptr(int *array) {
    bool looping = true;
    while (looping) {
        int swaps = 0;
        for (int i = 0; i < 9; ++i) {
            if (array[i] > array[i + 1]) {
                int t = array[i]; array[i] = array[i + 1]; array[i + 1] = t;
                ++swaps;
            }
        }
        looping = (swaps != 0);
    }
    return array;
}

int main(void) {
    int my_array[10];

    // EXACT strings preserved
    printf("Enter 10 numbers:");
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &my_array[i]);
    }

    printf("Original Array:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", my_array[i]);
    }

    int *sortedA = sort_asc_ptr(my_array);

    printf("\nSorted Array(Ascending):");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", sortedA[i]);
    }

    sort_desc_ptr(my_array);

    printf("\nSorted Array(Descending):");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", my_array[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
