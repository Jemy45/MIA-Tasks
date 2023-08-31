#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100 // Max number of tasks

struct Task //Each task have index and description
{
    int id;
    char description[100];
};
struct Task list[MAX]; // List contains all the tasks

int number_tasks = 0; // Number of present task

void addTask();
void viewTasks();
void removeTask();
int main()
{
int choice;
while(true)
    {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
             case 1:
                addTask();
                break;
             case 2:
                viewTasks();
                break;
             case 3:
                removeTask();
                break;
             case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}
/*
Breif its a function to take input tasks from user
@param newTask is a Task type got from user to be able to add it in list contain tasks
*/
void addTask(){
     if (number_tasks >= MAX)
    {
        printf("The list is full\n");
        return;
    }
    struct Task newTask;
    newTask.id = number_tasks + 1;
    printf("Enter task description: ");
    scanf(" %[^\n]", newTask.description);
    list[number_tasks] = newTask;
    number_tasks++;
    printf("Task added successfully!\n");
}
/*
Breif its a function to print current tasks for user
*/
void viewTasks() {
    if (number_tasks == 0) {
        printf("No tasks entered!\n");
    }

    printf("Task List:\n");
    for (int i = 0; i < number_tasks; i++) {
        printf("ID: %d, Description: %s\n", list[i].id, list[i].description);
    }
}

/*
Breif This function took ID of task from user and check its availability then remove it
@param remove_id is an int type took from user to be able to remove this id task.
@param temp is an int type using for storage available id in my list
*/
void removeTask() {
    if (number_tasks == 0) {
        printf("No tasks available.\n");
    }

    int remove_id;
    printf("Enter the ID of the task to remove: ");
    scanf("%d", &remove_id);

    int temp = -1;
    for (int i = 0; i < number_tasks; i++) {
        if (list[i].id == remove_id) {
            temp = i;
            break;
        }
    }

    if (temp == -1) {
        printf("Task with ID %d not found.\n", remove_id);
        return;

    }

    for (int i = temp; i < number_tasks - 1; i++) {
        list[i] = list[i + 1];
    }

    number_tasks--;
    printf("Task with ID %d removed successfully.\n", remove_id);
}


