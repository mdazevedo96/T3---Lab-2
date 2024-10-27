#ifndef PROJETO_H
#define PROJETO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "professor.h"

struct projeto{
    int cod;
    char* desc;
    char* tipo;
    float orc;
    float orc_atual;
    struct Professor* prof_resp;
    struct projeto* prox;
};

typedef struct projeto Projeto;

Projeto* projeto_insere(Projeto* p, Professor* prof_resp, int cod, char* desc, char* tipo, float orc, float orc_atual);

//bool verificaOrcamento(Aluno* al, Projeto* p);

#endif