#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* anterior;
    struct No* proximo;
} No;

void inserir_ordenado(No** head, int valor){
    No *novo = (No*) malloc(sizeof(No)), *atual;

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (*head == NULL){
        *head = novo;
        return;
    }

    if (valor < (*head)->valor){
        novo->proximo = *head;
        (*head)->anterior = novo;
        *head = novo;
        return;
    }

    atual = *head;
    while (atual->proximo != NULL && atual->proximo->valor < valor)
        atual = atual->proximo;

    novo->proximo = atual->proximo;
    novo->anterior = atual;
    if (atual->proximo != NULL)
        atual->proximo->anterior = novo;
    atual->proximo = novo;
}

int main(){
    FILE* arq = fopen("numeros.txt", "r");
    No *head = NULL, *aux;
    int num;

    if (arq == NULL)
        return 1;

    while (fscanf(arq, "%d", &num) == 1)
        inserir_ordenado(&head, num);
    fclose(arq);

    aux = head;
    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    putchar('\n');

    while (head != NULL){
        aux = head->proximo;
        free(head);
        head = aux;
    }

    return 0;
}