#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STRIDE_CONSTANT 1000
struct Task_t{
    uint32_t pid;
    char name[255];
    uint32_t tickets; 
    uint32_t stride;
    uint32_t pass_counter;
    struct Task_t *next_task;
};

struct Task_t *head = NULL;

struct Task_t * create_task(const char *task_name , const int tickets){
    if(!name){
        fprintf(stderr, "no name initialized\n");
        return NULL;
    }

    struct Task_t *new_task = (struct Task_t *)malloc(sizeof(struct Task_t));
    if(!new_task){
        fprintf(stderr, "task allocation failed\n");
        exit(1);
    }
    new_task->pid = 1;
    strncpy(new_task->name, task_name, sizeof(task_name));
    new_task->tickets = tickets;
    new_task->stride = (uint32_t)STRIDE_CONSTANT / tickets; 
    new_task->pass_counter = 0;
    return new_task;
}

void inset_task(const char *task_name, const int tickets){
    struct Task_t *new_task = create_task(task_name, tickets);
    if(head == NULL){
        head = new_task;
    }else{
        struct Task_t *temp = head;
        while(temp->next_task != NULL){
            temp = temp->next_task; 
        }
        temp->next_task = new_task;

    }
}

void Task_t *get_smallest_pass(){
    if(head == NULL){
        return NULL; 
    }
    struct Task_t *min_node = head ;
    struct Task_t *current = head->next_task;

    while(current != NULL){
        if(current->pass_counter < head->pass_counter){
            min_node = current;
        }
        current = current->next_task;
    }
    return min_node;
}
void schedule(){

    int x = 0;
    int test = 0;
    while(x < 10){

        if(head)

    }
}
