#include <stdio.h>

int main(){
    int c = 0x45FC;
    printf("0x%04X\n", (c << 16) & 0xFFFF);

    return 0;
}