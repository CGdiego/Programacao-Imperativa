#include <stdio.h>
#include <string.h>
#define MAX 200

int main(){
    const char* bases = "ACGT";
    char s[MAX];
    int cont[4] = {0}, i, j;

    fgets(s, MAX, stdin);
    s[strcspn(s, "\r\n")] = '\0';

    for (i = 0; s[i] != '\0'; i++)
        for (j = 0; bases[j] != '\0'; j++)
            if (s[i] == bases[j])
                cont[j]++;

    for (j = 0; bases[j] != '\0'; j++)
        printf("%c: %d\n", bases[j], cont[j]);

    return 0;
}