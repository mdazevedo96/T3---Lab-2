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
    char telefone[16]; //long int pq nº de telefone tem 9 digitos, e se for o caso do usuário inserir o ddd tbm, fica 11 digítos (int não lê essa quantidade)
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

// Exclui um projeto da lista (a partir do código do projeto)
Projeto* projeto_exclui(Projeto* lista, char* cod);

// Imprime os detalhes de todos os projetos
void projeto_imprime(Projeto* p);

// Gera um relatório de cada projeto com detalhes, incluindo alunos vinculados
void projeto_relatorio(Projeto* p);

void projeto_libera(Projeto* p);

Projeto* projeto_busca(Projeto* p, char* cod);


/*-----STRUCT VINCULO-----*/
struct vinculo {
    Aluno* al;             // Aluno vinculado
    Projeto* p;            // Projeto associado
//    Professor* pr;         // Professor responsável
    float bolsa_mensal;    // Valor mensal da bolsa
    struct vinculo* prox;  // Próximo vínculo na lista
};
typedef struct vinculo Vinculo; // Estrutura de vínculo entre aluno e projeto, incluindo professor e valor da bolsa

// Cria uma lista de vínculos vazia
Vinculo* vinculo_cria();

// Insere um novo vínculo na lista
Vinculo* vinculo_insere(Vinculo* v, Projeto* p, Aluno* al, float valor_bolsa);

// Exclui um vínculo específico da lista
Vinculo* vinculo_exclui(Vinculo* lista, Aluno* aluno, Projeto* projeto);

// Imprime todos os vínculos na lista
void vinculo_imprime(Vinculo* lista);

// Libera toda a lista de vínculos, evitando vazamentos de memória
void vinculo_libera_todos(Vinculo* lista);

#endif // LISTA_H
