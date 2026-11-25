#include <stdio.h>

int main(){
    int n, i;

    scanf("%d", &n);

    char v[n], inv[n];

    for (i = 0; i < n; i++)
        scanf(" %c", &v[i]);

    for (i = 0; i < n; i++)
        inv[i] = v[n - 1 - i];

    for (i = 0; i < n; i++)
        printf("%c ", v[i]);
    printf("\n");

    for (i = 0; i < n; i++)
        printf("%c ", inv[i]);
    printf("\n");

    return 0;
}