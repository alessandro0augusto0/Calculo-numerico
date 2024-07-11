#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 4;
}

void secante(double x0, double x1, double e)
{
    double x2;
    do
    {
        x2 = x1 - (x1 - x0) / (f(x1) - f(x0)) * f(x1);
        x0 = x1;
        x1 = x2;
    } while (fabs(f(x2)) > e);

    printf("A raiz da funcao eh: %f\n", x2);
}

int main()
{
    double x0, x1, e;

    printf("Digite o primeiro valor inicial: ");
    scanf("%lf", &x0);
    printf("Digite o segundo valor inicial: ");
    scanf("%lf", &x1);
    printf("Digite a tolerancia: ");
    scanf("%lf", &e);

    secante(x0, x1, e);

    return 0;
}
