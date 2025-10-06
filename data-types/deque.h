#ifndef DEQUE_H
#define DEQUE_H

#include <stddef.h>
#define DEQUE_CAPACITY 128

typedef struct {
    int data[DEQUE_CAPACITY];
    size_t head;
    size_t tail;
    size_t size;
} Deque;

void deque_init(Deque *dq);
void deque_push_front(Deque *dq, int value);
void deque_push_back(Deque *dq, int value);
int  deque_pop_front(Deque *dq);
int  deque_pop_back(Deque *dq);
int  deque_is_empty(const Deque *dq);
int  deque_is_full(const Deque *dq);

#endif // DEQUE_H
