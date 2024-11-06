#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct projeto {
    int cod;
    char desc[100]; 
    char tipo[20]; 
    float orc_atual;
    float orc_total;
    char prof_coord[50]; 
    
    struct projeto* prox;
    }Projeto;

// Cria uma lista vazia de projetos
Projeto* projeto_cria();

// Insere um novo projeto na lista
Projeto* projeto_insere(Projeto* p, const char* prof_coord, int cod, const char* desc, const char* tipo, float orc_total, float orc_atual);

// Exclui um projeto da lista (a partir do código do projeto)
Projeto* projeto_exclui(Projeto* lista, int cod);

// Imprime os detalhes de todos os projetos
void projeto_imprime(Projeto* p);

// Gera um relatório de cada projeto com detalhes, incluindo alunos vinculados
void projeto_relatorio(Projeto* p);
