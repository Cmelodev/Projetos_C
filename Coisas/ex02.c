#include<stdio.h>

//função que retorna a soma de dois números
int soma(int a, int b){
    return (a + b);
}

int main(void){
    //parâmetros primos
    int x = 3, y = 5;
    int resultado = soma(x, y);
    // imprime o resultado
    printf("A soma de %d e %d e: %d\n", x, y, resultado);
}