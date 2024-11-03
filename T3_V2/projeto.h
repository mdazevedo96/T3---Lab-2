#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct projeto {
    char prof_coord[50]; 
    int cod;
    char desc[100]; 
    char tipo[20]; 
    float orc_atual;
    float orc_total;
    struct projeto* prox;
    }Projeto;

Projeto* projeto_cria();
Projeto* projeto_insere(Projeto* p, const char* prof_coord, int cod, const char* desc, const char* tipo, float orc_total, float orc_atual);
void projeto_imprime(Projeto* p);
   