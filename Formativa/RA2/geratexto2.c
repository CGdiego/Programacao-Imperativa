#include <stdio.h>

int main(){
    FILE* texto = fopen("dados2.txt", "w");
    FILE* binario = fopen("dados.bin", "rb");
    int valor;

    while (fread(&valor, sizeof(int), 1, binario) == 1){
        printf("%d ", valor);
        fprintf(texto, "%d\n", valor);
    }

    fclose(binario);
    fclose(texto);

    return 0;
}