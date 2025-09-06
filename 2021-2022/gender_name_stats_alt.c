// alt_fq2.c — Alternative implementation for gender-prefixed names
// Goal: Preserve exact messages and output format, improve robustness and indexing.
// Behavior:
//  * Accept 1..5 arguments, each must start with "M_" or "F_" and contain at least 1 char after underscore.
//  * Count females/males and compute average string length per group (same metric as original: full strlen including prefix).
//  * Print two lines with the exact format required.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 6  // up to 5 names (argv[1..5])

int main(int argc, char* argv[])
{
    // Checking if number of arguments is at most 5 and at least 1
    if (argc <= 1 || argc > 6)
    {
        printf("Enter 1 to 5 arguments!\n");
        return 1;
    }

    int male_count = 0;
    int female_count = 0;
    int male_length[N];
    int female_length[N];

    // Use compact write indices for arrays to avoid gaps.
    int mi = 0, fi = 0;

    for (int i = 1; i < argc; i++) {
        int length = (int)strlen(argv[i]);

        // Must have a gender prefix of exactly two chars: 'M_' or 'F_'
        if (length >= 2 && argv[i][1] == '_' && (argv[i][0] == 'M' || argv[i][0] == 'F')) {

            // After the prefix, at least one character must remain.
            if (length == 2) {
                printf("Names should contain at least 1 character after gender prefix!");
                return 1;
            }

            if (argv[i][0] == 'M') {
                male_count++;
                if (mi < N) male_length[mi++] = length;
            } else {
                female_count++;
                if (fi < N) female_length[fi++] = length;
            }
        } else {
            printf("Names should start with either M_ or F_!\n");
            return 1;
        }
    }

    int male_sum = 0;
    for (int i = 0; i < mi; i++) male_sum += male_length[i];
    double male_avg = (male_count != 0) ? ((double)male_sum / male_count) : 0.0;

    int female_sum = 0;
    for (int i = 0; i < fi; i++) female_sum += female_length[i];
    double female_avg = (female_count != 0) ? ((double)female_sum / female_count) : 0.0;

    printf("Female count: %d, avg. female name length: %2.1f\n", female_count, female_avg);
    printf("Male count: %d, avg. male name length: %2.1f\n", male_count, male_avg);

    return 0;
}
