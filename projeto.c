#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"
#include "professor.h"

Projeto* lst_insere(Projeto* p, Professor* prof_resp, int cod, char* desc, char* tipo, float orc, float orc_atual){
    Projeto* novo = (Projeto*) malloc(sizeof(Projeto));
    novo->cod = cod;
    novo->desc = desc;
    novo->tipo = tipo;
    novo->orc = orc;
    novo->orc_atual = orc_atual;
    novo->prof_resp = prof_resp;
    novo->prox = p;
}
