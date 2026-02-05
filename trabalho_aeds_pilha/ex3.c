#include <stdio.h>
#define MaxTam 10

typedef int Apontador;

typedef struct {
    int valor;
} TipoItem;

typedef struct {
    TipoItem item[MaxTam];
    Apontador topo;
} TipoPilha;

void FPVazia(TipoPilha *p){
    p->topo = 0;
}

void empilhar(TipoPilha *p, TipoItem x){
    if (p->topo == MaxTam){
        printf("Pilha cheia!\n");
    } else {
        p->item[p->topo] = x;
        p->topo++;
    }
}

void dividir_pilha(TipoPilha *origem, TipoPilha *p1, TipoPilha *p2){
    TipoItem aux;

    FPVazia(p1);
    FPVazia(p2);

    while (origem->topo > 0){
        aux = origem->item[origem->topo - 1];
        origem->topo--;

        if (aux.valor % 2 == 0){
            empilhar(p1, aux);
        } else {
            empilhar(p2, aux);
        }
    }

    printf("Pilha dividida com sucesso!\n");
}

void exibir(TipoPilha *p){
    if (p->topo == 0){
        printf("Pilha vazia!\n");
        return;
    }

    for (int i = p->topo - 1; i >= 0; i--){
        printf("Valor: %d\n", p->item[i].valor);
    }
}

int main(){
    TipoPilha original, pares, impares;
    TipoItem x;
    int opcao;

    FPVazia(&original);
    FPVazia(&pares);
    FPVazia(&impares);

    do {
        printf("\nMENU\n (ps: pilha com maximo de %d elementos)\n", MaxTam);
        printf("1 - Empilhar valor\n");
        printf("2 - Exibir pilha original\n");
        printf("3 - dividir e exibir resultado da divisão (pares / impares)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &x.valor);
                empilhar(&original, x);
                break;

            case 2:
                printf("Pilha original:\n");
                exibir(&original);
                break;

            case 3:
                dividir_pilha(&original, &pares, &impares);
                printf("Pilha 1: (pares) \n");
                exibir(&pares);
                printf("Pilha 2: (impares)\n");
                exibir(&impares);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
