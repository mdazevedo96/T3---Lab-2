#include "stdio.h"

struct aluno{
    char* nome;
    int mat;
    int tel;
};
typedef struct aluno Aluno;

Aluno* lst_cria();

Aluno* lst_insere(Aluno* al, char* nome, int matricula, int telefone);
