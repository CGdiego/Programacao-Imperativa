#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct{
    int codigo;
    double altura;
    char nome[TAM_NOME];
} Pessoa;

typedef struct{
    Pessoa *v;
    int n;
    int cap;
} Lista;

typedef struct No{
    int pos;
    struct No *esq, *dir;
} No;

typedef int (*Comparador)(const Pessoa *a, const Pessoa *b);

int cmp_codigo(const Pessoa *a, const Pessoa *b){
    return (a->codigo > b->codigo) - (a->codigo < b->codigo);
}

int cmp_altura(const Pessoa *a, const Pessoa *b){
    if(a->altura != b->altura)
        return a->altura > b->altura ? 1 : -1;

    return cmp_codigo(a, b);
}

void erro(const char *msg){
    fprintf(stderr, "Erro: %s\n", msg);
    exit(1);
}

void lista_add(Lista *l, Pessoa p){
    if(l->n == l->cap){
        l->cap = l->cap ? l->cap * 2 : 8;
        l->v = realloc(l->v, l->cap * sizeof(Pessoa));
        if(!l->v)
            erro("Sem memoria");
    }
    l->v[l->n++] = p;
}

void limpa(char *s){
    char *ini = s;
    size_t len;

    while(*ini == ' ' || *ini == '\t')
        ini++;

    memmove(s, ini, strlen(ini) + 1);
    len = strlen(s);
    while(len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r' || s[len - 1] == ' '))
        s[--len] = '\0';
}

void le_arquivo(const char *caminho, Lista *l){
    FILE *f = fopen(caminho, "r");
    char linha[256];
    int num = 0;

    if(!f)
        erro("Nao consegui abrir o arquivo");

    while(fgets(linha, sizeof(linha), f)){
        Pessoa p;
        int lidos, usados;

        num++;
        if(!strchr(linha, '\n') && !feof(f)){
            int c;
            fprintf(stderr, "Linha %d muito longa, descartada\n", num);
            while((c = fgetc(f)) != '\n' && c != EOF);
            continue;
        }
        lidos = sscanf(linha, "%d %lf %n", &p.codigo, &p.altura, &usados);
        if(lidos == EOF)
            continue;

        if(lidos < 2){
            fprintf(stderr, "Linha %d ignorada (formato invalido)\n", num);
            continue;
        }
        strncpy(p.nome, linha + usados, TAM_NOME - 1);
        p.nome[TAM_NOME - 1] = '\0';
        limpa(p.nome);
        if(p.nome[0] == '\0'){
            fprintf(stderr, "Linha %d ignorada (sem nome)\n", num);
            continue;
        }
        lista_add(l, p);
    }
    fclose(f);
}

void imprime_pessoa(int i, const Pessoa *p){
    printf("[%2d] (%2d) (%.1f) %s\n", i, p->codigo, p->altura, p->nome);
}

void imprime_lista(const Lista *l){
    for(int i = 0; i < l->n; i++)
        imprime_pessoa(i, &l->v[i]);
}

No *insere(No *raiz, int pos, const Lista *l, Comparador cmp){
    if(!raiz){
        No *novo = malloc(sizeof(No));
        if(!novo)
            erro("Sem memoria");

        novo->pos = pos;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if(cmp(&l->v[pos], &l->v[raiz->pos]) < 0)
        raiz->esq = insere(raiz->esq, pos, l, cmp);
    else
        raiz->dir = insere(raiz->dir, pos, l, cmp);

    return raiz;
}

No *cria_arvore(const Lista *l, Comparador cmp){
    No *raiz = NULL;

    for(int i = 0; i < l->n; i++)
        raiz = insere(raiz, i, l, cmp);

    return raiz;
}

void imprime_arvore(const No *raiz, const Lista *l, int *cont){
    if(!raiz)
        return;

    imprime_arvore(raiz->esq, l, cont);
    imprime_pessoa((*cont)++, &l->v[raiz->pos]);
    imprime_arvore(raiz->dir, l, cont);
}

void libera_arvore(No *raiz){
    if(!raiz)
        return;

    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

int main(int argc, char *argv[]){
    Lista familia = {NULL, 0, 0};
    No *t1, *t2;
    int cont;

    le_arquivo(argc > 1 ? argv[1] : "familia.txt", &familia);

    printf("Pessoas da familia na ordem lida do arquivo texto:\n");
    imprime_lista(&familia);

    t1 = cria_arvore(&familia, cmp_codigo);
    printf("Pessoas da familia em ordem de codigo:\n");
    cont = 0;
    imprime_arvore(t1, &familia, &cont);

    t2 = cria_arvore(&familia, cmp_altura);
    printf("Pessoas da familia em ordem de altura:\n");
    cont = 0;
    imprime_arvore(t2, &familia, &cont);

    libera_arvore(t1);
    libera_arvore(t2);
    free(familia.v);
    return 0;
}