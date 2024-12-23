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
    int mat, tel, cod;
    char depto[10];
    char nome[100];
    char tipo[50];
    char desc[200];
    float orc_aprovado, orc_atual, valor_mensal;

    do {
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
        getchar(); // Limpa o buffer de entrada

        switch(opcao) {
            // 1- Inserir aluno
            case 1:
                printf("Nome do aluno: ");
                scanf("%99s", nome);
                printf("Matricula: ");
                scanf("%d", &mat);
                printf("Telefone: ");
                scanf("%d", &tel);
                al = aluno_insere(al, nome, mat, tel);
                break;

            // 2 - Listar alunos
            case 2:
                aluno_imprime(al);
                break;

            // 3 - Inserir professor
            case 3:
                printf("Nome do professor: ");
                scanf("%99s", nome);
                printf("Código: ");
                scanf("%d", &cod);
                printf("Depto de lotacao: ");
                scanf("%9s", depto);
                pr = professor_insere(pr, nome, cod, depto);
                break;

            // 4 - Listar professores
            case 4:
                professor_imprime(pr);
                break;

            // 5 - Inserir projeto
            case 5:
                printf("Codigo do projeto: ");
                scanf("%d", &cod);
                printf("Descricao: ");
                scanf("%199s", desc);
                printf("Tipo: ");
                scanf("%49s", tipo);
                printf("Orcamento aprovado: ");
                scanf("%f", &orc_aprovado);
                printf("Orcamento atual: ");
                scanf("%f", &orc_atual);
                printf("Nome do professor coordenador: ");
                scanf("%99s", nome);
                p = projeto_insere(p, nome, cod, desc, tipo, orc_aprovado, orc_atual);
                break;

            // 6 - Listar projetos
            case 6:
                projeto_imprime(p);
                break;

            // 7 - Vincular aluno a projeto
          case 7:
            printf("Nome do aluno: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final do nome

            printf("Codigo do projeto: ");
            scanf("%d", &cod);

            printf("Valor mensal da bolsa: ");
            scanf("%f", &valor_mensal);

            // Validação do valor da bolsa
            if (valor_mensal <= 0) {
                printf("Erro: O valor mensal da bolsa deve ser positivo.\n");
                break;
            }

            // Encontre o aluno e o projeto pelos identificadores fornecidos
            Aluno* aluno_encontrado = aluno_busca(al, nome);
            if (aluno_encontrado == NULL) {
                printf("Erro: Aluno não encontrado: %s\n", nome);
                break;
            }

            Projeto* projeto_encontrado = projeto_busca(p, cod);
            if (projeto_encontrado == NULL) {
                printf("Erro: Projeto não encontrado: %d\n", cod);
                break;
            }

            // Inserir o vínculo
            v = vinculo_insere(v, projeto_encontrado, aluno_encontrado, valor_mensal);
            break;


            // 8 - Excluir vínculo de aluno a projeto
            case 8:
                printf("Nome do aluno: ");
                scanf("%99s", nome);
                printf("Codigo do projeto: ");
                scanf("%d", &cod);

                // Encontre o aluno e o projeto pelos identificadores fornecidos
                aluno_encontrado = aluno_busca(al, nome);
                projeto_encontrado = projeto_busca(p, cod);

                if (aluno_encontrado && projeto_encontrado) {
                    v = vinculo_exclui(v, aluno_encontrado, projeto_encontrado);
                } else {
                    printf("Aluno ou projeto não encontrado.\n");
                }
                break;

            // 9 - Listar vínculos
            case 9:
                //vinculo_imprime(v);
                break;
        }
    } while(opcao != 0);

    return 0;
}

