#include <stdio.h>
#include <string.h>
#include "Lista.h"

void inicializar(Lista* lista) {
    lista->quantidade = 0;
}

int buscar(Lista* lista, char placa[]) {
    for (int i = 0; i < lista->quantidade; i++)
        if (strcmp(lista->itens[i].placa, placa) == 0)
            return i;
    return -1;
}

int inserir(Lista* lista, Veiculo v) {
    if (lista->quantidade >= MAX_VEICULOS) {
        printf("Erro: Lista cheia! Nao e possivel inserir mais veiculos.\n");
        return 0;
    }
    if (buscar(lista, v.placa) != -1) {
        printf("Aviso: Veiculo com placa %s ja cadastrado.\n", v.placa);
        return 0;
    }

    int i = lista->quantidade - 1;
    while (i >= 0 && strcmp(lista->itens[i].placa, v.placa) > 0) {
        lista->itens[i + 1] = lista->itens[i];
        i--;
    }
    lista->itens[i + 1] = v;
    lista->quantidade++;
    return 1;
}

int remover(Lista* lista, char placa[]) {
    int pos = buscar(lista, placa);
    if (pos == -1) {
        printf("Veiculo com placa %s nao encontrado.\n", placa);
        return 0;
    }

    for (int i = pos; i < lista->quantidade - 1; i++)
        lista->itens[i] = lista->itens[i + 1];
    
    lista->quantidade--;
    printf("Veiculo com placa %s removido com sucesso.\n", placa);
    return 1;
}

void imprimir_veiculo(Veiculo v) {
    printf("Placa: %-8s | Marca: %-15s | Modelo: %-15s | Ano: %d\n",
           v.placa, v.marca, v.modelo, v.ano);
}

void listar(Lista* lista) {
    if (lista->quantidade == 0) {
        printf("A lista de veiculos esta vazia.\n");
        return;
    }
    printf("\n--- LISTAGEM DE VEICULOS (%d cadastrados) ---\n", lista->quantidade);
    for (int i = 0; i < lista->quantidade; i++) {
        printf("%2d. ", i + 1);
        imprimir_veiculo(lista->itens[i]);
    }
    printf("----------------------------------------------\n");
}

int carregar_texto(Lista* lista, char nome_arquivo[]) {
    FILE* arq = fopen(nome_arquivo, "r");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo %s para leitura.\n", nome_arquivo);
        return 0;
    }

    char linha[150];
    int num_linha = 0;
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        num_linha++;
        int pos = strcspn(linha, "\r\n");
        linha[pos] = '\0';

        if (pos == 0)
            continue; 

        Veiculo v;
        if (sscanf(linha, "%7[^;];%29[^;];%29[^;];%d", v.placa, v.marca, v.modelo, &v.ano) == 4)
            inserir(lista, v);
        else
            printf("Aviso: linha %d ignorada por formato invalido.\n", num_linha);
    }

    fclose(arq);
    return 1;
}

int gravar_texto(Lista* lista, char nome_arquivo[]) {
    FILE* arq = fopen(nome_arquivo, "w");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo %s para escrita.\n", nome_arquivo);
        return 0;
    }

    for (int i = 0; i < lista->quantidade; i++)
        fprintf(arq, "%s;%s;%s;%d\n",
                lista->itens[i].placa,
                lista->itens[i].marca,
                lista->itens[i].modelo,
                lista->itens[i].ano);

    fclose(arq);
    return 1;
}

int carregar_binario(Lista* lista, char nome_arquivo[]) {
    FILE* arq = fopen(nome_arquivo, "rb");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo binario %s para leitura.\n", nome_arquivo);
        return 0;
    }

    Veiculo v;
    while (fread(&v, sizeof(Veiculo), 1, arq) == 1) {
        if (lista->quantidade >= MAX_VEICULOS) {
            printf("Aviso: limite atingido, restante do arquivo ignorado.\n");
            break;
        }
        lista->itens[lista->quantidade] = v;
        lista->quantidade++;
    }

    fclose(arq);
    return 1;
}

int gravar_binario(Lista* lista, char nome_arquivo[]) {
    FILE* arq = fopen(nome_arquivo, "wb");
    if (arq == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo binario %s para escrita.\n", nome_arquivo);
        return 0;
    }

    int gravados = fwrite(lista->itens, sizeof(Veiculo), lista->quantidade, arq);
    fclose(arq);

    if (gravados != lista->quantidade) {
        printf("Erro: falha ao gravar os dados em %s.\n", nome_arquivo);
        return 0;
    }
    return 1;
}