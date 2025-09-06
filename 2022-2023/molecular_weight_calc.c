/*
 * mt2q1_alt.c — Molecular Weight Calculator (elements up to Ne).
 * Behavior:
 *   - I/O strings are kept EXACT as in the original program to satisfy tests.
 *   - Reads repeated lines: "<symbol> <count>", stops on "end <anything>".
 *   - Accumulates total molecular weight using the provided lookup tables.
 */

#include <stdio.h>
#include <string.h>

// Lookup tables kept identical (order matters: indices align)
static const char *kElements[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
static const double kAtomicWeights[] = {1.007, 4.002602, 6.941, 9.012182, 10.811, 12.0107, 14.0067, 15.9994, 18.9984032, 20.1797};
static const int kNumElements = 10;

// Find the index of a chemical symbol; returns -1 if not found
static int find_symbol_index(const char *sym) {
    for (int i = 0; i < kNumElements; ++i) {
        if (strcmp(kElements[i], sym) == 0) return i;
    }
    return -1;
}

// Compute partial contribution for one symbol-count pair
static double calculate(const char *symbol, int atoms) {
    int idx = find_symbol_index(symbol);
    if (idx < 0 || atoms <= 0) return 0.0;
    return (double)atoms * kAtomicWeights[idx];
}

int main(void){
    char chemSymbol[8];   // roomy enough for "end" and 2-char symbols
    int atomCount = 0;
    double totalMass = 0.0;

    while (1){
        // Prompt must be EXACT
        printf("Enter element symbol and number of atoms separated with a space: ");
        if (scanf("%7s %d", chemSymbol, &atomCount) != 2) {
            // If parsing fails, continue prompting (original has no error text)
            continue;
        }
        if (strcmp(chemSymbol, "end") == 0){
            break;
        }
        totalMass += calculate(chemSymbol, atomCount);
    }

    // Final line must be EXACT
    printf("The molecular weight is %.2f\n", totalMass);
    return 0;
}
