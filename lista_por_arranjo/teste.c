#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#define InicioArranjo 1 
#define Maxtam 5

typedef int apontador;

typedef struct 
{
   int cod;
   int idade;
}tipoitem;

typedef struct 
{
tipoitem item[Maxtam];
apontador Primeiro;
apontador Ultimo;
}tipolista;

tipolista Lista;
tipoitem x;
apontador pos;

void FLVazia (tipolista * Lista)
{
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = InicioArranjo;
}

int Vazia (tipolista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void insere (tipoitem x, tipolista *Lista)
{
    if (Lista->Ultimo > Maxtam)
    {
        printf("Erro: Lista cheia\n");
        return;
    }
    Lista->item[Lista->Ultimo -1] = x;
    Lista->Ultimo++;
}

void imprime (tipolista Lista)
{
    int aux;
    for (aux = Lista.Primeiro-1; aux < Lista.Ultimo-2; aux++)
    {
        printf("Codigo: %d\n", Lista.item[aux -1].cod);
        printf("Idade: %d\n", Lista.item[aux -1].idade);
    }
    
}

int main (){

    int opcao ,resposta;
    setlocale(LC_ALL, "");
    FLVazia(&Lista);
    do 
    {
        printf("\nMenu\n");
        printf("\n0 = Sair");
        printf("\n1 = Esvaziar lista");
        printf("\n2 = Verificar se a lista esta vazia");
        printf("\n3 = Inserir elemento na lista");
        printf("\n4 = imprimir os elemntos da lista");
        printf("\nDigite a opcao desejada : ");
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
                if (resposta == 1)
                {
                    printf("A lista esta vazia!\n");
                }
                else
                {
                    printf("A lista nao esta vazia!\n");
                }
                break;
            case 3:
                {
                    printf("Digite o codigo: ");
                    scanf("%d",&x.cod);
                    printf("Digite a idade: ");
                    scanf("%d",&x.idade);
                    insere(x, &Lista);
                    break;
                }
            case 4:
            {
                imprime(Lista);
                break;
            }
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        _getch();
        system("cls");
    }while(opcao != 0);
    return 0;
}
