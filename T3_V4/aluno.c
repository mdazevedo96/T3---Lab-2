#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* aluno_cria(){
    return NULL;
}

Aluno* aluno_insere(Aluno* a, const char* nome, int mat, int tel) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0'; // Garante que a string é terminada em '\0'
    novo->matricula = mat;
    novo->telefone = tel;
    novo->prox = a;

    return novo;
}

void aluno_imprime(Aluno* a) {
    while (a != NULL) {
        printf("Nome: %s\n", a->nome);
        printf("Matricula: %d\n", a->matricula);
        printf("Telefone: %d\n", a->telefone);
        a = a->prox;
    }
}

#include <string.h>

Aluno* aluno_busca(Aluno* al, char* nome) {
    Aluno* b;
    for (b = al; b != NULL; b = b->prox) {
        if (strcmp(b->nome, nome) == 0) { // Usar strcmp para comparar strings
            return b;
        }
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}





