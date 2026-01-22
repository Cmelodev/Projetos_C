#include<stdio.h>
#include<stdlib.h>
#define InicioArranjo 0
#define maxtam 5

typedef int apontador;

typedef struct{
    int valores[maxtam];
    apontador primeiro;
    apontador ultimo;
} TipoFila;

typedef struct{
    int valores[10];
    apontador primeiro;
    apontador ultimo;
} TipoFilaFinal;


TipoFila fila1;
TipoFila fila2;
TipoFilaFinal FilaFinal;


void inicializaFila(TipoFila *fila){
    fila->primeiro = InicioArranjo;
    fila->ultimo = InicioArranjo;
}

void preencherFila(TipoFila *fila){
    int x;
    for (int c = 0; c < maxtam;c++){
        printf("Preencher Fila com 5 valores. Valor %d: ", c);
        scanf("%d", &x);
        fila->valores[fila->ultimo] = x;
        fila->ultimo++;
    }
}

void Imprime_Fila(TipoFila *fila){
    if (fila->primeiro == fila->ultimo){
        printf("Error!\n");
    } else{
        for (int c = 0; c < fila->ultimo; c++){
            printf("%d ", fila->valores[c]);
        }
    }
}

void IntercalaFila(TipoFila *fila1, TipoFila *fila2){
    FilaFinal.primeiro = InicioArranjo;
    FilaFinal.ultimo = InicioArranjo;
    for (int c = 0; c < fila1->ultimo; c++){
        FilaFinal.valores[FilaFinal.ultimo] = fila1->valores[c];
        FilaFinal.ultimo++;
        FilaFinal.valores[FilaFinal.ultimo] = fila2->valores[c];
        FilaFinal.ultimo++;
    }
    printf("Fila Final Concatenada: ");
    Imprime_FilaFinal(&FilaFinal);
}

void Imprime_FilaFinal(TipoFilaFinal *fila){
    if (fila->primeiro == fila->ultimo){
        printf("Fila vazia!\n");
    } else {
        for (int c = fila->primeiro; c < fila->ultimo; c++){
            printf("%d ", fila->valores[c]);
        }
        printf("\n");
    }
}

int main(){
    inicializaFila(&fila1);
    inicializaFila(&fila2);

    preencherFila(&fila1);
    printf("\n");
    preencherFila(&fila2);

    printf("Fila 1: ");
    Imprime_Fila(&fila1);
    printf("\n");
    printf("Fila 2: ");
    Imprime_Fila(&fila2);
    printf("\n");

    IntercalaFila(&fila1, &fila2);

    return 0;
}