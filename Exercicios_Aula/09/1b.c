#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[100];
    int idade;
} Pessoa;

int main(){
    FILE* arq = fopen("pessoas.txt", "r");
    Pessoa *vetor, *temp;
    size_t cap = 4, n = 0, i;
    char nome_lido[100];
    int idade_lida, soma = 0;
    double media;

    if (arq == NULL)
        return 1;

    vetor = (Pessoa*) malloc(cap * sizeof(Pessoa));
    if (vetor == NULL){
        fclose(arq);
        return 1;
    }

    while (fscanf(arq, " %99[^;\n]%*c %d", nome_lido, &idade_lida) == 2){
        if (n == cap){
            cap *= 2;
            temp = (Pessoa*) realloc(vetor, cap * sizeof(Pessoa));
            if (temp == NULL){
                free(vetor);
                fclose(arq);
                return 1;
            }
            vetor = temp;
        }

        snprintf(vetor[n].nome, sizeof(vetor[n].nome), "%s", nome_lido);
        vetor[n].idade = idade_lida;
        soma += idade_lida;
        n++;
    }
    fclose(arq);

    if (n > 0){
        media = (double) soma / n;
        for (i = 0; i < n; i++){
            if (vetor[i].idade > media)
                puts(vetor[i].nome);
        }
    }

    free(vetor);
    return 0;
}