#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        puts("ERRO: numero incorreto de argumentos!");
        puts("Uso: gerador <arquivo-texto-entrada> <arquivo-binario-saida>");
        exit(1);
    }

    Lista lista;
    inicializar(&lista);

    printf("Carregando veiculos do arquivo texto: %s ...\n", argv[1]);
    if (!carregar_texto(&lista, argv[1]))
        exit(1);

    printf("Total de registros carregados: %d\n", lista.quantidade);
    printf("Gravando base binaria em: %s ...\n", argv[2]);
    if (!gravar_binario(&lista, argv[2]))
        exit(1);

    printf("Geracao concluida com sucesso!\n");
    return 0;
}