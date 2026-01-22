#include <stdio.h>

#define MAX 20

typedef struct {
    int dados[MAX];
    int *inicio;
    int *fim;
    int total;
    int senhaAtual;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = f->dados;
    f->fim = f->dados;
    f->total = 0;
    f->senhaAtual = 1;
}

void adicionarCliente(Fila *f) {
    if (f->total == MAX) {
        printf("Fila cheia!\n");
        return;
    }

    *(f->fim) = f->senhaAtual++;
    printf("Cliente adicionado. Senha: %d\n", *(f->fim));

    f->fim++;
    if (f->fim == f->dados + MAX) {
        f->fim = f->dados;
    }

    f->total++;
}

void atenderCliente(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Atendendo cliente senha: %d\n", *(f->inicio));

    f->inicio++;
    if (f->inicio == f->dados + MAX) {
        f->inicio = f->dados;
    }

    f->total--;
}

void proximoCliente(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Proximo cliente: %d\n", *(f->inicio));
}

int main() {
    Fila fila;
    int opcao;

    inicializarFila(&fila);

    do {
        printf("\n1 - Adicionar cliente");
        printf("\n2 - Atender cliente");
        printf("\n3 - Mostrar proximo");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarCliente(&fila); break;
            case 2: atenderCliente(&fila); break;
            case 3: proximoCliente(&fila); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
