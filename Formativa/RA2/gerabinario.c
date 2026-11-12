#include <stdio.h>

int main(){
    FILE* texto = fopen("dados.txt", "r");
    FILE* binario = fopen("dados.bin", "wb");
    int valor;

    while (!feof(texto)){
        fscanf(texto, "%d", &valor);
        printf("%d ", valor);
        fwrite(&valor, sizeof(int), 1, binario);
    }

    fclose(binario);
    fclose(texto);

    return 0;
}