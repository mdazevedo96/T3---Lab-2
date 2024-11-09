#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

/*-----FUNCOES ALUNO-----*/

/*CRIA LISTA ALUNO*/
Aluno* aluno_cria()
{
    return NULL;
}

/*RECEBE OS DADOS DO CASE 1 DO MENU, INSERE NOVO NOH NA LISTA ALUNO E A RETORNA ATUALIZADA*/
Aluno* aluno_insere(Aluno* a, char* nome, char* mat, char* tel)
{
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));//malloc
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
	//o novo noh recebe os dados informados e aponta para o proximo noh
    strncpy(novo->nome, nome, sizeof(novo->nome));	
    strncpy(novo->matricula, mat, sizeof(novo->matricula));
    strncpy(novo->telefone, tel, sizeof(novo->telefone));
    novo->prox = a;

    return novo;//retorna lista aluno
}

/*RECEBE LISTA ALUNO E IMPRIME TODOS OS ALUNOS*/
void aluno_imprime(Aluno* a)
{
    Aluno* aux;
    int cont = 1;//para contar qual enésimo aluno estah sendo imprimido
	for(aux=a; aux!=NULL; aux=aux->prox) {
    	printf("\nAluno %d\n", cont);//enésimo aluno e infos do aluno abaixo
	    printf("Nome: %s\n", aux->nome);
        printf("Matricula: %s\n", aux->matricula);
        printf("Telefone: %s\n", aux->telefone);
        printf("\n");
        cont += 1;//att contador
    }
}

/*RECEBE LISTA ALUNO E NOME DO ALUNO QUE SE DESEJA BUSCAR*/
Aluno* aluno_busca(Aluno* al, char* nome) {
    Aluno* b;
    for (b = al; b != NULL; b = b->prox) {
        if (strcmp(b->nome, nome) == 0) {//compara se o nome do aluno do noh atual é igual ao do buscado
            return b;//se for, retornará o noh do aluno
        }
    }
    return NULL;//Retorna NULL se o aluno não foi encontrado
}

/*RECEBE LISTA ALUNO E MATRICULA DO ALUNO QUE SE DESEJA BUSCAR*/
Aluno* busca_mat(Aluno* al, char* mat)
{
    Aluno* b;
    for (b = al; b != NULL; b = b->prox) {
        if (strcmp(b->matricula, mat) == 0) {//compara se o nome do aluno do noh atual é igual ao do buscado
            return b;//se for, retornará o noh do aluno
        }
    }
    return NULL;//Retorna NULL se o aluno não foi encontrado
}

/*LIBERA A LISTA ALUNO*/
void aluno_libera(Aluno* a)
{
	Aluno* temp;
    while (a != NULL) {
        temp = a;
        a = a->prox;
        free(temp);
    }
}

