#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_LINHA 256

typedef struct Pessoa {
    int codigo;
    char nome[MAX_NOME];
    struct Pessoa *prox;
} Pessoa;

typedef int (*Comparador)(const Pessoa *, const Pessoa *);

/* ---------- Comparadores ---------- */
int cmpCodigo(const Pessoa *a, const Pessoa *b) {
    return a->codigo - b->codigo;
}

int cmpNome(const Pessoa *a, const Pessoa *b) {
    return strcmp(a->nome, b->nome);
}

/* ---------- Leitura do arquivo ---------- */
Pessoa *lerFamilia(const char *caminho) {
    FILE *f = fopen(caminho, "r");
    if (!f) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    Pessoa *cabeca = NULL, *cauda = NULL;
    char linha[MAX_LINHA];

    while (fgets(linha, sizeof linha, f)) {
        int codigo, lidos = 0;
        char nome[MAX_NOME];

        /* %n guarda quantos caracteres foram consumidos pelo codigo */
        if (sscanf(linha, "%d%n", &codigo, &lidos) != 1) continue;

        char *p = linha + lidos;
        while (*p == ' ' || *p == '\t') p++;          /* pula espacos */
        strncpy(nome, p, MAX_NOME - 1);
        nome[MAX_NOME - 1] = '\0';
        nome[strcspn(nome, "\r\n")] = '\0';           /* remove quebra de linha */

        Pessoa *nova = malloc(sizeof(Pessoa));
        if (!nova) {
            fprintf(stderr, "Erro de memoria\n");
            exit(1);
        }
        nova->codigo = codigo;
        strcpy(nova->nome, nome);
        nova->prox = NULL;

        if (!cabeca) cabeca = cauda = nova;
        else { cauda->prox = nova; cauda = nova; }
    }

    fclose(f);
    return cabeca;
}

/* ---------- Impressao ---------- */
void imprimir(const Pessoa *lista, const char *titulo) {
    printf("%s\n", titulo);
    int i = 0;
    for (const Pessoa *p = lista; p; p = p->prox, i++)
        printf("[%2d] (%2d) %s\n", i, p->codigo, p->nome);
    printf("\n");
}

/* ---------- Merge sort recursivo ---------- */

/* Intercala duas listas ja ordenadas (recursivo, estavel) */
Pessoa *merge(Pessoa *a, Pessoa *b, Comparador cmp) {
    if (!a) return b;
    if (!b) return a;

    if (cmp(a, b) <= 0) {
        a->prox = merge(a->prox, b, cmp);
        return a;
    } else {
        b->prox = merge(a, b->prox, cmp);
        return b;
    }
}

/* Divide a lista em duas metades; devolve o inicio da segunda */
Pessoa *dividir(Pessoa *cabeca) {
    Pessoa *lento = cabeca, *rapido = cabeca->prox;
    while (rapido && rapido->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    Pessoa *segunda = lento->prox;
    lento->prox = NULL;
    return segunda;
}

Pessoa *mergeSort(Pessoa *cabeca, Comparador cmp) {
    if (!cabeca || !cabeca->prox) return cabeca;

    Pessoa *segunda = dividir(cabeca);
    cabeca = mergeSort(cabeca, cmp);
    segunda = mergeSort(segunda, cmp);
    return merge(cabeca, segunda, cmp);
}

/* ---------- Liberacao de memoria ---------- */
void liberar(Pessoa *lista) {
    while (lista) {
        Pessoa *prox = lista->prox;
        free(lista);
        lista = prox;
    }
}

/* ---------- Main ---------- */
int main(int argc, char *argv[]) {
    const char *arquivo = (argc > 1) ? argv[1] : "familia.txt";

    Pessoa *familia = lerFamilia(arquivo);

    imprimir(familia, "Pessoas da família na ordem lida do arquivo texto:");

    familia = mergeSort(familia, cmpCodigo);
    imprimir(familia, "Pessoas da família em ordem de código:");

    familia = mergeSort(familia, cmpNome);
    imprimir(familia, "Pessoas da família em ordem de nome:");

    liberar(familia);
    return 0;
}
