#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define LINHA_MAX 256
#define MAX_PESSOAS 1000 // Limite de pessoas que podemos guardar de uma vez

typedef struct{
    int codigo;
    char nome[TAM_NOME];
} Pessoa;

// Regras para ajudar a decidir quem vem primeiro na hora de organizar
int compara_codigo(const Pessoa *a, const Pessoa *b){
    return a->codigo - b->codigo;
}

int compara_nome(const Pessoa *a, const Pessoa *b){
    return strcmp(a->nome, b->nome);
}

// Junta duas partes da lista que já estão arrumadas
void merge(Pessoa v[], Pessoa aux[], int ini, int meio, int fim,
           int (*cmp)(const Pessoa *, const Pessoa *)){
    int i = ini, j = meio + 1, k = ini;

    while (i <= meio && j <= fim){
        if (cmp(&v[i], &v[j]) <= 0) // O "<=" evita trocar de lugar quem já estava na ordem certa
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim)  aux[k++] = v[j++];

    for (k = ini; k <= fim; k++)
        v[k] = aux[k];
}

// Vai quebrando a lista pela metade até ficar fácil de organizar
void merge_sort(Pessoa v[], Pessoa aux[], int ini, int fim,
                int (*cmp)(const Pessoa *, const Pessoa *)){
    if (ini >= fim) return;

    int meio = ini + (fim - ini) / 2;
    merge_sort(v, aux, ini, meio, cmp);
    merge_sort(v, aux, meio + 1, fim, cmp);
    merge(v, aux, ini, meio, fim, cmp);
}

void ordenar(Pessoa v[], int n, int (*cmp)(const Pessoa *, const Pessoa *)){
    // Espaço de rascunho temporário para ajudar a montar a ordem final
    Pessoa aux[MAX_PESSOAS]; 
    merge_sort(v, aux, 0, n - 1, cmp);
}

void imprimir(const Pessoa v[], int n, const char *titulo){
    printf("%s\n", titulo);
    for (int i = 0; i < n; i++)
        printf("[%2d] (%2d) %s\n", i, v[i].codigo, v[i].nome);
    printf("\n");
}

// Pega os dados do arquivo texto e joga pra dentro da nossa lista
void ler_arquivo(const char *caminho, Pessoa v[], int *n){
    FILE *f = fopen(caminho, "r");
    if (f == NULL){
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char linha[LINHA_MAX];
    *n = 0;
    while (fgets(linha, sizeof(linha), f) != NULL){
        if (*n >= MAX_PESSOAS){
            fprintf(stderr, "Aviso: Atingiu o limite maximo de pessoas (%d).\n", MAX_PESSOAS);
            break;
        }

        int codigo, pos = 0;
        if (sscanf(linha, "%d %n", &codigo, &pos) < 1)
            continue; // Pula as linhas vazias ou bagunçadas

        char *nome = linha + pos;
        nome[strcspn(nome, "\r\n")] = '\0'; // Limpa o enter

        v[*n].codigo = codigo;
        strncpy(v[*n].nome, nome, TAM_NOME - 1);
        v[*n].nome[TAM_NOME - 1] = '\0';
        (*n)++;
    }
    fclose(f);
}

int main(int argc, char *argv[]){
    const char *arquivo = (argc > 1) ? argv[1] : "familia.txt";
    
    Pessoa familia[MAX_PESSOAS]; // Declara o vetor
    int n = 0;
    
    ler_arquivo(arquivo, familia, &n);

    imprimir(familia, n, "Pessoas da familia na ordem lida do arquivo texto:");

    ordenar(familia, n, compara_codigo);
    imprimir(familia, n, "Pessoas da familia em ordem de codigo:");

    ordenar(familia, n, compara_nome);
    imprimir(familia, n, "Pessoas da familia em ordem de nome:");

    return 0;
}