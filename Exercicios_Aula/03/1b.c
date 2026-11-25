#include <stdio.h>

int main(){
    int n, i;

    scanf("%d", &n);

    float v[n];

    for (i = 0; i < n; i++)
        scanf("%f", &v[i]);

    for (i = 0; i < n; i++)
        printf("%.2f ", v[i]);
    printf("\n");

    for (i = 0; i < (n + 1) / 2; i++)
        printf("%.2f ", v[i] + v[n - 1 - i]);
    printf("\n");

    return 0;
}