#ifndef VINCULO_H
#define VINCULO_H

#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"
#include "aluno.h"
#include "professor.h"

/*-----STRUCT VINCULO-----*/
struct vinculo {
    Aluno* al;             // Aluno vinculado
    Projeto* p;            // Projeto associado
    float bolsa_mensal;    // Valor mensal da bolsa
    struct vinculo* prox;  // Próximo vínculo na lista
};
typedef struct vinculo Vinculo;
// Estrutura de vínculo entre aluno e projeto, incluindo valor da bolsa

/*CRIA LISTA VINCULO*/
Vinculo* vinculo_cria();

/*RECEBE OS DADOS DO CASE 7 DO MENU, INSERE NOVO NOH NA LISTA VINCULO E A RETORNA ATUALIZADA*/
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa);

/*RECEBE LISTA VINCULO, ALUNO E PROJETO, ELIMINA VINCULO EXISTENTE ENTRE TAL ALUNO E PROJETO*/
Vinculo* vinculo_exclui(Vinculo* lista, Aluno* aluno, Projeto* projeto, int meses);

/*RECEBE LISTA DE VINCULOS E IMPRIME TODOS OS VINCULOS*/
void vinculo_imprime(Vinculo* lista);

/*LIBERA A LISTA DE VINCULOS*/
void vinculo_libera_todos(Vinculo* lista);

#endif  // VINCULO_H
