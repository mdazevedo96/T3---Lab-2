#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "projeto.h"
#include "aluno.h"
#include "vinculo.h"

void* vinculo_cria(){
    return   NULL;
}

Vinculo* vinculo_insere(Vinculo* v, Projeto* p, float valor_bolsa){
    float custo_total = valor_bolsa * 12;
    if(p->orc_atual < custo_total){
        printf("Orcamento insuficiente para vinculo\n");
        return v;
    }
    //Atualiza orcamento disponivel
    p->orc_atual -= custo_total;
}



bool verificaOrcAtual(Projeto* p, Vinculo* v){
    bool haOrc = false;
    if(p->orc_total < v->bolsa_mensal*12){
        return haOrc;
    }
    return haOrc;
}



