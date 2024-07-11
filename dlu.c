#include <stdio.h>
#include <stdlib.h>

#define n 3
 
void show_matrix(float (*mat)[n]){
    int i,j;
    for(i=0;i<n;i++){
        printf("|");
        for(j=0;j<n;j++){
            printf(" %.2f",mat[i][j]);
        }
        printf(" |\n");
    }    
}
 
void read_matrix(float (*mat)[n]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Digite o valor da posicao A[%d][%d]=",i+1,j+1);
            scanf("%f",&mat[i][j]);
        }
    }
}
 
void gauss(float(*mat)[n]){
    
    int i,j;
    float M[n][n],aux[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j]=0;
            aux[i][j]=mat[i][j]; 
        }
    }
    printf("\n***Seja Aux, uma matriz auxiliar como copia da matriz A***\n");
    printf("----Matriz aux antes----\n");
    show_matrix(aux);
   
    for(j=0;j<n;j++){      
        printf("\n***Multiplicadores de Gauss da %d coluna***\n",j+1);
        for(i=j+1;i<n;i++){
            if(aux[i][j]==0)
            {
                printf("Posicao ja e 0, nao ha necessidade de fazer eliminacao de gauss para este termo!\n");
            }else
             {
                M[i][j]=aux[i][j]/aux[j][j];
                printf("M[%d][%d]=%.2f\n",i+1,j+1,M[i][j]);
                int c=0;
               
                for(c=j;c<n;c++){
                    printf("\n----Multiplicando a %dx%d por %.2f----\n",j+1,c+1,-1*M[i][j]);              
                    show_matrix(aux);
                    printf("\n***Fazendo %.2f * %.2f = %.2f***\n",aux[j][c],-1*M[i][j],aux[j][c]*(-1*(M[i][j])));
                    printf("***Fazendo %.2f + %.2f = %.2f*** POS[%d][%d]\n",aux[j][c]*(-1*(M[i][j])),aux[i][c],aux[i][c]+aux[j][c]*(-1*(M[i][j])),i+1,c+1);
                    aux[i][c]=aux[i][c]+aux[j][c]*(-1*(M[i][j]));
               
                    printf("\n----Matriz aux depois----\n");    
                    show_matrix(aux);
                }      
            }      
            printf("\n");
        }
             
    }
    printf("\n\nRESULTADO FINAL\n");
    for(i=0;i<n;i++) M[i][i]=1;
    printf("\n----Matriz L----\n");
    show_matrix(M);
   
    printf("\n----Matriz U----\n");
    show_matrix(aux);
   
}
 
int main(){
    float A[n][n];
    float M[n][n];
   
    read_matrix(A);
    printf("***Seja A a matriz original***\n");
    printf("----Matriz A----\n");
    show_matrix(A);
   
    gauss(A);
   
   
    system("pause");
    return 0;  
}