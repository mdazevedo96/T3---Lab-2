#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

/*-----FUNCOES PROFESSOR-----*/

/*CRIA LISTA PROFESSOR*/
Professor* prof_cria()
{
	return NULL;
}

/*RECEBE OS DADOS DO CASE 3 DO MENU, INSERE NOVO NOH NA LISTA PROFESSOR E A RETORNA ATUALIZADA*/
Professor* professor_insere(Professor* pr, char* nome, char* cod, char* depto)
{
    Professor* novo = (Professor*) malloc(sizeof(Professor));//malloc
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
	//o novo noh recebe os dados informados e aponta para o proximo noh
    strncpy(novo->nome, nome, sizeof(novo->nome));
    strncpy(novo->cod, cod, sizeof(novo->cod));
    strncpy(novo->depto, depto, sizeof(novo->depto));
    novo->prox = pr;

    return novo;//retorna lista professor
}

/*RECEBE LISTA PROFESSOR E IMPRIME TODOS OS PROFESSOR*/
void professor_imprime(Professor* pr)
{
    Professor* aux;
    int b = 1;//para contar qual enésimo professor estah sendo imprimido
	for(aux=pr; aux!=NULL; aux=aux->prox) {
		printf("\nProfessor %d\n", b);//enésimo professor e infos abaixo
        printf("Nome: %s\n", aux->nome);
        printf("Codigo: %s\n", aux->cod);
        printf("Depto: %s\n", aux->depto);
        printf("\n");
        b += 1;//att contador
    }
}

/*RECEBE LISTA PROFESSOR E NOME DO PROFESSOR QUE SE DESEJA BUSCAR*/
Professor* prof_busca(Professor* pr, char* nome)
{
    Professor* p;
    for (p = pr; p != NULL; p = p->prox) {
        if (strcmp(p->nome, nome) == 0) {//compara se o nome do professor do noh atual é igual ao do buscado
            return p;//se for, retornará o noh do professor
        }
    }
    return NULL;//Retorna NULL se o professor não foi encontrado
}

/*LIBERA A LISTA PROFESSOR*/
void prof_libera(Professor* pr)
{
    Professor* temp;
    while (pr != NULL) {
        temp = pr;
        pr = pr->prox;
        free(temp);
	}
}
