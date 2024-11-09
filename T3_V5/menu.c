#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listas.h"
#include "menu.h"

void menu(){
	
	Aluno* al = aluno_cria();
    Projeto* p = projeto_cria();
    Professor* pr = prof_cria();
    Vinculo* v = vinculo_cria();
    int opcao;
    
    do {
    	int resp;//leitura do tipo
	    char nome[50], cod[15]; //variaveis usadas para mais de um case
        char mat[15], tel[20]; //vars do aluno
    	char depto[30]; //vars do professor
    	char tipo[10], desc[200]; //vars do projeto
    	float orc_aprovado, orc_atual, valor_mensal; //vars do projeto e para vinculo(v_mensal)
    	
        printf("\nDIGITE UMA DAS OPCOES:\n");
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

		printf("OPCAO ESCOLHIDA: ");
        scanf("%d", &opcao);
		while((getchar()) != '\n'); 

        switch(opcao) {
            // 1- Inserir aluno
            case 1:
                printf("Nome do aluno: ");
                fgets(nome, sizeof(nome), stdin);  // Le string
                nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' do final da string
                
                printf("Matricula: ");
                fgets(mat, sizeof(mat), stdin);
                mat[strcspn(mat, "\n")] = '\0';
                
                printf("Telefone: ");
                fgets(tel, sizeof(tel), stdin);
                tel[strcspn(tel, "\n")] = '\0';
                
                al = aluno_insere(al, nome, mat, tel);  // "Salva" os dados inseridos em um novo noh da lista 
                break;

            // 2 - Listar alunos
            case 2:
                aluno_imprime(al);
                break;

            // 3 - Inserir professor
            case 3:
                printf("Nome do professor: ");
                fgets(nome, sizeof(nome), stdin);  // Le string
                nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final da string
                
                printf("Codigo: ");
                fgets(cod, sizeof(cod), stdin);
                cod[strcspn(cod, "\n")] = '\0';
                
                printf("Departamento de lotacao: ");
                fgets(depto, sizeof(depto), stdin);
                depto[strcspn(depto, "\n")] = '\0';
                
                pr = professor_insere(pr, nome, cod, depto);  // "Salva" os dados inseridos em um novo noh da lista 
                break;

            // 4 - Listar professores
            case 4:
                professor_imprime(pr);
                break;

            // 5 - Inserir projeto
            case 5:
                printf("Codigo do projeto: ");
                fgets(cod, sizeof(cod), stdin);  // Le string
                cod[strcspn(cod, "\n")] = '\0';  // Remove o '\n' no final da string
                
                printf("Descricao: ");
                fgets(desc, sizeof(desc), stdin);
                desc[strcspn(desc, "\n")] = '\0';                
                
                printf("Tipo: 1-Ensino, 2-Pesquisa, 3-Extensao: ");
                scanf("%d", &resp);
                
                printf("Orcamento aprovado(ex: 0.00): ");
                scanf("%f", &orc_aprovado);  // Le float
                
                printf("Orcamento atual(ex: 0.00): ");
                scanf("%f", &orc_atual);  // Le float
                
           		while((getchar()) != '\n'); 
                printf("Nome do professor coordenador: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                
                Professor* prof_encontrado = prof_busca(pr, nome);
				if (prof_encontrado!=NULL) {                
                	p = projeto_insere(p, nome, cod, desc, resp, orc_aprovado, orc_atual);  // "Salva" os dados inseridos em um novo noh da lista
				} else {
                    printf("Erro: Nao ha professor cadastrado para vincular ao projeto.\n");
                } 
                break;

            // 6 - Listar projetos
            case 6:
                projeto_imprime(p);
                break;

            // 7 - Vincular aluno a projeto
          case 7:
            printf("Nome do aluno: ");
            fgets(nome, sizeof(nome), stdin);  //le string
            nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final da string

            printf("Codigo do projeto: ");
            fgets(cod, sizeof(cod), stdin);
            cod[strcspn(cod, "\n")] = '\0';

            printf("Valor mensal da bolsa(ex: 0.00): ");
            scanf("%f", &valor_mensal);  // Le float

            // Validação do valor da bolsa
            if (valor_mensal <= 0) {
                printf("Erro: O valor mensal da bolsa deve ser um valor positivo.\n");
                break;
            }

            // Encontre o aluno e o projeto pelos identificadores fornecidos
		    Aluno* aluno_encontrado = aluno_busca(al, nome);
            Projeto* projeto_encontrado = projeto_busca(p, cod);
            
			// Inserir o vínculo
            if (aluno_encontrado!=NULL && projeto_encontrado!=NULL) {
            	v = vinculo_insere(v, projeto_encontrado, aluno_encontrado, valor_mensal);  // "Salva" os dados inseridos em um novo noh da lista
            }else{
            	printf("Erro: Aluno ou projeto não encontrado.\n");	
			}
			break;

            // 8 - Excluir vínculo de aluno a projeto
            case 8:
                printf("Nome do aluno: ");
                fgets(nome, sizeof(nome), stdin);  // Le string
                nome[strcspn(nome, "\n")] = '\0';  // Remove o '\n' no final da string
                
                printf("Codigo do projeto: ");
                fgets(cod, sizeof(cod), stdin);
                cod[strcspn(cod, "\n")] = '\0';

                // Encontre o aluno e o projeto pelos identificadores fornecidos
                aluno_encontrado = aluno_busca(al, nome);
                projeto_encontrado = projeto_busca(p, cod);

				// Inserir o vínculo
                if (aluno_encontrado && projeto_encontrado) {
                    v = vinculo_exclui(v, aluno_encontrado, projeto_encontrado);
                } else {
                    printf("Aluno ou projeto nao encontrado.\n");
                }
                break;

            // 9 - Listar vínculos
            case 9:
                //vinculo_imprime(v);
                vinculo_imprime(v);
                break;
        }
    } while(opcao != 0);
    
    printf("\nRELATORIO:\n");
    imprime_relatorio(p, v);
    
    aluno_libera(al);
    prof_libera(pr);
    projeto_libera(p);
	vinculo_libera_todos(v);
}
