#include <stdio.h>

int main(){
    int n, x, i, indice = -1;

    scanf("%d", &n);

    int v[n];

    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &x);

    for (i = 0; i < n; i++)
        if (v[i] == x){
            indice = i;
            break;
        }

    printf("%d", indice);

    return 0;
}