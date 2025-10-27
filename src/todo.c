#include <stdio.h>
#include <stdbool.h>
#include <string.h>

taskCompleted = false;

struct Task {
        char taskName[30];
        int taskStatus;
        char taskData[30];
        char taskInfo[30];
        bool taskCompleted;
        char taskCategory[30];
    };

void addTask(struct Task taskArray[], int *total) {
printf("Digite o nome da tarefa: ");
fgets(taskArray[*total].taskName, 30, stdin);

printf("Qual o prazo de conclusão de sua tarefa: ");
fgets(taskArray[*total].taskData, 30, stdin);

printf("Descreva a sua tarefa ou objetivos dela: ");
fgets(taskArray[*total].taskInfo, 30, stdin);

printf("Digite a categoria de sua tarefa: ");
fgets(taskArray[*total].taskCategory, 30, stdin);

printf("Digite o status: ");
scanf("%d", &taskArray[*total].taskStatus);

taskArray[*total].taskCompleted = false;
(*total)++;
}

void concludedTask(struct Task taskArray[], int total) {
int indice;
//printando a lista de tarefas e seus indices
for(int i = 0; i < total; i++) {
    printf("Indice: [%d] ", i);
    printf("[%d] %s\n", i, taskArray[i].taskName);
}
//requisitando o indice da tarefa a ser concluida
printf("Digite o indice da tarefa a ser concluida: ");
scanf("%d", &indice);
//verificando se o indice é válido
while (indice < 0 || indice >= total) {
    printf("Indice invalido. Digite novamente: ");
    scanf("%d", &indice);
}

taskArray[indice].taskCompleted = true;

printf("Tarefa '%s' marcada como concluida.\n", taskArray[indice].taskName);
}

void list_category(struct Task taskArray[], int total) {

}

void removeTask(struct Task taskArray[], int *total) {
int indice;

//previne o usuario de colocar valores invalidos
while (indice < 0 || indice >= *total) {
//printar o indice da tarefa e seu nome
for(int i = 0; i < *total; i++) {
    printf("Indice: [%d] ", i);
    printf("[%d] %s\n", i, taskArray[i].taskName);
    printf("[%d] %s\n", i, taskArray[i].taskData);
}
printf("Digite o indice da tarefa a ser removida: ");
scanf("%d", &indice);
}
//ajustar a ordem das tarefas no array
for (int i = indice; i < *total - 1; i++) {
    taskArray[i] = taskArray[i+1];
}
//remover a tarefa
(*total)--;
}

int main() {

    struct Task taskArray[100];
    int totalTasks = 0;
    int menuOption;


    while (true) {
        printf("1 - Adicionar tarefa\n2 - Listar tarefas\n3 - Marcar como concluído\n4 - Remover tarefa\n5 - Salvar tarefas\n6 - Sair");
        scanf("%d", &menuOption);

        switch(menuOption) {
            case 1:
            addTask(taskArray, &totalTasks);
            break;

            case 2:
            list_category(taskArray, &totalTasks);
            break;
            
            case 3:
            concludedTask(taskArray, &totalTasks);
            break;

            case 4:
            removeTask(taskArray, &totalTasks);
            break;

            case 5:

        }
        
        if(menuOption == 6) {
            printf("Saindo...\n");
            break;
        }
    }

}