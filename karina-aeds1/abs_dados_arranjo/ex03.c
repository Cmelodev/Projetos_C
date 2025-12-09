int Pesquisar(TipoLista *L, int x) {
    for (int i = L->Primeiro; i < L->Ultimo; i++) {
        if (L->Item[i].valor == x) {
            return i; 
        }
    }
    return -1; 
}

// Menu
case 7:
    printf("Digite o valor a pesquisar: ");
    scanf("%d", &x);
    pos = Pesquisar(&Lista, x);
    if (pos != -1) printf("Elemento encontrado na posicao %d\n", pos);
    else printf("Elemento nao encontrado\n");
    break;
