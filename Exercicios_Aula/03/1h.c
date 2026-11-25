#include <stdio.h>
#include <math.h>
#define MAX 50

int main(){
    int n, i;
    float notas[MAX], soma = 0, soma_quad = 0, media, desvio;

    scanf("%d", &n);

    if (n <= 0 || n > MAX)
        return 1;

    for (i = 0; i < n; i++){
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / n;

    for (i = 0; i < n; i++)
        soma_quad += (notas[i] - media) * (notas[i] - media);

    desvio = sqrt(soma_quad / n);

    printf("%.2f\n%.2f\n", media, desvio);

    return 0;
}