#include<stdio.h>
//vetor com 4 elementos
float vetor[4] = {2.5, 10, 50, 120};

//funcão que retorna a metade dos valores do vetor
void metade(float * x)
{
    for(int i = 0; i < 4; i++){
        x[i] = x[i] / 2;
        printf("A metade do valor %.2f e: %.2f\n", vetor[i] * 2, x[i]);
    }
}

int main(void){
    metade(vetor);
    }