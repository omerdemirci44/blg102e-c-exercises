/*
 * tic_tac_tou_alt.c — Alternative Tic Tac Toe winner checker.
 * I/O strings are kept EXACT to match the original program's tester.
 * Prints:
 *   "Tic Tac Toe game \n"
 *   "give the input: \n"
 *   For i=0..2: "line%d = \n"
 *   "array: " then the 9 characters (no spaces) then "\n"
 *   Winner logic:
 *     - Prints single character with "\n" for row/column win
 *     - Prints single character WITHOUT newline for diagonal win (as original)
 *     - Otherwise prints "draw\n"
 */

#include <stdio.h>
#include <stdlib.h>

static void print_board_chars(char a[][3]) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            printf("%c", a[r][c]);
        }
    }
    printf("\n");
}

static void report_winner(char a[][3]) {
    // Row/column checks
    for (int i = 0; i < 3; ++i) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2]) {
            printf("%c\n", a[i][0]); // row winner (newline, like original)
            return;
        }
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i]) {
            printf("%c\n", a[0][i]); // column winner (newline)
            return;
        }
    }
    // Diagonals — original printed without newline when diagonal wins
    if ((a[0][0] == a[1][1] && a[1][1] == a[2][2]) ||
        (a[0][2] == a[1][1] && a[1][1] == a[2][0])) {
        printf("%c", a[0][0]); // keep exact missing newline behavior
        return;
    }
    // Draw
    printf("draw\n");
}

int main(void) {
    char grid[3][3];
    char token;

    printf("Tic Tac Toe game \n");
    printf("give the input: \n");

    for (int r = 0; r < 3; ++r) {
        printf("line%d = \n", r);
        for (int c = 0; c < 3; ++c) {
            scanf(" %c", &token);
            grid[r][c] = token;
        }
    }

    printf("array: ");
    print_board_chars(grid);

    report_winner(grid);
    return EXIT_SUCCESS;
}
