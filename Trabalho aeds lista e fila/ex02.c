#include <stdio.h>

#define MAX 100
#define InicioArranjo 0

typedef int apontador;

typedef struct {
    int valores[MAX];
    apontador primeiro;
    apontador ultimo;
} Lista;

void inicializaLista(Lista *L) {
    L->primeiro = InicioArranjo;
    L->ultimo = InicioArranjo;
}

void insereLista(Lista *L, int valor) {
    if (L->ultimo < MAX) {
        L->valores[L->ultimo] = valor;
        L->ultimo++;
    } else {
        printf("Lista cheia!\n");
    }
}

int main() {
    Lista notas;
    Lista *pNotas = &notas;

    int num;
    int soma = 0;
    float media;
    int acimaMedia = 0;
    int abaixoSete = 0;

    inicializaLista(pNotas);

    printf("Digite as notas (-1 para encerrar):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        insereLista(pNotas, num);
    }

    int qtd = pNotas->ultimo - pNotas->primeiro;

    if (qtd == 0) {
        printf("Nenhuma nota foi inserida.\n");
        return 0;
    }

    // a) quantidade 
    printf("\nQuantidade de valores lidos: %d\n", qtd);

    // b) ordem informada 
    printf("Valores na ordem informada: ");
    for (int i = pNotas->primeiro; i < pNotas->ultimo; i++) {
        printf("%d ", pNotas->valores[i]);
        soma += pNotas->valores[i];
    }
    printf("\n");

    // c) ordem inversa 
    printf("Valores na ordem inversa:\n");
    for (int i = pNotas->ultimo - 1; i >= pNotas->primeiro; i--) {
        printf("%d\n", pNotas->valores[i]);
    }

    // d) soma 
    printf("Soma dos valores: %d\n", soma);

    // e) media 
    media = (float)soma / qtd;
    printf("media dos valores: %.2f\n", media);

    // f) acima da media 
    for (int i = pNotas->primeiro; i < pNotas->ultimo; i++) {
        if (pNotas->valores[i] > media)
            acimaMedia++;
    }
    printf("Quantidade acima da media: %d\n", acimaMedia);

    // g) abaixo de 7 
    for (int i = pNotas->primeiro; i < pNotas->ultimo; i++) {
        if (pNotas->valores[i] < 7)
            abaixoSete++;
    }
    printf("Quantidade abaixo de 7: %d\n", abaixoSete);

    // h) mensagem de encerramento 
    printf("Programa encerrado com sucesso!\n");
    return 0;
}
