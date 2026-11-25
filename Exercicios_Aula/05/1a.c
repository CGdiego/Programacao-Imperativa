#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){
    char a[MAX], b[MAX], res[2 * MAX];

    fgets(a, MAX, stdin);
    a[strcspn(a, "\r\n")] = '\0';

    fgets(b, MAX, stdin);
    b[strcspn(b, "\r\n")] = '\0';

    strcpy(res, a);
    strcat(res, b);

    puts(a);
    puts(b);
    puts(res);

    return 0;
}