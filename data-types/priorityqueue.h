#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} PriorityQueue;

void pq_init(PriorityQueue *pq);
void pq_free(PriorityQueue *pq);
void pq_push(PriorityQueue *pq, int value);
int  pq_pop(PriorityQueue *pq);
int  pq_top(const PriorityQueue *pq);
size_t pq_size(const PriorityQueue *pq);

#endif // PRIORITYQUEUE_H
