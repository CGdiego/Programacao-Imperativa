#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE *in = fopen("entrada.txt", "r"), *out;
    char *texto, *temp;
    size_t cap = 64, tam = 0, i;
    int ch, max_freq = -1, idx_maior = 0, freq[5] = {0};
    const char vogais[5] = {'a', 'e', 'i', 'o', 'u'};

    if (in == NULL)
        return 1;

    texto = (char*) malloc(cap * sizeof(char));
    if (texto == NULL){
        fclose(in);
        return 1;
    }

    while ((ch = fgetc(in)) != EOF){
        if (ch == '#' || (!isalnum(ch) && !ispunct(ch) && !isspace(ch))){
            free(texto);
            fclose(in);
            return 1;
        }

        if (tam + 1 >= cap){
            cap *= 2;
            temp = (char*) realloc(texto, cap * sizeof(char));
            if (temp == NULL){
                free(texto);
                fclose(in);
                return 1;
            }
            texto = temp;
        }

        texto[tam++] = (char) ch;

        switch (tolower(ch)){
            case 'a': freq[0]++; break;
            case 'e': freq[1]++; break;
            case 'i': freq[2]++; break;
            case 'o': freq[3]++; break;
            case 'u': freq[4]++; break;
        }
    }
    texto[tam] = '\0';
    fclose(in);

    for (i = 0; i < 5; i++)
        if (freq[i] > max_freq){
            max_freq = freq[i];
            idx_maior = (int) i;
        }

    if (max_freq > 0)
        for (i = 0; i < tam; i++){
            if (tolower((unsigned char) texto[i]) == vogais[idx_maior])
                texto[i] = '#';
        }

    out = fopen("saida.txt", "w");
    if (out == NULL){
        free(texto);
        return 1;
    }

    fputs(texto, out);
    fclose(out);
    free(texto);

    return 0;
}