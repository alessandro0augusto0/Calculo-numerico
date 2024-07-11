#include <stdio.h>

double diferenca_dividida(int i, int j, double x_values[], double y_values[])
{
    if (i == j)
    {
        return y_values[i];
    }
    else
    {
        return (diferenca_dividida(i + 1, j, x_values, y_values) - diferenca_dividida(i, j - 1, x_values, y_values)) /
               (x_values[j] - x_values[i]);
    }
}

double newton(double x, double x_values[], double y_values[], int n)
{
    double result = 0.0;
    double term = 1.0;

    for (int i = 0; i < n; i++)
    {
        result += diferenca_dividida(0, i, x_values, y_values) * term;
        term *= (x - x_values[i]);
    }

    return result;
}

int main()
{
    int n;
    printf("Digite o numero de pontos para a interpolacao: ");
    scanf("%d", &n);

    double x_values[n], y_values[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor de x%d: ", i + 1);
        scanf("%lf", &x_values[i]);
        printf("Digite o valor de y%d: ", i + 1);
        scanf("%lf", &y_values[i]);
    }

    double x;
    printf("Digite o valor de x para interpolacao: ");
    scanf("%lf", &x);

    double result = newton(x, x_values, y_values, n);

    printf("O valor interpolado para x = %.2lf eh y = %.2lf\n", x, result);

    return 0;
}
