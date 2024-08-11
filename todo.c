// todo.c
// 8/20/2024

#include <stdio.h>
#include <string.h>

void show_options();
void view_tasks();
void add_task();
void toggle_task();
void edit_task();
void remove_task();

char tasks[100][30];
int task_states[100];
int tasks_lenght = 0;

int main()
{
    view_tasks();
    show_options();

    int input;
    scanf("%d", &input);
    getchar();

    while(input != 5)
    {
        switch (input)
        {
            case 1:
                add_task();
                break;
            case 2:
                toggle_task();
                break;
            case 3:
                edit_task();
                break;
            case 4:
                remove_task();
                break;
            default:
                break;
        }

        view_tasks();
        show_options();

        scanf("%d", &input);
        getchar();

    }
    
    return 0;
}

void add_task()
{
    printf("Name of the task:\n");
    printf("> ");

    fgets(tasks[tasks_lenght], 30, stdin);

    tasks_lenght++;

}

void toggle_task()
{
    if(tasks_lenght == 0)
    {
        return;
    }

    view_tasks();

    printf("Task index:\n> ");
    int selected;
    scanf("%d", &selected);
    getchar();

    if(selected < 0 || selected > tasks_lenght)
    {
        printf("Invalid index!\n");
        return;
    }

    if(task_states[selected - 1] == 0)
    {
        task_states[selected - 1] = 1;
    }
    else
    {
        task_states[selected - 1] = 0;
    }
}

void edit_task()
{
    if(tasks_lenght == 0)
    {
        return;
    }

    view_tasks();

    printf("Task index:\n> ");
    int selected;
    scanf("%d", &selected);
    getchar();

    if(selected < 0 || selected > tasks_lenght)
    {
        printf("Invalid index!\n");
        return;
    }

    printf("New name: ");
    fgets(tasks[selected - 1], 30, stdin);

    return;
}

void remove_task()
{
    if(tasks_lenght == 0)
    {
        return;
    }

    view_tasks();

    printf("Task index:\n> ");
    int selected;
    scanf("%d", &selected);
    getchar();

    if(selected < 0 || selected > tasks_lenght)
    {
        printf("Invalid index!\n");
        return;
    }

    for(int i = selected - 1; i < tasks_lenght; i++)
    {
        strcpy(tasks[i], tasks[i+1]);
        task_states[i] = task_states[i+1];
    }

    tasks_lenght--;

}

void show_options()
{
    printf("-----------\n");
    printf("Options:\n");
    printf("1. Add task\n");
    printf("2. Mark task as completed\n");
    printf("3. Edit task\n");
    printf("4. Remove task\n");
    printf("5. Quit\n");
    printf("> ");
}

void view_tasks()
{
    if(tasks_lenght == 0)
    {
        return;
    }

    printf("\nYour tasks:\n");
    for(int i = 0; i < tasks_lenght; i++)
    {
        char c = task_states[i] == 1 ? 'x' : ' ';
        printf("%d. [%c] %s", i+1, c, tasks[i]);
    }
}