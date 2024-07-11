#include <stdio.h>

double lagrange(double x, double x_values[], double y_values[], int n)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        double term = y_values[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= (x - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }
        result += term;
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

    double result = lagrange(x, x_values, y_values, n);

    printf("O valor interpolado para x = %.2lf eh y = %.2lf\n", x, result);

    return 0;
}
