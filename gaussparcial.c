#include <stdio.h>

#define MAX_SIZE 10

// Função para imprimir a matriz
void printMatrix(double matrix[MAX_SIZE][MAX_SIZE + 1], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para resolver o sistema de equações por Gauss simples
void gaussSimple(double matrix[MAX_SIZE][MAX_SIZE + 1], int size) {
    for (int i = 0; i < size; i++) {
        double pivot = matrix[i][i];
        for (int j = 0; j <= size; j++) {
            matrix[i][j] /= pivot;
        }
        for (int k = 0; k < size; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j <= size; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int size;
    printf("Digite a ordem da matriz quadrada (máx %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Ordem inválida.\n");
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE + 1];

    printf("Digite os elementos da matriz (linha por linha):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Matriz original:\n");
    printMatrix(matrix, size);

    gaussSimple(matrix, size);

    printf("Matriz reduzida:\n");
    printMatrix(matrix, size);

    printf("Soluções:\n");
    for (int i = 0; i < size; i++) {
        printf("x%d = %8.3f\n", i + 1, matrix[i][size]);
    }

    return 0;
}
