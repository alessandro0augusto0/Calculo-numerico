#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 4; 
}

double bisection(double a, double b, double tol) {
    double c;
    
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        
        if (f(c) == 0.0 || (b - a) < tol)
            break;
        
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    
    return c;
}

int main() {
    double a, b, tol;
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o valor de b: ");
    scanf("%lf", &b);
    printf("Digite a tolerancia desejada: ");
    scanf("%lf", &tol);

    double root = bisection(a, b, tol);

    printf("A raiz aproximada eh: %lf\n", root);

    return 0;
}
