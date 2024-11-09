#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*-----STRUCT ALUNO-----*/ 
struct aluno {
    char nome[50];
    char matricula[15];
    char telefone[16]; //long int pq n� de telefone tem 9 digitos, e se for o caso do usu�rio inserir o ddd tbm, fica 11 dig�tos (int n�o l� essa quantidade)
    struct aluno* prox;
};
typedef struct aluno Aluno;

Aluno* aluno_cria();

Aluno* aluno_insere(Aluno* a, char* nome, char* mat, char* tel);

void aluno_imprime(Aluno* al);

Aluno* aluno_busca(Aluno* al, char* nome);

void aluno_libera(Aluno* a);


/*-----STRUCT PROFESSOR-----*/
struct professor {
    char nome[50];
    char cod[15];
    char depto[30];
    struct professor* prox;
};
typedef struct professor Professor;

Professor* prof_cria();

Professor* professor_insere(Professor* pr, char* nome, char* cod, char* depto);

void professor_imprime(Professor* pr);

Professor* prof_busca(Professor* pr, char* nome);

void prof_libera(Professor* pr);


/*-----STRUCT PROJETO-----*/
struct projeto {
    char cod[15];
    char desc[200];
    char tipo[10];
    float orc_atual;
    float orc_total;
    char prof_coord[50];
    struct projeto* prox;
};
typedef struct projeto Projeto;

// Cria uma lista vazia de projetos
Projeto* projeto_cria();

// Insere um novo projeto na lista
Projeto* projeto_insere(Projeto* p, char* prof_coord, char* cod, char* desc, int r_tipo, float orc_total, float orc_atual);

// Exclui um projeto da lista (a partir do c�digo do projeto)
Projeto* projeto_exclui(Projeto* lista, char* cod);

// Imprime os detalhes de todos os projetos
void projeto_imprime(Projeto* p);

// Gera um relat�rio de cada projeto com detalhes, incluindo alunos vinculados
void projeto_relatorio(Projeto* p);

void projeto_libera(Projeto* p);

Projeto* projeto_busca(Projeto* p, char* cod);


/*-----STRUCT VINCULO-----*/
struct vinculo {
    Aluno* al;             // Aluno vinculado
    Projeto* p;            // Projeto associado
//    Professor* pr;         // Professor respons�vel
    float bolsa_mensal;    // Valor mensal da bolsa
    struct vinculo* prox;  // Pr�ximo v�nculo na lista
};
typedef struct vinculo Vinculo; // Estrutura de v�nculo entre aluno e projeto, incluindo professor e valor da bolsa

// Cria uma lista de v�nculos vazia
Vinculo* vinculo_cria();

// Insere um novo v�nculo na lista
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa);

// Exclui um v�nculo espec�fico da lista
Vinculo* vinculo_exclui(Vinculo* lista, Aluno* aluno, Projeto* projeto);

// Imprime todos os v�nculos na lista
void vinculo_imprime(Vinculo* lista);

// Libera toda a lista de v�nculos, evitando vazamentos de mem�ria
void vinculo_libera_todos(Vinculo* lista);

#endif // LISTA_H
