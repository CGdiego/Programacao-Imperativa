#include <stdio.h>
#include <string.h>
#define MAX 200

int main() {
    const char* bases = "ACGT";
    char s[MAX], *p;
    int valida = 1;

    fgets(s, MAX, stdin);
    s[strcspn(s, "\r\n")] = '\0';

    if (s[0] == '\0')
        valida = 0;

    for (p = s; *p != '\0'; p++)
        if (strchr(bases, *p) == NULL) {
            valida = 0;
            break;
        }

    if (valida)
        puts("Valida");
    else
        puts("Invalida");

    return 0;
}