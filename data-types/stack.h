#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Stack;

void stack_init(Stack *s);
void stack_free(Stack *s);
void stack_push(Stack *s, int value);
int  stack_pop(Stack *s);
int  stack_top(const Stack *s);
size_t stack_size(const Stack *s);

#endif // STACK_H
