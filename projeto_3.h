#ifndef PROJETO_3_BANCO_H
#define PROJETO_3_BANCO_H

int *Contador_Tarefas;

typedef struct {
    char descricao[300];
    char conteudo[100];
    int prioridade;
} Lista_Tarefas;

void Criar_Tarefa( Lista_Tarefas Lista[], int *Contador_Tarefas);

void Remove_Tarefas( Lista_Tarefas Lista[], int *Contador_Tarefas);

void Listar_Tarefas( Lista_Tarefas Lista[], int *Contador_Tarefas);

#endif //PROJETO_2_BANCO_H