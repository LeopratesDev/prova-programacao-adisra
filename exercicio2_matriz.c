#include <stdio.h>

#define MAX 100

// conta pares e impares e retorna a qtd maior
int contaMaiorOcorrencia(int mat[][MAX], int lin, int col){
    int pares = 0, impares = 0;
    int i, j;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            if(mat[i][j] % 2 == 0)
                pares++;
            else
                impares++;
        }
    }

    if(pares > impares)
        return pares;
    else
        return impares;
}

int main(){
    int mat[MAX][MAX];
    int lin, col, i, j, resp;

    printf("Linhas: ");
    scanf("%d", &lin);
    printf("Colunas: ");
    scanf("%d", &col);

    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    resp = contaMaiorOcorrencia(mat, lin, col);
    printf("Maior ocorrencia (par ou impar): %d\n", resp);

    return 0;
}
