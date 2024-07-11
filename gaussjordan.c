#include <stdio.h>
#include <math.h>

#define N 3

void printMatrix(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        printf("Passo %d:\n", i + 1);
        printMatrix(matrix);

        double pivot = matrix[i][i];
        for (int j = i; j <= N; j++) {
            matrix[i][j] /= pivot;
        }

        for (int j = i + 1; j < N; j++) {
            double factor = matrix[j][i];
            for (int k = i; k <= N; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            double factor = matrix[j][i];
            for (int k = i; k <= N; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
}

int main() {
    double matrix[N][N + 1];

    printf("Digite os elementos da matriz ampliada (linha por linha):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Matriz original:\n");
    printMatrix(matrix);

    gaussJordan(matrix);

    printf("Resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i, matrix[i][N]);
    }

    return 0;
}
