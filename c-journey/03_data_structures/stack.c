#include <stdio.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    if (s->top < MAX)
        s->arr[s->top++] = val;
}

int pop(Stack *s) {
    if (s->top > 0)
        return s->arr[--s->top];
    return -1;
}

int main() {
    Stack s = {.top = 0};
    push(&s, 5);
    push(&s, 10);
    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));
    return 0;
}