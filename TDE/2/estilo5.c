/* Programa para calcular as raízes de uma
equação de segundo grau */

#include <stdio.h>
#include <math.h>

int main(void) 
{
    float a, b, c; // coeficientes da equação (a*x^2 + b*x + c = 0)
    puts("Digite a: ");
    scanf("%f", &a);
    puts("Digite b: ");
    scanf("%f", &b);
    puts("Digite c: ");
    scanf("%f", &c);

    float delta = pow(b, 2) - 4 * a * c; // discriminante da equação
    printf("%f\n", delta);

    if (delta < 0) 
    {
        puts("Nao existe raiz!");
    }
    else if (delta == 0) 
    {
        float raiz = -b / (2 * a); // raiz única
        puts("Existe uma raiz:");
        printf("%f\n", raiz);
    } 
    else 
    {
        puts("Existem duas raizes:");
        float raiz_delta = sqrt(delta); // raiz quadrada do discriminante
        float raiz1 = (-b + raiz_delta) / (2 * a); // primeira raiz
        float raiz2 = (-b - raiz_delta) / (2 * a); // segunda raiz
        printf("%f\n", raiz1);
        printf("%f\n", raiz2);
    }

    return 0;
}