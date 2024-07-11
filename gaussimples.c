#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE + 1], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussSimple(double matrix[MAX_SIZE][MAX_SIZE + 1], int size) {
    for (int i = 0; i < size; i++) {
        double temp = matrix[i][i];
        for (int j = 0; j <= size; j++) {
            matrix[i][j] /= temp;
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
    printf("Digite o tamanho da matriz quadrada (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Tamanho inválido.\n");
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

    printf("Solucao:\n");
    for (int i = 0; i < size; i++) {
        printf("x%d = %8.3f\n", i + 1, matrix[i][size]);
    }

    return 0;
}
