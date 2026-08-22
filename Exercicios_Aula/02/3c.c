#include <stdio.h>

int main(){
    int N;
    float S = 0;

    printf("Insira um valor N: ");
    scanf("%d", &N);

    int num = 1, den = N;

    do{
        S += (float) num/den;
        num++;
        den--;
    } while (num <= N);

    printf("%f", S);

    return 0;
}