#include "projeto.h"

struct professor{
    int cod;
    char* nome;
    char* depto;
    struct projeto* prox;
};

typedef struct professor Professor;

