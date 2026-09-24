#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Erro no numero de argumentos!\n");
        printf("Uso: %s <arquivo_entrada> <arquivo_saida>\n", argv[0]);
        return 1;
    }

    FILE* entrada = fopen(argv[1], "r");
    if (entrada == NULL){
        printf("Erro ao abrir o ficheiro de entrada: %s\n", argv[1]);
        return 1;
    }

    FILE* saida = fopen(argv[2], "w");
    if (saida == NULL){
        printf("Erro ao criar o ficheiro de saida: %s\n", argv[2]);
        fclose(entrada);
        return 1;
    }

    int c = fgetc(entrada);
    while (c != EOF){
        fputc(toupper(c), saida);
        c = fgetc(entrada);
    }

    fclose(entrada);
    fclose(saida);

    printf("Ficheiro convertido com sucesso!\n");

    return 0;
}