#include <stdio.h>

int main(){
    int n, i, palindromo = 1;

    scanf("%d", &n);

    char v[n];

    for (i = 0; i < n; i++)
        scanf(" %c", &v[i]);

    for (i = 0; i < n / 2; i++)
        if (v[i] != v[n - 1 - i]){
            palindromo = 0;
            break;
        }

    if (palindromo)
        printf("Palindromo.");
    else
        printf("Nao palindromo.");

    return 0;
}