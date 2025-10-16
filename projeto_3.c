#include "projeto_3.h"
#include <stdio.h>
#include <string.h>

int *Contador_Tarefas;  //ultima posição da lista .
int indice = 0;


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
int Criar_Tarefa( Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por prioridade a Lista[]

    if (*Contador_Tarefas <= 100) {  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for menor ou igual a 100 .
        printf("\n --> Digite a descricao da tarefa: ");
        scanf(" %[^\n]", Lista[*Contador_Tarefas].descricao);  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].descricao .
        Clear_buffer();

        printf("\n --> Digite o conteudo da tarefa: ");
        scanf(" %[^\n]", Lista[*Contador_Tarefas].categoria);  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].conteudo .
        Clear_buffer();

        printf("\n --> Digite a prioridade desejada(de 0 a 10): ");
        scanf("%d", &Lista[*Contador_Tarefas].prioridade);  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].prioridade .
        Clear_buffer();

        printf("\n --> Digitar status: "); 
        scanf(" %[^\n]", Lista[*Contador_Tarefas].status);  //Salva a descricao escrita pelo cliente em Lista[*Contador_Tarefas].prioridade .

        printf("\n -_-_-Lista realizada com sucesso!!-_-_- \n");
        

        *Contador_Tarefas = *Contador_Tarefas + 1;  //Faz com que se acrescente uma posição na lista após a criação da anterior .
        return 1; //Sucesso .
    }
    else{
        printf("-_-_-A lista infelizmente esta cheia. Remova outra tarefa para poder acrescentar outra.-_-_- \n");
        return 0; // Falha .
    }
}

void Remove_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função remove tarefa/s da lista
    char remove_descricao[50];  //char criado para armazenar a descrição pedida(logo abaixo) ao usuario, contendo o mesmo numero de casas limite que em Lista[i].descricao

    if (*Contador_Tarefas > 0 ){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("--> digite a descricao da tarefa: ");
        scanf("%s", remove_descricao);  //guarda o que foi escrito pelo usuario em "remove_descricao" .
        Clear_buffer();  

        for (int i = 0 ; i < *Contador_Tarefas ; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao .
            if(strcmp(remove_descricao,Lista[i].descricao) == 0){  //condicao que so se aplica quando a descricao escrita pelo usuario em "remove_descricao" for igual a "Lista[i].descricao" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
            Lista[i] = Lista[i + 1];  //substitui a posicao a frente pela posicao atual

            printf(" -_-_-Lista deletada com sucesso!-_-_- ");
            printf("\n");
            }
            else{
                printf("-_-_-Descricao nao encontrada...-_-_- \n");
                printf("\n");
            }
        }
        (*Contador_Tarefas --);  //Remove a ultima posicao da tarefa 
    }
    else{
        printf("-_-_-Erro na remoção da tarefa desejada. Tente novamente...-_-_- \n");
        printf("\n");
    }
}

void Listar_Tarefas(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função lista as tarefas ja criadas

    if (*Contador_Tarefas > 0){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("--> Lista de tarefas: \n");

        for (int i = 0; i < *Contador_Tarefas; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao .
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
    // char nova_descricao[50];
    // char nova_categoria[50];
    // int nova_prioridade;
    // char novo_status[20];

    if (*Contador_Tarefas > 0 ){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("\n --> digite a descricao da tarefa a ser alterada: \n");
        scanf("%s", altera_descricao);  //guarda o que foi escrito pelo usuario em "remove_descricao" .
        Clear_buffer();

        for (int i = 0 ; i < *Contador_Tarefas ; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao . 
            if(strcmp(altera_descricao,Lista[i].descricao) == 0){  //condicao que so se aplica quando a descricao escrita pelo usuario em "altera_descricao" for igual a "Lista[i].descricao" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
                printf("--> Digite a nova descricao: \n");
                scanf(" %[^\n]", Lista[i].descricao);  //Salva a a nova descricao escrita pelo cliente em Lista[*Contador_Tarefas].descricao .
                Clear_buffer();

                printf("--> Digite o novo conteudo: \n");
                scanf(" %[^\n]", Lista[i].categoria);  //Salva a a nova descricao escrita pelo cliente em Lista[*Contador_Tarefas].categoria .
                Clear_buffer();

                printf("--> Digite a nova prioridade: \n");
                scanf("%d", &Lista[i].prioridade);  //Salva a a nova descricao escrita pelo cliente em Lista[*Contador_Tarefas].prioridade .
                Clear_buffer();

                printf("--> Digite o novo status: \n");
                scanf(" %[^\n]", Lista[i].status);  //Salva a a nova descricao escrita pelo cliente em Lista[*Contador_Tarefas].status .
                Clear_buffer();

                // nova_descricao == Lista[i].descricao;
                // nova_categoria == Lista[i].categoria;
                // nova_prioridade == Lista[i].prioridade;
                // novo_status == Lista[i].status;

                printf("\n");
            }
            else{
                printf("\n -_-_- Descricao nao encontrada... -_-_- \n");
                printf("\n");
            }
        }
        
    }
}

void Filtrar_Prioridade(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por prioridade a Lista[]
    int prioridade_escolhida;

    if(*Contador_Tarefas > 0){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("\n --> Digite a prioridade escolhida: \n");
        scanf("%d", &prioridade_escolhida);  //guarda o que foi escrito pelo usuario em "remove_descricao" .
        Clear_buffer();

        for (int i = 0; i < *Contador_Tarefas; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao . 
            if(prioridade_escolhida == Lista[i].prioridade){  //condicao que so se aplica quando a descricao escrita pelo usuario em "prioridade_escolhida" for igual a "Lista[i].prioridade" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
                printf("\n Lista %d\n", i + 1);
                printf("Descricao: %s\n", Lista[i].descricao);
                printf("Categoria: %s\n", Lista[i].categoria);
                printf("Prioridade: %d\n", Lista[i].prioridade);
                printf("Status: %s\n", Lista[i].status);
                printf("\n");

            }
        }   
    }
    else{
        printf(" -_-_- Prioridade nao encontrada... -_-_- \n");
    }
}

void Filtrar_Estado(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por estado a Lista[]
    char status_escolhido[20];

    if(*Contador_Tarefas > 0){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("\n --> Digite o Estado escolhido: \n");
        scanf("%s", status_escolhido);  //guarda o que foi escrito pelo usuario em "remove_descricao" .
        Clear_buffer();

        for (int i = 0; i < *Contador_Tarefas; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao . 
            if(strcmp(status_escolhido, Lista[i].status) == 0 ){  //condicao que so se aplica quando a descricao escrita pelo usuario em "status_escolhido" for igual a "Lista[i].status" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
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

void Filtrar_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas) {  //Essa função filtra por categoria a Lista[]
    char categoria_escolhida[50];

    if (*Contador_Tarefas > 0) {  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("Digite a categoria escolhida: \n");
        scanf(" %[^\n]", categoria_escolhida);  //guarda o que foi escrito pelo usuario em "remove_descricao" .
        Clear_buffer();

        int tarefasFiltradas = 0;
        for (int i = 0; i < *Contador_Tarefas; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao .  
            if (strcmp(categoria_escolhida, Lista[i].categoria) == 0) {  //condicao que so se aplica quando a descricao escrita pelo usuario em "categoria_escolhida" for igual a "Lista[i].categoria" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
                tarefasFiltradas++;  
            }
        }

        if (tarefasFiltradas > 0) {  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
            Lista_Tarefas tarefasCorrespondentes[tarefasFiltradas];
            int indice = 0;

            for (int i = 0; i < *Contador_Tarefas; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao .
                if (strcmp(categoria_escolhida, Lista[i].categoria) == 0) {  //condicao que so se aplica quando a descricao escrita pelo usuario em "categoria_escolhida" for igual a "Lista[i].categoria" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
                    tarefasCorrespondentes[indice++] = Lista[i];
                }
            }

            // Ordenar as tarefas correspondentes por prioridade
            Ordenar_Por_Prioridade(tarefasCorrespondentes, tarefasFiltradas);

            // Imprimir as tarefas ordenadas
            printf("--> Tarefas filtradas e ordenadas por prioridade:\n");
            for (int i = 0; i < tarefasFiltradas; ++i) {  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao .
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


void Filtrar_Prioridade_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por categoria a Lista[]
    char categoria_escolhida[50];
    int prioridade_escolhida;

    if(*Contador_Tarefas> 0){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("\n --> Digite a categoria: \n");
        scanf("%s", categoria_escolhida);  //guarda o que foi escrito pelo usuario em "categoria_escolhida" .
        Clear_buffer();

        printf("Digite a prioridade: \n");
        scanf("%d", &prioridade_escolhida);  //guarda o que foi escrito pelo usuario em "prioridade_escolhida" .
        Clear_buffer();

        for(int i = 0; i < *Contador_Tarefas; i ++){  //looping que roda a Lista[] desde a primeira posicao (i = 0) ate a ultima posicao .
            if(strcmp(categoria_escolhida,Lista[i].categoria) == 0 && prioridade_escolhida == Lista[i].prioridade){  //condicao que so se aplica quando a descricao escrita pelo usuario em "categoria_escolhida" for igual a "Lista[i].categoria" e "prioridade_escolhida" for igual a "Lista[i].prioridade" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
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

int Exportar_Prioridade(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por categoria a Lista[]
    Lista_Tarefas Prioridade[100];

    int prioridade_escolhida;  // variavel criada para comparar com a lista

    if(*Contador_Tarefas > 0){  // apenas roda quando a condição for realizada, no caso o *Contador_Tarefas(minha ultima posição na lista) for maior que zero, ou seja, Lista tem que ter uma ou mais posições 
        printf("\n --> Digite o número da prioridade que voce deseja exportar: \n");
        scanf("%d", &prioridade_escolhida);  // armazena a prioridade digitada me &prioridade_escolhida

        FILE *f = fopen("tarefas_prioridade.txt", "w");  // abre o arquivo

        for(int i = 0; i < *Contador_Tarefas ; i++){  // roda a lista da sua primeira posição até a ultima posição incluida, no caso *Contador_Tarefas
            if (prioridade_escolhida == Lista[i].prioridade){  // compara prioridade_escolhida com a prioridade criada em Lista[i].prioridade na funcao Criar_Tarefas
                fprintf(f, "\n Lista %d\n", i + 1);
                fprintf(f, "Descricao: %s\n", Lista[i].descricao);  // print da descricao na Lista
                fprintf(f, "Categoria: %s\n", Lista[i].categoria);  // print da categoria na Lista
                fprintf(f, "Prioridade: %d\n", Lista[i].prioridade);  // print da prioridade na Lista
                fprintf(f, "Status: %s\n", Lista[i].status);  // print da status na Lista
            }
        }
        fclose(f);  // fecha o arquivo
        printf("\n Tarefas incluidas com sucesso!!");
    }
    else{
        printf("Prioridade nao encontrada... \n");
    }
}

int Exportar_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por categoria a Lista[]
    char categoria_escolhida[50];

    if (*Contador_Tarefas > 0) {  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("Digite a categoria escolhida: \n");
        scanf(" %[^\n]", categoria_escolhida);  // armazena a prioridade digitada em "categoria_escolhida"
        Clear_buffer();
        
        int tarefasFiltradas = 0;  // Filtrar as tarefas correspondentes à categoria escolhida

        for (int i = 0; i < *Contador_Tarefas; ++i) {  // roda a lista da sua primeira posição até a ultima posição incluida, no caso *Contador_Tarefas
            if (strcmp(categoria_escolhida, Lista[i].categoria) == 0) { //compara prioridade_escolhida com a prioridade criada em Lista[i].prioridade na funcao Criar_Tarefas
                tarefasFiltradas++;
            }
        }

        if (tarefasFiltradas > 0) {  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
            Lista_Tarefas tarefasCorrespondentes[tarefasFiltradas];  // Criar uma cópia das tarefas correspondentes
            int cont = 0;

            FILE *f = fopen("tarefas_categoria.txt", "w");  // abre o arquivo

            for (int i = 0; i < *Contador_Tarefas; ++i) {  // roda a lista da sua primeira posição até a ultima posição incluida, no caso *Contador_Tarefas
                if (strcmp(categoria_escolhida, Lista[i].categoria) == 0) {  //condicao que so se aplica quando a descricao escrita pelo usuario em "categoria_escolhida" for igual a "Lista[i].categoria" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
                    tarefasCorrespondentes[cont++] = Lista[i];

                }
            }

            Ordenar_Por_Prioridade(tarefasCorrespondentes, tarefasFiltradas);  // Ordenar as tarefas correspondentes por prioridade
 

            printf("\n --> Tarefas filtradas e ordenadas por prioridade:\n");  // Imprimir as tarefas ordenadas
            for (int i = 0; i < tarefasFiltradas; ++i) {  // roda a lista da sua primeira posição até a ultima posição incluida, no caso *Contador_Tarefas
                fprintf(f, "\n Tarefa %d\n", i + 1);
                fprintf(f, "Descricao: %s\n", tarefasCorrespondentes[i].descricao);
                fprintf(f, "Categoria: %s\n", tarefasCorrespondentes[i].categoria);
                fprintf(f, "Prioridade: %d\n", tarefasCorrespondentes[i].prioridade);
                fprintf(f, "Status: %s\n", tarefasCorrespondentes[i].status);
            }

            fclose(f);
        } else {
            printf("\n -_-_- Categoria nao encontrada... -_-_- \n");
        }
    }
}

int Exportar_Prioridade_Categoria(Lista_Tarefas Lista[], int *Contador_Tarefas){  //Essa função filtra por categoria a Lista[]
    char categoria_escolhida[50];
    int prioridade_escolhida;

    if(*Contador_Tarefas){  //Condição que só funciona quando a ultima posição(*Contador_Tarefas) na lista[] for maior que 0 .
        printf("\n --> Digite a categoria: \n");
        scanf("%s", categoria_escolhida);  // armazena a prioridade digitada em "categoria_escolhida"
        Clear_buffer();

        printf("Digite a prioridade: \n");
        scanf("%d", &prioridade_escolhida);  // armazena a prioridade digitada em "&prioridade_escolhida"
        Clear_buffer();

        FILE *f = fopen("tarefas_prioridade_categoria.txt", "w");  // abre o arquivo

        for(int i = 0; i < *Contador_Tarefas; i ++){  // roda a lista da sua primeira posição até a ultima posição incluida, no caso *Contador_Tarefas
            if(strcmp(categoria_escolhida,Lista[i].categoria) == 0 && prioridade_escolhida == Lista[i].prioridade){  //condicao que so se aplica quando a descricao escrita pelo usuario em "categoria_escolhida" for igual a "Lista[i].categoria" e "prioridade_escolhida" for igual a "Lista[i].prioridade" que foi escrita na Lista[i] na funcao "Criar_Tarefa"
                fprintf(f, "\n Lista %d\n", i + 1);
                fprintf(f, "Descricao: %s\n", Lista[i].descricao);
                fprintf(f, "Categoria: %s\n", Lista[i].categoria);
                fprintf(f, "Prioridade: %d\n", Lista[i].prioridade);
                fprintf(f, "Status: %s\n", Lista[i].status);
            }
        }
        fclose(f);
        printf("\n -_-_- Tarefa exportada com sucesso!! -_-_- \n");
    }

}

void Clear_buffer(){  //evita erros com a funcao scanf
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void Ordenar_Por_Prioridade(Lista_Tarefas Lista[], int Contador_Tarefas) {  //funcao ordena por prioridade a Lista[] 
    // Implementação simples do algoritmo de ordenação de bolhas
    for (int i = 0; i < Contador_Tarefas ; ++i) {  // roda a lista da sua primeira posição até a ultima posição incluida, no caso *Contador_Tarefas
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
    FILE *f = fopen("Lista.txt", "rb");
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
    FILE *f = fopen("Lista.txt", "wb");
    if(f == NULL){
        return 1;
    }
    else{
        fwrite(Contador_Tarefas,sizeof(Lista_Tarefas), 1, f);
        fclose(f);
    }
    return 0;
}