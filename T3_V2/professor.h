#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <stdio.h>
#include <stdlib.h>

struct professor{
    int cod;
    char* nome;
    char* depto;
    struct projeto* prox;
};

typedef struct professor Professor;

#endif