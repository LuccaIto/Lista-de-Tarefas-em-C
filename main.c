#include <stdio.h>
#include <string.h>
#include "projeto_3.h"

int main() {
Lista_Tarefas Lista[100];  //Lista de Tarefas com no maximo 100 posições
int contador_tarefas = 0;  //ultima posicao na lista Lista[]
int opcao;  //diz a tarefa que sera usada pelo usuario
int cod;

cod = Carregar_Tarefa(Lista, &contador_tarefas);  //utiliza da funcao "Carregar_Tarefa" para carregar as tarefas feitas dentro do programa.
if(cod == 1){  //a condicao so sera realizada quando o "cod" for igual a "1".
    contador_tarefas = 0;
}

do {
    printf("Selecione a tarefa desejada abaixo: \n");  //opcoes abaixo vao ser escolhidas pelo usuario e serao aplicadas entro das opcoes do "switch" abaixo.
    printf("1. Criar tarefa; \n");  //pede para o usuario criar uma tarefa.
    printf("2. Remover tarefa; \n");  //pede para o usuario remover uma tarefa.
    printf("3. Listar tarefa; \n");  //pede para o usuario listar uma tarefa.
    printf("4. Alterar Tarefa; \n");  //pede para o usuario alterar uma tarefa.
    printf("5. Filtrar por Prioridade; \n");  //pede para o usuario filtrar por prioridade a tarefa.
    printf("6. Filtrar por Estado; \n");  //pede para o usuario filtrar por estado a tarefa.
    printf("7. Filtrar por Categoria; \n");  //pede para o usuario filtrar por categoria a tarefa.
    printf("8. Filtrar por Prioridade e Categoria; \n");  //pede para o usuario filtrar por categoria e por prioridade a tarefa.
    printf("9. Exportar por Prioridade; \n");  //pede para o usuario exportar por prioridade uma tarefa.
    printf("10. Expotar por Categoria; \n");  //pede para o usuario exportar por categoria uma tarefa.
    printf("11. Exportar por Prioridade e Categoria; \n");  //pede para o usuario exportar por prioridade e categoria uma tarefa.
    printf("12. Sair; \n");  //diz que vai fechar o programa.
    

    scanf("%d", &opcao);
    Clear_buffer();


    switch (opcao) {  //faz com que as escolhas do usuario acima(dentro da funcao "do") seja compativel com os "case's" abaixo.
         case 1:
            Criar_Tarefa(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Criar_Tarefa" para criar uma tarefa dentro da lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        case 2:
            Remove_Tarefas(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Remove_Tarefas" para remover uma tarefa dentro da lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        case 3:
            Listar_Tarefas(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Listar_Tarefas" para listar uma tarefa dentro da lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao

        case 4:
            Alterar_Tarefas(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Alterar_Tarefas" para alterar uma tarefa dentro da lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao

        case 5:
            Filtrar_Prioridade(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Filtrar_Prioridade" para filtrar por prioridade a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        
        case 6:
            Filtrar_Estado(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Filtrar_Estado" para filtrar por estado a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao

        case 7:
            Filtrar_Categoria(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Filtrar_Categoria" para filtrar por categoria a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        
        case 8:
            Filtrar_Prioridade_Categoria(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Filtrar_Prioridade_Categoria" para filtrar por prioridade e categoria a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        
        case 9:
            Exportar_Prioridade(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Exportar_Prioridade" para exportar por prioridade a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        
        case 10:
            Exportar_Categoria(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Exportar_Categoria" para exportar por categoria a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao
        
        case 11:
            Exportar_Prioridade_Categoria(Lista, &contador_tarefas);  //utiliza a funcao(dentro do "projeto_3.c") "Exportar_Prioridade_Categoria" para exportar por prioridade e categoria a lista, tendo como o ultimo termo/posicao o " &contador_tarefas"
            break;  //termina a acao puxada pelo "case" em questao

        case 12:
            cod = Salvar_Tarefa(Lista, &contador_tarefas);  //utiliza da funcao "Salvar_Tarefa" para salvar essa tarefa dentro do programa.
                if (cod != 0) {  //a condicao so sera realizada quando o "cod" ser diferente de 0.
                    printf("Erro ao salvar as tarefas.\n");
                }
                printf("u");
            break;
    }

}while (opcao != 12);  //faz a funcao "do" ate que a opcao seja diferente de "12"

return 0;
}
