#include <stdio.h>

double calcular_polinomio(double a, double b, double c, double x){
    return (a * x * x) + (b * x) + c;
}

void gerar_pontos(double a, double b, double c, double x_inicio, double x_fim, int num_pontos){
    int i;
    double x, y;

    if (num_pontos <= 0){
        printf("Erro: Numero de pontos deve ser maior que zero.\n");
        return;
    }

    printf("\n-----------------------------------\n");
    printf(" Pontos da curva f(x) = %.2fx^2 + %.2fx + %.2f\n", a, b, c);
    printf("-----------------------------------\n");
    printf("%-12s | %-12s\n", "x", "f(x)");
    printf("-----------------------------------\n");

    if (num_pontos == 1){
        y = calcular_polinomio(a, b, c, x_inicio);
        printf("%-12.4f | %-12.4f\n", x_inicio, y);
        printf("-----------------------------------\n");
        return;
    }

    double passo = (x_fim - x_inicio) / (num_pontos - 1);

    for (i = 0; i < num_pontos; i++){
        x = x_inicio + (i * passo);
        y = calcular_polinomio(a, b, c, x);
        printf("%-12.4f | %-12.4f\n", x, y);
    }
    printf("-----------------------------------\n");
}

int main(){
    double a, b, c;
    double x_inicio, x_fim;
    int num_pontos;

    // Leitura dos coeficientes
    printf("=== Coeficientes do Polinomio (ax^2 + bx + c) ===\n");
    printf("Valor de a: ");
    scanf("%lf", &a);
    printf("Valor de b: ");
    scanf("%lf", &b);
    printf("Valor de c: ");
    scanf("%lf", &c);

    // Leitura do intervalo e quantidade de pontos
    printf("\n=== Intervalo e Pontos ===\n");
    printf("Valor do x inicial: ");
    scanf("%lf", &x_inicio);
    printf("Valor do x final: ");
    scanf("%lf", &x_fim);
    printf("Quantidade de pontos: ");
    scanf("%d", &num_pontos);

    gerar_pontos(a, b, c, x_inicio, x_fim, num_pontos);

    return 0;
}
