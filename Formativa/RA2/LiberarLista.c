#include <stdlib.h>

typedef struct Planeta Planeta;
struct Planeta{
    char nome[16];
    double raio;
    double distancia_do_sol;
    Planeta* proximo;
};

void liberar(Planeta* p){
    while (p != NULL){
        Planeta* auxiliar = p->proximo;
        free(p);
        p = auxiliar;
    }
}

int main(){
    Planeta* L = NULL;

    Planeta* terra = (Planeta*) malloc(sizeof(Planeta));
    terra->proximo = NULL;
    L = terra;

    Planeta* venus = (Planeta*) malloc(sizeof(Planeta));
    venus->proximo = NULL;
    terra->proximo = venus;

    liberar(L);

    return 0;
}