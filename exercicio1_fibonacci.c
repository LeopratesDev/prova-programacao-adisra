#include <stdio.h>

// funcao pra calcular fibonacci na posicao que o usuario pedir
int fibonacci(int pos){
    int a = 0, b = 1, temp, i;

    if(pos == 0) return 0;
    if(pos == 1) return 1;

    for(i = 2; i <= pos; i++){
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(){
    int n, resultado;

    printf("Informe a posicao: ");
    scanf("%d", &n);

    if(n < 0){
        printf("Posicao invalida!\n");
        return 1;
    }

    resultado = fibonacci(n);
    printf("Fibonacci na posicao %d = %d\n", n, resultado);

    return 0;
}
