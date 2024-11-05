
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[50];
    int matricula;
    int telefone;
    struct aluno* prox;
} Aluno;


Aluno* aluno_cria();
Aluno* aluno_insere(Aluno* a,const char* nome, int mat, int tel);
void aluno_imprime(Aluno* al);

