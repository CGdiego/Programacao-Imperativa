#include <stdio.h>

int main(){
    int a[5], b[5], s[5], i;

    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < 5; i++){
        scanf("%d", &b[i]);
        s[i] = a[i] + b[i];
    }

    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");

    for (i = 0; i < 5; i++)
        printf("%d ", s[i]);
    printf("\n");

    return 0;
}