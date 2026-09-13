#include <stdio.h>

int main(void)
{
    const char letra = 'H'; // letra a ser impressa
    const int vezes_letra = 10; // número de vezes que a letra deve ser impressa
    for (int i = 0; i < vezes_letra; i++)
    {
        putchar(letra);
    }
    putchar('\n');

    // valor a ser impresso
    for (int valor_impresso = vezes_letra; valor_impresso > 0; valor_impresso--)
    {
        printf("%d ", valor_impresso);
    }
    putchar('\n');

    return 0;
}