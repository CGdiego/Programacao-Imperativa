#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Erro: Deve indicar o nome do ficheiro.\n");
        printf("Uso: %s <nome_do_ficheiro>\n", argv[0]);
        return 1;
    }

    FILE* arq = fopen(argv[1], "r");

    if (arq == NULL) {
        printf("Erro ao abrir o ficheiro. Verifique se o nome esta correto.\n");
        return 1;
    }

    int contagem[26] = {0};

    int c = fgetc(arq);
    while (c != EOF){
        if (isalpha(c)){
            c = toupper(c);
            int indice = c - 'A';
            contagem[indice]++;
        }
    
        c = fgetc(arq);
    }

    fclose(arq);

    printf("\nContagem de letras:\n");
    for (int i = 0; i < 26; i++)
        printf("%c: %d\n", 'A' + i, contagem[i]);
    
    return 0;
}