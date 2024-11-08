#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "projeto.h"
#include "vinculo.h"

// Função para inserir um vínculo
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa) {
    if (p == NULL || al == NULL) {
        printf("Erro: Projeto ou Aluno inválido.\n");
        return v;
    }

    float custo_total = valor_bolsa * 12;

    // Verifica se o orçamento atual é suficiente
    if (p->orc_atual >= custo_total) {
        // Deduz o custo total do orçamento do projeto
        p->orc_atual -= custo_total;

        // Aloca memória para o novo vínculo
        Vinculo* novo = (Vinculo*)malloc(sizeof(Vinculo));
        if (novo == NULL) {
            printf("Erro ao alocar memória para o vínculo.\n");
            p->orc_atual += custo_total; // Restaura o orçamento em caso de erro
            return v;
        }

        // Inicializa o novo vínculo
        novo->al = al;
        novo->p = p;
        novo->bolsa_mensal = valor_bolsa;
        novo->prox = v;

        printf("Vínculo inserido com sucesso: Aluno %s vinculado ao projeto %d.\n", al->nome, p->cod);
        return novo;  // Retorna o novo início da lista
    } else {
        printf("Orçamento insuficiente para vincular o aluno %s ao projeto %d.\n", al->nome, p->cod);
        return v;  // Retorna a lista original
    }
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

