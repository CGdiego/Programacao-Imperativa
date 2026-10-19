#include <stdio.h>

void hanoi(int n, char x, char y, char z){
    if (n > 0){
        hanoi(n - 1, x, z, y);
        printf("Mova o disco de %c para %c\n", x, y);
        hanoi(n - 1, z, y, x);
    }
}

int main(){
    int n = 3;

    hanoi(n, 'X', 'Y', 'Z');

    return 0;
}