#include <stdio.h>

int fatorial(int numero){
    if (numero <= 1){
        printf("1");
        return 1;
    }

    printf("%d . ", numero);
    return numero * fatorial(numero - 1);
}

int main(){
    int n = 9;

    printf("%d! = ", n);
    fatorial(n);

    return 0;
}