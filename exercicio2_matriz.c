/*
    Exercicio 2 - Funcao que recebe uma matriz, conta pares e impares,
    e retorna a quantidade do que tiver mais ocorrencias.
*/

#include <stdio.h>

int contarMaior(int matriz[][100], int linhas, int colunas) {
    int pares = 0;
    int impares = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] % 2 == 0)
                pares++;
            else
                impares++;
        }
    }

    if (pares >= impares)
        return pares;
    else
        return impares;
}

int main() {
    int linhas, colunas;

    printf("Quantas linhas tem a matriz? ");
    scanf("%d", &linhas);
    printf("Quantas colunas? ");
    scanf("%d", &colunas);

    int matriz[100][100];

    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("  [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int resultado = contarMaior(matriz, linhas, colunas);
    printf("\nA maior quantidade de ocorrencias (pares ou impares) eh: %d\n", resultado);

    return 0;
}

/*
    Exemplo de execucao:

    Matriz 3x3:
    | 2  5  8 |
    | 3  4  7 |
    | 6  1  9 |

    Pares: 2, 8, 4, 6 -> 4 numeros
    Impares: 5, 3, 7, 1, 9 -> 5 numeros
    Resultado: 5 (impares tem mais ocorrencias)
*/
