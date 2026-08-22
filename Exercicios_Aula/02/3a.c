#include <stdio.h>

int main(){
    int N;
    float H = 0;

    printf("Insira um número N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        H += (float) 1/i;

    printf("%f\n", H);

    return 0;
}