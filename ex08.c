#include<stdio.h>

//função aumento salario
float aumento(float x, float y){
    return (x + (x * y / 100));
}
int main(void){
    float salario, perc;
    printf("Digite o salario: ");
    scanf("%f", &salario);
    printf("Digite o percentual de aumento: ");
    scanf("%f", &perc);
    float resultado = aumento(salario, perc);
    //imprime o resultado
    printf("O novo salario e: %.2f\n", resultado);
}