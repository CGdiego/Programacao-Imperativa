#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        puts("ERRO: numero incorreto de argumentos!");
        puts("Uso: exportador <arquivo-binario-entrada> <arquivo-texto-saida>");
        exit(1);
    }

    Lista lista;
    inicializar(&lista);

    printf("Carregando veiculos do arquivo binario: %s ...\n", argv[1]);
    if (!carregar_binario(&lista, argv[1]))
        exit(1);

    printf("Total de registros lidos: %d\n", lista.quantidade);
    printf("Exportando para formato texto em: %s ...\n", argv[2]);
    if (!gravar_texto(&lista, argv[2]))
        exit(1);

    printf("Exportacao concluida com sucesso!\n");
    return 0;
}