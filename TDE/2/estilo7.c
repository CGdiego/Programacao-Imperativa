#include <stdio.h>

#define TAM_MAX 10

int main(void)
{
    char letras[TAM_MAX];

    puts("Digite 10 letras:");

    for (int i = 0; i < TAM_MAX; i++)
    {
        printf("letra %d: ", i + 1);
        letras[i] = getchar();
        getchar(); // skip the ENTER char
    }

    puts("As 10 letras digitadas foram:");

    for (int i = 0; i < TAM_MAX; i++)
    {
        putchar(letras[i]);
    }
    putchar('\n');

    puts("Digite uma sequência de, no máximo, 9 letras:");
    scanf("%9s", letras);
    printf("Sequência digitada: %s", letras);
    putchar('\n');

    return 0;
}