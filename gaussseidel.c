#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min_ordem 100

void mensagem(int p)
{
    switch (p)
    {
    case 1:
        printf("\n Gauss Seidel \n\n");
        break;
    case 2:
        printf("A Diagonal Principal nao pode ser Zero\n");
        break;
    case 3:
        printf("Digite Novamente: ");
        break;
    case 4:
        printf(" Deseja Criar uma matriz Interativa [S/n]?: ");
        break;
    case 5:
        printf(" Método de Gauss Seidel (S) ou Jacobi (J) ?: ");
        break;
    }
}

void criar_matriz_a(int ordem, float matriz_a[][min_ordem])
{
    int i, j;
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("Digite um valor para a posicao[%d][%d]: ", i, j);
            scanf("%f", &matriz_a[i][j]);

            if (i == j && matriz_a[i][j] == 0)
            {
                do
                {
                    mensagem(2);
                    printf("\n");
                    mensagem(3);
                    scanf("%f", &matriz_a[i][j]);
                } while (matriz_a[i][j] == 0);
            }
        }
    }
}

void criar_matriz_b(int ordem, float matriz_b[])
{
    int i;
    for (i = 0; i < ordem; i++)
    {
        printf("Valor para a posicao [%d]: ", i);
        scanf("%f", &matriz_b[i]);
    }
}

void criar_matriz_inicial(int ordem, float matriz_x[])
{
    int i;
    for (i = 0; i < ordem; i++)
    {
        printf("Matriz Inicial posicao [%d]: ", i);
        scanf("%f", &matriz_x[i]);
    }
}

void visualizar_matriz_aumentada(int ordem, float matriz_a[][min_ordem], float matriz_b[])
{
    int i, j;
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%.2f ", matriz_a[i][j]);
        }
        printf("| %.2f\n", matriz_b[i]);
    }
}

void gauss_seidel(int ordem, float matriz_a[][min_ordem], float matriz_b[], float matriz_x[], float tolerancia)
{
    float valorDeX[min_ordem] = {0};
    float x_nova[min_ordem] = {0};
    float somarLinhaX[min_ordem] = {0};
    float distancia = 0;
    int interacao = 0;

    do
    {
        int i, j;
        float somarLinha;
        for (i = 0; i < ordem; i++)
        {
            somarLinha = 0;
            for (j = 0; j < ordem; j++)
            {
                if (j == i)
                {
                    matriz_a[i][j] = matriz_a[i][j];
                }
                else
                {
                    float primeiroCalculo = ((-1) * (matriz_a[i][j]) * (matriz_x[j]));
                    matriz_a[i][j] = primeiroCalculo;
                    somarLinha += matriz_a[i][j];
                }
            }
            somarLinhaX[i] = somarLinha;
            valorDeX[i] = ((1 / matriz_a[i][i]) * (matriz_b[i] + somarLinhaX[i]));
            somarLinha = 0;
            x_nova[i] = valorDeX[i];
        }
        interacao += 1;

        printf(" --------------- Iteracao: %d ---------------\n", interacao);
        for (int k = 0; k < ordem; k++)
        {
            printf("x[%d] = 1/%.1f * (%.1f + (%.1f)) ) = %.1f \n", k, matriz_a[k][k], matriz_b[k], somarLinhaX[k], valorDeX[k]);
        }

        distancia = 0;

        for (int m = 0; m < ordem; m++)
        {
            matriz_x[m] = x_nova[m];
        }

    } while (tolerancia < distancia);
}

int main()
{
    mensagem(1);

    int ordem;

    printf("Qual a ordem da matriz que vc deseja criar? *obs: Maior ou igual a 2: ");
    scanf("%d", &ordem);

    if (ordem >= 2)
    {
        float matriz_a[min_ordem][min_ordem];
        float matriz_b[min_ordem];
        float matriz_x[min_ordem];
        float tolerancia;

        criar_matriz_a(ordem, matriz_a);
        criar_matriz_b(ordem, matriz_b);
        criar_matriz_inicial(ordem, matriz_x);

        printf("Defina um valor para a Tolerancia (EPSILON): ");
        scanf("%f", &tolerancia);

        printf("Sua matriz Aumentada está da seguinte maneira\n");
        visualizar_matriz_aumentada(ordem, matriz_a, matriz_b);

        printf("Utilizando o método de Gauss Seidel, você conseguiu fazer essas iteracoes\n");
        gauss_seidel(ordem, matriz_a, matriz_b, matriz_x, tolerancia);
    }

    printf(" --> Obrigado <--\n");

    return 0;
}