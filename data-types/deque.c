#include "deque.h"

void deque_init(Deque *dq) {
    dq->head = dq->tail = dq->size = 0;
}

void deque_push_front(Deque *dq, int value) {
    if (dq->size == DEQUE_CAPACITY) return;
    dq->head = (dq->head == 0 ? DEQUE_CAPACITY - 1 : dq->head - 1);
    dq->data[dq->head] = value;
    dq->size++;
}

void deque_push_back(Deque *dq, int value) {
    if (dq->size == DEQUE_CAPACITY) return;
    dq->data[dq->tail] = value;
    dq->tail = (dq->tail + 1) % DEQUE_CAPACITY;
    dq->size++;
}

int deque_pop_front(Deque *dq) {
    if (dq->size == 0) return 0;
    int val = dq->data[dq->head];
    dq->head = (dq->head + 1) % DEQUE_CAPACITY;
    dq->size--;
    return val;
}

int deque_pop_back(Deque *dq) {
    if (dq->size == 0) return 0;
    dq->tail = (dq->tail == 0 ? DEQUE_CAPACITY - 1 : dq->tail - 1);
    int val = dq->data[dq->tail];
    dq->size--;
    return val;
}

int deque_is_empty(const Deque *dq) {
    return dq->size == 0;
}

int deque_is_full(const Deque *dq) {
    return dq->size == DEQUE_CAPACITY;
}
