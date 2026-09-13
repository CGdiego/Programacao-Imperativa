#include <stdio.h>

int main(void)
{
    double primeiro_operando, segundo_operando; // operandos
    double resultado = 0; // resultado da operação
    char operador; // operador na forma de caracter
    puts("Digite o primeiro operando: ");
    scanf("%lf", &primeiro_operando);
    puts("Digite o segundo operando: ");
    scanf("%lf", &segundo_operando);
    getchar();
    puts("Digite um operador (+, -, *, /): ");
    operador = getchar();

    switch (operador)
    {
        case '+': resultado = primeiro_operando + segundo_operando; break;
        case '-': resultado = primeiro_operando - segundo_operando; break;
        case '*': resultado = primeiro_operando * segundo_operando; break;
        case '/': resultado = primeiro_operando / segundo_operando; break;
        default: puts("Operador inválido"); break;
    }

    printf("Resultado = %.2f\n", resultado);
    return 0;
}