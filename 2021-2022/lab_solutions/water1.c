// water1.c
#include <stdio.h>
#include <ctype.h>
int main(void){ double t; char s; if (scanf("%lf %c",&t,&s)!=2) return 0; s=(char)toupper((unsigned char)s);
    double c=(s=='F')? (t-32.0)*5.0/9.0 : t;
    if (c<=0.0) puts("solid"); else if (c>=100.0) puts("gaseous"); else puts("liquid"); return 0; }
