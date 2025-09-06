
#include <stdio.h>

static int strictly_increasing(const int v[3]) {
    return (v[0] < v[1]) && (v[1] < v[2]);
}

static int strictly_decreasing(const int v[3]) {
    return (v[0] > v[1]) && (v[1] > v[2]);
}

int main(void) {
    int a[3];
    printf("Give three integers separated with space:");
    if (scanf("%d %d %d", &a[0], &a[1], &a[2]) != 3) {
        return 0; 
    }

    if (strictly_decreasing(a)) {
        printf("strictly decreasing\n");
    } else if (strictly_increasing(a)) {
        printf("strictly increasing\n");
    } else {
        printf("none of the two\n");
    }
    return 0;
}
