#include <stdio.h>

int main(){
    int c = 0x45FC;

    printf("%X\n", c);

    c = c >> 1;

    printf("%X", c);

    return 0;
}