#include <stdio.h>

int main(int argc, char* argv[]){
    int a, b;
    char extra;

    if (argc != 3){
        puts("Numero incorreto de argumentos");
        return 1;
    }

    if (sscanf(argv[1], "%d %c", &a, &extra) != 1 || sscanf(argv[2], "%d %c", &b, &extra) != 1){
        puts("Os argumentos devem ser valores inteiros");
        return 1;
    }

    printf("%d\n", a + b);
    return 0;
}