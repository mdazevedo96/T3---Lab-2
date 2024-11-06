#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "projeto.h"
#include "professor.h"

Professor* professor_insere(Professor* pr, const char* nome, int cod, char* depto) {
    Professor* novo = (Professor*) malloc(sizeof(Professor));
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->cod = cod;
    strncpy(novo->depto, depto, sizeof(novo->depto) - 1);
    novo->prox = pr;

    return novo;
}

void professor_imprime(Professor* pr) {
    while (pr != NULL) {
        printf("Nome: %s\n", pr->nome);
        printf("Codigo: %d\n", pr->cod);
        printf("Depto: %s\n", pr->depto);
        pr = pr->prox;
    }
}
