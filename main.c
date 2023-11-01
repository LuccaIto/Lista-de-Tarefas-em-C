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
    printf("4. ; \n");
    printf("5. ; \n");
    printf("6. ; \n");
    printf("7. ; \n");
    printf("8. ; \n");

    scanf("%d", &opcao);
    //Clear_buffer();

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
            break;

        case 5:
            break;
        
        case 6:
            break;

        case 7:
            break;
        
        case 8:
            break;
        
        case 9:
            break;
            
        default:
            printf("Nenhuma opção encontrada. Tente novamente.(Opcoes : 1. Criar tarefa; 2. Remover tarefa; 3. Listar tarefa; 4. ; ");
    }


}while (opcao != 9);
return 0;

}
// menu();

// scanf(" %d", opcao);
// Clear_buffer();

// if(opcao == 1){
//     Criar_Tarefa(Lista, &contador_tarefas);
// }while(opcao != 9);

//}