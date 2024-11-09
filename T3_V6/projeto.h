#ifndef PROJETO_H
#define PROJETO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----STRUCT PROJETO-----*/
struct projeto {
    char cod[15];
    char desc[200];
    char tipo[10];
    float orc_atual;
    float orc_total;
    char prof_coord[50];
    struct projeto* prox;
};
typedef struct projeto Projeto;

/*CRIA LISTA PROJETO*/
Projeto* projeto_cria();

/*RECEBE OS DADOS DO CASE 5 DO MENU, INSERE NOVO NOH NA LISTA PROJETO E A RETORNA ATUALIZADA*/
Projeto* projeto_insere(Projeto* p, char* prof_coord, char* cod, char* desc, int r_tipo, float orc_total);

/*RECEBE LISTA PROJETO E IMPRIME TODOS OS PROJETOS*/
void projeto_imprime(Projeto* p);

/*RECEBE LISTA PROJETO E NOME DO PROJETO QUE SE DESEJA BUSCAR*/
Projeto* projeto_busca(Projeto* p, char* cod);

/*LIBERA A LISTA PROJETO*/
void projeto_libera(Projeto* p);

/*RECEBE LISTA DE PROJETO E DE VINCULO E IMPRIME O RELATORIO DE CADA PROJ E SEUS ALUNOS VINCULADOS*/
void projeto_relatorio(Projeto* p);

#endif
