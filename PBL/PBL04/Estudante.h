#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <stdbool.h>

#define CAPACIDADE_MAXIMA 60

typedef struct{
    int numeroMatricula;
    float notaSemestral;
    bool indicadorAprovacao;
} Estudante;

#endif