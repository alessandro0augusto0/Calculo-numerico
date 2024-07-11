#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 4;
}

double posicaoFalsa(double a, double b, double epsilon)
{
    double c;
    int iteracoes = 0;

    while (fabs(b - a) >= epsilon)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iteracoes++;
    }

    printf("Iteracoes necessarias: %d\n", iteracoes);
    return c;
}

int main()
{
    double a, b, epsilon;

    printf("Digite o valor de a: ");
    scanf("%lf", &a);

    printf("Digite o valor de b: ");
    scanf("%lf", &b);

    printf("Digite a precisao (epsilon): ");
    scanf("%lf", &epsilon);

    double resultado = posicaoFalsa(a, b, epsilon);

    if (!isnan(resultado))
        printf("A raiz aproximada eh: %lf\n", resultado);
    else
        printf("Nao foi possivel calcular a raiz.\n");

    return 0;
}
