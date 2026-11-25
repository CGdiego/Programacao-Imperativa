#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){
    char a[MAX], b[MAX], c[MAX];
    int i, k = 0;

    fgets(a, MAX, stdin);
    a[strcspn(a, "\r\n")] = '\0';

    fgets(b, MAX, stdin);
    b[strcspn(b, "\r\n")] = '\0';

    c[0] = '\0';
    for (i = 0; a[i] != '\0'; i++)
        if (strchr(b, a[i]) != NULL && strchr(c, a[i]) == NULL){
            c[k++] = a[i];
            c[k] = '\0';
        }

    puts(c);
    return 0;
}