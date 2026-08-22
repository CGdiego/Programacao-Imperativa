#include <stdio.h>

int main(){
    int N;
    unsigned long long int R = 1;

    printf("Digite um inteiro para calcular o fatorial: ");
    scanf("%d", &N);

    for (int i = N; i > 0; i--)
        R *= i;

    printf("%llu\n", R);

    return 0;
}