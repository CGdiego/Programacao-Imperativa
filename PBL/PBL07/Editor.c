#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Lista.h"

int ler_string(char destino[], int tamanho) {
    char buffer[150];
    destino[0] = '\0';
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return 0;
    
    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    buffer[strcspn(buffer, "\r\n")] = '\0';
    strncpy(destino, buffer, tamanho - 1);
    destino[tamanho - 1] = '\0';
    return 1;
}

int ler_placa(char placa[]) {
    char buffer[100];
    ler_string(buffer, sizeof(buffer));
    if (strlen(buffer) != 7) {
        printf("Placa invalida! A placa deve ter exatamente 7 caracteres.\n");
        return 0;
    }
    for (int i = 0; i < 7; i++)
        buffer[i] = toupper(buffer[i]);
    
    strcpy(placa, buffer);
    return 1;
}

int ler_campo(char destino[], int tamanho, char nome[]) {
    printf("%s: ", nome);
    ler_string(destino, tamanho);
    if (strlen(destino) == 0 || strchr(destino, ';') != NULL) {
        printf("%s invalido! Nao pode estar vazio nem conter ';'.\n", nome);
        return 0;
    }
    return 1;
}

int ler_ano(int* ano) {
    char buffer[100];
    printf("Ano: ");
    ler_string(buffer, sizeof(buffer));
    if (sscanf(buffer, "%d", ano) != 1 || *ano < 1900 || *ano > 2030) {
        printf("Ano invalido! Digite um valor entre 1900 e 2030.\n");
        return 0;
    }
    return 1;
}

int opcao_inserir(Lista* lista) {
    Veiculo v;
    printf("\n--- Inserir Veiculo ---\n");
    printf("Placa: ");
    if (!ler_placa(v.placa)) 
        return 0;
    
    if (buscar(lista, v.placa) != -1) {
        printf("Erro: Veiculo com placa %s ja cadastrado!\n", v.placa);
        return 0;
    }
    
    if (!ler_campo(v.marca, sizeof(v.marca), "Marca")) return 0;
    if (!ler_campo(v.modelo, sizeof(v.modelo), "Modelo")) return 0;
    if (!ler_ano(&v.ano)) return 0;
    
    if (inserir(lista, v)) {
        printf("Veiculo inserido com sucesso!\n");
        return 1;
    }
    return 0;
}

int opcao_remover(Lista* lista) {
    char placa[8];
    printf("\n--- Remover Veiculo ---\n");
    printf("Digite a placa a remover: ");
    if (!ler_placa(placa)) 
        return 0;
    
    return remover(lista, placa);
}

void opcao_buscar(Lista* lista) {
    char placa[8];
    printf("\n--- Buscar Veiculo ---\n");
    printf("Digite a placa a buscar: ");
    if (!ler_placa(placa)) 
        return;
    
    int pos = buscar(lista, placa);
    if (pos == -1)
        printf("Veiculo com placa %s nao encontrado.\n", placa);
    else {
        printf("Veiculo encontrado:\n");
        imprimir_veiculo(lista->itens[pos]);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        puts("ERRO: numero incorreto de argumentos!");
        puts("Uso: editor <arquivo-binario-entrada> <arquivo-binario-saida>");
        exit(1);
    }

    Lista lista;
    inicializar(&lista);

    printf("Carregando base binaria: %s ...\n", argv[1]);
    if (!carregar_binario(&lista, argv[1]))
        exit(1);
    
    printf("Base carregada com sucesso! Total de veiculos: %d\n", lista.quantidade);

    int modificado = 0;
    int opcao = -1;
    char buffer[100];

    while (opcao != 0) {
        printf("\n================ MENU EDITOR ================\n");
        printf("1 - Inserir veiculo\n");
        printf("2 - Remover veiculo\n");
        printf("3 - Buscar veiculo por placa\n");
        printf("4 - Listar todos os veiculos\n");
        printf("5 - Salvar alteracoes\n");
        printf("0 - Sair\n");
        printf("=============================================\n");
        printf("Escolha uma opcao: ");
        
        ler_string(buffer, sizeof(buffer));
        if (sscanf(buffer, "%d", &opcao) != 1) {
            printf("Opcao invalida! Digite um numero de 0 a 5.\n");
            continue;
        }

        if (opcao == 1) {
            if (opcao_inserir(&lista))
                modificado = 1;
        }
        else if (opcao == 2) {
            if (opcao_remover(&lista))
                modificado = 1;
        }
        else if (opcao == 3)
            opcao_buscar(&lista);
        else if (opcao == 4)
            listar(&lista);
        else if (opcao == 5) {
            printf("Gravando em %s ...\n", argv[2]);
            if (gravar_binario(&lista, argv[2])) {
                printf("Arquivo %s gravado com sucesso!\n", argv[2]);
                modificado = 0;
            }
        } 
        else if (opcao == 0)
            printf("Encerrando sessao do editor...\n");
        else
            printf("Opcao invalida! Digite um numero de 0 a 5.\n");
    }

    if (modificado) {
        printf("Salvando alteracoes pendentes...\n");
        gravar_binario(&lista, argv[2]);
    } else
        printf("Nenhuma alteracao pendente.\n");

    return 0;
}