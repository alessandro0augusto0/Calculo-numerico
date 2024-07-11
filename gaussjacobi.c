#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void SolucaoGaussJacobi(int ordem, float matriz[ordem][ordem], float vetIndependente[ordem], float erro, float vetInicial[ordem], float resultado[ordem], int interacoes);

int main()
{
    int i, j, ordem, k, interacoes;
    printf("Digite a dimensao do Sistema linear (sem o termo independente): ");
    scanf("%i", &ordem);

    while (ordem <= 0)
    {
        printf("Valor invalido!\n");
        printf("Por favor, digite novamente a dimensao do Sistema linear (sem o termo independente): ");
        scanf("%i", &ordem);
    }

    float matriz[ordem][ordem], vetIndependente[ordem], resultado[ordem], vetInicial[ordem], resultadoGaussJacobi[ordem];
    float erro;

    for (i = 0; i < ordem; i++)
    {
        printf("\n");
        for (j = 0; j < ordem; j++)
        {
            printf("Digite o valor do Sistema Linear na posicao [%i] [%i]:", i, j);
            scanf("%f", &matriz[i][j]);
        }
        printf("Digite o termo independente da %ia equacao: ", i + 1);
        scanf("%f", &vetIndependente[i]);
    }

    printf("\t\t ###### A MATRIZ Eh: ###### \n");
    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf(" %.2f", matriz[i][j]);
        }
        printf(" = %.2f", vetIndependente[i]);
        printf("\n");
    }

    printf("\t #####Muito bem, voce escolheu o metodo Interativo Gauss-Jacobi ##### \n");
    printf("Entre com a solucao inicial: ");
    for (k = 0; k < ordem; k++)
        scanf("%f", &vetInicial[k]);

    printf("\n Entre com a margem de erro: ");
    scanf("%f", &erro);

    printf("\n Entre com maximo de interacoes desejada: ");
    scanf("%i", &interacoes);

    SolucaoGaussJacobi(ordem, matriz, vetIndependente, erro, vetInicial, resultadoGaussJacobi, interacoes);

    printf("O conjunto solucao eh: S:{ ");
    for (i = 0; i < ordem; i++)
        printf("%.2f ", resultadoGaussJacobi[i]);
    printf("}\n\n");

    return 0;
}

void SolucaoGaussJacobi(int ordem, float matriz[ordem][ordem], float vetIndependente[ordem], float erro, float vetInicial[ordem], float resultado[ordem], int interacoes)
{
    int i, j, cont = 0, k;
    float soma, auxR[ordem];

    for (k = 0; k < ordem; k++)
        resultado[k] = vetInicial[k];

    while (cont < interacoes)
    {
        for (k = 0; k < ordem; k++)
            auxR[k] = resultado[k];

        for (i = 0; i < ordem; i++)
        {
            soma = 0;
            for (j = 0; j < ordem; j++)
            {
                if (i != j)
                    soma += matriz[i][j] * resultado[j];
            }
            resultado[i] = (vetIndependente[i] - soma) / matriz[i][i];
        }

        float max_erro = fabs(resultado[0] - auxR[0]);

        for (i = 1; i < ordem; i++)
        {
            float diff = fabs(resultado[i] - auxR[i]);
            if (diff > max_erro)
                max_erro = diff;
        }

        if (max_erro < erro)
            break;

        cont++;
    }
}
