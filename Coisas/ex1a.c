#include<stdio.h>

// cria a função pra ler os valores
void LerNotas(float *n1, float *n2){
    printf("Digite primeiro numero: ");
    scanf("%f", n1);
    printf("Digite o segundo numero: ");
    scanf("%f", n2);
    
}
int main(void){
    // chama as função
    float a, b;
    LerNotas(&a, &b);
    float media = (a + b) / 2;
    printf("A media e: %.1f\n", media);
}