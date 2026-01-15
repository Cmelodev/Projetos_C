#include<stdio.h>
float a, b;

// cria a função pra ler os valores
void LerNotas(){
    printf("Digite dois numeros: ");
    scanf("%f %f", &a, &b);
    
}
int main(void){
    // chama as função
    a = 1;
    b = 1;
    LerNotas();
    float media = (a + b) / 2;
    printf("A media e: %.1f\n", media);
}