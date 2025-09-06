
#include <stdio.h>
#include <stdbool.h>

static void print_menu(void) {
    printf("Which task would you like to perform?\n");
    printf("1 to check if the list is strictly increasing or decreasing\n");
    printf("2 to check if the list is increasing or decreasing\n");
    printf("3 to compute the maximum number in the list\n");
    printf("4 to reverse the list\n");
    printf("5 to enter a new list of integers\n");
    printf("-1 to terminate the program\n");
}

static bool is_strict_inc(const int v[3])   { return (v[0] < v[1]) && (v[1] < v[2]); }
static bool is_strict_dec(const int v[3])   { return (v[0] > v[1]) && (v[1] > v[2]); }
static bool is_non_strict_inc(const int v[3]) { return (v[0] <= v[1]) && (v[1] <= v[2]); }
static bool is_non_strict_dec(const int v[3]) { return (v[0] >= v[1]) && (v[1] >= v[2]); }
static int max3(const int v[3]) {
    int m = v[0];
    if (v[1] >= m) m = v[1];
    if (v[2] >  m) m = v[2];
    return m;
}

int main(void) {
    int x[3];
    int task;

    printf("Give three integers separated with space:");
    if (scanf("%d %d %d", &x[0], &x[1], &x[2]) != 3) {
        return 0;
    }

    while (true) {
        print_menu();
        if (scanf("%d", &task) != 1) return 0;

        if (task == 1) {
            if (is_strict_dec(x)) {
                printf("strictly decreasing\n");
            } else if (is_strict_inc(x)) {
                printf("strictly increasing\n");
            } else {
                printf("none of the two\n");
            }
        } else if (task == 2) {
            if (x[0] == x[1] && x[1] == x[2]) {
                printf("none of the two\n");
            } else if (is_non_strict_dec(x)) {
                printf("decreasing\n");
            } else if (is_non_strict_inc(x)) {
                printf("increasing\n");
            } else {
                printf("none of the two\n");
            }
        } else if (task == 3) {
            printf("the maximum number is %d\n", max3(x));
        } else if (task == 4) {
            printf("%d %d %d\n", x[2], x[1], x[0]);
        } else if (task == 5) {
            printf("Give three integers separated with space:");
            if (scanf("%d %d %d", &x[0], &x[1], &x[2]) != 3) return 0;
        } else if (task == -1) {
            return 0;
        } else {
            printf("not a defined option, try again\n");
        }
    }
    return 0;
}
