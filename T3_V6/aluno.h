#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----STRUCT E PROTOTIPOS PARA ALUNO-----*/ 
struct aluno {
    char nome[50];
    char matricula[15];//string pois matricula pode ter mais de 10 digitos
	char telefone[16];//string pois pode ser adicionado ddd, o que somaria 11 dígitos. Caso seja usado ' ' ou '-', fica melhor também
    struct aluno* prox;
};
typedef struct aluno Aluno;

/*CRIA LISTA ALUNO*/
Aluno* aluno_cria();

/*RECEBE OS DADOS DO CASE 1 DO MENU, INSERE NOVO NOH NA LISTA ALUNO E A RETORNA ATUALIZADA*/
Aluno* aluno_insere(Aluno* a, char* nome, char* mat, char* tel);

/*RECEBE LISTA ALUNO E IMPRIME TODOS OS ALUNOS*/
void aluno_imprime(Aluno* al);

/*RECEBE LISTA ALUNO E NOME DO ALUNO QUE SE DESEJA BUSCAR*/
Aluno* aluno_busca(Aluno* al, char* nome);

/*RECEBE LISTA ALUNO E MATRICULA DO ALUNO QUE SE DESEJA BUSCAR*/
Aluno* busca_mat(Aluno* al, char* mat);

/*LIBERA A LISTA ALUNO*/
void aluno_libera(Aluno* a);

#endif
