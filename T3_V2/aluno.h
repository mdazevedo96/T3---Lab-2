#include "stdio.h"

struct aluno{
    char* nome;
    int mat;
    int tel;
    struct aluno* prox;
};
typedef struct aluno Aluno;

Aluno* lst_cria();

Aluno* lst_insere(Aluno* al, char* nome, int matricula, int telefone);

void lst_imprime(Aluno* al);

