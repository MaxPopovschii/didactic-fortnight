#include "heap.h"

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heap_init(Heap *h) {
    h->size = 0;
}

void heap_push(Heap *h, int value) {
    if (h->size == HEAP_CAPACITY) return;
    size_t i = h->size++;
    h->data[i] = value;
    while (i > 0) {
        size_t parent = (i - 1) / 2;
        if (h->data[parent] >= h->data[i]) break;
        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

int heap_pop(Heap *h) {
    if (h->size == 0) return 0;
    int ret = h->data[0];
    h->data[0] = h->data[--h->size];
    size_t i = 0;
    while (1) {
        size_t left = 2 * i + 1, right = 2 * i + 2, max = i;
        if (left < h->size && h->data[left] > h->data[max]) max = left;
        if (right < h->size && h->data[right] > h->data[max]) max = right;
        if (max == i) break;
        swap(&h->data[i], &h->data[max]);
        i = max;
    }
    return ret;
}

int heap_top(const Heap *h) {
    if (h->size == 0) return 0;
    return h->data[0];
}

size_t heap_size(const Heap *h) {
    return h->size;
}
