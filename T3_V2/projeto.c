#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"
#include "professor.h"
#include "aluno.h"

Projeto* projeto_insere(Projeto* p, Professor* prof_resp, int cod, char* desc, char* tipo, float orc, float orc_atual){
    Projeto* novo = (Projeto*) malloc(sizeof(Projeto));
    if(!novo){
        printf("Erro de alocacao");
        exit(1);
    }
    novo->cod = cod;
    novo->desc = strdup(desc);
    novo->tipo = strdup(tipo);
    novo->orc = orc;
    novo->orc_atual = orc_atual;
    novo->prof_resp = prof_resp;
    novo->prox = p;

    return novo;
}


/*Um aluno só pode ser vinculado a um projeto se houver orçamento atual disponível para o
pagamento da sua bolsa por 12 meses (assuma que o orçamento aprovado para o projeto também
se refere a 12 meses);*/
/*bool verificaOrcamento(Aluno* al, Projeto* p){
   if (p == NULL || al == NULL){
        return false;
   }
    return p->orc_atual <= p-> orc;
} 
*/
/*
O orçamento atual disponível de um projeto deve ser atualizado sempre que um novo aluno for
vinculado àquele projeto. Por exemplo, supondo que o projeto foi aprovado com orçamento de 30
mil reais e há 3 bolsistas vinculados com bolsa de 500 reais mensais cada um (3*500*12=18000
reais), ainda restam 12 mil reais como orçamento atual disponível;
*/

/*
Para excluir um vínculo, são fornecidos como entrada o número da matrícula, o código do projeto
e a quantidade de meses em que a bolsa não vai ser mais paga; neste caso, o restante do valor da
bolsa não utilizado é creditado no orçamento atual disponível do projeto;
*/

/*
Um projeto só pode ser coordenado por um professor existente previamente cadastrado;
*/

/*
Um vínculo só pode ser criado para um aluno existente e em um projeto existente, previamente
cadastrados;
*/

/*
Não pode haver duplicidade de informações sobre alunos, projetos e professores. Por exemplo, um
vínculo não armazena/replica os dados de alunos e projetos, mas guarda apenas ponteiros que
apontam para os respectivos aluno e projeto já previamente cadastrados. Um projeto não
armazena/replica informações sobre professores, mas guarda apenas um ponteiro para o respectivo
professor já previamente cadastrado.
*/

/*
Ao final, deve ser gerado o seguinte relatório: para cada projeto cadastrado, imprimir: código do projeto, tipo
do projeto, nome do professor coordenador do projeto, orçamento atual disponível para o projeto e nome dos
alunos vinculados a este projeto (se houver). Se não houver nenhum aluno vinculado a este projeto, deve ser
mostrada a mensagem “não há alunos vinculados a este projeto”.
*/

/*void imprime_relatorio(Projeto* proj, Professor* prof,Aluno* al){
    Projeto* p;
    for(p = proj; p!=NULL; p=p->prox){
        printf("Codigo do projeto: %d\n", proj->cod);
        printf("Tipo: %d\n", proj->tipo);
        printf("Nome do professor coordenador: %s\n", proj->prof_resp);
        printf("Orcamento atual: %f\n", proj->orc_atual);
        //printf("Alunos vinculados ao projeto %d: %s\n", proj->cod, proj->alunos);

    }

}
*/