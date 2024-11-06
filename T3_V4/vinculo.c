#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "projeto.h"
#include "aluno.h"
#include "vinculo.h"

// Função para criar uma lista vazia de vínculos
Vinculo* vinculo_cria() {
    return NULL;
}

// Função para inserir um vínculo na lista
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa) {
    float custo_total = valor_bolsa * 12;
    if (p->orc_atual < custo_total) {
        printf("Orcamento insuficiente para vínculo\n");
        return v;
    }

    // Atualiza o orçamento disponível do projeto
    p->orc_atual -= custo_total;

    // Aloca memória para o novo vínculo
    Vinculo* novo = (Vinculo*)malloc(sizeof(Vinculo));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    // Inicializa o novo vínculo
    novo->al = al;
    novo->p = p;
    novo->bolsa_mensal = valor_bolsa;
    novo->prox = v;

    printf("Vínculo inserido com sucesso.\n");
    return novo;  // Retorna o novo início da lista
}

// Função para excluir um vínculo da lista
Vinculo* vinculo_exclui(Vinculo* v, Aluno* al, Projeto* p) {
    Vinculo *anterior = NULL, *atual = v;

    while (atual != NULL) {
        if (atual->al == al && atual->p == p) {
            if (anterior == NULL) {
                // Remove o primeiro elemento
                v = atual->prox;
            } else {
                // Remove um elemento no meio ou no final da lista
                anterior->prox = atual->prox;
            }

            // Restaura o orçamento do projeto
            p->orc_atual += atual->bolsa_mensal * 12;
            free(atual);
            printf("Vínculo excluído com sucesso.\n");
            return v;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Vínculo não encontrado.\n");
    return v;
}

// Função para imprimir todos os vínculos na lista
void vinculo_imprime(Vinculo* v) {
    while (v != NULL) {
        printf("Nome bolsista: %s\n", v->al->nome);
        printf("Projeto: %d\n", v->p->cod);
        printf("Valor bolsa: %.2f\n", v->bolsa_mensal);
        v = v->prox;
    }
}

// Função para liberar todos os vínculos da lista
void vinculo_libera(Vinculo* v) {
    Vinculo* atual;
    while (v != NULL) {
        atual = v;
        v = v->prox;
        free(atual);
    }
    printf("Todos os vínculos foram liberados.\n");
}
