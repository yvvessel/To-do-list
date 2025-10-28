#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Task
{
    char taskName[30];
    int taskStatus;
    char taskData[30];
    char taskInfo[30];
    bool taskCompleted;
    char taskCategory[30];
};

// remove o \n do final das strings lidas com fgets
void removeNewline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

void addTask(struct Task taskArray[], int *total)
{
    char input[10];

    printf("Digite o nome da tarefa: ");
    fgets(taskArray[*total].taskName, 30, stdin);
    removeNewline(taskArray[*total].taskName);

    printf("Qual o prazo de conclusão de sua tarefa: ");
    fgets(taskArray[*total].taskData, 30, stdin);
    removeNewline(taskArray[*total].taskData);

    printf("Descreva a sua tarefa ou objetivos dela: ");
    fgets(taskArray[*total].taskInfo, 30, stdin);
    removeNewline(taskArray[*total].taskInfo);

    printf("Digite a categoria de sua tarefa: ");
    fgets(taskArray[*total].taskCategory, 30, stdin);
    removeNewline(taskArray[*total].taskCategory);

    // validação do status (garante que o valor seja um número)
    while (true)
    {
        printf("Digite o status (número): ");
        fgets(input, 10, stdin);
        if (sscanf(input, "%d", &taskArray[*total].taskStatus) == 1)
        {
            break; // válido
        }
        else
        {
            printf("Valor inválido! Digite um número.\n");
        }
    }

    taskArray[*total].taskCompleted = false;
    (*total)++;
}

void concludedTask(struct Task taskArray[], int total)
{
    int indice;
    // printando a lista de tarefas e seus indices
    for (int i = 0; i < total; i++)
    {
        printf("Indice: [%d] ", i);
        printf("[%d] %s\n", i, taskArray[i].taskName);
    }
    // requisitando o indice da tarefa a ser concluida
    printf("Digite o indice da tarefa a ser concluida: \n");
    scanf("%d", &indice);
    getchar();
    // verificando se o indice é válido
    while (indice < 0 || indice >= total)
    {
        printf("Indice invalido. Digite novamente: \n");
        scanf("%d", &indice);
        getchar();
    }

    taskArray[indice].taskCompleted = true;

    printf("Tarefa '%s' marcada como concluida.\n", taskArray[indice].taskName);
}

void list_category(struct Task taskArray[], int total)
{
    bool found = false;
    char category[30];

    printf("Digite o nome da categoria a ser listada: \n");
    scanf("%s", category);
    getchar();

    for (int i = 0; i < total; i++)
    {
        if (strcmp(taskArray[i].taskCategory, category) == 0)
        {
            printf("[%d] Nome: %s\n", i, taskArray[i].taskName);
            printf("Prazo: %s\n", taskArray[i].taskData);
            printf("Status: %s\n", taskArray[i].taskCompleted ? "Concluída" : "Pendente");
            printf("Descrição: %s\n", taskArray[i].taskInfo);
            printf("[%d] %s\n", i, taskArray[i].taskCategory);
            found = true;
        }
    }
    if (!found)
    {
        printf("Categoria não encontrada!\n");
    }
}

void list_all_tasks(struct Task taskArray[], int total)
{
    if (total == 0)
    {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        printf("[%d] Nome: %s", i, taskArray[i].taskName);
        printf("    Prazo: %s", taskArray[i].taskData);
        printf("    Descrição: %s", taskArray[i].taskInfo);
        printf("    Categoria: %s", taskArray[i].taskCategory);
        printf("    Status: %s\n", taskArray[i].taskCompleted ? "Concluída" : "Pendente");
        printf("----------------------------------------\n");
    }
}

void removeTask(struct Task taskArray[], int *total)
{
    int indice = -1;

    // previne o usuario de colocar valores invalidos
    while (indice < 0 || indice >= *total)
    {
        // printar o indice da tarefa e seu nome
        for (int i = 0; i < *total; i++)
        {
            printf("Indice: [%d] ", i);
            printf("[%d] %s\n", i, taskArray[i].taskName);
            printf("[%d] %s\n", i, taskArray[i].taskData);
        }
        printf("Digite o indice da tarefa a ser removida: ");
        scanf("%d", &indice);
        getchar();
    }
    // ajustar a ordem das tarefas no array
    for (int i = indice; i < *total - 1; i++)
    {
        taskArray[i] = taskArray[i + 1];
    }
    // remover a tarefa
    (*total)--;
}

void saveTasks(struct Task taskArray[], int total)
{
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        fprintf(file, "%s;%s;%s;%d;%d;%s\n",
                taskArray[i].taskName,
                taskArray[i].taskData,
                taskArray[i].taskInfo,
                taskArray[i].taskStatus,
                taskArray[i].taskCompleted,
                taskArray[i].taskCategory);
    }

    fclose(file);
    printf("Tarefas salvas com sucesso!\n");
}

int loadTasks(struct Task taskArray[])
{
    FILE *file = fopen("tasks.txt", "r");
    if (!file)
        return 0; // se não existir, retorna 0 tarefas

    int total = 0;
    while (fscanf(file, "%29[^;];%29[^;];%29[^;];%d;%d;%29[^\n]\n",
                  taskArray[total].taskName,
                  taskArray[total].taskData,
                  taskArray[total].taskInfo,
                  &taskArray[total].taskStatus,
                  (int *)&taskArray[total].taskCompleted, // conversão aqui
                  taskArray[total].taskCategory) == 6)
        total++;

    fclose(file);
    return total;
}

int main()
{
    struct Task taskArray[100];
    int totalTasks = 0;
    int menuOption;

    totalTasks = loadTasks(taskArray);
    while (true)
    {
        printf("1 - Adicionar tarefa\n2 - Listar todas as tarefas\n3 - Listar por categoria\n4 - Remover tarefa\n5 - Marcar como concluído\n6 - Salvar tarefas\n7 - Sair\n");
        scanf("%d", &menuOption);
        getchar();

        switch (menuOption)
        {
        case 1:
            addTask(taskArray, &totalTasks);
            break;

        case 2:
            list_all_tasks(taskArray, totalTasks);
            break;

        case 3:
            list_category(taskArray, totalTasks);
            break;

        case 4:
            removeTask(taskArray, &totalTasks);
            break;

        case 5:
            concludedTask(taskArray, totalTasks);
            break;

        case 6:
            saveTasks(taskArray, totalTasks);
            break;
        }

        if (menuOption == 7)
        {
            printf("Saindo...\n");
            break;
        }
    }
}