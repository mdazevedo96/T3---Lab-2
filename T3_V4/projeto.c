#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "projeto.h"
#include "professor.h"
#include "aluno.h"
#include "vinculo.h"

// Função para criar uma lista de projetos vazia
Projeto* projeto_cria() {
    return NULL;
}

// Função para inserir um novo projeto na lista de projetos
Projeto* projeto_insere(Projeto* p, const char* prof_coord, int cod, const char* desc, const char* tipo, float orc_total, float orc_atual) {
    Projeto* novo = (Projeto*) malloc(sizeof(Projeto));
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    strncpy(novo->prof_coord, prof_coord, sizeof(novo->prof_coord) - 1);
    novo->prof_coord[sizeof(novo->prof_coord) - 1] = '\0';
    novo->cod = cod;
    strncpy(novo->desc, desc, sizeof(novo->desc) - 1);
    novo->desc[sizeof(novo->desc) - 1] = '\0';
    strncpy(novo->tipo, tipo, sizeof(novo->tipo) - 1);
    novo->tipo[sizeof(novo->tipo) - 1] = '\0';
    novo->orc_atual = orc_atual;
    novo->orc_total = orc_total;
    novo->prox = p;

    return novo;
}

// Função para verificar se há orçamento suficiente para vincular um novo aluno
bool verifica_orcamento(Projeto* p, float valor_bolsa) {
    return (p != NULL && (p->orc_atual >= valor_bolsa * 12));
}

// Função para imprimir um relatório de cada projeto e seus alunos vinculados
void imprime_relatorio(Projeto* proj, Vinculo* vinculos) {
    Projeto* p = proj;
    while (p != NULL) {
        printf("\nCódigo do projeto: %d\n", p->cod);
        printf("Tipo do projeto: %s\n", p->tipo);
        printf("Professor coordenador: %s\n", p->prof_coord);
        printf("Orçamento atual disponível: %.2f\n", p->orc_atual);

        bool tem_aluno = false;
        Vinculo* v = vinculos;
        while (v != NULL) {
            if (v->p == p) {
                printf("Aluno vinculado: %s\n", v->al->nome);
                tem_aluno = true;
            }
            v = v->prox;
        }

        if (!tem_aluno) {
            printf("Não há alunos vinculados a este projeto.\n");
        }

        p = p->prox;
    }
}

// Função para imprimir todos os projetos na lista
void projeto_imprime(Projeto* p) {
    while (p != NULL) {
        printf("Código: %d\n", p->cod);
        printf("Descrição: %s\n", p->desc);
        printf("Professor coordenador: %s\n", p->prof_coord);
        printf("Tipo: %s\n", p->tipo);
        printf("Orçamento atual: %.2f\n", p->orc_atual);
        printf("Orçamento total: %.2f\n", p->orc_total);
        p = p->prox;
    }
}

// Função para liberar todos os projetos da lista, evitando vazamento de memória
void projeto_libera(Projeto* p) {
    Projeto* temp;
    while (p != NULL) {
        temp = p;
        p = p->prox;
        free(temp);
    }
}


Projeto* projeto_busca(Projeto* p, int cod) {
    Projeto* b;
    for (b = p; b != NULL; b = b->prox) {
        if (b->cod == cod) {
            return b; // Retorna o projeto encontrado
        }
    }
    return NULL; // Retorna NULL se o projeto não for encontrado
}
