#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "projeto.h"
#include "professor.h"
#include "aluno.h"
#include "vinculo.h"

/*-----FUNCOES PROJETO-----*/

/*CRIA LISTA PROJETO*/
Projeto* projeto_cria() {
    return NULL;
}

/*RECEBE OS DADOS DO CASE 5 DO MENU, INSERE NOVO NOH NA LISTA PROJETO E A RETORNA ATUALIZADA*/
Projeto* projeto_insere(Projeto* p, char* prof_coord, char* cod, char* desc, int r_tipo, float orc_total)
{
	if(existe_proj(p, cod) == 1)
    {
    	return p;//se jah existir o projeto, retorna lista como estava
	}
	
    Projeto* novo = (Projeto*) malloc(sizeof(Projeto));//malloc
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }
    
	//o novo noh recebe os dados informados e aponta para o proximo noh
    strncpy(novo->prof_coord, prof_coord, sizeof(novo->prof_coord));
    strncpy(novo->cod, cod, sizeof(novo->cod));
    strncpy(novo->desc, desc, sizeof(novo->desc));
    switch(r_tipo)//seleciona qual será o conteúdo do tipo baseado na resposta dada pelo usuário no case 5 do menu
	{
    	case 1:
			strcpy(novo->tipo, "Ensino"); break;
		case 2:
			strcpy(novo->tipo, "Pesquisa"); break;
		case 3:
			strcpy(novo->tipo, "Extensao"); break;
		default:
			strcpy(novo->tipo, "Invalido"); break;
	}
    novo->orc_atual = orc_total;
    novo->orc_total = orc_total;
    novo->prox = p;

    return novo;//retorna lista projeto
}

/*RECEBE LISTA PROJETO E IMPRIME TODOS OS PROJETOS*/
void projeto_imprime(Projeto* p)
{
    Projeto* aux;
    int cont = 1;//para contar qual enésimo projeto estah sendo imprimido
	for(aux=p; aux!=NULL; aux=aux->prox) {
		printf("\nProjeto %d\n", cont);//enésimo projeto e infos abaixo
        printf("Codigo: %s\n", aux->cod);
        printf("Descricao: %s\n", aux->desc);
        printf("Professor coordenador: %s\n", aux->prof_coord);
        printf("Tipo: %s\n", aux->tipo);
        printf("Orcamento atual: %.2f\n", aux->orc_atual);
        printf("Orcamento total: %.2f\n", aux->orc_total);
        printf("\n");
        cont += 1;//att contador
    }
}

/*RECEBE LISTA PROJETO E NOME DO PROJETO QUE SE DESEJA BUSCAR*/
Projeto* projeto_busca(Projeto* p, char* cod)
{
    Projeto* b;
    for (b = p; b != NULL; b = b->prox) {
        if (strcmp(b->cod, cod) == 0) {//compara se o nome do projeto do noh atual é igual ao do buscado
            return b;//se for, retornará o noh do projeto
        }
    }
    return NULL;//Retorna NULL se o projeto não foi encontrado
}

/*RECEBE LISTA PROJETO E CODIGO DO PROJETO Q SE DESEJA CADASTRAR*/
bool existe_proj(Projeto* p, char* cod)
{
	if(projeto_busca(p, cod) == NULL)//se projeto nao for encontrado, returna false e cadastra projeto normalmente
	{
		return 0;
	}else{//retorna true, e na condicao if da funcao principal, irah "sair" dela, ja que proj ja estah cadastrado
		printf("Jah ha um projeto com o codigo %s cadastrado.\n", cod);
		return 1;
	}    
}

/*LIBERA A LISTA PROJETO*/
void projeto_libera(Projeto* p)
{
    Projeto* temp;
    while (p != NULL) {
        temp = p;
        p = p->prox;
        free(temp);
    }
}

/*RECEBE LISTA DE PROJETO E DE VINCULO E IMPRIME O RELATORIO DE CADA PROJ E SEUS ALUNOS VINCULADOS*/
void imprime_relatorio(Projeto* proj, Vinculo* vinculos)
{
    Projeto* aux;
    int cont = 1;//para contar qual enésimo projeto estah sendo imprimido
    
    if(proj==NULL)
       	printf("\nNao ha conteudo para imprimir o relatorio.\n");
       	
	for(aux=proj; aux!=NULL; aux=aux->prox)
	{
		printf("\nProjeto %d\n", cont);//enésimo projeto e infos abaixo
        printf("\nCodigo do projeto: %s\n", aux->cod);
        printf("Tipo do projeto: %s\n", aux->tipo);
        printf("Professor coordenador: %s\n", aux->prof_coord);
        printf("Orcamento atual disponivel: %.2f\n", aux->orc_atual);

        bool tem_aluno = false;
        Vinculo* v = vinculos;
        while (v != NULL) {
            if (v->p == aux) {
                printf("Aluno vinculado: %s\n", v->al->nome);
                tem_aluno = true;
            }
            v = v->prox;
        }

        if (tem_aluno == false) {
            printf("Nao ha alunos vinculados a este projeto.\n");
        }
		
		printf("\n");
        cont += 1;//att contador
    }
}
