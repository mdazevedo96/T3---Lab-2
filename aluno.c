#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

Aluno* lst_cria(){
    return NULL;
}

Aluno* lst_insere(Aluno* al, char* nome, int matricula, int telefone){

    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if(novo == NULL){
        printf("Erro na alocacao");
        exit(1);
    }else{
        novo-> nome = nome;
        novo->mat = matricula;
        novo-> tel = telefone;

        return novo;
    }
}