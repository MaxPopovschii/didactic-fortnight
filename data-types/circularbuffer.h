#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <stddef.h>
#define CIRCULARBUFFER_CAPACITY 128

typedef struct {
    int data[CIRCULARBUFFER_CAPACITY];
    size_t head;
    size_t tail;
    size_t size;
} CircularBuffer;

void cb_init(CircularBuffer *cb);
void cb_push(CircularBuffer *cb, int value);
int  cb_pop(CircularBuffer *cb);
int  cb_is_empty(const CircularBuffer *cb);
int  cb_is_full(const CircularBuffer *cb);

#endif // CIRCULARBUFFER_H
