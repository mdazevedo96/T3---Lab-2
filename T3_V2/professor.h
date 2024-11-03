
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professor {
    char nome[50];
    int cod;
    char depto[20];
    struct professor* prox;
} Professor;

typedef struct professor Professor;

Professor* professor_insere(Professor* pr, const char* nome, int cod, char* depto);
    
void professor_imprime(Professor* pr);
   