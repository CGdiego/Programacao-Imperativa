#include "Estudante.h"
#include "Leitura.h"
#include "Classificacao.h"
#include "Relatorio.h"

int main(){
    Estudante turma[CAPACIDADE_MAXIMA];
    int quantidade;

    quantidade = ler_dados_dos_estudantes(turma);

    for (int i = 0; i < quantidade; i++)
        turma[i] = classificar(turma[i]);

    imprimir_relatorio(turma, quantidade);

    return 0;
}