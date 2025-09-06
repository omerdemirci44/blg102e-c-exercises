/*
 * monte_hall_alt.c — Monte Hall simulation (no stdout by design).
 * Notes:
 *   - I/O is intentionally identical to the original: it prints NOTHING.
 *   - Variable names and structure are refactored; comments are in English.
 *   - Random seed: time-based for variability across runs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N_ITERATIONS 100000  // same iteration count as the original

// Return a host door to open (not prize, not initial pick). Deterministic choice.
static int host_open_choice(int prize, int pick) {
    for (int d = 1; d <= 3; ++d) {
        if (d != prize && d != pick) return d;
    }
    // If pick==prize, any non-picked door could be opened; choose the first.
    for (int d = 1; d <= 3; ++d) {
        if (d != pick) return d;
    }
    return 1; // fallback (unreachable)
}

int main(void) {
    srand((unsigned)time(NULL));

    int win_stay = 0;    // strategy1: stay with initial pick
    int win_switch = 0;  // strategy2: switch to the other unopened door

    for (int i = 0; i < N_ITERATIONS; ++i) {
        int prize_door = (rand() % 3) + 1;
        int first_pick = (rand() % 3) + 1;

        int opened_by_host = host_open_choice(prize_door, first_pick);

        // The remaining unopened door after host reveals a goat
        int switch_target = 6 - first_pick - opened_by_host; // 1+2+3 == 6

        if (prize_door == first_pick) {
            ++win_stay;
        } else if (prize_door == switch_target) {
            ++win_switch;
        }
    }

    // No printf: keep output identical to the original (empty)
    return 0;
}
