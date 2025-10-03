#include<stdio.h>
float vetor[2];

//função que retorna o maior salário
float msalario(float *x){
    float maior = x[0];
    for(int i = 0; i < 2; i++){
        if(x[i] > maior){
           maior = vetor[i];
        }
    }
    return maior;  
}
int main(void){
    float salario;
    //armazena os valores no vetor
    for(int i = 0; i < 2; i++){
        printf("Digite o salario %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }
    //chama a função que retorna o maior salário e printa o resultado
    float resultado = msalario(vetor);
    printf("O maior salario e: %.2f\n", resultado);
}