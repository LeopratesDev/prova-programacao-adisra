/*
    Exercicio 1 - Sequencia de Fibonacci
    O usuario digita uma posicao e o programa retorna
    o numero de Fibonacci correspondente.
    Exemplo: posicao 6 -> resultado 8 (0,1,1,2,3,5,8)
*/

#include <stdio.h>

int fibonacci(int posicao) {
    if (posicao == 0) return 0;
    if (posicao == 1) return 1;

    int anterior = 0;
    int atual = 1;
    int proximo;

    for (int i = 2; i <= posicao; i++) {
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    return atual;
}

int main() {
    int posicao;

    printf("Digite a posicao desejada na sequencia de Fibonacci: ");
    scanf("%d", &posicao);

    if (posicao < 0) {
        printf("Erro: a posicao deve ser um numero positivo.\n");
        return 1;
    }

    int resultado = fibonacci(posicao);
    printf("O numero na posicao %d da sequencia de Fibonacci eh: %d\n", posicao, resultado);

    return 0;
}

/*
    Exemplo de execucao:

    Digite a posicao desejada na sequencia de Fibonacci: 6
    O numero na posicao 6 da sequencia de Fibonacci eh: 8

    Sequencia: 0, 1, 1, 2, 3, 5, 8
    Posicao:   0  1  2  3  4  5  6
*/
