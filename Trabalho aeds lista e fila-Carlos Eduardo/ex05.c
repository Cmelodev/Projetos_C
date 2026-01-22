#include<stdio.h>
#include<stdlib.h>

#define InicioArranjo 1
#define maxtam 10

typedef int apontador;

typedef struct{
    int valores;
} Valores;

typedef struct{
    Valores dados[maxtam];
    apontador primeiro;
    apontador ultimo;
} ListaValores;

void vazia(ListaValores *ListaValores){
    ListaValores->primeiro = InicioArranjo;
    ListaValores->ultimo = InicioArranjo;
}

void MaiorMenor(ListaValores *ListaValores, float *maior, float *menor){
    if (ListaValores->ultimo == ListaValores->primeiro){
        printf("A lista esta vazia!\n");
    } else{
        for (int c = ListaValores->primeiro; c < ListaValores->ultimo; c++){
            if (c == ListaValores->primeiro){
                *maior = ListaValores->dados[c-1].valores;
                *menor = ListaValores->dados[c-1].valores;
            } else{
                if (ListaValores->dados[c-1].valores > *maior){
                    *maior = ListaValores->dados[c-1].valores;
                }
                if (ListaValores->dados[c-1].valores < *menor){
                    *menor = ListaValores->dados[c-1].valores;
                }
            }
        }
    }
}

void Media(ListaValores *listaValores){
    float soma = 0.0;
    int quantidade = listaValores->ultimo - listaValores->primeiro;

    for (int i = listaValores->primeiro - 1; i < listaValores->ultimo - 1; i++){
        soma += listaValores->dados[i].valores;
    }

    if (quantidade > 0){
        float media = soma / quantidade;
        printf("Media dos valores: %.2f\n", media);
    } else {
        printf("A lista esta vazia!\n");
    }
}

void preencher_lista(ListaValores *ListaValores){
    int valor;
    while (ListaValores->ultimo - ListaValores->primeiro < maxtam){
        printf("Digite dez valores. Valor inteiro %d: ", ListaValores->ultimo - ListaValores->primeiro + 1);
        scanf("%d", &valor);
        if (valor == -1){
            break;
        }
        ListaValores->dados[ListaValores->ultimo - 1].valores = valor;
        ListaValores->ultimo++;
    }
}

int main(){
    ListaValores ListaValores;
    vazia(&ListaValores);

    preencher_lista(&ListaValores);

    float maior, menor;
    MaiorMenor(&ListaValores, &maior, &menor);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);

    Media(&ListaValores);

    return 0;
}