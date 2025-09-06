/*
 * moving_average_alt.c — Weekly data reporter with prefix-average and 3-term moving average.
 * Notes:
 *   - All prompts and output formats are kept EXACT to match the tester.
 *   - Variable/function names are customized; comments are in English.
 */

#include <stdio.h>
#include <stdlib.h>

// Average of elements array[0..idx] inclusive
static double prefix_mean(const double *arr, int idx) {
    double acc = 0.0;
    for (int k = 0; k <= idx; ++k) {
        acc += arr[k];
    }
    // Match original division by (idx+1)
    return acc / (double)(idx + 1);
}

// 3-term moving average ending at idx (idx-2, idx-1, idx). If idx<2 => 0.0
static double tri_window_mean(const double *arr, int idx) {
    if (idx < 2) return 0.0;
    double s = arr[idx] + arr[idx - 1] + arr[idx - 2];
    return s / 3.0;
}

int main(void) {
    double series[16] = {0};
    double val = 0.0;

    // EXACT input loop & prompt
    for (int i = 1; i <= 16; ++i) {
        printf("Enter data for Week %d:", i);
        scanf("%lf", &val);
        series[i - 1] = val;
    }

    // EXACT output formatting (two spaces between numbers)
    for (int i = 0; i < 16; ++i) {
        printf("Week %d: %.3lf  %.3lf  %.3lf\n",
               i + 1,
               series[i],
               prefix_mean(series, i),
               tri_window_mean(series, i));
    }

    return EXIT_SUCCESS;
}
