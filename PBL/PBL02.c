#include <stdio.h>

int main() {
    int T, D, M, y, anterior = 0;

    scanf("%d %d %d", &T, &D, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &y);
        if (y - anterior >= T) {
            printf("Y");
            return 0;
        }
        anterior = y;
    }

    if (D - anterior >= T)
        printf("Y");
    else
        printf("N");

    return 0;
}