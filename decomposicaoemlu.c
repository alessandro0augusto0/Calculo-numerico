#include <stdio.h>
#include <stdlib.h>

#define n 3
#define m 4

void show_matrix(float (*mat)[m]) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("|");
        for (j = 0; j < m; j++) {
            printf(" %.2f", mat[i][j]);
        }
        printf(" |\n");
    }
}

void read_matrix(float (*mat)[m]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Digite o valor da posicao A[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }
}

void decomposeLU(float (*mat)[m], float (*L)[n], float (*U)[n]) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j < i) {
                L[j][i] = 0;
            } else {
                L[j][i] = mat[j][i];
                for (k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
            }

            if (j < i) {
                U[i][j] = 0;
            } else if (j == i) {
                U[i][j] = 1;
            } else {
                U[i][j] = mat[i][j];
                for (k = 0; k < i; k++) {
                    U[i][j] -= (L[i][k] * U[k][j]);
                }
                U[i][j] /= L[i][i];
            }
        }
    }
}

void solveLU(float (*L)[n], float (*U)[n], float b[n], float x[n]) {
    float y[n];

    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i];
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main() {
    float A[n][m], L[n][n], U[n][n];
    float b[n], x[n];

    printf("Digite a matriz A:\n");
    read_matrix(A);

    printf("Digite o vetor b:\n");
    for (int i = 0; i < n; i++) {
        printf("Digite o valor de b[%d] = ", i + 1);
        scanf("%f", &b[i]);
    }

    decomposeLU(A, L, U);
    solveLU(L, U, b, x);

    printf("Resultado:\n");
    printf("x: %.2f\n", x[0]);
    printf("y: %.2f\n", x[1]);
    printf("z: %.2f\n", x[2]);

    return 0;
}
