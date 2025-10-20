#include <stdio.h>
#define MAX 20

typedef struct {
    int arr[MAX];
    int size;
} Set;

void add(Set *s, int val) {
    for (int i = 0; i < s->size; i++)
        if (s->arr[i] == val) return;
    if (s->size < MAX)
        s->arr[s->size++] = val;
}

int contains(Set *s, int val) {
    for (int i = 0; i < s->size; i++)
        if (s->arr[i] == val) return 1;
    return 0;
}

int main() {
    Set s = {.size = 0};
    add(&s, 5);
    add(&s, 10);
    add(&s, 5);
    printf("Set contiene 10? %s\n", contains(&s, 10) ? "Si" : "No");
    printf("Set contiene 7? %s\n", contains(&s, 7) ? "Si" : "No");
    return 0;
}