#include "queue.h"
#include <stdlib.h>

void queue_init(Queue *q) {
    q->data = NULL;
    q->head = q->tail = q->size = q->capacity = 0;
}

void queue_free(Queue *q) {
    free(q->data);
    q->data = NULL;
    q->head = q->tail = q->size = q->capacity = 0;
}

void queue_enqueue(Queue *q, int value) {
    if (q->size == q->capacity) {
        size_t new_capacity = q->capacity == 0 ? 4 : q->capacity * 2;
        int *new_data = realloc(q->data, new_capacity * sizeof(int));
        if (!new_data) return;
        if (q->size > 0 && q->head > q->tail) {
            for (size_t i = 0; i < q->tail; ++i)
                new_data[new_capacity - q->tail + i] = q->data[i];
            q->tail = new_capacity - (q->capacity - q->tail);
        }
        q->data = new_data;
        q->capacity = new_capacity;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

int queue_dequeue(Queue *q) {
    if (q->size == 0) return 0;
    int val = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return val;
}

int queue_front(const Queue *q) {
    if (q->size == 0) return 0;
    return q->data[q->head];
}

size_t queue_size(const Queue *q) {
    return q->size;
}
