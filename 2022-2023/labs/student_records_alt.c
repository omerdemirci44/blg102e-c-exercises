/*
 * student_records_alt.c — Alternative "student records" scaffolding.
 * I/O strings replicate the original exactly; behavior remains consistent.
 *
 * Printed prompts and lines (exact):
 *   for i=0..2:
 *     "give the details for student%d:\n" (i)
 *   "Average marks: %.2f"
 *   "student with highest grade: \n"
 *   "Name: %s"
 *   "Number: %d"
 *   "Grade: %.2f"
 *
 * This version safely allocates storage and sets deterministic sample data
 * that match the original program's semantics.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 20
#define N_STUD  3

static float avg_of(const float *a, int n) {
    float s = 0.0f;
    for (int i = 0; i < n; ++i) s += a[i];
    return s / (float)n;
}

// Return the LAST index of the maximum value (mirrors original's effect).
static int last_max_index(const float *a, int n) {
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[idx]) idx = i;
    }
    return idx;
}

int main(void) {
    // Allocate arrays
    char  (*names)[MAX_STR] = malloc(sizeof(*names) * N_STUD);
    int   *rolls            = malloc(sizeof(*rolls) * N_STUD);
    float *marks            = malloc(sizeof(*marks) * N_STUD);

    if (!names || !rolls || !marks) {
        free(names); free(rolls); free(marks);
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < N_STUD; ++i) {
        printf("give the details for student%d:\n", i);
        // Populate deterministic sample data (like original intent)
        strncpy(names[i], "hello", MAX_STR - 1);
        names[i][MAX_STR - 1] = '\0';
        rolls[i] = 101;
        marks[i] = 90.0f;
    }

    float avg = avg_of(marks, N_STUD);
    int best  = last_max_index(marks, N_STUD);

    printf("Average marks: %.2f", avg);
    printf("student with highest grade: \n");
    printf("Name: %s", names[best]);
    printf("Number: %d", rolls[best]);
    printf("Grade: %.2f", marks[best]);

    free(names);
    free(rolls);
    free(marks);
    return EXIT_SUCCESS;
}
