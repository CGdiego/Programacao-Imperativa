#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese"); // habilita a acentuação para o português

    char nome_do_paciente[20]; // nome do paciente
    puts("Digite o seu nome: ");
    scanf("%19s", nome_do_paciente);

    int idade_do_paciente = 0; // idade do paciente
    puts("Digite a sua idade: ");
    scanf("%d", &idade_do_paciente);
    
    printf("%s, você tem %d anos.\n", nome_do_paciente, idade_do_paciente);
    return 0;
}