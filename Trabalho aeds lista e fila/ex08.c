#include <stdio.h>

#define MAX 20

typedef struct {
    int dados[MAX];
    int total;
    int senhaAtual;
} Fila;

void inicializarFila(Fila *f) {
    f->total = 0;
    f->senhaAtual = 1;
}

void adicionarCliente(Fila *f) {
    if (f->total == MAX) {
        printf("Fila cheia!\n");
        return;
    }

    f->dados[f->total] = f->senhaAtual++;
    printf("Cliente adicionado. Senha: %d\n", f->dados[f->total]);
    f->total++;
}

void atenderCliente(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Atendendo cliente senha: %d\n", f->dados[0]);

    for (int i = 0; i < f->total - 1; i++) {
        f->dados[i] = f->dados[i + 1];
    }

    f->total--;
}

void proximoCliente(Fila *f) {
    if (f->total == 0) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Proximo cliente: %d\n", f->dados[0]);
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
