// bubble_sort_generic.c
#include <stdio.h>
#include <ctype.h>
void bubble_sort(int *a, int n, int ascending) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i < n - 1; ++i) {
            int cmp = ascending ? (a[i] > a[i+1]) : (a[i] < a[i+1]);
            if (cmp) { int tmp = a[i]; a[i] = a[i+1]; a[i+1] = tmp; swapped = 1; }
        }
    }
}
int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int arr[1000]; if (n > 1000) n = 1000;
    for (int i = 0; i < n; ++i) if (scanf("%d", &arr[i]) != 1) return 0;
    char t; if (scanf(" %c", &t) != 1) return 0; t = (char)toupper((unsigned char)t);
    bubble_sort(arr, n, t=='A');
    for (int i = 0; i < n; ++i) { if (i) printf(" "); printf("%d", arr[i]); } printf("\n");
    return 0;
}
