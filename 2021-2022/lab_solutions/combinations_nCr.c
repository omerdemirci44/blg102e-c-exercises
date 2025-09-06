// combinations_nCr.c
#include <stdio.h>
unsigned long long factorial(unsigned int x) { unsigned long long f = 1ULL; for (unsigned int i = 2; i <= x; ++i) f *= i; return f; }
unsigned long long nCr(unsigned int n, unsigned int r) { if (r > n) return 0ULL; return factorial(n) / (factorial(r) * factorial(n - r)); }
int main(void) { unsigned int n, r; if (scanf("%u %u", &n, &r) != 2) return 0; printf("nCr = %llu\n", nCr(n, r)); return 0; }
