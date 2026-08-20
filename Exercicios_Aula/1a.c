#include <stdio.h>

int main(){
    int n1, n2;

    printf("Insira 2 números inteiros diferentes:\n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    if (n1 != n2)
        if (n1 < n2)
            printf("%d %d", n1, n2);
        else
            printf("%d %d", n2, n1);
    else
        printf("Os números precisam ser diferentes.");

    return 0;
}