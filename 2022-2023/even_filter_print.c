/*
 * even_filter_print.c — Alternative implementation for MT2 Q3.
 * Behavior:
 *   - EXACT same prompts/outputs as the original specification.
 *   - Reads up to CAPACITY integers (stop with -1).
 *   - Prints either even numbers only or all numbers based on user's choice.
 * Comments are in English; variable/function names are customized.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CAPACITY 6

/* ---------- Required I/O strings (must match exactly) ----------
printf("Enter your numbers (-1 to finish):\n");
printf("Max capacity is reached! Cannot accept more numbers!\n");
printf("Number of evens: %d\n", _______);
printf("What type of numbers would you print?\n  > (0: for evens only, 1: for all numbers):");
printf("%d. %d\n",_______);
----------------------------------------------------------------- */

/* Print array items with 1-based indexing, line format: "%d. %d\n" */
void print_array_content(int* vec, int used){
    for (int idx = 0; idx < used; ++idx){
        printf("%d. %d\n", idx + 1, vec[idx]);
    }
}

/* Read integers until -1 or CAPACITY is reached; return #items stored */
int populate_array(int* store, int limit){
    int token = 0;
    int used = 0;

    printf("Enter your numbers (-1 to finish):\n");
    while (used < limit && scanf("%d", &token) == 1){
        if (token == -1){
            return used;
        }
        store[used++] = token;
    }

    if (used == limit){
        printf("Max capacity is reached! Cannot accept more numbers!\n");
    }
    return used;
}

/* Count even numbers in the first 'used' elements */
int get_even_count(int *vec, int used){
    int tally = 0;
    for (int i = 0; i < used; ++i){
        if (vec[i] % 2 == 0){
            ++tally;
        }
    }
    return tally;
}

/* Allocate a compact array of only even numbers; caller frees */
int *filter_evens(int *vec, int used, int n_evens){
    /* malloc(0) is permitted; main frees regardless */
    int *only_evens = (int*)malloc(sizeof(int) * (size_t)n_evens);
    int w = 0;
    for (int i = 0; i < used; ++i){
        if (vec[i] % 2 == 0){
            only_evens[w++] = vec[i];
        }
    }
    return only_evens;
}

/* Prompt for choice exactly as specified; return 0 or 1 */
int get_users_choice(void){
    int choice = 0;
    printf("What type of numbers would you print?\n  > (0: for evens only, 1: for all numbers):");
    scanf("%d", &choice);
    return choice;
}

/* ---------- WARNING: Do not modify the below part! ---------- */

int main(void) {
    int numbers[CAPACITY];
    int size_numbers;
    int size_evens;

    size_numbers = populate_array(numbers, CAPACITY);
    
    size_evens = get_even_count(numbers, size_numbers);
    printf("Number of evens: %d\n", size_evens);

    int *evens = filter_evens(numbers, size_numbers, size_evens);
    int choice = get_users_choice();

    if(choice == 0) {
        print_array_content(evens, size_evens);
    } else {
        print_array_content(numbers, size_numbers);
    }

    free(evens);
    return EXIT_SUCCESS;
}
