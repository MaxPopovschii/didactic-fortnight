#ifndef SET_H
#define SET_H

#include <stddef.h>

#define SET_SIZE 101

typedef struct {
    int value;
    int used;
} SetEntry;

typedef struct {
    SetEntry entries[SET_SIZE];
} Set;

void set_init(Set *set);
void set_add(Set *set, int value);
int  set_contains(Set *set, int value);
void set_remove(Set *set, int value);
void set_free(Set *set);

#endif // SET_H
