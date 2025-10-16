#ifndef PROJETO_3_BANCO_H
#define PROJETO_3_BANCO_H

extern int *Contador_Tarefas;

typedef struct {  //estrutura que define a quantidade e tipo da funcao
    char descricao[50];
    char categoria[50];
    char status[20];
    int prioridade;
} Lista_Tarefas;


int Criar_Tarefa( Lista_Tarefas Lista[], int *Contador_Tarefas);

void Remove_Tarefas( Lista_Tarefas Lista[], int *Contador_Tarefas);

void Listar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas);

void Alterar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas);

void Filtrar_Prioridade(Lista_Tarefas Lista[], int *Contador_Tarefas);

void Filtrar_Estado(Lista_Tarefas Lista[], int *Contador_Tarefas);

void Filtrar_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas);

void Filtrar_Prioridade_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas);

int Exportar_Prioridade(Lista_Tarefas Lista[], int *Contador_Tarefas);

int Exportar_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas);

int Exportar_Prioridade_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas);

void Clear_buffer();

void Ordenar_Por_Prioridade(Lista_Tarefas Lista[], int Contador_Tarefas);

int Carregar_Tarefa(Lista_Tarefas Lista[], int *Contador_Tarefas);

int Salvar_Tarefa(Lista_Tarefas Lista[], int *Contador_Tarefas);

#endif //PROJETO_2_BANCO_H