#include <stdio.h>

#define MAX 20

typedef struct {
    int dados[MAX];
    int *primeiro;
    int *ultimo;
} Fila;

void inicializarFila(Fila *f) {
    f->primeiro = f->dados;
    f->ultimo = f->dados;
}

int filaVazia(Fila *f) {
    return f->primeiro == f->ultimo;
}

int filaCheia(Fila *f) {
    return f->ultimo == f->dados + MAX;
}

void adicionarCliente(Fila *f, int senha) {
    if (filaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }

    *(f->ultimo) = senha;
    printf("Cliente adicionado. Senha: %d\n", senha);
    f->ultimo++;
}

void atenderCliente(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Atendendo cliente senha: %d\n", *(f->primeiro));

    for (int *p = f->primeiro; p < f->ultimo - 1; p++) {
        *p = *(p + 1);
    }

    f->ultimo--;
}

void proximoCliente(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Proximo cliente: %d\n", *(f->primeiro));
}

int main() {
    Fila fila;
    int opcao;
    int senha = 1;

    inicializarFila(&fila);

    do {
        printf("\n1 - Adicionar cliente");
        printf("\n2 - Atender cliente");
        printf("\n3 - Mostrar proximo");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarCliente(&fila, senha);
                senha++;
                break;
            case 2:
                atenderCliente(&fila);
                break;
            case 3:
                proximoCliente(&fila);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
