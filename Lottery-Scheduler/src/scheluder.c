#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_STRING_LEN 256 

struct Task{
    char task_name[MAX_STRING_LEN];
    int ticket;
    struct Task *next;
};

struct Task *head = NULL; 

struct Task* createTask(const char *task_name, const int tickets){

    if(!task_name){
        fprintf(stderr, "no name insitalized\n");
        return NULL;
    }

    struct Task * new_task = (struct Task*)malloc(sizeof(struct Task));
    if(new_task == NULL){
        fprintf(stderr, "allocation failed\n");
        exit(1);
    }
    strncpy(new_task->task_name, task_name, MAX_STRING_LEN);
    new_task->ticket = tickets;
    new_task->next = NULL;

    return new_task;
}
void insert_task(const char *task_name, const int tickets){

    struct Task *new_task = createTask(task_name, tickets);
    if(head == NULL){
        head = new_task;
    }else{
        struct Task * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_task;
    }
}
int get_random(int min, int max){

    srand(time(0)); 
    int random_number = min + rand() % (max-min+1);
    return random_number;
}

struct Task *schedule(){
    int counter = 0;

    int winner = get_random(0, 100);

    struct Task *current = head;

    while(current){
        counter = counter +current->ticket;
        if(counter > winner){
            break;
        }
        current = current->next;
    }
    return current; 
}
int main(int argc, char *argv[])
{
    insert_task("google", 10);
    insert_task("grep", 20);
    insert_task("nvim", 30);

    struct Task *winner_task = schedule(); 

    printf("winner task = %s\n", winner_task->task_name);
    
    
}

