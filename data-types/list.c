#include "list.h"
#include <stdlib.h>

void list_init(List *list) {
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void list_free(List *list) {
    free(list->data);
    list->data = NULL;
    list->size = 0;
    list->capacity = 0;
}

void list_push(List *list, int value) {
    if (list->size == list->capacity) {
        size_t new_capacity = list->capacity == 0 ? 4 : list->capacity * 2;
        int *new_data = realloc(list->data, new_capacity * sizeof(int));
        if (!new_data) return;
        list->data = new_data;
        list->capacity = new_capacity;
    }
    list->data[list->size++] = value;
}

int list_get(List *list, size_t index) {
    if (index >= list->size) return 0;
    return list->data[index];
}

size_t list_size(const List *list) {
    return list->size;
}
