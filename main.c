#include <stdio.h>
#include <string.h>
#include "projeto_3.h"

int main() {
Lista_Tarefas Lista[100];
int contador_tarefas = 0;
int opcao;
int indice;

do {
    printf("Selecione a tarefa desejada abaixo: \n");
    printf("1. Criar tarefa; \n");
    printf("2. Remover tarefa; \n");
    printf("3. Listar tarefa; \n");
    printf("4. Finalizar; \n");
    scanf("%d ", &opcao);
    getchar();

    switch (opcao) {
         case 1:
            Criar_Tarefa(Lista, &contador_tarefas);
            break;

        case 2:
            Remove_Tarefas(Lista, &contador_tarefas);

        case 3:
            Listar_Tarefas(Lista, &contador_tarefas);
            break;

        case 4:
            
            break;

        default:
            printf("Nenhuma opção encontrada. Tente novamente.(Opcoes : 1. Criar tarefa; 2. Remover tarefa; 3. Listar tarefa; 4. Finalizar; ");
    }

} while (opcao != 4);
return 0;

}
