#include "stack.h"
#include <stdlib.h>

void stack_init(Stack *s) {
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void stack_free(Stack *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
}

void stack_push(Stack *s, int value) {
    if (s->size == s->capacity) {
        size_t new_capacity = s->capacity == 0 ? 4 : s->capacity * 2;
        int *new_data = realloc(s->data, new_capacity * sizeof(int));
        if (!new_data) return;
        s->data = new_data;
        s->capacity = new_capacity;
    }
    s->data[s->size++] = value;
}

int stack_pop(Stack *s) {
    if (s->size == 0) return 0;
    return s->data[--s->size];
}

int stack_top(const Stack *s) {
    if (s->size == 0) return 0;
    return s->data[s->size - 1];
}

size_t stack_size(const Stack *s) {
    return s->size;
}
