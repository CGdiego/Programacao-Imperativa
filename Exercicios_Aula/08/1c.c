#include <stdio.h>

int fibonacci(int numero){
    if (numero == 0)
        return 0;
    if (numero == 1)
        return 1;

    return fibonacci(numero - 1) + fibonacci(numero - 2);
}

int main(){
    int n = 10;

    printf("F(%d) = %d\n", n, fibonacci(n));

    return 0;
}