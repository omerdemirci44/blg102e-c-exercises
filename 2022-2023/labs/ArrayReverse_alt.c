/*
 * ArrayReverse_alt.c — Reverse a fixed array in place and print diagnostics.
 * Notes:
 *   - Prompts and output strings match the original file exactly.
 *   - Function and variable names are customized; comments in English.
 */

#include <stdio.h>
#include <stdlib.h>

// Reverse the array of length 10 and return the first element AFTER reversing
static int flip_and_head(int *arr) {
    for (int left = 0; left < 5; ++left) {
        int right = 10 - (left + 1);
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
    return arr[0];
}

int main(void) {
    int data[10] = {3, 6, 7, 5, 2, 9, 1, 0, 8, 4};

    // EXACT original prints
    printf("ORIGINAL ARRAY:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", data[i]);
    }
    printf("\n");

    int first_index = flip_and_head(data);
    printf("first index = %d\n", first_index);

    printf("REVERSE ARRAY:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", data[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
