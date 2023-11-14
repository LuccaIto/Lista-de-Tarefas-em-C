#include <stdio.h>
#include <string.h>
#include "projeto_3.h"

int main() {
Lista_Tarefas Lista[100];
int contador_tarefas = 0;
int indice;
int opcao;
int cod;
char arquivo[] = "listatarefa";

cod = Carregar_Tarefa(Lista, &contador_tarefas);
if(cod == 1){
    contador_tarefas = 0;
}

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
    printf("12. Sair; \n");



    scanf("%d", &opcao);
    Clear_buffer();


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
            cod = Salvar_Tarefa(Lista, &contador_tarefas);
                if (cod != 0) {
                    printf("Erro ao salvar as tarefas.\n");
                }
                printf("u");
    }

}while (opcao != 12);

return 0;
}
