#include <stdio.h>
#include <stdbool.h>
#define N 5

void caminho(bool adj[N][N], int a, int b){
    int fila[N], anterior[N], rota[N];
    int ini = 0, fim = 0, atual, i, tam = 0;

    for (i = 0; i < N; i++)
        anterior[i] = -1;

    fila[fim++] = a;
    anterior[a] = a;

    while (ini < fim && anterior[b] == -1){
        atual = fila[ini++];
        for (i = 0; i < N; i++)
            if (adj[atual][i] && anterior[i] == -1){
                anterior[i] = atual;
                fila[fim++] = i;
            }
    }

    if (anterior[b] != -1){
        for (atual = b; atual != a; atual = anterior[atual])
            rota[tam++] = atual;
        rota[tam++] = a;

        for (i = tam - 1; i >= 0; i--)
            printf("%d ", rota[i]);
        printf("\n");
    }
}

int main(){
    int a, b;
    bool adj[N][N] = {
        {false, true, false, false, false},
        {false, false, true, true, false},
        {false, false, false, false, true},
        {true, false, false, false, false},
        {false, false, false, false, false}
    };

    scanf("%d %d", &a, &b);
    caminho(adj, a, b);

    return 0;
}