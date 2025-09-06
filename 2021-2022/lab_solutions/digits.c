// digits.c
#include <stdio.h>
int main(void) { int n; if (scanf("%d", &n) != 1) return 0; int s = (n<0)?-1:1; int x = n*s; int d3=x%10, d2=(x/10)%10, d1=(x/100)%10;
    printf("Digits of number %d are %d, %d, %d respectively\n", n, d1, d2, d3); return 0; }
