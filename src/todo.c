#include <stdio.h>
#include <stdbool.h>
struct Task {
        char taskName[30];
        int taskStatus;
        char taskData[30];
        char taskInfo[30];
        bool taskCompleted;
        char taskCategory[30];
    };

void addTask(struct Task taskArray[], int *total) {
(*total)++;
}

void concludedTask(struct Task taskArray[], int total) {

}

void list_category(struct Task taskArray[], int total) {

}

void removeTask(struct Task taskArray[], int *total) {
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