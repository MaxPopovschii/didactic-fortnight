#include "set.h"
#include <stdlib.h>

static int hash(int value) {
    return (value < 0 ? -value : value) % SET_SIZE;
}

void set_init(Set *set) {
    for (int i = 0; i < SET_SIZE; i++)
        set->entries[i].used = 0;
}

void set_add(Set *set, int value) {
    int idx = hash(value);
    for (int i = 0; i < SET_SIZE; i++) {
        int try = (idx + i) % SET_SIZE;
        if (!set->entries[try].used || set->entries[try].value == value) {
            set->entries[try].value = value;
            set->entries[try].used = 1;
            return;
        }
    }
}

int set_contains(Set *set, int value) {
    int idx = hash(value);
    for (int i = 0; i < SET_SIZE; i++) {
        int try = (idx + i) % SET_SIZE;
        if (set->entries[try].used && set->entries[try].value == value)
            return 1;
    }
    return 0;
}

void set_remove(Set *set, int value) {
    int idx = hash(value);
    for (int i = 0; i < SET_SIZE; i++) {
        int try = (idx + i) % SET_SIZE;
        if (set->entries[try].used && set->entries[try].value == value) {
            set->entries[try].used = 0;
            return;
        }
    }
}

void set_free(Set *set) {
    // nothing to free in this static implementation
}
