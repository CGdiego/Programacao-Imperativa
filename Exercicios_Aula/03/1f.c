#include <stdio.h>

int main(){
    int n, i, j, aux;

    scanf("%d", &n);

    int v[n], ord[n];

    for (i = 0; i < n; i++){
        scanf("%d", &v[i]);
        ord[i] = v[i];
    }

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1; j++)
            if (ord[j] > ord[j + 1]){
                aux = ord[j];
                ord[j] = ord[j + 1];
                ord[j + 1] = aux;
            }

    for (i = 0; i < n; i++)
        printf("%d ", ord[i]);

    return 0;
}