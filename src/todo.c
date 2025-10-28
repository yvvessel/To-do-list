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

// --- Função auxiliar para limpar o '\n' do fgets ---
void removeNewline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}

// --- Adicionar tarefa ---
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

    while (true)
    {
        printf("Digite o status (número): ");
        fgets(input, 10, stdin);
        if (sscanf(input, "%d", &taskArray[*total].taskStatus) == 1)
        {
            break;
        }
        else
        {
            printf("Valor inválido! Digite um número.\n");
        }
    }

    taskArray[*total].taskCompleted = false;
    (*total)++;
}

// --- Marcar tarefa como concluída ---
void concludedTask(struct Task taskArray[], int total)
{
    int indice;

    for (int i = 0; i < total; i++)
    {
        printf("[%d] %s\n", i, taskArray[i].taskName);
    }

    printf("Digite o índice da tarefa a ser concluída: ");
    scanf("%d", &indice);
    getchar();

    while (indice < 0 || indice >= total)
    {
        printf("Índice inválido. Digite novamente: ");
        scanf("%d", &indice);
        getchar();
    }

    taskArray[indice].taskCompleted = true;
    printf("Tarefa '%s' marcada como concluída.\n", taskArray[indice].taskName);
}

// --- Listar tarefas por categoria ---
void list_category(struct Task taskArray[], int total)
{
    bool found = false;
    char category[30];

    printf("Digite o nome da categoria a ser listada: ");
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
            printf("Categoria: %s\n", taskArray[i].taskCategory);
            printf("----------------------------------------\n");
            found = true;
        }
    }

    if (!found)
    {
        printf("Categoria não encontrada!\n");
    }
}

// --- Listar todas as tarefas ---
void list_all_tasks(struct Task taskArray[], int total)
{
    if (total == 0)
    {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    for (int i = 0; i < total; i++)
    {
        printf("[%d] Nome: %s\n", i, taskArray[i].taskName);
        printf("Prazo: %s\n", taskArray[i].taskData);
        printf("Descrição: %s\n", taskArray[i].taskInfo);
        printf("Categoria: %s\n", taskArray[i].taskCategory);
        printf("Status: %s\n", taskArray[i].taskCompleted ? "Concluída" : "Pendente");
        printf("----------------------------------------\n");
    }
}

// --- Remover tarefa ---
void removeTask(struct Task taskArray[], int *total)
{
    int indice = -1;

    while (indice < 0 || indice >= *total)
    {
        for (int i = 0; i < *total; i++)
        {
            printf("[%d] %s\n", i, taskArray[i].taskName);
        }
        printf("Digite o índice da tarefa a ser removida: ");
        scanf("%d", &indice);
        getchar();
    }

    for (int i = indice; i < *total - 1; i++)
    {
        taskArray[i] = taskArray[i + 1];
    }

    (*total)--;
    printf("Tarefa removida com sucesso.\n");
}

// --- Salvar tarefas em arquivo ---
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

// --- Carregar tarefas de arquivo ---
int loadTasks(struct Task taskArray[])
{
    FILE *file = fopen("tasks.txt", "r");
    if (!file)
        return 0;

    int total = 0;
    while (fscanf(file, "%29[^;];%29[^;];%29[^;];%d;%d;%29[^\n]\n",
                  taskArray[total].taskName,
                  taskArray[total].taskData,
                  taskArray[total].taskInfo,
                  &taskArray[total].taskStatus,
                  (int *)&taskArray[total].taskCompleted,
                  taskArray[total].taskCategory) == 6)
    {
        total++;
    }

    fclose(file);
    return total;
}

// --- Programa principal ---
int main()
{
    struct Task taskArray[100];
    int totalTasks = loadTasks(taskArray);
    int menuOption;

    while (true)
    {
        printf("1 - Adicionar tarefa\n");
        printf("2 - Listar todas as tarefas\n");
        printf("3 - Listar por categoria\n");
        printf("4 - Remover tarefa\n");
        printf("5 - Marcar como concluída\n");
        printf("6 - Salvar tarefas\n");
        printf("7 - Sair\n");
        printf("Escolha uma opção: ");
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
        case 7:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção inválida.\n");
        }
    }
}