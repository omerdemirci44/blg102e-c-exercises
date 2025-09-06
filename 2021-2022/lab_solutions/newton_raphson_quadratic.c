// newton_raphson_quadratic.c
#include <stdio.h>
#include <math.h>
static double f(double a,double b,double c,double x){return a*x*x + b*x + c;}
static double dfdx(double a,double b,double c,double x){ const double h=1e-6; return (f(a,b,c,x+h)-f(a,b,c,x-h))/(2.0*h); }
int main(void){ double a,b,c,x,eps; int it; if (scanf("%lf %lf %lf %lf %lf %d",&a,&b,&c,&x,&eps,&it)!=6) return 0;
    for(int k=0;k<it;++k){ double fx=f(a,b,c,x); if (fabs(fx)<eps) break; double d=dfdx(a,b,c,x); if (fabs(d)<1e-12) break; x=x-fx/d; }
    printf("root: %.6f\n", x); return 0; }
