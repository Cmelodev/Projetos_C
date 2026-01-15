#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>
#define InicioArranjo 1
#define maxtam 5

typedef int apontador;

typedef struct{
    char nome[30];
    int cod;
} dados;

typedef struct{
    dados dados_p[maxtam];
    apontador primeiro;
    apontador ultimo;
}tipolista;

tipolista Funcionarios;

void insere(tipolista *lista){
    for(int c = 0; c < maxtam; c++){
        printf("Digite o nome do funcionario: ");
        scanf("%s", lista->dados_p[c].nome);
        lista->dados_p[c].cod = c;
    }
}

void imprime(tipolista *lista){
    for (int j = 0; j < 4; j++){
        printf("Nome: %s\ncod %d\n", lista->dados_p[j].nome, lista->dados_p[j].cod);
    }
}

void Busca_lista(tipolista *lista){
    
}
//main

int main(void){
    insere(&Funcionarios);
    imprime(&Funcionarios);
}