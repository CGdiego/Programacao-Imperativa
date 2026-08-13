#include <stdio.h>

int main()
{
    const double taxa_desconto = 0.15;
    double salario_bruto, salario_liquido, desconto;
    printf("Digite o salario bruto: ");
    scanf("%lf", &salario_bruto);
    desconto = salario_bruto * taxa_desconto;
    printf("desconto = %.2f\n", desconto);
    salario_liquido = salario_bruto - desconto;
    printf("salario liquido = %.2f\n", salario_liquido);
    return 0;
}