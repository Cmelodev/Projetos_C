#include <stdio.h>
#define MAX 11

typedef int apontador;

typedef struct {
    int dados[MAX];
    apontador primeiro;
    apontador ultimo;
} ListaOrdenada;

void inicializar(ListaOrdenada *lista) {
    lista->primeiro = 0;
    lista->ultimo = 0;
}

void inserir(ListaOrdenada *lista, int valor) {
    if (lista->ultimo >= MAX) {
        printf("Lista cheia\n");
        return;
    }

    int i = lista->ultimo - 1;

    while (i >= 0 && lista->dados[i] > valor) {
        lista->dados[i + 1] = lista->dados[i];
        i--;
    }

    lista->dados[i + 1] = valor;
    lista->ultimo++;
}

void imprimir(ListaOrdenada lista) {
    for (int i = 0; i < lista.ultimo; i++) {
        printf("%d ", lista.dados[i]);
    }
    printf("\n");
}

int main() {
    ListaOrdenada lista;
    inicializar(&lista);

    for (int i = 0; i < MAX; i++) {
        int valor;
        printf("Digite o %d valor: ", i + 1);
        scanf("%d", &valor);
        inserir(&lista, valor);
    }

    imprimir(lista);
    return 0;
}
