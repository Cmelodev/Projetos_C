#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MaxTam 5

typedef int Apontador;

typedef struct{
    int cod;
    int valor;
} TipoItem;


//Criador da pilha
typedef struct{
    TipoItem item[MaxTam];
    Apontador topo;
} TipoPilha;

TipoPilha Pilha;
TipoItem x;


//inicializador da Pilha
void FPVazia (TipoPilha *Pilha){
    Pilha->topo = 0;
}


//função q empilha fila
int empilhar(TipoPilha *Pilha, TipoItem valor){
    if (Pilha->topo == MaxTam){
        printf("Erro! Pilha cheia");
    }
    else{
        Pilha->item[Pilha->topo] = valor;
        Pilha->topo ++;
    }
}


/função q exibe os codigos na pilha
int exibir_cods(TipoPilha *Pilha){
    for (int i = Pilha->topo -1; i >= 0; i--){
        printf("valores disponiveis: \n");
        printf("Codigo: %d | valor: %d\n", Pilha->item[i].cod, Pilha->item[i].valor);
    }
}


//função q procura codigo na pilha
int procurar_codigo(TipoPilha *pilha, int cod){
    for (int i = pilha->topo - 1; i >= 0; i--){
        if (cod == pilha->item[i].cod){
            printf("Codigo %d encontrado na %d* a ser colocado \n", cod, i + 1);  // meu locale n funciona então coloquei o asterico pra indicar primeiroo, segundo etc.
            return 1;
        }
        printf("Codigo %d nao encontrado na pilha\n", cod);
    }
}



int main(void){
    int escolha = 0;
    int valor = 0;
    FPVazia(&Pilha);
    do{
        printf("Menu \n Escolha uma opcao: \n 0- encerrar \n 1- empilhar valor \n 2- procurar valor \n:  ");
        scanf("%d", &escolha);
        switch (escolha){
            case 1: {
                printf("Qual Valor voce quer acrescentar?: ");
                scanf("%d", &x.valor);
                printf("Qual codigo deseja colocar: ");
                scanf("%d", &x.cod);
                empilhar(&Pilha, x);
                break;
            }
            case 2: {
                exibir_cods(&Pilha);
                if (Pilha.topo == 0){
                printf("Pilha vazia, nao ha codigos para procurar\n");
                }else{
                printf("Qual codigo deseja procurar?: ");
                scanf("%d", &valor);
                procurar_codigo(&Pilha, valor);
                break;
                }
            }

        }
    } while(escolha != 0);
    printf("Programa encerrado!");
    return 0;
}
    