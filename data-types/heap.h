#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>
#define HEAP_CAPACITY 128

typedef struct {
    int data[HEAP_CAPACITY];
    size_t size;
} Heap;

void heap_init(Heap *h);
void heap_push(Heap *h, int value);
int  heap_pop(Heap *h);
int  heap_top(const Heap *h);
size_t heap_size(const Heap *h);

#endif // HEAP_H
