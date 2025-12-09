#include <stdio.h>

int main() {
    char respostas[5];
    int sim = 0;

    printf("Telefonou para a vitima? (s/n) ");
    scanf(" %c", &respostas[0]);

    printf("Esteve no local do crime? (s/n) ");
    scanf(" %c", &respostas[1]);

    printf("Mora perto da vitima? (s/n) ");
    scanf(" %c", &respostas[2]);

    printf("Devia para a vitima? (s/n) ");
    scanf(" %c", &respostas[3]);

    printf("Ja trabalhou com a vitima? (s/n) ");
    scanf(" %c", &respostas[4]);

    for (int i = 0; i < 5; i++)
        if (respostas[i] == 's' || respostas[i] == 'S')
            sim++;

    if (sim == 2) printf("Classificacao: Suspeita\n");
    else if (sim == 3 || sim == 4) printf("Classificacao: Cumplice\n");
    else if (sim == 5) printf("Classificacao: Assassino\n");
    else printf("Classificacao: Inocente\n");

    return 0;
}
