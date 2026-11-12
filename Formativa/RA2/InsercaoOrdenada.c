#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo Nodo;
struct Nodo{
    int valor;
    Nodo* proximo;
};

Nodo* L = NULL;

void inserir(int valor){
    Nodo* novo_no = (Nodo*) malloc(sizeof(Nodo));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    if (L == NULL) {
        L = novo_no;
    }
    else if (valor < L->valor) {
        novo_no->proximo = L;
        L = novo_no;
    }
    else {
        Nodo* atual = L;
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }
        novo_no->proximo = atual->proximo;
        atual->proximo = novo_no;
    }
}

int main(){
    FILE* texto = fopen("dados.txt", "r");
    if (texto == NULL)
        return 1;

    int valor;

    while (fscanf(texto, "%d", &valor) == 1){
        printf("%d ", valor);
        inserir(valor);
    }
    
    fclose(texto);
    return 0;
}