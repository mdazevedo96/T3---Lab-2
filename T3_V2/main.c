#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "projeto.h"
#include "professor.h"

int main() {
    Aluno* al = NULL;
    Projeto* p = NULL;
    Professor* pr = NULL;
    
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

    //Inserção de professor
    pr = professor_insere(pr, "Mateus", 01, "ELC");
    pr = professor_insere(pr, "Patricia", 02, "LACC");

    //Impressao de listas de professores
    professor_imprime(pr);

    return 0;
}