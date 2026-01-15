#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#define InicioArranjo 1
#define Maxtam 5

typedef int apontador;

typedef struct{

    char nome[30];
    int idade;
    char telefone[15];
}dados;

typedef struct{
    dados item[Maxtam];
    apontador Primeiro;
    apontador Ultimo;
}tipolista;

tipolista Pessoa;
dados x;
apontador pos;

// manipulando valores da lista
int main(){
    strcpy(Pessoa.item[0].nome, "Joao");
    Pessoa.item[0].idade = 20;
    strcpy(Pessoa.item[0].telefone, "3312345678");
    


    // acrescentando valores na lista sem criar funcoes
    for (int i = 1; i < 4; i++){
        printf("Digite o nome: ");
        scanf("%s", Pessoa.item[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &Pessoa.item[i].idade);
        printf("Digite o telefone: ");
        scanf("%s", Pessoa.item[i].telefone);
    }

    // imprimindo valores da lista
    for (int j = 0; j < 4; j++){
        printf("Nome: %s\nidade: %d \ntelefone: %s \n", Pessoa.item[j].nome, Pessoa.item[j].idade, Pessoa.item[j].telefone);
    }
}

