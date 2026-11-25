#include <stdio.h>
#include <stdbool.h>
#define N 8

bool casa_segura(bool tab[N][N], int linha, int col){
    int i, j;

    for (i = 0; i < linha; i++)
        if (tab[i][col])
            return false;

    for (i = linha - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (tab[i][j])
            return false;

    for (i = linha - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (tab[i][j])
            return false;

    return true;
}

bool resolver(bool tab[N][N], int linha){
    int col;
    
    if (linha == N)
        return true;

    for (col = 0; col < N; col++)
        if (casa_segura(tab, linha, col)){
            tab[linha][col] = true;
            if (resolver(tab, linha + 1))
                return true;
            tab[linha][col] = false;
        }

    return false;
}

int main(){
    bool tabuleiro[N][N] = {false};
    int i, j;

    if (resolver(tabuleiro, 0))
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++)
                printf("%d ", tabuleiro[i][j]);
            putchar('\n');
        }

    return 0;
}