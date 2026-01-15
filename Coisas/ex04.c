#include<stdio.h>
#include<math.h>

//função que calcula a hipotenusa
float hipotenusa(float cat1, float cat2){
    return (sqrt((cat1 * cat1)) + (cat2 * cat2));
}

int main(void){
    float a, b;
    printf("Digite o valor do cateto 1: ");
    scanf("%f", &a);
    printf("Digite o valor do cateto 2: ");
    scanf("%f", &b);
    float resultado = hipotenusa(a, b);
    //imprime o resultado
    printf("O valor da hipotenusa e: %.2f\n", resultado);
}