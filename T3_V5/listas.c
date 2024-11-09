#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listas.h"

/*-----FUNCOES ALUNO-----*/
Aluno* aluno_cria(){
    return NULL;
}

Aluno* aluno_insere(Aluno* a, char* nome, char* mat, char* tel) {
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    strncpy(novo->nome, nome, sizeof(novo->nome));	
    strncpy(novo->matricula, mat, sizeof(novo->matricula));
    strncpy(novo->telefone, tel, sizeof(novo->telefone));
    novo->prox = a;

    return novo;
}

void aluno_imprime(Aluno* a) {
    Aluno* aux;
    int al = 1;
	for(aux=a; aux!=NULL; aux=aux->prox) {
    	printf("\nAluno %d\n", al);
	    printf("Nome: %s\n", aux->nome);
        printf("Matricula: %s\n", aux->matricula);
        printf("Telefone: %s\n", aux->telefone);
        printf("\n");
        al += 1;
    }
}

Aluno* aluno_busca(Aluno* al, char* nome) {
    Aluno* b;
    for (b = al; b != NULL; b = b->prox) {
        if (strcmp(b->nome, nome) == 0) { // Usar strcmp para comparar strings
            return b;
        }
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}

void aluno_libera(Aluno* a)
{
	Aluno* temp;
    while (a != NULL) {
        temp = a;
        a = a->prox;
        free(temp);
    }
}



/*-----FUNCOES PROFESSOR-----*/
Professor* prof_cria(){
	return NULL;
}
Professor* professor_insere(Professor* pr, char* nome, char* cod, char* depto) {
    Professor* novo = (Professor*) malloc(sizeof(Professor));
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    strncpy(novo->nome, nome, sizeof(novo->nome));
    strncpy(novo->cod, cod, sizeof(novo->cod));
    strncpy(novo->depto, depto, sizeof(novo->depto));
    novo->prox = pr;

    return novo;
}

void professor_imprime(Professor* pr) {
    Professor* aux;
    int b = 1;
	for(aux=pr; aux!=NULL; aux=aux->prox) {
		printf("\nProfessor %d\n", b);
        printf("Nome: %s\n", aux->nome);
        printf("Codigo: %s\n", aux->cod);
        printf("Depto: %s\n", aux->depto);
        printf("\n");
        b += 1;
    }
}

Professor* prof_busca(Professor* pr, char* nome) {
    Professor* p;
    for (p = pr; p != NULL; p = p->prox) {
        if (strcmp(p->nome, nome) == 0) { // Usar strcmp para comparar strings
            return p;
        }
    }
    return NULL; // Retorna NULL se o aluno não for encontrado
}

void prof_libera(Professor* pr)
{
    Professor* temp;
    while (pr != NULL) {
        temp = pr;
        pr = pr->prox;
        free(temp);
	}
}


/*-----FUNCOES PROJETO-----*/
// Função para criar uma lista de projetos vazia
Projeto* projeto_cria() {
    return NULL;
}

// Função para inserir um novo projeto na lista de projetos
Projeto* projeto_insere(Projeto* p, char* prof_coord, char* cod, char* desc, int r_tipo, float orc_total, float orc_atual) {
    Projeto* novo = (Projeto*) malloc(sizeof(Projeto));
    if (novo == NULL) {
        printf("Erro na alocacao\n");
        exit(1);
    }

    strncpy(novo->prof_coord, prof_coord, sizeof(novo->prof_coord));
    strncpy(novo->cod, cod, sizeof(novo->cod));
    strncpy(novo->desc, desc, sizeof(novo->desc));
    switch(r_tipo)
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
    Projeto* aux;
    int e = 1;
	for(aux=proj; aux!=NULL; aux=aux->prox) {
		printf("\nProjeto %d\n", e);
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
        aux = aux->prox;
        e += 1;
    }
}

// Função para imprimir todos os projetos na lista
void projeto_imprime(Projeto* p) {
    Projeto* aux;
    int c = 1;
	for(aux=p; aux!=NULL; aux=aux->prox) {
		printf("\nProjeto %d\n", c);
        printf("Codigo: %s\n", aux->cod);
        printf("Descricao: %s\n", aux->desc);
        printf("Professor coordenador: %s\n", aux->prof_coord);
        printf("Tipo: %s\n", aux->tipo);
        printf("Orcamento atual: %.2f\n", aux->orc_atual);
        printf("Orcamento total: %.2f\n", aux->orc_total);
        printf("\n");
        c += 1;
    }
}

Projeto* projeto_busca(Projeto* p, char* cod) {
    Projeto* b;
    for (b = p; b != NULL; b = b->prox) {
        if (strcmp(b->cod, cod) == 0) {
            return b; // Retorna o projeto encontrado
        }
    }
    return NULL; // Retorna NULL se o projeto não for encontrado
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


/*-----FUNCOES VINCULO-----*/
Vinculo* vinculo_cria(){
	return NULL;
}

// Função para inserir um vínculo
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa) {
    if (p == NULL || al == NULL) {
        printf("Erro: Projeto ou Aluno invalido.\n");
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
            printf("Erro ao alocar memoria para o vinculo.\n");
            p->orc_atual += custo_total; // Restaura o orçamento em caso de erro
            return v;
        }

        // Inicializa o novo vínculo
        novo->al = al;
        novo->p = p;
        novo->bolsa_mensal = valor_bolsa;
        novo->prox = v;

        printf("Vinculo inserido com sucesso: Aluno %s vinculado ao projeto %s.\n", al->nome, p->cod);
        return novo;  // Retorna o novo início da lista
    } else {
        printf("Orcamento insuficiente para vincular o aluno %s ao projeto %s.\n", al->nome, p->cod);
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
            printf("Vinculo excluido com sucesso.\n");
            return v;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("Vinculo nao encontrado.\n");
    return v;
}
//Listar vinculos
void vinculo_imprime(Vinculo* lista)
{
	Vinculo* aux;
    int d = 1;
	for(aux=lista; aux!=NULL; aux=aux->prox) {
		printf("\nVinculo %d\n", d);
		printf("-Dados do Aluno-\nAluno: %s - Matricula: %s - Telefone: %s\n", aux->al->nome, aux->al->matricula, aux->al->telefone);
        printf("-Dados do Projeto-\nProjeto: %s - Tipo: - Professor: %s\n", aux->p->cod, aux->p->tipo, aux->p->prof_coord);
        printf("Orcamento atual: %.2f - Orcamento total: %.2f\nDescricao: %s\n", aux->p->orc_atual, aux->p->orc_total, aux->p->desc);
        printf("Bolsa Mensal do aluno: %.2f\n", aux->bolsa_mensal);
        printf("\n");
        d += 1;
	}
}

void vinculo_libera_todos(Vinculo* lista)
{
	Vinculo* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
}
