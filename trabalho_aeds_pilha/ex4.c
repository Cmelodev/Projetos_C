#include <stdio.h>
#define MaxTam 10

typedef int Apontador;

typedef struct {
    int cod;
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


void ordenar_pilha(TipoPilha *p){
    TipoPilha aux;
    TipoItem temp;

    FPVazia(&aux);

    while (p->topo > 0){
        temp = p->item[p->topo - 1];
        p->topo--;

        while (aux.topo > 0 && aux.item[aux.topo - 1].cod < temp.cod){
            p->item[p->topo] = aux.item[aux.topo - 1];
            p->topo++;
            aux.topo--;
        }

        aux.item[aux.topo] = temp;
        aux.topo++;
    }

    while (aux.topo > 0){
        p->item[p->topo] = aux.item[aux.topo - 1];
        p->topo++;
        aux.topo--;
    }
}


void exibir(TipoPilha *p){
    if (p->topo == 0){
        printf("Pilha vazia!\n");
        return;
    }

    for (int i = p->topo - 1; i >= 0; i--){
        printf("Cod: %d  Valor: %d\n", p->item[i].cod, p->item[i].valor);
    }
}

int main(){
    TipoPilha original;
    TipoItem x;
    int opcao;

    FPVazia(&original);

    do {
        printf("\nMENU\n");
        printf("1 - Empilhar valor\n");
        printf("2 - Ordenar Pilha \n");
        printf("3 - Exibir pilha \n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Digite o codigo: ");
                scanf("%d", &x.cod);
                printf("Digite o valor: ");
                scanf("%d", &x.valor);
                empilhar(&original, x);
                break;

            case 2:
                ordenar_pilha(&original);
                printf("Pilha Ordenada");
                break;

            case 3:
                printf("Pilha: \n");
                exibir(&original);
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
