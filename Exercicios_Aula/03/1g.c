#include <stdio.h>

int main(){
    int i, n, valor, inseridos = 0, repetido;

    scanf("%d", &n);

    int v[n];

    while (inseridos < n){
        scanf("%d", &valor);

        repetido = 0;
        for (i = 0; i < inseridos; i++)
            if (v[i] == valor){
                repetido = 1;
                break;
            }

        if (repetido)
            printf("Valor repetido.\n");
        else{
            v[inseridos] = valor;
            inseridos++;
        }
    }

    return 0;
}