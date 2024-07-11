#include <stdio.h>

double media(double arr[], int n)
{
    double soma = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += arr[i];
    }
    return soma / n;
}

double coeficiente_angular(double x_values[], double y_values[], int n)
{
    double x_media = media(x_values, n);
    double y_media = media(y_values, n);

    double numerador = 0.0;
    double denominador = 0.0;

    for (int i = 0; i < n; i++)
    {
        numerador += (x_values[i] - x_media) * (y_values[i] - y_media);
        denominador += (x_values[i] - x_media) * (x_values[i] - x_media);
    }

    return numerador / denominador;
}

double coeficiente_linear(double x_values[], double y_values[], int n)
{
    double a = coeficiente_angular(x_values, y_values, n);
    double x_media = media(x_values, n);
    double y_media = media(y_values, n);

    return y_media - a * x_media;
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

    double a = coeficiente_angular(x_values, y_values, n);
    double b = coeficiente_linear(x_values, y_values, n);

    printf("Ajuste Linear: y = %.2lfx + %.2lf\n", a, b);

    return 0;
}
