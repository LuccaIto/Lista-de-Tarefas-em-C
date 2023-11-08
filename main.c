#include <stdio.h>
#include <string.h>
#include "projeto_3.h"

int main() {
Lista_Tarefas Lista[100];
int contador_tarefas = 0;
int indice;
int opcao;

do {
    printf("Selecione a tarefa desejada abaixo: \n");
    printf("1. Criar tarefa; \n");
    printf("2. Remover tarefa; \n");
    printf("3. Listar tarefa; \n");
    printf("4. Alterar Tarefa; \n");
    printf("5. Filtrar por Prioridade; \n");
    printf("6. Filtrar por Estado; \n");
    printf("7. Filtrar por Categoria; \n");
    printf("8. Filtrar por Prioridade e Categoria; \n");
    printf("9. Exportar por Prioridade; \n");
    printf("10. Expotar por Categoria; \n");
    printf("11. Exportar por Prioridade e Categoria; \n");


    scanf("%d", &opcao);
    //Clear_buffer();


// acho q estou puxando errado o "contador_tarefas"
    switch (opcao) {
         case 1:
            Criar_Tarefa(Lista, &contador_tarefas);
            break;
        case 2:
            Remove_Tarefas(Lista, &contador_tarefas);
            break;
        case 3:
            Listar_Tarefas(Lista, &contador_tarefas);
            break;

        case 4:
            Alterar_Tarefas(Lista, &contador_tarefas);
            break;

        case 5:
            Filtrar_Prioridade(Lista, &contador_tarefas);
            break;
        
        case 6:
            Filtrar_Estado(Lista, &contador_tarefas);
            break;

        case 7:
            Filtrar_Categoria(Lista, &contador_tarefas);
            break;
        
        case 8:
            Filtrar_Prioridade_Categoria(Lista, &contador_tarefas);
            break;
        
        case 9:
            Exportar_Prioridade(Lista, &contador_tarefas);
            break;
        
        case 10:
            Exportar_Categoria(Lista, &contador_tarefas);
            break;
        
        case 11:
            Exportar_Prioridade_Categoria(Lista, &contador_tarefas);
            break;

        default:
            printf("Nenhuma opção encontrada. Tente novamente.(Opcoes : 1. Criar tarefa; 2. Remover tarefa; 3. Listar tarefa; 4. Alterar_Tarefas; 5. Filtrar_Prioridade; 6. Filtrar_Estado; 7. Filtrar_Categoria; 8. Filtrar_Prioridade_Categoria; 9. Exportar_Prioridade; 10. Expotar_Categoria; 11. Exportar_Prioridade_Categoria;");
    }


}while (opcao != 0);
return 0;

}
