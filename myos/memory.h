#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
void memory_init(void *heap_start, size_t heap_size);
void *kmalloc(size_t size);

#endif