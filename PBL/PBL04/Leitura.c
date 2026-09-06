#include <stdio.h>
#include "Leitura.h"

int ler_dados_dos_estudantes(Estudante turma[]){
    int quantidade = 0;
    int matricula;

    printf("-== Cadastro de estudantes (capacidade maxima: %d) ==-\n", CAPACIDADE_MAXIMA);
    printf("Digite -1 no numero de matricula para encerrar o cadastro.\n\n");

    while (quantidade < CAPACIDADE_MAXIMA){
        printf("Estudante %d\n", quantidade + 1);
        printf("Numero de matricula: ");
        scanf("%d", &matricula);

        if (matricula == -1)
            break;

        turma[quantidade].numeroMatricula = matricula;

        printf("Nota semestral: ");
        scanf("%f", &turma[quantidade].notaSemestral);

        quantidade++;
        printf("\n");
    }

    return quantidade;
}