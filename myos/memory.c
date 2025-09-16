#include "memory.h"

static unsigned char *heap;
static size_t heap_size;
static size_t used = 0;

void memory_init(void *heap_start, size_t size) {
    heap = (unsigned char*)heap_start;
    heap_size = size;
    used = 0;
}

void *kmalloc(size_t size) {
    if (used + size > heap_size) return 0;
    void *ptr = heap + used;
    used += size;
    return ptr;
}
