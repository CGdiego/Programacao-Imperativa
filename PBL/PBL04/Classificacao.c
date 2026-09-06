#include "Classificacao.h"

Estudante classificar(Estudante estudante){
    if (estudante.notaSemestral >= NOTA_MINIMA)
        estudante.indicadorAprovacao = true;
    else
        estudante.indicadorAprovacao = false;

    return estudante;
}