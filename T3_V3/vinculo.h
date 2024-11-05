#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"
#include "aluno.h"

struct vinculo{
    Aluno* al;
    Projeto* p;
    float bolsa_mensal;
    struct vinculo* prox;
};
typedef struct vinculo Vinculo;

void* vinculo_cria();
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, float valor_bolsa);
bool verificaOrcAtual(Projeto* p, Vinculo* v);