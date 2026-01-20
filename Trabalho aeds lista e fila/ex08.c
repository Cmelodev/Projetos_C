#include <stdio.h>

#define MAX 20

int fila[MAX];
int inicio = 0, fim = 0, total = 0;
int senhaAtual = 1;

void adicionarCliente() {
    if (total == MAX) {
        printf("Fila cheia!\n");
        return;
    }
    fila[fim] = senhaAtual++;
    fim = (fim + 1) % MAX;
    total++;
    printf("Cliente adicionado. Senha: %d\n", fila[(fim - 1 + MAX) % MAX]);
}

void atenderCliente() {
    if (total == 0) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Atendendo cliente senha: %d\n", fila[inicio]);
    inicio = (inicio + 1) % MAX;
    total--;
}

void proximoCliente() {
    if (total == 0) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Proximo cliente: %d\n", fila[inicio]);
}

int main() {
    int opcao;

    do {
        printf("\n1 - Adicionar cliente");
        printf("\n2 - Atender cliente");
        printf("\n3 - Mostrar proximo");
        printf("\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarCliente(); break;
            case 2: atenderCliente(); break;
            case 3: proximoCliente(); break;
        }
    } while (opcao != 0);

    return 0;
}
