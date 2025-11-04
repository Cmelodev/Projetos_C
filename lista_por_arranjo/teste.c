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
}tipoitem;

typedef struct 
{
tipoitem item[Maxtam];
apontador Primeiro;
apontador Ultimo;
}tipolista;

tipolista lista ;
tipoitem x;
apontador pos;

void FLVazia (tipolista *Lista)
{
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = InicioArranjo;
}

int Vazia (tipolista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

int main (){

    int opcao ,resposta;
    setlocale(LC_ALL, "");
    // FLVazia(&lista);
    do 
    {
        printf("\n\nMenu\n\n");
        printf("\n0 = Sair");
        printf("\n1 = Esvaziar lista");
        printf("\n2 = Verificar se a lista esta vazia");
        printf("Digite a opcao desejada : ");
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1:
                // FLVazia(&lista);
                printf("Lista esvaziada com sucesso!\n");
                break;
            case 2:
                // resposta = Vazia(lista);
                if (resposta == 1)
                {
                    printf("A lista esta vazia!\n");
                }
                else
                {
                    printf("A lista nao esta vazia!\n");
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
