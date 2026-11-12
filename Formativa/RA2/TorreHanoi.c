#include <stdio.h>

void hanoi(int N, char origem, char auxiliar, char destino){
    if (N > 0){
        hanoi(N - 1, origem, destino, auxiliar);
        printf("Movimentar disco de %c para %c\n", origem, destino);
        hanoi(N - 1, auxiliar, origem, destino);
    }
}

int main(){
    hanoi(5, 'B', 'X', 'T');

    return 0;
}