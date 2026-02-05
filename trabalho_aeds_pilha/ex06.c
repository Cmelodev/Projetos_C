#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MaxTam 12

typedef int Apontador;


typedef struct{
    int cod;
    int idade;
} TipoItem;


typedef struct{
    TipoItem item[MaxTam];
    Apontador topo;
} TipoPilha;


void FPVazia(TipoPilha *p){
    p->topo = 0;
}


void Empilha_Pilha(TipoPilha *p, TipoItem x){
    p->item[p->topo] = x;
    p->topo++;
}


void Exibir_Pilha(TipoPilha *p){
    if (p->topo == 0){
        printf("Pilha vazia!\n");
    } else{
        for (int i = p-> topo - 1; i >= 0; i--){
            printf("Cod: %d | Idade: %d\n", p->item[i].cod, p->item[i].idade);
        }
    }
}

void Verifica(TipoPilha *p, TipoPilha *par, TipoPilha *impar){
    if (p->topo == 0){
        printf("Pilha vazia!\n");
    } else{
        for (int i = 0; i < p->topo; i++){
            if (p->item[i].idade % 2 == 0){
                Empilha_Pilha(par, p->item[i]);
            } else{
                Empilha_Pilha(impar, p->item[i]);
            }
        }
    }
}

int main(){
    TipoPilha Pilha, Impar, Par;
    TipoItem x;
    int opcao = 0;

    FPVazia(&Pilha);
    FPVazia(&Impar);
    FPVazia(&Par);

    do {
        printf("Menu: \n");
        printf("1 - Empilhar valor \n2 - Exibir valores \n3 - Verificar pares e impares \n0 - Sair\n");
        printf("Qual sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
            printf("Digite o cod: ");
            scanf("%d", &x.cod);
            printf("Digite a idade: ");
            scanf("%d", &x.idade);
            Empilha_Pilha(&Pilha, x);
            break;

            case 2:
            printf("Pilha: \n");
            Exibir_Pilha(&Pilha);
            break;

            case 3:
            printf("Verificando pares e impares: \n");
            Verifica(&Pilha, &Par, &Impar);
            printf("Pares: \n");
            Exibir_Pilha(&Par);
            printf("Impares: \n");
            Exibir_Pilha(&Impar);

            break;

            case 0:
            printf("Encerrando programa...\n");
            break;

            default:
                printf("Opcao invalida");
                break;
        }

    } while (opcao != 0);
    return 0;
}

