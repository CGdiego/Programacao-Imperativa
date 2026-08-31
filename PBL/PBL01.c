#include <stdio.h>

int main(){
    char c1, c2, c3;
    int N1, N2;
    float Q;

    printf("Insira três inteiros, e pressione ENTER a cada um: \n");
    scanf(" %c", &c1);
    scanf(" %c", &c2);
    scanf(" %c", &c3);

    N1 = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0');

    printf("\nInsira três inteiros, e pressione ENTER a cada um: \n");
    scanf(" %c", &c1);
    scanf(" %c", &c2);
    scanf(" %c", &c3);

    N2 = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0');

    Q = (float) N1 / N2;
    printf("\n%8.3f", Q);

    return 0;
}