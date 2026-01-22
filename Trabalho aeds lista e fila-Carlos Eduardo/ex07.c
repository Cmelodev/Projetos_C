#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *valores;
    int capacidade;
    int primeiro;
    int ultimo;
} Fila;

void inicializaFila(Fila *f, int tamInicial) {
    f->capacidade = tamInicial;
    f->valores = (int*) malloc(tamInicial * sizeof(int));
    f->primeiro = 0;
    f->ultimo = 0;
}

int filaCheia(Fila *f) {
    return f->ultimo == f->capacidade;
}

void dobraFila(Fila *f) {
    f->capacidade *= 2;
    f->valores = (int*) realloc(f->valores, f->capacidade * sizeof(int));
}

void enqueue(Fila *f, int valor) {
    if (filaCheia(f)) {
        dobraFila(f);
    }
    f->valores[f->ultimo] = valor;
    f->ultimo++;
}

int dequeue(Fila *f) {
    if (f->primeiro == f->ultimo) {
        return -1;
    }
    return f->valores[f->primeiro++];
}

void imprimeFila(Fila *f) {
    for (int i = f->primeiro; i < f->ultimo; i++) {
        printf("%d ", f->valores[i]);
    }
    printf("\n");
}

int main() {
    Fila f;

    inicializaFila(&f, 5);

    for (int i = 1; i <= 15; i++) {
        enqueue(&f, i);
    }

    imprimeFila(&f);

    return 0;
}
