#include "map.h"
#include <stdlib.h>

static int hash(int key) {
    return (key < 0 ? -key : key) % MAP_SIZE;
}

void map_init(Map *map) {
    for (int i = 0; i < MAP_SIZE; i++)
        map->entries[i].used = 0;
}

void map_put(Map *map, int key, int value) {
    int idx = hash(key);
    for (int i = 0; i < MAP_SIZE; i++) {
        int try = (idx + i) % MAP_SIZE;
        if (!map->entries[try].used || map->entries[try].key == key) {
            map->entries[try].key = key;
            map->entries[try].value = value;
            map->entries[try].used = 1;
            return;
        }
    }
}

int map_get(Map *map, int key, int *found) {
    int idx = hash(key);
    for (int i = 0; i < MAP_SIZE; i++) {
        int try = (idx + i) % MAP_SIZE;
        if (map->entries[try].used && map->entries[try].key == key) {
            if (found) *found = 1;
            return map->entries[try].value;
        }
    }
    if (found) *found = 0;
    return 0;
}

void map_free(Map *map) {
    // nothing to free in this static implementation
}
