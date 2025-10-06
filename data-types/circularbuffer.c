#include "circularbuffer.h"

void cb_init(CircularBuffer *cb) {
    cb->head = cb->tail = cb->size = 0;
}

void cb_push(CircularBuffer *cb, int value) {
    if (cb->size == CIRCULARBUFFER_CAPACITY) return;
    cb->data[cb->tail] = value;
    cb->tail = (cb->tail + 1) % CIRCULARBUFFER_CAPACITY;
    cb->size++;
}

int cb_pop(CircularBuffer *cb) {
    if (cb->size == 0) return 0;
    int val = cb->data[cb->head];
    cb->head = (cb->head + 1) % CIRCULARBUFFER_CAPACITY;
    cb->size--;
    return val;
}

int cb_is_empty(const CircularBuffer *cb) {
    return cb->size == 0;
}

int cb_is_full(const CircularBuffer *cb) {
    return cb->size == CIRCULARBUFFER_CAPACITY;
}
