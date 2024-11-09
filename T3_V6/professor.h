#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----STRUCT PROFESSOR-----*/
struct professor {
    char nome[50];
    char cod[15]; //melhor para o caso do código ser maior do que outros tipos possam suportar
    char depto[30];
    struct professor* prox;
};
typedef struct professor Professor;

/*CRIA LISTA PROFESSOR*/
Professor* prof_cria();

/*RECEBE OS DADOS DO CASE 3 DO MENU, INSERE NOVO NOH NA LISTA PROFESSOR E A RETORNA ATUALIZADA*/
Professor* professor_insere(Professor* pr, char* nome, char* cod, char* depto);

/*RECEBE LISTA PROFESSOR E IMPRIME TODOS OS PROFESSOR*/
void professor_imprime(Professor* pr);

/*RECEBE LISTA PROFESSOR E NOME DO PROFESSOR QUE SE DESEJA BUSCAR*/
Professor* prof_busca(Professor* pr, char* nome);

/*LIBERA A LISTA PROFESSOR*/
void prof_libera(Professor* pr);

#endif // PROFESSOR
