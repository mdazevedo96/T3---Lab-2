#include "professor.h"

struct projeto{
    int cod;
    char* desc;
    char* tipo;
    float orc;
    float orc_atual;
    struct Professor* prof_resp;
    struct projeto* prox;
};

typedef struct projeto Projeto;

Projeto* lst_insere(Projeto* p, Professor* prof_resp, int cod, char* desc, char* tipo, float orc, float orc_atual);

