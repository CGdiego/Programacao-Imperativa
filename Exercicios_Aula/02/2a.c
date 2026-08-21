#include <stdio.h>

int main(){
    double operando1, operando2;
    char operador;

    printf("Digite uma conta no formato 'operando1' 'operador' 'operando2', ex: 1 + 1:\n");
    scanf("%lf %c %lf", &operando1, &operador, &operando2);

    switch (operador)
    {
        case '+': printf("%lf\n", operando1 + operando2); break;
        case '-': printf("%lf\n", operando1 - operando2); break;
        case '*': case 'x': case 'X': case '.': printf("%lf\n", operando1 * operando2); break;
        case '/': case '\\': case ':':
        if (operando2 == 0){
            printf("Não é possível dividir por zero.\n");
            return 0;
        }
        printf("%lf\n", operando1 / operando2); break;

        default: printf("Operador inválido\n"); break;
    }

    return 0;
}