#include "projeto_3.h"
#include <stdio.h>
#include <string.h>

int *Contador_Tarefas;
int indice = 0;


//Essa função cria uma tarefa na lista
void Criar_Tarefa( Lista_Tarefas Lista[], int *Contador_Tarefas){    
    Lista_Tarefas tarefa;

    if (*Contador_Tarefas <= 100) {
        printf("Digite a descricao da tarefa: \n");
        scanf("%s", &tarefa.descricao);

        printf("Digite o conteudo da tarefa: \n");
        scanf("%s", &tarefa.conteudo);

        printf("Digite a prioridade desejada(de 0 a 10: \n");
        scanf("%i", &tarefa.prioridade);

        printf("Lista realizada com sucesso!! \n");
        return 1; // Sucesso.

        Lista[*Contador_Tarefas] = tarefa;
        *Contador_Tarefas = *Contador_Tarefas + 1;
    }
    else{
        printf("A lista infelizmente esta full. Remova outra tarefa para poder acrescentar outra. \n");
        return 0; // Falha.
    }
}

//Essa função remove tarefa/s da lista
void Remove_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){
    if (*Contador_Tarefas > 0 && indice > 0 && indice <= *Contador_Tarefas){
        for (int i = indice ; i < *Contador_Tarefas ; ++i) {
            Lista[i] = Lista[i + 1];
        }
        (*Contador_Tarefas --);
        printf("Remoção realizada com sucesso!! \n");
        return 1; // Sucesso.
    }
    else{
        printf("Erro na remoção da tarefa desejada. Tente novamente.. \n");
        return 0; // Erro.
    }
}

//Essa função lista as tarefas ja criadas
void Listar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){

    if (Contador_Tarefas > 0){
        printf("Lista de tarefas: \n");

        for (int i = 0; i < *Contador_Tarefas; ++i) {
            printf("Tarefa: \n", i + 1);
            printf("Descrição: \n", Lista[i].descricao);
            printf("Conteudo: \n", Lista[i].conteudo);
            printf("Prioridade: \n", Lista[i].prioridade);
        }
    } else{
        printf("A lista esta vazia! ");
        return 0; //Erro
}
}