#ifndef VINCULO_H
#define VINCULO_H

#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"
#include "aluno.h"
#include "professor.h"

// Estrutura de vínculo entre aluno e projeto, incluindo professor e valor da bolsa
struct vinculo {
    Aluno* al;             // Aluno vinculado
    Projeto* p;            // Projeto associado
    Professor* pr;         // Professor responsável
    float bolsa_mensal;    // Valor mensal da bolsa
    struct vinculo* prox;  // Próximo vínculo na lista
};

typedef struct vinculo Vinculo;

// Cria uma lista de vínculos vazia
Vinculo* vinculo_cria();

// Insere um novo vínculo na lista
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa);

// Exclui um vínculo específico da lista
Vinculo* vinculo_exclui(Vinculo* lista, Aluno* aluno, Projeto* projeto);

// Imprime todos os vínculos na lista
void vinculo_imprime(Vinculo* lista);

// Libera toda a lista de vínculos, evitando vazamentos de memória
void vinculo_libera_todos(Vinculo* lista);

#endif  // VINCULO_H
