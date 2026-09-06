#include <stdio.h>
#include "Relatorio.h"

void imprimir_relatorio(Estudante turma[], int quantidade){
    printf("\n--- Relatorio de Estudantes ---\n");

    for (int i = 0; i < quantidade; i++) {
        printf("Matricula: %d | Nota: %.1f | Situacao: ", turma[i].numeroMatricula, turma[i].notaSemestral);
        
        if (turma[i].indicadorAprovacao == true)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
    }
    printf("\n");
}