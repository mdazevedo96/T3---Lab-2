#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aluno.h"
#include "projeto.h"
#include "professor.h"
#include "vinculo.h"

int main() {
    
    Aluno* al = NULL;
    Projeto* p = NULL;
    Professor* pr = NULL;
    Vinculo* v = NULL;
    int opcao;
    int mat, tel, cod, depto = 0;
    char* tipo, desc, nome;
    float orc_aprovado, orc_atual, valor_mensal = 0;

    do{

    printf("Digite uma das opcoes:\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Inserir professor\n");
    printf("4 - Listar professores\n");
    printf("5 - Inserir projeto\n");
    printf("6 - Listar projeto\n");
    printf("7 - Vincular aluno a projeto\n");
    printf("8 - Excluir vinculo de aluno a projeto\n");
    printf("9 - Listar vinculos\n");
    printf("0 - Sair\n");
    
    scanf("%d", &opcao);

    switch(opcao){
        //1- Inserir aluno
        case 1:
            printf("Nome do aluno: %s\n", &nome);
            printf("Matricula: %d\n", &mat);
            printf("Telefone: %d", &tel);
            al = aluno_insere(al,nome, mat, tel);
    
        //2 - Listar alunos
        case 2:
            aluno_imprime(al);

        //3 - Inserir professor
        case 3:
            printf("Nome: %s\n", &nome);
            printf("Código: %d\n", &cod);
            printf("Depto de lotacao: %s\n", &depto);
            
             pr = professor_insere(pr, nome, cod, depto);

        //4 - Listas professores
        case 4:
            professor_imprime(pr);

        //5 - Inserir projeto
        case 5:
            printf("Codigo: %d\n", &cod);
            printf("Descricao: %s\n", &desc);
            printf("Tipo: %s\n", &tipo);
            printf("Orcamento aprovado: %f\n", &orc_aprovado);
            printf("Orcamentao atual: %f\n", &orc_atual);
            printf("Professor coord: %s\n", &nome);

        //6 - Listar projeto
        case 6: 
            projeto_imprime(p);

        //7 - Vincular aluno a projeto
        case 7:
            printf("Nome do aluno: %s\n", &nome);
            printf("Codigo projeto: %d\n", &cod);
            printf("Valor mensal da bolsa: %f\n", &valor_mensal);
            //v = vinculo_insere(nome, cod, valor_mensal);

    }
        
    }while(opcao !=0);


    return 0;
}