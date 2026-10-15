#ifndef LISTA_H
#define LISTA_H

#define MAX_VEICULOS 100

typedef struct {
    char placa[8];
    char marca[30];
    char modelo[30];
    int ano;
} Veiculo;

typedef struct {
    Veiculo itens[MAX_VEICULOS];
    int quantidade;
} Lista;

void inicializar(Lista* lista);
int inserir(Lista* lista, Veiculo v);
int remover(Lista* lista, char placa[]);
int buscar(Lista* lista, char placa[]);
void imprimir_veiculo(Veiculo v);
void listar(Lista* lista);

int carregar_texto(Lista* lista, char nome_arquivo[]);
int gravar_texto(Lista* lista, char nome_arquivo[]);
int carregar_binario(Lista* lista, char nome_arquivo[]);
int gravar_binario(Lista* lista, char nome_arquivo[]);

#endif