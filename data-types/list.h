#ifndef LIST_H
#define LIST_H

#include <stddef.h>

// Simple dynamic array (List) for int
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} List;

void list_init(List *list);
void list_free(List *list);
void list_push(List *list, int value);
int  list_get(List *list, size_t index);
size_t list_size(const List *list);

#endif // LIST_H
