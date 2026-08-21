#include <stdio.h>
#include <ctype.h>

int main(){
    char c1, c2, c3;

    printf("Insira três letras distintas:\n");
    scanf(" %c", &c1);
    scanf(" %c", &c2);
    scanf(" %c", &c3);

    c1 = tolower(c1);
    c2 = tolower(c2);
    c3 = tolower(c3);

    if (c1 != c2 && c2 != c3 && c1 != c3)
        if (c1 < c2 && c2 < c3)
            printf("%c %c %c", c1, c2, c3);
        else if (c2 < c1 && c1 < c3)
            printf("%c %c %c", c2, c1, c3);
        else if (c3 < c2 && c2 < c1)
            printf("%c %c %c", c3, c2, c1);
        else if (c1 < c3 && c3 < c2)
            printf("%c %c %c", c1, c3, c2);
        else if (c2 < c3 && c3 < c1)
            printf("%c %c %c", c2, c3, c1);
        else
            printf("%c %c %c", c3, c1, c2);
    else
        printf("As letras precisam ser diferentes.");

    return 0;
}