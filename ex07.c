#include<stdio.h>

//função que calcula a área do quadrado
float areaquadrado(float x){
    return (x * x);
}

float areacirculo(float r){
    return (3.14 * (r * r));
}
int main(void){
    float lado, raio;
    printf("Digite o valor do lado do quadrado: ");
    scanf("%f", &lado);
    float resultado = areaquadrado(lado);
    printf("Entre o valor do raio do circulo: ");
    scanf("%f", &raio);
    float resultado2 = areacirculo(raio);
 
    //imprime os resultados
    printf("A area do quadrado e: %.2f\n", resultado);
    printf("A area do circulo e: %.2f\n", resultado2);
}