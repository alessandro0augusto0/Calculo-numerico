#include <stdio.h>

double soma_quadrados(double arr[], int n)
{
    double soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += arr[i] * arr[i];
    }
    return soma;
}

double coeficiente_a0(double y_values[], int n)
{
    return soma_quadrados(y_values, n) / n;
}

double coeficiente_a1(double x_values[], double y_values[], int n)
{
    double x_sum = 0.0;
    double xy_sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        x_sum += x_values[i];
        xy_sum += x_values[i] * y_values[i];
    }

    return xy_sum / x_sum;
}

double coeficiente_a2(double x_values[], double y_values[], int n)
{
    double x_sum = 0.0;
    double x_squared_sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        x_sum += x_values[i];
        x_squared_sum += x_values[i] * x_values[i];
    }

    return x_squared_sum / x_sum;
}

int main()
{
    int n;
    printf("Digite o numero de pontos: ");
    scanf("%d", &n);

    double x_values[n], y_values[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor de x%d: ", i + 1);
        scanf("%lf", &x_values[i]);
        printf("Digite o valor de y%d: ", i + 1);
        scanf("%lf", &y_values[i]);
    }

    double a0 = coeficiente_a0(y_values, n);
    double a1 = coeficiente_a1(x_values, y_values, n);
    double a2 = coeficiente_a2(x_values, y_values, n);

    printf("Ajuste Quadratico: y = %.2lfx^2 + %.2lfx + %.2lf\n", a2, a1, a0);

    return 0;
}
