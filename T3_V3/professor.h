#ifndef PROFESSOR.H
#define PROFESSOR.H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor {
    char nome[50];
    int cod;
    char depto[20];
    struct professor* prox;
};

typedef struct professor Professor;

Professor* professor_insere(Professor* pr, const char* nome, int cod, char* depto);

void professor_imprime(Professor* pr);

#endif // PROFESSOR
