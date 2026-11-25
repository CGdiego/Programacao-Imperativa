#include <stdio.h>

int main(int argc, char* argv[]){
    double b, c, res;
    char extra;

    if (argc != 4 || argv[1][1] != '\0')
        return 1;

    if (sscanf(argv[2], "%lf %c", &b, &extra) != 1 || sscanf(argv[3], "%lf %c", &c, &extra) != 1)
        return 1;

    switch (argv[1][0]){
        case '+': res = b + c; break;
        case '-': res = b - c; break;
        case '*': res = b * c; break;
        case '/':
            if (c == 0){
                puts("Divisao por zero!");
                return 1;
            }
            res = b / c;
            break;
        default:
            return 1;
    }

    printf("%lf\n", res);
    return 0;
}