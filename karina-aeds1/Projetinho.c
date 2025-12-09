#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#define InicioArranjo 1 
#define Maxtam 5

typedef int apontador ;

typedef struct 
{
   int cod;
   int idade;
}TipoItem;

typedef struct 
{
TipoItem item[Maxtam];
apontador Primeiro;
apontador Ultimo;
}TipoLista;

TipoLista Lista ;
TipoItem x;
apontador pos;

void FLVazia (TipoLista *Lista)
{
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = InicioArranjo;
}

int Vazia (TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista * Lista){
    if (Lista -> Ultimo > Maxtam){
        printf("\n A Lista esta cheia!\n");
    }
    else{
        Lista -> item[Lista -> Ultimo -1] = x;
        Lista ->Ultimo = Lista -> Ultimo +1; 
    }

}

void Imprime(TipoLista Lista){
int aux; 
for (aux = Lista.Primeiro - 1; aux <= (Lista.Ultimo - 2); aux = aux +1){
    printf("Cod: %d\n Idade: %d\n\n\n", Lista.item[aux].cod, Lista.item[aux].idade);
}
}
void Procurar(TipoItem x, TipoLista Lista){
    int i, encontrou = 0;
    for (i = Lista.Primeiro -1; i <= Lista.Ultimo -2; i = i + 1){
        if (Lista.item[i].cod == x.cod){
        encontrou = 1;
        printf("Codigo encontrado na posicao: %d\n", i);
        break;
        }
    }

}

int main (){

    int opcao ,resposta;
    setlocale(LC_ALL, "");
     FLVazia(&Lista);
    do 
    {
        printf("\n\nMenu\n\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Lista\n");
        printf("2 - Verificar se a Lista esta vazia\n");
        printf("3 - Inserir o elemento da Lista\n");
        printf("4 - Imprimir os elementos da Lista\n");
        printf("5 - Pesquisar elemento da Lista\n");
        printf("Digite a opcao desejada :\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 0:
                printf("Encerrando o programa...\n");
                break;

            case 1:
                FLVazia(&Lista);
                printf("Lista esvaziada com sucesso!\n");
                break;

            case 2:
                resposta = Vazia(Lista);
                if (resposta == 1){
                    printf("A Lista esta vazia!\n");
                }
                else{
                    printf("A Lista nao esta vazia!\n");
                }
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;

            case 3:{
                printf("digite o codigo\n");
                scanf("%d", &x.cod);
                printf("Digite a idade\n");
                scanf("%d", &x.idade);
                Insere(x, &Lista);
                break;
            }

            case 4:{
                Imprime(Lista);
                break;
            }
        }
        _getch();
        system("cls");
    }while(opcao != 0);
    return 0;
}