#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>
#define InicioArranjo 1
#define maxtam 4

typedef int apontador;

typedef struct{
    int modelos;
    float consumo;
} Moto;

typedef struct{
    Moto Moto_dados[maxtam];
    apontador primeiro;
    apontador ultimo;
} ListaMotos;

ListaMotos Motos;

void insereMoto(ListaMotos *Motos, int modelo, float consumo){
    if(Motos->ultimo < maxtam){
        Motos->Moto_dados[Motos->ultimo].modelos = modelo;
        Motos->Moto_dados[Motos->ultimo].consumo = consumo;
        Motos->ultimo++;
    } else {
        printf("Lista cheia!\n");
    }
}

void inicializaLista(ListaMotos *Motos){
    Motos->primeiro = InicioArranjo - 1;
    Motos->ultimo = InicioArranjo - 1;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    inicializaLista(&Motos);

    insereMoto(&Motos, 1, 25.5);
    insereMoto(&Motos, 2, 30.0);
    insereMoto(&Motos, 3, 22.3);

    //a)
    printf("Modelo de Moto mais economicos na lista:\n");
    float MaisEconomico;
    for(int i = Motos.primeiro; i < Motos.ultimo; i++){
        if (i == Motos.primeiro){
            MaisEconomico = Motos.Moto_dados[i].consumo;
        } else {
            if(Motos.Moto_dados[i].consumo < MaisEconomico){
                MaisEconomico = Motos.Moto_dados[i].consumo;
            }
        }
    }
    printf("Consumo mais economico: %.2f km/l\n", MaisEconomico);
    getch();

    //b)
    for(int i = Motos.primeiro; i < Motos.ultimo; i++){
        float CalculoConsumo = 100 / Motos.Moto_dados[i].consumo;
        printf("A Moto %d consome para percorrer 100 km e de %.2f L\n", Motos.Moto_dados[i].modelos, CalculoConsumo);
    }
}