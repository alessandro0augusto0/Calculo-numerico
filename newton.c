#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 5;
}

double f_prime(double x) {
    return 2*x;
}

int main() {
    double x0;
    int max_iter;
    double epsilon;

    printf("Digite a estimativa inicial: ");
    scanf("%lf", &x0);

    printf("Digite o numero maximo de iteracoes: ");
    scanf("%d", &max_iter);

    printf("Digite a tolerancia para a solucao: ");
    scanf("%lf", &epsilon);

    int iter;
    for (iter = 0; iter < max_iter; iter++) {
        double fx = f(x0);
        double f_prime_x = f_prime(x0);

        if (fabs(fx) < epsilon) {
            printf("Aproximacao da raiz encontrada: %lf\n", x0);
            break;
        }

        if (f_prime_x == 0) {
            printf("A derivada se tornou zero. Não eh possivel continuar.\n");
            break;
        }

        x0 = x0 - fx / f_prime_x;
    }

    if (iter == max_iter) {
        printf("Numero maximo de iteracoes atingido. A solucao pode nao ter convergido.\n");
    }

    return 0;
}
