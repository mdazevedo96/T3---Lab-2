#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "projeto.h"

int main() {
    Aluno* al = NULL;
    Projeto* p = NULL;
    
    // Inserção de alunos
    al = aluno_insere(al, "Marcelo", 1, 21);
    al = aluno_insere(al, "Paula", 2, 3);

    // Impressão da lista de alunos
    aluno_imprime(al);

    // Inserção de projetos
    p = projeto_insere(p, "Candia", 1, "Teste 1", "Extensao", 250, 100);
    p = projeto_insere(p, "Ceretta", 2, "Teste 2", "Ensino", 500, 250);

    // Impressão da lista de projetos
    projeto_imprime(p);

    return 0;
}