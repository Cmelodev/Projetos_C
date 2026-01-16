#include<stdio.h>
#include<stdlib.h>
#define InicioArranjo 1
#define maxtam 100

typedef int apontador;

typedef struct{
    float nota;
} Aluno;

typedef struct{
    Aluno dados[maxtam];
    apontador primeiro;
    apontador ultimo;
} ListaAlunos;

ListaAlunos ListaATT;

void inicializaLista(ListaAlunos *ListaATT){
    ListaATT->primeiro = InicioArranjo;
    ListaATT->ultimo = InicioArranjo;
}

void InserirNota(ListaAlunos *ListaATT, float x){
    if (ListaATT->ultimo > maxtam){
        printf("A lista esta cheia");
    } else{
        ListaATT->dados[ListaATT->ultimo - 1].nota = x;
        ListaATT->ultimo++;
    }
}

void RemoverNota(ListaAlunos *ListaATT, int indice){
    if (indice < ListaATT->primeiro - 1 || indice >= ListaATT->ultimo){
        printf("Indice invalido!\n");
    } else {
        for (int i = ListaATT->primeiro - 1; i < ListaATT->ultimo - 1; i++){
            if (i == indice - 1){
                for (int j = i; j < ListaATT->ultimo - 1; j++){
                    ListaATT->dados[j] = ListaATT->dados[j + 1];
                }
            }
        }
        ListaATT->ultimo--;
        printf("Nota removida com sucesso!\n");
    }
    
}

void Media(ListaAlunos *ListaATT){
    float soma = 0.0;
    int quantidade = ListaATT->ultimo - ListaATT->primeiro;

    for (int i = ListaATT->primeiro - 1; i < ListaATT->ultimo - 1; i++){
        soma += ListaATT->dados[i].nota;
    }

    if (quantidade > 0){
        float media = soma / quantidade;
        printf("Media das notas: %.2f\n", media);
    } else {
        printf("Nenhuma nota para calcular a media.\n");
    }
}

float maior = 0;
float menor = 0;

void MaiorMenor(ListaAlunos *ListaATT, float *maior, float *menor){
    if (ListaATT->ultimo == ListaATT->primeiro){
        printf("A lista esta vazia!\n");
        return;
    }

    for (int c = ListaATT->primeiro; c < ListaATT->ultimo; c++){
        if (c == ListaATT->primeiro){
            *maior = ListaATT->dados[c-1].nota;
            *menor = ListaATT->dados[c-1].nota;
        } else{
            if (ListaATT->dados[c-1].nota > *maior){
                *maior = ListaATT->dados[c-1].nota;
            }
            if (ListaATT->dados[c-1].nota < *menor){
                *menor = ListaATT->dados[c-1].nota;
            }
        }
    }
}

int main(){
    int opcao;
    float nota, indice;
    inicializaLista(&ListaATT);
    do{
        printf("\n");
        printf("1 - Inserir nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Calcular media\n");
        printf("4 - Maior e menor nota\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite a nota a ser inserida: ");
                scanf("%f", &nota);
                InserirNota(&ListaATT, nota);
                break;
            case 2:
                for(int c = ListaATT.primeiro - 1; c < ListaATT.ultimo - 1; c++){
                    printf("Indice %d: Nota %.2f\n", c, ListaATT.dados[c].nota);
                }
                printf("Digite o indice da nota a ser removida: ");
                scanf("%d", &indice);
                RemoverNota(&ListaATT, indice);
                break;
            case 3:
                Media(&ListaATT);
                break;
            case 4:
                MaiorMenor(&ListaATT, &maior, &menor);
                printf("Maior nota: %.2f\n", maior);
                printf("Menor nota: %.2f\n", menor);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
    return 0;
}