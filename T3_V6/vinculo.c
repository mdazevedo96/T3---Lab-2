#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "projeto.h"
#include "vinculo.h"

/*-----FUNCOES VINCULO-----*/

/*CRIA LISTA VINCULO*/
Vinculo* vinculo_cria()
{
	return NULL;
}

/*RECEBE OS DADOS DO CASE 7 DO MENU, INSERE NOVO NOH NA LISTA VINCULO E A RETORNA ATUALIZADA*/
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa)
{
    if (p == NULL || al == NULL) {
        printf("Erro: Projeto ou Aluno invalido.\n");
        return v;
    }

    float custo_total = valor_bolsa * 12;//guarda o valor da bolsa para o ano inteiro

    if (p->orc_atual >= custo_total) {//Verifica se o orçamento atual é suficiente para pagar o custo total do aluno
        p->orc_atual -= custo_total;//Atualiza o orçamento atual do projeto, subtraindo o custo total do aluno

        Vinculo* novo = (Vinculo*)malloc(sizeof(Vinculo));//malloc
        if (novo == NULL) {
            printf("Erro ao alocar memoria para o vinculo.\n");
            p->orc_atual += custo_total; //Restaura o orçamento em caso de erro
            return v;
        }

        //o novo noh recebe os dados informados e aponta para o proximo noh
        novo->al = al;
        novo->p = p;
        novo->bolsa_mensal = valor_bolsa;
        novo->prox = v;

        printf("Vinculo inserido com sucesso: Aluno %s vinculado ao projeto %s.\n", al->nome, p->cod);
        return novo;//retorna lista vinculo atualizada
    } else {
        printf("Orcamento insuficiente para vincular o aluno %s ao projeto %s.\n", al->nome, p->cod);
        return v; //retorna a lista vinculo original, como estava
    }
}

/*RECEBE LISTA VINCULO, ALUNO E PROJETO, ELIMINA VINCULO EXISTENTE ENTRE ALUNO E PROJETO*/
Vinculo* vinculo_exclui(Vinculo* v, Aluno* al, Projeto* p, int meses)
{
    Vinculo *anterior = NULL, *atual = v;

    while (atual != NULL) {
        if (atual->al == al && atual->p == p) {
            if (anterior == NULL) {// Remove o primeiro elemento
                v = atual->prox;
            } else {// Remove um elemento no meio ou no final da lista
                anterior->prox = atual->prox;
            }

            p->orc_atual += atual->bolsa_mensal * meses;// Restaura o orçamento do projeto
            free(atual);
            printf("Vinculo excluido com sucesso.\n");
            return v;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Vinculo nao encontrado.\n");
    return v;
}

/*RECEBE LISTA DE VINCULOS E IMPRIME TODOS OS VINCULOS*/
void vinculo_imprime(Vinculo* lista)
{
	Vinculo* aux;
    int d = 1;//para contar qual enésimo vinculo estah sendo imprimido
    if(lista == NULL)
    	printf("\nNao ha vinculos existentes.\n");
	for(aux=lista; aux!=NULL; aux=aux->prox) {
		printf("\nVinculo %d\n", d);//enésimo vinculo e infos abaixo
		printf("-Dados do Aluno-\nAluno: %s - Matricula: %s - Telefone: %s\n", aux->al->nome, aux->al->matricula, aux->al->telefone);
        printf("-Dados do Projeto-\nProjeto: %s - Tipo: - Professor: %s\n", aux->p->cod, aux->p->tipo, aux->p->prof_coord);
        printf("Orcamento atual: %.2f - Orcamento total: %.2f\nDescricao: %s\n", aux->p->orc_atual, aux->p->orc_total, aux->p->desc);
        printf("Bolsa Mensal do aluno: %.2f\n", aux->bolsa_mensal);
        printf("\n");
        d += 1;//att contador
	}
}

/*LIBERA A LISTA DE VINCULOS*/
void vinculo_libera_todos(Vinculo* lista)
{
	Vinculo* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}
