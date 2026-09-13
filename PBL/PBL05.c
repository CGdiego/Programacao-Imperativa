#include <stdio.h>

int main(){
    int N, i, contador = 0;
    char sequencia[100001];

    scanf("%d", &N);
    scanf("%s", sequencia);

    for (i = 0; i < N; i++){
        if (sequencia[i] == 'a'){
            if ((i > 0 && sequencia[i - 1] == 'a') || (i < N && sequencia[i + 1] == 'a'))
                contador++;
        }
    }

    printf("%d\n", contador);

    return 0;
}