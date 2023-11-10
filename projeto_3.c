#include "projeto_3.h"
#include <stdio.h>
#include <string.h>

int *Contador_Tarefas;  //ultima posição da lista .
int indice = 0;
//

// Duvidas abaixo:
// apagar_tarefas
// alterar_trefas

//

// int menu(){
//     printf("Selecione a tarefa desejada abaixo: \n");
//     printf("1. Criar tarefa; \n");
//     printf("2. Remover tarefa; \n");
//     printf("3. Listar tarefa; \n");
//     printf("4. ; \n");
//     printf("5. ; \n");
//     printf("6. ; \n");
//     printf("7. ; \n");
//     printf("8. ; \n");
// }

//Essa função cria uma tarefa na lista .
int Criar_Tarefa( Lista_Tarefas Lista[], int *Contador_Tarefas){    

    if (*Contador_Tarefas <= 100) {  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for menor ou igual a 100 .
        printf("\n --> Digite a descricao da tarefa: ");
        scanf("%s", Lista[*Contador_Tarefas].descricao);  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].descricao .
        Clear_buffer();

        printf("\n --> Digite o conteudo da tarefa: ");
        scanf("%s", Lista[*Contador_Tarefas].categoria);  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].conteudo .
        Clear_buffer();

        printf("\n --> Digite a prioridade desejada(de 0 a 10): ");  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].prioridade .
        scanf("%d", &Lista[*Contador_Tarefas].prioridade);
        Clear_buffer();

        printf("\n --> Digitar status: ");  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].status .
        scanf("%s", Lista[*Contador_Tarefas].status);

        printf("\n -_-_-Lista realizada com sucesso!!-_-_- \n");
        

        *Contador_Tarefas = *Contador_Tarefas + 1;  //Faz com que se acrescente uma posição na lista após a criação da anterior .
        return 1; //Sucesso .
    }
    else{
        printf("-_-_-A lista infelizmente esta cheia. Remova outra tarefa para poder acrescentar outra.-_-_- \n");
        return 0; // Falha .
    }
}

//Essa função remove tarefa/s da lista
void Remove_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){
    char remove_descricao[50];

    if (*Contador_Tarefas > 0 ){
        printf("--> digite a descricao da tarefa: ");
        scanf("%s", remove_descricao); 
        Clear_buffer();

        for (int i = 0 ; i < *Contador_Tarefas ; ++i) {
            // if(strcmp(remove_descricao,Lista[*Contador_Tarefas].descricao) == 0) essa seria a funcao certa nao?
            if(strcmp(remove_descricao,Lista[i].descricao) == 0){
            Lista[i] = Lista[i + 1];

            printf(" -_-_-Lista deletada com sucesso!-_-_- ");
            printf("\n");
            }
            else{
                printf("-_-_-Descricao nao encontrada...-_-_- \n");
                printf("\n");
            }
        }
        (*Contador_Tarefas --);
    }
    else{
        printf("-_-_-Erro na remoção da tarefa desejada. Tente novamente...-_-_- \n");
        printf("\n");
    }
}

//Essa função lista as tarefas ja criadas
void Listar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){

    if (*Contador_Tarefas > 0){
        printf("--> Lista de tarefas: \n");

        for (int i = 0; i < *Contador_Tarefas; ++i) {
            printf("\n Tarefa: %d\n", i + 1);
            printf(" -->   Descrição:  %s\n", Lista[i].descricao);
            printf(" -->   Conteudo:  %s\n", Lista[i].categoria);
            printf(" -->   Prioridade:  %d\n", Lista[i].prioridade);
            printf(" -->   Status:  %s\n", Lista[i].status);
            printf("\n");
        }
    } else{
        printf("\n -_-_- A lista esta vazia! -_-_- \n");
        printf("\n");
}
}

void Alterar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){
    char altera_descricao[50];
    char nova_descricao[50];
    char nova_categoria[50];
    int nova_prioridade;
    char novo_status[20];

    if (*Contador_Tarefas > 0 ){
        printf("\n --> digite a descricao da tarefa a ser alterada: \n");
        scanf("%s", altera_descricao);
        Clear_buffer();

        for (int i = 0 ; i < *Contador_Tarefas ; ++i) {
            if(strcmp(altera_descricao,Lista[i].descricao) == 0){
                printf("--> Digite a nova descricao: \n");
                // salvar no scanf como Lista[i].descricao seria o certo?
                scanf(" %[^\n]", nova_descricao);
                Clear_buffer();

                printf("--> Digite o novo conteudo: \n");
                scanf(" %[^\n]", nova_categoria);
                Clear_buffer();

                printf("--> Digite a nova prioridade: \n");
                scanf("%d", &nova_prioridade);
                Clear_buffer();

                printf("--> Digite o novo status: \n");
                scanf(" %[^\n]", novo_status);
                Clear_buffer();
// problema em salvar as novas descricoes na lista
                nova_descricao == Lista[i].descricao;
                nova_categoria == Lista[i].categoria;
                nova_prioridade == Lista[i].prioridade;
                novo_status == Lista[i].status;

                printf("\n");
            }
            else{
                printf("\n -_-_- Descricao nao encontrada... -_-_- \n");
                printf("\n");
            }
        }
        
    }
}

void Filtrar_Prioridade(Lista_Tarefas Lista[], int *Contador_Tarefas){
    int prioridade_escolhida;

    if(*Contador_Tarefas > 0){
        printf("Digite a prioridade escolhida: \n");
        scanf("%d", &prioridade_escolhida);
        Clear_buffer();

        for (int i = 0; i < *Contador_Tarefas; ++i) {
            if(prioridade_escolhida == Lista[i].prioridade){
                printf("\n Lista %d\n", i + 1);
                printf("Descricao: %s\n", Lista[i].descricao);
                printf("Categoria: %s\n", Lista[i].categoria);
                printf("Prioridade: %d\n", Lista[i].prioridade);
                printf("Status: %s\n", Lista[i].status);
                printf("\n");

            }
        }   
}
}

void Filtrar_Estado(Lista_Tarefas Lista[], int *Contador_Tarefas){
    char status_escolhido[20];

    if(*Contador_Tarefas > 0){
        printf("Digite o Estado escolhido: \n");
        scanf("%s", status_escolhido);
        Clear_buffer();

        for (int i = 0; i < *Contador_Tarefas; ++i) {
            if(strcmp(status_escolhido, Lista[i].status) == 0 ){
                printf("\n Lista %d\n", i + 1);
                printf("Descricao: %s\n", Lista[i].descricao);
                printf("Categoria: %s\n", Lista[i].categoria);
                printf("Prioridade: %d\n", Lista[i].prioridade);
                printf("Status: %s\n", Lista[i].status);
                printf("\n");
            }
        }   
    }
}

void Filtrar_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas) {
    char categoria_escolhida[50];

    if (*Contador_Tarefas > 0) {
        printf("Digite a categoria escolhida: \n");
        scanf(" %[^\n]", categoria_escolhida);
        Clear_buffer();

        // Filtrar as tarefas correspondentes à categoria escolhida
        int tarefasFiltradas = 0;
        for (int i = 0; i < *Contador_Tarefas; ++i) {
            if (strcmp(categoria_escolhida, Lista[i].categoria) == 0) {
                tarefasFiltradas++;
            }
        }

        if (tarefasFiltradas > 0) {
            // Criar uma cópia das tarefas correspondentes
            Lista_Tarefas tarefasCorrespondentes[tarefasFiltradas];
            int index = 0;

            for (int i = 0; i < *Contador_Tarefas; ++i) {
                if (strcmp(categoria_escolhida, Lista[i].categoria) == 0) {
                    tarefasCorrespondentes[index++] = Lista[i];
                }
            }

            // Ordenar as tarefas correspondentes por prioridade
            Ordenar_Por_Prioridade(tarefasCorrespondentes, tarefasFiltradas);

            // Imprimir as tarefas ordenadas
            printf("--> Tarefas filtradas e ordenadas por prioridade:\n");
            for (int i = 0; i < tarefasFiltradas; ++i) {
                printf("\n Tarefa %d\n", i + 1);
                printf("Descricao: %s\n", tarefasCorrespondentes[i].descricao);
                printf("Categoria: %s\n", tarefasCorrespondentes[i].categoria);
                printf("Prioridade: %d\n", tarefasCorrespondentes[i].prioridade);
                printf("Status: %s\n", tarefasCorrespondentes[i].status);
                printf("\n");
            }
        } else {
            printf("\n -_-_- Categoria nao encontrada... -_-_- \n");
        }
    }
}


void Filtrar_Prioridade_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas){
    char categoria_escolhida[50];
    int prioridade_escolhida;

    if(*Contador_Tarefas){
        printf("Digite a categoria: \n");
        scanf("%s", categoria_escolhida);
        // Clear_buffer();

        printf("Digite a prioridade: \n");
        scanf("%d", &prioridade_escolhida);
        // Clear_buffer();

        for(int i = 0; i < *Contador_Tarefas; i ++){
            if(strcmp(categoria_escolhida,Lista[i].categoria) == 0 && prioridade_escolhida == Lista[i].prioridade){
                printf("\n Lista %d\n", i + 1);
                printf("Descricao: %s\n", Lista[i].descricao);
                printf("Categoria: %s\n", Lista[i].categoria);
                printf("Prioridade: %d\n", Lista[i].prioridade);
                printf("Status: %s\n", Lista[i].status);
                printf("\n");
            }
        }
    }
}

void Exportar_Prioridade(Lista_Tarefas Lista[], int *Contador_Tarefas){
    Lista_Tarefas Prioridade[100];

    for

}

void Exportar_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas){

}

void Exportar_Prioridade_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas){

}

void Clear_buffer(){  //evita erros com a funcao scanf
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void Ordenar_Por_Prioridade(Lista_Tarefas Lista[], int Contador_Tarefas) {
    // Implementação simples do algoritmo de ordenação de bolhas
    for (int i = 0; i < Contador_Tarefas ; ++i) {
        for (int j = 0; j < Contador_Tarefas - i - 1; ++j) {
            if (Lista[j].prioridade > Lista[j + 1].prioridade) {
                // Troca as posições se a prioridade for maior
                Lista_Tarefas temp = Lista[j];
                Lista[j] = Lista[j + 1];
                Lista[j + 1] = temp;
            }
        }
    }
}

int Carregar_Tarefa(Lista_Tarefas Lista[], int *Contador_Tarefas){
    FILE *f = fopen("Lista", "rb");
    if(f == NULL){
        return 1;
    }
    else{
        fread(Contador_Tarefas,sizeof(Lista_Tarefas), 1, f);
        fclose(f);
    }
    return 0;

}

int Salvar_Tarefa(Lista_Tarefas Lista[], int *Contador_Tarefas){
    FILE *f = fopen("Lista", "wb");
    if(f == NULL){
        return 1;
    }
    else{
        fwrite(Contador_Tarefas,sizeof(Lista_Tarefas), 1, f);
        fclose(f);
    }
    return 0;
}