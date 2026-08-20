#include <stdio.h>

int main(){
    int N, K;
    
    printf("Digite o número de diretores: ");
    scanf("%d", &N);
    
    printf("Digite a duração máxima da reunião: ");
    scanf("%d", &K);
    
    int duracao = (K - (N - 1)) / N;
    
    printf("%d", duracao);

    return 0;
}