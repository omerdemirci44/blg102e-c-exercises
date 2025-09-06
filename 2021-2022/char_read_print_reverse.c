// alt_m2q1.c — BLG102E M2 Q1: same I/O, different implementation (while loops + two-index reverse)
#include <stdio.h>

#define SIZE 20

void get_characters(char characters[], int size)
{
    int i = 0;
    while (i < size) {
    
        if (scanf("%c", &characters[i]) != 1) {
            characters[i] = '\n'; 
        }
        i++;
    }
}

void reverse_characters(char characters[], char reversed_array[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left < size) {
        reversed_array[left] = characters[right];
        left++;
        right--;
    }
}

void print_characters(char characters[], int size)
{
    int i = 0;
    if (size <= 0) {
        putchar('\n');
        return;
    }
 
    do {
        printf("%c", characters[i]);
        i++;
    } while (i < size);
    printf("\n");
}

int main(void)
{
    char characters[SIZE];
    char reversed_array[SIZE];
    int size = SIZE;

    
    printf("Insert 20 consecutive characters:");
    get_characters(characters, size);
    printf("\nThe user entered the following characters:");
    print_characters(characters, size);
    reverse_characters(characters, reversed_array, size);
    printf("The characters in reverse order are: ");
    print_characters(reversed_array, size);

    return 0;
}
