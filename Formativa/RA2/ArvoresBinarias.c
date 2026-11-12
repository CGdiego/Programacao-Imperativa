#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo Nodo;
struct Nodo{
    char nome[45];
    int count;
    Nodo* esquerda;
    Nodo* direita;
};

Nodo* raiz = NULL;

int inserir(Nodo** no, char* nome){
    if (*no == NULL){
        Nodo* novo_no = (Nodo*) malloc(sizeof(Nodo));
        strcpy(novo_no->nome, nome);
        novo_no->count = 1;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
        *no = novo_no;
        return 0;
    }

    int cmp = strcmp(nome, (*no)->nome);

    if (cmp == 0){
        int atual = (*no)->count;
        (*no)->count++;
        return atual;
    }
    else if (cmp < 0)
        return inserir(&((*no)->esquerda), nome);
    else
        return inserir(&((*no)->direita), nome);
}

int main(){
    int n;
    char nome[45];
    char novo_nome[45];

    scanf("%d", &n);

    while (n--){
        scanf("%s", nome);
        int res = inserir(&raiz, nome);
        
        if (res == 0) {
            printf("OK\n");
        } 
        else {
            while (1) {
                sprintf(novo_nome, "%s%d", nome, res);

                int check = inserir(&raiz, novo_nome);

                if (check == 0) {
                    printf("%s\n", novo_nome);
                    break;
                }
                
                res++;
            }
        }
    }
    
    return 0;
}