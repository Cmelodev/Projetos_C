#include<stdio.h>

//função que não retorna valor
int operaao1(int a, int b){
    printf("%d + %d = %d\n", a, b, (a + b));
}
//função que retorna valor
int operacao2(int a, int b){
    return (a + b);
}
int main(void){
    int x = 3, y = 5;
    //chama a função que não retorna valor
    operaao1(x, y);
    //chama a função que retorna valor
    int resultado = operacao2(x, y);
    printf("A soma de %d e %d e: %d\n", x, y, resultado);
}