#include<stdio.h>

//função calcular o valor de y
int y(int f, int g){
    return (f) +  (g);
}

//funçãpo calcular o valor de h(x)
int h(int m){
    return ((m * m) - 16);
}

//função calcular o valor de f(x)
int f(int x){
    if (x >= 0){
        return x;
    }
    else if (x < 0){
        return 1;
        }
}
//função calcular o valor de g(x)
int g(int x, int y){
    if (x == 0){
        return ((y * y) + 16);
    }
    else if(x > 0){
        return 0;
        }
}

int main(void){
    int x = 0;
    printf("De o valor de x: ");
    scanf("%d", &x);
    //armazena os valores em variáveis
    int valor_h = h(x);
    int valor_f = f(valor_h);
    int valor_g = g(valor_f, x);
    int resultado = y(valor_f, valor_g);
    //imprime o resultado
    printf("O resultado e: %d\n", resultado);
}