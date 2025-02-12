#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define MAX_STRING_LEN 256

struct Task {
    uint32_t pid;
    char task_name[MAX_STRING_LEN];
    uint32_t ticket;
    struct Task *next;
};

extern struct Task *head;

struct Task* createTask(const char *task_name, const int tickets);
void insert_task(const char *task_name, const int tickets);
int get_random(int min, int max);
struct Task *schedule();

#endif // SCHEDULER_H
