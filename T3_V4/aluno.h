#ifndef ALUNO.H
#define ALUNO.H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[50];
    int matricula;
    int telefone;
    struct aluno* prox;
};
typedef struct aluno Aluno;


Aluno* aluno_cria();
Aluno* aluno_insere(Aluno* a,const char* nome, int mat, int tel);
void aluno_imprime(Aluno* al);
Aluno* aluno_busca(Aluno* al, char* nome);

#endif
