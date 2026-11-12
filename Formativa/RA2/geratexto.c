#include <stdio.h>

int main(){
    FILE* texto = fopen("dados2.txt", "w");
    FILE* binario = fopen("dados.bin", "rb");
    int valor;

    fread(&valor, sizeof(int), 1, binario);
    while (!feof(binario)){
        printf("%d ", valor);
        fprintf(texto, "%d\n", valor);
        fread(&valor, sizeof(int), 1, binario);
    }

    fclose(binario);
    fclose(texto);

    return 0;
}