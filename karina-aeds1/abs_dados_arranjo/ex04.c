#include <stdio.h>

int main() {
    int notas[1000], n = 0, x;
    int soma = 0;

    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        notas[n++] = x;
    }

    // a
    printf("Quantidade lida: %d\n", n);

    // b
    printf("Valores na ordem informada: ");
    for (int i = 0; i < n; i++)
        printf("%d ", notas[i]);
    printf("\n");

    // c
    printf("Valores na ordem inversa:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d\n", notas[i]);

    // d
    for (int i = 0; i < n; i++)
        soma += notas[i];
    printf("Soma: %d\n", soma);

    // e
    float media = soma / (float)n;
    printf("Media: %.2f\n", media);

    // f
    int acima = 0;
    for (int i = 0; i < n; i++)
        if (notas[i] > media) acima++;
    printf("Acima da media: %d\n", acima);

    // g
    int abaixo7 = 0;
    for (int i = 0; i < n; i++)
        if (notas[i] < 7) abaixo7++;
    printf("Abaixo de 7: %d\n", abaixo7);

    // h
    printf("Programa encerrado.\n");

    return 0;
}
