#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
} Queue;

void queue_init(Queue *q);
void queue_free(Queue *q);
void queue_enqueue(Queue *q, int value);
int  queue_dequeue(Queue *q);
int  queue_front(const Queue *q);
size_t queue_size(const Queue *q);

#endif // QUEUE_H
