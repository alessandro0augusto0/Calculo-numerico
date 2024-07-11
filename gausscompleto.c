#include <stdio.h>
#include <stdlib.h>

void swapRows(double **matrix, int row1, int row2, int n) {
    for (int i = 0; i <= n; i++) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void printMatrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussianElimination(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        printf("Passo %d:\n", i + 1);

        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (matrix[j][i] > matrix[maxRow][i]) {
                maxRow = j;
            }
        }
        if (maxRow != i) {
            swapRows(matrix, i, maxRow, n);
            printf("Troca das linhas %d e %d:\n", i + 1, maxRow + 1);
            printMatrix(matrix, n);
        }

        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
            printf("Eliminacao da linha %d usando a linha %d com fator %.2f:\n", j + 1, i + 1, factor);
            printMatrix(matrix, n);
        }
    }
}

int main() {
    int n;
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc((n + 1) * sizeof(double));
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("\nMatriz inicial:\n");
    printMatrix(matrix, n);

    gaussianElimination(matrix, n);

    printf("\nMatriz triangular:\n");
    printMatrix(matrix, n);

    double solutions[n];
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solutions[i] -= matrix[i][j] * solutions[j];
        }
        solutions[i] /= matrix[i][i];
    }

    printf("\nSolucao:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i, solutions[i]);
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
